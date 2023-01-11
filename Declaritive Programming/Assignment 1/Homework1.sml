(*
Name: Ghazi Najeeb Al-Abbar
ID: 2181148914
Assignment #1
Declaritive programming
*)

(*
    List or List1, List2, ... , ListN -- are user input list(s)
    num or num1, num2, ... , numN     -- are user input number(s) 
*)

(* Question 1 *)
(* Calling the function would be like: Triangle_Area(num1, num2, num3) *)
(* takes the length of each triangle size and returns the area. It will raise an exception if it is not a triangle *)
exception NOT_A_TRIANGLE
fun Triangle_Area(a, b, c) = if (a + b >= c andalso a + c >= b andalso b + c >= a) then let
                                                                                            val S = (a + b + c) / 2.0
                                                                                        in
                                                                                            Math.sqrt(S * (S - a) * (S - b) * (S - c))
                                                                                        end
                            else raise NOT_A_TRIANGLE; 


(* Question 2 *)
(* Calling the function would be like: deficient(num1, num2) *)
(* Takes a range of numbers and returns how many numbers within that range are deficient.
It will raise an exception if the range goes backwards or the start is equal to the end *)
exception RANGE_ERROR_OR_NUMBERS_ARE_EQUAL
fun deficient(A,B) = if (A = B orelse B < A) then raise RANGE_ERROR_OR_NUMBERS_ARE_EQUAL else 
                                             let fun helper(A, B, num) = if (A > B) then num else
                                                                                             let fun loop(i,A, sum) = if (i = A) then sum 
                                                                                             else if (A mod i = 0) then loop(i + 1, A, sum + i) else loop(i + 1, A, sum)

                                                                                             in if (loop(1, A, 0) < A) then helper(A + 1, B, num + 1) 
                                                                                             else helper(A + 1, B, num)
                                                                                             end 
                                             in helper(A,B, 0) end;


(* Question 3 *)
(*a-1*)
(* Calling the function would be like: list2reverseInt(num, []) *)
(* Takes an integer and returns the list representation of the integer in reverse *)
fun revIntList(0, L) = L | revIntList(num, L) = revIntList(num div 10, L @ [num mod 10]);

(*a-2*)
(* Calling the function would be like: List2int(List) *)
(* Takes a list and returns the integer representation of the list *)
exception Empty
fun List2int(nil) = raise Empty | List2int(x::xs) = let fun loop(nil, accum, pow) = accum | loop(y::ys, accum, pow) = loop(ys, y * pow + accum, pow * 10)
                                          in
                                              loop(xs, x, 10)
                                          end;

(*b-1*)
(* Calling the function would be like: sum1(List1, List2) *)
(* Takes a two lists, turns them into an integer representation, adds them, then convert them back to a list and returns it *)
fun sum1(nil,nil) = nil | sum1(L, nil) = L | sum1(nil, L) = L
| sum1(x::xs, y::ys) = let
                            fun list2int(nil, res) = res | list2int(x::xs, res) = list2int(xs, res*10 + x)
                            fun int2list(0,L) = L | int2list(num, L) = int2list(num div 10, [num mod 10] @ L)
                        in
                            int2list(list2int(xs, x) + list2int(ys, y), nil)
                        end;

(*b-2*)
(* Calling the function would be like: sum2(List1, List2) *)
(* Takes two lists and adds the directly. It returns the resulting list *)
fun sum2(nil, nil) = nil | sum2(L, nil) = L | sum2(nil, L) = L
| sum2(L1, L2) = let
                    fun addLists(nil, nil, Res, carry) = if (carry > 0) then Res @ [carry] else Res
                    | addLists(L1, nil, Res, carry) = Res @ L1
                    | addLists(nil, L2, Res, carry) = Res @ L2
                    | addLists(x::xs, y::ys, Res, carry) = addLists(xs, ys, Res @ [(x+y+carry) mod 10], (x+y+carry) div 10)
                in 
                   addLists(L1, L2, [], 0)
                end;

(*Question 4*)
(*a*)
(* Calling the function would be like: rmvdup(List, [], 0) *)
(* Takes a list and removes all duplicates and results the resulting list. *Does not necessarily work if the list starts with 0* *)
fun rmvdup(nil, Result, dup) = Result | rmvdup(x::xs, Result, dup) = if (dup = x) then rmvdup(xs, Result, dup) else rmvdup(xs, Result @ [x], x);

(*b*)
(* Calling the function would be like: insertInOrder(List, num, [])*)
(* Takes a list and number, and returns the same list with the number added in the correct order *)
fun insertInOrder(nil, num, List2) = List2 @ [num] | insertInOrder(x::xs, num, List2) = if (num <= x) then List2 @ [num, x] @ xs else insertInOrder(xs, num, List2 @ [x]); 

(*c*)
(* Calling the function would be like: insertsort(List) *)
(* Sorts a list using insert sort *)
fun insertsort([], Res) = Res | insertsort(x::xs, Res) = insertsort(xs, insertInOrder(Res, x, []));

(*d*)
(* Calling the function would be like: SortAndRemove(List) *)
(* Takes a list and returns the list sorted and with no duplicates *)
fun SortAndRemove(nil) = nil | SortAndRemove(L) = let 
                                                     fun Remove(nil, Result, D) = Result
                                                     | Remove(x::xs, Result, D) = if (x = D) then Remove(xs, Result, D) else Remove(xs, Result @ [x], x)
                                                
                                                  in
                                                     Remove(insertsort(L), [], 0)
                                                  end;