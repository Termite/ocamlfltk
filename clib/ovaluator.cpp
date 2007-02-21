#include "ovaluator.h"

namespace Ofltk {

char Slider_id[] = "slider-director";
char Valuator_id[] = "valuator-director";
char ValueInput_id[] = "valueinput-director";
char ValueOutput_id[] = "valueoutput-director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value valuator_set_range(value widget, value a, value b)
    {
        CAMLparam3(widget, a, b);
        ((ocaml_valuator*) widget)->set_range(Double_val(a), Double_val(b));
        CAMLreturn(Val_unit);
    }


    CAMLprim value valuator_set_value(value widget, value v)
    {
        CAMLparam2(widget, v);
        int n = ((ocaml_valuator*) widget)->new_value(Double_val(v));
        CAMLreturn(Val_int(n));
    }


    CAMLprim value valuator_set_step(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((ocaml_valuator*) widget)->set_step(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value valuator_set_max(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((ocaml_valuator*) widget)->set_maximum(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value valuator_set_min(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((ocaml_valuator*) widget)->set_minimum(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value get_linesize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_valuator*) widget)->get_linesize()));
    }

    CAMLprim value valuator_get_max(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_valuator*) widget)->get_maximum()));
    }

    CAMLprim value valuator_get_min(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_valuator*) widget)->get_minimum()));
    }

    CAMLprim value valuator_get_step(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_valuator*) widget)->get_step()));
    }

    CAMLprim value valuator_get_value(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_valuator*) widget)->get_value()));
    }

    CAMLprim value new_slider(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_slider* widget = new ocaml_slider(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_slider_bc(value* args, int argc)
    {
        return new_slider(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value slider_get_ticksize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((ocaml_slider*)widget)->get_tick_size()));
    }

    CAMLprim value slider_get_slidersize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((ocaml_slider*)widget)->get_slider_size()));
    }

    CAMLprim value slider_set_ticksize(value widget, value n)
    {
        CAMLparam2(widget, n);
        ((ocaml_slider*)widget)->set_tick_size(Int_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value slider_set_slidersize(value widget, value n)
    {
        CAMLparam2(widget, n);
        ((ocaml_slider*)widget)->set_slider_size(Int_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value new_valueinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_valueinput* widget = new ocaml_valueinput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_valueinput_bc(value* args, int argc)
    {
        return new_valueinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value new_valueoutput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_valueoutput* widget = new ocaml_valueoutput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_valueoutput_bc(value* args, int argc)
    {
        return new_valueoutput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

}
