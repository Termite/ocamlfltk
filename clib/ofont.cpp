#include "ocamlfltk.h"
#include <fltk/Font.h>

using namespace Ofltk;

extern "C" {

    CAMLprim value font_list(value nix)
    {
        CAMLparam1(nix);
        CAMLlocal1(fonts);

        fltk::Font** f = 0;

        int n = fltk::list_fonts(f);
        fonts = caml_alloc_tuple(n);
        for (int i=0; i < n; i++)
        {
            Store_field(fonts, i, (value)(f[i]));
        }
        CAMLreturn(fonts);
    }

    CAMLprim value font(value name, value attr)
    {
        CAMLparam2(name, attr);
        fltk::Font* f = fltk::font(String_val(name), Int_val(attr));
        CAMLreturn((value) f);
    }

    CAMLprim value font_name(value font)
    {
        CAMLparam1(font);
        CAMLreturn(caml_copy_string( ((fltk::Font*)font)->name()));
    }

    CAMLprim value font_current_name(value font)
    {
        CAMLparam1(font);
        CAMLreturn(caml_copy_string( ((fltk::Font*)font)->current_name()));
    }

    CAMLprim value font_system_name(value font)
    {
        CAMLparam1(font);
        CAMLreturn(caml_copy_string( ((fltk::Font*)font)->system_name()));
    }

    CAMLprim value font_plus(value font, value attr)
    {
        CAMLparam2(font, attr);
        fltk::Font* f = ((fltk::Font*)font)->plus(Int_val(attr));
        CAMLreturn((value) f);
    }

    CAMLprim value font_bold(value font)
    {
        CAMLparam1(font );
        fltk::Font* f = ((fltk::Font*)font)->bold();
        CAMLreturn((value) f);
    }

    CAMLprim value font_italic(value font)
    {
        CAMLparam1(font );
        fltk::Font* f = ((fltk::Font*)font)->italic();
        CAMLreturn((value) f);
    }

    CAMLprim value font_encodings(value font)
    {
        CAMLparam1(font);
        CAMLlocal1(erg);
        const char** e = 0;
        int n = ((fltk::Font*)font)->encodings(e);
        erg = caml_alloc_tuple(n);
        for (int i=0; i < n; i++)
        {
            Store_field(erg, i, caml_copy_string(e[i]));
        }
        
        CAMLreturn(erg);
    }

    CAMLprim value font_sizes(value font)
    {
        CAMLparam1(font);
        CAMLlocal1(erg);
        int* sz = 0;
        int n = ((fltk::Font*)font)->sizes(sz);
        erg = caml_alloc_tuple(n);
        for (int i=0; i < n; i++)
        {
            Store_field(erg, i, Val_int((sz[i])));
        }
        CAMLreturn(erg);
    }


}
