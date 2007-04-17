#include "ocamlfltk.h"
#include "orect.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_rect(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        ocaml_rect* r = new ocaml_rect(Int_val(x), Int_val(y), Int_val(w), Int_val(h));
        CAMLreturn((value) r);
    }

}
