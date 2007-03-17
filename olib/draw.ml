type color = Int32.t;;

(* Transformations *)
external push_matrix: unit -> unit = "push_matrix";;
external pop_matrix: unit -> unit = "pop_matrix";;
external scale_xy: float -> float -> unit = "scale_xy";;
external scale_x: float -> unit = "scale_x";;
external translate_f: float -> float -> unit = "translate_f";;
external translate_i: int -> int -> unit = "translate_i";;
external rotate: float -> unit = "rotate";;
external concat: int->int->int->int->int->int -> unit = "concat_bc" "concat";;
external load_identity: unit -> unit = "load_identity";;
external transform_f: float -> float -> float * float = "tranform_f";;
external transform_distance: float -> float -> float * float = "tranform_distance";;
external transform_i: int -> int -> int * int = "tranform_i";;
external transform_rect: int -> int -> int -> int ->
    int * int * int * int = "tranform_rect";;


(* Clipping *)
external push_clip: int -> int -> int -> int -> unit = "style_push_clip";;
external clipout:   int -> int -> int -> int -> unit = "style_clipout";;
external pop_clip: unit -> unit = "style_pop_clip";;
external push_no_clip: unit -> unit = "style_push_no_clip";;
external not_clipped: int -> int -> int -> int -> bool = "style_not_clipped";;

type clipped =
    | NoIntersect of int*int*int*int
    | Equal of int*int*int*int 
    | Partially of int*int*int*int
;;

external intersect_with_clip: int -> int -> int -> int -> clipped
    = "style_intersect_with_clip";;

(* Path construction *)

external newpath: unit -> unit = "newpath";;
external addvertex_f: float -> float -> unit = "addvertex_f";;
external addvertex_i: int -> int -> unit = "addvertex_i";;
external addvertices_f: float array -> unit = "addvertices_f";;
external addvertices_i: int array -> unit = "addvertices_i";;
external addvertices_transformed: (int*int) array -> unit = "addvertices_transformed";;
external addcurve: float -> float -> float -> float -> float -> float -> float -> float 
    -> unit = "addcurve_bc" "addcurve";;
external addarc: float -> float -> float -> float -> float -> float -> unit
    = "addarc_bc" "addarc";;
external addpie: int -> int -> int -> int -> float -> float-> unit = "addpie";;
external addchord: int -> int -> int -> int -> float -> float-> unit = "addchord";;
external closepath: unit -> unit = "closepath";;

(* Shapes & Lines *)

external strokepath: unit -> unit = "strokepath";;
external fillpath:   unit -> unit = "fillpath";;
external fillstrokepath: unit -> unit = "fillstrokepath";;
external fillrect: int -> int -> int -> int -> unit = "fillrect";;
external strokerect: int -> int -> int -> int -> unit = "strokerect";;
external drawline_i: int -> int -> int -> int -> unit = "drawline_i";;
external drawline_f: float -> float -> float -> float -> unit = "drawline_f";;
external drawpoint_i: int -> int -> unit = "drawpoint_i";;
external drawpoint_f: float -> float -> unit = "drawpoint_f";;

(* Text *)

external setfont: Font.font -> float -> unit = "setfont";;
external setfont_name: string -> float -> unit = "setfont_name";;
external get_encoding: unit -> string = "get_encoding";;
external set_encoding: string -> unit = "set_encoding";;
external getfont: unit -> Font.font = "getfont";;
external getsize: unit -> float = "getsize";;
external getwidth: string -> float = "draw_getwidth";;
external drawtext_transformed: string -> int -> float -> float -> unit = 
    "drawtext_transformed";;
external drawtext: string -> float -> float -> unit = "drawtext";;
external drawsubtext: string -> int -> float -> float -> unit = "drawsubtext";;
(*
(*
 * 
external drawtextrect: string -> int -> int -> int -> int -> int -> unit =
    "drawtextrect_bc" "drawtextrect";;
*)
(*
external drawtext_x: (string -> int -> float -> float -> unit)
    -> (string -> int -> float)
    -> string -> int -> int -> int -> int -> int -> unit =
        "drawtext_x_bc" "drawtext_x";;
*)

let drawtext text ?bytes x y =
    match len with
    | None -> drawtext text x y
    | Some n -> drawsubtext text n x y
;;




(* Functions *)
let solid	    = 0;;
let dash	    = 1;;
let dot	        = 2;;
let dashdot	    = 3;;
let dashdotdot	= 4;;

let cap_flat	= 0x100;;
let cap_round	= 0x200;;
let cap_square	= 0x300;;

let join_miter	= 0x1000;;
let join_round	= 0x2000;;
let join_bevel	= 0x3000;;

external setcolor: color -> unit = "setcolor";;
external setcolor_alpha: color -> float -> unit = "setcolor_alpha";;
external getcolor: unit -> color = "getcolor";;
external setbgcolor: color -> unit = "setbgcolor";;
external getbgcolor: unit -> color = "getbgcolor";;
external set_drawstyle: style -> int -> unit = "drawstyle";;
external get_drawstyle: unit -> style = "get_drawstyle";;
external set_drawflags: int -> int = "set_drawflags";;
external get_drawflags: unit -> int = "get_drawflags";;
external set_linestyle: int -> float -> string = "set_linestyle";;
external get_linestyle: unit -> int = "get_linestyle";;
external get_linewidth: unit -> float = "get_linewidth";;
external get_linedashes: unit -> string = "get_linedashes";;




*)
