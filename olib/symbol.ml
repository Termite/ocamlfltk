type box;; 

type -'a sym = box;;
type 'a draw_callback = box -> int*int*int*int -> unit;;

type symbol = [`Box];;
    type flatbox = [symbol | `Flatbox]
        type highlight = [flatbox | `HighlightBox]

    type framebox = [symbol | `Framebox]

    type image = [symbol | `Image]

        type sharedimage = [image | `SharedImage]
            type gifimage = [sharedimage | `GifImage]
            type xpm_fileimage = [sharedimage | `XpmFileImage]

        type xbmimage = [image | `XbmImage]
        type xpmimage = [image | `XpmImage]

    type multiimage = [symbol | `MultiImage]

    type tiledimage = [symbol | `TiledImage]

;;

let symbol_id = ref 1;;

let register fkt =
    let name = "symbol-" ^ (string_of_int !symbol_id) in
    incr symbol_id;
    Callback.register name fkt;
    name
;;

let register_opt fkt = match fkt with
    | None -> None
    | Some f -> Some (register f)
;;

external new_symbol: string -> string -> box = "new_symbol";;
external new_flatbox: string option -> string -> box = "new_flatbox";;
external new_framebox: string option -> string ->
        int -> int -> int -> int -> string -> box option -> box 
        = "new_framebox_bc" "new_framebox";;
external new_xpmimage: string option -> string array -> string option -> box = "new_xpmimage";; 
external get_name: box -> string = "symbol_get_name";;
external set_name: box -> string -> unit = "symbol_set_name";;
external is_frame: box -> bool = "symbol_is_frame";;
external measure: box -> int -> int -> int*int = "symbol_measure";;
external native_symbol_iter: int -> (int * box) option = "symbol_iter";;

let iter_symbol fkt =
    let rec next n =
        let s = native_symbol_iter n in
        match s with
        | None -> ()
        | Some(i,s) -> fkt s; next i
    in
    next 0
;;

let map_symbol fkt =
    let rec next n accu =
        let s = native_symbol_iter n in
        match s with
        | None -> accu
        | Some (i,s) -> next i (fkt s :: accu)
    in
    next 0 []
;;


let make_symbol draw name = new_symbol (register draw) name;;
let make_flatbox ?(draw=None) name = new_flatbox (register_opt draw) name;;
let make_framebox ?(draw=None) name dx dy w h pattern down_box=
    new_framebox (register_opt draw) name dx dy w h pattern down_box;;
let make_xpmimage ?(draw=None) ?name data =
    new_xpmimage (register_opt draw) data name
;;

