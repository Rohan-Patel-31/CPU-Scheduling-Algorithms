// This code implements FCFS(First Come First Serve) CPU Scheduling Algorithm using Arrival Time.

#include <stdio.h>

#define MAX 30

int main() {
    int i, n;
    int bt[MAX], at[MAX], wt[MAX], tat[MAX], temp[MAX];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    temp[0] = 0;

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time = %.2f\n", awt);
    printf("Average Turnaround Time = %.2f\n", atat);

    return 0;
}
