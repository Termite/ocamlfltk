#ifndef OGROUP_H
#define OGROUP_H

#include "owidget.h"
#include <fltk/Group.h>

namespace Ofltk {

NEW_DIRECTOR(Group);

class ocaml_group : public ocaml_widget {
    public:
        ocaml_group() : ocaml_widget() {}

        ocaml_group(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Group_d(o_class, x, y, w, h, t);
        }
        
        virtual ~ocaml_group() {}

        DEF_DEFAULT(Group_d);

        void begin() { static_cast<fltk::Group*>(dest_widget)->begin(); }
        void end() { static_cast<fltk::Group*>(dest_widget)->end(); }

        void resizable(ocaml_widget* w)
        { 
            static_cast<fltk::Group*>(dest_widget)->resizable(w->give_widget());
        }

        int children()
        {
            return static_cast<fltk::Group*>(dest_widget)->children();
        }

        virtual fltk::Widget* child(int n)
        {
             return static_cast<fltk::Group*>(dest_widget)->child(n);
        }
        
};


}

#endif
