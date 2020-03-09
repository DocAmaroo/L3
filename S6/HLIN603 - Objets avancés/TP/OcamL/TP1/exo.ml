let rec print_list = function [] -> ()
| e::l -> print_string e ; print_string " " ; print_list l

let print_bool b = if b then print_string "true" else print_string "false";;

let list = ["a"; "b"; "a"; "d"; "a"; "a"];;
let list2 = ["a"; "b"; "c"; "d";];;

let rec reverse = function []->[]
| e :: tl -> (reverse tl) @ [e];;

let rec occurence x = function []->0
| e :: tl -> ( if x=e then 1+(occurence x tl) else (occurence x tl) );;

let rec isSort = function 
[]->true 
| [e]->true
| e1 :: e2:: tl -> ( e1 < e2) && (isSort(e2 :: tl));;

let rec insertTri x = function []->[x]
| e :: tl -> (if x <= e then x :: e :: tl else e:: (insertTri x tl));;

let rec tri = function []->[]
| e :: tl -> insertTri e (tri tl);;

(* MAIN *)
print_string "\n ____ Exercice 1 ____\n";;
print_list (reverse list);;
print_char '\n';;
print_int (occurence "a" list);;
print_char '\n';;
print_bool (isSort list2);;
print_char '\n';;
print_list (insertTri "c" list2);;
print_char '\n';;
print_list (tri list);;
print_string "\n ____ Exercice 2 ____\n";;

type form =
  | Top
  | Bot
  | Var of string
  | Not of form
  | And of form * form
  | Or of form * form
  | Imp of form * form
  | Equ of form * form;;

let rec string_of_form = function
  | Top -> "T"
  | Bot -> "F"
  | Var x -> x
  | Not x -> "!"^(string_of_form x)
  | And (x, y) -> (string_of_form x)^" AND "^(string_of_form y)
  | Or (x, y) -> (string_of_form x) ^" OR " ^(string_of_form y)
  | Imp (x, y) -> (string_of_form x)^"=>" ^(string_of_form y)
  | Equ (x, y) -> (string_of_form x)^"<=>" ^(string_of_form y);;

let simp_and = function
  | (f, Top) | (Top, f) -> f
  | (_, Bot) | (Bot, _) -> Bot
  | (l, r) -> And(l, r);;

let simp_or = function
  | (_, Top) | (Top, _) -> Top
  | (f, Bot) | (Bot, f) -> f
  | (l, r) -> Or(l, r);;

let simp_imp = function
  | (_, Top) | (Bot, _) -> Top
  | (f, Bot) -> Not f
  | (Top, f) -> f
  | (l, r) -> Imp(l, r);;

let simp_equ = function
  | (f, Top) | (Top, f) -> f
  | (_, Bot) | (Bot, _) -> Not f
  | (l, r) -> Equ(l, r);;

let rec simplifie = function
  | And (f1, f2) ->
    let f1 = simplifie f1
    and f2 = simplifie f2 in
    simp_and (f1', f2')
  | Or (f1, f2) ->
    let f1 = simplifie f1
    and f2 = simplifie f2 in
    simp_or (f1', f2')
  | Imp (f1, f2) ->
    let f1 = simplifie f1
    and f2 = simplifie f2 in
    simp_imp (f1', f2')
  | Equ (f1, f2) ->
    let f1 = simplifie f1
    and f2 = simplifie f2 in
    simp_equ (f1', f2');;

let test = (And (Var "A", Top));;

print_char '\n';;
print_string (string_of_form test);;
print_char '\n';;
print_string (string_of_form (simplifie test));;
print_char '\n';;