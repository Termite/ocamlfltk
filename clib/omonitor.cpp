#include "ocamlfltk.h"
#include "omonitor.h"

using namespace Ofltk;

extern "C" {

    CAMLprim value monitor_depth(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( Val_int(((ocaml_monitor*)mon)->depth()) );
    }

    CAMLprim value monitor_dpi_x(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(((ocaml_monitor*)mon)->dpi_x()) );
    }

    CAMLprim value monitor_dpi_y(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(((ocaml_monitor*)mon)->dpi_y()) );
    }

    CAMLprim value monitor_dpi(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(((ocaml_monitor*)mon)->dpi()) );
    }

    CAMLprim value monitor_find(value x, value y)
    {
        CAMLparam2(x, y);
        const fltk::Monitor& m = fltk::Monitor::find(Int_val(x), Int_val(y));
        CAMLreturn((value)(new ocaml_monitor(m)));
    }

    CAMLprim value monitor_all(value nix)
    {
        CAMLparam1(nix);
        const fltk::Monitor m = fltk::Monitor::all();
        CAMLreturn((value)(new ocaml_monitor(m)));
    }

    CAMLprim value monitor_list(value nix)
    {
        CAMLparam1(nix);
        CAMLlocal1(erg);
        const fltk::Monitor* list = 0; 
        int cnt = fltk::Monitor::list(&list);
        erg = caml_alloc_tuple(cnt);
        for (int i=0; i < cnt; ++i)
        {
           Store_field(erg, i, (value)(new ocaml_monitor(list[i]))); 
        }
        CAMLreturn(erg);
    }
}
