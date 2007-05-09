#include "ocamlfltk.h"
#include <fltk/TextBuffer.h>

extern "C" {

CAMLprim value make_TextSelection(value nix)
{
    CAMLparam1(nix);

    CAMLreturn( (value) (new fltk::TextSelection()));
}

 
CAMLprim value make_TextBuffer(value size)
{
    CAMLparam1(size);

    CAMLreturn( (value) (new fltk::TextBuffer(Int_val(size))));
}

    

}
