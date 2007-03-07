open Printf;;

(*
let l = Monitor.list() in
Array.iter (fun m -> printf "depth: %d\tdpi_x:%f\tdpi_y:%f\n" 
(Monitor.depth m) (Monitor.dpi_x m) (Monitor.dpi_y m)) l;
print_endline ""
*)

let l = Monitor.list () in
Array.iter (fun a -> printf "dpi: %f\n%!" (Monitor.dpi_y a)) l;

