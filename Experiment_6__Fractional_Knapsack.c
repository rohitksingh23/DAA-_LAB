// Name: Rohit Kumar singh
// Roll Number: 25/DA/055

#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    // Calculate value/weight ratio
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)items[i].value / items[i].weight;
    }

    // Sort items by ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratios
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // swap items
                struct Item tempItem = items[i];
                items[i] = items[j];
                items[j] = tempItem;
            }
        }
    }

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    printf("Items taken (weight, value, fraction):\n");

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // take whole item
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("%d %d 1.0\n", items[i].weight, items[i].value);
        } else {
            // take fraction
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("%d %d %.2f\n", items[i].weight, items[i].value, fraction);
            break;
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", totalValue);
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}
