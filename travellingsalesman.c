#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int cities[MAX_CITIES][MAX_CITIES]; 
int numCities; 


int calculateTourDistance(int tour[]) {
    int totalDistance = 0;
    int i;
    for (i = 0; i < numCities - 1; i++) {
        totalDistance += cities[tour[i]][tour[i + 1]];
    }
    
    totalDistance += cities[tour[numCities - 1]][tour[0]];
    return totalDistance;
}


void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void generatePermutations(int arr[], int size, int tour[]) {
    if (size == 1) {

        int distance = calculateTourDistance(arr);
        
        if (distance < minDistance) {
            minDistance = distance;
            for (int i = 0; i < numCities; i++) {
                tour[i] = arr[i];
            }
        }
        return;
    }
    for (int i = 0; i < size; i++) {
        generatePermutations(arr, size - 1, tour);
        if (size % 2 == 1) {
            swap(arr, 0, size - 1);
        } else {
            swap(arr, i, size - 1);
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &cities[i][j]);
        }
    }

    int citiesArray[MAX_CITIES];
    int tour[MAX_CITIES];
    for (int i = 0; i < numCities; i++) {
        citiesArray[i] = i;
    }

    int minDistance = INT_MAX;
    generatePermutations(citiesArray, numCities, tour);

    printf("Shortest tour distance: %d\n", minDistance);
    printf("Shortest tour: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", tour[i]);
    }
    printf("\n");

    return 0;
}

