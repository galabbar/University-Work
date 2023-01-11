//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//quiz2.c

#include <stdio.h>

void printBit(int val){

     int mask = 1 << 31;
     int i = 0;

     for (i; i < 31; i++){

        if (mask & val)
            printf("1");
        else
            printf("0");

        val <<= 1;
     }
}

int ithBitInto1(int val, int i){\

    int mask = 1<<i;

    return val | mask;
}

int Add1(int val){

    int i = 0;
    int Result = 0;
    int isOne = 0;

    for (i; i < 31; i++){

        if (val & 1){
            isOne = 1;
            val >>= 1;
            continue;
        }

        else{
            if (isOne)
                Result |= (1<<i);
        }

        isOne = 0;
    }

    return Result;
}

int main(){

    printf("printing 75 in binary: ");
    printBit(75);

    printf("\n\n");

    printf("Changing the 9th bit of 128 to 1: ");
    printBit(ithBitInto1(128, 9));

    printf("\n\n");

    printf("Adding 1 to 15 results in: ");
    printf("%d", Add1(15));

    return 0;
}
