#ifndef OOUTPUT_H
#define OOUTPUT_H

#include "oinput.h"
#include <fltk/Output.h>
#include <fltk/MultiLineOutput.h>
#include <fltk/WordwrapOutput.h>

namespace Ofltk {

NEW_DIRECTOR(Output);
NEW_DIRECTOR(MultiLineOutput);
NEW_DIRECTOR(WordwrapOutput);

class ocaml_output : public ocaml_input {
    public:
        ocaml_output() : ocaml_input() {}

        ocaml_output(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Output_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_output() {}

        DEF_DEFAULT(Output_d);
};

class ocaml_multiline : public ocaml_output {
    public:
        ocaml_multiline() : ocaml_output() {}

        ocaml_multiline(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new MultiLineOutput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_multiline() {}

        DEF_DEFAULT(MultiLineOutput_d);
};

class ocaml_wordwrap : public ocaml_output {
    public:
        ocaml_wordwrap() : ocaml_output() {}

        ocaml_wordwrap(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new WordwrapOutput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_wordwrap() {}

        DEF_DEFAULT(WordwrapOutput_d);
};


}

#endif

