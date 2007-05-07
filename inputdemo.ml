open Widgets;;
open Printf;;


let _ =
    let cb w () = printf "Callback for %s '%s'\n%!" w#label w#get_text in
    let window = new window 400 (350 + 105) "" in
    let inputs = List.map (fun ((w:input),t) ->
                 w#configure ~cb:(cb w) ~tooltip:t ~when_flags:[WhenNever] (); w)
            [
            new input 70 10 300 23 "Normal", "Normal input field";
            (new floatInput 70 (10+27) 300 23 "Float" :> input), "Input field for floating points";
            (new intInput 70 (10+2*27) 300 23 "Int" :> input), "Input field for integers";
            new secretInput 70 (10+3*27) 300 23 "Secret", "Input field for password";
            new wordwrapInput 70 (10+4*27) 300 100 "Wordwrap", "Inputfield for *short* text"
            ]
    in
    let editor = new wordwrapInput 70 (10+4*27+105) 300 100 "TextEditor" in
    editor#configure
        ~when_flags:[WhenNever]
        ~cb:(fun () ->printf "Callback for %s '%s'\n%!" editor#label editor#get_text)
        ~tooltip:"Texteditor for editing small programs and email"
        ()
        ;
    window#resizable editor;

    let toggle_cb but fl () =
        if but#value then but#set_when [fl] else but#clr_when [fl];
        let when_flags = but#get_when in
        List.iter (fun i -> i#set_when when_flags) inputs
    in

    let y = 10 + 4 * 27 + 210 in
    let buttons = List.map (fun (y, label, tt, wf) ->
        let b = new toggleButton 10 y 200 23 label in
        b#set_tooltip tt; b#callback (toggle_cb b wf);
        b) [y, "WHEN_&CHANGED", "do callback each time the text changes", WhenChanged;
            y+23, "WHEN_&RELEASE", "do callback when widget loses focus", WhenRelease;
            y+46, "WHEN_&ENTER_KEY", "do callback when user hits enter", WhenEnterKey;
            y+69, "WHEN_&NOT_CHANGED", "do callback even if not changed", WhenNotChanged
            ]
    in

    let b = new button 10 (y+69+5) 200 23 "&print changed" in
    b#configure ~tooltip:"Print widget that have changed() flag set"
                ~cb:(fun () -> List.iter (fun i ->
                        if i#has_changed then (
                            i#clear_changed;
                            printf "%s '%s'\n%!" i#label i#get_text)
                        ) inputs) ();



    
    window#wend;
    window#show;
    Run.run()

