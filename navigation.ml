open Printf;;
open Widgets;;

exception Break;;

let populate (window : fWindow) height width =
(*    let log = Scanf.Scanning.from_file "log" in*)
    let grid = 25 in
    let m_y = height / grid + 1 in
    let m_x = width / grid + 1 in
    for i=0 to 9999 do
(*        let x = (Scanf.bscanf log "%d\n" (fun n -> n)) in*)
(*        let y = (Scanf.bscanf log "%d\n" (fun n -> n)) in*)
(*        let w = (Scanf.bscanf log "%d\n" (fun n -> n)) in*)
(*        let h = (Scanf.bscanf log "%d\n" (fun n -> n)) in*)
        let x = Random.bits() mod m_x * grid in
        let y = Random.bits() mod m_y * grid in
        let w = Random.bits() mod m_x * grid in
        let h = Random.bits() mod m_y * grid in
        let w, x = if w < x then x-w, w else w-x, x in
        let h, y = if h < y then y-h, h else h-y, y in
        if not (w < grid || h < grid || w < h) then begin
            try
                let o = window#fold_childs (fun e o ->
                    if x < o#x + o#w && x + w > o#x &&
                       y < o#y + o#h && y + h > o#y
                    then 
                       raise Break
                    else if e == None && (y < o#y || y = o#y && x < o#x) then
                        (
                            Some o
                        ) else None ) None
                in
                let inp = new fInput x y w h "" in
                window#insert_before inp o 
            with
            | Break -> ()
        end;
    done;
;;

let _ =
    Random.self_init ();
    let width = 600 and height = 300 in
    let window = new fWindow width height Sys.argv.(0) in
    window#wend;
    populate window height width;
    window#resizable window;
    if Array.length Sys.argv < 2 then window#show;
    Run.run ();

