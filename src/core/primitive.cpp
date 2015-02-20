#include <rendermoon.h>

Primitive::Primitive()
{
}

Spectrum Primitive::L(Intersection& i, Point& light_point, Normal& light_nornal) 
{ 
	return Spectrum(); 
}


void Primitive::Refine(list<Reference<Primitive> > &refined) const
{
 //   Severe("Unimplemented Primitive::Refine() method called!");
}


void Primitive::FullyRefine(list<Reference<Primitive> > &refined) const
{
    list<Reference<Primitive> > todo;
    todo.push_back(const_cast<Primitive *>(this));
    while (todo.size())
    {
        // Refine last primitive in todo list
        Reference<Primitive> prim = todo.back();
        todo.pop_back();
        if (prim->CanIntersect())
            refined.push_back(prim);
        else
            prim->Refine(todo);
    }
}

bool Primitive::CanIntersect() const
{
    return true;
}