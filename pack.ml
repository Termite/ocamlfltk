open Printf;;
open Ofltk;;

let make_bar name w h dir =
    let b = new fBarGroup 0 0 w h name in
    if dir = `Vert then b#set_vertical;
    b#set_box Box.thin_up_box;
;;


let win = new fWindow 300 300  "Pack Demo" in
let p = new fPackedGroup 0 0 300 300 "" in
win#resizable p;
p#begin_add;
make_bar "bar0" 30 30 `H; 
make_bar "bar1" 30 30 `H;
make_bar "bar2" 30 30 `Vert;
make_bar "bar3" 30 30 `Vert;
make_bar "bar4" 30 30 `H;
let w = new fWidget 0 0 30 30 "resizable()" in
w#set_box Box.flat_box;
w#set_color 0x44444400l;
p#resizable w;
make_bar "bar5" 30 30 `H;
make_bar "bar6" 30 30 `Vert;
make_bar "bar7" 30 30 `Vert;
make_bar "bar8" 30 30 `H;
make_bar "bar9" 30 30 `H;
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();

