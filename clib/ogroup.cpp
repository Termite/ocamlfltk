#include "ogroup.h"

namespace Ofltk {

char Group_id[] = "group_director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_group(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_Group* widget = new o_Group(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_group_bc(value* args, int argc)
    {
        return new_group(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value group_begin(value group)
    {
        CAMLparam1(group);
        ((fltk::Group*)group) -> begin();
        CAMLreturn(Val_unit);
    }

    CAMLprim value group_end(value group)
    {
        CAMLparam1(group);
        ((fltk::Group*)group) -> end();
        CAMLreturn(Val_unit);
    }

    CAMLprim value group_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_Group*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value group_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_Group*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value group_set_resizable(value group, value widget)
    {
       CAMLparam2(group, widget);
      ((fltk::Group*)group)->resizable((fltk::Widget*)widget);
       CAMLreturn(Val_unit);
    }

    CAMLprim value group_children(value group)
    {
      CAMLparam1(group);
      CAMLreturn(Val_int(((fltk::Group*)group)->children()));
    }

    CAMLprim value group_get_child(value group, value n)
    {
      CAMLparam2(group, n);
      fltk::Widget* w = ((fltk::Group*)group)->child(Int_val(n));
      CAMLreturn((value)w);
    }

    CAMLprim value group_insert(value group, value widget, value idx)
    {
      CAMLparam3(group, widget, idx);
      ((fltk::Group*) group)->insert(*((fltk::Widget*)widget), Int_val(idx));
      CAMLreturn(Val_unit);
    }

    CAMLprim value group_insert_before(value group, value widget, value before)
    {
      CAMLparam3(group, widget, before);
//      fltk::Widget* w = Is_long(before) ? 0 : (fltk::Widget*) Field(before,0);
      ((fltk::Group*) group)->insert(*((fltk::Widget*)widget), (fltk::Widget*)before);
      CAMLreturn(Val_unit);
    }
}
