#ifndef OCAMLFLTK_H 
#define OCAMLFLTK_H 

#include <iostream>

extern "C" {
#define CAML_NAME_SPACE
#include "caml/mlvalues.h"
#include "caml/alloc.h"
#include "caml/memory.h"
#include "caml/callback.h"
#include <string.h>

#define Float_val(x)    (float(Double_val(x)))    
}

namespace Ofltk {

inline value copy_string(const char* s)
{
    return ::caml_copy_string(s ? s : "");
}

static const int draw_method = caml_hash_variant("draw");
static const int handle_method = caml_hash_variant("handle");
static const int layout_method = caml_hash_variant("layout");

template<class widget, const char* name>
class fltk_widget: public widget {
        const char* id;
    protected:
        ::value* ocaml_obj;

    public:
    fltk_widget(::value* oclass, int x, int y, int w, int h, const char* t = 0)
        : widget(x, y, w, h, t), id(name), ocaml_obj(oclass)
    { }

    virtual ~fltk_widget()
    { }

    void default_draw()
    {
        //std::cout << "drawing a default " << id << std::endl;
        widget::draw();
    }

    virtual void draw()
    {
        caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
    }

    int default_handle(int e)
    {
        return widget::handle(e);
    }

    virtual int handle(int e)
    {
        //std::cout << id <<  "-handle event: " << e << std::endl;
        return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
    }
};


// NEW_WIDGET(Widget) gives: 
// extern char Widget_id[];
// typedef fltk_widget<fltk::Widget, Widget_id> Widget_d;
//

}
#define NEW_WIDGET(typ) \
            extern char typ ## _id[];\
            typedef fltk_widget<fltk::typ, typ##_id>  o_##typ;

#define GEN_NEW(widget) \
    CAMLprim value new_##widget(value name, value x, value y, value w, value h, value label)\
    {\
        CAMLparam5(x,y,w,h,label);\
        CAMLxparam1(name);\
        o_##widget* wp = new o_##widget(caml_named_value(String_val(name)),\
                 Int_val(x), Int_val(y), Int_val(w), Int_val(h), String_val(label));\
        CAMLreturn((value) wp);\
    }\
    CAMLprim value new_##widget##_bc(value* args, int argc)\
    { return new_##widget(args[0],args[1],args[2],args[3],args[4],args[5]); }


#endif
