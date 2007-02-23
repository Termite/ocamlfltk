#ifndef OWIZARDGROUP_H
#define OWIZARDGROUP_H

#include "ogroup.h"
#include <fltk/WizardGroup.h>

namespace Ofltk {

    NEW_DIRECTOR(WizardGroup);

    class ocaml_wizardgroup : public ocaml_group {
        public:

        ocaml_wizardgroup() : ocaml_group() {}

        ocaml_wizardgroup(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new WizardGroup_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_wizardgroup() {}

        DEF_DEFAULT(WizardGroup_d);

        void next()
        {
            static_cast<WizardGroup_d*>(dest_widget)->next();
        }

        void prev()
        {
            static_cast<WizardGroup_d*>(dest_widget)->prev();
        }
    };


}
#endif
