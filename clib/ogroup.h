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

        virtual ocaml_widget* child(int n)
        {
             return new ocaml_widget(static_cast<fltk::Group*>(dest_widget)->child(n));
        }

        void insert(ocaml_widget* w, int index)
        {
            static_cast<fltk::Group*>(dest_widget)->insert(*(w->give_widget()), index);
        }
        
        void insert(ocaml_widget* w, ocaml_widget* before)
        {
            static_cast<fltk::Group*>(dest_widget)->insert(*(w->give_widget()), 
                    before ? before->give_widget() : 0);
        }
        
};


}

#endif
