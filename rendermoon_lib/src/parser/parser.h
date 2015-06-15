#ifndef PROJECT_PARSER_H
#define PROJECT_PARSER_H

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

using namespace std;

class parser
{
    enum TokenLitterals {
        STRING = 258,
        ID = 259,
        NUM = 260,
        LBRACK = 261,
        RBRACK = 262,
        ACCELERATOR = 263,
        AREALIGHTSOURCE = 264,
        ATTRIBUTEBEGIN = 265,
        ATTRIBUTEEND = 266,
        CAMERA = 267,
        CONCATTRANSFORM = 268,
        COORDINATESYSTEM = 269,
        COORDSYSTRANSFORM = 270,
        FILM = 271,
        IDENTITY = 272,
        LIGHTSOURCE = 273,
        LOOKAT = 274,
        MATERIAL = 275,
        OBJECTBEGIN = 276,
        OBJECTEND = 277,
        OBJECTINSTANCE = 278,
        PIXELFILTER = 279,
        REVERSEORIENTATION = 280,
        ROTATE = 281,
        SAMPLER = 282,
        SCALE = 283,
        SEARCHPATH = 284,
        SHAPE = 285,
        SURFACEINTEGRATOR = 286,
        TEXTURE = 287,
        TRANSFORMBEGIN = 288,
        TRANSFORMEND = 289,
        TRANSFORM = 290,
        TRANSLATE = 291,
        VOLUME = 292,
        VOLUMEINTEGRATOR = 293,
        WORLDBEGIN = 294,
        WORLDEND = 295,
        HIGH_PRECEDENCE = 296
    };

//    const string TokenLitteralID[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};



    enum Token {
        tok_eof = -1,
        tok_identifier = -3,
        tok_number = -3,
        tok_left_bracket = -4,
        tok_right_bracket = -5,
        tok_string_begin_end = -6
    };

    static std::string IdentifierIdentifiant;  // Filled in if tok_identifier
    static std::string IdentifierNumber;  // Filled in if tok_identifier
    static std::string IdentifierString;  // Filled in if tok_identifier

    static int gettok()
    {
        static int LastChar = ' ';

        // Skip any whitespace.
        while (isspace(LastChar))
            LastChar = getchar();

        //string [a-zA-Z][a-zA-Z0-9]*
        IdentifierIdentifiant = "";
        if (isalpha(LastChar)) {
            IdentifierIdentifiant = LastChar;
            while (isalnum((LastChar = getchar())))
                IdentifierIdentifiant += LastChar;

            return tok_identifier;
        }

        //some thing that look like a number
        IdentifierNumber = "";
        if (isdigit(LastChar) || LastChar == '.' || LastChar == '+' || LastChar == '-') {   // Number: [0-9.]+
            IdentifierNumber = LastChar;
            LastChar = getchar();
            while (isdigit(LastChar) || LastChar == '.')
            {
                IdentifierNumber += LastChar;
                LastChar = getchar();
            }
            return tok_number;
        }

        //string begin/end
        if (LastChar == '"')
            return tok_string_begin_end;

        // left bracket
        if (LastChar == '[')
            return tok_left_bracket;

        // right bracket
        if (LastChar == ']')
            return tok_right_bracket;

        // comment bracket
        if (LastChar == '#') {
            // Comment until end of line.
            do LastChar = getchar();
            while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

            if (LastChar != EOF)
                return gettok();
        }

        // EOF
        if (LastChar == EOF)
            return tok_eof;

        // Otherwise, just return the character as its ascii value.
        int ThisChar = LastChar;
        LastChar = getchar();
        return ThisChar;
    }


};


#endif //PROJECT_PARSER_H
