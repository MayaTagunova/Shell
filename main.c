#include <stdio.h>
#include <unistd.h>

int main()
{
    while (1) {
        char buffer[256];

        printf("\n>");
        scanf("%255s", buffer);

        int cpid;
        cpid = fork();

        if (cpid == -1) {
            printf("Failed to run child process.");
        } else if (cpid == 0) {
            if (execlp(buffer, buffer, NULL) == -1)
                printf("Failed to execute command.");
        }
        else {
            wait();
        }
    }
    return 0;
}

