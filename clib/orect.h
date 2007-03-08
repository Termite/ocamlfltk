#ifndef ORECT_H
#define ORECT_H


#include <fltk/Rectangle.h>

namespace fltk {
    class Widget;
}

namespace Ofltk {


class ocaml_rect {
    protected:

    fltk::Rectangle* dest_widget;

    public:
    ocaml_rect() : dest_widget(0) {}
    virtual ~ocaml_rect()
    {
        std::cout << "ocaml_rectangle destroyed" << std::endl;
        //delete dest_widget;
    }

    int x() const { return dest_widget->x(); }
    int y() const { return dest_widget->y(); }
    int w() const { return dest_widget->w(); }
    int h() const { return dest_widget->h(); }

    void x(int v) { dest_widget->x(v); }
    void y(int v) { dest_widget->y(v); }
    void w(int v) { dest_widget->w(v); }
    void h(int v) { dest_widget->h(v); }  
    
};






}


#endif
