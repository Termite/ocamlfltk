open Printf;;
open Ofltk;;

let win = new fWindow (5*75) 400  "Pack Demo" in
let sc = new fScrollGroup 0 0 (5*75) 300 "" in
sc#begin_add;
let w = new fWidget 0 (8*25) (5*75) (5*75) "" in
sc#wend;
sc#scrolltype BothAlways;

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();

