type 'a symb;;

type 'a draw_callback = 'a symb -> int * int * int * int -> unit;;

(* base *)
val make_box: [`Box] draw_callback -> string -> [`Box] symb;;
val get_name: 'a symb -> string;;
val set_name: 'a symb -> string -> unit;;
external measure: 'a symb -> int*int = "symbol_measure";;

(*val draw: 'a symb -> int*int*int*int -> unit;;
val is_frame: 'a symb -> bool;;*)

(*val make_flatbox: string -> [`FlatBox] draw_callback -> [`FlatBox] symb;;

val make_highlightbox: string -> [`Highbox] draw_callback -> [`Highbox] symb;;

val make_image: string -> [`Image] draw_callback -> [`Image] symb;;
val image_depth: [< `Image | `XbmImage] symb -> int;;
val image_fetch: [< `Image | `XbmImage] symb -> bool;;

val make_xbm: string -> 'a draw_callback -> [`XbmImage] symb;;
val xbm_fetch: [`XbmImage] symb -> string -> bool * [`Image] symb;; 

*)

