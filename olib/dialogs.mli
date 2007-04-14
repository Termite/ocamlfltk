
val ask:  ('a, unit, string, int) format4 -> 'a
val message:  ('a, unit, string, unit) format4 -> 'a
val choice:  string -> string -> string -> ('a, unit, string, int) format4 -> 'a
val input: string -> ('a, unit, string, string option) format4 -> 'a
val set_ok: string -> unit;;


