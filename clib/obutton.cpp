#include "obutton.h"

namespace Ofltk {

char Button_id[] = "button-director";
char CheckButton_id[] = "checkbutton-director";
char LightButton_id[] = "lightbutton-director";
char RadioButton_id[] = "radio-director";
char HighlightButton_id[] = "highlight-director";
char RepeatButton_id[] = "repeat-director";
char ReturnButton_id[] = "return-director";
char ToggleButton_id[] = "toggle-director";
}

using namespace Ofltk;
extern "C" {

    MAKE_NEW(button)

    CAMLprim value button_value(value button)
    {
        CAMLparam1(button);
        ocaml_button* b = (ocaml_button*) button;
        CAMLreturn(Val_int(b->get_value()));
    }

    CAMLprim value button_set_value(value button, value data)
    {
        CAMLparam2(button, data);
        ocaml_button* b = (ocaml_button*) button;
        CAMLreturn(Val_int(b->set_value(Int_val(data))));
    }

    MAKE_NEW(checkbutton)
    MAKE_NEW(lightbutton)
    MAKE_NEW(radiobutton)
    MAKE_NEW(highlightbutton)
    MAKE_NEW(repeatbutton)
    MAKE_NEW(returnbutton)
    MAKE_NEW(togglebutton)


}
