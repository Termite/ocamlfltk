type -'a sym;;

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

val to_box: 'a sym -> symbol sym;;

type 'a draw_callback = int->int->int->int -> unit;;
type 'a measure_callback = int -> int -> int*int;;
type 'a fill_callback = unit -> bool;;
type 'a is_frame_callback = unit -> bool;;
type 'a inset_callback =  int -> int -> int -> int -> unit;;

val make_symbol :
  draw:('a draw_callback) ->
  ?measure:('a measure_callback) ->
  ?fill:('a fill_callback) ->
  ?is_frame:('a is_frame_callback) ->
  ?inset:('a inset_callback) -> string -> symbol sym;;

val get_name: [> symbol] sym -> string;;
val set_name: [> symbol] sym -> string -> unit;;
val is_frame: [> symbol] sym -> bool;;
val measure: [> symbol] sym -> int -> int -> int*int;;

val iter_symbol: (symbol sym -> unit) -> unit;;
val map_symbol: (symbol sym -> 'a) -> 'a list;;
val make_flatbox: 
  ?draw:([<flatbox]  draw_callback) ->
  ?measure:([<flatbox]  measure_callback) ->
  ?fill:([<flatbox]  fill_callback) ->
  ?is_frame:([<flatbox]  is_frame_callback) ->
  ?inset:([<flatbox]  inset_callback) -> string -> flatbox sym;;

val make_tiledimage: 
  ?draw:([<tiledimage]  draw_callback) ->
  ?measure:([<tiledimage]  measure_callback) ->
  ?fill:([<tiledimage]  fill_callback) ->
  ?is_frame:([<tiledimage]  is_frame_callback) ->
  ?inset:([<tiledimage]  inset_callback) -> [> symbol] sym -> tiledimage sym;;

val make_multiimage: 
  ?draw:([<multiimage]  draw_callback) ->
  ?measure:([<multiimage]  measure_callback) ->
  ?fill:([<multiimage]  fill_callback) ->
  ?is_frame:([<multiimage]  is_frame_callback) ->
  ?inset:([<multiimage]  inset_callback) -> [> symbol] sym
  	-> (Flags.flags * [> symbol] sym) list -> multiimage sym;;

val make_xpmimage: 
  ?draw:([<xpmimage]  draw_callback) ->
  ?measure:([<xpmimage]  measure_callback) ->
  ?fill:([<xpmimage]  fill_callback) ->
  ?is_frame:([<xpmimage]  is_frame_callback) ->
  ?inset:([<xpmimage]  inset_callback) ->
  ?name:string -> string array -> xpmimage sym;;


val add_to_multiimage: multiimage sym -> (Flags.flags * [>symbol] sym) list -> unit;;
val current_image: multiimage sym -> symbol sym;;
val release: multiimage sym -> unit;;
(*
val make_highlightbox: ?draw: [<highlightbox] draw_callback option -> string ->
    [>symbol] sym -> highlightbox sym;;
val make_framebox: ?draw: [<framebox] draw_callback option -> string ->
    int -> int -> int -> int -> string -> [>symbol] sym option -> framebox sym;;
*)

external register_images: unit -> unit = "register_images";;

module SharedImage :
  sig
    external get : string -> sharedimage sym = "shared_image_get"
    external remove : string -> int = "shared_image_remove"
    external set_root_directory : string -> unit = "shared_image_root"
    external draw : [< sharedimage] sym -> int * int * int * int -> unit
      = "shared_image_draw"
  end

