//
//  main.c
//  Table
//
//  Created by Augustin Debureaux on 29/07/2019.
//  Copyright © 2019 Augustin Debureaux. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
# include "zone.h"

int main(int argc, const char * argv[])
{   // Definition de la zone
    int arr = 0, dep = 0;
    int zoneMessagerie = 0;
    printf("Departement de depart : ");
    scanf("%d", &dep);
    dep--;
    if (dep >= 20)
    {
        dep--;
    }
    printf("\nDepartement de d'arrive : ");
    scanf("%d", &arr);
    arr--;
    if (arr >= 20)
    {
        arr--;
    }
    zoneMessagerie = zone(arr, dep);
    printf("Zone %d\n", zoneMessagerie);

    // Definition du poids
    int poids = 0, tranchePoids = 0;
    double prixBase = 0;

        double table[12][16] = {
    { 11.87, 13.00, 14.10, 15.21, 16.32, 19.63, 22.92, 24.92, 26.95, 28.95, 30.97, 32.96, 31.31, 29.76, 28.26 },
    { 19.88, 22.39, 24.91, 27.44, 29.96, 33.30, 36.66, 40.03, 43.38, 46.75, 50.11, 53.46, 53.46, 50.79, 48.24 },
    { 21.86, 25.39, 28.93, 32.45, 35.98, 40.62, 45.25, 49.90, 54.52, 59.16, 63.78, 68.42, 68.42, 65.00, 61.75 }
    };

    printf("Poids du colis : ");
    scanf("%d", &poids);

    if (poids >= 0 && poids <= 4)
    {
        tranchePoids = 0;
    }
    else if (poids >= 5 && poids <= 9)
    {
        tranchePoids = 1;
    }
    else if (poids >= 10 && poids <= 14)
    {
        tranchePoids = 2;
    }
    else if (poids >= 15 && poids <= 19)
    {
        tranchePoids = 3;
    }
    else if (poids >= 20 && poids <= 29)
    {
        tranchePoids = 4;
    }
    else if (poids >= 30 && poids <= 39)
    {
        tranchePoids = 5;
    }
    else
    {
        printf("\nTrop de poids\n");
    }

    printf("\n%d\n", tranchePoids);
    printf("Table : %f", table[zoneMessagerie][tranchePoids]);

}
