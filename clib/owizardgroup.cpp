#include "owizardgroup.h"


namespace Ofltk {

char WizardGroup_id[] = "wizardgroup-director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_WizardGroup(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        o_WizardGroup* widget = new o_WizardGroup(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_WizardGroup_bc(value* args, int argc)
    {
        return new_WizardGroup(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value wizard_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_WizardGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value wizard_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_WizardGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value wizard_next(value widget)
    {
        CAMLparam1(widget);
        ((fltk::WizardGroup*)widget)->next();
        CAMLreturn(Val_unit);
    }

    CAMLprim value wizard_prev(value widget)
    {
        CAMLparam1(widget);
        ((fltk::WizardGroup*)widget)->prev();
        CAMLreturn(Val_unit);
    }

}
