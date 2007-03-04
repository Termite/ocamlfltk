#ifndef OSYMBOLS_H
#define OSYMBOLS_H

#include "ocamlfltk.h"
#include <fltk/Symbol.h>
#include <fltk/Box.h>

namespace Ofltk {

class Symbol_d : public fltk::Symbol {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:
    Symbol_d(value* dm, const char* name)
        : Symbol(name), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~Symbol_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
        caml_callbackN(*_draw_method, 4, args);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::Symbol::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_symbol {
    protected:
        fltk::Symbol* dest;

    public:
        ocaml_symbol() : dest(0) {}
        ocaml_symbol(fltk::Symbol* s) : dest(s) { }

        ocaml_symbol(value* dm, const char* name)        
        {
            dest = new Symbol_d(dm, name);
        }
        virtual ~ocaml_symbol() {}

        fltk::Symbol* dest_symbol() { return dest; }
        const fltk::Symbol& symbol() { return *dest; } 

        virtual void _draw(const fltk::Rectangle& r)
        {
            dest->_draw(r);
        }
        virtual void measure(int& w, int &h)
        {
            dest->measure(w, h);
        }
        virtual void name(const char* n) { dest->name(n); }
        virtual const char* name(void) { return dest->name(); }
        virtual int dx() { return dest->dx(); }
        virtual int dy() { return dest->dy(); }
        virtual int dw() { return dest->dw(); }
        virtual int dh() { return dest->dh(); }
        virtual bool is_frame() { return dest->is_frame(); }

};

/**********************************************************************************/
/*                                     FlatBox                                    */
/**********************************************************************************/


class FlatBox_d : public fltk::FlatBox {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:
    FlatBox_d(value* dm, const char* name)
        : FlatBox(name), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~FlatBox_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
        else
            fltk::FlatBox::_draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::Symbol::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_flatbox : public ocaml_symbol {

    public:
        ocaml_flatbox() : ocaml_symbol() {}
        ocaml_flatbox(fltk::FlatBox* s) : ocaml_symbol(s) {}

        ocaml_flatbox(value* dm, const char* name)        
        {
            dest = new FlatBox_d(dm, name);
        }
        virtual ~ocaml_flatbox() {}


};


/**********************************************************************************/
/*                                     FrameBox                                   */
/**********************************************************************************/

class FrameBox_d : public fltk::FrameBox {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:
    FrameBox_d(value* dm, const char* name, int dx, int dy, int dw, int dh,
            const char* pattern, fltk::Box* down = 0)
        : FrameBox(name, dx, dy, dw, dh, pattern, down)
          , _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~FrameBox_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (!_draw_method)
            fltk::FrameBox::_draw(r);
        else {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::FrameBox::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_framebox : public ocaml_symbol {

    public:
        ocaml_framebox() : ocaml_symbol() {}
        ocaml_framebox(fltk::FrameBox* s) : ocaml_symbol(s) {}

        ocaml_framebox(value* dm, const char* name, int x, int y, int w, int h,
                const char* pattern, ocaml_symbol* box)
        {
            dest = new FrameBox_d(dm, name, x, y, w, h, pattern, box->dest_symbol());
        }
        virtual ~ocaml_framebox() {}

        virtual const char* data() { return static_cast<fltk::FrameBox*>(dest)->data(); }
        virtual void data(const char* d) { static_cast<fltk::FrameBox*>(dest)->data(d); }

};


/**********************************************************************************/
/*                                     HighlightBox                               */
/**********************************************************************************/

class HighlightBox_d : public fltk::HighlightBox {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:
    HighlightBox_d(value* dm, const char* name, fltk::Box* box)
        : HighlightBox(name, box)
          , _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~HighlightBox_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (!_draw_method)
            fltk::HighlightBox::_draw(r);
        else {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::HighlightBox::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_highlightbox : public ocaml_flatbox {

    public:
        ocaml_highlightbox() : ocaml_flatbox() {}
        ocaml_highlightbox(fltk::HighlightBox* s) : ocaml_flatbox(s) {}

        ocaml_highlightbox(value* dm, const char* name, ocaml_symbol* box) 
        {
            dest = new HighlightBox_d(dm, name, box->dest_symbol());
        }
        virtual ~ocaml_highlightbox() {}

};

}
#endif

