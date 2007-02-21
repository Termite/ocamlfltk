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
        void show() { static_cast<fltk::Window*>(dest_widget)->show(); }

        virtual void default_draw()
        {

            //std::cout << "window-default-draw" << std::endl;
            static_cast<Window_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            //std::cout << "window-default-handle " << ev << std::endl;
            return static_cast<Window_d*>(dest_widget)->default_handle(ev); 
        }

        
};

}

#endif

