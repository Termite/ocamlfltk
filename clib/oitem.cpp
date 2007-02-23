#include "oitem.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value new_item(value name, value item)
    {
        CAMLparam2(name, item);
        ocaml_item* widget =
            new ocaml_item(caml_named_value(String_val(name)), String_val(item));
        CAMLreturn((value) widget);
    }

    CAMLprim value new_itemgroup(value name, value item)
    {
        CAMLparam2(name, item);
        ocaml_itemgroup* widget =
            new ocaml_itemgroup(caml_named_value(String_val(name)), String_val(item));
        CAMLreturn((value) widget);
    }



}
