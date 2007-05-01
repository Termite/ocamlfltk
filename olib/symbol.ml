type box;; 

type -'a sym = box;;
type 'a draw_callback = int->int->int->int -> unit;;
type 'a measure_callback = int -> int -> int*int;;
type 'a fill_callback = unit -> bool;;
type 'a is_frame_callback = unit -> bool;;
type 'a inset_callback =  int -> int -> int -> int -> unit;;
type virtuals = string option * string option * string option * string option * string option;;

type symbol = [`Box];;
    type flatbox = [symbol | `Flatbox]
        type highlightbox = [flatbox | `HighlightBox]

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

let to_box x = x;;

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

external new_symbol: virtuals -> string -> box = "new_symbol";;
external new_multiimage: virtuals -> box -> box = "new_multiimage";;
external add_to_multiimage: box -> int -> box -> unit = "add_to_multiimage";;
external current_image: box -> box = "multiimage_current_image";;
external release: box -> unit = "multiimage_release";;
external release: box -> unit = "multiimage_release";;
external new_flatbox: virtuals -> string -> box = "new_flatbox";;
external new_tiledimage: virtuals -> box -> box = "new_tiledimage";;
external new_highlightbox: virtuals -> string -> box -> highlightbox sym = "new_highlightbox";;
external new_framebox: virtuals -> string ->
        int -> int -> int -> int -> string -> box option -> box 
        = "new_framebox_bc" "new_framebox";;
external new_xpmimage: virtuals -> string array -> string option -> box = "new_xpmimage";; 
external get_name: box -> string = "symbol_get_name";;
external set_name: box -> string -> unit = "symbol_set_name";;
external is_frame: box -> bool = "symbol_is_frame";;
external measure: box -> int -> int -> int*int = "symbol_measure";;
external native_symbol_iter: int -> (int * box) option = "symbol_iter";;

let add_to_multiimage multiimage images =
    List.iter (fun (flag, image) ->
        add_to_multiimage multiimage flag image) images
;;

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


let make_virtuals ~draw ~measure ~fill ~is_frame ~inset () =
	(register_opt draw, register_opt measure, register_opt fill, register_opt is_frame, register_opt inset)
;;

let make_symbol ~draw ?measure ?fill ?is_frame ?inset name =
	let vi = make_virtuals ~draw:(Some draw) ~measure ~fill ~is_frame ~inset () in
	new_symbol vi name
;;	


let make_multiimage ?draw ?measure ?fill ?is_frame ?inset image0 more_images = 
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    let m = new_multiimage vi image0 in
    add_to_multiimage m more_images;
    m
;;

let make_flatbox ?draw ?measure ?fill ?is_frame ?inset name =
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    new_flatbox vi name
;;

let make_tiledimage ?draw ?measure ?fill ?is_frame ?inset otherbox =
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    new_tiledimage vi otherbox;;

let make_framebox ?draw ?measure ?fill ?is_frame ?inset name dx dy w h pattern down_box=
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    new_framebox vi name dx dy w h pattern down_box
;;

module SharedImage = struct
    external get: string -> box = "shared_image_get";;
    external remove: string -> int = "shared_image_remove";;
    external set_root_directory: string -> unit = "shared_image_root";;
    external draw: box -> int*int*int*int -> unit = "shared_image_draw";;
end;;

let make_xpmimage ?draw ?measure ?fill ?is_frame ?inset ?name data =
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    new_xpmimage vi data name ;;

let make_highlightbox ?draw ?measure ?fill ?is_frame ?inset name otherbox = 
	let vi = make_virtuals ~draw ~measure ~fill ~is_frame ~inset () in
    new_highlightbox vi name otherbox
;;

external register_images: unit -> unit = "register_images";;

module Symbols = struct

type symbol_ptr;;
let null_ptr : symbol_ptr = Obj.magic None;;

external symbol_measure: symbol_ptr -> int -> int -> int*int = "symbol_measure";;
external symbol_name: symbol_ptr -> string = "symbol_measure";;
external symbol_fills_rectangle: symbol_ptr -> bool = "symbol_measure";;
external symbol_is_frame: symbol_ptr -> bool = "symbol_measure";;
external symbol_inset: symbol_ptr -> int -> int -> int -> int -> unit = "symbol_measure";;
external symbol_set_name: symbol_ptr -> string -> unit = "symbol_measure";;
external symbol_dx: symbol_ptr -> int = "symbol_measure";;

class virtual symbol name = object(self)
	val mutable obj = null_ptr
	method obj = obj
	method private virtual alloc : string -> symbol_ptr
	method _measure = symbol_measure obj
	method virtual _draw : int -> int -> int -> int -> unit 
	method inset = symbol_inset obj
	method fills_rectangle = symbol_fills_rectangle obj
	method is_frame = symbol_is_frame obj
	method name = symbol_name obj
	method set_name n = symbol_set_name obj n
	method dx = symbol_dx obj
	method dy = symbol_dx obj
	method dw = symbol_dx obj
	method dh = symbol_dx obj
	initializer
		let obj_id = "sym" ^ (string_of_int (Oo.id self)) in
		Callback.register obj_id self;
		obj <- self#alloc obj_id
end;;

external frameBox_dx: symbol_ptr -> int = "symbol_measure";;
external new_frameBox: string -> string -> int->int-> int -> int -> string -> symbol_ptr -> symbol_ptr 
	= "symbol_measure" "symbol_measure";;
external frameBox_data: symbol_ptr -> string = "symbol_measure";;
external frameBox_set_data: symbol_ptr -> string -> unit = "symbol_measure";;
external frameBox_draw: symbol_ptr -> int -> int -> int -> int -> unit = "symbol_measure";;

class frameBox name dx dy dw dh pattern downBox = object(self)
	inherit symbol name
	method private alloc obj_id = new_frameBox obj_id name dw dy dw dh pattern downBox
	method data = frameBox_data obj
	method set_data d = frameBox_set_data obj d
	method _draw = frameBox_draw obj
	method dx = frameBox_dx obj
	method dy = frameBox_dx obj
	method dw = frameBox_dx obj
	method dh = frameBox_dx obj
end;;


external flatBox_draw: symbol_ptr -> int -> int -> int -> int -> unit = "symbol_measure";;
external new_flatBox: string -> string -> symbol_ptr = "symbol_measure";;

class flatBox name = object(self)
	inherit symbol name
	method _draw = flatBox_draw obj
	method private alloc obj_id = new_flatBox obj_id name
end;;

external new_highlight_box: string -> string -> symbol_ptr -> symbol_ptr = "symbol_measure";;

class highlightBox name hbox  = object(self)
	inherit flatBox name
	method private alloc obj_id = new_highlight_box obj_id name hbox#obj
end;;

(*
let a = new flatBox "eins" in
let b = new highlightBox "zwei" a in
print_endline b#name
*)


end;;


