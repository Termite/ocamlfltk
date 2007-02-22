#include "opackedgroup.h"

namespace Ofltk {

    char PackedGroup_id[] = "PackedGroup-director";    
    char BarGroup_id[] = "BarGroup-director";
}

using namespace Ofltk;

extern "C" {

    MAKE_NEW(packedgroup)
    MAKE_NEW(bargroup)
    
    CAMLprim value packedgroup_set_spacing(value group, value data)
    {
        CAMLparam2(group, data);
        ocaml_packedgroup* b = (ocaml_packedgroup*) group;
        b->spacing(Int_val(data));
        CAMLreturn(Val_unit);
    }

    CAMLprim value packedgroup_get_spacing(value group)
    {
        CAMLparam1(group);
        ocaml_packedgroup* b = (ocaml_packedgroup*) group;
        CAMLreturn(Val_int(b->spacing()));
    }

    CAMLprim value bargroup_get_opened(value bargroup)
    {
        CAMLparam1(bargroup);
        ocaml_bargroup* b = (ocaml_bargroup*) bargroup;
        CAMLreturn(Val_int(b->opened()));
    }

    CAMLprim value bargroup_set_opened(value bargroup, value data)
    {
        CAMLparam2(bargroup, data);
        ocaml_bargroup* b = (ocaml_bargroup*) bargroup;
        CAMLreturn(Val_int(b->opened(bool(Int_val(data)))));
    }

    CAMLprim value bargroup_open(value bargroup)
    {
        CAMLparam1(bargroup);
        ocaml_bargroup* b = (ocaml_bargroup*) bargroup;
        CAMLreturn(Val_int(b->open()));
    }

    CAMLprim value bargroup_close(value bargroup)
    {
        CAMLparam1(bargroup);
        ocaml_bargroup* b = (ocaml_bargroup*) bargroup;
        CAMLreturn(Val_int(b->close()));
    }


    

}

