#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        int sum = 0;
        for (int i = 1; i <= n; i += 2) {
            sum += i;
        }
        printf("Child process (odd numbers) sum: %d\n", sum);
    } else {
        int sum = 0;
        for (int i = 2; i <= n; i += 2) {
            sum += i;
        }
        printf("Parent process (even numbers) sum: %d\n", sum);
    }

    return 0;
}
