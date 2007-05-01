#ifndef OSTATUSBAR_H
#define OSTATUSBAR_H

#include "ogroup.h"
#include <fltk/StatusBarGroup.h>


namespace Ofltk {

class o_StatusBarGroup: public fltk::StatusBarGroup {
        const char* id;
    protected:
        ::value* ocaml_obj;

    public:
    o_StatusBarGroup(::value* oclass, int x, int y, int w, int h, const char* t = 0)
        : fltk::StatusBarGroup(x, y, w, h, t), id("StatusBarGroup"), ocaml_obj(oclass) 
    { }

    o_StatusBarGroup(::value* oclass, int h)
        : fltk::StatusBarGroup(h), id("StatusBarGroup"), ocaml_obj(oclass) 
    { 
        std::cout << "new easy statusbar" << std::endl;
    }

    virtual ~o_StatusBarGroup()
    { }

    void default_draw()
    {
        std::cout << "statusbar default draw" << std::endl;
        fltk::StatusBarGroup::draw();
    }

    virtual void draw()
    {
        caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
    }

    int default_handle(int e)
    {
        return fltk::StatusBarGroup::handle(e);
    }

    virtual int handle(int e)
    {
        //std::cout << id <<  "-handle event: " << e << std::endl;
        return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
    }
};


}

#endif
