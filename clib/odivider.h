#ifndef ODIVIDER_H
#define ODIVIDER_H

#include "owidget.h"
#include <fltk/Divider.h>

namespace Ofltk {

    class o_Divider : public fltk::Divider {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        o_Divider(::value* oclass)
            : fltk::Divider()
              , id("Divider-director") 
              , ocaml_obj(oclass)
        { }

        virtual ~o_Divider()
        { }

        void default_draw()
        {
            std::cout << "drawing a " << id << std::endl;
            fltk::Divider::draw();
        }

        virtual void draw()
        {
            caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
        }

        int default_handle(int e)
        {
            return fltk::Divider::handle(e);
        }

        virtual int handle(int e)
        {
            //std::cout << id <<  "-handle event: " << e << std::endl;
            return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
        }
    };

}

#endif
