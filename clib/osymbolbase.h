#ifndef OSYMBOL_BASE_H
#define OSYMBOL_BASE_H

#include "ocamlfltk.h"
#include <fltk/Rectangle.h>


namespace Ofltk {

class symbol_base {
    protected:
    ::value* _draw_method;
    ::value* fills_rect_method;
    ::value* is_frame_method;
    ::value* inset_method;
    ::value* measure_method;

    public:
    symbol_base() : _draw_method(0), fills_rect_method(0),
        is_frame_method(0), inset_method(0), measure_method(0)
    {}
    symbol_base(value vm)
    {
    	value s1 = Field(vm,0);
	_draw_method = Is_long(s1) ? 0 : caml_named_value(String_val(Field(s1,0)));
    	value s2 = Field(vm,1);
	measure_method = Is_long(s2) ? 0 : caml_named_value(String_val(Field(s2,0)));
    	value s3 = Field(vm,2);
	fills_rect_method = Is_long(s3) ? 0 : caml_named_value(String_val(Field(s3,0)));
    	value s4 = Field(vm,3);
	is_frame_method = Is_long(s4) ? 0 : caml_named_value(String_val(Field(s4,0)));
    	value s5 = Field(vm,4);
	inset_method = Is_long(s5) ? 0 : caml_named_value(String_val(Field(s5,0)));
    }

    void base_draw(const fltk::Rectangle& r) const
    {
	    ::value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
	    caml_callbackN(*_draw_method, 4, args);
    }

    void base_measure(int&w, int& h)
    {
	    ::value m = caml_callback2(*measure_method, Val_int(w), Val_int(h));
	    w = Int_val(Field(m,0));
	    h = Int_val(Field(m,1));
    }

    bool base_fill(const fltk::Rectangle&r)
    {
	    ::value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };
	    return Int_val(caml_callbackN(*fills_rect_method , 4, args));
    }

};

}

#define DRAW(c) \
    void base_draw(const fltk::Rectangle& r) const\
    {\
        if (_draw_method)\
        {\
            ::value args[] = {  Val_int(r.x()), Val_int(r.y()), Val_int(r.w()), Val_int(r.h()) };\
            caml_callbackN(*_draw_method, 4, args);\
        }\
        else\
            c::_draw(r);\
    }





#endif
