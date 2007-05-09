open Widgets;;

module TextBuffer = struct

type textselection;;
type textbuffer;;

external make_selection: unit -> textselection = "make_TextSelection";;
external make_textbuffer: int -> textbuffer = "make_TextBuffer";;

end;;

open TextBuffer;;


external new_textDisplay: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_textDisplay_bc" "new_textDisplay";;
external textDisplay_draw: widget_ptr -> unit = "textDisplay_draw";;
external textDisplay_handle: widget_ptr -> Event.event_type -> Event.event_type
= "textDisplay_handle";;
external textDisplay_wrap_mode: widget_ptr -> int -> bool -> unit = "textDisplay_wrap_mode";;
external textDisplay_set_text: widget_ptr -> string -> unit = "textDisplay_set_text";;
external textDisplay_get_text: widget_ptr -> string = "textDisplay_get_text";;
external textDisplay_get_buffer: widget_ptr -> textbuffer = "textDisplay_get_buffer";;
external textDisplay_set_buffer: widget_ptr -> textbuffer -> unit = "textDisplay_set_buffer";;


class textDisplay x y w h label = object(self)
    inherit Widgets.group ~x ~y w h label
    method private alloc = new_textDisplay
    method handle ev = textDisplay_handle obj ev
    method draw = textDisplay_draw obj
    method wrap_mode ?(margin=0) wrap = textDisplay_wrap_mode obj margin wrap
    method get_text = textDisplay_get_text obj
    method set_text txt = textDisplay_set_text obj txt
    method set_buffer b = textDisplay_set_buffer obj b
    method get_buffer = textDisplay_get_buffer obj
end;;    

external new_textEditor: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_textEditor_bc" "new_textEditor";;
external textEditor_handle: widget_ptr -> Event.event_type -> Event.event_type
= "textEditor_handle";;
external textEditor_draw: widget_ptr -> unit = "textEditor_draw";;


class textEditor x y w h label = object(self)
    inherit textDisplay x y w h label
    method private alloc = new_textEditor
    method handle ev = textEditor_handle obj ev
    method draw = textEditor_draw obj
end;;    



