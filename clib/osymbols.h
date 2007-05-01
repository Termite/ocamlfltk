#ifndef OSYMBOLS_H
#define OSYMBOLS_H

#include "ocamlfltk.h"
#include "osymbolbase.h"
#include <fltk/Symbol.h>
#include <fltk/Box.h>

namespace Ofltk {

class o_Symbol : public symbol_base, public fltk::Symbol {

    public:
    o_Symbol(value vm, const char* name)
        : symbol_base(vm), Symbol(name)
    {}

    virtual ~o_Symbol() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
    	if (draw_method) base_draw(r); else fltk::Symbol::draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            base_measure(w,h); 
	else fltk::Symbol::measure(w, h);
    }


};



/**********************************************************************************/
/*                                     FlatBox                                    */
/**********************************************************************************/


class o_FlatBox : public symbol_base, public fltk::FlatBox {

    public:
    o_FlatBox(value vm, const char* name)
        : symbol_base(vm), FlatBox(name)
    {}

    virtual ~o_FlatBox() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            base_draw(r);
        }
        else
            fltk::FlatBox::_draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::Symbol::measure(w, h);
        else {             
             base_measure(w, h);
        }
    }


};



/**********************************************************************************/
/*                                     FrameBox                                   */
/**********************************************************************************/

class o_FrameBox : public symbol_base, public fltk::FrameBox {

    public:
    o_FrameBox(value vm, const char* name, int dx, int dy, int dw, int dh,
            const char* pattern, fltk::Box* down = 0)
        : symbol_base(vm), FrameBox(name, dx, dy, dw, dh, pattern, down)
    {}

    virtual ~o_FrameBox() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (!_draw_method)
            fltk::FrameBox::_draw(r);
        else {
            base_draw(r);
        }
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::FrameBox::measure(w, h);
        else {             
             base_measure(w, h);
        }
    }


};




/**********************************************************************************/
/*                                     HighlightBox                               */
/**********************************************************************************/

class o_HighlightBox : public symbol_base, public fltk::HighlightBox {

    public:
    o_HighlightBox(value vm, const char* name, fltk::Box* box)
        : symbol_base(vm), HighlightBox(name, box)
    {}

    virtual ~o_HighlightBox() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (!_draw_method)
            fltk::HighlightBox::_draw(r);
        else {
            base_draw(r);
        }
    }

    virtual void _measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::HighlightBox::_measure(w, h);
        else {             
             base_measure(w, h);
        }
    }


};


}
#endif

