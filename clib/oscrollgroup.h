#ifndef OSCROLLGROUP_H
#define OSCROLLGROUP_H

#include "ogroup.h"
#include <fltk/ScrollGroup.h>

namespace Ofltk {

    NEW_DIRECTOR(ScrollGroup);

    class ocaml_scrollgroup : public ocaml_group {
        public:
            ocaml_scrollgroup() : ocaml_group() {}

            ocaml_scrollgroup(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new ScrollGroup_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_scrollgroup() {}

            virtual void default_draw()
            {
                static_cast<ScrollGroup_d*>(dest_widget)->default_draw();
            }

            int default_handle(int ev)
            {
                return static_cast<ScrollGroup_d*>(dest_widget)->default_handle(ev); 
            }

            int xpos() { return static_cast<ScrollGroup_d*>(dest_widget)->xposition(); }
            int ypos() { return static_cast<ScrollGroup_d*>(dest_widget)->yposition(); }

            void scroll_to(int x, int y)
            { 
                static_cast<ScrollGroup_d*>(dest_widget)->scrollTo(x, y);
            }
    };


}

#endif

