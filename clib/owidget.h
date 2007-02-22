#ifndef OWIDGET_H
#define OWIDGET_H

#include "ocamlfltk.h"
#include <fltk/Widget.h>
#include <fltk/InvisibleBox.h>

#define MAKE_NEW(widget) \
    CAMLprim value new_##widget(value name, value x, value y, value w, value h, value label)\
    {\
        CAMLparam5(x,y,w,h,label);\
        CAMLxparam1(name);\
        ocaml_##widget* wp = new ocaml_##widget(caml_named_value(String_val(name)),\
                 Int_val(x), Int_val(y), Int_val(w), Int_val(h), String_val(label));\
        CAMLreturn((value) wp);\
    }\
    CAMLprim value new_##widget##_bc(value* args, int argc)\
    { return new_##widget(args[0],args[1],args[2],args[3],args[4],args[5]); }


namespace Ofltk {

NEW_DIRECTOR(Widget);

class ocaml_widget {
    protected:
        fltk::Widget* dest_widget;
        ::value* caml_obj;

    public:
        ::value* callback_fkt;

        ocaml_widget() 
            : dest_widget(0), caml_obj(0), callback_fkt(0)
        {}

        ocaml_widget(::value* o_obj, int x, int y, int w, int h, const char* t = 0)
            : dest_widget(new Widget_d(o_obj, x, y, w, h, t)), caml_obj(o_obj)
        {
        }

        virtual ~ocaml_widget() {}

        fltk::Widget* give_widget() { return dest_widget; }

        void hide() { dest_widget->hide(); }
        virtual void show() { static_cast<Widget_d*>(dest_widget)->show(); }
        int w() { dest_widget->w(); }
        int h() { dest_widget->h(); }
        int flags() { dest_widget->flags(); }
        void flags(int f) { dest_widget->flags(f); }
        uchar get_when() { return dest_widget->when(); }
        void set_when(uchar f) { dest_widget->when(f); }
        uchar get_type() { return dest_widget->type(); }
        void set_type(uchar f) { dest_widget->type(f); }
        void relayout() { dest_widget->relayout(); }
        void set_vertical() { dest_widget->set_vertical(); }
        void set_horitontal() { dest_widget->set_horizontal(); }
        void set_box(fltk::Box* b) { dest_widget->box(b); }

        void color(unsigned c) { dest_widget->color(c); }
        void copy_label(const char* l)
        {
            dest_widget->copy_label(l);
        }

        void callback(fltk::Callback* cb, void* data)
        {
            dest_widget->callback(cb, data);
        }

        virtual void default_draw()
        {
            std::cout << "default draw" << std::endl;
            static_cast<Widget_d*>(dest_widget)->default_draw();
        }

        virtual void draw()
        {
            dest_widget->draw();            
        }

        virtual void redraw()
        {
            dest_widget->redraw();
        }

        virtual int default_handle(int ev)
        {
            return static_cast<Widget_d*>(dest_widget)->default_handle(ev); 
        }
};

NEW_DIRECTOR(InvisibleBox);

class ocaml_invisiblebox : public ocaml_widget {
    public:
        ocaml_invisiblebox() : ocaml_widget() {}

        ocaml_invisiblebox(value* ocaml, int x, int y, int w, int h, const char* t = 0)
        {
            dest_widget = new InvisibleBox_d(ocaml, x, y, w, h, t);
        }

        virtual ~ocaml_invisiblebox() {}

        virtual void default_draw()
        {
            static_cast<InvisibleBox_d*>(dest_widget)->default_draw();
        }

        int default_handle(int ev)
        {
            return static_cast<InvisibleBox_d*>(dest_widget)->default_handle(ev); 
        }
};

};

#endif

