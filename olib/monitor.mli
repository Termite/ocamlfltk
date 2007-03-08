type monitor
external depth : monitor -> int = "monitor_depth"
external dpi_x : monitor -> float = "monitor_dpi_x"
external dpi_y : monitor -> float = "monitor_dpi_y"
external dpi : monitor -> float = "monitor_dpi"
external find : int -> int -> monitor = "monitor_find"
external all : unit -> monitor = "monitor_all"
external list : unit -> monitor array = "monitor_list"
external rect: monitor -> int*int*int*int = "monitor_rect";;
