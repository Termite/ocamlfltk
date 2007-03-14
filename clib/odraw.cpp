#include "odraw.h"


namespace Ofltk {

    CAMLprim value push_matrix(value unit)
    {
        CAMLparam1(unit);
        fltk::push_matrix();
        CAMLreturn(Val_unit);
    }

    CAMLprim value pop_matrix(value unit)
    {
        CAMLparam1(unit);
        fltk::pop_matrix();
        CAMLreturn(Val_unit);
    }

    CAMLprim value scale_xy(value x, value y)
    {
        CAMLparam2(x, y);
        fltk::scale(Double_val(x), Double_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value scale_x(value x)
    {
        CAMLparam1(x);
        fltk::scale(Double_val(x));
        CAMLreturn(Val_unit);
    }

    CAMLprim value translate_f(value x, value y)
    {
        CAMLparam2(x, y);
        fltk::translate(float(Double_val(x)), float(Double_val(y)));
        CAMLreturn(Val_unit);
    }

    CAMLprim value translate_i(value x, value y)
    {
        CAMLparam2(x, y);
        fltk::translate(Int_val(x), Int_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value rotate(value x)
    {
        CAMLparam1(x);
        fltk::rotate(Double_val(x));
        CAMLreturn(Val_unit);
    }

    CAMLprim value concat(value a, value b, value c, value d, value x, value y)
    {
        CAMLparam4(a,b,c,d);
        CAMLxparam2(x,y);
        fltk::concat(Double_val(a),Double_val(b),Double_val(c),Double_val(d),Double_val(x),Double_val(y)); 
        CAMLreturn(Val_unit);
    }

    CAMLprim value concat_bc(value* argv, int argn)
    {
        return concat(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    }

    CAMLprim value load_identity(value unit)
    {
        CAMLparam1(unit);
        fltk::load_identity();
        CAMLreturn(Val_unit);
    }





}
