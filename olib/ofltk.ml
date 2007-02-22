type widget;;

external get_null_widget: unit -> widget = "get_null_widget";;

external run: unit -> int = "app_run" ;;

external new_window: string -> int -> int -> int -> int -> string -> widget
    = "new_window_bc" "new_window";;
external new_group: string -> int -> int -> int -> int -> string -> widget
    = "new_group_bc" "new_group";;
external group_begin: widget -> unit = "group_begin"
(*external addw: widget -> 'a -> unit = "group_add"*)
external group_end: widget -> unit = "group_end"
external set_resizeable : widget -> widget -> unit = "group_set_resizable";;
external window_draw: widget -> unit = "window_draw";;

external set_window_cb: widget -> string -> unit = "set_window_cb";;

let id = ref 0;;

let callback window (fkt: unit -> unit) = 
  incr id;
  let name = "wcb" ^ (string_of_int !id) in
    Callback.register name fkt;
    set_window_cb window name
;;


open Printf ;;
type flags = int;;

let no_flags		= 0x00000000
let align_top		  = 0x00000001
let align_bottom		  = 0x00000002
let align_left		  = 0x00000004
let align_right		  = 0x00000008
let align_center		  = 0x00000010
let align_inside		  = 0x00000020
let align_clip		  = 0x00000040
let align_wrap		  = 0x00000080
let align_mask		  = 0x000000ff
let align_positionmask      = 0x0000000f
let align_topleft		  = (align_top lor align_left)
let align_bottomleft	  = (align_bottom lor align_left)
let align_topright	  = (align_top lor align_right)
let align_bottomright	  = (align_bottom lor align_right)
let align_centerleft	  = (align_center lor align_left)
let align_centerright	  = (align_center lor align_right)
let align_inside_top	  = (align_inside lor align_top)
let align_inside_bottom	  = (align_inside lor align_bottom)
let align_inside_left	  = (align_inside lor align_left)
let align_inside_topleft	  = (align_inside lor align_topleft)
let align_inside_bottomleft = (align_inside lor align_bottomleft)
let align_inside_right	  = (align_inside lor align_right)
let align_inside_topright	  = (align_inside lor align_topright)
let align_inside_bottomright= (align_inside lor align_bottomright)
let align_menu		  = (align_inside_left lor align_clip)
let align_browser		  = align_menu
let inactive		  = 0x00000100
let output		  = 0x00000200
let state			  = 0x00000400
let selected		  = 0x00000800
let invisible		  = 0x00001000
let highlight		  = 0x00002000
let changed		  = 0x00004000
let copied_label		  = 0x00008000
let raw_label		  = 0x00010000
let layout_vertical	  = 0x00020000
let tab_to_focus		  = 0x00040000
let click_to_focus	  = 0x00080000
let inactive_r		  = 0x00100000
let focused		  = 0x00200000
let pushed		  = 0x00400000
let resize_none		  = 0
let resize_fit		  = 0x01000000
let resize_fill		  = 0x00800000
let opened		  = state



external new_widget: string -> int -> int -> int -> int -> string -> widget
    = "new_widget_bc" "new_widget"

external widget_show: widget -> unit = "widget_show";;
external widget_hide: widget -> unit = "widget_hide";;
external get_width: widget -> int = "get_width";;
external get_height: widget -> int = "get_height";;
external get_when: widget -> int = "widget_get_when";;
external set_when: widget -> int -> unit = "widget_set_when";;
external get_type: widget -> int = "widget_get_type";;
external set_type: widget -> int -> unit = "widget_set_type";;
external set_label: widget -> string -> unit = "widget_set_label";;
external set_color: widget -> int32 -> unit = "widget_set_color";;
external widget_set_box: widget -> Box.box -> unit = "widget_set_box";;

external widget_relayout: widget -> unit = "widget_relayout";;
external widget_draw: widget -> unit = "widget_draw";;
external widget_set_vertical: widget -> unit = "widget_set_vertical";;
external widget_set_horizontal: widget -> unit = "widget_set_horizontal";;
external widget_handle: widget -> int -> int = "widget_handle";;
external redraw_widget: widget -> unit = "redraw_widget";;

external new_button: string -> int -> int -> int -> int -> string -> widget = 
  "new_button_bc" "new_button";;
external new_checkbutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_checkbutton_bc" "new_checkbutton";;
external new_lightbutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_lightbutton_bc" "new_lightbutton";;
external new_radiobutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_radiobutton_bc" "new_radiobutton";;
external new_highlightbutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_highlightbutton_bc" "new_highlightbutton";;
external new_repeatbutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_repeatbutton_bc" "new_repeatbutton";;
external new_returnbutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_returnbutton_bc" "new_returnbutton";;
external new_togglebutton: string -> int -> int -> int -> int -> string -> widget = 
  "new_togglebutton_bc" "new_togglebutton";;
external button_value: widget -> bool = "button_value";;
external button_set_value: widget -> bool -> bool = "button_set_value";;

external set_callback: 'a -> string -> unit = "set_window_cb";;

external new_valuator: string -> int -> int -> int -> int -> string -> widget
    = "new_valuator_bc" "new_valuator"
external valuator_get_value: widget -> float = "valuator_get_value";;
external valuator_set_value: widget -> float -> unit = "valuator_set_value";;
external valuator_get_step: widget -> float = "valuator_get_step";;
external valuator_set_step: widget -> float -> unit = "valuator_set_step";;
external valuator_set_min: widget -> float -> unit = "valuator_set_min";;
external valuator_set_max: widget -> float -> unit = "valuator_set_max";;
external valuator_get_min: widget -> float = "valuator_get_min";;
external valuator_get_max: widget -> float = "valuator_get_max";;
external valuator_range: widget -> float -> float -> unit = "valuator_set_range";;

external new_slider: string -> int -> int -> int -> int -> string -> widget =
  "new_slider_bc" "new_slider";;

external slider_get_ticksize: widget -> int = "slider_get_ticksize";;
external slider_get_slidersize: widget -> int = "slider_get_slidersize";;
external slider_set_ticksize: widget -> int -> unit = "slider_set_ticksize";;
external slider_set_slidersize: widget -> int-> unit = "slider_set_slidersize";;

external new_valueinput: string -> int -> int -> int -> int -> string -> widget =
  "new_valueinput_bc" "new_valueinput";;

external new_valueoutput: string -> int -> int -> int -> int -> string -> widget =
  "new_valueoutput_bc" "new_valueoutput";;

(*

external new_intinput:string -> int -> int -> int -> int -> string -> widget =
    "new_intinput_bc" "new_intinput";;
external intinput_draw: widget -> unit = "intinput_draw";;
external set_numinput_ivalue: widget -> int -> unit = "numinput_set_ivalue";;
external set_numinput_fvalue: widget -> float -> unit ="numinput_set_fvalue";;
external floatinput_ivalue: widget -> int = "floatinput_ivalue";;
external floatinput_fvalue: widget -> float = "floatinput_fvalue";;
*)

external get_flags: widget -> int = "widget_get_flags";;
external set_flags: widget -> int -> unit = "widget_set_flags";;

let conf_label ?box ?font ?size ?typ w = ();;
(*
    let apply f v = match v with
      | None -> ()
      | Some x -> f w x
    in      
      apply widget_box box;
      apply set_labelfont font;
      apply set_labelsize size;
      apply labeltype typ
;;
*)

let or_flags start flag_list =
    List.fold_left (fun erg flag -> erg lor flag) start flag_list
;;


let null_widget : widget = Obj.magic 0;;

class virtual fltkbase x y w h title = object(self)
    val mutable obj = null_widget
    method obj = obj
    method ct = "base"
    method private virtual alloc
        : string -> int -> int -> int -> int -> string -> widget
    initializer
        let name = "obj" ^ (string_of_int (Oo.id self)) in
        Callback.register name self;
        print_endline ("allocating " ^ self#ct ^ " " ^ name);
        obj <- self#alloc name x y w h title
end;;

class fWidget x y w h title = object(self)
  inherit fltkbase x y w h title
  method private alloc = new_widget
  method ct = "widget"
  method set_flags (f:flags list) =
      printf "setting flags %d\n%!" (or_flags 0 f);
      let flags = or_flags (get_flags obj) f in
      set_flags obj flags

  method clr_flags (f:flags list) =
      printf "clearing flags %d\n%!" (or_flags 0 f);
      let flags = get_flags obj land (lnot (or_flags 0 f)) in
      set_flags obj flags

  method inv_flags (f: flags list) = 
      let flags = get_flags obj lxor (or_flags 0 f) in
      set_flags obj flags

  method is_set (f: flags) = get_flags obj land f
  method any_set (f: flags list) = get_flags obj land (or_flags 0 f) <> 0
  method all_set (f: flags list) =
      let flags = or_flags 0 f in
      get_flags obj land flags = flags
      
  method relayout = widget_relayout obj
  method draw = widget_draw obj
  method handle ev = widget_handle obj ev
  method redraw = redraw_widget obj
  method show = widget_show obj
  method hide = widget_hide obj
  method width = get_width obj
  method set_vertical = widget_set_vertical obj
  method set_horizontal = widget_set_horizontal obj
  method get_when = get_when obj
  method set_when n = set_when obj n
  method get_type = get_type obj
  method set_type n = set_type obj n
  method set_label l = set_label obj l
  method set_color c = set_color obj c
  method set_box b = widget_set_box obj b
  method as_widget = (self :> fWidget)
  (*method setfont font size = set_font font size
  method labelsize = get_labelsize obj
  method labelfont = get_labelfont obj*)
  method height = get_height obj
  (*method conf = conf_label*)
  method callback (fkt: unit->unit) = 
      let name = "widgetcb" ^ (string_of_int (Oo.id self)) in
      Callback.register name fkt;
      set_callback obj name

end;;

class fGroup ?(add=false) ?(x=0) ?(y=0) w h title = object(self)
    inherit fWidget x y w h title
    method private alloc = new_group
    method ct = "group"
    method wend = group_end obj
    method begin_add = group_begin obj
    method resizable: 'a. (< obj: widget; ..> as 'a) -> unit = 
        fun widget -> set_resizeable obj widget#obj
    initializer 
        if add = true then self#begin_add else self#wend
end;;


external new_statusbar: string -> int -> int -> int -> int -> string -> widget
    = "new_statusbar_bc" "new_statusbar";;

external new_easy_statusbar: string -> int -> widget = "new_easy_statusbar";;

type statusbar_pos = SBAR_LEFT | SBAR_CENTER | SBAR_RIGHT;;
external statusbar_set_text: widget -> statusbar_pos -> string -> unit =
            "statusbar_set_text";; 
external statusbar_child_box: widget -> Box.box -> statusbar_pos -> unit =
            "statusbar_child_box";;

type statusbar = Default | Height of int | Special of int*int*int*int*string

class f_StatusBar typ =
    let easy, x,y,w,h,l = match typ with
    | Special(x1,y1,w1,h1,l1) -> None, x1,y1,w1,h1,l1
    | Default -> Some(24), 0,0,0,0,""
    | Height(h) -> Some(h), 0,0,0,0,""
    in
    object 
    inherit fGroup ~x:x ~y:y w h l
    method child_box pos box = statusbar_child_box obj box pos
    method print ?(pos=SBAR_RIGHT) text = statusbar_set_text obj pos text
    method format_text : 'a. statusbar_pos -> ('a, unit,string, unit) format4 -> 'a =
        fun pos form -> Printf.ksprintf (statusbar_set_text obj pos) form
    method private alloc = match easy with
    | None -> new_statusbar
    | Some h -> (fun name _ _ _ _ _ -> new_easy_statusbar name h)
    method ct = "StatusBar"
end;;

class fStatusBar x y w h label = f_StatusBar (Special (x,y,w,h,label));;
class easyStatusBar = f_StatusBar Default;;
class easyNStatusBar n = f_StatusBar (Height n);;


external new_wizard_group: string -> int -> int -> int -> int -> string -> widget
    = "new_wizardgroup_bc" "new_wizardgroup";;

external wizard_next: widget -> unit = "wizard_next";;
external wizard_prev: widget -> unit = "wizard_prev";;

class fWizardGroup x y w h label = object
    inherit fGroup ~x:x ~y:y w h label
    method ct = "Wizard"
    method private alloc = new_wizard_group
    method next_page = wizard_next obj
    method prev_page = wizard_prev obj
end;;

external new_packedgroup: string -> int -> int -> int -> int -> string -> widget
    = "new_packedgroup_bc" "new_packedgroup";;
external new_bargroup: string -> int -> int -> int -> int -> string -> widget
    = "new_bargroup_bc" "new_bargroup";;
external packedgroup_get_spacing: widget -> int = "packedgroup_get_spacing";;
external packedgroup_set_spacing: widget -> int -> unit = "packedgroup_set_spacing";;
external bargroup_get_opened: widget -> bool = "bargroup_get_opened";;
external bargroup_set_opened: widget -> bool -> bool = "bargroup_set_opened";;
external bargroup_open: widget -> bool = "bargroup_open";;
external bargroup_close: widget -> bool = "bargroup_close";;


type packed_group_dir = Normal | AllVertical;;

class fPackedGroup x y w h label = object
    inherit fGroup ~x:x ~y:y w h label
    method ct = "PackedGroup"
    method private alloc = new_packedgroup
    method set_spacing n = packedgroup_set_spacing obj n
    method get_spacing = packedgroup_get_spacing obj
end;;

class fBarGroup x y w h label = object
    inherit fGroup ~x:x ~y:y w h label
    method ct = "BarGroup"
    method private alloc = new_bargroup
    method open_bar = bargroup_open obj
    method close_bar = bargroup_close obj
    method is_open = bargroup_get_opened obj
end;;

external new_tabgroup: string -> int -> int -> int -> int -> string -> widget
    = "new_tabgroup_bc" "new_tabgroup";;
external tabgroup_get_value: widget -> int = "tabgroup_get_value";;
external tabgroup_set_value: widget -> int -> bool = "tabgroup_set_value";;

class fTabGroup x y w h label = object
    inherit fGroup ~x:x ~y:y w h label
    method private alloc = new_tabgroup
    method set_value n = tabgroup_set_value obj n
    method get_value = tabgroup_get_value obj
end;;



type scrolltype = Horizontal | Vertical | Both | Always | HorizontalAlways
                | VerticalAlways | BothAlways;;

external new_scrollgroup: string -> int -> int -> int -> int -> string -> widget
    = "new_scrollgroup_bc" "new_scrollgroup";;
external scrollgroup_xpos: widget -> int = "scrollgroup_xpos";;
external scrollgroup_ypos: widget -> int = "scrollgroup_ypos";;
external scrollgroup_type: widget -> scrolltype -> unit = "scrollgroup_type";;
external scrollgroup_scroll_to: widget -> int -> int -> unit = "scrollgroup_scroll_to";;

class fScrollGroup x y w h label = object
    inherit fGroup ~x:x ~y:y w h label
    method scrolltype t = scrollgroup_type obj t
    method xpos = scrollgroup_xpos obj
    method ypos = scrollgroup_ypos obj
    method scroll_to x y = scrollgroup_scroll_to obj x y
end;;

class fWindow ?(add=true) ?(x=0) ?(y=0) w h title = object(self)
    inherit fGroup ~add ~x ~y w h title    
    method private alloc = new_window
    method ct = "window"
end;;

type button_typ = NormalButton | CheckButton | LightButton
    | RadioButton | HighlightButton | RepeatButton
    | ReturnButton | ToggleButton
;;

class fButton ?(btyp=NormalButton) x y w h title =
  let buttonname = match btyp with
    | NormalButton -> "button"
    | CheckButton -> "checkbutton"
    | LightButton -> "lightbutton"
    | RadioButton -> "radiobutton" 
    | HighlightButton -> "highlightbutton" 
    | RepeatButton -> "repeatbutton"
    | ReturnButton -> "returnbutton"
    | ToggleButton -> "togglebutton"
  in
  object(self)
  inherit fWidget x y w h title
  method ct =  buttonname
  method private alloc = match btyp with
    | NormalButton -> new_button
    | CheckButton -> new_checkbutton
    | LightButton -> new_lightbutton
    | RadioButton -> new_radiobutton
    | HighlightButton -> new_highlightbutton
    | RepeatButton -> new_repeatbutton
    | ReturnButton -> new_returnbutton
    | ToggleButton -> new_togglebutton

  method value = button_value obj
  method setValue n = button_set_value obj n  
end;;

external new_invisible: string -> int -> int -> int -> int -> string -> widget =
  "new_invisible_bc" "new_invisible";;

class fInvisible x y w h label = object
    inherit fWidget x y w h label
    method ct = "invisible box"
    method private alloc = new_invisible
end;;

let dummy_alloc obj x y w h name = null_widget;;

class fValuator x y w h label = object(self)
    inherit fWidget x y w h label
    method ct = "Valuator"
    method private alloc = dummy_alloc 
    method get_value = valuator_get_value obj
    method set_value v = valuator_set_value obj v
    method set_value_check v =
        if v >= self#get_min && v <= self#get_max then
            let t = (if v < 0.0 then ceil else floor) (v /. self#get_step) in
            let v = self#get_step *. t in
            self#set_value v
    method get_step = valuator_get_step obj
    method set_step v = valuator_set_step obj v
    method set_min v = valuator_set_min obj v
    method set_max v = valuator_set_max obj v
    method get_min = valuator_get_min obj
    method get_max = valuator_get_max obj
    method range a b = valuator_range obj a b
end;;


class fSlider x y w h label = object(self)
  inherit fValuator x y w h label
  method ct = "slider"                                    
  method private alloc = new_slider
  method tick_size = slider_get_ticksize obj
  method slider_size = slider_get_slidersize obj
  method set_ticksize n = slider_set_ticksize obj n
  method set_slidersize n = slider_set_slidersize obj n
end;;

class fValueInput x y w h label = object
    inherit fValuator x y w h label
    method ct = "valueinput"
    method private alloc = new_valueinput
end;;

class fValueOutput x y w h label = object
    inherit fValuator x y w h label
    method ct = "valueoutput"
    method private alloc = new_valueoutput
end;;

external new_intinput: string -> int -> int -> int -> int -> string -> widget
    = "new_intinput_bc" "new_intinput";;


external new_floatinput: string -> int -> int -> int -> int -> string -> widget
    = "new_floatinput_bc" "new_floatinput";;

external set_value_f: widget -> float -> unit = "numinput_set_valued";;
external set_value_i: widget -> int -> unit = "numinput_set_valuei";;
external get_value_f: widget -> float = "floatinput_get_valued";;
external get_value_i: widget -> int = "floatinput_get_valuei";;
external input_get_text: widget -> string = "input_get_text";;
external input_set_text: widget -> string -> bool = "input_set_text";;


class fInput x y w h label = object(self)
    inherit fWidget x y w h label
    method private alloc = dummy_alloc
    method set_text txt = input_set_text obj txt
    method get_text = input_get_text obj
end;;

class fNumInput x y w h label = object(self)
    inherit fInput x y w h label
    method private alloc = dummy_alloc
    method set_int v = set_value_i obj v
    method set_float v = set_value_f obj v
end;;

class fFloatInput x y w h label = object
    inherit fNumInput x y w h label
    method private alloc = new_floatinput
    method get_int = get_value_i obj
    method get_float = get_value_f obj
end;;

class fIntInput x y w h label = object
    inherit fFloatInput x y w h label
    method private alloc = new_intinput
end;;



external new_output: string -> int -> int -> int -> int -> string -> widget
    = "new_output_bc" "new_output";;

external new_multiline: string -> int -> int -> int -> int -> string -> widget
    = "new_multiline_bc" "new_multiline";;

external new_wordwrap: string -> int -> int -> int -> int -> string -> widget
    = "new_wordwrap_bc" "new_wordwrap";;


type output_type = NormalOutput | MultiLine | WordWrap

class fOutput ?(otype = NormalOutput) x y w h label =
    let output_name = match otype with
    | NormalOutput -> "normaloutput"
    | MultiLine -> "multiline"
    | WordWrap -> "wordwrap"
    in
    object
        inherit fInput x y w h label
        method ct = output_name
        method private alloc = match otype with
        | NormalOutput -> new_output
        | MultiLine -> new_multiline        
        | WordWrap -> new_wordwrap
    end;;

