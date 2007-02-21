#include "owizardgroup.h"


namespace Ofltk {

char WizardGroup_id[] = "wizardgroup-director";

}

using namespace Ofltk;

extern "C" {

    CAMLprim value new_wizardgroup(value name, value x, value y, value w, value h, value label)
    {
        CAMLparam5(x,y,w,h,label);
        CAMLxparam1(name);
        ocaml_wizardgroup* widget = new ocaml_wizardgroup(caml_named_value(String_val(name)), Int_val(x), Int_val(y), Int_val(w)
                , Int_val(h), String_val(label));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_wizardgroup_bc(value* args, int argc)
    {
        return new_wizardgroup(args[0],args[1],args[2],args[3],args[4],args[5]);
    }

    CAMLprim value wizard_next(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_wizardgroup*)widget)->next();
        CAMLreturn(Val_unit);
    }

    CAMLprim value wizard_prev(value widget)
    {
        CAMLparam1(widget);
        ((ocaml_wizardgroup*)widget)->prev();
        CAMLreturn(Val_unit);
    }

}
