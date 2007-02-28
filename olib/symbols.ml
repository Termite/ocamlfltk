

external inspect: 'a -> unit = "inspect_block";;

type symbol;;
type 'a symb = symbol;;
type 'a draw_callback = symbol -> int * int * int * int -> unit;;

type 'a ptr = Ok of 'a | Null

external new_box: string -> string -> symbol = "new_symbol";;
external get_name: symbol -> string = "symbol_get_name";;
external set_name: symbol -> string -> unit = "symbol_set_name";;
external is_frame: symbol -> bool = "symbol_is_frame";;
external measure: symbol -> int -> int -> int*int = "symbol_measure";;


external find_symbol: string -> symbol option = "find_symbol";;
external find_between: string -> int -> int -> symbol option = "find_between";;
external native_symbol_iter: int -> (int * symbol) option = "symbol_iter";;

(*
external native_symbol_iter: int -> bool*int*symbol = "symbol_iter";;
  let native_symbol_iter n =
    let null, n, ptr = native_symbol_iter n in
    if null then None
    else Some(n,ptr)
;;
*)


let symbol_iter fkt =
    let rec next n =
        let s = native_symbol_iter n in
        match s with
        | None -> ()
        | Some(i,s) -> fkt s; next i
    in
    next 0
;;

let symbol_map fkt =
    let rec next n accu =
        let s = native_symbol_iter n in
        match s with
        | None -> accu
        | Some (i,s) -> next i (fkt s :: accu)
    in
    next 0 []
;;


type flatboxes = [ `Box | `FlatBox ];;
external new_flatbox: string option -> string -> [`FlatBox] symb = "new_flatbox";;

type frameboxes = [`FrameBox | `Box ];;
external new_framebox: string option -> string ->
        int -> int -> int -> int -> string -> 'a symb option -> [`FrameBox] symb
        = "new_framebox_bc" "new_framebox";;

let symbol_id = ref 1;;

let register fkt =
    let name = "symbol-" ^ (string_of_int !symbol_id) in
    incr symbol_id;
    Callback.register name fkt;
    name
;;

let make_box draw_funk name = new_box (register draw_funk) name ;;

let make_flatbox ?(draw=None) name =
    match draw with
    | None ->  new_flatbox None name
    | Some f -> new_flatbox (Some (register f)) name
;;


let make_framebox ?(draw=None) name dx dy w h pattern down_box=
    let _draw = match draw with
    | None -> None
    | Some f -> Some (register f)
    in
    new_framebox _draw name dx dy w h pattern down_box;;

external get_data: symbol -> string = "framebox_get_data";;
external set_data: symbol -> string -> unit = "framebox_set_data";;

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



