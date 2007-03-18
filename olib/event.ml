
type event_type =
   NO_EVENT| PUSH| RELEASE| ENTER| LEAVE| DRAG| FOCUS| UNFOCUS| 
   KEY| KEYUP| FOCUS_CHANGE| MOVE| SHORTCUT| DEACTIVATE| ACTIVATE| HIDE| 
   SHOW| PASTE| TIMEOUT| MOUSEWHEEL| DND_ENTER| DND_DRAG| DND_LEAVE| DND_RELEASE| 
   TOOLTIP
;;

module Keys = struct
    let leftButton	= 1;;
    let middleButton	= 2;;
    let rightButton	= 3;;
    let spaceKey	= 32;;
  (* 'a'-'z' *)
    let backSpaceKey	= 0xff08;;
    let tabKey	= 0xff09;;
    let clearKey	= 0xff0b;;
    let returnKey	= 0xff0d;;
    let pauseKey	= 0xff13;;
    let scrollLockKey	= 0xff14;;
    let escapeKey	= 0xff1b;;
    let homeKey	= 0xff50;;
    let leftKey	= 0xff51;;
    let upKey		= 0xff52;;
    let rightKey	= 0xff53;;
    let downKey	= 0xff54;;
    let pageUpKey	= 0xff55;;
    let pageDownKey	= 0xff56;;
    let endKey	= 0xff57;;
    let printKey	= 0xff61;;
    let insertKey	= 0xff63;;
    let menuKey	= 0xff67;;
    let helpKey	= 0xff68;;
    let numLockKey	= 0xff7f;;
    let keypad	= 0xff80;;
    let keypadEnter	= keypad+(int_of_char '\r');;
    let multiplyKey	= keypad+(int_of_char '*');;
    let addKey	= keypad+(int_of_char '+');;
    let subtractKey	= keypad+(int_of_char '-');;
    let decimalKey	= keypad+(int_of_char '.');;
    let divideKey	= keypad+(int_of_char '/');;
    let keypad0	= keypad+(int_of_char '0');;
    let keypad1	= keypad+(int_of_char '1');;
    let keypad2	= keypad+(int_of_char '2');;
    let keypad3	= keypad+(int_of_char '3');;
    let keypad4	= keypad+(int_of_char '4');;
    let keypad5	= keypad+(int_of_char '5');;
    let keypad6	= keypad+(int_of_char '6');;
    let keypad7	= keypad+(int_of_char '7');;
    let keypad8	= keypad+(int_of_char '8');;
    let keypad9	= keypad+(int_of_char '9');;
    let keypadLast	= 0xffbd;;
    let f0Key		= 0xffbd;;
    let f1Key		= f0Key+1;;
    let f2Key		= f0Key+2;;
    let f3Key		= f0Key+3;;
    let f4Key		= f0Key+4;;
    let f5Key		= f0Key+5;;
    let f6Key		= f0Key+6;;
    let f7Key		= f0Key+7;;
    let f8Key		= f0Key+8;;
    let f9Key		= f0Key+9;;
    let f10Key	= f0Key+10;;
    let f11Key	= f0Key+11;;
    let f12Key	= f0Key+12;;
    (* use f0Key+n to get function key n *)
    let lastFunctionKey = f0Key+35;;
    let leftShiftKey	= 0xffe1;;
    let rightShiftKey	= 0xffe2;;
    let leftCtrlKey	= 0xffe3;;
    let rightCtrlKey	= 0xffe4;;
    let capsLockKey	= 0xffe5;;
    let leftMetaKey	= 0xffe7;;
    let rightMetaKey	= 0xffe8;;
    let leftAltKey	= 0xffe9;;
    let rightAltKey	= 0xffea;;
    let deleteKey	= 0xffff;;

    external get_special: unit -> int*int*int*int = "get_special_keys";;

    let leftAccKey, rightAccKey, leftCmdKey, rightCmdKey = get_special();; 

end;;


external event_dy: unit -> int = "event_dy";;
external event_button: unit -> int = "event_button";;
external set_event_clicks: int -> unit = "event_set_clicks";;
external get_event_clicks: unit -> int = "event_get_clicks";;
external event_is_click: unit -> bool = "event_is_click";;
external event_set_is_click: bool -> unit = "event_set_is_click";;
external event_clicks: unit -> int = "event_clicks";;
external event_key: unit -> int = "event_key";;




