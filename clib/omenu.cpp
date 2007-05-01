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

    CAMLprim value menu_children(value widget)
    {
        CAMLparam1(widget);
        int r = ((fltk::Menu*) widget) -> children();
        CAMLreturn(Val_int(r));
    }

    CAMLprim value menu_value(value widget)
    {
        CAMLparam1(widget);
        int r = ((fltk::Menu*) widget) -> value();
        CAMLreturn(Val_int(r));
    }

    CAMLprim value menu_set_value(value widget, value v)
    {
        CAMLparam2(widget, v);
        int r = ((fltk::Menu*) widget) -> value(Int_val(v));
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

