
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
(*
(* Clipping *)
external push_clip: int -> int -> int -> int -> unit = "push_clip";;
external clipout:   int -> int -> int -> int -> unit = "clipout";;
external pop_clip: unit -> unit = "pop_clip";;
external push_no_clip: unit -> unit = "push_no_clip";;
external not_clipped: int -> int -> int -> int -> bool = "not_clipped";;
external intersect_with_clip: int -> int -> int -> int -> int = "intersect_with_clip";;

(* Path construction *)

external newpath: unit -> unit = "newpath";;
external addvertex_f: float -> float = "addvertex_f";;
external addvertex_i: int -> int = "addvertex_i";;
external addvertices_f: float array = "addvertices_f";;
external addvertices_i: int array = "addvertices_i";;
external addvertices_transformed: (int*int) array -> unit = "addvertices_transformed";;
external addcurve: float -> float -> float -> float -> float -> float -> float -> float 
    -> unit = "addcurve";;
external addarc: float -> float -> float -> float -> float -> float -> unit = "addcurve";;
external addpie: int -> int -> int -> int -> float -> float-> unit = "addpie";;
external addchord: int -> int -> int -> int -> float -> float-> unit = "addchord";;
external closepath: unit -> unit = "closepath";;

(* Shapes & Lines *)

external strokepath: unit -> unit = "strokepath";;
external fillpath:   unit -> unit = "fillpath";;
external fillstrokepath: unit -> unit = "fillstrokepath";;
external fillrect: int -> int -> int -> int i-> unit = "fillrect";;
external strokerect: int -> int -> int -> int -> unit = "strokerect";;
external drawline_i: int -> int -> int -> int -> unit = "drawline_i";;
external drawline_f: float -> float -> float -> float -> unit = "drawline_f";;
external drawpoint_i: int -> int -> unit = "drawpoint_i";;
external drawpoint_f: float -> float -> unit = "drawpoint_f";;

(* Text *)

external setfont: font -> float -> unit = "setfont";;
external setfont_name: string -> float -> unit = "setfont_name";;
external get_encoding: unit -> string = "get_encoding";;
external set_encoding: string -> unit = "set_encoding";;
external getfont: unit -> font = "getfont";;
external getsize: unit -> float = "getsize";;
external getwidth: string -> float = "getwidth";;
external drawtext_transformed: string -> int -> float -> float -> unit = 
    "drawtext_transformed";;
external drawtext: string -> float -> float -> unit = "drawtext";;
external drawsubtext: string -> int -> float -> float -> unit = "drawsubtext";;
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



*)
