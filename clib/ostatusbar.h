#ifndef OSTATUSBAR_H
#define OSTATUSBAR_H

#include "ogroup.h"
#include <fltk/StatusBarGroup.h>

namespace Ofltk {

class StatusBarGroup_d: public fltk::StatusBarGroup {
        const char* id;
    protected:
        ::value* ocaml_obj;

    public:
    StatusBarGroup_d(::value* oclass, int x, int y, int w, int h, const char* t = 0)
        : fltk::StatusBarGroup(x, y, w, h, t), id("StatusBarGroup"), ocaml_obj(oclass) 
    { }

    StatusBarGroup_d(::value* oclass, int h = 24)
        : fltk::StatusBarGroup(h), id("StatusBarGroup"), ocaml_obj(oclass) 
    { }

    virtual ~StatusBarGroup_d()
    { }

    void default_draw()
    {
        std::cout << "drawing a " << id << std::endl;
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

class ocaml_statusbar : public ocaml_group {
    public:

        ocaml_statusbar() : ocaml_group() {}

        ocaml_statusbar(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new StatusBarGroup_d(ocaml, x, y, w, h, t);
        }

        ocaml_statusbar(value* ocaml, int h = 24) 
        {
            dest_widget = new StatusBarGroup_d(ocaml, h);
        }

        virtual ~ocaml_statusbar() {}

        DEF_DEFAULT(StatusBarGroup_d);

        void set(const char* txt, fltk::StatusBarGroup::Position pos)
        {
            static_cast<StatusBarGroup_d*>(dest_widget)->set(txt, pos);
        }

        void child_box(fltk::Box* box, fltk::StatusBarGroup::Position pos)
        {
            static_cast<StatusBarGroup_d*>(dest_widget)->child_box(box, pos);
        }
};


}

#endif
