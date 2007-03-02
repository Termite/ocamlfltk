type -'a sym;;

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

type 'a draw_callback = 'a sym -> int*int*int*int -> unit;;

val make_symbol: symbol draw_callback -> string -> symbol sym;;

val get_name: [> symbol] sym -> string;;
val set_name: [> symbol] sym -> string -> unit;;
val is_frame: [> symbol] sym -> bool;;
val measure: [> symbol] sym -> int -> int -> int*int;;

val iter_symbol: (symbol sym -> unit) -> unit;;
val map_symbol: (symbol sym -> 'a) -> 'a list;;

val make_flatbox: ?draw: [<flatbox] draw_callback option -> string -> flatbox sym;;
val make_framebox: ?draw: [<framebox] draw_callback option -> string ->
    int -> int -> int -> int -> string -> [>symbol] sym option -> framebox sym;;
val make_xpmimage: ?draw: [<xpmimage] draw_callback option -> ?name:string ->
    string array -> xpmimage sym;;


