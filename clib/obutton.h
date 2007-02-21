#ifndef OBUTTON_H
#define OBUTTON_H

#include "ocamlfltk.h"
#include "owidget.h"
#include <fltk/Button.h>
#include <fltk/CheckButton.h>
#include <fltk/LightButton.h>
#include <fltk/RadioButton.h>
#include <fltk/HighlightButton.h>
#include <fltk/RepeatButton.h>
#include <fltk/ReturnButton.h>
#include <fltk/ToggleButton.h>

namespace Ofltk {

NEW_DIRECTOR(Button);

extern char CheckButton_id[]; 
typedef fltk_director<fltk::CheckButton, CheckButton_id>  CheckButton_d;

NEW_DIRECTOR(LightButton);
NEW_DIRECTOR(RadioButton);
NEW_DIRECTOR(HighlightButton);
NEW_DIRECTOR(RepeatButton);
NEW_DIRECTOR(ReturnButton);
NEW_DIRECTOR(ToggleButton);

class ocaml_button : public ocaml_widget {
    public:
        ocaml_button() : ocaml_widget() {}

        ocaml_button(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Button_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_button() {}

        bool get_value()
        {
            return static_cast<Button_d*>(dest_widget)->value();
        }

        bool set_value(bool v)
        {
            return static_cast<Button_d*>(dest_widget)->value(v);
        }

        virtual void default_draw()
        {
            static_cast<Button_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<Button_d*>(dest_widget)->default_handle(ev); 
        }
};

template<class native, class parent>
class ocaml_xxx_button : public parent {
    public:
        ocaml_xxx_button() : parent() {}

        ocaml_xxx_button(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            this->dest_widget = new native(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_xxx_button() {}

        virtual void default_draw()
        {
            static_cast<native*>(this->dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<native*>(this->dest_widget)->default_handle(ev); 
        }

};


typedef ocaml_xxx_button<CheckButton_d, ocaml_button> ocaml_checkbutton;
typedef ocaml_xxx_button<LightButton_d, ocaml_checkbutton> ocaml_lightbutton;
typedef ocaml_xxx_button<RadioButton_d, ocaml_checkbutton> ocaml_radiobutton;
typedef ocaml_xxx_button<HighlightButton_d, ocaml_button> ocaml_highlightbutton;
typedef ocaml_xxx_button<RepeatButton_d, ocaml_button> ocaml_repeatbutton;
typedef ocaml_xxx_button<ReturnButton_d, ocaml_button> ocaml_returnbutton;
typedef ocaml_xxx_button<ToggleButton_d, ocaml_button> ocaml_togglebutton;


}

#endif
