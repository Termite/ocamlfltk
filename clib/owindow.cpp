#include "owindow.h"

namespace Ofltk {

char Window_id[] = "window-director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_window(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_window* widget = new ocaml_window(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_window_bc(value* args, int argc)
    {
        return new_window(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value window_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((ocaml_window*) widget)->default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value window_draw(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    static void widget_cb(fltk::Widget* widget, value* caml_cb)
    {
        caml_callback(*caml_cb, Val_unit);
    }

    CAMLprim value set_window_cb(value window, value fkt)
    {
        CAMLparam2(window, fkt);
        value* cb = caml_named_value(String_val(fkt));             
//        ((ocaml_widget*) window)->callback_fkt = caml_named_value(String_val(fkt));
        ((ocaml_widget*) window)
            ->callback((fltk::Callback*)widget_cb, (void*)cb);
        CAMLreturn(Val_unit);
    }

}
