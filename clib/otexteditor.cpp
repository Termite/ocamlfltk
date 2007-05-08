#include "otexteditor.h"

namespace Ofltk {

char TextEditor_id[] = "TextEditor";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_textEditor(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_TextEditor* widget = new o_TextEditor(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_textEditor_bc(value* args, int argc)
    {
        return new_textEditor(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value textEditor_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_TextEditor*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value textEditor_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_TextEditor*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

}

