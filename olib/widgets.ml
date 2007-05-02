open Printf;;
open Flags;;
type widget_ptr;;

type 'a image = 'a Symbol.sym constraint 'a = [>Symbol.symbol]
type symbol = Symbol.symbol Symbol.sym;;

type when_enum = WhenNever | WhenChanged | WhenRelease | WhenReleaseAlways
               | WhenEnterKey | WhenEnterKeyAlways
;;

external int_of_when: when_enum -> int = "%identity";;

let when2int flag =
    let tab = [| 0; 1; 4; 6; 8; 10 |] in
    tab.(int_of_when flag)
;;

let rec flags_of_bits flags bits res =
    match flags with
    | [] -> res
    | (value, name) :: rest ->
            if bits land value = value then
                flags_of_bits rest (bits - value) (name :: res)
            else
                flags_of_bits rest bits res
;;

external redraw : unit -> unit = "fltk_redraw";;
external new_widget: string -> int -> int -> int -> int -> string -> widget_ptr
= "s_new_widget_bc" "s_new_widget";;
external widget_draw: widget_ptr -> unit = "s_widget_draw";;
external widget_handle: widget_ptr -> Event.event_type -> Event.event_type = "s_widget_handle";;
external get_flags: widget_ptr -> int = "widget_get_flags";;
external set_flags: widget_ptr -> int -> unit = "widget_set_flags";;
external widget_show: widget_ptr -> unit = "s_widget_show";;
external widget_hide: widget_ptr-> unit = "widget_hide";;
external widget_active: widget_ptr-> bool = "widget_active";;
external widget_activate: widget_ptr-> unit = "widget_activate";;
external widget_deactivate: widget_ptr-> unit = "widget_deactivate";;
external widget_draw_box: widget_ptr-> unit = "widget_draw_box";;
external widget_scrollbar_align: widget_ptr -> Flags.flags -> unit = "widget_scrollbar_align";;
external widget_scrollbar_width: widget_ptr -> int -> unit =
    "widget_scrollbar_width";;
external get_width: widget_ptr-> int = "get_width";;
external get_height: widget_ptr-> int = "get_height";;
external get_x: widget_ptr-> int = "get_x";;
external get_y: widget_ptr-> int = "get_y";;
external widget_resize: widget_ptr -> (int*int) option -> int -> int -> bool = "s_widget_resize";;
external get_when: widget_ptr-> int = "widget_get_when";;
external set_when: widget_ptr-> int -> unit = "widget_set_when";;
external get_type: widget_ptr-> int = "widget_get_type";;
external set_type: widget_ptr-> int -> unit = "widget_set_type";;
external set_label: widget_ptr-> string -> unit = "widget_set_label";;
external set_labelcolor: widget_ptr-> int32 -> unit = "widget_set_labelcolor";;
external set_color: widget_ptr-> int32 -> unit = "widget_set_color";;
external redraw_widget: widget_ptr -> unit = "s_redraw_widget";;
external set_callback: widget_ptr -> string -> unit = "s_set_widget_cb";;
external widget_label: widget_ptr-> string = "widget_label";;
external get_labelfont: widget_ptr -> Font.font = "s_widget_get_labelfont";;
external get_labelsize: widget_ptr -> float = "s_widget_get_labelsize";;
external set_labelsize: widget_ptr -> float -> unit = "s_widget_get_labelsize";;
external widget_set_box: widget_ptr-> 'a image -> unit = "widget_set_box";;
external widget_get_box: widget_ptr-> symbol = "widget_get_box";;
external widget_get_image: widget_ptr-> symbol = "widget_get_image";;
external widget_set_image: widget_ptr-> 'a image -> unit = "widget_set_image";;

external widget_relayout: widget_ptr-> unit = "widget_relayout";;
external widget_draw: widget_ptr-> unit = "widget_draw";;
external widget_damage: widget_ptr-> int = "widget_damage";;
external widget_set_vertical: widget_ptr-> unit = "widget_set_vertical";;
external widget_set_tooltip : widget_ptr-> string -> unit = "widget_set_tooltip";;
external widget_get_tooltip : widget_ptr-> string = "widget_get_tooltip";;
external widget_set_horizontal: widget_ptr-> unit = "widget_set_horizontal";;
external widget_handle: widget_ptr-> Event.event_type -> Event.event_type = "widget_handle";;
external widget_set_labelfont: widget_ptr -> Font.font -> unit = "widget_get_labelfont";;
external widget_align: widget_ptr -> Flags.flags -> unit = "widget_align";;


external new_button: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_button_bc" "new_button";;
external button_draw: widget_ptr -> unit = "button_draw";;
external button_handle: widget_ptr -> Event.event_type -> Event.event_type = "button_handle";;

external button_value: widget_ptr -> bool = "button_value";;
external button_set_value: widget_ptr -> bool -> bool = "button_set_value";;

external new_group: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_group_bc" "new_group";;
external group_begin: widget_ptr -> unit = "group_begin"
(*external addw: widget_ptr -> 'a -> unit = "group_add"*)
external group_end: widget_ptr -> unit = "group_end"
external group_draw: widget_ptr -> unit = "group_draw";;
external group_handle: widget_ptr -> Event.event_type -> Event.event_type = "group_handle";;
external group_children: widget_ptr -> int = "group_children";;
external group_get_child: widget_ptr -> int -> widget_ptr = "group_get_child";;
external group_insert: widget_ptr -> widget_ptr -> int -> unit = "group_insert";;
external group_insert_before: widget_ptr -> widget_ptr -> widget_ptr -> unit = "group_insert_before";;

(*let null_widget : widget_ptr = Obj.magic 0;;*)
external get_null_widget: unit -> widget_ptr = "get_null_widget";;
let null_widget = get_null_widget();;

module PtrHash = Hashtbl.Make(struct 
    type t = widget_ptr
    let equal = (==)
    let hash = Hashtbl.hash end);; 

let ptr_tbl = PtrHash.create 257;;

module GroupHash = Hashtbl.Make(struct 
    type t = widget_ptr
    let equal = (==)
    let hash = Hashtbl.hash end);; 

let grp_tbl = GroupHash.create 257;;

class virtual fltkbase x y w h title = object(self : 'a)
    val mutable obj = null_widget
    method obj = obj
    method ct = "base"
    method private virtual alloc
        : string -> int -> int -> int -> int -> string -> widget_ptr
    initializer
        let name = "obj" ^ (string_of_int (Oo.id self)) in
        Callback.register name self;
        obj <- self#alloc name x y w h title
end;;

let or_flags start flag_list =
    List.fold_left (fun erg flag -> erg lor flag) start flag_list
;;

class widget x y w h title = object(self)
  inherit fltkbase x y w h title
  val mutable cb_name = ""
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
  method draw_box = widget_draw_box obj
  method show = widget_show obj
  method align = widget_align obj
  method scrollbar_align = widget_scrollbar_align obj
  method scrollbar_width = widget_scrollbar_width obj
  method hide = widget_hide obj
  method active = widget_active obj
  method activate = widget_activate obj
  method deactivate = widget_deactivate obj
  method w = get_width obj
  method h = get_height obj
  method x = get_x obj
  method y = get_y obj
  method resize ?xy w h = widget_resize obj xy w h
  method set_vertical = widget_set_vertical obj
  method set_horizontal = widget_set_horizontal obj
  method get_when =
      let f = flags_of_bits [
          (10, WhenEnterKeyAlways);
          (8, WhenEnterKey);
          (6, WhenReleaseAlways);
          (4, WhenRelease);
          (1, WhenChanged) ] (get_when obj) []
      in
      if f = [] then [WhenNever] else f

  method set_when flags =
      let n = List.fold_left (fun erg flag -> erg lor (when2int flag)) 0 flags in
      set_when obj n
  method get_type = get_type obj
  method set_type n = set_type obj n
  method set_label l = set_label obj l
  method set_labelcolor l = set_labelcolor obj l
  method set_color c = set_color obj c
  method set_tooltip t = widget_set_tooltip obj t
  method get_tooltip = widget_get_tooltip obj
  method set_box : 'a. 'a image -> unit =
      fun box -> widget_set_box obj box
  method get_box = widget_get_box obj
  method get_image = widget_get_image obj
  method set_image : 'a. 'a image -> unit =
      fun box -> widget_set_image obj box
  method as_widget = (self :> widget)
(*  method setfont font size = set_font font size*)
  method labelsize = get_labelsize obj
  method label = widget_label obj
  method labelfont = get_labelfont obj
  method set_labelsize size = set_labelsize obj size
  method set_labelfont font = widget_set_labelfont obj font
  (*method conf = conf_label*)
  method callback (fkt: unit->unit) = 
      Callback.register cb_name fkt;
      set_callback obj cb_name
    initializer
        cb_name <- "widgetcb" ^ (string_of_int (Oo.id self));
        PtrHash.add ptr_tbl obj (self :> widget)
end;;

class widgetProxy ptr = object(self)
  inherit widget 0 0 0 0 ""
  method private alloc = (fun _ _ _ _ _ _ -> ptr) 
  method ct = "widgetProxy"
end;;

external new_invisible: 'a image option -> string -> int -> int -> int -> int -> string -> widget_ptr =
  "new_invisible_bc" "new_invisible";;
external invisible_draw: widget_ptr -> unit = "invisible_draw";;
external invisible_handle: widget_ptr -> Event.event_type -> Event.event_type =
    "invisible_handle";;

class invisible ?box x y w h label = object
    inherit widget x y w h label
    method ct = "invisible box"
    method private alloc = new_invisible box
    method draw = invisible_draw obj
    method handle ev = invisible_handle obj ev
end;;

class button x y w h title =
  object(self)
  inherit widget x y w h title
  method ct =  "button"
  method private alloc = new_button
  method draw = button_draw obj
  method handle ev = button_handle obj ev
  method value = button_value obj
  method setValue n = button_set_value obj n  
  method default_style = Style.buttonDefaultStyle
end;;

external new_checkbutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_CheckButton_bc" "new_CheckButton";;
external checkbutton_draw: widget_ptr -> unit = "checkbutton_draw";;
external checkbutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "checkbutton_handle";;

external new_lightbutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_LightButton_bc" "new_LightButton";;
external lightbutton_draw: widget_ptr -> unit = "lightbutton_draw";;
external lightbutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "lightbutton_handle";;

external new_radiobutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_RadioButton_bc" "new_RadioButton";;
external radiobutton_draw: widget_ptr -> unit = "radiobutton_draw";;
external radiobutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "radiobutton_handle";;

external new_highlightbutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_HighlightButton_bc" "new_HighlightButton";;
external highlightbutton_draw: widget_ptr -> unit = "highlightbutton_draw";;
external highlightbutton_handle: widget_ptr -> Event.event_type ->
    Event.event_type = "highlightbutton_handle";;

external new_repeatbutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_RepeatButton_bc" "new_RepeatButton";;
external repeatbutton_draw: widget_ptr -> unit = "repeatbutton_draw";;
external repeatbutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "repeatbutton_handle";;

external new_returnbutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_ReturnButton_bc" "new_ReturnButton";;
external returnbutton_draw: widget_ptr -> unit = "returnbutton_draw";;
external returnbutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "returnbutton_handle";;

external new_togglebutton: string -> int -> int -> int -> int -> string -> widget_ptr = 
  "new_ToggleButton_bc" "new_ToggleButton";;
external togglebutton_draw: widget_ptr -> unit = "togglebutton_draw";;
external togglebutton_handle: widget_ptr -> Event.event_type -> Event.event_type
= "togglebutton_handle";;

class checkButton x y w h title = object
    inherit button x y w h title
    method ct = "CheckButton"
    method private alloc = new_checkbutton
    method draw = checkbutton_draw obj
    method handle ev = checkbutton_handle obj ev
end;;

class lightButton x y w h title = object
    inherit button x y w h title
    method ct = "LightButton"
    method private alloc = new_lightbutton
    method draw = lightbutton_draw obj
    method handle ev = lightbutton_handle obj ev
end;;

class radioButton x y w h title = object
    inherit button x y w h title
    method ct = "RadioButton"
    method private alloc = new_radiobutton
    method draw = radiobutton_draw obj
    method handle ev = radiobutton_handle obj ev
end;;

class highlightButton x y w h title = object
    inherit button x y w h title
    method ct = "HighlightButton"
    method private alloc = new_highlightbutton
    method draw = highlightbutton_draw obj
    method handle ev = highlightbutton_handle obj ev
end;;

class repeatButton x y w h title = object
    inherit button x y w h title
    method ct = "RepeatButton"
    method private alloc = new_repeatbutton
    method draw = repeatbutton_draw obj
    method handle ev = repeatbutton_handle obj ev
end;;

class returnButton x y w h title = object
    inherit button x y w h title
    method ct = "ReturnButton"
    method private alloc = new_returnbutton
    method draw = returnbutton_draw obj
    method handle ev = returnbutton_handle obj ev
end;;

class toggleButton x y w h title = object
    inherit button x y w h title
    method ct = "ToggleButton"
    method private alloc = new_togglebutton
    method draw = togglebutton_draw obj
    method handle ev = togglebutton_handle obj ev
end;;

external new_input: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_Input_bc" "new_Input";;
external new_numinput: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_NumericInput_bc" "new_NumericInput";;
external new_intinput: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_intinput_bc" "new_intinput";;
external new_floatinput: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_floatinput_bc" "new_floatinput";;

external set_value_f: widget_ptr -> float -> unit = "numinput_set_valued";;
external set_value_i: widget_ptr -> int -> unit = "numinput_set_valuei";;
external get_value_f: widget_ptr -> float = "floatinput_get_valued";;
external get_value_i: widget_ptr -> int = "floatinput_get_valuei";;
external input_get_text: widget_ptr -> string = "input_get_text";;
external input_set_text: widget_ptr -> string -> bool = "input_set_text";;

external input_draw: widget_ptr -> unit = "input_draw";;
external input_handle: widget_ptr -> Event.event_type -> Event.event_type = "input_handle";;
external numInput_draw: widget_ptr -> unit = "numInput_draw";;
external numInput_handle: widget_ptr -> Event.event_type -> Event.event_type = "numInput_handle";;
external floatInput_draw: widget_ptr -> unit = "floatInput_draw";;
external floatInput_handle: widget_ptr -> Event.event_type -> Event.event_type = "floatInput_handle";;
external intInput_draw: widget_ptr -> unit = "intInput_draw";;
external intInput_handle: widget_ptr -> Event.event_type -> Event.event_type = "intInput_handle";;

class input x y w h label = object(self)
    inherit widget x y w h label
    method private alloc = new_input
    method draw = input_draw obj
    method handle ev = input_handle obj ev
    method set_text txt = input_set_text obj txt
    method get_text = input_get_text obj
end;;


class numInput x y w h label = object(self)
    inherit input x y w h label
    method private alloc = new_numinput
    method draw = numInput_draw obj
    method handle ev = numInput_handle obj ev
    method set_int v = set_value_i obj v
    method set_float v = set_value_f obj v
end;;

class floatInput x y w h label = object
    inherit numInput x y w h label
    method private alloc = new_floatinput
    method draw = floatInput_draw obj
    method handle ev = floatInput_handle obj ev
    method get_int = get_value_i obj
    method get_float = get_value_f obj
end;;

class floatInputProxy obj = object
    inherit floatInput 0 0 0 0 ""
    method private alloc = (fun _ _ _ _ _ _ -> obj)
    method ct = "floatInputProxy"
end;;


class intInput x y w h label = object
    inherit floatInput x y w h label
    method private alloc = new_intinput
    method draw = intInput_draw obj
    method handle ev = intInput_handle obj ev
end;;

external new_output: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_Output_bc" "new_Output";;
external output_draw: widget_ptr -> unit = "output_draw";;
external output_handle: widget_ptr -> Event.event_type -> Event.event_type = "output_handle";;

external new_multiline: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_MultiLineOutput_bc" "new_MultiLineOutput";;
external multiline_draw: widget_ptr -> unit = "multiline_draw";;
external multiline_handle: widget_ptr -> Event.event_type -> Event.event_type = "multiline_handle";;

external new_wordwrap: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_WordwrapOutput_bc" "new_WordwrapOutput";;
external wordwrap_draw: widget_ptr -> unit = "wordwrap_draw";;
external wordwrap_handle: widget_ptr -> Event.event_type -> Event.event_type = "wordwrap_handle";;

class output x y w h label =
    object
    inherit input x y w h label
    method ct = "normaloutput"
    method private alloc = new_output
    method draw = output_draw obj
    method handle ev = output_handle obj ev
    end;;

class multiLineOutput x y w h label =
    object
    inherit input x y w h label
    method ct = "multiline"
    method private alloc = new_multiline
    method draw = multiline_draw obj
    method handle ev = multiline_handle obj ev
    end;;

class wordwrapOutput x y w h label =
    object
    inherit input x y w h label
    method ct = "wordwrap"
    method private alloc = new_wordwrap
    method draw = wordwrap_draw obj
    method handle ev = wordwrap_handle obj ev
    end;;


let dummy_alloc obj x y w h name = null_widget;;

external new_valuator: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_valuator_bc" "new_valuator"
external valuator_draw: widget_ptr -> unit = "valuator_draw";;
external valuator_handle: widget_ptr -> Event.event_type -> Event.event_type = "valuator_handle";;
external valuator_get_value: widget_ptr -> float = "valuator_get_value";;
external valuator_set_value: widget_ptr -> float -> unit = "valuator_set_value";;
external valuator_get_step: widget_ptr -> float = "valuator_get_step";;
external valuator_set_step: widget_ptr -> float -> unit = "valuator_set_step";;
external valuator_set_min: widget_ptr -> float -> unit = "valuator_set_min";;
external valuator_set_max: widget_ptr -> float -> unit = "valuator_set_max";;
external valuator_get_min: widget_ptr -> float = "valuator_get_min";;
external valuator_get_max: widget_ptr -> float = "valuator_get_max";;
external valuator_range: widget_ptr -> float -> float -> unit = "valuator_set_range";;

class valuator x y w h label = object(self)
    inherit widget x y w h label
    method ct = "Valuator"
    method private alloc = dummy_alloc 
    method draw = valuator_draw obj
    method handle ev = valuator_handle obj ev
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

module Slider = struct
let tick_above = 2
let tick_left = tick_above;;
let tick_below = 4;;
let tick_right = tick_below;;
let tick_both = tick_above lor tick_below
end;;

external new_slider: string -> int -> int -> int -> int -> string -> widget_ptr =
  "new_slider_bc" "new_slider";;

external slider_draw: widget_ptr -> unit = "slider_draw";;
external slider_handle: widget_ptr -> Event.event_type -> Event.event_type = "slider_handle";;
external slider_get_ticksize: widget_ptr -> int = "slider_get_ticksize";;
external slider_get_slidersize: widget_ptr -> int = "slider_get_slidersize";;
external slider_set_ticksize: widget_ptr -> int -> unit = "slider_set_ticksize";;
external slider_set_slidersize: widget_ptr -> int-> unit = "slider_set_slidersize";;

class slider x y w h label = object(self)
  inherit valuator x y w h label
  method ct = "slider"                                    
  method private alloc = new_slider
  method draw  = slider_draw obj
  method handle ev = slider_handle obj ev
  method tick_size = slider_get_ticksize obj
  method slider_size = slider_get_slidersize obj
  method set_ticksize n = slider_set_ticksize obj n
  method set_slidersize n = slider_set_slidersize obj n
end;;

external new_value_slider: string -> int -> int -> int -> int -> string -> widget_ptr=
    "new_valueslider_bc" "new_valueslider";;
external valueslider_input_widget: widget_ptr -> widget_ptr = "valueslider_get_input";;
external valueslider_draw: widget_ptr -> unit = "valueslider_draw";;
external valueslider_handle: widget_ptr -> Event.event_type -> Event.event_type
= "valueslider_handle";;

class valueSlider x y w h label = object(self)
  inherit slider x y w h label
  method draw  = valueslider_draw obj
  method handle ev = valueslider_handle obj ev

(*    val mutable input = new fFloatInput 0 0 0 0 ""*)
  val mutable input = None
  method input = match input with
        | Some i -> i
        | None ->
                let i =(new floatInputProxy (valueslider_input_widget obj) :> floatInput) in
                input <- Some i;
                i
  method ct = "ValueSlider"
  method private alloc = new_value_slider
end;;

external new_valueInput: string -> int -> int -> int -> int -> string -> widget_ptr =
  "new_valueinput_bc" "new_valueinput";;
external valueInput_draw: widget_ptr -> unit = "valueinput_draw";;
external valueInput_handle: widget_ptr -> Event.event_type -> Event.event_type = "valueinput_handle";;

class valueInput x y w h label = object
    inherit valuator x y w h label
    method ct = "valueinput"
    method private alloc = new_valueInput
    method draw  = valueInput_draw obj
    method handle ev = valueInput_handle obj ev
end;;

external new_valueOutput: string -> int -> int -> int -> int -> string -> widget_ptr =
  "new_valueoutput_bc" "new_valueoutput";;
external valueOutput_draw: widget_ptr -> unit = "valueoutput_draw";;
external valueOutput_handle: widget_ptr -> Event.event_type -> Event.event_type = "valueoutput_handle";;

class valueOutput x y w h label = object
    inherit valuator x y w h label
    method ct = "valueoutput"
    method private alloc = new_valueOutput
    method draw  = valueOutput_draw obj
    method handle ev = valueOutput_handle obj ev
end;;

external group_set_resizeable : widget_ptr -> widget_ptr -> unit = "group_set_resizable";;
external group_get_resizable: widget_ptr -> widget_ptr = "group_get_resizable";;
external group_add: widget_ptr -> widget_ptr -> unit = "group_add";;
external group_clear: widget_ptr -> unit = "group_clear";;
external group_init_sizes: widget_ptr -> unit = "group_init_sizes";;
external group_set_focuswidget: widget_ptr -> widget_ptr -> unit = "group_set_focuswidget";;
external group_set_focusindex: widget_ptr -> int -> unit = "group_set_focusindex";;
external group_get_focus: widget_ptr -> int = "group_get_focus";;
external group_find: widget_ptr -> widget_ptr -> int = "group_find";;
external group_remove: widget_ptr -> int -> unit = "group_remove";;
external group_remove_widget: widget_ptr -> widget_ptr -> unit = "group_remove_widget";;
external group_replace: widget_ptr -> int -> widget_ptr -> unit = "group_replace";;
external group_replace_with: widget_ptr -> widget_ptr -> widget_ptr -> unit = "group_replace_with";;
external group_current: unit -> widget_ptr = "group_get_current";;
external group_set_current: widget_ptr -> unit = "group_set_current";;



class group ?(add=false) ?(x=0) ?(y=0) w h title = object(self)
    inherit widget x y w h title
    method private alloc = new_group
    method ct = "group"
    method draw = group_draw obj
    method handle ev = group_handle obj ev
    method wend = group_end obj
    method begin_add = group_begin obj
    method clear = group_clear obj
    method init_sizes = group_init_sizes obj
    method setFocusWidget: 'a. (#widget as 'a) -> unit = 
        fun widget -> group_set_focuswidget obj widget#obj
    method setFocus i = group_set_focusindex obj i
    method focus = group_get_focus obj
    method find: 'a. (#widget as 'a) -> int = 
        fun widget -> group_find obj widget#obj
    method get_resizable =
    	let w = group_get_resizable obj in
        try
            PtrHash.find ptr_tbl w
        with Not_found -> (new widgetProxy w :> widget)

    method resizable: 'a. (#widget as 'a) -> unit = 
        fun widget -> group_set_resizeable obj widget#obj
    method add: 'a. (#widget as 'a) -> unit =
        fun widget -> group_add obj widget#obj
    method add_resizable: 'a. (#widget as 'a) -> unit =
        fun widget -> 
		self#add widget;
		self#resizable widget
    method remove_widget: 'a. (#widget as 'a) -> unit =
        fun widget -> group_remove_widget obj widget#obj
    method remove idx = group_remove obj idx
    method replace: 'a. int -> (#widget as 'a) -> unit =
        fun idx widget -> group_replace obj idx widget#obj
    method replace_with: 'a 'b.  (#widget as 'a) -> (#widget as 'b) -> unit =
        fun old replacement -> group_replace_with obj old#obj replacement#obj
    method insert: 'a. (#widget as 'a) -> int -> unit =
        fun widget idx -> group_insert obj widget#obj idx 
    method insert_before: 'a 'b.  (#widget as 'a) -> (#widget as 'b) option -> unit =
        fun widget before -> match before with
        | None ->   group_insert_before obj widget#obj null_widget 
        | Some w -> group_insert_before obj widget#obj w#obj
    method children = group_children obj
    method child n =
        let c = group_get_child obj n in
        try
            PtrHash.find ptr_tbl c
        with Not_found -> (new widgetProxy c :> widget)

    method iter_childs (f : widget -> unit) =
        for i=0 to self#children - 1 do
            f (self#child i)
        done

    method fold_childs: 'a.  (('a -> widget -> 'a) -> 'a -> 'a) =
        fun f start -> 
        let e = ref start in
        self#iter_childs (fun w -> e := f !e w);
        !e
    initializer 
        if add = true then self#begin_add else self#wend;
	print_endline "group init";
	GroupHash.add grp_tbl obj (self :> group)		

end;;

class groupProxy ptr = object(self)
	inherit group 0 0 ""
	method private alloc = fun _ _ _ _ _ _ -> ptr
	initializer
		print_endline "groupProxy init"
		(*GroupHash.add grp_tbl ptr (self :> group) *)
end;;

let groupGetCurrent () =
	let g = group_current () in
    if g == null_widget then None
    else Some (
    	try
	        GroupHash.find grp_tbl g
    	with
	    	Not_found -> (new groupProxy g :> group))
;;		

let groupSetCurrent (group : #group option) =
	match group with
	| None -> group_set_current null_widget
	| Some g -> group_set_current g#obj
;;

external new_wizard_group: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_WizardGroup_bc" "new_WizardGroup";;

external wizard_next: widget_ptr -> unit = "wizard_next";;
external wizard_prev: widget_ptr -> unit = "wizard_prev";;
external wizard_draw: widget_ptr -> unit = "wizard_draw";;
external wizard_handle: widget_ptr -> Event.event_type -> Event.event_type = "wizard_handle";;

class wizardGroup x y w h label = object
    inherit group ~x:x ~y:y w h label
    method ct = "Wizard"
    method private alloc = new_wizard_group
    method draw = wizard_draw obj
    method handle ev = wizard_handle obj ev
    method next_page = wizard_next obj
    method prev_page = wizard_prev obj
end;;

external new_packedgroup: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_PackedGroup_bc" "new_PackedGroup";;
external packedgroup_get_spacing: widget_ptr -> int = "packedgroup_get_spacing";;
external packedgroup_set_spacing: widget_ptr -> int -> unit = "packedgroup_set_spacing";;
external packedgroup_draw: widget_ptr -> unit = "packedgroup_draw";;
external packedgroup_handle: widget_ptr -> Event.event_type -> Event.event_type = "packedgroup_handle";;

type packed_group_dir = Normal | AllVertical;;

class packedGroup x y w h label = object
    inherit group ~x:x ~y:y w h label
    method ct = "PackedGroup"
    method draw = packedgroup_draw obj
    method handle ev = packedgroup_handle obj ev
    method private alloc = new_packedgroup
    method set_spacing n = packedgroup_set_spacing obj n
    method get_spacing = packedgroup_get_spacing obj
end;;


external new_bargroup: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_BarGroup_bc" "new_BarGroup";;
external bargroup_get_opened: widget_ptr -> bool = "bargroup_get_opened";;
external bargroup_set_opened: widget_ptr -> bool -> bool = "bargroup_set_opened";;
external bargroup_open: widget_ptr -> bool = "bargroup_open";;
external bargroup_close: widget_ptr -> bool = "bargroup_close";;
external bargroup_draw: widget_ptr -> unit = "bargroup_draw";;
external bargroup_handle: widget_ptr -> Event.event_type -> Event.event_type = "bargroup_handle";;

class barGroup x y w h label = object
    inherit group ~x:x ~y:y w h label
    method ct = "BarGroup"
    method private alloc = new_bargroup
    method draw = bargroup_draw obj
    method handle ev = bargroup_handle obj ev
    method open_bar = bargroup_open obj
    method close_bar = bargroup_close obj
    method is_open = bargroup_get_opened obj
end;;

external new_tabgroup: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_TabGroup_bc" "new_TabGroup";;
external tabgroup_draw: widget_ptr -> unit = "tabgroup_draw";;
external tabgroup_handle: widget_ptr -> Event.event_type -> Event.event_type = "tabgroup_handle";;
external tabgroup_get_value: widget_ptr -> int = "tabgroup_get_value";;
external tabgroup_set_value: widget_ptr -> int -> bool = "tabgroup_set_value";;

class tabGroup x y w h label = object
    inherit group ~x:x ~y:y w h label
    method private alloc = new_tabgroup
    method draw = tabgroup_draw obj
    method handle ev = tabgroup_handle obj ev
    method ct = "TabGroup"
    method set_value n = tabgroup_set_value obj n
    method get_value = tabgroup_get_value obj
end;;

type scrolltype = NoScroll | Horizontal | Vertical | Both | Always | HorizontalAlways
                | VerticalAlways | BothAlways;;

external new_scrollgroup: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_ScrollGroup_bc" "new_ScrollGroup";;
external scrollgroup_draw: widget_ptr -> unit = "scrollgroup_draw";;
external scrollgroup_handle: widget_ptr -> Event.event_type -> Event.event_type = "scrollgroup_handle";;
external scrollgroup_xpos: widget_ptr -> int = "scrollgroup_xpos";;
external scrollgroup_ypos: widget_ptr -> int = "scrollgroup_ypos";;
external scrollgroup_type: widget_ptr -> scrolltype -> unit = "scrollgroup_type";;
external scrollgroup_set_position: widget_ptr -> int -> int -> unit = "scrollgroup_set_position";; 
external scrollgroup_scroll_to: widget_ptr -> int -> int -> unit = "scrollgroup_scroll_to";;

class scrollGroup x y w h label = object
    inherit group ~x:x ~y:y w h label
    method ct = "ScrollGroup"
    method private alloc = new_scrollgroup
    method draw = scrollgroup_draw obj
    method handle ev = scrollgroup_handle obj ev
    method scrolltype t = scrollgroup_type obj t
    method xpos = scrollgroup_xpos obj
    method ypos = scrollgroup_ypos obj
    method position x y = scrollgroup_set_position obj x y
    method scroll_to x y = scrollgroup_scroll_to obj x y
end;;

external new_menu: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_Menu_bc" "new_Menu";;
external menu_draw: widget_ptr -> unit = "menu_draw";;
external menu_handle: widget_ptr -> Event.event_type -> Event.event_type = "menu_handle";;
external menu_children: widget_ptr -> int = "menu_children";;
external menu_value: widget_ptr -> int = "menu_value";;
external menu_set_value: widget_ptr -> int -> unit = "menu_set_value";;

class menu x y w h label = object
    inherit group ~x:x ~y:y w h label
    method ct = "Menu"
    method private alloc = new_menu
    method draw = menu_draw obj
    method handle ev = menu_handle obj ev
    (*method children = menu_children obj*)
    method value = menu_value obj
    method set_value = menu_set_value obj
end;;

external new_choice: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_Choice_bc" "new_Choice";;
external choice_draw: widget_ptr -> unit = "choice_draw";;
external choice_handle: widget_ptr -> Event.event_type -> Event.event_type = "choice_handle";;


class choice x y w h label = object
    inherit menu x y w h label
    method ct = "Choice"
    method private alloc = new_choice
    method draw = choice_draw obj
    method handle ev = choice_handle obj ev
end;;


external new_cyclebutton: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_CycleButton_bc" "new_CycleButton";;
external cyclebutton_draw: widget_ptr -> unit = "cyclebutton_draw";;
external cyclebutton_handle: widget_ptr -> Event.event_type -> Event.event_type = "cyclebutton_handle";;


class cycleButton x y w h label = object
    inherit menu x y w h label
    method ct = "cycleButton"
    method private alloc = new_cyclebutton
    method draw = cyclebutton_draw obj
    method handle ev = cyclebutton_handle obj ev
end;;


external new_popup: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_PopupMenu_bc" "new_PopupMenu";;
external popup_draw: widget_ptr -> unit = "popup_draw";;
external popup_handle: widget_ptr -> Event.event_type -> Event.event_type = "popup_handle";;


class popupMenu x y w h label = object
    inherit menu x y w h label
    method ct = "popup"
    method private alloc = new_popup
    method draw = popup_draw obj
    method handle ev = popup_handle obj ev
end;;

external new_menubar: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_MenuBar_bc" "new_MenuBar";;
external menubar_draw: widget_ptr -> unit = "menubar_draw";;
external menubar_handle: widget_ptr -> Event.event_type -> Event.event_type = "menubar_handle";;

class menuBar x y w h label = object
    inherit menu x y w h label
    method ct = "MenuBar"
    method private alloc = new_menubar
    method draw = menubar_draw obj
    method handle ev = menubar_handle obj ev
end;;

external new_item: string -> string -> 'a image option -> widget_ptr = "new_Item";;
external item_draw: widget_ptr -> unit = "item_draw";;
external item_handle: widget_ptr -> Event.event_type -> Event.event_type = "item_handle";;

class item ?symbol menuitem = object
    inherit widget 0 0 0 0 ""
    method ct = "Item"
    method private alloc = fun objcb _ _ _ _ _ -> new_item objcb menuitem symbol
    method draw = item_draw obj
    method handle ev = item_handle obj ev
end;;

external new_itemgroup: string -> string -> widget_ptr = "new_ItemGroup";;
external itemgroup_draw: widget_ptr -> unit = "itemgroup_draw";;
external itemgroup_handle: widget_ptr -> Event.event_type -> Event.event_type = "itemgroup_handle";;

class itemGroup item = object
    inherit menu 0 0 0 0 ""
    method ct = "ItemGroup"
    method private alloc = fun objcb _ _ _ _ _ -> new_itemgroup objcb item
    method draw = itemgroup_draw obj
    method handle ev = itemgroup_handle obj ev
end;;

external new_divider: string -> widget_ptr = "new_Divider"
external divider_draw: widget_ptr -> unit = "divider_draw";;
external divider_handle: widget_ptr -> Event.event_type -> Event.event_type = "divider_handle";;

class divider = object
    inherit widget 0 0 0 0 ""
    method private alloc = fun name _ _ _ _ _ -> new_divider name
    method draw = divider_draw obj
    method handle ev = divider_handle obj ev
    method ct = "Divider"
end;;

external new_window: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_window_bc" "new_window";;
external window_draw: widget_ptr -> unit = "window_draw";;
external window_handle: widget_ptr -> Event.event_type -> Event.event_type = "window_handle";;
external window_show: widget_ptr -> unit = "window_show";;
external window_show_args: widget_ptr -> string array -> unit = "window_show_args";;

external window_set_doublebuffer: widget_ptr -> unit = "window_set_doublebuffer";;
external window_clear_doublebuffer: widget_ptr -> unit = "window_clear_doublebuffer";;
external widget_damage: widget_ptr -> int = "widget_damage";;
external window_border: widget_ptr -> bool -> unit = "window_border";;

class window ?(add=true) ?(x=0) ?(y=0) w h title = object(self)
    inherit group ~add ~x ~y w h title    
    method private alloc = new_window
    method ct = "window"
    method draw = window_draw obj
    method handle ev = window_handle obj ev
    method show = window_show obj
    method show_args args = window_show_args args
    method set_doublebuffer = window_set_doublebuffer obj
    method clear_doublebuffer = window_clear_doublebuffer obj
    method damage = widget_damage obj
    method border set = window_border obj set
end;;

external new_statusbar: string -> int -> int -> int -> int -> string -> widget_ptr
    = "new_StatusBarGroup_bc" "new_StatusBarGroup";;
external new_easy_statusbar: string -> int -> widget_ptr = "new_easy_statusbar";;
external statusbar_draw: widget_ptr -> unit = "statusbar_draw";;
external statusbar_handle: widget_ptr -> Event.event_type -> Event.event_type = "statusbar_handle";;

type statusbar_pos = SBAR_LEFT | SBAR_CENTER | SBAR_RIGHT;;
external statusbar_set_text: widget_ptr -> statusbar_pos -> string -> unit =
            "statusbar_set_text";; 
external statusbar_child_box: widget_ptr -> 'a image -> statusbar_pos -> unit =
    "statusbar_child_box";;

class statusBarGroup ~bar x y w h label = 
    object 
    inherit group ~x ~y w h label
    method draw = statusbar_draw obj
    method handle ev = statusbar_handle obj ev
    method child_box: 'a. statusbar_pos -> 'a image -> unit=
        fun pos box -> statusbar_child_box obj box pos
    method print ?(pos=SBAR_RIGHT) text = statusbar_set_text obj pos text
    method format_text : 'a. statusbar_pos -> ('a, unit,string, unit) format4 -> 'a =
        fun pos form -> Printf.ksprintf (statusbar_set_text obj pos) form
    method private alloc = match bar with
    | `Normal -> new_statusbar
    | `Easy   -> (fun name _ _ _ _ _ -> new_easy_statusbar name h)
    method ct = "StatusBar"
end;;

class easyStatusBar h = statusBarGroup ~bar:`Easy 0 0 0 h "";;
class statusBar x y w h label = statusBarGroup ~bar:`Normal x y w h label;;



