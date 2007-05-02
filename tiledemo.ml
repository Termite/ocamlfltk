open Widgets;;
open Printf;;

let window = new window 320 320 "" in
window#resizable window;

let tile = new tiledGroup 10 10 300 300 "" in
tile#begin_add;

let box0 = new group 150 150 "0" in
box0#set_box Box.down_box;
box0#set_color 9l;
box0#set_labelsize 36.0;
box0#set_flags [Flags.align_clip];

box0#begin_add;
let but = new button 20 20 100 30 "Button" in
but#set_flags [Flags.align_clip];
box0#wend;

let w1 = new window ~x:150 ~y:0 150 150 "1" in
let box1 = new widget 0 0 150 150 "1\nThis is a \nchild\nX window" in
box1#set_box Box.down_box;
box1#set_color 19l;
box1#set_labelsize 18.0;
box1#set_flags [Flags.align_clip];
w1#resizable box1;
w1#wend;


let box2a = new widget 0 150 70 150 "2a" in
box2a#set_box Box.down_box;
box2a#set_color 12l;
box2a#set_labelsize 36.0;
box2a#set_flags [Flags.align_clip];
let box2b = new widget 70 150 80 150 "2b" in
box2b#set_box Box.down_box;
box2b#set_color 13l;
box2b#set_labelsize 36.0;
box2b#set_flags [Flags.align_clip];

let box3a = new widget 150 150 150 70 "3a" in
box3a#set_box Box.down_box;
box3a#set_color 12l;
box3a#set_labelsize 36.0;
box3a#set_flags [Flags.align_clip];
let box3b = new widget 150 (150+70) 150 80 "3b" in
box3b#set_box Box.down_box;
box3b#set_color 13l;
box3b#set_labelsize 36.0;
box3b#set_flags [Flags.align_clip];


let r = new widget 10 0 290 290 "" in
r#hide;
tile#resizable r;
tile#wend;
window#wend;
window#show;
Run.run()

