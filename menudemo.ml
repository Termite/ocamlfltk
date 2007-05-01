open Printf;;
open Widgets;;


type _item = I of string * (unit -> unit) option | Divider
           | Sub of (string * _item list) list

let rec make_menu groups = 
    List.iter (fun (name,items) ->
        let g = new itemGroup name in
        g#begin_add;
        List.iter (fun menuitem -> match menuitem with
        | Sub(sub_items) -> make_menu sub_items
        | Divider -> ignore (new divider)
        | I(item,cb) ->
            let i = new item item in
            (match cb with
            | None -> ()
            | Some cb -> i#callback cb);
            ()) items;
        g#wend) groups
;;
       

let demo_menu () =
    make_menu [
        "&File", [ I("&Load", None);
        Divider;
        Sub(["&Edit", [ I("Cut", None);
        I("Paste", None) ]])];

        "&Conf", [ I("&Save", Some(fun() -> print_endline "Save!"));
        I("&hier", None); I("dort", None)]

    ];;



let win = new window ~x:0 ~y:0 600 400  "Pack Demo" in
let bar = new menuBar 0 0 600 25 "" in
bar#begin_add;
demo_menu();
bar#wend;
let pop = new popupMenu 180 50 100 25 "&PopupMenu" in
pop#set_tooltip "das sollte ein Popup sein";
pop#begin_add;
demo_menu();
pop#wend;
let ch = new choice 180 90 100 25 "&choice" in
ch#set_tooltip "eine kleine Choice";
ch#begin_add;
demo_menu();
ch#wend;
let cy = new cycleButton 110 130 100 25 "cycle" in
cy#set_tooltip "was zum cyclen";
cy#begin_add;
let i1 = new item "cycle 1" in
let i2 = new item "teil 2" in
let i3 = new item "last" in
cy#wend;

print_endline ("cycle: " ^ cy#get_tooltip);

win#wend;
Gc.full_major();
win#show;
Gc.full_major();
Run.run();
Gc.full_major();

