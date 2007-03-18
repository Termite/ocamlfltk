#include "ocamlfltk.h"
#include <fltk/run.h>

namespace Ofltk {

extern "C" {

    CAMLprim value app_run(value nix)
    {
        CAMLparam1(nix);

        CAMLreturn(Val_int(fltk::run()));
    }
    
    CAMLprim value app_check(value nix)
    {
        CAMLparam1(nix);

        CAMLreturn(Val_int(fltk::check()));
    }
    
    CAMLprim value app_wait(value v)
    {
        CAMLparam1(v);

        CAMLreturn(Val_int(fltk::wait()));
    }
    

}
}
