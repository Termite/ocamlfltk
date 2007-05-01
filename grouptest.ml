open Widgets;;


let win = new window 300 200 "test" in
groupSetCurrent None;
let c = groupGetCurrent() in
(match c with
| None -> print_endline "keine Gruppe!" 
| Some g -> g#add (new button 1 1 40 20 "hi"));
groupSetCurrent (Some win);
let b1 = new button 10 20 40 24 "zwo" in
win#wend;
let b2 = new button 10 40 30 20 "drei" in
b1#callback (fun () -> win#replace_with b1 b2);
b2#callback (fun () -> let idx = win#find b2 in win#replace idx b1);
win#show;
Run.run();
print_endline "fertig"
