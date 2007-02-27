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
class fltk_director: public widget {
        const char* id;
    protected:
        ::value* ocaml_obj;

    public:
    fltk_director(::value* oclass, int x, int y, int w, int h, const char* t = 0)
        : widget(x, y, w, h, t), ocaml_obj(oclass), id(name) 
    { }

    virtual ~fltk_director()
    { }

    void default_draw()
    {
        std::cout << "drawing a " << id << std::endl;
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

// NEW_DIRECTOR(Widget) gives: 
// extern char Widget_id[];
// typedef fltk_director<fltk::Widget, Widget_id> Widget_d;
//

}
// = #typ "-director";
#define NEW_DIRECTOR(typ) extern char typ ## _id[];\
                      typedef fltk_director<fltk::typ, typ##_id>  typ##_d;

#define DEF_DEFAULT(widget)\
            virtual void default_draw() { static_cast<widget*>(dest_widget)->default_draw(); }\
            virtual int default_handle(int ev) { return static_cast<widget*>(dest_widget)->default_handle(ev); }


#endif
