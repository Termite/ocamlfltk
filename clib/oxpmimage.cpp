#include "oxpmimage.h"

using namespace Ofltk;

typedef char* row_ptr;

extern "C" {

    CAMLprim value new_xpmimage(value _draw, value data, value name)
    {
        CAMLparam3(_draw, data, name);
        int rows = Wosize_val(data);
        char** d = new row_ptr[rows];
        for (int i=0; i < rows; i++)
        {
            d[i] = String_val(Field(data,i));
        }
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        char* n = Is_block(name) ? String_val(Field(name,0)) : 0;
        ocaml_xpmimage* s = new ocaml_xpmimage(draw, d, n);
        CAMLreturn((value) s);
    }


}
