open Widgets;;

let _ =
    let window = new window 320 65 "Resize" in
    let b1 = new button 0 0 320 65 "Resize Me" in
    let cb =
        let f = ref true in
        fun () -> if !f then
                      ignore (b1#resize ~xy:(100,10) 190 35)
                  else
                      ignore (b1#resize ~xy:(0,0) 320 65);
                  f := not !f
    in
    let rec cb1 () = ignore (b1#resize ~xy:(100,10) 190 35); b1#callback cb2
    and cb2 () = ignore (b1#resize ~xy:(0,0) 320 65); b1#callback cb1 in
    b1#callback cb;
    window#wend;
    window#show;
    Run.run ()
;;

