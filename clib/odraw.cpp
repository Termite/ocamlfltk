#include "odraw.h"


namespace Ofltk {

extern "C" {    

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

    /* Clipping */

    CAMLprim value push_clip(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        fltk::push_clip(Int_val(x), Int_val(y), Int_val(w), Int_val(h));
        CAMLreturn(Val_unit);
    }

    CAMLprim value clip_out(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        fltk::clipout(fltk::Rectangle(Int_val(x), Int_val(y), Int_val(w), Int_val(h)));
        CAMLreturn(Val_unit);
    }

    CAMLprim value pop_clip(value h)
    {
        CAMLparam1(h);
        fltk::pop_clip();
        CAMLreturn(Val_unit);
    }

    CAMLprim value push_no_clip(value h)
    {
        CAMLparam1(h);
        fltk::push_no_clip();
        CAMLreturn(Val_unit);
    }

    CAMLprim value not_clipped(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        CAMLreturn(Val_int(fltk::not_clipped(fltk::Rectangle(Int_val(x), Int_val(y), Int_val(w), Int_val(h)))));
    }

    CAMLprim value intersect_with_clip(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        CAMLlocal2(cr,e);
        fltk::Rectangle r(Int_val(x), Int_val(y), Int_val(w), Int_val(h));        
        int c = fltk::intersect_with_clip(r);
        // c should be of type clipped in draw.ml
        // XXX exception?
        c = c > 2 ? 2 : (c < 0 ? 0 : c);
        cr = caml_alloc_small(4, 0);
        Field(cr,0) = Val_int(r.x());
        Field(cr,1) = Val_int(r.y());
        Field(cr,2) = Val_int(r.w());
        Field(cr,3) = Val_int(r.h());
        e = caml_alloc_small(1, c);
        Field(e, 0) = cr;
        CAMLreturn(e);
    }

    /* Path construction */

    CAMLprim value newpath(value n)
    {
        CAMLparam1(n);
        fltk::newpath();
        CAMLreturn(Val_unit);
    }

    CAMLprim value add_vertex_f(value x, value y)
    {
        CAMLparam2(x,y);
        fltk::addvertex(float(Double_val(x)), float(Double_val(y)));
        CAMLreturn(Val_unit);
    }

    CAMLprim value add_vertex_i(value x, value y)
    {
        CAMLparam2(x,y);
        fltk::addvertex(Int_val(x), Int_val(y));
        CAMLreturn(Val_unit);
    }

    typedef float pair[2];

    CAMLprim value add_vertices_f(value v)
    {
        CAMLparam1(v);
        int n = Wosize_val(v);
        pair *data = new pair[n];
        for (int k=0; k < n; k++)
        {
            value pair = Field(v,k);
            data[k][0] = float(Double_val(Field(pair,0)));
            data[k][1] = float(Double_val(Field(pair,1)));
        }
        fltk::addvertices(n, data);
        delete[] data;
        CAMLreturn(Val_unit);
    }

    typedef int pair_i[2];
    CAMLprim value add_vertices_i(value v)
    {
        CAMLparam1(v);
        int n = Wosize_val(v);
        pair_i *data = new pair_i[n];
        for (int k=0; k < n; k++)
        {
            value pair = Field(v,k);
            data[k][0] = Int_val(Field(pair,0));
            data[k][1] = Int_val(Field(pair,1));
        }
        fltk::addvertices(n, data);
        delete[] data;
        CAMLreturn(Val_unit);
    }

    CAMLprim value add_vertices_transformed(value v)
    {
        CAMLparam1(v);
        int n = Wosize_val(v);
        pair *data = new pair[n];
        for (int k=0; k < n; k++)
        {
            value pair = Field(v,k);
            data[k][0] = Float_val(Field(pair,0));
            data[k][1] = Float_val(Field(pair,1));
        }
        fltk::addvertices_transformed(n, data);
        delete[] data;
        CAMLreturn(Val_unit);
    }

    CAMLprim value addcurve(value x0, value y0, value x1, value y1, value x2, value y2,
                            value x3, value y3)
    {
        CAMLparam5(x0,y0,x1,y1,x2);
        CAMLxparam3(y2,x3,y3);
        fltk::addcurve(Double_val(x0),Double_val(y0),Double_val(x1),Double_val(y1),
                       Double_val(x2),Double_val(y2),Double_val(x3),Double_val(y3));
        CAMLreturn(Val_unit);
    }

    CAMLprim value addcurve_bc(value* argv, int n)
    {
        return addcurve(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    }

    CAMLprim value addarc(value x0, value y0, value x1, value y1, value x2, value y2)
    {
        CAMLparam5(x0,y0,x1,y1,x2);
        CAMLxparam1(y2);
        fltk::addarc(Double_val(x0),Double_val(y0),Double_val(x1),Double_val(y1),
                       Double_val(x2),Double_val(y2));
        CAMLreturn(Val_unit);
    }

    CAMLprim value addarc_bc(value* argv, int n)
    {
        return addarc(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    }

    CAMLprim value addpie(value x, value y, value w, value h, value a1, value a2)
    {
        CAMLparam5(x,y,w,h,a1);
        CAMLxparam1(a2);
        fltk::addpie(fltk::Rectangle(Int_val(x),Int_val(y),Int_val(w),Int_val(h)),
                       Double_val(a1),Double_val(a2));
        CAMLreturn(Val_unit);
    }

    CAMLprim value addpie_bc(value* argv, int n)
    {
        return addpie(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    }

    CAMLprim value addchord(value x, value y, value w, value h, value a1, value a2)
    {
        CAMLparam5(x,y,w,h,a1);
        CAMLxparam1(a2);
        fltk::addchord(fltk::Rectangle(Int_val(x),Int_val(y),Int_val(w),Int_val(h)),
                       Double_val(a1),Double_val(a2));
        CAMLreturn(Val_unit);
    }

    CAMLprim value addchord_bc(value* argv, int n)
    {
        return addchord(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    }

    CAMLprim value closepath(value n)
    {
        CAMLparam1(n);
        fltk::closepath();
        CAMLreturn(Val_unit);
    }

    /* Shapes and Lines */ 
}
}

