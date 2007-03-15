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
        CAMLparam5(a,b,c,d,x);
        CAMLxparam1(y);
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

    CAMLprim value transform_f(value x, value y)
    {
        CAMLparam2(x, y);
        CAMLlocal1(e);
        float a = Double_val(x);
        float b = Double_val(y);
        fltk::transform(a, b);
        e = caml_alloc_small(2,0);
        Field(e,0) = caml_copy_double(a);
        Field(e,1) = caml_copy_double(b);
        CAMLreturn(e);
    }

    CAMLprim value transform_i(value x, value y)
    {
        CAMLparam2(x, y);
        CAMLlocal1(e);
        int a = Int_val(x);
        int b = Int_val(y);
        fltk::transform(a, b);
        e = caml_alloc_small(2,0);
        Field(e,0) = Val_int(a);
        Field(e,1) = Val_int(b);
        CAMLreturn(e);
    }

    CAMLprim value transform_distance(value x, value y)
    {
        CAMLparam2(x, y);
        CAMLlocal1(e);
        float a = Double_val(x);
        float b = Double_val(y);
        fltk::transform_distance(a, b);
        e = caml_alloc_small(2,0);
        Field(e,0) = caml_copy_double(a);
        Field(e,1) = caml_copy_double(b);
        CAMLreturn(e);
    }

    CAMLprim value transform_rect(value x, value y, value w, value h)
    {
        CAMLparam4(x, y, w, h);
        CAMLlocal1(e);
        fltk::Rectangle r;
        fltk::transform(Int_val(x), Int_val(y), Int_val(w), Int_val(h), r);
        e = caml_alloc_small(4,0);
        Field(e,0) = Val_int(r.x()); 
        Field(e,1) = Val_int(r.y());
        Field(e,2) = Val_int(r.w());
        Field(e,3) = Val_int(r.h());
        CAMLreturn(e);
    }





}
