#ifndef OWIDGET_H
#define OWIDGET_H

#include "ocamlfltk.h"
#include <fltk/Widget.h>
#include <fltk/InvisibleBox.h>
#include "orect.h"
#include "osymbols.h"

namespace Ofltk {

NEW_WIDGET(Widget);

class o_InvisibleBox : public fltk::InvisibleBox {
        const char* id;
    protected:
        ::value* ocaml_obj;

    public:
    o_InvisibleBox(::value* oclass, int x, int y, int w, int h, const char* t = 0)
        : fltk::InvisibleBox(x, y, w, h, t), id("InvisibleBox"), ocaml_obj(oclass)
    { }

    o_InvisibleBox(::value* oclass, fltk::Box* b, int x, int y, int w, int h, const char* t)
        : fltk::InvisibleBox(b, x, y, w, h, t), id("InvisibleBox"), ocaml_obj(oclass)
    { }

    virtual ~o_InvisibleBox()
    { }

    void default_draw()
    {
        //std::cout << "drawing a default " << id << std::endl;
        fltk::InvisibleBox::draw();
    }

    virtual void draw()
    {
        caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
    }

    int default_handle(int e)
    {
        return fltk::InvisibleBox::handle(e);
    }

    virtual int handle(int e)
    {
        //std::cout << id <<  "-handle event: " << e << std::endl;
        return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
    }
};

};

#endif

