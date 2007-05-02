#include "otabgroup.h"

namespace Ofltk {

    char TabGroup_id[] = "TabGroup director";

}

using namespace Ofltk;

extern "C" {

    GEN_NEW(TabGroup);

    CAMLprim value tabgroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_TabGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value tabgroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_TabGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    
    CAMLprim value tabgroup_get_value(value tabgroup)
    {
        CAMLparam1(tabgroup);
        fltk::TabGroup* b = (fltk::TabGroup*) tabgroup;
        CAMLreturn(Val_int(b->value()));
    }

    CAMLprim value tabgroup_set_value(value tabgroup, value data)
    {
        CAMLparam2(tabgroup, data);
        fltk::TabGroup* b = (fltk::TabGroup*) tabgroup;
        CAMLreturn(Val_bool(b->value(Int_val(data))));
    }

    CAMLprim value tabgroup_set_selected_child(value tabgroup, value widget)
    {
        CAMLparam2(tabgroup, widget);
        fltk::TabGroup* b = (fltk::TabGroup*) tabgroup;
        CAMLreturn(Val_bool(b->selected_child((fltk::Widget*)(widget))));
    }

}
