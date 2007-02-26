#include "ocamlfltk.h"
#include <fltk/Box.h>
#include <fltk/ask.h>

#include "osymbols.h"

using namespace fltk;

extern "C" {

    /* Boxes */
        
    CAMLprim value init_boxes(value nix)
    {
        CAMLparam1(nix);
        CAMLlocal1(boxes);
        Box* f[] = { 
             UP_BOX,
             DOWN_BOX,
             THIN_UP_BOX,
             THIN_DOWN_BOX,
             ENGRAVED_BOX,
             EMBOSSED_BOX,
             BORDER_BOX,
             FLAT_BOX,
             HIGHLIGHT_UP_BOX,
             HIGHLIGHT_DOWN_BOX,
             ROUND_UP_BOX,
             ROUND_DOWN_BOX,
             DIAMOND_UP_BOX,
             DIAMOND_DOWN_BOX,
             NO_BOX,
             SHADOW_BOX,
             ROUNDED_BOX,
             RSHADOW_BOX,
             RFLAT_BOX,
             OVAL_BOX,
             OSHADOW_BOX,
             OFLAT_BOX,
             BORDER_FRAME,
             FOCUS_FRAME,
             PLASTIC_UP_BOX,
             PLASTIC_DOWN_BOX
            };
        int size = sizeof(f) / sizeof(Box*);
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
        CAMLreturn(Val_int(ask("%s", m)));
    }
       
    CAMLprim value input_box(value default_str, value message)
    {
        CAMLparam2(default_str, message);
        CAMLlocal1(erg);
        char* m = String_val(message);
        const char* answer = input("%s", String_val(default_str), m);
        if (answer == 0) 
        {
           erg = Val_int(0);
        }
        else
        {
           erg = caml_alloc_tuple(1);
           Store_field(erg, 0, caml_copy_string(answer));
        }
        CAMLreturn(erg);
    }
}
