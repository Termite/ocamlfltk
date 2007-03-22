open Printf;;
open Ofltk;;


let map_childs fn group =
    let e = ref [] in
    for i=0 to group#children - 1 do
        e := (fn group#child i) :: !e
    done;
    !e
;;

let populate (window : fWindow) height width =
    let log = Scanf.Scanning.from_file "log" in
    let grid = 25 in
    let m_y = height / grid + 1 in
    let m_x = width / grid + 1 in
    let k = ref 0 in
    let cont = ref 0 in
    let inp = ref (new_input "" 0 0 10 10 "") in
    let in2 = ref (new fInput 0 0 10 10 "") in
    for i=0 to 9999 do
            let x = (Scanf.bscanf log "%d\n" (fun n -> n)) in
            let y = (Scanf.bscanf log "%d\n" (fun n -> n)) in
            let w = (Scanf.bscanf log "%d\n" (fun n -> n)) in
            let h = (Scanf.bscanf log "%d\n" (fun n -> n)) in
            let x = x mod m_x * grid in
            let y = y mod m_y * grid in
            let w = w mod m_x * grid in
            let h = h mod m_y * grid in
            (*
            Printf.printf "ran: %10d %10d %10d %10d\t" x y w h;
            Printf.printf "x %d y %d w %d h %d\n" x y w h;
            Printf.printf "x %d y %d w %d h %d\n" x y w h;
            let x = Random.bits() mod m_x * grid in
            let y = Random.bits() mod m_y * grid in
            let w = Random.bits() mod m_x * grid in
            let h = Random.bits()  mod m_y * grid in*)
            let w, x = if w < x then x-w, w else w-x, x in
            let h, y = if h < y then y-h, h else h-y, y in
            if not (w < grid || h < grid || w < h) then (
                    let j = ref None in
                    let n = ref 0 in
                    let go_on = ref true in 
                    while !n < window#children && !go_on = true do
                        let o = window#child !n in
                        if x < o#xpos + o#width && x + w > o#xpos &&
                           y < o#ypos + o#height && y + h > o#ypos
                        then (
                            (*printf "%d mal gesucht\n%!" n;*)
                            go_on := false;
                            decr n;
                        ) else (
                            cont := 0;
                            if !j == None && 
                                (y < o#ypos || y = o#ypos && x < o#xpos) then (
                                    j := Some o
                            )
                        );
                        incr n;
                    done;                                         
                    if !n >= window#children then (
                        incr k;
                        (*printf "continued: %d\n" !cont;*)
                        cont := 0;
(*                        inp := new_input "" 0 0 10 10 "";*)
                        in2 := new fInput x y w h "";

                        (*                    let s = Symbol.make_flatbox "box" in ()*)
                        (*printf "endcoord: %d ,%d k:%d\n%!" (x+w) (y+h) !k;*)
                        window#insert !in2 1;
                    )
            )
            else incr cont; 
    done;
    !in2, !k
;;

exception Break;;
let _ =
    Random.init 12345;
    let width = 600 and height = 300 in
    let window = new fWindow (1+width) (1+height) Sys.argv.(0) in
    window#wend;
    let inp, k = populate window height width in
    print_endline "done";
    window#resizable window;
    print_endline "done 1";
    print_endline "done 2";
    print_endline "done 3";
    Run.run ();
    printf "inp:%d, k: %d\n%!" inp#width k;
    print_endline "done 4";
            


