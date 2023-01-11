#include <stdio.h>

char* encrypt(char* str){

    int i;

    for (i = 0; *(str + i) != '\0'; i++){

        *(str + i) += 1;
    }

    return str;
}

char* decrypt(char* str){

    void *address = str;

    while(*str != '\0'){

        *str -= 1;
        str += 1;
    }

    str = address;

    return str;
}

int main(){

    char str[100];

    printf("Enter a string: ");
    gets(str);

    printf("The string you entered: %s\n", str);

    printf("The string after encryption: %s\n", encrypt(str));

    printf("The string after decryption: %s\n", decrypt(str));

    return 0;
}
