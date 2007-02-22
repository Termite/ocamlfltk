#include "oscrollgroup.h"

namespace Ofltk {
    char ScrollGroup_id[] = "Scrollgroup-director";
}

using namespace Ofltk;

extern "C" {
    
    MAKE_NEW(scrollgroup);

    CAMLprim value scrollgroup_xpos(value sc)
    {
        CAMLparam1(sc);
        ocaml_scrollgroup* b = (ocaml_scrollgroup*) sc;
        CAMLreturn(Val_int(b->xpos()));
    }

    CAMLprim value scrollgroup_ypos(value sc)
    {
        CAMLparam1(sc);
        ocaml_scrollgroup* b = (ocaml_scrollgroup*) sc;
        CAMLreturn(Val_int(b->ypos()));
    }

    CAMLprim value scrollgroup_scroll_to(value sc, value x, value y)
    {
        CAMLparam3(sc, x, y);
        ocaml_scrollgroup* b = (ocaml_scrollgroup*) sc;
        b->scroll_to(Int_val(x), Int_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value scrollgroup_type(value sc, value typ)
    {
        CAMLparam2(sc, typ);
        ocaml_scrollgroup* b = (ocaml_scrollgroup*) sc;
        b->set_type(1 + Int_val(typ));
        CAMLreturn(Val_unit);
    }

    
}

