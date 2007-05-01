#include "ooutput.h"

namespace Ofltk {
    char Output_id[] = "output-director";
    char MultiLineOutput_id[] = "multiline-director";
    char WordwrapOutput_id[] = "wordwrap-director";
}

using namespace Ofltk;

extern "C" {
    GEN_NEW(Output);
    GEN_NEW(MultiLineOutput);
    GEN_NEW(WordwrapOutput);

    CAMLprim value output_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Output*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value output_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Output*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value multiline_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_MultiLineOutput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value multiline_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_MultiLineOutput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value wordwrap_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_WordwrapOutput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value wordwrap_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_WordwrapOutput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

}

