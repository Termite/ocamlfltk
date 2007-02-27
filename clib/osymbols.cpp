#include "osymbols.h"

using namespace Ofltk;

extern "C" {


    CAMLprim value new_symbol(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        ocaml_symbol* s =
            new ocaml_symbol(caml_named_value(String_val(_draw)), String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value symbol_measure(value symbol, value _w, value _h)
    {
        CAMLparam3(symbol, _w, _h);
        CAMLlocal1(erg);
        int w = Int_val(_w);
        int h = Int_val(_h);
        ((ocaml_symbol*)symbol)->measure(w, h);
        erg = caml_alloc_small(2, 0);     
        Field(erg, 0) = Val_int(w);
        Field(erg, 1) = Val_int(h);
        CAMLreturn(erg);
    }

    CAMLprim value symbol_set_name(value symbol, value name)
    {
        CAMLparam2(symbol, name);
        ((ocaml_symbol*)symbol)->name(String_val(name));
        CAMLreturn(Val_unit);
    }

    CAMLprim value symbol_get_name(value symbol)
    {
        CAMLparam1(symbol);
        const char* n = ((ocaml_symbol*)symbol)->name();
        CAMLreturn(caml_copy_string(n ? n : ""));
    }

    CAMLprim value symbol_is_frame(value symbol)
    {
        CAMLparam1(symbol);
        bool n = ((ocaml_symbol*)symbol)->is_frame();
        CAMLreturn(Val_int(n));
    }

    CAMLprim value new_flatbox(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        ocaml_flatbox* s =
            new ocaml_flatbox(caml_named_value(String_val(_draw)), String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value new_framebox(value _draw, value name, value x, value y,
            value w, value h, value pattern, value down_box)
    {
        CAMLparam4(_draw, name, x, y);
        CAMLxparam4(h, pattern, down_box, w);
        ocaml_symbol* down = (Is_block(down_box)) ? (ocaml_symbol*)Field(down_box,1) : 0;
        ocaml_framebox* s =
            new ocaml_framebox(caml_named_value(String_val(_draw)), String_val(name),
                    Int_val(x), Int_val(y), Int_val(w), Int_val(h),
                    String_val(pattern), down);
        CAMLreturn((value) s);
    }


    CAMLprim value new_framebox_bc(value* arg, int argc)
    {
        return new_framebox(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
    }

    CAMLprim value framebox_get_data(value symbol)
    {
        CAMLparam1(symbol);
        CAMLreturn(caml_copy_string(((ocaml_framebox*)symbol)->data()));
    }

    CAMLprim value framebox_set_data(value symbol, value data)
    {
        CAMLparam2(symbol, data);
        ((ocaml_framebox*)symbol)->data(String_val(data));
        CAMLreturn(Val_unit);
    }



    
}
