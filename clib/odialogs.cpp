#include "ocamlfltk.h"
#include <fltk/ask.h>

using namespace Ofltk;

extern "C" {

    CAMLprim value dialog_message(value message)
    {
        CAMLparam1(message);
        char* m = String_val(message);
        fltk::message("%s", m);
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value dialog_alert(value message)
    {
        CAMLparam1(message);
        char* m = String_val(message);
        fltk::alert("%s", m);
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value dialog_ask(value message)
    {
        CAMLparam1(message);
        char* m = String_val(message);
        CAMLreturn(Val_int(fltk::ask("%s", m)));
    }
       
    CAMLprim value dialog_choice(value b0, value b1, value b2, value txt)
    {
        CAMLparam4(b0, b1, b2, txt);
        char* m = String_val(txt);
        int r = fltk::choice("%s", String_val(b0), String_val(b1), String_val(b2), m);
        CAMLreturn(Val_int(r));
    }
       
    CAMLprim value dialog_choice_alert(value b0, value b1, value b2, value txt)
    {
        CAMLparam4(b0, b1, b2, txt);
        char* m = String_val(txt);
        int r = fltk::choice_alert("%s", String_val(b0), String_val(b1), String_val(b2), m);
        CAMLreturn(Val_int(r));
    }
       
    CAMLprim value dialog_input(value default_str, value message)
    {
        CAMLparam2(default_str, message);
        CAMLlocal1(erg);
        char* m = String_val(message);
        const char* answer = fltk::input("%s", String_val(default_str), m);
        if (answer == 0) 
        {
           erg = Val_int(0);
        }
        else
        {
           erg = caml_alloc_small(1,0);
           Field(erg, 0) = caml_copy_string(answer);
        }
        CAMLreturn(erg);
    }

    CAMLprim value dialog_password(value default_str, value message)
    {
        CAMLparam2(default_str, message);
        CAMLlocal1(erg);
        char* m = String_val(message);
        const char* answer = fltk::password("%s", String_val(default_str), m);
        if (answer == 0) 
        {
           erg = Val_int(0);
        }
        else
        {
           erg = caml_alloc_small(1,0);
           Field(erg, 0) = caml_copy_string(answer);
        }
        CAMLreturn(erg);
    }

    CAMLprim value set_no(value v)
    {
        CAMLparam1(v);
        fltk::no = strdup(String_val(v));
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value set_yes(value v)
    {
        CAMLparam1(v);
        fltk::yes = strdup(String_val(v));
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value set_ok(value v)
    {
        CAMLparam1(v);
        fltk::ok = strdup(String_val(v));
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value set_cancel(value v)
    {
        CAMLparam1(v);
        fltk::cancel = strdup(String_val(v));
        CAMLreturn(Val_unit);
    }
       
    CAMLprim value dialog_no(value v)
    {
        CAMLparam1(v);
        CAMLreturn(copy_string(fltk::no));
    }
       
    CAMLprim value dialog_yes(value v)
    {
        CAMLparam1(v);
        CAMLreturn(copy_string(fltk::yes));
    }
       
    CAMLprim value dialog_ok(value v)
    {
        CAMLparam1(v);
        CAMLreturn(copy_string(fltk::ok));
    }
       
    CAMLprim value dialog_cancel(value v)
    {
        CAMLparam1(v);
        CAMLreturn(copy_string(fltk::cancel));
    }
       
}
