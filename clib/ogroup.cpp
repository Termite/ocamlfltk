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
        ocaml_group* widget = new ocaml_group(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
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
        ((ocaml_group*)group) -> begin();
        CAMLreturn(Val_unit);
    }

    CAMLprim value group_end(value group)
    {
        CAMLparam1(group);
        ((ocaml_group*)group) -> end();
        CAMLreturn(Val_unit);
    }

    CAMLprim value group_set_resizable(value group, value widget)
    {
       CAMLparam2(group, widget);
      ((ocaml_group*)group)->resizable((ocaml_widget*)widget);
       CAMLreturn(Val_unit);
    }

    CAMLprim value group_children(value group)
    {
      CAMLparam1(group);
      CAMLreturn(Val_int(((ocaml_group*)group)->children()));
    }

    CAMLprim value group_get_child(value group, value n)
    {
      CAMLparam2(group, n);
      ocaml_widget* w = ((ocaml_group*)group)->child(Int_val(n));
      CAMLreturn((value)w);
    }

    CAMLprim value group_insert(value group, value widget, value idx)
    {
      CAMLparam3(group, widget, idx);
      ((ocaml_group*) group)->insert((ocaml_widget*)widget, Int_val(idx));
      CAMLreturn(Val_unit);
    }

    CAMLprim value group_insert_before(value group, value widget, value before)
    {
      CAMLparam3(group, widget, before);
      ((ocaml_group*) group)->insert((ocaml_widget*)widget, (ocaml_widget*)before);
      CAMLreturn(Val_unit);
    }

}
