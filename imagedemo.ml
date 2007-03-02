open Ofltk;;
open Symbol;;


let file_small2 = [|
    "15 18 5 1";
    " 	c None";
    ".	c #848484";
    "+	c #FFFFFF";
    "@	c #C6C6C6";
    "#	c #000000";
    "               ";
    " ..........    ";
    " .++++++++@.   ";
    " .+@......@+.  ";
    " .++++++++...# ";
    " .+@.......+@# ";
    " .++++++++++@# ";
    " .+@.......+@# ";
    " .++++++++++@# ";
    " .+@.......+@# ";
    " .++++++++++@# ";
    " .+@.......+@# ";
    " .++++++++++@# ";
    " .+@.......+@# ";
    " .++++++++++@# ";
    " .@@@@@@@@@@@# ";
    "  ############ ";
    "               "
|];;

let file_xpm = make_xpmimage ~name:"Bildchen" file_small2 in
let win = new fWindow ~x:1 ~y:500 320 200  "hehe" in
let up = new fButton 150 60 50 31 "up" in
up#set_image file_xpm;
win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();





