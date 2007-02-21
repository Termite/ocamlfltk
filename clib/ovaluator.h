#ifndef VALUATOR_H
#define VALUATOR_H

#include "owidget.h"
#include <fltk/Valuator.h>
#include <fltk/ValueInput.h>
#include <fltk/ValueOutput.h>
#include <fltk/Slider.h>

namespace Ofltk {

NEW_DIRECTOR(Slider);
NEW_DIRECTOR(Valuator);
NEW_DIRECTOR(ValueInput);
NEW_DIRECTOR(ValueOutput);

class ocaml_valuator : public ocaml_widget {
    public:
        ocaml_valuator() : ocaml_widget() {}

        ocaml_valuator(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new fltk::Valuator(x, y, w, h, t);
        }
        
        virtual ~ocaml_valuator() {}

        double get_value() { return static_cast<fltk::Valuator*>(dest_widget)->value(); }
        double get_step() { return static_cast<fltk::Valuator*>(dest_widget)->step(); }
        double get_linesize() { return static_cast<fltk::Valuator*>(dest_widget)->linesize(); }
        double get_minimum() { return static_cast<fltk::Valuator*>(dest_widget)->minimum(); }
        double get_maximum() { return static_cast<fltk::Valuator*>(dest_widget)->maximum(); }

        void set_minimum(double v) { static_cast<fltk::Valuator*>(dest_widget)->minimum(v); }
        void set_maximum(double v) { static_cast<fltk::Valuator*>(dest_widget)->maximum(v); }
        void set_range(double a, double b) { static_cast<fltk::Valuator*>(dest_widget)->range(a,b); }
        void set_step(double v) { static_cast<fltk::Valuator*>(dest_widget)->step(v); }
        int  new_value(double v){ static_cast<fltk::Valuator*>(dest_widget)->value(v);}

};

class ocaml_slider : public ocaml_valuator {
    public:
        ocaml_slider() : ocaml_valuator() {}
        ocaml_slider(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Slider_d(o_class, x, y, w, h, t);
        }

        virtual ~ocaml_slider() {}

        virtual void default_draw()
        {

            //std::cout << "slider-default-draw" << std::endl;
            static_cast<Slider_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            //std::cout << "slider-default-handle " << ev << std::endl;
            return static_cast<Slider_d*>(dest_widget)->default_handle(ev); 
        }

        void set_tick_size(int n)
        {
            static_cast<Slider_d*>(dest_widget)->tick_size(n);
        }

        int get_tick_size()
        {
            return static_cast<Slider_d*>(dest_widget)->tick_size();
        }

        void set_slider_size(int n)
        {
            static_cast<Slider_d*>(dest_widget)->slider_size(n);
        }

        int get_slider_size()
        {
            return static_cast<Slider_d*>(dest_widget)->slider_size();
        }

};

class ocaml_valueinput : public ocaml_valuator {
    public:
        ocaml_valueinput() : ocaml_valuator() {}
        ocaml_valueinput(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new ValueInput_d(o_class, x, y, w, h, t);
        }

        virtual ~ocaml_valueinput() {}

        virtual void default_draw()
        {

            //std::cout << "slider-default-draw" << std::endl;
            static_cast<ValueInput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            //std::cout << "slider-default-handle " << ev << std::endl;
            return static_cast<ValueInput_d*>(dest_widget)->default_handle(ev); 
        }

};

class ocaml_valueoutput : public ocaml_valuator {
    public:
        ocaml_valueoutput() : ocaml_valuator() {}
        ocaml_valueoutput(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new ValueOutput_d(o_class, x, y, w, h, t);
        }

        virtual ~ocaml_valueoutput() {}

        virtual void default_draw()
        {

            //std::cout << "slider-default-draw" << std::endl;
            static_cast<ValueOutput_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            //std::cout << "slider-default-handle " << ev << std::endl;
            return static_cast<ValueOutput_d*>(dest_widget)->default_handle(ev); 
        }

};

}


#endif

