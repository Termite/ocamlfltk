open Printf;;
open Ofltk;;


let add_group wiz text col pos =
    let g = new fGroup ~x:0 ~y:0 320 200 "" in
    g#begin_add;
    if pos <> `Last then (
        let b1 = new fButton 20 25 (320-25) 25 ">> next" in
        b1#callback  (fun () -> wiz#next_page));
    if pos <> `First then (
        let b2 = new fButton 20 55 (320-25) 25 "<< prev" in
        b2#callback  (fun () -> wiz#prev_page));
    let w = new fWidget 10 100 300 90 "" in
    w#set_color col;
    w#set_label text;
    g#wend;
;;


let win = new fWindow 320 200  "hehe" in
let wiz = new fWizardGroup 0 0 320 200 "" in
wiz#begin_add;
add_group wiz "hi" 0l `First;
add_group wiz "do" 0x55555500l `Middle;
add_group wiz "drei" 0xa0000000l `Last;
wiz#wend;
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();
Gc.full_major();

