#include "owidget.h"

#include <fltk/run.h>
#include <fltk/Widget.h>
#include <fltk/Font.h>
#include <fltk/draw.h>
#include <fltk/ask.h>
#include "osymbols.h"

namespace Ofltk {

char Widget_id[] = "widget-director";
char InvisibleBox_id[] = "invisible-director";

}

using namespace Ofltk;

extern "C" {
    

    CAMLprim value output_ptr(value a)
    {
        CAMLparam1(a);
        std::cout << "p: " << (void*)a << std::endl;
        CAMLreturn(Val_unit);
    }

    CAMLprim value cmp_pointer(value a, value b)
    {
        CAMLparam2(a,b);
        //std::cout << "a: " << (void*)a << " b: " << (void*)b << std::endl;
        CAMLreturn(Val_int((void*)a == (void*)b));
    }

    CAMLprim value get_null_widget(value nix)
    {
        CAMLparam1(nix);
        CAMLreturn(Val_int(0));
    }


    /* ============================================================ */

    CAMLprim value new_widget(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_widget* widget = new ocaml_widget(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_widget_bc(value* args, int argc)
    {
        return new_widget(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value make_objwidget(value name, value widget)
    {
        CAMLparam2(name, widget);
        value* ocaml_obj = caml_named_value(String_val(name));
        ((ocaml_widget*) widget)->store_obj(ocaml_obj);
        CAMLreturn(widget);
    }

    CAMLprim value widget_hide(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*)widget) -> hide();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_show(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*)widget) -> show();
        CAMLreturn(Val_unit);
    }

    CAMLprim value redraw_widget(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*)widget)->redraw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_tooltip(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((ocaml_widget*) widget)->tooltip()));
    }

    CAMLprim value widget_set_tooltip(value widget, value tooltip)
    {
        CAMLparam2(widget, tooltip);
        ((ocaml_widget*) widget)->tooltip(String_val(tooltip));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((ocaml_widget*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value widget_draw(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_vertical(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*) widget) -> set_vertical();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_horizontal(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*) widget) -> set_horitontal();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_image(value widget, value image)
    {
        CAMLparam2(widget, image);
        ((ocaml_widget*) widget)->image(((ocaml_symbol*)image));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_image(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((ocaml_widget*) widget)->image()));
    }

    CAMLprim value widget_set_box(value widget, value box)
    {
        CAMLparam2(widget, box);
        ((ocaml_widget*) widget)->set_box(((ocaml_symbol*)box)->dest_symbol());
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_box(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((ocaml_widget*) widget)->get_box()));
    }

    CAMLprim value widget_damage(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((ocaml_widget*) widget)->damage()));
    }

    CAMLprim value widget_relayout(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_widget*) widget) -> relayout();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_label(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((ocaml_widget*) widget) -> label()));
    }

    CAMLprim value widget_get_labelsize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((ocaml_widget*) widget) -> labelsize()));
    }

    CAMLprim value widget_set_labelsize(value widget, value size)
    {
        CAMLparam2(widget, size);
        ((ocaml_widget*) widget) -> labelsize(Double_val(size));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_type(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((ocaml_widget*) widget) -> get_type()));
    }

    CAMLprim value widget_set_type(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((ocaml_widget*) widget) -> set_type(Int_val(typ));
        CAMLreturn(Val_unit);
    }
    CAMLprim value widget_get_when(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((ocaml_widget*) widget) -> get_when()));
    }

    CAMLprim value widget_set_when(value widget, value when)
    {
        CAMLparam2(widget, when);
        ((ocaml_widget*) widget) -> set_when(Int_val(when));
        CAMLreturn(Val_unit);
    }
    CAMLprim value widget_set_labelfont(value widget, value font)
    {
        CAMLparam2(widget, font);
        ((ocaml_widget*) widget)->labelfont((fltk::Font*) font);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_labelfont(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)((ocaml_widget*) widget)->labelfont());
    }

/*
    CAMLprim value widget_labeltype(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((ocaml_widget*) widget)->labeltype((LabelType*) typ);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_box(value widget, value boxtyp)
    {
        CAMLparam2(widget, boxtyp);
        ((ocaml_widget*) widget)->box((Box*)boxtyp);
        CAMLreturn(Val_unit);
    }
*/
    CAMLprim value get_width(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((ocaml_rect*) rect)-> w()));
    }

    CAMLprim value get_height(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((ocaml_rect*) rect)-> h()));
    }

    CAMLprim value get_x(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((ocaml_rect*) rect)-> x()));
    }

    CAMLprim value get_y(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((ocaml_rect*) rect)-> y()));
    }

/*
    CAMLprim value set_widget_callback(value widget, value fkt)
    {
        CAMLparam2(widget, fkt);
        ((ocaml_widget*)widget)->set_caml_cb(fkt);
        CAMLreturn(Val_unit);
    }
*/
    CAMLprim value widget_set_color(value widget, value color)
    {
        CAMLparam2(widget, color);
        ((ocaml_widget*) widget)->color(Int32_val(color));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_label(value widget, value label)
    {
        CAMLparam2(widget, label);
        ((ocaml_widget*) widget)->copy_label(String_val(label));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_flags(value widget)
    {
       CAMLparam1(widget);
       CAMLreturn(Val_int(((ocaml_widget*) widget)-> flags()));
    }

    CAMLprim value widget_set_flags(value widget, value flags)
    {
       CAMLparam2(widget, flags);
       ((ocaml_widget*) widget)->flags(Int_val(flags));
       CAMLreturn(Val_unit);
    }

    CAMLprim value widget_resize(value widget, value xy, value w, value h)
    {
       CAMLparam4(widget, xy, w, h);
       bool r;
       if (Is_long(xy)) 
       {
           std::cout << "no xy " << std::endl;
            r = ((ocaml_widget*) widget)->resize(Int_val(w), Int_val(h));
       }
       else
       {
           value p = Field(xy,0);
           int x = Int_val(Field(p,0));
           int y = Int_val(Field(p,1));
           std::cout << "x: " << x << " y: " << y << std::endl;
           r = ((ocaml_widget*) widget)->resize(x, y, Int_val(w), Int_val(h));
       }
       CAMLreturn(Val_int(r));
    }


    CAMLprim value new_invisible(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_invisiblebox* widget = new ocaml_invisiblebox(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_invisible_bc(value* args, int argc)
    {
        return new_invisible(args[0],args[1],args[2],args[3],args[4],args[5]);
    }


}

