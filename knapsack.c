#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10


typedef struct {
    int weight;
    int value;
} Item;


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsack(Item items[], int numItems, int capacity) {
    
    if (numItems == 0 || capacity == 0)
        return 0;


    if (items[numItems - 1].weight > capacity)
        return knapsack(items, numItems - 1, capacity);

    
    else
        return max(items[numItems - 1].value + knapsack(items, numItems - 1, capacity - items[numItems - 1].weight),
                   knapsack(items, numItems - 1, capacity));
}

int main() {
    // Example: items with their weights and values
    Item items[MAX_ITEMS] = {{2, 10}, {3, 5}, {5, 15}, {7, 7}, {1, 6}};
    int numItems = 5; // Number of items
    int capacity = 10; // Knapsack capacity

    int max_value = knapsack(items, numItems, capacity);
    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}

