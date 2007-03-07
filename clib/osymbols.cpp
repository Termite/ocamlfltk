#include "osymbols.h"

using namespace Ofltk;

extern "C" {


    CAMLprim value new_symbol(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        ocaml_symbol* s =
            new ocaml_symbol(caml_named_value(String_val(_draw)), String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value symbol_measure(value symbol, value _w, value _h)
    {
        CAMLparam3(symbol, _w, _h);
        CAMLlocal1(erg);
        int w = Int_val(_w);
        int h = Int_val(_h);
        ((ocaml_symbol*)symbol)->measure(w, h);
        erg = caml_alloc_small(2, 0);     
        Field(erg, 0) = Val_int(w);
        Field(erg, 1) = Val_int(h);
        CAMLreturn(erg);
    }

    CAMLprim value symbol_set_name(value symbol, value name)
    {
        CAMLparam2(symbol, name);
        ((ocaml_symbol*)symbol)->name(String_val(name));
        CAMLreturn(Val_unit);
    }

    CAMLprim value symbol_get_name(value symbol)
    {
        CAMLparam1(symbol);
        const char* n = ((ocaml_symbol*)symbol)->name();
        CAMLreturn(copy_string(n));
    }

    CAMLprim value symbol_is_frame(value symbol)
    {
        CAMLparam1(symbol);
        bool n = ((ocaml_symbol*)symbol)->is_frame();
        CAMLreturn(Val_int(n));
    }

    CAMLprim value new_flatbox(value _draw, value name)
    {
        CAMLparam2(_draw, name);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_flatbox* s = new ocaml_flatbox(draw, String_val(name));
        CAMLreturn((value) s);
    }

    CAMLprim value new_framebox(value _draw, value name, value x, value y,
            value w, value h, value pattern, value down_box)
    {
        CAMLparam4(_draw, name, x, y);
        CAMLxparam4(h, pattern, down_box, w);
        ocaml_symbol* down = (Is_block(down_box)) ? (ocaml_symbol*)Field(down_box,0) : 0;
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_framebox* s =
            new ocaml_framebox(draw, String_val(name),
                    Int_val(x), Int_val(y), Int_val(w), Int_val(h),
                    String_val(pattern), down);
        CAMLreturn((value) s);
    }


    CAMLprim value new_framebox_bc(value* arg, int argc)
    {
        return new_framebox(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], arg[7]);
    }

    CAMLprim value framebox_get_data(value symbol)
    {
        CAMLparam1(symbol);
        CAMLreturn(copy_string(((ocaml_framebox*)symbol)->data()));
    }

    CAMLprim value framebox_set_data(value symbol, value data)
    {
        CAMLparam2(symbol, data);
        ((ocaml_framebox*)symbol)->data(String_val(data));
        CAMLreturn(Val_unit);
    }

    CAMLprim value new_highlightbox(value _draw, value name, value box)
    {
        CAMLparam3(_draw, name, box);
        value* draw = Is_block(_draw) 
            ? caml_named_value(String_val(Field(_draw,0)))
            : 0;
        ocaml_highlightbox* s = new ocaml_highlightbox(draw, String_val(name)
                , (ocaml_symbol*) box);
        CAMLreturn((value) s);
    }

    CAMLprim value find_symbol(value name)
    {
        CAMLparam1(name);
        CAMLlocal1(ret);
        fltk::Symbol* s = const_cast<fltk::Symbol*>(fltk::Symbol::find(String_val(name)));
        if (!s) CAMLreturn(Val_int(0));
        ret = caml_alloc_small(1,0);
        Field(ret,0) = (value)(new ocaml_symbol(s));
        CAMLreturn(ret);
    }
        
    CAMLprim value find_between(value name, value start, value stop)
    {
        CAMLparam3(name, start, stop);
        CAMLlocal1(ret);
        char* str = String_val(name);
        int l = strlen(str);
        int a = Int_val(start);
        int b = Int_val(stop);
        //XXX exception?
        if (a >= b || a < 0 || b <= 0 || a > l || b > l) CAMLreturn(Val_int(0));
        fltk::Symbol* s = const_cast<fltk::Symbol*>(fltk::Symbol::find(str+a, str+b));
        if (!s) CAMLreturn(Val_int(0));
        ret = caml_alloc_small(1,0);
        Field(ret,0) = (value)(new ocaml_symbol(s));
        CAMLreturn(ret);
    }
        
    CAMLprim value symbol_iter(value nr)
    {
        CAMLparam1(nr);
        CAMLlocal2(ret,opt);
        int n = Int_val(nr);
        fltk::Symbol* s = const_cast<fltk::Symbol*>(fltk::Symbol::iterate(n));
        if (!s) 
        {
            opt = Val_int(0);  
        }
        else
        {
            ocaml_symbol* os = new ocaml_symbol(s);
            ret = caml_alloc_small(2,0);
            Field(ret,0) = Val_int(n);
            Field(ret,1) = (value)os; 
            opt = caml_alloc_small(1,0);
            Field(opt,0) = ret;
        }
        CAMLreturn(opt);
    }
        
    static void margin (int n)
    { while (n-- > 0) printf(".");  return; }

    static void print_block (value v,int m) 
    {
        unsigned int size ;
        unsigned int i;
        margin(m);
        if (Is_long(v)) 
        { printf("immediate value (%d)\n", Int_val(v));  return; };
        printf ("memory block: size=%d  -  ", size=Wosize_val(v));
        switch (Tag_val(v))
        {
            case Closure_tag : 
                printf("closure with %d free variables\n", size-1);
                margin(m+4); printf("code pointer: %p\n",Code_val(v)) ;
                for (i=1;i<size;i++)  print_block(Field(v,i), m+4);
                break;
            case String_tag :
                printf("string: %s (%s)\n", String_val(v),(char *) v);  
                break;
            case Double_tag:  
                printf("float: %g\n", Double_val(v));
                break;
            case Double_array_tag : 
                printf ("float array: "); 
                for (i=0;i<size/Double_wosize;i++)  printf("  %g", Double_field(v,i));
                printf("\n");
                break;
            case Custom_tag: printf("custom type\n"); break;
            case Abstract_tag : printf("abstract type\n"); break;
            case Object_tag : printf("object type\n"); 
                              for (i=2; i<size; i++) print_block(Field(v,i), m+4);
                              break;
            default:  
                              if (Tag_val(v)>=No_scan_tag) { printf("unknown tag"); break; }; 
                              printf("structured block (tag=%d):\n",Tag_val(v));
                              for (i=0;i<size;i++)  print_block(Field(v,i),m+4);
        }
        return ;
    }

    CAMLprim value inspect_block (value v)  
    { print_block(v,4); fflush(stdout); return Val_unit; }


    
}
