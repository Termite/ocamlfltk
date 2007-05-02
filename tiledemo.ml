open Widgets;;
open Printf;;

let align_clip = [Flags.align_clip] in

let window = new window 320 320 "" in
window#resizable window;

let tile = new tiledGroup 10 10 300 300 "" in
tile#begin_add;

let box0 = new group 150 150 "0" in
box0#configure ~box:Box.down_box ~labelsize:36.0 ~flags:align_clip ~color:9l ();
box0#wend;

let w1 = new window ~x:150 ~y:0 150 150 "1" in
let box1 = new widget 0 0 150 150 "1\nThis is a \nchild\nX window" in
box1#configure ~box:Box.down_box ~labelsize:18.0 ~flags:align_clip ~color:19l ();

w1#resizable box1;
w1#wend;

let box2a = new widget 0 150 70 150 "2a" in
box2a#configure ~box:Box.down_box ~color:12l ~labelsize:36.0 ~flags:align_clip (); 
let box2b = new widget 70 150 80 150 "2b" in
box2b#configure ~box:Box.down_box ~color:13l ~labelsize:36.0 ~flags:align_clip (); 

let box3a = new widget 150 150 150 70 "3a" in
box3a#configure ~box:Box.down_box ~color:12l ~labelsize:36.0 ~flags:align_clip (); 
let box3b = new widget 150 (150+70) 150 80 "3b" in
box3b#configure ~box:Box.down_box ~color:13l ~labelsize:36.0 ~flags:align_clip (); 

let r = new widget 10 0 290 290 "" in
r#hide;
tile#resizable r;
tile#wend;
window#wend;
window#show;
Run.run()

