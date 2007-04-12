#ifndef OWIDGET_H
#define OWIDGET_H

#include "ocamlfltk.h"
#include <fltk/Widget.h>
#include <fltk/InvisibleBox.h>
#include "orect.h"
#include "osymbols.h"

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
           
#define dest_ptr  static_cast<fltk::Widget*>(dest_widget) 

class ocaml_widget : public ocaml_rect {
    protected:
        ::value* caml_obj;

    public:

        ocaml_widget() 
            : caml_obj(0)
        {
            dest_widget = 0;
        }

        ocaml_widget(fltk::Widget* w)
        {
            dest_widget = w;
        }

        ocaml_widget(::value* o_obj, int x, int y, int w, int h, const char* t = 0)
            :  caml_obj(o_obj)
        {      
            dest_widget = new Widget_d(o_obj, x, y, w, h, t);
        }

        virtual ~ocaml_widget() {}

        fltk::Widget* give_widget() { return static_cast<fltk::Widget*>(dest_widget); }
        void store_obj(value* o) { caml_obj = o; }

        void hide() { dest_ptr->hide(); }
        virtual void show() { dest_ptr->show(); }
        int flags() { return dest_ptr->flags(); }
        void flags(int f) { dest_ptr->flags(f); }
        uchar get_when() { return dest_ptr->when(); }
        void set_when(uchar f) { dest_ptr->when(f); }
        uchar get_type() { return dest_ptr->type(); }
        uchar damage() { return dest_ptr->damage(); }
        void tooltip(const char* t) { dest_ptr->tooltip(t); }
        const char* tooltip() { return dest_ptr->tooltip(); }
        void set_type(uchar f) { dest_ptr->type(f); }
        void relayout() { dest_ptr->relayout(); }
        void set_vertical() { dest_ptr->set_vertical(); }
        void set_horitontal() { dest_ptr->set_horizontal(); }
        virtual void set_box(fltk::Box* b) { dest_ptr->box(b); }
        virtual ocaml_symbol* get_box() { return new ocaml_symbol(dest_ptr->box()); }
        void labelfont(fltk::Font* s) { dest_ptr->labelfont(s); }
        fltk::Font* labelfont() { return dest_ptr->labelfont(); }
        void labelsize(double s) { dest_ptr->labelsize(s); }
        double labelsize() { return dest_ptr->labelsize(); }
        void image(ocaml_symbol* s) { dest_ptr->image(s->dest_symbol());}
        ocaml_symbol* image()
        {
            return new ocaml_symbol(const_cast<fltk::Symbol*>(dest_ptr->image()));
        }

        void color(unsigned c) { dest_ptr->color(c); }
        void copy_label(const char* l)
        {
            dest_ptr->copy_label(l);
        }

        void callback(fltk::Callback* cb, void* data)
        {
            dest_ptr->callback(cb, data);
        }

        DEF_DEFAULT(Widget_d);

        virtual void draw()
        {
            dest_ptr->draw();            
        }

        virtual void redraw()
        {
            dest_ptr->redraw();
        }

        virtual bool resize(int w, int h)
        {
            return dest_ptr->resize(w, h);
        }

        virtual bool resize(int x, int y, int w, int h)
        {
            return dest_ptr->resize(x, y, w, h);
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

        DEF_DEFAULT(InvisibleBox_d);
};

};

#endif

