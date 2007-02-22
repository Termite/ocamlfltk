#include "otabgroup.h"

namespace Ofltk {

    char TabGroup_id[] = "TabGroup director";

}

using namespace Ofltk;

extern "C" {

    MAKE_NEW(tabgroup);
    
    CAMLprim value tabgroup_get_value(value tabgroup)
    {
        CAMLparam1(tabgroup);
        ocaml_tabgroup* b = (ocaml_tabgroup*) tabgroup;
        CAMLreturn(Val_int(b->get_value()));
    }

    CAMLprim value tabgroup_set_value(value tabgroup, value data)
    {
        CAMLparam2(tabgroup, data);
        ocaml_tabgroup* b = (ocaml_tabgroup*) tabgroup;
        CAMLreturn(Val_int(b->set_value(Int_val(data))));
    }

}
