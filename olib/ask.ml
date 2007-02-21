
external _ask: string -> int = "ask_box";;
external input: string -> string -> string option = "input_box";;

let ask form =
   Printf.ksprintf _ask form 
;;

let input def form =
    Printf.ksprintf (input def) form
;;
