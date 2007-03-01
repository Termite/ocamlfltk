#include "oimage.h"

using namespace Ofltk;

extern "C" {


    CAMLprim value new_image(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_image* s = new ocaml_image(draw, String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value new_image_wh(value _draw, value w, value h, value name)
    {
        CAMLparam4(_draw, w, h, name);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_image* s =
            new ocaml_image(draw, Int_val(w), Int_val(h), String_val(name));
        CAMLreturn((value) s);
    }




}
