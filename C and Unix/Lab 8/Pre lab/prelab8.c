//Name: Ghazi Najeeb Al-Abbar
//id: 2181148914
//prelab8.c

#include <stdio.h>

typedef struct person{

    char name[15];
    int age;
    float weight;
}Person;

int main(){

    Person arr[20] = {0};
    int numOfPeople, i;

    printf("Enter how many people you want to identify (Must not exceed 20 persons): ");
    scanf("%d", &numOfPeople);

    for (i = 0; i < numOfPeople; i++){

        printf("Person #%d\n\n", i + 1);

        printf("Enter this person's name (must not exceed 15 characters): ");
        scanf("%s", arr[i].name);

        printf("Enter his/her age: ");
        scanf("%d", &arr[i].age);

        printf("Enter his/her weight: ");
        scanf("%f", &arr[i].weight);

        puts("\n");
    }

    for (i = 0; i < numOfPeople; i++){

        printf("Person #%d\n\n", i + 1);

        printf("Name: %s\n", arr[i].name);
        printf("Age: %d\n", arr[i].age);
        printf("Weight: %f\n", arr[i].weight);

        puts("\n");
    }

    return 0;
}
