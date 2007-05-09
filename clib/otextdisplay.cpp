#include "otextdisplay.h"


namespace Ofltk {

char TextDisplay_id[] = "TextDisplay";

}


using namespace Ofltk;
extern "C" {

    CAMLprim value new_textDisplay(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_TextDisplay* widget = new o_TextDisplay(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_textDisplay_bc(value* args, int argc)
    {
        return new_textDisplay(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value textDisplay_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_TextDisplay*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value textDisplay_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_TextDisplay*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value textDisplay_wrap_mode(value widget, value margin, value wrap)
    {
        CAMLparam3(widget, wrap, margin);
        ((fltk::TextDisplay*) widget) -> wrap_mode(Bool_val(wrap), Int_val(margin));
        CAMLreturn(Val_unit);
    }

    CAMLprim value textDisplay_set_text(value widget, value text)
    {
        CAMLparam2(widget, text);
        ((fltk::TextDisplay*) widget) -> text(String_val(text));
        CAMLreturn(Val_unit);
    }

    CAMLprim value textDisplay_get_text(value widget)
    {
        CAMLparam1(widget);
        const char* t = ((fltk::TextDisplay*) widget) -> text();
        CAMLreturn(caml_copy_string(t));
    }

    CAMLprim value textDisplay_set_buffer(value widget, value buffer)
    {
        CAMLparam2(widget, buffer);
        ((fltk::TextDisplay*) widget) -> buffer((fltk::TextBuffer*) buffer); 
        CAMLreturn(Val_unit);
    }

    CAMLprim value textDisplay_get_buffer(value widget)
    {
        CAMLparam1(widget);
        const fltk::TextBuffer* b = ((fltk::TextDisplay*) widget) -> buffer();
        CAMLreturn((value) b);
    }



}
