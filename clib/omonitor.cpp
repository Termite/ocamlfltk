#include "ocamlfltk.h"
#include "omonitor.h"

using namespace Ofltk;

extern "C" {

#include <caml/custom.h>
#define monval(v)   (*((ocaml_monitor**)Data_custom_val(v)))

    void destroy_monitor(value m)
    {
        std::cout << "destroying monitor..." << std::endl;
        delete(monval(m));
    }
   
    static struct custom_operations monitor_ops = {
        "monitor_ops",
        destroy_monitor,
        custom_compare_default,
        custom_hash_default,
        custom_serialize_default,
        custom_deserialize_default
    };

    static value alloc_monitor(ocaml_monitor* m)
    {
        value v = caml_alloc_custom(&monitor_ops, sizeof(ocaml_monitor*), 0, 1);
        monval(v) = m;
        return v;
    }


    CAMLprim value monitor_depth(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( Val_int(monval(mon)->depth()) );
    }

    CAMLprim value monitor_dpi_x(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(monval(mon)->dpi_x()));
    }

    CAMLprim value monitor_dpi_y(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(monval(mon)->dpi_y()) );
    }

    CAMLprim value monitor_dpi(value mon)
    {
        CAMLparam1(mon);
        CAMLreturn( caml_copy_double(monval(mon)->dpi()) );
    }

    CAMLprim value monitor_find(value x, value y)
    {
        CAMLparam2(x, y);
        const fltk::Monitor& m = fltk::Monitor::find(Int_val(x), Int_val(y));
        CAMLreturn(alloc_monitor(new ocaml_monitor(m)));
    }

    CAMLprim value monitor_all(value nix)
    {
        CAMLparam1(nix);
        const fltk::Monitor m = fltk::Monitor::all();
        CAMLreturn((value)(alloc_monitor(new ocaml_monitor(m))));
    }

    CAMLprim value monitor_rect(value mon)
    {
        CAMLparam1(mon);
        CAMLlocal1(r);
        r = caml_alloc_small(4,0);
        Field(r,0) = monval(mon)->work()->x();
        Field(r,1) = monval(mon)->work()->y();
        Field(r,2) = monval(mon)->work()->w();
        Field(r,3) = monval(mon)->work()->h();
        CAMLreturn(r);
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
           Store_field(erg, i, alloc_monitor(new ocaml_monitor(list[i]))); 
        }
        CAMLreturn(erg);
    }
}
