#ifndef ODIVIDER_H
#define ODIVIDER_H

#include "owidget.h"
#include <fltk/Divider.h>

namespace Ofltk {

    class Divider_d : public fltk::Divider {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        Divider_d(::value* oclass)
            : fltk::Divider()
              , ocaml_obj(oclass)
              , id("Divider-director") 
        { }

        virtual ~Divider_d()
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

    class ocaml_divider : public ocaml_widget {
        public:
            ocaml_divider() : ocaml_widget() {}

            ocaml_divider(value* ocaml)
            {
                dest_widget = new Divider_d(ocaml);
            }

            virtual ~ocaml_divider() {}

            DEF_DEFAULT(Divider_d)

    };
    

}

#endif
