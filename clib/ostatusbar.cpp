#include "ostatusbar.h"
#include "osymbols.h"

namespace Ofltk {

char StatusBarGroup_id[] = "StatusBarGroup";

}

using namespace Ofltk;

extern "C" {

    GEN_NEW(StatusBarGroup);

    CAMLprim value new_easy_statusbar(value name, value height) 
    {
        CAMLparam2(name, height);
        o_StatusBarGroup* widget = new o_StatusBarGroup(caml_named_value(String_val(name)), Int_val(height));
        CAMLreturn((value) widget);
    }

    CAMLprim value statusbar_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_StatusBarGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value statusbar_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_StatusBarGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value statusbar_set_text(value widget, value pos, value text)
    {
       CAMLparam3(widget, pos, text); 
       ((fltk::StatusBarGroup*) widget)->set(String_val(text), fltk::StatusBarGroup::Position(Int_val(pos)));
       CAMLreturn(Val_unit);
    }

    CAMLprim value statusbar_child_box(value widget, value box, value pos)
    {
       CAMLparam3(widget, box, pos);
       ((fltk::StatusBarGroup*) widget)->child_box((fltk::Box*) box, fltk::StatusBarGroup::Position(Int_val(pos)));
       CAMLreturn(Val_unit);
    }



}
