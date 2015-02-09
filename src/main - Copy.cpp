#include "main.h"



#include "tga.h"

using namespace std;

glm::vec3 view_position = glm::vec3(0.0, 0.0, 10.0);
glm::vec3 view_at = glm::vec3(0.0, 0.0, 0.0);
glm::vec3 view_up = glm::vec3(0.0, 1.0, 0.0);
glm::mat4 view = glm::lookAt(view_position, view_at, view_up);



float fov = 45.0f;
int canvas_width = 512;
int canvas_height = 256;
float aspectRatio = canvas_width/canvas_height;


void save(int width, int height, int *data);
Ray get_camera_ray(int x, int y);

const glm::mat2 m2 = glm::mat2(1.6, -1.2, 1.2, 1.6);

float tri(glm::vec2 p )
{
    return 0.5*(cos(6.2831*p.x) + cos(6.2831*p.y));
}

float terrainMed( glm::vec2 p )
{
    p *= 0.0013;

    float s = 1.0f;
    float t = 0.0f;
    for( int i=0; i<6; i++ )
    {
        t += s*tri( p );
        s *= 0.5f + 0.1f*t;
        p = 0.97f*m2*p + (t-0.5f)*0.2f;
    }

    return t*55.0f;
}

float terrainLow( glm::vec2 p )
{
    p *= 0.0013f;

    float s = 1.0f;
    float t = 0.0f;
    for( int i=0; i<2; i++ )
    {
        t += s*tri( p );
        s *= 0.5f + 0.1f*t;
        p = 0.97f*m2*p + (t-0.5f)*0.2f;
    }
    return t*55.0f;
}

glm::vec2 map( glm::vec3 pos, float time )
{
    float m = 0.0;
    float h = pos.y - terrainMed( glm::vec2(pos.x, pos.z));

#ifdef DRAW_RUBES
    float sph = tubes( pos, time );
    float k = 60.0;
    float w = clamp( 0.5 + 0.5*(h-sph)/k, 0.0, 1.0 );
    h = mix( h, sph, w ) - k*w*(1.0-w);
    m = mix( m, 1.0, w ) - 1.0*w*(1.0-w);
    m = glm::clamp(m,0.0,1.0);
#endif
    return glm::vec2( h, m );
}

glm::vec2 interesct( Ray& r, float tmin, float tmax, float time )
{
    float t = tmin;
    float  m = 0.0;
    for( int i=0; i<160; i++ )
    {
        glm::vec3 pos = r.o + t*r.d;
        glm::vec2 res = map( pos, time );
        m = res.y;
        if( res.x<(0.001*t) || t>tmax  ) break;
        t += res.x * 0.5;
    }

    return glm::vec2( t, m );
}

glm::vec3 dome( glm::vec3 rd, glm::vec3 light1 )
{
    float sda = glm::clamp(0.5f + 0.5f*glm::dot(rd, light1), 0.0f, 1.0f);//[0.5..1.0]
    float cho = max(rd.y, 0.0f);

    glm::vec3 bgcol = glm::mix(
                            glm::mix(
                                    0.7f*glm::vec3(0.0f, 0.40f, 0.60f),
                                    glm::vec3(0.80f,0.70f, 0.20f),
                                    pow(1.0f-cho,3.0f + 4.0f-4.0f*sda)
                            ),
                            glm::vec3(0.43f+0.2f*sda,0.4f-0.1f*sda,0.4f-0.25f*sda),
                            pow(1.0f-cho,10.0f + 8.0f-8.0f*sda)
                        );
    bgcol *= 0.8f + 0.2f*sda;
    return 0.75f*bgcol;
}

glm::vec3 calcNormalMed( glm::vec3 pos, float t )
{
    float e = 0.005f*t;
    glm::vec2  eps = glm::vec2(e, 0.0f);
    float h = terrainMed( glm::vec2(pos.x, pos.z) );
    return glm::normalize(
            glm::vec3(
                    terrainMed(glm::vec2(pos.x, pos.z) - glm::vec2(eps.x, eps.y)-h),
                    e,
                    terrainMed(glm::vec2(pos.x, pos.z) - glm::vec2(eps.y, eps.x)-h)
            ));
}

int main()
{
    Buffer<int> b1= Buffer<int>(512,256);

    for(int y=0; y<canvas_height; y++)
    {
        for(int x=0; x<canvas_width; x++)
        {
            Ray ray = get_camera_ray(x, y);
            //printf("%f %f %f\n", ray.d.x, ray.d.y, ray.d.z);
            glm::vec3 light1 = glm::normalize( glm::vec3(-0.8,0.2,0.5) );

            float sundotc = glm::clamp( glm::dot(ray.d, light1), 0.0f, 1.0f );
printf("%f %f %f \n",ray.d.x, ray.d.y, ray.d.z);
            // background
            glm::vec3 bgcol = dome( ray.d, light1 );

            // raymarch
            float tmin = 10.0;
            float tmax = 4500.0;

            glm::vec3  col = bgcol;

            float time = 10;
            glm::vec2 res = interesct( ray, tmin, tmax, time );
            if( true )
            {
                // sky
                col += 0.2f*0.12f*glm::vec3(1.0,0.5,0.1)*pow( sundotc,5.0f );
                col += 0.2f*0.12f*glm::vec3(1.0,0.6,0.1)*pow( sundotc,64.0f );
                col += 0.2f*0.12f*glm::vec3(2.0,0.4,0.1)*pow( sundotc,512.0f );

                // clouds
//                glm::vec2 sc = glm::vec2(r.o.x, r.o.z) + glm::vec2(r.d.x, r.d.z)*(1000.0-r.o.y)/r.d.y;
//                col = mix( col, 0.25*glm::vec3(0.5,0.9,1.0), 0.4*glm::smoothstep(0.0,1.0,texture2D(iChannel0,0.000005*sc).x) );

                // sun scatter
                col += 0.2f*0.2f*glm::vec3(1.5,0.7,0.4)*pow( sundotc, 4.0f );
            }
            else
            {
                float t = res.x;
                glm::vec3 pos = ray.o + t*ray.d;
                glm::vec3 sor = calcNormalMed( pos, t );
/*
                // lighting
                float amb = glm::clamp( nor.y, 0.0f, 1.0f);
                float dif = glm::clamp( glm::dot( light1, nor ), 0.0, 1.0 );
                float bac = glm::clamp( glm::dot( normalize( glm::vec3(-light1.x, 0.0, light1.z ) ), nor ), 0.0, 1.0 );
                float sha = glm::mix( calcShadow( pos, light1 ), 1.0, res.y );
                float spe = glm::pow( glm::clamp( dot(ref,light1), 0.0, 1.0 ), 4.0 ) * dif;

                glm::vec3 lin  = glm::vec3(0.0);
                lin += dif*glm::vec3(11.0,6.00,3.00) * glm::vec3( sha, sha*sha*0.5+0.5*sha, sha*sha*0.8+0.2*sha );
                lin += amb*glm::vec3(0.25,0.30,0.40);
                lin += bac*glm::vec3(0.35,0.40,0.50);
                lin += spe*glm::vec3(4.00,4.00,4.00)*res.y;

                col *= lin;
*/
            }

            // gamma
            col = pow( col, glm::vec3(0.45) );

            // color grading
            col = col*1.4f*glm::vec3(1.0,1.0,1.02) + glm::vec3(0.0,0.0,0.11);
            col = glm::clamp(col,0.0f,1.0f);
            col = col*col*(3.0f-2.0f*col);
            col = glm::mix( col, glm::vec3(glm::dot(col,glm::vec3(0.333f))), 0.25f );


            int r= (int)glm::clamp(col.x*255.0f, 0.0f, 255.0f);
            int g = (int)glm::clamp(col.y*255.0f, 0.0f, 255.0f);
            int b = (int)glm::clamp(col.z*255.0f, 0.0f, 255.0f);

 //           printf("%f %f %f %d %d %d\n",col.x, col.y, col.z, r, g, b);

            b1[x+y*canvas_width] = (r<<16) + (g<<8) + b;
        }
    }

    //save
    save(canvas_width, canvas_height, b1.get_ptr());

    cout << "Hello, World!" << endl;

    return 0;
}

void save(int width, int height, int *data)
{
    RBitmap bitmap = RBitmap();
    bitmap.width = width;
    bitmap.height = height;
    bitmap.data = data;
    write_truecolor_tga(&bitmap);
}

Ray get_camera_ray(int x, int y)
{
//    glm::mat4 Projection = glm::perspective(fov, 4.0f / 3.0f, 0.1f, 100.f);

    //raster space to NDC  [0..pixel_width][0..pixel_height] -> [0..1][0..1]
    float x_ndc = (x+0.5)/canvas_width;
    float y_ndc = (y+0.5)/canvas_height;

    //NDC to screen space [0..1][0..1]->([-1..1]*aspectRatio)[-1..1]
    float x_screen_space = ((2.0*x_ndc)-1.0)*aspectRatio;
    float y_screen_space = (2.0*y_ndc)-1.0;

    //screen space to camera space
    float x_camera_space = x_screen_space*tan((float)(29.5 * DEG2RAD/2.0));
    float y_camera_space = -y_screen_space*tan((float)(29.5 * DEG2RAD/2.0)); //had to flip vertically because upper left is [-1,-1] and not [-1,1]
    float z_camera_space = -1.0; //image plan

    //camera space to world space
    glm::mat3 camera_orientation = (glm::mat3)view;
    camera_orientation = glm::transpose(camera_orientation);
    glm::vec3 ray_direction = camera_orientation * glm::vec3(x_camera_space, y_camera_space, z_camera_space);
    ray_direction = glm::normalize(ray_direction);

    Ray r;
    r.o = view_position;
    r.d = ray_direction;

    return r;
}

