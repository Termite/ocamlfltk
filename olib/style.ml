type cstyle;;

type -'a style = cstyle;;

type normal = [`Style];;
type named = [normal | `Named];;
type 'a box = 'a Symbol.sym constraint 'a = [> Symbol.symbol];;

external default_style: unit -> cstyle = "style_default_style";;
external set_box: cstyle -> 'a box -> unit = "style_set_box";;

external set_buttonbox: [> normal ] style -> 'a box -> unit = "style_set_buttonbox";;
(*external set_focusbox:  [> normal ] style -> 'a box -> unit = "style_set_focusbox";;*)
external set_glyph: [>normal] style -> 'a box -> unit = "style_set_glyph";;
external set_labelfont: [>normal] style -> Font.font -> unit = "style_set_labelfont";;
external set_textfont:  [>normal] style -> Font.font -> unit = "style_set_textfont";;
(* set_labeltype *)
external set_color: [>normal] style -> Color.color -> unit = "style_set_color";;
external set_textcolor: [>normal] style -> Color.color -> unit = "style_set_textcolor";;
external set_selection_color: [>normal] style -> Color.color -> unit = "style_set_selcolor";;
external set_seltextcolor: [>normal] style -> Color.color -> unit = "style_setseltextcolor";;
external set_buttoncolor:  [>normal] style -> Color.color -> unit = "style_setbuttoncolor";;
external set_labelcolor:   [>normal] style -> Color.color -> unit = "style_setlabelcolor";;
external set_highlight_color:    [>normal] style -> Color.color -> unit = "style_set_highlight_color";;
external set_highlighttextcol:[>normal] style -> Color.color -> unit = "style_sethighlighttextcol";;
external get_color: [>normal] style -> Color.color = "style_get_color";;
external get_textcolor: [>normal] style -> Color.color = "style_get_textcolor";;
external get_selection_color: [>normal] style -> Color.color = "style_get_selection_color";;
external set_labelsize: [>normal] style -> float -> unit = "style_setlabelsize";;
external set_textsize:  [>normal] style -> float -> unit = "style_settextsize";;
external set_leading:   [>normal] style -> float -> unit = "style_setleading";;
external set_scrollbar_align: [>normal] style -> Flags.flags -> unit = "style_scrollbar_align";;
external set_scrollbar_width: [>normal] style -> Flags.flags -> unit = "style_scrollbar_width";;

external find: string -> normal style option  = "style_find";;

external reset_theme: unit -> unit = "reset_theme";;

let apply v f st =
    match v with
    | None -> ()
    | Some n -> f st n
;;

external button_default_style: unit -> cstyle = "button_default_style";;
let buttonDefaultStyle = button_default_style();;

(*
let modify_style 
    ?box ?buttonbox ?focusbox ?glyph ?labelfont ?textfont ?labeltype 
    ?color ?textcolor ?sel_color ?sel_textcolor ?buttoncolor ?labelcolor
    ?hi_color ?hi_textcolor ?labelsize ?textsize ?leading
    ?scrollbar_align ?scrollbar_width
    ?hide_underscore ?draw_boxes_inactive ?wheel_scroll
    style =
        List.iter (fun (v,f) -> apply v f style) [
            box,setbox;
            buttonbox, setbuttonbox;
            focusbox, set_focusbox;
            glyph, set_glyph;
            labelfont, set_labelfont;


let ns = buttonDefaultStyle () in
modify_style ~box:plastic_up ~color:220l ~highlightColor:3l ns;;

*)


