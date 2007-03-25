#ifndef OGROUP_H
#define OGROUP_H

#include <map>
#include <ext/hash_map>
#include "owidget.h"
#include <fltk/Group.h>


namespace Ofltk {

typedef std::map<fltk::Rectangle*, Ofltk::ocaml_widget*> kid_map;
static kid_map kids;

NEW_DIRECTOR(Group);

class ocaml_group : public ocaml_widget {
    public:
        ocaml_group() : ocaml_widget() {}

        ocaml_group(::value* o_class, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new Group_d(o_class, x, y, w, h, t);
        }
        
        virtual ~ocaml_group()
        {
            kids.erase(this->dest_widget);
        }

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
             fltk::Widget* w = static_cast<fltk::Group*>(dest_widget)->child(n);
             kid_map::iterator i = kids.find(w);
             if (i != kids.end())
                 return i->second;
             else {
                 ocaml_widget* o = new ocaml_widget(w);
                 kids.insert(std::make_pair(w, o));
                 return o;
             }
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
