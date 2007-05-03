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
        o_Window* widget = new o_Window(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
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
        int r = ((o_Window*) widget)->default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value window_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Window*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_show(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Window*)widget) -> show();
        CAMLreturn(Val_unit);
    }

    typedef char* char_p;

    CAMLprim value window_show_args(value widget, value args)
    {
        CAMLparam2(widget, args);
        int size = Wosize_val(args);
        char** argv = size ? new char_p [size] : 0;
        for (int i=0; i < size; ++i) {
            argv[i] = String_val(Field(args,i));
        }
        ((fltk::Window*)widget) -> show(size, argv);
        if (argv) delete[] argv;
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_set_doublebuffer(value window)
    {
        CAMLparam1(window);
        ((fltk::Window*) window)->set_double_buffer();
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_clear_doublebuffer(value window)
    {
        CAMLparam1(window);
        ((fltk::Window*) window)->clear_double_buffer();
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_border(value window, value set)
    {
        CAMLparam2(window, set);
        ((fltk::Window*) window)->border(Int_val(set));
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_borders(value window)
    {
        CAMLparam1(window);
	CAMLlocal1(e);
        fltk::Rectangle r;
	((fltk::Window*) window)->borders(&r);
	e = caml_alloc_small(4,0);
	Field(e,0) = r.x();
	Field(e,1) = r.y();
	Field(e,2) = r.w();
	Field(e,3) = r.h();
        CAMLreturn(e);
    }

    CAMLprim value window_hide(value window)
    {
        CAMLparam1(window);
        ((fltk::Window*) window)->hide();
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_iconize(value window)
    {
        CAMLparam1(window);
        ((fltk::Window*) window)->iconize();
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_iconic(value window)
    {
        CAMLparam1(window);
        bool i = ((fltk::Window*) window)->iconic();
        CAMLreturn(Val_bool(i));
    }

    CAMLprim value window_hotspot_xy(value window, value off, value x, value y)
    {
        CAMLparam4(window, off, x, y);
        ((fltk::Window*) window)->hotspot(Int_val(x), Int_val(y), Int_val(off));
        CAMLreturn(Val_unit);
    }

    CAMLprim value window_hotspot_widget(value window, value off, value widget)
    {
        CAMLparam3(window, off, widget);
        ((fltk::Window*) window)->hotspot((fltk::Widget*) widget, Int_val(off));
        CAMLreturn(Val_unit);
    }


}
