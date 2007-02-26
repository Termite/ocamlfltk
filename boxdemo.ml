open Printf;;
open Ofltk;;
open Symbols


let box_draw box (x,y,w,h) =
    Printf.printf "x:%d y:%d\n%!" x y
;;

let win = new fWindow ~x:1 ~y:0 400 400  "Pack Demo" in
let box = make_box box_draw "my box" in
let w,h = measure box in 
printf "symbol name: %s\tsize: %d, %d\n%!" (get_name box) w h;
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();

