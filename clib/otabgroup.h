#ifndef OTABGROUP_H
#define OTABGROUP_H

#include "ogroup.h"
#include <fltk/TabGroup.h>

namespace Ofltk {

    NEW_DIRECTOR(TabGroup);
    
    class ocaml_tabgroup : public ocaml_group {
        public:
            ocaml_tabgroup() : ocaml_group() {}

            ocaml_tabgroup(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new TabGroup_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_tabgroup() {}

            int get_value()
            {
                return static_cast<TabGroup_d*>(dest_widget)->value();
            }

            bool set_value(int v)
            {
                return static_cast<TabGroup_d*>(dest_widget)->value(v);
            }

            DEF_DEFAULT(TabGroup_d);
    };


}

#endif


