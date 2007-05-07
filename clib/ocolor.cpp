#include "ocamlfltk.h"
#include <fltk/Color.h>

CAMLprim value color_contrast(value fg, value bg)
{
    CAMLparam2(fg,bg);
    fltk::Color c = fltk::contrast(Int32_val(fg), Int32_val(bg));
    CAMLreturn(caml_copy_int32(c));
}

