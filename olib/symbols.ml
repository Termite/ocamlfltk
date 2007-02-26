
type symbol;;
type 'a symb = symbol;;
type 'a draw_callback = symbol -> int * int * int * int -> unit;;

external new_box: string -> string -> symbol = "make_symbol";;
external get_name: symbol -> string = "symbol_get_name";;
external set_name: symbol -> string -> unit = "symbol_set_name";;
external measure: symbol -> int*int = "symbol_measure";;

let symbol_id = ref 1;;

let register fkt =
    let name = "symbol-" ^ (string_of_int !symbol_id) in
    incr symbol_id;
    Callback.register name fkt;
    name
;;

let make_box draw_funk name = new_box (register draw_funk) name ;;

(*
external dx: 'a symb -> int = "symbol_dx";;
external dy: 'a symb -> int = "symbol_dy";;
external dw: 'a symb -> int = "symbol_dw";;
external dh: 'a symb -> int = "symbol_dh";;
external draw: symbol -> int*int*int*int -> unit = "symbol_draw";;
external is_frame: symbol -> bool = "symbol_is_frame";;



external make_flatbox: string -> 'a draw_callback -> symbol = "make_flatbox";;
external make_highlightbox: string ->'a draw_callback -> symbol = "make_highlightbox";;

external make_image: string ->'a draw_callback -> symbol = "make_image";;
external image_depth: symbol -> int = "image_depth";;
external image_fetch: symbol -> bool= "image_fetch";;
external xbm_fetch: symbol -> string -> bool* symbol = "xbm_fetch";;

external make_xbm: string -> 'a draw_callback -> symbol = "make_xbm";;
*)


