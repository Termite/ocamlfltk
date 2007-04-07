open Printf;;
open Widgets;;

let win = new fWindow 320 296  "Pack Demo" in
let t = new fTabGroup 10 10 300 191 "" in
t#begin_add;
let g1 = new fGroup ~x:0 ~y:20 300 171 "Label 1" in
g1#begin_add;
let b1 = new fButton 10 25 100 22 "button 1" in
g1#wend;
let g2 = new fGroup ~x:0 ~y:20 300 171 "Tab 2" in
g2#hide;
g2#begin_add;
let b2 = new fButton ~btyp:RadioButton 10 25 100 22 "Radio1" in
let b2 = new fButton ~btyp:RadioButton 10 60 100 22 "Radio2" in
g2#wend;
let g3 = new fGroup ~x:0 ~y:20 300 171 "Tab 3" in
g3#begin_add;
let eb = new fButton 20 50 80 22 "ende & aus" in
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

