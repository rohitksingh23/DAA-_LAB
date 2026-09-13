#include <stdio.h>

// Structure to store an activity
struct Activity {
    int start;
    int finish;
};

// Function to sort activities according to finish time
void sortActivities(struct Activity activities[], int n) {
    int i, j;
    struct Activity temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (activities[j].finish > activities[j + 1].finish) {
                temp = activities[j];
                activities[j] = activities[j + 1];
                activities[j + 1] = temp;
            }
        }
    }
}

// Greedy Activity Selection
void activitySelection(struct Activity activities[], int n) {
    int i;
    int lastFinish;

    // Sort according to finish time
    sortActivities(activities, n);

    printf("\nSelected Activities:\n");

    // Select the first activity
    printf("(%d, %d)\n", activities[0].start, activities[0].finish);
    lastFinish = activities[0].finish;

    // Select remaining activities
    for (i = 1; i < n; i++) {
        if (activities[i].start >= lastFinish) {
            printf("(%d, %d)\n",
                   activities[i].start,
                   activities[i].finish);

            lastFinish = activities[i].finish;
        }
    }
}

int main() {
    int n, i;
    struct Activity activities[100];

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start and finish time of each activity:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d",
              &activities[i].start,
              &activities[i].finish);
    }

    activitySelection(activities, n);

    return 0;
}