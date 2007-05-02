#include "oscrollgroup.h"

namespace Ofltk {
    char ScrollGroup_id[] = "Scrollgroup-director";
}

using namespace Ofltk;

extern "C" {
    
    GEN_NEW(ScrollGroup);

    CAMLprim value scrollgroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_ScrollGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value scrollgroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_ScrollGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value scrollgroup_set_position(value sc, value x, value y)
    {
        CAMLparam3(sc, x, y);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        b->position(Int_val(x), Int_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value scrollgroup_xpos(value sc)
    {
        CAMLparam1(sc);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        CAMLreturn(Val_int(b->xposition()));
    }

    CAMLprim value scrollgroup_ypos(value sc)
    {
        CAMLparam1(sc);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        CAMLreturn(Val_int(b->yposition()));
    }

    CAMLprim value scrollgroup_scroll_to(value sc, value x, value y)
    {
        CAMLparam3(sc, x, y);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        b->scrollTo(Int_val(x), Int_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value scrollgroup_type(value sc, value typ)
    {
        CAMLparam2(sc, typ);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        b->type( Int_val(typ));
        CAMLreturn(Val_unit);
    }

    CAMLprim value scrollgroup_align(value sc, value typ)
    {
        CAMLparam2(sc, typ);
        fltk::ScrollGroup* b = (fltk::ScrollGroup*) sc;
        b->align(Int_val(typ));
        CAMLreturn(Val_unit);
    }

    
}

