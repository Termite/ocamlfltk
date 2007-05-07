
external show_colormap: int -> int = "show_colormap";; 
val message:  ('a, unit, string, unit) format4 -> 'a
val alert:  ('a, unit, string, unit) format4 -> 'a
val ask:  ('a, unit, string, int) format4 -> 'a
val choice:  string -> string -> string -> ('a, unit, string, int) format4 -> 'a
val choice_alert:  string -> string -> string -> ('a, unit, string, int) format4 -> 'a
val input: ?def:string -> ('a, unit, string, string option) format4 -> 'a
val password: ?def:string -> ('a, unit, string, string option) format4 -> 'a
val set_no: string -> unit;;
val set_yes: string -> unit;;
val set_ok: string -> unit;;
val set_cancel: string -> unit;;
val no: unit -> string;;
val yes: unit -> string;;
val ok: unit -> string;;
val cancel: unit -> string;;


