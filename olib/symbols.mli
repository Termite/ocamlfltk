type 'a symb;;

type symbol_types = [
    `Box | `Image | `xpmImage | `FrameBox | `FlatBox | `MultiImage
];;

type 'a draw_callback = 'a symb -> int * int * int * int -> unit;;

external inspect: 'a -> unit = "inspect_block";;
(* base *)
val make_box: [`Box] draw_callback -> string -> [`Box] symb;;
val get_name: 'a symb -> string;;
val set_name: 'a symb -> string -> unit;;
external is_frame: 'a symb -> bool = "symbol_is_frame";;
external measure: 'a symb -> int -> int -> int*int = "symbol_measure";;

val symbol_iter: ([`Box] symb -> unit) -> unit;;

type flatboxes = [ `Box | `FlatBox ];;
val make_flatbox: ?draw:[< flatboxes] draw_callback option -> string -> [`FlatBox] symb;;

type frameboxes = [`FrameBox | `Box ];;
val make_framebox: ?draw:[< frameboxes] draw_callback option -> string ->
        int -> int -> int -> int -> string -> 'a symb option -> [`FrameBox] symb;;

val get_data: [`FrameBox] symb -> string;;
val set_data: [`FrameBox] symb -> string -> unit;;

(*val draw: 'a symb -> int*int*int*int -> unit;;
*)

(*

val make_highlightbox: string -> [`Highbox] draw_callback -> [`Highbox] symb;;

val make_image: string -> [`Image] draw_callback -> [`Image] symb;;
val image_depth: [< `Image | `XbmImage] symb -> int;;
val image_fetch: [< `Image | `XbmImage] symb -> bool;;

val make_xbm: string -> 'a draw_callback -> [`XbmImage] symb;;
val xbm_fetch: [`XbmImage] symb -> string -> bool * [`Image] symb;; 

*)
val make_xpmimage: ?draw:[< `Box | `Image | `xpmImage ] draw_callback option ->
    ?name: string -> string array -> [`xpmImage  | `Box ] symb;;


val make_multiimage: ?draw:[< `Box | `MultiImage] draw_callback option -> 'a symb ->
    [`MultiImage] symb;;

val add_to_multi: [`MultiImage] symb -> (int * 'a symb) list -> unit;;
