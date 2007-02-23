open Printf;;
open Ofltk;;


type _item = I of string * (unit -> unit) option | Divider
           | Sub of (string * _item list) list

let rec make_menu groups = 
    List.iter (fun (name,items) ->
        let g = new fItemGroup name in
        g#begin_add;
        List.iter (fun menuitem -> match menuitem with
        | Sub(sub_items) -> make_menu sub_items
        | Divider -> ignore (new fDivider)
        | I(item,cb) ->
            let i = new fItem item in
            (match cb with
            | None -> ()
            | Some cb -> i#callback cb);
            ()) items;
        g#wend) groups
;;
       

let win = new fWindow ~x:0 ~y:0 600 400  "Pack Demo" in
let bar = new fMenuBar 0 0 600 23 "" in
bar#begin_add;
make_menu [
    "&File", [ I("&Load", None);
    Divider;
    Sub(["&Edit", [ I("Cut", None);
                    I("Paste", None) ]]);
    I("&Save", Some(fun() -> print_endline "Save!")) ];
    
];

bar#wend;
let pop = new fPopupMenu 180 50 100 25 "&PopupMenu" in
pop#begin_add;
make_menu [
    "&File", [ I("&Load", None);
    Divider;
    Sub(["&Edit", [ I("Cut", None);
                    I("Paste", None) ]]);
    I("&Save", Some(fun() -> print_endline "Save!")) ];
    
];
pop#wend;
let ch = new fChoice 180 90 100 25 "&choice" in
ch#begin_add;
make_menu [
    "&File", [ I("&Load", None);
    Divider;
    Sub(["&Edit", [ I("Cut", None);
                    I("Paste", None) ]]);
    I("&Save", Some(fun() -> print_endline "Save!")) ];
    
];
ch#wend;
let cy = new fCycleButton 110 130 100 25 "cycle" in
cy#begin_add;
let i1 = new fItem "cycle 1" in
let i2 = new fItem "teil 2" in
let i3 = new fItem "last" in
cy#wend;



win#wend;
Gc.full_major();
win#show;
Gc.full_major();
run();
Gc.full_major();

