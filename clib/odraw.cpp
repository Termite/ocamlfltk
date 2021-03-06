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
		fltk::Rectangle from(Int_val(x), Int_val(y), Int_val(w), Int_val(h));
        fltk::transform(from, r);
        e = caml_alloc_small(4,0);
        Field(e,0) = Val_int(r.x()); 
        Field(e,1) = Val_int(r.y());
        Field(e,2) = Val_int(r.w());
        Field(e,3) = Val_int(r.h());
        CAMLreturn(e);
    }

    /* Clipping */

    CAMLprim value draw_push_clip(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        fltk::push_clip(Int_val(x), Int_val(y), Int_val(w), Int_val(h));
        CAMLreturn(Val_unit);
    }

    CAMLprim value draw_clipout(value x, value y, value w, value h)
    {
        CAMLparam4(x,y,w,h);
        fltk::clipout(fltk::Rectangle(Int_val(x), Int_val(y), Int_val(w), Int_val(h)));
        CAMLreturn(Val_unit);
    }

    CAMLprim value draw_pop_clip(value h)
    {
        CAMLparam1(h);
        fltk::pop_clip();
        CAMLreturn(Val_unit);
    }

    CAMLprim value draw_push_no_clip(value h)
    {
        CAMLparam1(h);
        fltk::push_no_clip();
        CAMLreturn(Val_unit);
    }

    CAMLprim value draw_not_clipped(value x, value y, value w, value h)
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

    CAMLprim value strokepath(value n)
    {
        CAMLparam1(n);
        fltk::strokepath();
        CAMLreturn(Val_unit);
    }

    CAMLprim value fillpath(value n)
    {
        CAMLparam1(n);
        fltk::fillpath();
        CAMLreturn(Val_unit);
    }

    CAMLprim value fillstrokepath(value color)
    {
        CAMLparam1(color);
        fltk::fillstrokepath(Int32_val(color));
        CAMLreturn(Val_unit);
    }

    CAMLprim value fillrect(value x, value y, value w, value h) 
    {
        CAMLparam4(x, y, w, h);
        fltk::fillrect(Int_val(x), Int_val(y), Int_val(w), Int_val(h));  
        CAMLreturn(Val_unit);
    }

    CAMLprim value strokerect(value x, value y, value w, value h) 
    {
        CAMLparam4(x, y, w, h);
        fltk::strokerect(Int_val(x), Int_val(y), Int_val(w), Int_val(h));  
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawline(value x, value y, value x1, value y1) 
    {
        CAMLparam4(x, y, x1, y1);
        fltk::drawline(Int_val(x), Int_val(y), Int_val(x1), Int_val(y1));  
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawline_f(value x, value y, value x1, value y1) 
    {
        CAMLparam4(x, y, x1, y1);
        fltk::drawline(Float_val(x), Float_val(y), Float_val(x1), Float_val(y1));  
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawpoint_f(value x, value y) 
    {
        CAMLparam2(x, y);
        fltk::drawpoint(Float_val(x), Float_val(y));  
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawpoint(value x, value y) 
    {
        CAMLparam2(x, y);
        fltk::drawpoint(Int_val(x), Int_val(y));  
        CAMLreturn(Val_unit);
    }

    /* Text */

    CAMLprim value draw_setfont(value font, value size) 
    {
        CAMLparam2(font, size);
        fltk::setfont((fltk::Font*) font, Float_val(size));
        CAMLreturn(Val_unit);
    }

/*
    CAMLprim value draw_setfont_name(value font, value size) 
    {
        CAMLparam2(font, size);
        fltk::setfont(String_val(font), Float_val(size));
        CAMLreturn(Val_unit);
    }
*/

    CAMLprim value get_encoding(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_string(fltk::get_encoding()));
    }

    CAMLprim value set_encoding(value n) 
    {
        CAMLparam1(n);
        fltk::set_encoding(String_val(n));
        CAMLreturn(n);
    }

    CAMLprim value get_font(value n) 
    {
        CAMLparam1(n);
        CAMLreturn((value)(fltk::getfont()));
    }

    CAMLprim value get_size(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_double(fltk::getsize()));
    }

    CAMLprim value draw_getwidth(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_double(fltk::getwidth(String_val(n))));
    }

    CAMLprim value drawtext(value text, value x, value y) 
    {
        CAMLparam3(text, x, y);
        fltk::drawtext(String_val(text), Float_val(x), Float_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawsubtext(value text, value len, value x, value y) 
    {
        CAMLparam4(text, len, x, y);
        fltk::drawtext(String_val(text), Int_val(len), Float_val(x), Float_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawtext_rect(value str, value x, value y, value w, value h, value f)
    {
        CAMLparam5(str, x, y, w, h);
        CAMLxparam1(f);
        fltk::drawtext(String_val(str),
                fltk::Rectangle(Int_val(x),Int_val(y),Int_val(w),Int_val(h)),
                       Int_val(f));
        CAMLreturn(Val_unit);
    }

    CAMLprim value drawtext_rect_bc(value* argv, int n)
    {
        return drawtext_rect(argv[0], argv[1], argv[2], argv[3], argv[4], argv[5]);
    }

    /* Functions */

    CAMLprim value setcolor(value n) 
    {
        CAMLparam1(n);
        fltk::setcolor(Int32_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value setcolor_alpha(value c, value alpha) 
    {
        CAMLparam2(c, alpha);
        fltk::setcolor_alpha(Int32_val(c), Float_val(alpha));
        CAMLreturn(Val_unit);
    }

    CAMLprim value getcolor(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_int32(fltk::getcolor()));
    }

    CAMLprim value setbgcolor(value n) 
    {
        CAMLparam1(n);
        fltk::setbgcolor(Int32_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value getbgcolor(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_int32(fltk::getbgcolor()));
    }

    CAMLprim value drawstyle(value style, value flags) 
    {
        CAMLparam2(style, flags);
        fltk::drawstyle( (fltk::Style*)style, Int_val(flags));
        CAMLreturn(Val_unit);
    }

    CAMLprim value get_drawstyle(value n) 
    {
        CAMLparam1(n);
        CAMLreturn((value)(fltk::drawstyle()));
    }

    CAMLprim value set_drawflags(value flags) 
    {
        CAMLparam1(flags);
        fltk::drawflags(Int_val(flags));
        CAMLreturn(Val_unit);
    }

    CAMLprim value get_drawflags(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::drawflags()));
    }

    CAMLprim value set_linestyle(value style, value width, value dashes) 
    {
        CAMLparam3(style, width, dashes);
        float w = Is_long(width) ? 0.0 : Float_val(Field(width,0));
        char* d = Is_long(dashes) ? 0 : String_val(Field(dashes,0));
        fltk::line_style(Int_val(style), w, d);
        CAMLreturn(Val_unit);
    }

    CAMLprim value get_linestyle(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::line_style()));
    }

    CAMLprim value get_linewidth(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_double(fltk::line_width()));
    }

    CAMLprim value get_linedashes(value n) 
    {
        CAMLparam1(n);
        CAMLreturn(caml_copy_string(fltk::line_dashes()));
    }


}
}

