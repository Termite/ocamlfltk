type font;;

external list: unit -> font array = "font_list";;
external font: string -> int -> font = "font";;
external name: font -> string = "font_name";;
external current_name: font -> string = "font_current_name";;
external system_name: font -> string = "font_system_name";;
external plus: font -> int -> font = "font_plus";;
external bold: font -> font = "font_bold";;
external italic: font -> font = "font_italic";;
external encodings: font -> string array = "font_encodings";;
external sizes: font -> int array = "font_sizes";;

external get_fonts: unit -> font array = "get_fonts";;

let f = get_fonts();;
let helvetica = f.(0);;
let helvetica_bold = f.(1);;
let helvetica_italic = f.(2);;
let helvetica_bold_italic = f.(3);;
let courier = f.(4);;
let courier_bold = f.(5);;
let courier_italic = f.(6);;
let courier_bold_italic = f.(7);;
let times = f.(8);;
let times_bold = f.(9);;
let times_italic = f.(10);;
let times_bold_italic = f.(11);;
let symbol_font = f.(12);;
let screen_font = f.(13);;
let screen_bold_font = f.(14);;
let zapf_dingbats = f.(15);;

