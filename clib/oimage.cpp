#include "oimage.h"
#include <fltk/SharedImage.h>

using namespace Ofltk;

extern "C" {


    CAMLprim value new_image(value vm, value name)
    {
        CAMLparam2(vm, name);
        o_Image* s = new o_Image(vm, String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value new_image_wh(value vm, value w, value h, value name)
    {
        CAMLparam4(vm, w, h, name);
        o_Image* s = new o_Image(vm, Int_val(w), Int_val(h), String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value new_tiledimage(value vm, value symbol)
    {
        CAMLparam2(vm, symbol);
        o_TiledImage* s = new o_TiledImage(vm, (fltk::Symbol*)symbol);
        CAMLreturn((value) s);
    }


    CAMLprim value shared_image_get(value name)
    {
        CAMLparam1(name);
        fltk::SharedImage* s = fltk::SharedImage::get(String_val(name));
        CAMLreturn((value) s);
    }



}
