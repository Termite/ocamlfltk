open Symbols;;
type box = [`Box] symb;;

external init_boxes: unit -> box array = "init_boxes";;

let boxes = init_boxes ();;

let up_box = boxes.(0);;
let down_box = boxes.(1);;
let thin_up_box = boxes.(2);;
let thin_down_box = boxes.(3);;
let engraved_box = boxes.(4);;
let embossed_box = boxes.(5);;
let border_box = boxes.(6);;
let flat_box = boxes.(7);;
let highlight_up_box = boxes.(8);;
let highlight_down_box = boxes.(9);;
let round_up_box = boxes.(10);;
let round_down_box = boxes.(11);;
let diamond_up_box = boxes.(12);;
let diamond_down_box = boxes.(13);;
let no_box = boxes.(14);;
let shadow_box = boxes.(15);;
let rounded_box = boxes.(16);;
let rshadow_box = boxes.(17);;
let rflat_box = boxes.(18);;
let oval_box = boxes.(19);;
let oshadow_box = boxes.(20);;
let oflat_box = boxes.(21);;
let border_frame = boxes.(22);;
let focus_frame = boxes.(23);;
let plastic_up_box = boxes.(24);;
let plastic_down_box = boxes.(25);;

