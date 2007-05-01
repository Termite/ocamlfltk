#include "oitem.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_Item(value name, value item)
    {
        CAMLparam2(name, item);
        o_Item* widget =
            new o_Item(caml_named_value(String_val(name)), String_val(item));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_ItemGroup(value name, value item)
    {
        CAMLparam2(name, item);
        o_ItemGroup* widget =
            new o_ItemGroup(caml_named_value(String_val(name)), String_val(item));
        CAMLreturn((value) widget);
    }

    CAMLprim value item_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Item*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value item_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Item*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value itemgroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ItemGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value itemgroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ItemGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }



}
