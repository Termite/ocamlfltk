#include "ocamlfltk.h"
#include <fltk/events.h>


using namespace Ofltk;

extern "C" {

    CAMLprim value event_dy(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_dy()));
    }

    CAMLprim value event_button(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_button()));
    }

    CAMLprim value event_set_clicks(value n)
    {
        CAMLparam1(n);
        fltk::event_clicks(Int_val(n));
        CAMLreturn(Val_unit);
    }

    CAMLprim value event_get_clicks(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_clicks()));
    }

    CAMLprim value event_is_click(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_is_click()));
    }

    CAMLprim value event_set_is_click(value n)
    {
        CAMLparam1(n);
        fltk::event_is_click(Int_val(n));
        CAMLreturn(Val_unit);
    }

    /*
    static unsigned keys[] =
    { 
        fltk::LeftButton, 
        fltk::MiddleButton, 
        fltk::RightButton, 
        fltk::SpaceKey, 
        fltk::BackSpaceKey, 
        fltk::TabKey, 
        fltk::ClearKey, 
        fltk::ReturnKey, 
        fltk::PauseKey, 
        fltk::ScrollLockKey, 
        fltk::EscapeKey, 
        fltk::HomeKey, 
        fltk::LeftKey, 
        fltk::UpKey, 
        fltk::RightKey, 
        fltk::DownKey, 
        fltk::PageUpKey, 
        fltk::PageDownKey, 
        fltk::EndKey, 
        fltk::PrintKey, 
        fltk::InsertKey, 
        fltk::MenuKey, 
        fltk::HelpKey, 
        fltk::NumLockKey, 
        fltk::Keypad, 
        fltk::KeypadEnter, 
        fltk::MultiplyKey, 
        fltk::AddKey, 
        fltk::SubtractKey, 
        fltk::DecimalKey, 
        fltk::DivideKey, 
        fltk::Keypad0, 
        fltk::Keypad1, 
        fltk::Keypad2, 
        fltk::Keypad3, 
        fltk::Keypad4, 
        fltk::Keypad5, 
        fltk::Keypad6, 
        fltk::Keypad7, 
        fltk::Keypad8, 
        fltk::Keypad9, 
        fltk::KeypadLast, 
        fltk::F0Key, 
        fltk::F1Key, 
        fltk::F2Key, 
        fltk::F3Key, 
        fltk::F4Key, 
        fltk::F5Key, 
        fltk::F6Key, 
        fltk::F7Key, 
        fltk::F8Key, 
        fltk::F9Key, 
        fltk::F10Key, 
        fltk::F11Key, 
        fltk::F12Key, 
        fltk::LastFunctionKey, 
        fltk::LeftShiftKey, 
        fltk::RightShiftKey, 
        fltk::LeftCtrlKey, 
        fltk::RightCtrlKey, 
        fltk::CapsLockKey, 
        fltk::LeftMetaKey, 
        fltk::RightMetaKey, 
        fltk::LeftAltKey, 
        fltk::RightAltKey, 
        fltk::DeleteKey, 
    };
    */

    CAMLprim value get_special_keys(value n)
    {
        CAMLparam1(n);
        CAMLlocal1(k);
        k = caml_alloc_small(4,0);
        Field(k,0) = fltk::LeftAccKey;
        Field(k,1) = fltk::RightAccKey;
        Field(k,2) = fltk::LeftCmdKey;
        Field(k,3) = fltk::RightCmdKey;
        CAMLreturn(k);
    }

    CAMLprim value event_key(value n)
    {
        CAMLparam1(n);
        CAMLreturn(Val_int(fltk::event_key()));
    }

}
