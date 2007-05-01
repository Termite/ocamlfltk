#include "ovaluator.h"

namespace Ofltk {

char Slider_id[] = "slider-director";
char ValueSlider_id[] = "valueslider-director";
char Valuator_id[] = "valuator-director";
char ValueInput_id[] = "valueinput-director";
char ValueOutput_id[] = "valueoutput-director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value valuator_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Valuator*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value valuator_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Valuator*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value valuator_set_range(value widget, value a, value b)
    {
        CAMLparam3(widget, a, b);
        ((fltk::Valuator*) widget)->range(Double_val(a), Double_val(b));
        CAMLreturn(Val_unit);
    }


    CAMLprim value valuator_set_value(value widget, value v)
    {
        CAMLparam2(widget, v);
        int n = ((fltk::Valuator*) widget)->value(Double_val(v));
        CAMLreturn(Val_int(n));
    }


    CAMLprim value valuator_set_step(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((fltk::Valuator*) widget)->step(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value valuator_set_max(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((fltk::Valuator*) widget)->maximum(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value valuator_set_min(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((fltk::Valuator*) widget)->minimum(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value get_linesize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Valuator*) widget)->linesize()));
    }

    CAMLprim value valuator_get_max(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Valuator*) widget)->maximum()));
    }

    CAMLprim value valuator_get_min(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Valuator*) widget)->minimum()));
    }

    CAMLprim value valuator_get_step(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Valuator*) widget)->step()));
    }

    CAMLprim value valuator_get_value(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Valuator*) widget)->value()));
    }

    CAMLprim value new_slider(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_Slider* widget = new o_Slider(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_slider_bc(value* args, int argc)
    {
        return new_slider(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value slider_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Slider*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value slider_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Slider*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value slider_get_ticksize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Slider*)widget)->tick_size()));
    }

    CAMLprim value slider_get_slidersize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Slider*)widget)->slider_size()));
    }

    CAMLprim value slider_set_ticksize(value widget, value n)
    {
        CAMLparam2(widget, n);
        ((fltk::Slider*)widget)->tick_size(Int_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value slider_set_slidersize(value widget, value n)
    {
        CAMLparam2(widget, n);
        ((fltk::Slider*)widget)->slider_size(Int_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value new_valueslider(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_ValueSlider* widget = new o_ValueSlider(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_valueslider_bc(value* args, int argc)
    {
        return new_valueslider(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value valueslider_get_input(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)&(((fltk::ValueSlider*)widget)->input));
    }

    CAMLprim value valueslider_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ValueSlider*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value valueslider_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ValueSlider*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }



    CAMLprim value new_valueinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_ValueInput* widget = new o_ValueInput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_valueinput_bc(value* args, int argc)
    {
        return new_valueinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value valueinput_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ValueInput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value valueinput_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ValueInput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value new_valueoutput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_ValueOutput* widget = new o_ValueOutput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_valueoutput_bc(value* args, int argc)
    {
        return new_valueoutput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value valueoutput_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ValueOutput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value valueoutput_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ValueOutput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

}
