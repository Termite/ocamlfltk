#ifndef OMULTI_IMAGE_H
#define OMULTI_IMAGE_H

#include "osymbols.h"
#include "osymbolbase.h"
#include <fltk/MultiImage.h>

namespace Ofltk {

class o_MultiImage : public symbol_base, public fltk::MultiImage {

    public:
    o_MultiImage(value vm) : symbol_base(vm), fltk::MultiImage() {}

    o_MultiImage(value vm, const fltk::Symbol& image0)
        : symbol_base(vm), fltk::MultiImage(image0)
    {}

    virtual ~o_MultiImage() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
            base_draw(r);
        else
            fltk::MultiImage::_draw(r);
    }

    virtual void _measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::MultiImage::_measure(w, h);
        else {             
            base_measure(w, h);
        }
    }

};

}

#endif

