#include "obutton.h"

namespace Ofltk {

char Button_id[] = "button-director";
char CheckButton_id[] = "checkbutton-director";
char LightButton_id[] = "lightbutton-director";
char RadioButton_id[] = "radio-director";
char HighlightButton_id[] = "highlight-director";
char RepeatButton_id[] = "repeat-director";
char ReturnButton_id[] = "return-director";
char ToggleButton_id[] = "toggle-director";
}

using namespace Ofltk;
extern "C" {

    CAMLprim value new_button(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_Button* widget = new o_Button(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_button_bc(value* args, int argc)
    {
        return new_button(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value button_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Button*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value button_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Button*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value button_default_style(value button)
    {
        CAMLparam1(button);
        CAMLreturn((value)(fltk::Button::default_style));
    }

    CAMLprim value button_value(value button)
    {
        CAMLparam1(button);
        fltk::Button* b = (fltk::Button*) button;
        CAMLreturn(Val_int(b->value()));
    }

    CAMLprim value button_set_value(value button, value data)
    {
        CAMLparam2(button, data);
        fltk::Button* b = (fltk::Button*) button;
        CAMLreturn(Val_int(b->value(Int_val(data))));
    }

    GEN_NEW(CheckButton);
    GEN_NEW(LightButton);
    GEN_NEW(RadioButton);
    GEN_NEW(HighlightButton);
    GEN_NEW(RepeatButton);
    GEN_NEW(ReturnButton);
    GEN_NEW(ToggleButton);

    CAMLprim value checkbutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_CheckButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value checkbutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_CheckButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value lightbutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_LightButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value lightbutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_LightButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value radiobutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_RadioButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value radiobutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_RadioButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value highlightbutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_HighlightButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value highlightbutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_HighlightButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value repeatbutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_RepeatButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value repeatbutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_RepeatButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value returnbutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ReturnButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value returnbutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ReturnButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value togglebutton_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ToggleButton*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value togglebutton_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ToggleButton*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

}
