#include "ostyle.h"
#include "osymbols.h"

namespace Ofltk {

extern "C" {

CAMLprim value style_default_style(value n)
{
    CAMLparam1(n);
    CAMLreturn((value)(new fltk::Style()));
}

CAMLprim value style_set_box(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->box((fltk::Box*)v);
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_buttonbox(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->buttonbox((fltk::Box*)v);
    CAMLreturn(Val_unit);
}

/*
CAMLprim value style_set_focusbox(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->focusbox((fltk::Box*)v);
    CAMLreturn(Val_unit);
}
*/

CAMLprim value style_set_glyph(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->glyph((fltk::Box*)v);
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_labelfont(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->labelfont((fltk::Font*)v);
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_textfont(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->labelfont((fltk::Font*)v);
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_color(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->color(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_textcolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->textcolor(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_selcolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->selection_color(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_seltextcolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->selection_textcolor(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_buttoncolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->buttoncolor(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_labelcolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->labelcolor(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_highlight_color(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->highlight_color(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_highlight_textcolor(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->highlight_textcolor(Int32_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_get_color(value style)
{
    CAMLparam1(style);
    CAMLreturn(caml_copy_int32(((fltk::Style*)style)->color()));
}

CAMLprim value style_get_textcolor(value style)
{
    CAMLparam1(style);
    CAMLreturn(caml_copy_int32(((fltk::Style*)style)->textcolor()));
}

CAMLprim value style_get_selection_color(value style)
{
    CAMLparam1(style);
    CAMLreturn(caml_copy_int32(((fltk::Style*)style)->selection_color()));
}

CAMLprim value style_set_labelsize(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->labelsize(float(Double_val(v)));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_textsize(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->textsize(float(Double_val(v)));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_leading(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->leading(float(Double_val(v)));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_scrollbar_align(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->scrollbar_align(Int_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_scrollbar_width(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->scrollbar_width(Int_val(v));
    CAMLreturn(Val_unit);
}

CAMLprim value style_find(value v)
{
    CAMLparam1(v);
    CAMLlocal1(r);
    fltk::Style* s = fltk::Style::find(String_val(v));
    if (s) {
        r = caml_alloc_small(1,0);
        Field(r,0) = (value) s;
    } else {
        r = Val_int(0);
    }
    CAMLreturn(r);
}


CAMLprim value reset_theme(value nix)
{
    CAMLparam1(nix);
    fltk::reset_theme();
    CAMLreturn(Val_unit);
}

	

}

}
