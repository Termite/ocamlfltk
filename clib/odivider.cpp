#include "odivider.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_divider(value name)
    {
        CAMLparam1(name);
        ocaml_divider* widget =
            new ocaml_divider(caml_named_value(String_val(name)));
        CAMLreturn((value) widget);
    }


}

