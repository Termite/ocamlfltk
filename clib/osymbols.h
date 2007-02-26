#ifndef OSYMBOLS_H
#define OSYMBOLS_H

#include "ocamlfltk.h"
#include <fltk/Symbol.h>

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
             value m = caml_callback(*measure_method, Val_unit);
             w = Field(m,0);
             h = Field(m,1);
        }
    }


};


class ocaml_symbol {
    protected:
        fltk::Symbol* dest;

    public:
        ocaml_symbol() : dest(0) {}
        ocaml_symbol(fltk::Symbol* s) : dest(s)
        { }

        ocaml_symbol(value* dm, const char* name)        
        {
            dest = new Symbol_d(dm, name);
        }
        virtual ~ocaml_symbol() {}

        fltk::Symbol* dest_widget() { return dest; }

        virtual void _draw(const fltk::Rectangle& r)
        {
            dest->_draw(r);
        }
        virtual void measure(int& w, int &h)
        {
            dest->measure(w, h);
        }
        void name(const char* n) { dest->name(n); }
        const char* name(void) { return dest->name(); }
        int dx() { return dest->dx(); }
        int dy() { return dest->dy(); }
        int dw() { return dest->dw(); }
        int dh() { return dest->dh(); }

};




}
#endif

