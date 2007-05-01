open Printf;;
open Widgets;;
open Symbol;;

let w = 150;;
let h = 50;;
let rows = 6;;


let bt = 
	let n = ref 0 in
	fun ?box ?(square=false) name ->
        let x = (!n mod 4) * w + 10 in
        let y = (!n / 4) * h + 10 in
        incr n;
        let b = new invisible ?box x y (if square then h - 20 else w - 20) (h - 20) name in
        b#set_labelsize 11.0;
	if square then (
		b#clr_flags [Flags.align_mask];
		b#set_flags [Flags.align_right]		
	);
	b
;;



let win = new window (4 * w) (rows * h) "Box Demo" in
win#set_color 12l;
print_endline "all symbols:";
Symbol.iter_symbol(fun s -> print_endline (get_name s));

bt ~box:Box.no_box "no_box";
bt ~box:Box.flat_box "flat_box";
bt ~box:Box.up_box "up_box";
bt ~box:Box.down_box "down_box";
bt ~box:Box.thin_up_box "thin_up_box";
bt ~box:Box.thin_down_box "thin_down_box";
bt ~box:Box.engraved_box "engraved_box";
bt ~box:Box.embossed_box "embossed_box";
bt ~box:Box.round_up_box "round_up_box";
bt ~box:Box.round_down_box "round_down_box";
bt ~box:Box.diamond_up_box "diamond_up_box";
bt ~box:Box.diamond_down_box "diamond_down_box";
bt ~box:Box.border_box "border_box";
bt ~box:Box.rounded_box "rounded_box";
bt ~box:Box.rshadow_box "rshadow_box";
bt ~box:Box.rflat_box "rflat_box";
bt ~box:Box.shadow_box "shadow_box";
bt ~box:Box.oval_box "oval box";
bt ~box:Box.oshadow_box "oshadow box";
bt ~box:Box.oflat_box "oflat box";
bt ~box:Box.focus_frame "focus frame";
bt ~box:Box.border_frame "border frame";
(bt ~box:Box.plastic_up_box "plastik_up_box")#set_color 12l;
(bt ~box:Box.plastic_down_box "plastik_down_box")#set_color 12l;



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
Run.run();
Gc.full_major();

