#include "ochoices.h"

namespace Ofltk {
    char Choice_id[] = "Choice-director";
    char CycleButton_id[] = "Cyclebutton-director";
    char PopupMenu_id[] = "Popupmenu-director";
}

using namespace Ofltk;

extern "C" {

    GEN_NEW(Choice);
    GEN_NEW(CycleButton);
    GEN_NEW(PopupMenu);

    CAMLprim value choice_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Choice*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value choice_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Choice*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value cyclebutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_CycleButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value cyclebutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_CycleButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value popup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_PopupMenu*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value popup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_PopupMenu*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

}
