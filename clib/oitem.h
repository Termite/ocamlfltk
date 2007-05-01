#ifndef OITEM_H
#define OITEM_H

#include "owidget.h"
#include <fltk/Item.h>
#include <fltk/ItemGroup.h>

namespace Ofltk {

    class o_Item : public fltk::Item {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        o_Item(::value* oclass, const char* label=0)
            : fltk::Item(label)
              , id("Item-director") 
              , ocaml_obj(oclass)
        { }

        virtual ~o_Item()
        { }

        void default_draw()
        {
            std::cout << "drawing a " << id << std::endl;
            fltk::Item::draw();
        }

        virtual void draw()
        {
            caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
        }

        int default_handle(int e)
        {
            return fltk::Item::handle(e);
        }

        virtual int handle(int e)
        {
            //std::cout << id <<  "-handle event: " << e << std::endl;
            return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
        }
    };

    class o_ItemGroup : public fltk::ItemGroup {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        o_ItemGroup(::value* oclass, const char* label=0)
            : fltk::ItemGroup(label)
              , id("ItemGroup-director") 
              , ocaml_obj(oclass)
        { }

        virtual ~o_ItemGroup()
        { }

        void default_draw()
        {
            std::cout << "drawing a " << id << std::endl;
            fltk::ItemGroup::draw();
        }

        virtual void draw()
        {
            caml_callback(caml_get_public_method(*ocaml_obj, draw_method), *ocaml_obj);
        }

        int default_handle(int e)
        {
            return fltk::ItemGroup::handle(e);
        }

        virtual int handle(int e)
        {
            //std::cout << id <<  "-handle event: " << e << std::endl;
            return Int_val(caml_callback2(caml_get_public_method(*ocaml_obj, handle_method), *ocaml_obj, Val_int(e)));
        }
    };

}

#endif


