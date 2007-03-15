type cstyle;;
type color = Int32.t;;

type -'a style = cstyle;;

type normal = [`Style];;
type named = [normal | `Named];;
type 'a box = 'a Symbol.sym constraint 'a = [> Symbol.symbol];;

external default_style: unit -> cstyle = "style_default_style";;
external set_box: [> normal] style -> 'a box -> unit = "style_set_box";;
external set_buttonbox: [> normal ] style -> 'a box -> unit = "style_set_buttonbox";;
external set_focusbox:  [> normal ] style -> 'a box -> unit = "style_set_focusbox";;
external set_glyph: [>normal] style -> 'a box -> unit = "style_set_glyph";;
external set_labelfont: [>normal] style -> Font.font -> unit = "style_set_labelfont";;
external set_textfont:  [>normal] style -> Font.font -> unit = "style_set_textfont";;
(* set_labeltype *)
external set_color: [>normal] style -> color -> unit = "style_set_color";;
external set_textcolor: [>normal] style -> color -> unit = "style_set_textcolor";;
external set_selcolor: [>normal] style -> color -> unit = "style_setselcolor";;
external set_seltextcolor: [>normal] style -> color -> unit = "style_setseltextcolor";;
external set_buttoncolor:  [>normal] style -> color -> unit = "style_setbuttoncolor";;
external set_labelcolor:   [>normal] style -> color -> unit = "style_setlabelcolor";;
external set_highlightcol:    [>normal] style -> color -> unit = "style_sethighlightcol";;
external set_highlighttextcol:[>normal] style -> color -> unit = "style_sethighlighttextcol";;
external set_labelsize: [>normal] style -> float -> unit = "style_setlabelsize";;
external set_textsize:  [>normal] style -> float -> unit = "style_settextsize";;
external set_leading:   [>normal] style -> float -> unit = "style_setleading";;
external set_scrollbar_align: [>normal] style -> Flags.flags -> unit = "style_scrollbar_align";;
external set_scrollbar_width: [>normal] style -> Flags.flags -> unit = "style_scrollbar_width";;






let apply v f st =
    match v with
    | None -> ()
    | Some n -> f st n
;;

(*
let make_style 
    ?box ?buttonbox ?focusbox ?glyph ?labelfont ?textfont ?labeltype 
    ?color ?textcolor ?sel_color ?sel_textcolor ?buttoncolor ?labelcolor
    ?hi_color ?hi_textcolor ?labelsize ?textsize ?leading
    ?scrollbar_align ?scrollbar_width
    ?hide_underscore ?draw_boxes_inactive ?wheel_scroll
    () =
        let s = default_style () in
        List.iter (fun (v,f) -> apply v f s) [
            box,setbox;
            buttonbox, setbuttonbox;
            focusbox, set_focusbox;
            glyph, set_glyph;
            labelfont, set_labelfont;
*)




