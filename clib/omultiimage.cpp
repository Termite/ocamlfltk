#include "omultiimage.h"
#include <iostream>

using namespace Ofltk;

extern "C" {

    CAMLprim value new_multiimage(value vm, value image0)
    {
        CAMLparam2(vm, image0);
        o_MultiImage* s = new o_MultiImage(vm);
        s->add(0,*((fltk::Symbol*)image0));
        CAMLreturn((value) s);
    }

    CAMLprim value add_to_multiimage(value multiimage, value flags, value image)
    {
        CAMLparam3(multiimage, flags, image);
        ((fltk::MultiImage*)multiimage)->add(Int_val(flags), *((fltk::Symbol*)image));
        CAMLreturn(Val_unit);
    }

    CAMLprim value multiimage_current_image(value multiimage)
    {
        CAMLparam1(multiimage);
        CAMLreturn((value)(((fltk::MultiImage*)multiimage)->current_image()));
    }

    CAMLprim value multiimage_release(value multiimage)
    {
        CAMLparam1(multiimage);
        ((fltk::MultiImage*)multiimage)->release();
        CAMLreturn(Val_unit);
    }



}
