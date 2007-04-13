open Widgets;;
open Ask;;


let _ =
	let window = new fWindow 200 55 "" in
	let b = new fButton 20 10 160 35 "test text" in
	b#callback (fun () -> 
		match input "Input:" "%s" with
		| None -> ()
		| Some t -> b#set_label t; b#redraw
		);
	window#resizable b;
	window#show;
	window#callback (fun () -> if ask "Aufhoehren?" = 1 then exit 0);
	Run.run ()
;;
