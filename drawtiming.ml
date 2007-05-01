open Widgets;;
open Draw;;
open Printf;;

class testWindow t = object(self)
    inherit window ~x:100 ~y:100 300 300 "Timing"
    val test = t
    val mutable iter = 1
    method draw =
        iter <- iter + 1;
        let b = Printf.sprintf "Redraw number %d, text in the widget is clipped
        off somewhere on the right" iter in
        let w = self#w and h = self#h in
        if test land 2 <> 0 then
            begin
            setcolor Color.gray75;
            fillrect 0 0 w h;
            let y = ref 10 in
            while !y + 21 < h do
                let x1 = 5 + !y / 10 in
                let y1 = !y in
                let w1 = w - 5 - x1 in
                let h1 = 21 in
                push_clip x1 y1 w1 h1;
                setcolor Color.black;
                fillrect x1 y1 w1 h1;
                if !y < 11 then begin
                    setcolor Color.white;
                    setfont Font.helvetica 12.0;
                    drawtext b (float (x1+3)) (float (y1+16))
                end;
                pop_clip ();
                y := !y + 25
            done;
            end
        else begin
            push_clip 0 0 w h;
            let y = ref 10 in
            while !y + 21 < h do
                let x1 = 5 + !y / 10 in
                let y1 = !y in
                let w1 = w - 5 - x1 in
                let h1 = 21 in
                push_clip x1 y1 w1 h1;
                setcolor Color.black;
                fillrect x1 y1 w1 h1;
                if !y < 11 then begin
                    setcolor Color.white;
                    setfont Font.helvetica 12.0;
                    drawtext b (float (x1+3)) (float (y1+16));
                end;
                pop_clip ();
                clipout x1 y1 w1 h1;
                y := !y + 25;
            done;
            setcolor Color.gray75;
            fillrect 0 0 w h;
            pop_clip()
            end

    initializer
        if t land 1 <> 0 then self#set_doublebuffer else self#clear_doublebuffer
        
end;;


let _ =
    let test = int_of_string Sys.argv.(1) in
    let iter = int_of_string Sys.argv.(2) in
    Printf.printf "Test %d, Iterations %d\n%!" test iter;
    let w = new testWindow test in
    let dt = Run.get_time_secs () in
    w#show;
    while w#damage <> 0 do
        ignore (Run.wait())
    done; 
    print_endline "gewartet";
    for i=0 to iter do
        w#redraw;
        ignore (Run.check())
    done;
    let dt = Run.get_time_secs () -. dt in
    printf "time elapsed = %4.6f secs\n%!" dt;


