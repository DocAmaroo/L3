(*** EXERCICE 1 ***)

(* int -> object *)
class min(init : int) =
object (self)
  val x = init
  method get = x
  method min y = if self#get < y then self#get else y
end;;

(* int -> object *)
class min_max(init : int) =
object (self)
  inherit min init
  method max y = if self#min y = y then self#get else y
end;;

(* object *)
class other = 
object
  method get = 1
  method min n = n - 1
  method max n = n + 1
end;;

(* 'a -> object *)
class ['a] cell (init : 'a) =
object
  val mutable cont = init
  method get = cont
  method set n = cont <- n
end;;

let m = new min 1;;
let mm = new min_max 2;;
let o = new other;;
let c = new cell 1;;

(* 
 * let natural (o: min) ==> <other> qui doit être un <min>
 * o#min(0) = 0 ==> <bool>
 * 
 * min -> bool = <fun>
*)
let natural (o: min) = o#min(0) = 0;;

(* 
 * let negative (o: min) ==> <other> qui doit être de type <min>
 * o#min(0) = 0 ==> <bool>
 * 
 * min -> bool = <fun>
*)
let negative (o: min) = o#min(0) = o#get;;

(* 
 * let positive o ==> <object>
 * 
 * <int ...> -> bool = <fun>
*)
let positive o = o#get > 0;;

natural m;;
(* natural mm ---> Devrait être un type min *)
(* natural o ---> Devrait être un type min *)
natural (o:>min);;
(* natural c ---> Devrait être un type min *)
(* negative c ---> Devrait être un type min *)
negative m;;
(* negative mm ---> Devrait être un type min *)
(* negative o ---> Devrait être un type min *)
(* negative c ---> Devrait être un type min *)
positive m;;
positive mm;;
positive o;;
positive c;;

(*** EXERCICE 2 ***)
class virtual ['a] add_magma =
object
  method virtual add : 'a -> 'a -> 'a
end;;

class virtual ['a] mul_magma =
object
  method virtual mul : 'a -> 'a -> 'a
end;;

class virtual ['a] add_monoid =
object
  inherit ['a] add_magma
  method virtual add_id : 'a
end;;

class virtual ['a] mul_monoid =
object
  inherit ['a] mul_magma
  method virtual mul_id : 'a
end;;

class virtual ['a] add_group =
object
  inherit ['a] add_monoid
  method virtual sub : 'a -> 'a -> 'a
end;;

(* class virtual ['a] ring =
object
  inherit ['a] add_group
  inherit ['a] mul_monoid
  method virtual add
end;; *)


(* class int_ring =
    object (self)
        inherit [int] ring
        method add a b = a + b
        method mul a b = a * b
        method add_id = 0
        method mul_id = 1
        method soust a b = a - b
end;; *)