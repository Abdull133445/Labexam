//to understand concept of strings and related function
//write a c program to print your name using string 
#include <stdio.h>

int main() {
    char name[30];
    printf("Enter your name: ");
    fgets(name, 30, stdin);
    printf("My name is: %s", name);
    puts(name);
return 0;
}

