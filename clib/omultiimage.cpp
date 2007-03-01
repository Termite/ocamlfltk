#include "omultiimage.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_multiimage(value _draw, value image0)
    {
        CAMLparam2(_draw, image0);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_multiimage* s = new ocaml_multiimage(draw ,(ocaml_symbol*)image0);
        CAMLreturn((value) s);
    }

    CAMLprim value add_image(value multiimage, value flags, value image)
    {
        CAMLparam3(multiimage, flags, image);
        ((ocaml_multiimage*)multiimage)->add(Int_val(flags), (ocaml_symbol*)image);
    }

}
