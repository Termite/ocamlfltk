open Printf;;
open Ofltk;;

open Draw;;

class shape_widget handle_roller x y w h title = object(self)
    inherit fWidget x y w h title
    val pi = 4.0 *. (atan 1.0)
    val mutable _sides = 3
    method sides = _sides
    method set_sides n = if n <> _sides then
        begin
            _sides <- n;
            self#redraw
        end
           
    method handle e =
        if e = Event.MOUSEWHEEL then handle_roller e else Event.NO_EVENT

    method draw =
        setcolor Color.black;
        let w = self#width in
        let h = self#height in
        fillrect 0 0 w h;
        push_matrix ();
        scale_xy (float w /. 2.0) (float h /. 2.0);
        translate_i 1 1;
        setcolor 0x8098b000l;
        let f = 2.0 *. pi /. (float _sides) in
        for i=0 to _sides do
            let ang = float i *. f in
            addvertex_f (cos ang) (sin ang)
        done;
        fillstrokepath Color.white;
        pop_matrix ();
        setfont self#labelfont self#labelsize;
        setcolor Color.white;        
        let s = float _sides in
        let ang = 2.0 *. pi /. s in
        let txt = sprintf "%d sides\nAngle between sides = %g\nLength of side = %g\nPerimeter = %g\nArea = %g" _sides
            (360.0 /. s)
            (sqrt (2.0 -. 2.0 *. (cos ang)))
            (s *. (sqrt (2.0 -. 2.0 *. (cos ang))))
            (s *. (sin ang) /. 2.0)
        in
        drawtext_rect txt 0 0 w h Flags.align_wrap
end;;



let win = new fWindow ~x:0 ~y:0 300 330  "hehe" in
let sl = new fSlider 50 285 (win#width - 60) 30 "Sides:" in
let sw = new shape_widget sl#handle 10 10 270 270 "" in
win#resizable sw;
let stat = new easyStatusBar in
stat#child_box SBAR_RIGHT Box.thin_down_box; 
stat#print "Hi, wie geht's?";
win#begin_add;
sl#clr_flags [Flags.align_mask];
sl#set_flags [Flags.align_left];
sl#set_value (float sw#sides);
sl#set_step 1.0;
sl#range 3.0 40.0;
sl#callback (fun () -> sw#set_sides (int_of_float sl#get_value);
        stat#format_text SBAR_RIGHT "%d sides" sw#sides
    );

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();

