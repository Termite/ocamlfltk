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
    
    CAMLprim value fltk_redraw(value a)
    {
        CAMLparam1(a);
        fltk::redraw(); 
        CAMLreturn(Val_unit);
    }


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
        CAMLreturn((value)0);
    }
	
    /* XXX TEST */
    
    CAMLprim value s_new_widget(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_Widget* widget = new o_Widget(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value s_new_widget_bc(value* args, int argc)
    {
        return s_new_widget(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value widget_active(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_bool(((fltk::Widget*)widget) -> active()));
    }

    CAMLprim value widget_draw_box(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget) -> draw_box();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_activate(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget) -> activate();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_deactivate(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget) -> deactivate();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_hide(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget) -> hide();
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_show(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget) -> show();
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_redraw_widget(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*)widget)->redraw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_tooltip(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((fltk::Widget*) widget)->tooltip()));
    }

    CAMLprim value widget_set_tooltip(value widget, value tooltip)
    {
        CAMLparam2(widget, tooltip);
        ((fltk::Widget*) widget)->tooltip(String_val(tooltip));
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Widget*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value s_widget_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Widget*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_set_vertical(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> set_vertical();
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_set_horizontal(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> set_horizontal();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_align(value widget, value flags)
    {
        CAMLparam2(widget, flags);
        ((fltk::Widget*) widget)->align(Int_val(flags));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_scrollbar_width(value sc, value width)
    {
        CAMLparam2(sc, width);
        fltk::Widget* b = (fltk::Widget*) sc;
        b->scrollbar_width(Int_val(width));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_scrollbar_align(value sc, value typ)
    {
        CAMLparam2(sc, typ);
        fltk::Widget* b = (fltk::Widget*) sc;
        b->scrollbar_align(Int_val(typ));
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_set_image(value widget, value image)
    {
        CAMLparam2(widget, image);
        ((fltk::Widget*) widget)->image(((fltk::Symbol*)image));
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_get_image(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((fltk::Widget*) widget)->image()));
    }

    CAMLprim value widget_set_box(value widget, value box)
    {
        CAMLparam2(widget, box);
        ((fltk::Widget*) widget)->box((fltk::Symbol*)box);
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_get_box(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((fltk::Widget*) widget)->box()));
    }

    CAMLprim value s_widget_damage(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget)->damage()));
    }

    CAMLprim value s_widget_relayout(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> relayout();
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_label(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((fltk::Widget*) widget) -> label()));
    }

    CAMLprim value s_widget_get_labelsize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Widget*) widget) -> labelsize()));
    }

    CAMLprim value s_widget_set_labelsize(value widget, value size)
    {
        CAMLparam2(widget, size);
        ((fltk::Widget*) widget) -> labelsize(Double_val(size));
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_get_type(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget) -> type()));
    }

    CAMLprim value s_widget_set_type(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((fltk::Widget*) widget) -> type(Int_val(typ));
        CAMLreturn(Val_unit);
    }
    CAMLprim value s_widget_get_when(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget) -> when()));
    }

    CAMLprim value s_widget_set_when(value widget, value when)
    {
        CAMLparam2(widget, when);
        ((fltk::Widget*) widget) -> when(Int_val(when));
        CAMLreturn(Val_unit);
    }
    CAMLprim value s_widget_set_labelfont(value widget, value font)
    {
        CAMLparam2(widget, font);
        ((fltk::Widget*) widget)->labelfont((fltk::Font*) font);
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_get_labelfont(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)((fltk::Widget*) widget)->labelfont());
    }

/*
    CAMLprim value s_widget_labeltype(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((fltk::Widget*) widget)->labeltype((LabelType*) typ);
        CAMLreturn(Val_unit);
    }

    CAMLprim value s_widget_box(value widget, value boxtyp)
    {
        CAMLparam2(widget, boxtyp);
        ((fltk::Widget*) widget)->box((Box*)boxtyp);
        CAMLreturn(Val_unit);
    }
*/
    CAMLprim value get_width(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((fltk::Widget*) rect)-> w()));
    }

    CAMLprim value get_height(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((fltk::Widget*) rect)-> h()));
    }

    CAMLprim value get_x(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((fltk::Widget*) rect)-> x()));
    }

    CAMLprim value get_y(value rect)
    {
       CAMLparam1(rect);
       CAMLreturn(Val_int(((fltk::Widget*) rect)-> y()));
    }

    CAMLprim value s_widget_resize(value widget, value xy, value w, value h)
    {
       CAMLparam4(widget, xy, w, h);
       bool r;
       if (Is_long(xy)) 
       {
           std::cout << "no xy " << std::endl;
            r = ((fltk::Widget*) widget)->resize(Int_val(w), Int_val(h));
       }
       else
       {
           value p = Field(xy,0);
           int x = Int_val(Field(p,0));
           int y = Int_val(Field(p,1));
           std::cout << "x: " << x << " y: " << y << std::endl;
           r = ((fltk::Widget*) widget)->resize(x, y, Int_val(w), Int_val(h));
       }
       CAMLreturn(Val_int(r));
    }

    static void widget_cb(fltk::Widget* widget, value* caml_cb)	    
    {
        caml_callback(*caml_cb, Val_unit);
    }

    CAMLprim value s_set_widget_cb(value widget, value fkt)
    {
        CAMLparam2(widget, fkt);
        value* cb = caml_named_value(String_val(fkt));             
        ((fltk::Widget*) widget)
            ->callback((fltk::Callback*)widget_cb, (void*)cb);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Widget*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value widget_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Widget*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_vertical(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> set_vertical();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_horizontal(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> set_horizontal();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_image(value widget, value image)
    {
        CAMLparam2(widget, image);
        ((fltk::Widget*) widget)->image(((fltk::Symbol*)image));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_image(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((fltk::Widget*) widget)->image()));
    }

    CAMLprim value widget_get_box(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)(((fltk::Widget*) widget)->box()));
    }

    CAMLprim value widget_damage(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget)->damage()));
    }

    CAMLprim value widget_relayout(value widget)
    {
        CAMLparam1(widget);
        ((fltk::Widget*) widget) -> relayout();
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_label(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(copy_string(((fltk::Widget*) widget) -> label()));
    }

    CAMLprim value widget_get_labelsize(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(caml_copy_double(((fltk::Widget*) widget) -> labelsize()));
    }

    CAMLprim value widget_set_labelsize(value widget, value size)
    {
        CAMLparam2(widget, size);
        ((fltk::Widget*) widget) -> labelsize(Double_val(size));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_type(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget) -> type()));
    }

    CAMLprim value widget_set_type(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((fltk::Widget*) widget) -> type(Int_val(typ));
        CAMLreturn(Val_unit);
    }
    CAMLprim value widget_get_when(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn(Val_int(((fltk::Widget*) widget) ->when()));
    }

    CAMLprim value widget_set_when(value widget, value when)
    {
        CAMLparam2(widget, when);
        ((fltk::Widget*) widget) -> when(Int_val(when));
        CAMLreturn(Val_unit);
    }
    CAMLprim value widget_set_labelfont(value widget, value font)
    {
        CAMLparam2(widget, font);
        ((fltk::Widget*) widget)->labelfont((fltk::Font*) font);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_labelfont(value widget)
    {
        CAMLparam1(widget);
        CAMLreturn((value)((fltk::Widget*) widget)->labelfont());
    }

/*
    CAMLprim value widget_labeltype(value widget, value typ)
    {
        CAMLparam2(widget, typ);
        ((fltk::Widget*) widget)->labeltype((LabelType*) typ);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_box(value widget, value boxtyp)
    {
        CAMLparam2(widget, boxtyp);
        ((fltk::Widget*) widget)->box((Box*)boxtyp);
        CAMLreturn(Val_unit);
    }
*/
/*
    CAMLprim value set_widget_callback(value widget, value fkt)
    {
        CAMLparam2(widget, fkt);
        ((fltk::Widget*)widget)->set_caml_cb(fkt);
        CAMLreturn(Val_unit);
    }
*/
    
    CAMLprim value set_widget_cb(value widget, value fkt)
    {
        CAMLparam2(widget, fkt);
        value* cb = caml_named_value(String_val(fkt));             
        ((fltk::Widget*) widget)
            ->callback((fltk::Callback*)widget_cb, (void*)cb);
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_color(value widget, value color)
    {
        CAMLparam2(widget, color);
        ((fltk::Widget*) widget)->color(Int32_val(color));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_labelcolor(value widget, value color)
    {
        CAMLparam2(widget, color);
        ((fltk::Widget*) widget)->labelcolor(Int32_val(color));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_set_label(value widget, value label)
    {
        CAMLparam2(widget, label);
        ((fltk::Widget*) widget)->copy_label(String_val(label));
        CAMLreturn(Val_unit);
    }

    CAMLprim value widget_get_flags(value widget)
    {
       CAMLparam1(widget);
       CAMLreturn(Val_int(((fltk::Widget*) widget)-> flags()));
    }

    CAMLprim value widget_set_flags(value widget, value flags)
    {
       CAMLparam2(widget, flags);
       ((fltk::Widget*) widget)->flags(Int_val(flags));
       CAMLreturn(Val_unit);
    }

    CAMLprim value widget_resize(value widget, value xy, value w, value h)
    {
       CAMLparam4(widget, xy, w, h);
       bool r;
       if (Is_long(xy)) 
       {
           std::cout << "no xy " << std::endl;
            r = ((fltk::Widget*) widget)->resize(Int_val(w), Int_val(h));
       }
       else
       {
           value p = Field(xy,0);
           int x = Int_val(Field(p,0));
           int y = Int_val(Field(p,1));
           std::cout << "x: " << x << " y: " << y << std::endl;
           r = ((fltk::Widget*) widget)->resize(x, y, Int_val(w), Int_val(h));
       }
       CAMLreturn(Val_int(r));
    }


    CAMLprim value new_invisible(value box, value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam2(name, box);
	fltk::Box* b = Is_long(box) ? 0 : (fltk::Box*) Field(box,0);
	o_InvisibleBox* widget  = 0;
	if (b) 
		std::cout << "box set" << std::endl;
	else
		std::cout << "box empty" << std::endl;

	widget =
		b ? new o_InvisibleBox(caml_named_value(String_val(name)), b, 
				Int_val(x), Int_val(y), Int_val(w) , Int_val(h), String_val(label))
		: new o_InvisibleBox(caml_named_value(String_val(name)),
				Int_val(x), Int_val(y), Int_val(w) , Int_val(h), String_val(label));

        CAMLreturn((value) widget);
    }

    CAMLprim value new_invisible_bc(value* args, int argc)
    {
        return new_invisible(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
    }

    CAMLprim value invisible_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_InvisibleBox*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value invisible_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_InvisibleBox*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }


}

