let print_bool b = if b then print_string "true" else print_string "false";;

class min (xi : int) =
object (self)
    val mutable x = xi
    method get = x
    method set n = x <- n
    method min y = if self#get < y then self#get else y
end;;

class min_zero xi =
object
    inherit min xi
    method get = 0
end;;

let o1 = new min 4;;
let o2 = new min_zero 4;;

print_int(o1#min 2);;
print_newline();;
print_int(o1#min 7);;
print_newline();;
print_int(o2#min (-2));;
print_newline();;

print_string("\n___ Exercice 1 ___\n");;

(* EXO 1 *)
class account b =
object (self)
    val mutable balance = 0.0
    method get = balance
    method deposit a = balance <- balance +. a
    method withdraw a = balance <- balance -. a
    method print = print_float balance ; print_newline()
    initializer self#deposit b
end;;

class interest_account b =
object
    inherit account b
    method interest =
        balance <- balance +. 5. *. balance /. 100.
end;;

class secure_account b =
object
    inherit account b as super
    method withdraw a =
        if ( balance -. a ) >= 0. then super#withdraw a
        else failwith " Not enough money THO-MAS !"
end;;

class bank =
object (self)
    val mutable list = ([] : account list)
    method add (b : account) = 
        list <- b :: list
    method balance =
        List.fold_left(fun acc x -> acc +. x#get) 0. list
    method print = 
        List.iter(fun x -> x#print) list
    method fees = 
        List.iter(fun x -> x#withdraw (x#get *. 5. /. 100.)) list
end;;

let account = new account 10.;;
let interestAccount = new secure_account 10000.;;
let secureAccount = new secure_account 10000.;;
let bank = new bank;;

bank#add account;;
bank#add (interestAccount:>account);;
bank#add secureAccount;;

print_string("\n__bank\n");;
print_float(bank#balance);;
print_newline();;
print_string("\n__affichage des comptes\n");;
bank#print;;
print_string("\n__applications des frais\n");;
bank#fees;;
bank#print;;

print_string("\n___ Exercice 2 ___\n");;
(* EXO 2 *)

class ['a] collection =
object
    val mutable acc_list = []
    method add (a : 'a) = acc_list <- a::acc_list
end;;

class bank2 =
object
    inherit [account] collection
    method balance = List.fold_left (fun a b -> a +. b#get) 0. acc_list
    method print = List.iter (fun a -> a#print) acc_list
    method fees = List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) acc_list
end;;

print_string("\n__bank v2\n");;
let bank2 = new bank2;;
bank2#add account;;
bank2#add (interestAccount:>account);;
bank2#add secureAccount;;
bank2#balance;;
bank2#print;;
bank2#fees;;
bank2#print;;

print_string("\n___ Exercice 3 ___\n");;
(* Exercice 3 *)

class cte n =
object
    val content = n
    method eval = content
    method print = print_int n
end;;

class inv (e : cte) =
object
    val content = e
    method eval = 
        -e#eval
    method print =
        print_string "(-:"; content#print; print_endline ")"
end;;

class add (l : cte) (r : cte) =
object
    val x = l
    val y = r
    method eval = 
        x#eval + y#eval
    method print =
        print_string "("; x#print; print_string " + "; y#print; print_endline ")"
end;;

class sub (l : cte) (r : cte) =
object
    val x = l
    val y = r
    method eval = 
        x#eval - y#eval
    method print =
        print_string "("; x#print; print_string " - "; y#print; print_endline ")"
end;;

class mul (l : cte) (r : cte) =
object
    val x = l
    val y = r
    method eval = 
        x#eval * y#eval
    method print = 
        print_string "("; x#print; print_string " * "; y#print; print_endline ")"
end;;

class div (l : cte) (r : cte) =
object
    val x = l
    val y = r
    method eval = 
        x#eval / y#eval
    method print = 
        print_string "("; x#print; print_string "/"; y#print; print_endline ")"
end;;

let e = new add (new cte 1) (new cte 2);;
e#eval;;
e#print;;

print_string("\n___ Exercice 4 ___\n");;
(* Exercice 4 *)

class virtual ['a] abr =
object
    method virtual insert : 'a -> 'a abr
    method virtual find : 'a -> bool
end;;

class ['a] empty =
object
    inherit ['a] abr
    method insert n = 
        new node n (new empty) (new empty)
    method find n = false
    end

    and ['a] node n (l : 'a abr) (r : 'a abr) =
        object (self)
            inherit ['a] abr
            val value = n
            val mutable x = l
            val mutable y = r
            method insert (n : 'a) = (
                if n < value then x <- x#insert n
                else if n > value then y <- y#insert n
            );
            (self :> 'a abr)
            method find (n : 'a) =
                if n == value then true
                else if n < value then x#find n
                else y#find n
end;;

let t = ((((new empty)#insert 8)# insert 3)# insert 10)#insert 6;;
print_bool(t#find 8);;
print_newline();;
print_bool(t#find 2);;
print_newline();;
