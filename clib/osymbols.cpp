#include "osymbols.h"

using namespace Ofltk;

extern "C" {


    CAMLprim value make_symbol(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        ocaml_symbol* s =
            new ocaml_symbol(caml_named_value(String_val(_draw)), String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value symbol_measure(value symbol)
    {
        CAMLparam1(symbol);
        CAMLlocal1(erg);
        int w, h;
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
        CAMLreturn(caml_copy_string(n));
    }




    
}
