//
//  tarif.c
//  Tarification
//
//  Created by Augustin Debureaux on 30/07/2019.
//  Copyright � 2019 Augustin Debureaux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

double tarif(int zoneMessagerie, int poids)
{
    int tranchePoids = 0;

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
    else if (poids >= 40 && poids <= 49)
    {
        tranchePoids = 6;
    }
    else if (poids >= 50 && poids <= 59)
    {
        tranchePoids = 7;
    }
    else if (poids >= 60 && poids <= 69)
    {
        tranchePoids = 8;
    }
    else if (poids >= 70 && poids <= 79)
    {
        tranchePoids = 9;
    }
    else if (poids >= 80 && poids <= 89)
    {
        tranchePoids = 10;
    }
    else if (poids >= 90 && poids <= 99)
    {
        tranchePoids = 11;
    }
    else if (poids >= 100 && poids <= 199)
    {
        tranchePoids = 12;
    }
    else if (poids >= 200 && poids <= 299)
    {
        tranchePoids = 13;
    }
    else if (poids >= 300 && poids <= 499)
    {
        tranchePoids = 14;
    }
    else if (poids >= 500 && poids <= 1000)
    {
        tranchePoids = 15;
    }
    else
    {
        printf("\nPoids incorrect.\n");
    }

    // Recalibrage departement depart
    zoneMessagerie--;

    double prixBase = 0, multiplier = 0;
    double table[12][16] = {
    { 11.87, 13.00, 14.10, 15.21, 16.32, 19.63, 22.92, 24.92, 26.95, 28.95, 30.97, 32.96, 32.96, 31.31, 29.76, 28.26 },
    { 19.88, 22.39, 24.91, 27.44, 29.96, 33.30, 36.66, 40.03, 43.38, 46.75, 50.11, 53.46, 53.46, 50.79, 48.24, 45.83 },
    { 21.86, 25.39, 28.93, 32.45, 35.98, 40.62, 45.25, 49.90, 54.52, 59.16, 63.78, 68.42, 68.42, 65.00, 61.75, 58.67 },
    { 23.38, 27.38, 31.37, 35.36, 39.35, 44.50, 49.67, 54.83, 59.99, 65.14, 70.30, 75.46, 75.46, 71.20, 68.10, 64.70 },
    { 24.90, 29.26, 33.62, 37.95, 42.31, 47.81, 53.30, 58.78, 64.29, 69.77, 75.25, 80.74, 80.74, 76.72, 72.87, 69.24 },
    { 26.42, 31.24, 36.07, 40.88, 45.71, 51.54, 57.32, 63.16, 68.94, 74.78, 80.59, 86.40, 86.40, 82.08, 77.99, 74.07 },
    { 27.59, 33.02, 38.49, 43.94, 49.37, 55.39, 61.44, 67.46, 73.50, 79.52, 85.55, 91.58, 91.58, 87.01, 82.66, 78.52 },
    { 27.76, 34.03, 40.29, 46.55, 52.83, 59.01, 65.20, 71.40, 77.60, 83.78, 89.97, 96.15, 96.15, 91.37, 86.79, 82.45 },
    { 27.95, 35.09, 42.23, 49.38, 56.52, 62.88, 69.23, 75.57, 81.91, 88.27, 94.63, 100.98, 100.98, 95.92, 91.13, 86.57 },
    { 28.10, 36.20, 44.29, 52.39, 60.48, 66.98, 73.49, 79.99, 86.51, 93.01, 99.53, 106.02, 106.02, 100.73, 95.68, 90.91 },
    { 28.29, 37.24, 46.20, 55.14, 64.12, 70.85, 77.61, 84.33, 91.08, 97.83, 104.58, 111.33, 111.33, 105.76, 100.48, 95.46 },
    { 28.46, 38.17, 47.89, 57.60, 67.30, 74.07, 80.85, 87.60, 94.38, 101.13, 107.91, 114.67, 114.67, 108.93, 103.48, 98.31 }
    };
    prixBase = table[zoneMessagerie][tranchePoids];

    
    if (poids > 100 )
    {
        multiplier = poids / 100;
        prixBase = prixBase * multiplier;
    }


    return prixBase;
}
