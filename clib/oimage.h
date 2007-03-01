#ifndef OIMAGE_H
#define OIMAGE_H

#include "osymbols.h"
#include <fltk/Image.h>

namespace Ofltk {

class Image_d : public fltk::Image {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:

    Image_d(value* dm, const char* name) 
        : fltk::Image(name), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}
    Image_d(value* dm, int w, int h, const char* name) 
        : fltk::Image(w, h, name), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~Image_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
        else
            fltk::Image::_draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::Image::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_image : public ocaml_symbol {

    public:
        ocaml_image() : ocaml_symbol() {}

        ocaml_image(value* dm, const char* name)        
        {
            dest = new Image_d(dm, name);
        }
        ocaml_image(value* dm, int w, int h, const char* name)        
        {
            dest = new Image_d(dm, w, h, name);
        }

        virtual ~ocaml_image() {}

};



}

#endif
