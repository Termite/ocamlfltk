#include "otiledgroup.h"

namespace Ofltk {

    char TiledGroup_id[] = "TiledGroup";

}

using namespace Ofltk;

extern "C" {

    GEN_NEW(TiledGroup);

    CAMLprim value tiledgroup_handle(value widget, value ev)
    {
        CAMLparam2(widget, ev);
        int r = ((o_TiledGroup*) widget) -> default_handle(Int_val(ev));
        CAMLreturn(Val_int(r));
    }

    CAMLprim value tiledgroup_draw(value widget)
    {
        CAMLparam1(widget);
        ((o_TiledGroup*) widget) -> default_draw();
        CAMLreturn(Val_unit);
    }

    CAMLprim value tiledgroup_position(value widget, value oldx, value oldy, value x, value y)
    {
        CAMLparam5(widget, oldx, oldy, x, y);
        ((fltk::TiledGroup*) widget) -> position(Int_val(oldx),Int_val(oldy),Int_val(x),Int_val(y));
        CAMLreturn(Val_unit);
    }

    CAMLprim value tiledgroup_position_bc(value* args, int argc)
    { return tiledgroup_position(args[0],args[1],args[2],args[3],args[4]); }

}


