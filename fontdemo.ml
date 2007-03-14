open Printf;;

let x= Font.courier;;

let all = Font.list () in
Array.iter (fun f -> print_endline (Font.name f)) all;

