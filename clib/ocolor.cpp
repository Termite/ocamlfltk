#include "ocamlfltk.h"
#include <fltk/Color.h>
#include <fltk/show_colormap.h>

extern "C" {

CAMLprim value color_contrast(value fg, value bg)
{
    CAMLparam2(fg,bg);
    fltk::Color c = fltk::contrast(Int32_val(fg), Int32_val(bg));
    CAMLreturn(caml_copy_int32(c));
}

CAMLprim value show_colormap(value old_col)
{
    CAMLparam1(old_col);
    int col = fltk::show_colormap(Int32_val(old_col));
    CAMLreturn(caml_copy_int32(col));
}

}
