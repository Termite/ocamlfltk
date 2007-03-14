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

val helvetica : font;;
val helvetica_bold : font;;
val helvetica_italic : font;;
val helvetica_bold_italic : font;;
val courier : font;;
val courier_bold : font;;
val courier_italic : font;;
val courier_bold_italic : font;;
val times : font;;
val times_bold : font;;
val times_italic : font;;
val times_bold_italic : font;;
val symbol_font : font;;
val screen_font : font;;
val screen_bold_font : font;;
val zapf_dingbats : font;;


