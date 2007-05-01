#include "omenu.h"

namespace Ofltk {
    char Menu_id[] = "menu-director";
    char MenuBar_id[] = "menubar-director";
}

using namespace Ofltk;

extern "C" {

    GEN_NEW(Menu);
    GEN_NEW(MenuBar);

    CAMLprim value menu_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Menu*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value menu_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Menu*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value menubar_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_MenuBar*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value menubar_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_MenuBar*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }


     
}

