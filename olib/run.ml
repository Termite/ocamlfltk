
external run: unit -> int = "app_run" ;;
external check: unit -> int = "app_check";;
external wait: unit -> int = "app_wait";;

let  get_time_secs = Unix.gettimeofday;;



