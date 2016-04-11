#include <stdio.h>


int main(int argc, char *argv[]) {

    int i;

    printf("Hello, everyone!\n");

    for (i = 0 ; i < argc ; i ++)
        printf("Good bye, %s!\n", argv[i]);

    printf("See you later!\n");

    return 0;
}
