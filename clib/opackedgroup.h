#ifndef OPACKEDGROUP_H
#define OPACKEDGROUP_H

#include "ogroup.h"
#include <fltk/PackedGroup.h>
#include <fltk/BarGroup.h>

namespace Ofltk {

    NEW_DIRECTOR(PackedGroup);
    NEW_DIRECTOR(BarGroup);

    class ocaml_packedgroup : public ocaml_group {
        public:

        ocaml_packedgroup() : ocaml_group() {}

        ocaml_packedgroup(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new PackedGroup_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_packedgroup() {}

        DEF_DEFAULT(PackedGroup_d);

        int spacing() { return static_cast<PackedGroup_d*>(dest_widget)->spacing(); }

        void spacing(int i)
        {
            static_cast<PackedGroup_d*>(dest_widget)->spacing(i);
        }

        virtual void layout() { static_cast<PackedGroup_d*>(dest_widget)->layout(); }
};

    class ocaml_bargroup : public ocaml_group {
        public:

        ocaml_bargroup() : ocaml_group() {}

        ocaml_bargroup(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new BarGroup_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_bargroup() {}

        DEF_DEFAULT(BarGroup_d);

        bool opened() { return static_cast<BarGroup_d*>(dest_widget)->opened(); }

        bool opened(int i)
        {
            static_cast<BarGroup_d*>(dest_widget)->opened(bool(i));
        }
        bool open() { return static_cast<BarGroup_d*>(dest_widget)->open(); }
        bool close() { return static_cast<BarGroup_d*>(dest_widget)->close(); }

};

}

#endif
