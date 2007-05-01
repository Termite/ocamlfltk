open Printf;;
open Widgets;;

let win = new window 320 296  "Pack Demo" in
let t = new tabGroup 10 10 300 191 "" in
t#begin_add;
let g1 = new group ~x:0 ~y:20 300 171 "Label 1" in
g1#begin_add;
let b1 = new button 10 25 100 22 "button 1" in
g1#wend;
let g2 = new group ~x:0 ~y:20 300 171 "Tab 2" in
g2#hide;
g2#begin_add;
let b2 = new radioButton 10 25 100 22 "Radio1" in
let b2 = new radioButton 10 60 100 22 "Radio2" in
g2#wend;
let g3 = new group ~x:0 ~y:20 300 171 "Tab 3" in
g3#begin_add;
let eb = new button 20 50 80 22 "ende & aus" in
eb#callback (fun () -> win#hide);
g3#wend;
g3#hide;
t#wend;
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();
Gc.full_major();

