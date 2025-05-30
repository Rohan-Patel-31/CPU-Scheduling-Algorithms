// This C program is intended to implement FCFS(First Come First Serve) without using the arrival time.

#include <stdio.h>

#define MAX 30

int main() {
    int n, bt[MAX], wt[MAX], tat[MAX];
    float awt = 0.0, atat = 0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of processes. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        if (bt[i] < 0) {
            printf("Burst time must be non-negative.\n");
            return 1;
        }
    }

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", awt / n);
    printf("Average Turnaround Time = %.2f\n", atat / n);

    return 0;
}
