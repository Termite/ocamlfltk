open Ofltk;;
open Symbol;;

let folder_small3 = [|
"20 16 34 1";
" 	c None";
".	c #A68A5E";
"+	c #FEF3A7";
"@	c #FEECA1";
"#	c #FEE49A";
"$	c #FEDD94";
"%	c #FED68E";
"&	c #FEF6A9";
"*	c #FEEEA3";
"=	c #FEE79D";
"-	c #FEDF96";
";	c #FED890";
">	c #FEF1A5";
",	c #FEE99F";
"'	c #FEE298";
")	c #FEDA92";
"!	c #FEF0A5";
"~	c #FEEBA1";
"{	c #FEE69C";
"]	c #FEE198";
"^	c #FEDC93";
"/	c #FED78F";
"(	c #54452F";
"_	c #FEF2A6";
":	c #FEEDA2";
"<	c #FEE299";
"[	c #FEE99E";
"}	c #FEDE95";
"|	c #FED991";
"1	c #FEEFA4";
"2	c #FEEA9F";
"3	c #FEE59B";
"4	c #FEE096";
"5	c #FEDB92";
"                    ";
"          .....     ";
"         .+@#$%.    ";
"   ......&*=-;%%.   ";
"   .&&&&&>,')%%%.   ";
"   .&&&&+@#$%%%%.   ";
"   .&&............  ";
"   .&&.&!~{]^/%%%.( ";
"   .&&._:=<$;%%%%.( ";
"   .&.+*[#}|%%%%.(  ";
"   .&.12345%%%%%.(  ";
"    .!~{]^/%%%%.(   ";
"    ............(   ";
"    ((((((((((((    ";
"                    ";
"                    "
|];;

let folder_small2 = [|
"20 16 44 1";
" 	c None";
".	c #A68A5E";
"+	c #54452F";
"@	c #FEE89E";
"#	c #FEE59B";
"$	c #FEE298";
"%	c #FEDE95";
"&	c #FEDB93";
"*	c #CEAB75";
"=	c #FEF6A9";
"-	c #FEF2A7";
";	c #FEEFA4";
">	c #FEECA1";
",	c #FEE99E";
"'	c #FEE69C";
")	c #FEE399";
"!	c #FEDF96";
"~	c #FEDC93";
"{	c #FED991";
"]	c #FED68E";
"^	c #FEF3A7";
"/	c #FEF0A4";
"(	c #FEEDA2";
"_	c #FEE99F";
":	c #FEE097";
"<	c #FEDD94";
"[	c #FEDA91";
"}	c #FED78E";
"|	c #FEF0A5";
"1	c #FEEA9F";
"2	c #FEE79D";
"3	c #FEE49A";
"4	c #FEE197";
"5	c #FEDA92";
"6	c #FED78F";
"7	c #FEEEA3";
"8	c #FEEAA0";
"9	c #FEE198";
"0	c #FEDB92";
"a	c #FED88F";
"b	c #FEEBA0";
"c	c #FED890";
"d	c #FEE299";
"e	c #FED990";
"                    ";
"          .....+    ";
"         .@#$%&.+   ";
"   ......*******.   ";
"   .=-;>,')!~{]].+  ";
"   .^/(_'):<[}]].+  ";
"   .|(1234<56]]].+  ";
"   .78239%0a]]]].+  ";
"   .b@#$%&c]]]]].+  ";
"   .@#d!~e]]]]]].+  ";
"   .')!~{]]]]]]].+  ";
"   .):<[}]]]]]]].+  ";
"   ..............+  ";
"    ++++++++++++++  ";
"                    ";
"                    "
|];;

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

let folder_small = [|
"16 16 23 1";
" 	c None";
".	c #000000000000";
"X	c #FFFFFFFFFFFF";
"o	c #CF3CCF3CCF3C";
"O	c #FFFF9A699A69";
"+	c #EFBEEFBEEFBE";
"@	c #FFFFFFFF9A69";
"#	c #FFFFFFFFCF3C";
"$	c #CF3CCF3C30C2";
"%	c #CF3C9A6930C2";
"&	c #9A699A696595";
"*	c #FFFFCF3CCF3C";
"=	c #FFFFFFFF30C2";
"-	c #DF7DDF7DDF7D";
";	c #FFFFCF3C6595";
":	c #9A6965956595";
">	c #FFFFCF3C30C2";
",	c #FFFFFFFF6595";
"<	c #FFFFFFFF0000";
"1	c #9A699A699A69";
"2	c #75D675D675D6";
"3	c #208120812081";
"4	c #659565956595";
"   .. ..        ";
"   .X..o..      ";
".. .XXX..O..... ";
".+..@#XXX..$%%. ";
".+++..@##XX..&O.";
" .*=**..-@#XX.%.";
" .*;**+;..:@#.& ";
" .*;>o*;;o..@.& ";
"  .**+*o*o*.@.. ";
"  .**;*o**o.,.  ";
"   .;>;;;;;.<.  ";
"   .;;;;;;;%..1 ";
"    ..;;;>;;..22";
"      ..;;;>.32 ";
"        ..;;.4  ";
"          ...   "
|];;

let file_xpm = make_xpmimage ~name:"Bildchen" file_small2 in
let high_xpm = make_highlightbox "Bildchen" file_xpm in

let fold1 = make_xpmimage folder_small in
let fold2 = make_xpmimage folder_small2 in
let fold3 = make_xpmimage folder_small3 in

let push_release_img = make_multiimage fold2 in
add_to_multiimage push_release_img [ Flags.pushed, fold3 ];

let push_release_hlt_i = make_multiimage fold2 in
add_to_multiimage push_release_hlt_i [ Flags.highlight, fold1; Flags.pushed, fold3];

let win = new fWindow ~x:1 ~y:500 320 200  "hehe" in
let up = new fButton 150 60 50 31 "push/release img" in
up#set_image push_release_hlt_i;

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();





