#include <stdio.h>
#include <stdlib.h>

struct Item {
    int profit;
    int weight;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    float ratio1 = item1->ratio;
    float ratio2 = item2->ratio;
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

float fractional_knapsack(struct Item arr[], int n, int W) {

    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    qsort(arr, n, sizeof(arr[0]), compare);

    float total_profit = 0;
    int weight_remaining = W;

    for (int i = 0; i < n; i++) {

        if (arr[i].weight <= weight_remaining) {
            total_profit += arr[i].profit;
            weight_remaining -= arr[i].weight;
        } else {

            total_profit += arr[i].ratio * weight_remaining;
            break;
        }
    }

    return total_profit;
}

int main() {
    // Ejemplo de entrada
    /*struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 50;*/

    /*Caso de prueba 1*/
    /*struct Item arr[] = {{50, 5}, {110, 30}, {150, 50}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 30;*/

    /*Caso de prueba 2*/
    /*struct Item arr[] = {{25, 10}, {40, 15}, {18, 3}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 15;*/
    
    /*Caso de prueba 3*/
    struct Item arr[] = {{30, 15}, {40, 20}, {80, 35}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int W = 10;

    float max_profit = fractional_knapsack(arr, n, W);
    printf("El beneficio maximo obtenido es: %.2f\n", max_profit);

    return 0;
}
