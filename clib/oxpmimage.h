#ifndef OXPMIMAGE_H
#define OXPMIMAGE_H

#include "oimage.h"
#include <fltk/xpmImage.h>

namespace Ofltk {

class xpmImage_d : public fltk::xpmImage {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:

    xpmImage_d(value* dm, const char * const * data, const char* name) 
        : fltk::xpmImage(data, name), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~xpmImage_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
        else
            fltk::xpmImage::_draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::xpmImage::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_xpmimage : public ocaml_image {

    public:
        ocaml_xpmimage() : ocaml_image() {}

        ocaml_xpmimage(value* dm, const char * const * data, const char* name)        
        {
            dest = new xpmImage_d(dm, data, name);
        }

        virtual ~ocaml_xpmimage() {}

};

}

#endif

