open Printf;;

let g = ref None;;

let fin_mon id v =
    printf "finalizing %d\n%!" id;
    g := Some v
;;

let m1 = Monitor.find 1 1 in
let (x,y,w,h) = Monitor.rect m1 in
printf "rect: %d,%d,%d,%d\n%!" x y w h;


for i=1 to 100  do
    let l = Monitor.list () in
    printf "register %d\n%!" i;
    let f = fin_mon i in
    Gc.finalise f l;
    Array.iter (fun a -> printf "dpi: %f\n%!" (Monitor.dpi_y a)) l;
    Gc.compact();
done
