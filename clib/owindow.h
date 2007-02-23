#ifndef OWINDOW_H
#define OWINDOW_H

#include "ogroup.h"
#include <fltk/Window.h>


namespace Ofltk {

NEW_DIRECTOR(Window);

class ocaml_window : public ocaml_group {
    public:
        ocaml_window() : ocaml_group() {}
        ocaml_window(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Window_d(o_class, x, y, w, h, t);
        }
        virtual ~ocaml_window() {}

        virtual void show() { static_cast<Window_d*>(dest_widget)->show(); }

        DEF_DEFAULT(Window_d);

        
};

}

#endif

