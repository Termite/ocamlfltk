external message: string -> unit = "dialog_message";;
external alert: string -> unit = "dialog_alert";;
external ask: string -> int = "dialog_ask";;
external choice: string -> string -> string -> string -> int = "dialog_choice";;
external choice_alert: string -> string -> string -> string -> int =
    "dialog_choice_alert";;
external input: string -> string -> string option = "dialog_input";;
external password: string -> string -> string option = "dialog_password";;
external set_no: string -> unit = "set_no";;
external set_yes: string -> unit = "set_yes";;
external set_ok: string -> unit = "set_ok";;
external set_cancel: string -> unit = "set_cancel";;
external no: unit -> string = "dialog_no";;
external yes: unit -> string = "dialog_yes";;
external ok: unit -> string = "dialog_ok";;
external cancel: unit -> string = "dialog_cancel";;

let message fmt = Printf.ksprintf message fmt;;
let alert fmt = Printf.ksprintf alert fmt ;;
let ask fmt = Printf.ksprintf ask fmt ;;
let choice b0 b1 b2 fmt = Printf.ksprintf (choice b0 b1 b2) fmt;;
let choice_alert b0 b1 b2 fmt = Printf.ksprintf (choice_alert b0 b1 b2) fmt;;
let input ?(def="") fmt = Printf.ksprintf (input def) fmt ;;
let password ?(def="") fmt = Printf.ksprintf (password def) fmt ;;


