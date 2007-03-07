#ifndef OMONITOR_H
#define OMONITOR_H

#include <fltk/Monitor.h>
#include "orect.h"

namespace Ofltk {

    class ocaml_monitor : public ocaml_rect {
        public:
        ocaml_monitor() : ocaml_rect()
        { }
        ocaml_monitor(const fltk::Monitor& m) : ocaml_rect()
        {
            dest_widget =const_cast<fltk::Monitor*>(&m);
        }

        ocaml_monitor(fltk::Monitor* m) : ocaml_rect()
        {
            dest_widget = m;
        }

        int depth() const { return static_cast<fltk::Monitor*>(dest_widget)->depth(); }
        float dpi_x() const { return static_cast<fltk::Monitor*>(dest_widget)->dpi_x(); }
        float dpi_y() const { return static_cast<fltk::Monitor*>(dest_widget)->dpi_y(); }
        float dpi() const   { return static_cast<fltk::Monitor*>(dest_widget)->dpi(); }
    };

}


#endif

