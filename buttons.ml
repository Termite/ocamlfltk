open Widgets;;
open Symbol;;
open Printf;;

let w = 150;;
let h = 24;;
let b = 10;;
let x0 = b;;
let x1 = b + w + b;;

let active_cb but =
	fun () -> if but#active then (
			but#deactivate;
			but#set_label "Inactive")
		  else (
		  	but#activate;
			but#set_label "Active"
		  );
		  but#redraw
;;		  

let change_style =
	let style = ref false in
	fun () -> if !style then Style.reset_theme()
		  else (
		  	let ns = Style.buttonDefaultStyle in			
			Style.set_box ns Box.plastic_up_box;
			Style.set_color ns 220l;
			Style.set_highlight_color ns 3l
		  );
		  style := not !style;
		  redraw();
 ;;

	


let _ = 
    let fold1 = make_xpmimage Pixmaps.folder_small in
    let fold2 = make_xpmimage Pixmaps.folder_small2 in
    let fold3 = make_xpmimage Pixmaps.folder_small3 in
    (* segfault
    let ifold2= SharedImage.get "../fltk-2.0.x-r5782/test/images/testimg.jpg" in
    *)
    let ifold2 = make_xpmimage Pixmaps.folder_small2 in
    let push_release = make_multiimage ifold2 [(Flags.pushed, fold1)] in
    let push_release_hlt= make_multiimage fold2 
        [(Flags.highlight,fold1); (Flags.pushed, fold3)]
    in
    let window = new window (x1+w+b) (b+7*(h+b)) "" in
    let y = b in
    let b1 = new button x0 y w h "Button" in
    let rb = new returnButton x1 y w h "Flip Theme" in
    rb#callback change_style;
    rb#set_tooltip "Push Me!";
    let y = y + h + b in
    let tb = new toggleButton x0 y w h "ToggleButton" in
    let rb2= new radioButton x1 y w h "RadioButton" in
    let y = y + h + b in
    let tb2 = new repeatButton x0 y w h "RepeatButton" in
    let rb3 = new radioButton x1 y w h "RadioButton" in
    let y = y + h + b in
    let tb3 = new lightButton x0 y w h "LightButton" in
    let rb4 = new radioButton x1 y w h "RadioButton" in
    let y = y + h + b in
    let hb = new highlightButton x0 y w h "highlight Button" in
    let cb = new checkButton x1 y w h "CheckButton" in
    let y = y + h + b in
    let b2 = new button x0 y w h "push/release img" in
    b2#set_image push_release;
    let b3= new button x1 y w h "push/rel noborder" in
    b3#set_image push_release;
    b3#set_box Box.no_box;
    let y = y + h + b in
    let ab = new button x1 y w h "Inactive 2" in
    let multi = make_multiimage fold2 [ (Flags.pushed, to_box fold3); (Flags.inactive, to_box ifold2)] in
    ab#set_image multi;
    let hb2= new highlightButton x0 y w h "Everything !" in
    hb2#set_image push_release_hlt;
    hb2#callback (active_cb ab);


    window#resizable window;
    window#wend;
    window#show;
    Run.run()

