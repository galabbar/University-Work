#Made and debugged in Onlinegdb
#Calculates the interest
sub interest{
    
    #Gathers the parameters in their variables
    ($amount) = @_[0];
    ($time) = @_[1];
    ($rate) = @_[2];
    
    return ($amount * $time * $rate) / 100; #Returns the interest
}

#prints all the prime numbers from the range given by the parameter
sub printPrimeNumbers{
    
    ($Size) = @_[0]; #stores the parameter in Size
    
    #Goes through the list of numbers from 2 to Size and checks if it's a prime number
    for ($i = 2; $i <= $Size; $i += 1){
        
        $flag = 1; #boolean flag to check if the number is prime
        for ($j = 2; $j < $i; $j += 1){
            
            #if the number is divisable by any number that isn't 1 and itself,
            #then the boolean flag turns false and the loop is broken
            if ($i % $j == 0){
                
                $flag = 0;
                last;
            }
        }
        
        #if the flag is true, then the number is a prime and it is printed.
        if ($flag){
            
            print "$i  ";
        }
    }
    
    print "\n\n";
}

#Driver function for the intrest function
sub main{
    print "Enter the amount: ";
    $amount = <STDIN>;
    
    print "Enter the time: ";
    $time = <STDIN>;
    
    print "Enter the rate: ";
    $rate = <STDIN>;
    
    $Interest = interest($amount, $time, $rate);
    
    print "The interest is: $Interest\n";
}

#driver function for the printPrimeNumbers function
sub main2{
    
    print "Enter a number: ";
    $Num = <STDIN>;
    
    printPrimeNumbers($Num);
}

#The driver functions are called and the program starts
print "Question 4.1:\n\n";
main();
print "\n\nQuestion 4.2:\n\n";
main2();
#End Of Program