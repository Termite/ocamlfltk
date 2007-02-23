#ifndef OCHOICES_H
#define OCHOICES_H

#include "omenu.h"
#include <fltk/Choice.h>
#include <fltk/CycleButton.h>
#include <fltk/PopupMenu.h>

namespace Ofltk {

    NEW_DIRECTOR(Choice);
    NEW_DIRECTOR(CycleButton);
    NEW_DIRECTOR(PopupMenu);

    
    class ocaml_choice : public ocaml_menu {
        public:
            ocaml_choice() : ocaml_menu() {}

            ocaml_choice(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new Choice_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_choice() {}

            DEF_DEFAULT(Choice_d);

    };

    class ocaml_cyclebutton : public ocaml_menu {
        public:
            ocaml_cyclebutton() : ocaml_menu() {}

            ocaml_cyclebutton(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new CycleButton_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_cyclebutton() {}

            DEF_DEFAULT(CycleButton_d);

    };

    class ocaml_popupmenu : public ocaml_menu {
        public:
            ocaml_popupmenu() : ocaml_menu() {}

            ocaml_popupmenu(value* ocaml, int x, int y, int w, int h, const char* t = 0)
            {
                dest_widget = new PopupMenu_d(ocaml, x, y, w, h, t);
            }

            virtual ~ocaml_popupmenu() {}

            DEF_DEFAULT(PopupMenu_d);

    };
}

#endif
