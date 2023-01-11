//Name: Ghazi Najeeb Al-Abbar
//ID: 2181148914
//postlab9.c

#include <stdio.h>

int isidentical(int val1, int val2){
        
        return !(val1 ^ val2);
}

int main(){

    int val1, val2;

    printf("Enter two integers: ");
    scanf("%d %d", &val1, &val2);

    if (isidentical(val1,val2))
        printf("They are identical!\n");
    else
        printf("They are not identical.\n");

    return 0;
}