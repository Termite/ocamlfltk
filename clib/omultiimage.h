#ifndef OMULTI_IMAGE_H
#define OMULTI_IMAGE_H

#include "osymbols.h"
#include <fltk/MultiImage.h>

namespace Ofltk {

class MultiImage_d : public fltk::MultiImage {
    value* _draw_method;
    value* fills_rect_method;
    value* is_frame_method;
    value* inset_method;
    value* measure_method;

    public:
    MultiImage_d(value* dm) : fltk::MultiImage(), _draw_method(dm) {}

    MultiImage_d(value* dm, const fltk::Symbol& image0)
        : fltk::MultiImage(image0), _draw_method(dm), fills_rect_method(0)
          , is_frame_method(0), inset_method(0), measure_method(0)
    {}

    virtual ~MultiImage_d() {}

    virtual void _draw(const fltk::Rectangle& r) const
    {
        if (_draw_method) 
        {
            value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
            caml_callbackN(*_draw_method, 4, args);
        }
        else
            fltk::MultiImage::_draw(r);
    }

    virtual void measure(int&w, int& h)
    {
        if (!measure_method)
            fltk::MultiImage::measure(w, h);
        else {             
             value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
             w = Int_val(Field(m,0));
             h = Int_val(Field(m,1));
        }
    }


};


class ocaml_multiimage : public ocaml_symbol {

    public:
        ocaml_multiimage() : ocaml_symbol() {}
        ocaml_multiimage(fltk::Symbol* s) : ocaml_symbol(s) {}

        ocaml_multiimage(value* dm, ocaml_symbol* image0)        
        {
            dest = new MultiImage_d(dm, *(image0->dest_symbol()));
        }
        virtual ~ocaml_multiimage() {}

        virtual void add(int flags, ocaml_symbol* image)
        {
           static_cast<MultiImage_d*>(dest)->add(flags, *(image->dest_symbol()));   
        }


};

}

#endif

