#include "oinput.h"

namespace Ofltk {

char Input_id[] = "input-director";
char NumericInput_id[] = "numinput-director";
char FloatInput_id[] = "floatinput-director";
char IntInput_id[] = "intinput-director";

}


using namespace Ofltk;

extern "C" {

    GEN_NEW(Input);
    GEN_NEW(NumericInput);

    CAMLprim value input_default_style(value button)
    {
        CAMLparam1(button);
        CAMLreturn((value)(fltk::Input::default_style));
    }

    CAMLprim value input_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Input*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value input_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Input*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value input_cut(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Input*) widget) -> cut();
        CAMLreturn(Val_unit);
    }

    CAMLprim value input_position(value widget, value a, value b)
    {
        CAMLparam3(widget, a, b);
        ((fltk::Input*) widget) -> position(Int_val(a), Int_val(b));
        CAMLreturn(Val_unit);
    }

    CAMLprim value input_reserve(value widget, value s)
    {
        CAMLparam2(widget, s);
        ((fltk::Input*) widget) -> reserve(Int_val(s));
        CAMLreturn(Val_unit);
    }

    CAMLprim value input_undo(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Input*) widget) -> undo();
        CAMLreturn(Val_unit);
    }

    CAMLprim value input_cut_chrs(value widget, value n)
    {
        CAMLparam2(widget, n);
        int p = ((fltk::Input*) widget) -> cut(Int_val(n));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_at(value widget, value pos)
    {
        CAMLparam2(widget, pos);
        int p = ((fltk::Input*) widget) -> at(Int_val(pos));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_insert(value widget, value text)
    {
        CAMLparam2(widget, text);
        bool p = ((fltk::Input*) widget) -> insert(String_val(text));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_copy(value widget, value clipboard)
    {
        CAMLparam2(widget, clipboard);
        bool p = ((fltk::Input*) widget) -> copy(Int_val(clipboard));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_word_start(value widget, value i)
    {
        CAMLparam2(widget, i);
        int p = ((fltk::Input*) widget) -> word_start(Int_val(i));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_word_end(value widget, value i)
    {
        CAMLparam2(widget, i);
        int p = ((fltk::Input*) widget) -> word_end(Int_val(i));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_line_end(value widget, value i)
    {
        CAMLparam2(widget, i);
        int p = ((fltk::Input*) widget) -> line_end(Int_val(i));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_line_start(value widget, value i)
    {
        CAMLparam2(widget, i);
        int p = ((fltk::Input*) widget) -> line_start(Int_val(i));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_size(value widget)
    {
        CAMLparam1(widget);
        int p = ((fltk::Input*) widget) -> size();
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_get_position(value widget)
    {
        CAMLparam1(widget);
        int p = ((fltk::Input*) widget) -> position();
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_get_mark(value widget)
    {
        CAMLparam1(widget);
        int p = ((fltk::Input*) widget) -> mark();
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_replace(value widget, value b, value e, value text, value ilen)
    {
        CAMLparam5(widget, b, e, text, ilen);
        bool p = ((fltk::Input*) widget) -> replace(Int_val(b), Int_val(e), 
                String_val(text), Int_val(ilen));
        CAMLreturn(Val_int(p));
    }

    CAMLprim value input_set_text(value widget, value txt)
    {
        CAMLparam2(widget, txt);
        bool r = ((fltk::Input*)widget)->text(String_val(txt));
        CAMLreturn(Val_int(r));
    }


    CAMLprim value input_get_text(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((fltk::Input*)widget)->text()));
    }

    CAMLprim value input_set_text_len(value widget, value txt, value len)
    {
        CAMLparam3(widget, txt, len);
        bool r = ((fltk::Input*)widget)->text(String_val(txt), Int_val(len));
        CAMLreturn(Val_bool(r));
    }

    CAMLprim value new_floatinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_FloatInput* widget = new o_FloatInput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_floatinput_bc(value* args, int argc)
    {
        return new_floatinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value floatInput_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_FloatInput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value floatInput_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_FloatInput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value new_intinput(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_IntInput* widget = new o_IntInput(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_intinput_bc(value* args, int argc)
    {
        return new_intinput(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value intInput_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_IntInput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value intInput_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_IntInput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value numInput_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_NumericInput*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value numInput_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_NumericInput*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }


    CAMLprim value numinput_set_valued(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((fltk::NumericInput*)widget)->value(Double_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value numinput_set_valuei(value widget, value v)
    {
        CAMLparam2(widget, v);
        ((fltk::NumericInput*)widget)->value(Int_val(v));
        CAMLreturn(Val_unit);
    }

    CAMLprim value floatinput_get_valued(value widget)
    {
        CAMLparam1(widget);
        double e = ((fltk::FloatInput*)widget)->fvalue();
        CAMLreturn(caml_copy_double(e)); 
    }

    CAMLprim value floatinput_get_valuei(value widget)
    {
        CAMLparam1(widget);
        int e = ((fltk::FloatInput*)widget)->ivalue();
        CAMLreturn(Val_int(e));
    }

}
