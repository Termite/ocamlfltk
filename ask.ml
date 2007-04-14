open Widgets;;
open Dialogs;;


let _ =
    set_ok "na gut";
    message "Jallo %s" "micha";
    let c = choice "eins" "zwei" "drei" "waehl mal.." in
    Printf.printf "gezogen: %d\n%!" c;
	let window = new fWindow 200 55 "" in
	let b = new fButton 20 10 160 35 "test text" in
	b#callback (fun () -> 
		match input b#label "new label:" with
		| None -> ()
		| Some t -> b#set_label t; b#redraw
		);
	window#resizable b;
	window#show;
	window#callback (fun () -> if ask "Aufhoehren?" = 1 then exit 0);
	Run.run ()
;;
