open Printf;;
open Widgets;;

let win = new window (5*75) 400  "ScrollGroup Demo" in
let sc = new scrollGroup 0 0 (5*75) 300 "" in
sc#begin_add;
let w = new widget 0 (8*25) (5*75) (5*75) "" in
sc#wend;
sc#scrolltype BothAlways;

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();
Gc.full_major();

