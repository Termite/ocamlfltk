open Printf;;
open Widgets;;

class myButton x y w h t = object(self)
    inherit fButton x y w h t as chef
    method draw = print_endline "myButton Draw"; chef#draw
end;; 

class myWin w h t = object(self)
    inherit fWindow w h t as chef
    method draw = print_endline "nix..."; chef#draw
end;;

class myRadio x y w h t var value = object(self)
    inherit fButton ~btyp:RadioButton x y w h t as chef
    method callback fkt = chef#callback (fun () -> var := value; fkt ())
end;;
        
external inspect: 'a -> unit = "inspect_block";;


let add_group wiz text col =
    let g = new fGroup ~x:0 ~y:0 320 200 "" in
    g#begin_add;
    let b1 = new fButton 20 25 (320-25) 25 ">> next" in
    b1#callback  (fun () -> wiz#next_page);
    let b2 = new fButton 20 55 (320-25) 25 "<< prev" in
    b2#callback  (fun () -> wiz#prev_page);
    let w = new fWidget 10 100 300 90 "" in
    w#set_color col;
    w#set_label text;
    g#wend;
;;

let win = new fWindow ~x:1 ~y:500 320 200  "hehe" in
let stat = new easyStatusBar in
stat#child_box SBAR_RIGHT Box.thin_down_box; 
stat#print "Hi, wie geht's?";
win#begin_add;
(*let down = new fButton ~btyp:RadioButton 50 60 50 20 "" in*)
let radio = ref "" in
let down = new myRadio 50 60 50 20 "radio" radio "Mensch!" in
let up = new fButton ~btyp:CheckButton 150 60 50 20 "up" in
let byby = new fButton ~btyp:RadioButton 250 60 50 20 "exit" in
let slider = new fSlider 10 35 300 20 "" in
let inp = new fValueInput 10 10 100 20 "" in
inp#range (-10.0) 10.0;
inp#set_step 1.0;
slider#range (-10.0) 10.0;
slider#set_step 1.0;
slider#set_value 0.0;
slider#callback (fun () -> inp#set_value slider#get_value);
down#callback (fun () ->
    printf "downvalue: %b\n%!" down#value;
    slider#set_value_check (slider#get_value -. 1.0);
    inp#set_value slider#get_value);
up#callback (fun () ->
    printf "radio: %s\n%!" !radio;
    slider#set_value_check (slider#get_value +. 1.0);
    inp#set_value slider#get_value);
byby#callback (fun () -> win#hide);    
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();

