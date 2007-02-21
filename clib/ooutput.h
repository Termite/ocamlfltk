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

        virtual void default_draw()
        {
            static_cast<Output_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<Output_d*>(dest_widget)->default_handle(ev); 
        }
};

class ocaml_multiline : public ocaml_output {
    public:
        ocaml_multiline() : ocaml_output() {}

        ocaml_multiline(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new MultiLineOutput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_multiline() {}

        virtual void default_draw()
        {
            static_cast<MultiLineOutput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<MultiLineOutput_d*>(dest_widget)->default_handle(ev); 
        }
};

class ocaml_wordwrap : public ocaml_output {
    public:
        ocaml_wordwrap() : ocaml_output() {}

        ocaml_wordwrap(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new WordwrapOutput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_wordwrap() {}

        virtual void default_draw()
        {
            static_cast<WordwrapOutput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<WordwrapOutput_d*>(dest_widget)->default_handle(ev); 
        }
};


}

#endif

