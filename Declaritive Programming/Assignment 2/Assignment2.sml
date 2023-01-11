(*
    Name: Ghazi Najeeb Al-Abbar
    ID: 2181148914
    Declaritive Programming 
    Assignment 2
*)


(*Question 1*)
(*part a*)
fun filter p nil = nil | filter p (x::xs) = if (p(x)) then x::filter p xs else filter p xs;

fun isPrime(1) = false | isPrime(x) = let 
                                         fun loop(1, x, accum) = accum | loop(i, x, accum) = if (x mod i = 0) then loop(i - 1, x, accum + 1) else loop(i - 1, x, accum)
                                      in
                                         if (loop(x - 1, x, 0) = 0) then true else false
                                      end;   
exception EMPTY_LIST
fun PrimeList(nil) = raise EMPTY_LIST | PrimeList(L) = filter isPrime L;

(*part b*)
fun foldl f accum nil = accum | foldl f accum (x::xs) = foldl f (f(x, accum)) (xs);

fun ListProduct List = foldl (fn (x,y) => x * y) 1 List;

(*Question 2*)
(* Function Q3 acts as a helper. Q3 should be called to utilize ListEquality *)
exception NOT_EQUAL_LENGTHS
fun ListEquality f (x::xs) nil = raise NOT_EQUAL_LENGTHS | ListEquality f nil (y::ys) = raise NOT_EQUAL_LENGTHS | ListEquality f nil nil = true
| ListEquality f (x::xs) (y::ys) = if (f(x,y)) then ListEquality f xs ys else false;

fun Q2(List1, List2) = ListEquality (fn (x,y) => x = y) List1 List2;

(*Question 3*)
(* Function Q4 acts as a helper. Q4 should be called to utilize Max *)
fun Max f Result nil = Result | Max f Result (x::xs) = if (f(x, Result)) then Max f x xs else Max f Result xs; 

fun Q3 List = Max (fn (x,y) => y < x) (hd(List)) List;

(* Question 4 *)
(* distance should be called like this: distance(point(a,b,c), point(d,e,f)), where a-f are real numbers *)
(*part a*)
datatype COORDS = point of (real * real * real);

(*part b*)
fun square(x:real) = x * x;
fun distance(point(x1,y1,z1), point(x2,y2,z2)) = Math.sqrt( square(x2 - x1) + square(y2 - y1) + square(z2 - z1));
