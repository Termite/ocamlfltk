open Printf;;
open Widgets;;

class myButton x y w h t = object(self)
    inherit button x y w h t as chef
    method draw = print_endline "myButton Draw"; chef#draw
end;; 

class myWin w h t = object(self)
    inherit window w h t as chef
    method draw = print_endline "nix..."; chef#draw
end;;

class myRadio x y w h t var value = object(self)
    inherit radioButton x y w h t as chef
    method callback fkt = chef#callback (fun () -> var := value; fkt ())
end;;
        
external inspect: 'a -> unit = "inspect_block";;

let win = new window ~x:1 ~y:500 320 200  "hehe" in
let stat = new easyStatusBar 24  in
stat#child_box SBAR_RIGHT Box.thin_down_box; 
stat#print "Hi, wie geht's?";
win#begin_add;
let radio = ref "" in
let down = new myRadio 50 60 50 20 "radio" radio "Mensch!" in
let up = new checkButton 150 60 50 20 "up" in
let byby = new radioButton 250 60 50 20 "exit" in
let slider = new slider 10 35 300 20 "" in
let inp = new valueInput 10 10 100 20 "" in
inp#range (-10.0) 10.0;
inp#set_step 1.0;
inp#callback (fun () -> slider#set_value (inp#get_value));
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
Run.run();

