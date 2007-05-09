open Widgets;;
open Printf;;

let toggle_cb inputs but fl () =
    if but#value then but#set_when [fl] else but#clr_when [fl];
    let when_flags = but#get_when in
    List.iter (fun i -> i#set_when when_flags) inputs
;;

let color_cb but n () =
    let s = Input.default_style in
    let c = match n with
        | 0 -> Style.get_color s
        | 1 -> Style.get_selection_color s
        | _ -> Style.get_textcolor s
    in
    let c = Color.show_colormap c in
    (match n with
         | 0 -> Style.set_color s c 
         | 1 -> Style.set_selection_color s c
         | _ -> Style.set_textcolor s c);
    but#set_color c;
    but#set_labelcolor (Color.contrast Color.black c);
    redraw()
;;


let _ =
    let cb w () = printf "Callback for %s '%s'\n%!" w#label w#get_text in

    let window = new window 400 (350 + 105) "" in
    let inputs =
        List.map (fun (make, y, l, tt) ->
            let w = (make 70 y 300 23 l :> input) in
            w#configure ~cb:(cb w) ~tooltip:tt ~when_flags:[WhenNever] (); w) [
            new input, 10, "Normal", "Normal intput field";
            new floatInput, 37, "Float", "Input field for floating point";
            new intInput, 64, "Int", "Input field for integer input";
            new secretInput, (10+3*27), "Secret", "Input field for password";
            new wordwrapInput, (10+4*27), "Wordwrap", "Inputfield for *short* text"
            ]
    in
    let editor = new Text.textEditor 70 (10+4*27+105) 300 100 "TextEditor" in
    editor#wrap_mode true;
    editor#configure
        ~when_flags:[WhenNever]
        ~cb:(fun () ->printf "Callback for %s '%s'\n%!" editor#label editor#get_text)
        ~tooltip:"Texteditor for editing small programs and email"
        ()
        ;
    resizable window editor;

    let y = 10 + 4 * 27 + 210 in
    let buttons = List.map (fun (y, label, tt, wf) ->
        let b = new toggleButton 10 y 200 23 label in
        b#set_tooltip tt; b#callback (toggle_cb inputs b wf);
        b) [y, "WHEN_&CHANGED", "do callback each time the text changes", WhenChanged;
            y+23, "WHEN_&RELEASE", "do callback when widget loses focus", WhenRelease;
            y+46, "WHEN_&ENTER_KEY", "do callback when user hits enter", WhenEnterKey;
            y+69, "WHEN_&NOT_CHANGED", "do callback even if not changed", WhenNotChanged
            ]
    in

    let b = new button 10 (y+92+5) 200 23 "&print changed" in
    let buf = ref (Text.TextBuffer.make_textbuffer 0) in
    b#configure ~tooltip:"Switch Textbuffer / Print widget that have changed() flag set"
                ~cb:(fun () -> 
                    let b = editor#get_buffer in
                    editor#set_buffer !buf;
                    buf := b;
                    redraw;
                    List.iter (fun i ->
                        if i#has_changed then (
                            i#clear_changed;
                            printf "%s '%s'\n%!" i#label i#get_text)
                        ) inputs) ();
                 
    let i = List.hd inputs in                        
    let b = new button 220 y 100 23 "color" in
    b#configure ~tooltip:"Color behind the text"
                ~color:(i#get_color)
                ~cb:(color_cb b 0) ();
    b#set_labelcolor (Color.contrast Color.black b#get_color);                
    let b1 = new button 220 (y+23) 100 23 "selection_color" in
    b1#configure ~tooltip:"Color behind selected text"
                ~color:(i#get_selection_color)
                ~cb:(color_cb b1 1) ();
    b1#set_labelcolor (Color.contrast Color.black b1#get_color);                
    let b2 =  new button 220 (y+46) 100 23 "textcolor" in
    b2#configure ~tooltip:"Color of the text"
                ~color:(i#get_textcolor)
                ~cb:(color_cb b2 2) ();
    b2#set_labelcolor (Color.contrast Color.black b2#get_color);                
    
    window#wend;
    window#show;
    Run.run()

