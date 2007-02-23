#ifndef OMENU_H
#define OMENU_H

#include "ogroup.h"
#include <fltk/Menu.h>
#include <fltk/MenuBar.h>

namespace Ofltk {

    NEW_DIRECTOR(Menu);
    NEW_DIRECTOR(MenuBar);

    class ocaml_menu : public ocaml_group {
        public:
            ocaml_menu() : ocaml_group() {}

            ocaml_menu(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new Menu_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_menu() {}

            DEF_DEFAULT(Menu_d);

    };

    class ocaml_menubar : public ocaml_menu {
        public:
            ocaml_menubar() : ocaml_menu() {}

            ocaml_menubar(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new MenuBar_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_menubar() {}

            DEF_DEFAULT(MenuBar_d);

    };
}

#endif

