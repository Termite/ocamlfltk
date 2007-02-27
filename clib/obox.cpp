#include "ocamlfltk.h"
#include <fltk/Box.h>
#include <fltk/ask.h>

#include "osymbols.h"

using namespace Ofltk;

extern "C" {

    /* Boxes */
        
    CAMLprim value init_boxes(value nix)
    {
        CAMLparam1(nix);
        CAMLlocal1(boxes);
        fltk::Box* f[] = { 
            fltk::UP_BOX,
            fltk::DOWN_BOX,
            fltk::THIN_UP_BOX,
            fltk::THIN_DOWN_BOX,
            fltk::ENGRAVED_BOX,
            fltk::EMBOSSED_BOX,
            fltk::BORDER_BOX,
            fltk::FLAT_BOX,
            fltk::HIGHLIGHT_UP_BOX,
            fltk::HIGHLIGHT_DOWN_BOX,
            fltk::ROUND_UP_BOX,
            fltk::ROUND_DOWN_BOX,
            fltk::DIAMOND_UP_BOX,
            fltk::DIAMOND_DOWN_BOX,
            fltk::NO_BOX,
            fltk::SHADOW_BOX,
            fltk::ROUNDED_BOX,
            fltk::RSHADOW_BOX,
            fltk::RFLAT_BOX,
            fltk::OVAL_BOX,
            fltk::OSHADOW_BOX,
            fltk::OFLAT_BOX,
            fltk::BORDER_FRAME,
            fltk::FOCUS_FRAME,
            fltk::PLASTIC_UP_BOX,
            fltk::PLASTIC_DOWN_BOX
            };
        int size = sizeof(f) / sizeof(fltk::Box*);
        boxes = caml_alloc_tuple(size);
        for (int i=0; i < size; ++i)
        {
            Store_field(boxes, i, (value)(new Ofltk::ocaml_symbol(f[i])));
        }
        CAMLreturn(boxes);
    }    

    CAMLprim value ask_box(value message)
    {
        CAMLparam1(message);
        char* m = String_val(message);
        CAMLreturn(Val_int(fltk::ask("%s", m)));
    }
       
    CAMLprim value input_box(value default_str, value message)
    {
        CAMLparam2(default_str, message);
        CAMLlocal1(erg);
        char* m = String_val(message);
        const char* answer = fltk::input("%s", String_val(default_str), m);
        if (answer == 0) 
        {
           erg = Val_int(0);
        }
        else
        {
           erg = caml_alloc_tuple(1);
           Store_field(erg, 0, copy_string(answer));
        }
        CAMLreturn(erg);
    }
}
