#include "ocamlfltk.h"
#include <fltk/events.h>


using namespace Ofltk;

extern "C" {

    CAMLprim value event_dy(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_dy()));
    }


}
