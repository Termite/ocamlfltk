#include "ostatusbar.h"
#include "osymbols.h"

namespace Ofltk {

char StatusBarGroup_id[] = "StatusBarGroup";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_statusbar(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_statusbar* widget = new ocaml_statusbar(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_statusbar_bc(value* args, int argc)        
    {
        return new_statusbar(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value new_easy_statusbar(value name, value height) 
    {
        CAMLparam2(name, height);
        ocaml_statusbar* widget = new ocaml_statusbar(caml_named_value(String_val(name)), Int_val(height));
        CAMLreturn((value) widget);
    }

    CAMLprim value statusbar_set_text(value widget, value pos, value text)
    {
       CAMLparam3(widget, pos, text); 
       ((ocaml_statusbar*) widget)->set(String_val(text), fltk::StatusBarGroup::Position(Int_val(pos)));
       CAMLreturn(Val_unit);
    }

    CAMLprim value statusbar_child_box(value widget, value box, value pos)
    {
       CAMLparam3(widget, box, pos);
       ((ocaml_statusbar*) widget)->child_box(((ocaml_symbol*) box)->dest_widget(), fltk::StatusBarGroup::Position(Int_val(pos)));
       CAMLreturn(Val_unit);
    }



}
