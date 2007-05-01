open Printf;;
open Widgets;;
open Draw;;

let dargs = [| 90.0; 90.0; 100.0; 100.0; 0.0; 360.0; 0.0 |];;
let name = [| "X"; "Y"; "W"; "H"; "start"; "end"; "rotate" |];;

class drawing x y w h = object(self)
    inherit widget x y w h ""
    method draw =
        let w = self#w in
        let h = self#h in
        push_clip 0 0 w h;
        setcolor_alpha Color.blue 0.6;
        fillrect 0 0 w h;
        push_matrix ();
        translate_f (float w /. 2.0) (float h /. 2.0);
        rotate dargs.(6);
        translate_f (float w /. -2.0) (float h /. -2.0);
        addarc dargs.(0) dargs.(1) dargs.(2) dargs.(3) dargs.(4) dargs.(5);
        closepath ();
        addarc 120.0 120.0 40.0 40.0 0.0 (-360.0);
        setcolor_alpha Color.gray33 0.6;
        fillstrokepath Color.white;
        setcolor Color.gray33;
        addchord 20 20 (int_of_float dargs.(2) + 1) (int_of_float dargs.(3) + 1) 
            dargs.(4) dargs.(5);
        fillstrokepath Color.white;
        pop_matrix ();
        setcolor_alpha Color.gray40 0.6;
        fillrect 10 (270 - (int_of_float dargs.(3))) (int_of_float dargs.(2)) (int_of_float dargs.(3));
        setcolor Color.gray90;
        strokerect 10 (- int_of_float dargs.(3) + 270) (int_of_float dargs.(2)) (int_of_float dargs.(3));
        setcolor_alpha Color.red 0.6;
        addchord  10 (- int_of_float dargs.(3) + 270) (int_of_float dargs.(2)) (int_of_float dargs.(3)) dargs.(4) dargs.(5);
        fillstrokepath Color.gray90;
        pop_clip ()
end;;        

        



let _ =
    let window = new window 300 510 "Arc" in
    (* window#border false; *)
    window#begin_add;
    let drawing = new drawing 10 10 280 280 in
    let y = ref 300 in
    for n=0 to 6 do
        let s = new valueSlider 50 !y 240 25 name.(n) in
        y := !y + 30;
        let a, b = if n < 4 then (0.0, 300.0)
        else if n = 6 then ( 0.0, 360.0)
        else ( -360.0, 360.0 ) in
        s#set_min a;
        s#set_max b;
        s#set_type Slider.tick_above; 
        s#set_step 1.0;
        s#set_value dargs.(n);
        s#clr_flags [Flags.align_mask];
        s#set_flags [Flags.align_left];
        s#callback (fun () ->
            dargs.(n) <- s#get_value;
            drawing#redraw);
    done;
    window#wend;
    window#resizable drawing;
    window#show;
    Gc.full_major ();
    Run.run ()
;;

