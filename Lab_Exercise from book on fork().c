#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void countFrequency(int arr[], int size, int number) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    printf("Parent Process Result: Frequency of %d is %d\n", number, count);
}

void sumOfEvenNumbers(int arr[], int size) {
    int evenSum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        }
    }
    printf("1st Child Process Result: Sum of even numbers is %d\n", evenSum);
}

void totalEvenNumbers(int arr[], int size) {
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    printf("2nd Child Process Result: Total even numbers is %d\n", evenCount);
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("3rd Child Process Result: Sorted array is ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Example array
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(array) / sizeof(array[0]);

    // Create child processes
    pid_t child1, child2, child3;

    child1 = fork();
    if (child1 == 0) {
        // 1st child process
        sumOfEvenNumbers(array, size);
        exit(0);
    }

    child2 = fork();
    if (child2 == 0) {
        // 2nd child process
        totalEvenNumbers(array, size);
        exit(0);
    }

    child3 = fork();
    if (child3 == 0) {
        // 3rd child process
        sortArray(array, size);
        exit(0);
    }

    // Parent process
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    waitpid(child3, NULL, 0);

    // Parent process task
    countFrequency(array, size, 5);

    return 0;
}

