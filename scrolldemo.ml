open Printf;;
open Widgets;;
open Draw;;

class drawing x y w h l= object(self)
	inherit widget x y w h l
    val mpi = (4.0 *. (atan 1.0)) /. 10.0
	method draw =
         self#draw_box;
         push_matrix();         
         translate_i (self#w / 2) (self#h / 2);
         scale_xy (float self#w /. 2.0) (float self#h /. 2.0);
         setcolor Color.black;
         let fn  x = float x *. mpi +. 0.1 in
         for i=0 to 19 do
             for j = i + 1 to 19 do
                 newpath();
                 addvertex_f (cos (fn i)) (sin (fn i));
                 addvertex_f (cos (fn j)) (sin (fn j));
                 strokepath();
                 set_linestyle solid None;
             done;
         done;
         pop_matrix()

	initializer
		self#align Flags.align_top;
		self#set_box Box.flat_box;
		self#set_color Color.white
end;;


let align_cb sc new_typ =
    fun () -> sc#scrollbar_align new_typ;
    sc#relayout
;;

let choice_cb sc new_typ =
    fun () -> sc#scrolltype new_typ;
    sc#relayout
;;

let win = new window (5*75) 400  "ScrollGroup Demo" in
let sc = new scrollGroup 0 0 (5*75) 300 "" in
sc#begin_add;
let n = ref 1 in
for y=0 to 15 do
	for x = 0 to 4 do
		let b = new button (x*75) (y * 25 + (if y >= 8 then (5*75) else 0)) 75 25 "" in
		b#set_label (string_of_int !n);
		b#set_color (Int32.of_int !n);
		b#set_labelcolor Color.white;
		incr n;
	done;
done;
let drawing = new drawing 0 (8*25) (5*75) (5*75) "" in
sc#wend;
sc#scrolltype Vertical; 
sc#set_box Box.down_box;
win#resizable sc;
let but1 = new lightButton 150 310 200 25 "box" in
but1#callback (fun () ->
	sc#set_box (if but1#value then Box.down_box else Box.no_box);
	sc#relayout;
	sc#redraw);

let choice = new choice 150 335 200 25 "type():" in
choice#begin_add;
(new item "0")#callback (choice_cb sc NoScroll);
(new item "Horizontal")#callback (choice_cb sc Horizontal);
(new item "Vertical")#callback (choice_cb sc Vertical);
(new item "Both")#callback (choice_cb sc Both);
(new item "Horizontal_Always")#callback (choice_cb sc HorizontalAlways);
(new item "Vertical_Always")#callback (choice_cb sc VerticalAlways);
(new item "Both_Always")#callback (choice_cb sc BothAlways);
choice#wend;
choice#set_value 3;

let achoice = new choice 150 360 200 25 "scrollbar_align():" in
achoice#begin_add;
(new item "left+top")#callback (align_cb sc (Flags.align_left + Flags.align_top));
(new item "left+bottom")#callback (align_cb sc (Flags.align_left + Flags.align_bottom));
(new item "right+top")#callback (align_cb sc (Flags.align_right + Flags.align_top));
(new item "right+bottom")#callback (align_cb sc (Flags.align_right + Flags.align_bottom));
achoice#wend;
achoice#set_value 3;

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();
Gc.full_major();

