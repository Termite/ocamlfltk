#include "odivider.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_Divider(value name)
    {
        CAMLparam1(name);
        o_Divider* widget =
            new o_Divider(caml_named_value(String_val(name)));
        CAMLreturn((value) widget);
    }

    CAMLprim value divider_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Divider*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value divider_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Divider*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }


}

