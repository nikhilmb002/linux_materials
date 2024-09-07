#include <stdio.h>
#include <unistd.h>
int main() {

        printf("hi\n");
        fork();
        printf("bye...\n");
}

