
external _ask: string -> int = "ask_box";;
external choice: string -> string -> string -> string -> int = "choice";;
external message_box: string -> unit = "message_box";;
external input: string -> string -> string option = "input_box";;
external set_ok: string -> unit = "set_ok";;

let ask fmt = Printf.ksprintf _ask fmt ;;

let message fmt = Printf.ksprintf message_box fmt;;

let input def fmt = Printf.ksprintf (input def) fmt ;;

let choice b0 b1 b2 fmt = Printf.ksprintf (choice b0 b1 b2) fmt;;


