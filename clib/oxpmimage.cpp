#include "oxpmimage.h"

using namespace Ofltk;

typedef char* row_ptr;

extern "C" {

    CAMLprim value new_xpmimage(value vm, value data, value name)
    {
        CAMLparam3(vm, data, name);
        int rows = Wosize_val(data);
        char** d = new row_ptr[rows];
        for (int i=0; i < rows; i++)
        {
            d[i] = String_val(Field(data,i));
        }
        char* n = Is_block(name) ? String_val(Field(name,0)) : 0;
        o_XpmImage* s = new o_XpmImage(vm, d, n);
        CAMLreturn((value) s);
    }


}
