#ifndef OXPMIMAGE_H
#define OXPMIMAGE_H

#include "oimage.h"
#include "osymbolbase.h"
#include <fltk/xpmImage.h>


namespace Ofltk {

class o_XpmImage : public symbol_base, public fltk::xpmImage {

    public:

    o_XpmImage(value vm, const char * const * data, const char* name) 
        : symbol_base(vm), fltk::xpmImage(data, name)
    { }

    virtual ~o_XpmImage() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
            base_draw(r);
        else
            fltk::xpmImage::_draw(r);
    }

    virtual void _measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::xpmImage::_measure(w, h);
        else {             
            base_measure(w, h);
        }
    }

};

}

#endif

