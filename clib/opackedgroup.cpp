#include "opackedgroup.h"

namespace Ofltk {

    char PackedGroup_id[] = "PackedGroup-director";    
    char BarGroup_id[] = "BarGroup-director";
}

using namespace Ofltk;

extern "C" {

    GEN_NEW(PackedGroup)
    GEN_NEW(BarGroup)
    
    CAMLprim value bargroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_BarGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value bargroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_BarGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value packedgroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_PackedGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value packedgroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_PackedGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value packedgroup_set_spacing(value group, value data)
    {
        CAMLparam2(group, data);
        fltk::PackedGroup* b = (fltk::PackedGroup*) group;
        b->spacing(Int_val(data));
        CAMLreturn(Val_unit);
    }

    CAMLprim value packedgroup_get_spacing(value group)
    {
        CAMLparam1(group);
        fltk::PackedGroup* b = (fltk::PackedGroup*) group;
        CAMLreturn(Val_int(b->spacing()));
    }

    CAMLprim value bargroup_get_opened(value bargroup)
    {
        CAMLparam1(bargroup);
        fltk::BarGroup* b = (fltk::BarGroup*) bargroup;
        CAMLreturn(Val_int(b->opened()));
    }

    CAMLprim value bargroup_set_opened(value bargroup, value data)
    {
        CAMLparam2(bargroup, data);
        fltk::BarGroup* b = (fltk::BarGroup*) bargroup;
        CAMLreturn(Val_int(b->opened(bool(Int_val(data)))));
    }

    CAMLprim value bargroup_open(value bargroup)
    {
        CAMLparam1(bargroup);
        fltk::BarGroup* b = (fltk::BarGroup*) bargroup;
        CAMLreturn(Val_int(b->open()));
    }

    CAMLprim value bargroup_close(value bargroup)
    {
        CAMLparam1(bargroup);
        fltk::BarGroup* b = (fltk::BarGroup*) bargroup;
        CAMLreturn(Val_int(b->close()));
    }


    

}

