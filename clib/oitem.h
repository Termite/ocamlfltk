#ifndef OITEM_H
#define OITEM_H

#include "owidget.h"
#include <fltk/Item.h>
#include <fltk/ItemGroup.h>

namespace Ofltk {

    class Item_d : public fltk::Item {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        Item_d(::value* oclass, const char* label=0)
            : fltk::Item(label)
              , ocaml_obj(oclass)
              , id("Item-director") 
        { }

        virtual ~Item_d()
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

    class ocaml_item : public ocaml_widget {
        public:
            ocaml_item() : ocaml_widget() {}

            ocaml_item(value* ocaml, const char* t = 0)
            {
                dest_widget = new Item_d(ocaml, t);
            }

            virtual ~ocaml_item() {}

            DEF_DEFAULT(Item_d);

    };

    class ItemGroup_d : public fltk::ItemGroup {
        const char* id;
        protected:
        ::value* ocaml_obj;

        public:
        ItemGroup_d(::value* oclass, const char* label=0)
            : fltk::ItemGroup(label)
              , ocaml_obj(oclass)
              , id("ItemGroup-director") 
        { }

        virtual ~ItemGroup_d()
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

    class ocaml_itemgroup : public ocaml_widget {
        public:
            ocaml_itemgroup() : ocaml_widget() {}

            ocaml_itemgroup(value* ocaml, const char* t = 0)
            {
                dest_widget = new ItemGroup_d(ocaml, t);
            }

            virtual ~ocaml_itemgroup() {}

            DEF_DEFAULT(ItemGroup_d);

    };

}

#endif


