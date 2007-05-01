#ifndef OIMAGE_H
#define OIMAGE_H

#include "osymbols.h"
#include <fltk/Image.h>
#include <fltk/TiledImage.h>

namespace Ofltk {

class o_Image : public symbol_base, public fltk::Image {

    public:

    o_Image(value vm, const char* name) 
        : symbol_base(vm), fltk::Image(name)
    {}
    o_Image(value vm, int w, int h, const char* name) 
        : symbol_base(vm), fltk::Image(w, h, name)
    {}

    virtual ~o_Image() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            base_draw(r); 
        }
        else
            fltk::Image::_draw(r);
    }

    virtual void _measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::Image::_measure(w, h);
        else {             
             base_measure(w, h); 
        }
    }


};

class o_TiledImage : public symbol_base, public fltk::TiledImage {

    public:

    o_TiledImage(value vm, fltk::Symbol* box) 
        : symbol_base(vm), fltk::TiledImage(box)
    {}

    virtual ~o_TiledImage() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            base_draw(r); 
        }
        else {
            fltk::TiledImage::_draw(r);
	}
    }

    virtual void _measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::TiledImage::_measure(w, h);
        else {             
             base_measure(w, h); 
        }
    }
};

}

#endif
