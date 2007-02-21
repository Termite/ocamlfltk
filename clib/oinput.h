#ifndef OINPUT_H
#define OINPUT_H

#include "ocamlfltk.h"
#include "owidget.h"
#include <fltk/Input.h>
#include <fltk/IntInput.h>
#include <fltk/NumericInput.h>

namespace Ofltk {

NEW_DIRECTOR(Input);
NEW_DIRECTOR(NumericInput);
NEW_DIRECTOR(FloatInput);
NEW_DIRECTOR(IntInput);

class ocaml_input : public ocaml_widget {
    public:
        ocaml_input() : ocaml_widget() {}

        ocaml_input(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Input_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_input() {}

        virtual void default_draw()
        {
            static_cast<Input_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<Input_d*>(dest_widget)->default_handle(ev); 
        }

        const char* get_text()
        {
            return  static_cast<Input_d*>(dest_widget)->text();
        }

        bool set_text(const char* t)
        {
            return static_cast<Input_d*>(dest_widget)->text(t);
        }


};


class ocaml_numinput : public ocaml_input {
    public:
        ocaml_numinput() : ocaml_input() {}

        ocaml_numinput(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new NumericInput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_numinput() {}

        virtual void default_draw()
        {
            static_cast<NumericInput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<NumericInput_d*>(dest_widget)->default_handle(ev); 
        }

        void set_value_d(double v)
        {
            static_cast<NumericInput_d*>(dest_widget)->value(v);
        }

        void set_value_i(int v)
        {
            static_cast<NumericInput_d*>(dest_widget)->value(v);
        }
};

class ocaml_floatinput : public ocaml_numinput {
    public:
        ocaml_floatinput() : ocaml_numinput() {}

        ocaml_floatinput(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new FloatInput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_floatinput() {}

        virtual void default_draw()
        {
            static_cast<FloatInput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<FloatInput_d*>(dest_widget)->default_handle(ev); 
        }

        double get_value_d()
        {
            return static_cast<FloatInput_d*>(dest_widget)->fvalue();
        }

        int get_value_i()
        {
            return static_cast<FloatInput_d*>(dest_widget)->ivalue();
        }
};

class ocaml_intinput : public ocaml_floatinput {
    public:
        ocaml_intinput() : ocaml_floatinput() {}

        ocaml_intinput(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new IntInput_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_intinput() {}

        virtual void default_draw()
        {
            static_cast<IntInput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<IntInput_d*>(dest_widget)->default_handle(ev); 
        }
};


}
#endif

