#include "oinput.h"

namespace Ofltk {

char Input_id[] = "input-director";
char NumericInput_id[] = "numinput-director";
char FloatInput_id[] = "floatinput-director";
char IntInput_id[] = "intinput-director";

}


using namespace Ofltk;

extern "C" {

    CAMLprim value input_get_text(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_string(((ocaml_input*)widget)->get_text()));
    }

    CAMLprim value input_set_text(value widget, value txt)
    {
        CAMLparam2(widget, txt);
        bool r = ((ocaml_input*)widget)->set_text(String_val(txt));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value new_floatinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_floatinput* widget = new ocaml_floatinput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_floatinput_bc(value* args, int argc)
    {
        return new_floatinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value new_intinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_intinput* widget = new ocaml_intinput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_intinput_bc(value* args, int argc)
    {
        return new_intinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value numinput_set_valued(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((ocaml_numinput*)widget)->set_value_d(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value numinput_set_valuei(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((ocaml_numinput*)widget)->set_value_i(Int_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value floatinput_get_valued(value widget)
    {
        CAMLparam1(widget);
        double e = ((ocaml_floatinput*)widget)->get_value_d();
        CAMLreturn(caml_copy_double(e)); 
    }

    CAMLprim value floatinput_get_valuei(value widget)
    {
        CAMLparam1(widget);
        int e = ((ocaml_floatinput*)widget)->get_value_i();
        CAMLreturn(Val_int(e));
    }

}
