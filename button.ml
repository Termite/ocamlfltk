open Widgets;;
open Symbol;;
open Printf;;

let chk = ref 0;;

let check () =
	incr chk;
	printf "hi %d\n%!" !chk
;;


let imageDir = if Array.length Sys.argv > 1 then
                Sys.argv.(1)
               else
                "../../fltk-2.0.x-r5750/test/images/";;

let _ =
    register_images ();
    print_endline imageDir;
    let window = new window 320 65 "" in
    let ib = new group ~x:0 ~y:0 320 65 "" in
    ib#set_image (make_tiledimage (SharedImage.get (imageDir ^ "bg.jpeg")));
    window#resizable ib;
    let b1 = new button 20 20 80 25 "&Beep" in
    b1#callback (fun () -> print_char '\007');
    let b2 = new button 120 20 80 25 "" in
    b2#set_image (make_tiledimage (SharedImage.get (imageDir ^ "coucou.png")));
    let b3 = new button 220 20 80 25 "E&xit" in
    b3#callback (fun () -> window#hide);
    ib#wend;
    window#wend;
    window#show;
    Run.run()
;;




