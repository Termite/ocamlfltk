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
    ((fltk::Style*)style)->box(((ocaml_symbol*)v)->dest_symbol());
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_buttonbox(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->buttonbox(((ocaml_symbol*)v)->dest_symbol());
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_focusbox(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->focusbox(((ocaml_symbol*)v)->dest_symbol());
    CAMLreturn(Val_unit);
}

CAMLprim value style_set_glyph(value style, value v)
{
    CAMLparam2(style, v);
    ((fltk::Style*)style)->glyph(((ocaml_symbol*)v)->dest_symbol());
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



}

}