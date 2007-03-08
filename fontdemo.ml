open Printf;;

let all = Font.list () in
Array.iter (fun f -> print_endline (Font.name f)) all;

