open Printf;;
open Ofltk;;
open Symbols

let w = 150;;
let h = 50;;
let rows = 6;;

let bt =
    let n = ref 0 in
    fun (name, box, square) ->
        let x = (!n mod 4) * w + 10 in
        let y = (!n / 4) * h + 10 in
        incr n;
        let b = new fInvisible x y (if square then h - 20 else w - 20) (h - 20) name in
        b#set_box box;
        b#set_labelsize 11.0;
;;



let win = new fWindow ~x:0 ~y:0 (4 * w) (rows * h) "Box Demo" in
win#set_color 12l;
print_endline "all symbols:";
Symbols.symbol_iter (fun s -> print_endline (get_name s));

List.iter bt [
    "up_box", Box.up_box, false;
    "oflat box", Box.oflat_box, false;
    "border box", Box.border_box, false;
    "thin-up box", Box.thin_up_box, false
];
(*
let box = iv#get_box in 
let w,h = measure box 100 30 in printf "size: %d, %d\n%!" w h;
ignore (get_name box);
printf "symbol name: %s\t\n%!" (get_name box);
*)
win#wend;

Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();

