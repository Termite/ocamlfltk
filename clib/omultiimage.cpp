#include "omultiimage.h"
#include <iostream>

using namespace Ofltk;

extern "C" {

    CAMLprim value new_multiimage(value _draw, value image0)
    {
        CAMLparam2(_draw, image0);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_multiimage* s = new ocaml_multiimage(draw);
        s->add(0,(ocaml_symbol*)image0);
        CAMLreturn((value) s);
    }

    CAMLprim value add_to_multiimage(value multiimage, value flags, value image)
    {
        CAMLparam3(multiimage, flags, image);
        ((ocaml_multiimage*)multiimage)->add(Int_val(flags), (ocaml_symbol*)image);
        CAMLreturn(Val_unit);
    }

    CAMLprim value multiimage_current_image(value multiimage)
    {
        CAMLparam1(multiimage);
        CAMLreturn((value)(((ocaml_multiimage*)multiimage)->current_image()));
    }

    CAMLprim value multiimage_release(value multiimage)
    {
        CAMLparam1(multiimage);
        ((ocaml_multiimage*)multiimage)->release();
        CAMLreturn(Val_unit);
    }



}
