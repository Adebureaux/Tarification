//
//  Zones.c
//  Tarification
//
//  Created by Augustin Debureaux on 30/07/2019.
//  Copyright © 2019 Augustin Debureaux. All rights reserved.
//


# include <stdio.h>
# include <stdlib.h>

int zone(int arr, int dep)
{
    int run = 1;
    
    signed char table[94][94] = {
        { 1, 6, 3, 5, 3, 7, 3, 6, 8, 4, 7, 6, 5, 8, 6, 6, 7, 4, 5, 3, 9, 5, 6, 3, 3, 7, 6, 10, 5, 8, 8, 7, 5, 8, 5, 6, 2, 2, 8, 5, 3, 3, 8, 5, 7, 8, 4, 7, 8, 5, 4, 7, 5, 5, 9, 5, 3, 7, 7, 7, 7, 3, 9, 9, 7, 5, 5, 2, 3, 2, 6, 2, 2, 6, 7, 6, 6, 7, 7, 7, 7, 6, 4, 7, 6, 5, 4, 4, 4, 6, 6, 6, 6, 6 },
        { 6, 1, 5, 10, 9, 11, 8, 2, 11, 3, 11, 9, 10, 5, 8, 7, 7, 5, 8, 5, 7, 6, 8, 5, 8, 3, 4, 8, 9, 10, 10, 8, 10, 6, 5, 5, 8, 6, 10, 5, 7, 8, 6, 3, 9, 9, 9, 6, 5, 2, 3, 6, 4, 3, 7, 4, 5, 2, 2, 5, 3, 6, 10, 10, 11, 5, 5, 7, 5, 6, 5, 7, 7, 3, 3, 3, 3, 7, 2, 10, 9, 10, 9, 7, 6, 7, 5, 3, 5, 3, 3, 3, 3, 3 },
        { 3, 5, 1, 6, 6, 8, 3, 6, 8, 4, 7, 5, 6, 6, 3, 5, 6, 2, 3, 3, 7, 2, 5, 4, 4, 5, 4, 8, 6, 7, 7, 6, 6, 6, 3, 4, 3, 3, 7, 3, 2, 3, 6, 3, 6, 6, 5, 5, 6, 5, 4, 5, 5, 5, 7, 6, 2, 7, 5, 5, 6, 2, 7, 7, 8, 6, 6, 3, 4, 2, 5, 4, 4, 5, 6, 5, 5, 5, 6, 6, 6, 7, 6, 6, 4, 3, 5, 3, 5, 5, 5, 5, 5, 5 },
        { 5, 10, 6, 1, 2, 3, 3, 10, 6, 8, 5, 6, 3, 11, 7, 9, 10, 7, 8, 7, 12, 7, 8, 7, 2, 10, 9, 12, 3, 6, 7, 9, 4, 11, 8, 9, 3, 6, 8, 9, 5, 5, 11, 8, 7, 7, 5, 10, 11, 9, 8, 10, 9, 9, 12, 9, 7, 11, 10, 10, 11, 6, 8, 8, 5, 9, 8, 5, 7, 5, 10, 3, 5, 9, 11, 9, 9, 10, 11, 6, 7, 3, 2, 10, 9, 8, 8, 8, 8, 9, 9, 9, 9, 9 },
        { 4, 9, 6, 2, 1, 4, 4, 9, 7, 7, 6, 6, 4, 10, 7, 9, 10, 7, 7, 6, 11, 7, 8, 6, 2, 9, 9, 12, 5, 7, 7, 9, 5, 10, 7, 8, 2, 5, 8, 8, 3, 5, 10, 8, 7, 8, 5, 9, 11, 8, 7, 10, 9, 8, 11, 8, 6, 10, 10, 9, 10, 6, 8, 8, 6, 8, 8, 3, 6, 5, 9, 2, 3, 9, 10, 9, 9, 9, 10, 6, 7, 4, 5, 10, 8, 8, 9, 7, 7, 9, 9, 9, 9, 9 },
        { 7, 11, 8, 2, 3, 1, 5, 11, 8, 10, 7, 7, 3, 12, 8, 9, 12, 8, 8, 8, 12, 8, 9, 8, 4, 10, 10, 12, 4, 8, 8, 10, 5, 12, 8, 10, 6, 7, 9, 10, 6, 6, 12, 10, 8, 9, 6, 11, 12, 9, 9, 12, 11, 10, 12, 12, 9, 12, 11, 12, 12, 8, 9, 9, 7, 11, 10, 6, 9, 7, 11, 6, 6, 11, 11, 11, 11, 11, 12, 7, 8, 2, 3, 12, 9, 9, 11, 9, 9, 11, 11, 11, 11, 11 },
        { 3, 8, 3, 3, 3, 6, 1, 8, 6, 6, 6, 3, 4, 9, 3, 7, 8, 6, 6, 4, 10, 6, 7, 5, 2, 8, 7, 11, 4, 6, 7, 8, 4, 9, 6, 7, 2, 4, 8, 7, 2, 2, 9, 7, 6, 7, 2, 8, 10, 7, 6, 8, 7, 7, 10, 7, 4, 9, 8, 8, 9, 3, 8, 7, 6, 7, 7, 3, 5, 3, 8, 3, 4, 8, 9, 8, 8, 8, 9, 6, 6, 4, 3, 9, 7, 6, 6, 6, 6, 8, 8, 8, 8, 8 },
        { 6, 2, 6, 10, 9, 11, 8, 1, 11, 3, 11, 9, 10, 6, 9, 8, 8, 5, 8, 5, 8, 7, 8, 5, 8, 5, 5, 9, 9, 11, 10, 9, 10, 7, 6, 6, 8, 6, 10, 5, 7, 8, 7, 5, 9, 10, 9, 7, 6, 2, 3, 7, 3, 2, 8, 4, 5, 3, 3, 6, 4, 7, 11, 11, 11, 5, 5, 7, 5, 6, 6, 7, 7, 4, 5, 4, 4, 8, 3, 10, 10, 11, 9, 8, 7, 7, 3, 4, 5, 4, 4, 4, 4, 4 },
        { 8, 11, 8, 6, 7, 8, 6, 11, 1, 10, 2, 4, 6, 10, 5, 6, 7, 8, 5, 9, 10, 6, 5, 9, 6, 10, 9, 11, 5, 2, 3, 5, 3, 9, 7, 8, 7, 8, 4, 8, 7, 6, 9, 8, 4, 4, 5, 8, 10, 10, 10, 9, 11, 11, 10, 12, 8, 12, 10, 9, 11, 7, 4, 3, 3, 12, 11, 7, 10, 8, 9, 7, 8, 10, 10, 10, 10, 7, 11, 3, 3, 6, 5, 7, 7, 6, 10, 9, 10, 10, 10, 10, 10, 10 },
        { 4, 3, 4, 8, 7, 10, 6, 3, 10, 1, 9, 8, 8, 5, 7, 6, 7, 4, 6, 2, 7, 5, 7, 4, 6, 4, 4, 8, 7, 9, 9, 8, 8, 6, 4, 5, 6, 3, 9, 4, 5, 6, 6, 3, 8, 8, 7, 5, 6, 2, 2, 6, 3, 3, 7, 4, 3, 5, 3, 5, 4, 5, 9, 9, 10, 5, 5, 5, 3, 3, 5, 5, 5, 3, 4, 3, 3, 6, 4, 8, 8, 9, 7, 7, 5, 5, 3, 2, 4, 3, 3, 3, 3, 3 },
        { 7, 11, 7, 5, 6, 7, 5, 11, 2, 9, 1, 3, 5, 10, 5, 6, 7, 8, 5, 8, 10, 6, 5, 8, 6, 10, 9, 11, 3, 2, 3, 5, 2, 10, 7, 8, 6, 7, 4, 8, 6, 6, 10, 8, 4, 4, 5, 8, 10, 10, 9, 9, 10, 10, 10, 11, 8, 12, 10, 9, 11, 6, 4, 3, 2, 11, 10, 6, 9, 7, 9, 6, 7, 10, 10, 10, 10, 7, 11, 2, 3, 5, 4, 8, 7, 6, 9, 9, 9, 10, 10, 10, 10, 10 },
        { 6, 9, 5, 6, 6, 8, 4, 9, 4, 8, 3, 1, 4, 9, 2, 5, 6, 6, 3, 7, 9, 5, 3, 8, 5, 8, 7, 10, 3, 3, 3, 5, 2, 8, 6, 6, 6, 7, 5, 6, 5, 4, 8, 7, 2, 3, 2, 7, 9, 8, 8, 8, 9, 9, 9, 11, 6, 10, 9, 8, 10, 3, 5, 5, 4, 10, 9, 5, 8, 6, 7, 6, 7, 8, 9, 8, 8, 6, 9, 2, 2, 6, 4, 7, 5, 4, 9, 7, 9, 8, 8, 8, 8, 8 },
        { 5, 10, 6, 3, 4, 3, 4, 10, 6, 8, 5, 3, 1, 11, 6, 8, 10, 7, 7, 7, 12, 7, 8, 7, 3, 10, 9, 12, 2, 6, 6, 8, 3, 11, 8, 9, 5, 6, 7, 8, 5, 5, 11, 8, 6, 7, 4, 10, 11, 9, 8, 10, 9, 9, 12, 9, 7, 11, 10, 10, 11, 6, 7, 7, 5, 9, 9, 5, 7, 5, 10, 5, 5, 9, 10, 9, 9, 9, 11, 4, 6, 2, 2, 10, 9, 8, 8, 8, 8, 9, 9, 9, 9, 9 },
        { 8, 5, 6, 11, 10, 12, 9, 6, 10, 5, 10, 9, 11, 1, 8, 6, 5, 5, 7, 7, 4, 6, 7, 8, 9, 2, 3, 5, 10, 9, 9, 7, 11, 3, 5, 4, 9, 8, 8, 4, 8, 8, 4, 4, 8, 8, 9, 4, 2, 5, 6, 3, 7, 6, 4, 7, 6, 5, 3, 2, 4, 7, 9, 9, 11, 8, 8, 8, 7, 7, 3, 9, 9, 4, 3, 4, 4, 5, 4, 9, 9, 11, 10, 5, 5, 6, 7, 5, 8, 4, 4, 4, 4, 4 },
        { 6, 8, 3, 7, 7, 8, 3, 9, 5, 7, 5, 2, 6, 8, 1, 4, 6, 5, 2, 6, 8, 3, 3, 7, 5, 7, 7, 9, 3, 4, 4, 5, 3, 7, 5, 5, 6, 6, 5, 6, 3, 2, 7, 6, 2, 3, 2, 6, 8, 8, 7, 7, 8, 8, 8, 9, 5, 10, 8, 7, 9, 2, 6, 5, 6, 9, 9, 5, 7, 5, 6, 6, 6, 7, 8, 7, 7, 5, 9, 3, 3, 7, 6, 6, 5, 3, 8, 6, 8, 7, 7, 7, 7, 7 },
        { 6, 7, 5, 9, 9, 10, 7, 8, 6, 6, 6, 5, 8, 6, 4, 1, 2, 4, 3, 6, 6, 3, 2, 7, 7, 6, 5, 7, 7, 5, 4, 2, 7, 5, 3, 3, 7, 7, 3, 4, 6, 6, 4, 5, 3, 3, 6, 3, 6, 7, 7, 5, 8, 7, 5, 9, 5, 8, 6, 5, 8, 4, 5, 5, 7, 9, 9, 6, 7, 6, 4, 7, 7, 6, 6, 6, 6, 2, 7, 5, 4, 9, 8, 3, 2, 2, 8, 6, 8, 6, 6, 6, 6, 6 },
        { 7, 7, 6, 10, 10, 12, 8, 8, 7, 7, 7, 6, 10, 5, 6, 2, 1, 5, 4, 7, 5, 4, 2, 8, 8, 6, 5, 5, 9, 6, 5, 2, 8, 4, 4, 4, 8, 8, 3, 4, 7, 7, 3, 5, 3, 3, 7, 3, 5, 7, 8, 4, 9, 8, 4, 9, 5, 8, 7, 5, 8, 6, 5, 5, 8, 10, 10, 7, 8, 7, 4, 8, 8, 6, 6, 6, 6, 2, 7, 6, 5, 10, 9, 2, 3, 3, 9, 6, 9, 6, 6, 6, 6, 6 },
        { 4, 5, 2, 7, 7, 9, 6, 5, 8, 4, 8, 6, 7, 5, 5, 4, 5, 1, 3, 3, 6, 2, 4, 5, 5, 4, 3, 7, 7, 7, 6, 5, 7, 5, 2, 3, 5, 4, 6, 2, 3, 5, 5, 2, 6, 6, 6, 4, 5, 4, 4, 4, 6, 5, 6, 6, 2, 6, 5, 4, 6, 3, 7, 7, 9, 7, 6, 4, 5, 3, 3, 5, 5, 4, 5, 4, 4, 4, 5, 7, 6, 8, 6, 5, 3, 3, 6, 3, 6, 4, 4, 4, 4, 4 },
        { 5, 8, 3, 8, 7, 9, 6, 8, 5, 6, 5, 3, 7, 7, 2, 3, 3, 3, 1, 6, 7, 2, 2, 6, 6, 6, 6, 8, 6, 4, 4, 3, 5, 6, 3, 4, 6, 6, 5, 5, 3, 3, 5, 5, 2, 3, 4, 5, 7, 7, 7, 6, 8, 7, 7, 8, 5, 9, 7, 6, 8, 2, 5, 5, 6, 9, 8, 5, 7, 5, 5, 6, 6, 6, 7, 6, 6, 4, 8, 4, 3, 8, 7, 5, 3, 2, 8, 6, 7, 6, 6, 6, 6, 6 },
        { 3, 5, 3, 7, 6, 8, 5, 5, 9, 2, 8, 7, 7, 7, 6, 6, 7, 3, 6, 1, 8, 5, 6, 3, 4, 6, 5, 9, 6, 8, 9, 8, 6, 7, 5, 5, 3, 2, 8, 5, 3, 4, 7, 3, 7, 8, 5, 6, 7, 3, 2, 7, 4, 3, 8, 4, 2, 6, 5, 6, 6, 3, 9, 9, 8, 5, 4, 3, 2, 2, 6, 4, 4, 4, 6, 4, 4, 7, 6, 8, 8, 7, 6, 7, 6, 5, 3, 2, 3, 4, 4, 4, 4, 4 },
        { 9, 7, 7, 12, 11, 12, 10, 8, 10, 7, 10, 9, 12, 4, 8, 6, 5, 6, 7, 8, 1, 7, 7, 9, 10, 5, 5, 2, 11, 9, 9, 7, 11, 2, 6, 5, 10, 9, 8, 5, 9, 9, 3, 5, 8, 8, 10, 3, 3, 8, 8, 3, 9, 8, 2, 9, 7, 8, 6, 4, 7, 8, 9, 9, 11, 10, 10, 9, 9, 8, 4, 10, 10, 6, 5, 6, 6, 5, 6, 9, 9, 12, 11, 4, 5, 6, 9, 7, 10, 6, 6, 6, 6, 6 },
        { 5, 6, 2, 7, 7, 10, 6, 7, 6, 5, 6, 5, 7, 6, 3, 3, 4, 2, 2, 5, 7, 1, 3, 5, 5, 5, 4, 7, 7, 6, 5, 4, 7, 5, 2, 3, 5, 5, 5, 3, 3, 3, 5, 3, 3, 5, 5, 4, 6, 6, 6, 5, 7, 6, 6, 7, 3, 7, 6, 5, 7, 2, 6, 6, 8, 8, 7, 4, 6, 3, 4, 5, 6, 5, 6, 5, 5, 4, 6, 5, 5, 8, 7, 5, 3, 2, 6, 4, 6, 5, 5, 5, 5, 5 },
        { 6, 8, 5, 8, 8, 10, 7, 8, 5, 7, 5, 3, 8, 7, 3, 2, 2, 4, 2, 6, 7, 3, 1, 7, 7, 6, 6, 7, 7, 4, 3, 2, 6, 6, 3, 4, 7, 7, 3, 5, 6, 6, 5, 5, 2, 2, 5, 5, 7, 7, 7, 6, 8, 8, 6, 9, 5, 9, 7, 6, 8, 3, 4, 4, 6, 10, 9, 6, 8, 6, 5, 7, 8, 6, 7, 6, 6, 3, 8, 4, 3, 8, 7, 3, 3, 2, 8, 6, 8, 6, 6, 6, 6, 6 },
        { 3, 5, 4, 7, 6, 8, 5, 5, 9, 4, 8, 8, 7, 8, 7, 7, 8, 5, 6, 3, 9, 5, 7, 1, 5, 6, 6, 10, 6, 9, 9, 8, 7, 8, 5, 6, 5, 2, 9, 6, 4, 5, 8, 5, 8, 9, 6, 7, 8, 4, 3, 7, 4, 4, 9, 4, 4, 7, 6, 7, 6, 5, 10, 10, 8, 4, 3, 4, 2, 3, 7, 4, 4, 5, 7, 5, 5, 7, 6, 8, 9, 7, 6, 8, 7, 6, 3, 4, 2, 5, 5, 5, 5, 5 },
        { 3, 8, 4, 2, 2, 4, 2, 8, 6, 6, 5, 5, 3, 9, 5, 7, 8, 5, 6, 3, 10, 6, 7, 5, 1, 8, 7, 11, 3, 6, 7, 8, 4, 9, 6, 7, 2, 4, 8, 6, 3, 2, 9, 6, 7, 7, 3, 8, 9, 7, 5, 8, 7, 6, 10, 7, 4, 9, 8, 8, 9, 3, 8, 7, 5, 7, 6, 3, 4, 4, 7, 3, 4, 7, 8, 7, 7, 7, 8, 6, 6, 3, 2, 8, 7, 6, 6, 6, 6, 7, 7, 7, 7, 7 },
        { 7, 3, 5, 10, 9, 12, 8, 5, 10, 4, 10, 8, 10, 2, 7, 6, 6, 4, 6, 6, 5, 5, 6, 6, 8, 1, 2, 6, 9, 9, 9, 7, 10, 4, 4, 4, 8, 6, 8, 3, 7, 7, 5, 3, 8, 8, 8, 4, 3, 4, 5, 3, 6, 5, 5, 6, 5, 4, 2, 2, 4, 6, 9, 9, 11, 7, 7, 7, 6, 6, 3, 8, 8, 3, 2, 3, 3, 5, 3, 9, 8, 10, 9, 5, 5, 5, 6, 4, 7, 3, 3, 3, 3, 3 },
        { 6, 4, 4, 9, 9, 11, 7, 5, 9, 4, 9, 7, 9, 3, 7, 5, 5, 3, 6, 5, 5, 4, 6, 6, 7, 2, 1, 6, 8, 8, 8, 6, 9, 4, 3, 3, 7, 6, 7, 2, 6, 7, 4, 2, 7, 7, 7, 3, 3, 4, 5, 3, 6, 4, 5, 6, 3, 5, 3, 2, 4, 5, 8, 8, 10, 7, 7, 6, 6, 6, 2, 7, 7, 3, 3, 3, 3, 5, 4, 8, 8, 10, 8, 5, 4, 5, 6, 3, 6, 3, 3, 3, 3, 3 },
        { 10, 8, 8, 12, 12, 12, 11, 9, 11, 8, 11, 10, 12, 5, 9, 6, 5, 6, 7, 9, 2, 7, 7, 10, 11, 6, 6, 1, 12, 10, 9, 7, 12, 3, 6, 6, 11, 10, 9, 6, 10, 10, 3, 7, 9, 9, 11, 5, 5, 9, 9, 4, 11, 9, 2, 11, 8, 9, 7, 5, 8, 9, 9, 9, 12, 12, 12, 10, 10, 10, 5, 11, 11, 7, 6, 7, 7, 5, 8, 10, 9, 12, 12, 5, 5, 6, 11, 8, 11, 7, 7, 7, 7, 7 },
        { 5, 9, 6, 3, 4, 4, 2, 9, 5, 7, 3, 2, 2, 10, 3, 7, 9, 7, 6, 6, 11, 7, 7, 6, 4, 9, 8, 12, 1, 4, 5, 7, 2, 10, 7, 8, 4, 5, 6, 8, 3, 4, 10, 8, 3, 6, 2, 9, 11, 8, 7, 9, 8, 8, 10, 8, 6, 11, 9, 9, 10, 6, 6, 6, 4, 9, 8, 4, 7, 5, 9, 4, 5, 9, 10, 9, 9, 8, 10, 3, 3, 3, 2, 9, 8, 7, 7, 7, 7, 9, 9, 9, 9, 9 },
        { 8, 10, 7, 6, 7, 8, 6, 11, 2, 9, 2, 3, 6, 9, 4, 5, 6, 7, 4, 8, 9, 6, 4, 9, 6, 9, 8, 10, 4, 1, 2, 4, 3, 8, 6, 7, 7, 8, 3, 7, 6, 6, 8, 7, 3, 3, 5, 7, 9, 10, 9, 8, 11, 10, 8, 11, 7, 11, 9, 8, 10, 6, 3, 2, 3, 11, 11, 7, 9, 8, 8, 7, 8, 9, 9, 9, 9, 6, 10, 2, 2, 6, 5, 7, 6, 5, 10, 8, 10, 9, 9, 9, 9, 9 },
        { 8, 10, 7, 7, 7, 8, 7, 10, 3, 9, 3, 3, 6, 9, 4, 4, 5, 6, 4, 9, 9, 5, 3, 9, 7, 9, 8, 9, 5, 2, 1, 3, 5, 8, 6, 6, 8, 9, 2, 7, 7, 6, 7, 7, 3, 2, 5, 7, 9, 9, 9, 7, 11, 10, 8, 11, 7, 11, 9, 8, 10, 6, 2, 2, 4, 12, 11, 8, 10, 8, 7, 8, 8, 8, 9, 8, 8, 5, 10, 3, 2, 7, 6, 6, 5, 5, 10, 8, 10, 8, 8, 8, 8, 8 },
        { 7, 8, 6, 9, 9, 10, 8, 9, 5, 8, 5, 5, 8, 7, 5, 2, 2, 5, 3, 8, 7, 4, 2, 8, 8, 6, 6, 7, 7, 4, 3, 1, 6, 6, 5, 5, 8, 8, 2, 5, 7, 7, 5, 6, 3, 2, 6, 5, 7, 7, 8, 6, 9, 9, 6, 10, 6, 9, 8, 6, 9, 5, 3, 4, 6, 11, 10, 7, 9, 7, 6, 8, 9, 7, 7, 7, 7, 3, 8, 4, 3, 9, 7, 3, 4, 3, 9, 7, 9, 7, 7, 7, 7, 7 },
        { 5, 10, 6, 4, 4, 5, 4, 10, 3, 8, 2, 2, 3, 11, 3, 7, 8, 7, 5, 6, 11, 7, 5, 7, 5, 10, 9, 12, 2, 3, 5, 6, 1, 10, 8, 8, 5, 6, 6, 8, 4, 5, 10, 8, 3, 5, 4, 9, 11, 9, 7, 10, 8, 8, 10, 9, 7, 11, 10, 10, 11, 6, 6, 5, 3, 9, 8, 4, 7, 5, 9, 5, 5, 9, 10, 9, 9, 8, 10, 2, 3, 4, 3, 9, 8, 6, 8, 7, 8, 9, 9, 9, 9, 9 },
        { 8, 6, 6, 11, 10, 12, 9, 7, 9, 6, 9, 8, 11, 3, 7, 5, 4, 5, 6, 7, 2, 5, 6, 8, 9, 4, 4, 3, 10, 8, 8, 6, 10, 1, 5, 3, 9, 8, 7, 4, 8, 8, 2, 4, 7, 7, 9, 2, 2, 7, 7, 2, 8, 7, 2, 8, 6, 7, 5, 3, 6, 7, 8, 8, 10, 9, 9, 8, 8, 7, 3, 9, 9, 5, 4, 5, 5, 3, 6, 8, 8, 12, 10, 3, 3, 5, 8, 6, 9, 5, 5, 5, 5, 5 },
        { 5, 5, 3, 8, 7, 9, 6, 6, 7, 4, 7, 6, 8, 5, 5, 3, 4, 2, 3, 5, 6, 2, 3, 5, 6, 4, 3, 7, 7, 6, 6, 5, 8, 5, 1, 2, 6, 5, 6, 2, 5, 5, 4, 3, 5, 5, 6, 3, 5, 5, 5, 4, 6, 5, 5, 7, 3, 6, 5, 4, 6, 3, 6, 7, 8, 8, 7, 5, 6, 4, 3, 6, 6, 5, 5, 5, 5, 3, 5, 6, 6, 8, 7, 4, 2, 2, 6, 4, 6, 5, 5, 5, 5, 5 },
        { 6, 5, 4, 9, 8, 10, 7, 6, 8, 5, 8, 6, 9, 4, 5, 3, 4, 3, 4, 5, 5, 3, 4, 6, 7, 4, 3, 6, 8, 7, 6, 5, 8, 3, 2, 1, 7, 6, 6, 2, 6, 6, 3, 3, 6, 6, 7, 2, 4, 5, 5, 3, 7, 6, 4, 7, 4, 6, 4, 3, 6, 4, 7, 7, 9, 8, 8, 6, 6, 5, 2, 7, 7, 5, 4, 5, 5, 3, 5, 7, 6, 9, 8, 3, 2, 3, 7, 4, 7, 5, 5, 5, 5, 5 },
        { 2, 8, 3, 3, 2, 5, 2, 8, 7, 6, 6, 6, 5, 9, 6, 7, 8, 5, 6, 3, 10, 5, 7, 5, 2, 8, 7, 11, 3, 7, 8, 8, 4, 9, 6, 7, 1, 3, 9, 6, 2, 3, 9, 6, 7, 8, 3, 8, 9, 7, 5, 8, 6, 6, 10, 7, 4, 9, 8, 8, 9, 3, 9, 8, 6, 7, 6, 2, 4, 3, 8, 2, 3, 7, 8, 7, 7, 8, 8, 7, 7, 5, 3, 8, 7, 6, 6, 6, 6, 7, 7, 7, 7, 7 },
        { 2, 6, 3, 6, 5, 7, 4, 6, 8, 3, 7, 7, 6, 8, 6, 7, 8, 4, 6, 2, 9, 5, 7, 2, 4, 6, 6, 10, 5, 8, 9, 8, 6, 8, 5, 6, 3, 1, 9, 5, 3, 4, 8, 5, 8, 8, 5, 7, 8, 5, 3, 7, 4, 4, 9, 5, 3, 7, 6, 7, 7, 4, 9, 10, 7, 5, 4, 3, 2, 2, 7, 3, 3, 6, 7, 6, 6, 7, 7, 8, 8, 7, 5, 8, 6, 6, 3, 3, 3, 6, 6, 6, 6, 6 },
        { 8, 10, 7, 8, 8, 9, 8, 10, 4, 9, 5, 5, 7, 8, 5, 4, 3, 6, 5, 8, 8, 5, 3, 9, 8, 8, 7, 9, 6, 3, 2, 2, 6, 7, 6, 6, 9, 9, 1, 7, 8, 7, 6, 7, 3, 2, 6, 6, 8, 9, 9, 7, 11, 10, 7, 11, 7, 11, 9, 7, 10, 6, 2, 3, 5, 12, 11, 8, 10, 8, 7, 9, 9, 8, 9, 8, 8, 5, 9, 4, 3, 8, 7, 5, 5, 5, 10, 8, 10, 8, 8, 8, 8, 8 },
        { 5, 5, 3, 9, 8, 10, 7, 5, 8, 4, 8, 6, 8, 4, 6, 4, 4, 2, 5, 5, 5, 3, 5, 6, 6, 3, 2, 6, 8, 7, 7, 5, 8, 4, 2, 2, 6, 5, 7, 1, 5, 6, 4, 2, 6, 6, 7, 3, 4, 4, 5, 3, 6, 5, 5, 6, 3, 6, 4, 3, 5, 4, 7, 7, 9, 7, 7, 5, 6, 5, 2, 6, 6, 4, 4, 4, 4, 4, 5, 7, 7, 9, 8, 4, 3, 3, 6, 3, 7, 4, 4, 4, 4, 4 },
        { 3, 7, 2, 5, 3, 6, 2, 7, 7, 5, 6, 5, 5, 8, 3, 6, 7, 3, 3, 3, 9, 3, 6, 4, 2, 7, 6, 10, 3, 6, 7, 7, 4, 8, 5, 6, 2, 3, 8, 5, 1, 2, 8, 5, 6, 7, 3, 7, 8, 6, 5, 7, 6, 6, 9, 7, 3, 8, 7, 7, 8, 2, 8, 8, 6, 7, 6, 2, 4, 2, 6, 3, 4, 6, 7, 6, 6, 6, 7, 6, 6, 5, 3, 7, 6, 5, 6, 5, 5, 6, 6, 6, 6, 6 },
        { 3, 8, 3, 5, 5, 6, 2, 8, 6, 6, 6, 3, 5, 8, 2, 6, 7, 5, 3, 4, 9, 3, 6, 5, 3, 7, 7, 10, 3, 6, 6, 7, 4, 8, 5, 6, 3, 4, 7, 6, 2, 1, 8, 6, 3, 6, 2, 7, 9, 7, 6, 7, 7, 7, 9, 8, 3, 9, 8, 7, 9, 2, 7, 7, 6, 8, 7, 3, 5, 3, 7, 4, 4, 7, 8, 7, 7, 6, 8, 5, 5, 5, 3, 7, 6, 5, 6, 5, 6, 7, 7, 7, 7, 7 },
        { 7, 7, 6, 11, 10, 12, 9, 8, 8, 6, 8, 7, 11, 4, 6, 4, 3, 5, 5, 7, 3, 5, 5, 8, 8, 5, 5, 3, 10, 7, 7, 5, 9, 2, 4, 3, 9, 8, 6, 4, 7, 8, 1, 4, 6, 6, 8, 2, 3, 7, 7, 3, 8, 7, 2, 9, 6, 7, 6, 4, 7, 6, 7, 7, 9, 10, 10, 7, 8, 7, 3, 9, 9, 5, 5, 5, 5, 3, 6, 8, 7, 11, 10, 2, 3, 4, 9, 6, 9, 5, 5, 5, 5, 5 },
        { 5, 3, 3, 8, 8, 10, 7, 5, 8, 3, 8, 7, 8, 4, 6, 5, 5, 2, 5, 3, 5, 3, 5, 5, 6, 3, 2, 7, 8, 7, 7, 6, 8, 4, 3, 3, 6, 5, 7, 2, 5, 6, 4, 1, 6, 7, 7, 4, 5, 3, 4, 4, 5, 4, 5, 6, 2, 5, 3, 3, 5, 4, 8, 8, 9, 7, 7, 5, 5, 3, 3, 6, 6, 3, 4, 3, 3, 4, 4, 7, 7, 9, 8, 5, 4, 4, 6, 2, 6, 3, 3, 3, 3, 3 },
        { 7, 9, 6, 7, 7, 8, 6, 9, 4, 8, 4, 2, 7, 8, 2, 3, 3, 6, 2, 7, 8, 3, 2, 8, 7, 8, 7, 9, 3, 3, 3, 3, 3, 7, 5, 6, 7, 8, 3, 6, 6, 4, 6, 6, 1, 2, 4, 6, 8, 8, 8, 7, 9, 9, 7, 11, 6, 10, 8, 7, 9, 3, 4, 4, 5, 10, 10, 6, 8, 7, 6, 7, 8, 8, 8, 8, 8, 5, 9, 3, 2, 7, 6, 6, 5, 3, 9, 7, 9, 8, 8, 8, 8, 8 },
        { 8, 9, 6, 7, 8, 9, 7, 10, 4, 8, 4, 3, 7, 8, 3, 3, 3, 6, 3, 8, 8, 5, 2, 9, 7, 8, 7, 9, 6, 3, 2, 2, 5, 7, 5, 6, 8, 8, 2, 6, 7, 6, 6, 7, 2, 1, 5, 6, 8, 9, 9, 7, 10, 9, 7, 10, 6, 10, 8, 7, 10, 5, 3, 3, 5, 11, 10, 7, 9, 7, 7, 8, 9, 8, 8, 8, 8, 5, 9, 3, 2, 7, 6, 5, 5, 3, 10, 7, 10, 8, 8, 8, 8, 8 },
        { 4, 9, 5, 5, 5, 7, 2, 9, 5, 7, 5, 2, 4, 9, 2, 6, 7, 6, 3, 5, 10, 5, 5, 6, 3, 8, 7, 11, 3, 5, 5, 6, 4, 9, 6, 7, 3, 5, 6, 7, 3, 2, 9, 7, 3, 5, 1, 8, 10, 8, 7, 8, 8, 8, 9, 9, 4, 10, 8, 8, 10, 3, 6, 6, 5, 9, 8, 3, 6, 5, 8, 5, 5, 8, 9, 8, 8, 7, 9, 3, 3, 5, 4, 8, 7, 5, 8, 6, 7, 8, 8, 8, 8, 8 },
        { 7, 6, 5, 10, 9, 11, 8, 7, 8, 5, 8, 7, 10, 4, 6, 3, 3, 4, 5, 6, 3, 4, 5, 7, 8, 4, 3, 5, 9, 7, 7, 5, 9, 2, 3, 2, 8, 7, 6, 3, 7, 7, 2, 4, 6, 6, 8, 1, 3, 6, 6, 2, 7, 7, 3, 8, 5, 6, 5, 3, 6, 5, 7, 7, 9, 9, 9, 7, 7, 6, 2, 8, 8, 5, 4, 5, 5, 2, 5, 7, 7, 10, 9, 2, 2, 3, 8, 5, 8, 5, 5, 5, 5, 5 },
        { 8, 5, 6, 11, 11, 12, 10, 6, 10, 6, 10, 9, 11, 2, 8, 6, 5, 5, 7, 7, 3, 6, 7, 8, 9, 3, 3, 5, 11, 9, 9, 7, 11, 2, 5, 4, 9, 8, 8, 4, 8, 9, 3, 5, 8, 8, 10, 3, 1, 6, 7, 2, 7, 7, 3, 8, 6, 5, 4, 2, 5, 7, 9, 9, 11, 9, 9, 8, 8, 8, 3, 9, 9, 5, 4, 5, 5, 5, 4, 10, 9, 12, 10, 5, 5, 6, 8, 6, 8, 5, 5, 5, 5, 5 },
        { 5, 2, 5, 9, 8, 10, 7, 2, 10, 2, 10, 8, 9, 5, 8, 7, 7, 4, 7, 3, 7, 6, 7, 4, 7, 4, 4, 9, 8, 10, 9, 8, 9, 7, 5, 5, 7, 5, 9, 4, 6, 7, 6, 3, 8, 9, 8, 6, 6, 1, 2, 6, 3, 2, 8, 4, 4, 3, 3, 5, 4, 6, 10, 10, 10, 4, 4, 6, 3, 5, 5, 6, 6, 3, 4, 3, 3, 7, 3, 9, 9, 9, 8, 7, 6, 6, 3, 3, 4, 3, 3, 3, 3, 3 },
        { 4, 3, 4, 8, 7, 9, 6, 3, 10, 2, 9, 8, 8, 6, 7, 7, 8, 4, 7, 2, 8, 6, 7, 3, 5, 5, 5, 9, 7, 9, 9, 8, 7, 7, 5, 5, 5, 3, 9, 5, 5, 6, 7, 4, 8, 9, 7, 6, 7, 2, 1, 6, 3, 2, 8, 4, 3, 5, 5, 6, 5, 5, 10, 10, 9, 3, 3, 4, 2, 3, 6, 5, 5, 4, 5, 4, 4, 7, 5, 9, 9, 8, 7, 7, 6, 6, 2, 3, 3, 4, 4, 4, 4, 4 },
        { 7, 6, 5, 10, 10, 12, 8, 7, 9, 6, 9, 8, 10, 3, 7, 5, 4, 4, 6, 7, 3, 5, 6, 7, 8, 3, 3, 4, 9, 8, 7, 6, 10, 2, 4, 3, 8, 7, 7, 3, 7, 7, 3, 4, 7, 7, 8, 2, 2, 6, 6, 1, 7, 6, 3, 7, 5, 6, 5, 2, 6, 6, 8, 8, 10, 9, 9, 7, 7, 7, 2, 8, 8, 5, 4, 5, 5, 3, 5, 8, 7, 11, 9, 3, 3, 5, 8, 5, 8, 5, 5, 5, 5, 5 },
        { 5, 4, 5, 9, 8, 10, 7, 3, 11, 4, 10, 9, 9, 7, 8, 8, 9, 6, 8, 4, 9, 7, 8, 4, 7, 6, 5, 10, 8, 11, 11, 9, 8, 8, 6, 7, 6, 4, 11, 6, 6, 7, 8, 5, 9, 10, 8, 7, 7, 3, 3, 7, 1, 2, 9, 2, 5, 5, 5, 7, 5, 6, 11, 11, 10, 2, 3, 6, 3, 5, 7, 6, 6, 5, 6, 5, 5, 8, 5, 10, 10, 9, 8, 9, 7, 7, 2, 4, 3, 5, 5, 5, 5, 5 },
        { 5, 3, 5, 9, 8, 10, 7, 2, 11, 3, 10, 9, 9, 6, 8, 7, 8, 5, 7, 3, 8, 6, 8, 4, 6, 5, 4, 9, 8, 10, 10, 9, 8, 7, 5, 6, 6, 4, 10, 5, 6, 7, 7, 4, 9, 9, 8, 7, 7, 2, 2, 6, 2, 1, 8, 3, 5, 5, 4, 6, 4, 6, 10, 10, 10, 3, 3, 5, 3, 5, 6, 6, 6, 4, 5, 4, 4, 7, 4, 10, 9, 9, 8, 8, 7, 7, 2, 4, 3, 4, 4, 4, 4, 4 },
        { 9, 7, 7, 12, 11, 12, 10, 8, 9, 7, 9, 8, 12, 4, 8, 5, 4, 6, 7, 8, 2, 7, 6, 9, 9, 5, 5, 2, 11, 8, 8, 6, 10, 2, 5, 4, 10, 9, 7, 5, 8, 9, 2, 5, 8, 7, 9, 3, 3, 8, 8, 3, 9, 8, 1, 9, 7, 8, 6, 4, 7, 7, 8, 8, 10, 10, 10, 9, 9, 8, 4, 10, 10, 6, 5, 6, 6, 4, 7, 9, 8, 12, 11, 3, 4, 6, 9, 7, 10, 6, 6, 6, 6, 6 },
        { 5, 4, 6, 9, 8, 11, 7, 4, 11, 4, 11, 10, 9, 7, 9, 9, 9, 6, 8, 4, 9, 7, 9, 4, 7, 6, 6, 10, 8, 11, 11, 10, 9, 8, 7, 7, 7, 5, 11, 6, 7, 8, 8, 6, 10, 10, 9, 8, 8, 4, 4, 7, 2, 3, 9, 1, 6, 5, 5, 7, 5, 7, 11, 12, 11, 2, 3, 6, 4, 5, 7, 7, 6, 5, 6, 5, 5, 8, 5, 11, 11, 10, 8, 9, 8, 8, 3, 5, 4, 5, 5, 5, 5, 5 },
        { 3, 5, 2, 7, 6, 9, 5, 5, 8, 3, 8, 6, 7, 6, 5, 5, 5, 2, 5, 2, 7, 3, 5, 4, 4, 5, 3, 8, 6, 7, 7, 6, 7, 6, 3, 4, 4, 3, 7, 3, 3, 3, 6, 2, 6, 6, 4, 5, 6, 4, 3, 5, 5, 5, 7, 6, 1, 6, 5, 5, 6, 3, 8, 8, 8, 6, 6, 3, 3, 2, 4, 5, 5, 4, 5, 4, 4, 5, 5, 7, 7, 7, 6, 5, 4, 4, 5, 2, 5, 4, 4, 4, 4, 4 },
        { 7, 2, 7, 11, 10, 12, 9, 3, 12, 5, 12, 10, 11, 5, 10, 8, 8, 6, 8, 6, 7, 7, 8, 7, 9, 4, 5, 8, 11, 11, 11, 9, 11, 7, 6, 6, 9, 7, 11, 6, 8, 9, 7, 5, 9, 10, 10, 6, 5, 3, 5, 6, 5, 5, 7, 5, 6, 1, 3, 5, 2, 8, 11, 11, 12, 7, 7, 8, 6, 7, 6, 9, 9, 4, 3, 4, 4, 8, 2, 11, 10, 12, 10, 8, 7, 7, 6, 5, 7, 4, 4, 4, 4, 4 },
        { 7, 2, 5, 10, 10, 12, 8, 3, 10, 3, 10, 9, 10, 3, 8, 6, 7, 5, 7, 5, 6, 6, 7, 6, 8, 2, 3, 7, 9, 9, 9, 8, 10, 5, 5, 4, 8, 6, 9, 4, 7, 8, 5, 3, 8, 8, 8, 5, 4, 3, 5, 5, 5, 4, 6, 5, 5, 3, 1, 3, 3, 6, 10, 10, 11, 6, 6, 7, 6, 6, 4, 8, 8, 3, 2, 3, 3, 6, 2, 9, 9, 11, 9, 6, 5, 6, 6, 3, 6, 3, 3, 3, 3, 3 },
        { 7, 5, 5, 10, 9, 12, 8, 6, 9, 5, 9, 8, 10, 2, 7, 5, 5, 4, 6, 6, 4, 5, 6, 7, 8, 2, 2, 5, 9, 8, 8, 6, 10, 3, 4, 3, 8, 7, 7, 3, 7, 7, 4, 3, 7, 7, 8, 3, 2, 5, 6, 2, 7, 6, 4, 7, 5, 5, 3, 1, 5, 6, 8, 8, 10, 8, 8, 7, 7, 6, 2, 8, 8, 4, 3, 4, 4, 4, 4, 8, 8, 10, 9, 4, 4, 5, 7, 5, 7, 4, 4, 4, 4, 4 },
        { 7, 2, 6, 11, 10, 12, 9, 4, 11, 4, 11, 10, 11, 4, 9, 8, 8, 6, 8, 6, 7, 7, 8, 6, 9, 4, 4, 8, 10, 10, 10, 9, 11, 6, 6, 6, 9, 7, 10, 5, 8, 9, 7, 5, 9, 10, 10, 6, 5, 3, 5, 6, 5, 4, 7, 5, 6, 2, 3, 5, 1, 7, 11, 11, 12, 6, 6, 8, 6, 7, 5, 8, 8, 4, 3, 4, 4, 7, 2, 11, 10, 11, 10, 7, 7, 7, 6, 5, 7, 4, 4, 4, 4, 4 },
        { 3, 6, 2, 6, 6, 8, 3, 7, 7, 5, 6, 3, 6, 7, 2, 4, 6, 3, 2, 3, 8, 2, 3, 5, 3, 6, 5, 9, 6, 6, 6, 5, 6, 7, 3, 4, 3, 4, 6, 4, 2, 2, 7, 4, 3, 5, 3, 5, 7, 6, 5, 6, 6, 6, 7, 7, 3, 8, 6, 6, 7, 1, 7, 7, 7, 7, 7, 3, 4, 3, 5, 4, 5, 5, 6, 5, 5, 5, 7, 5, 5, 7, 6, 6, 4, 3, 6, 4, 6, 5, 5, 5, 5, 5 },
        { 9, 10, 7, 8, 8, 10, 8, 11, 4, 10, 5, 5, 7, 9, 6, 5, 5, 7, 5, 9, 9, 6, 4, 10, 8, 9, 8, 9, 6, 3, 2, 3, 6, 8, 6, 7, 9, 9, 2, 7, 8, 7, 7, 8, 4, 3, 6, 7, 9, 10, 10, 8, 11, 10, 8, 12, 8, 12, 10, 8, 11, 7, 1, 2, 5, 12, 11, 9, 10, 9, 7, 9, 9, 9, 9, 9, 9, 5, 10, 4, 3, 8, 7, 6, 6, 5, 11, 8, 11, 9, 9, 9, 9, 9 },
        { 9, 10, 7, 8, 8, 10, 7, 11, 3, 10, 4, 5, 7, 9, 5, 5, 6, 7, 5, 9, 9, 6, 4, 10, 7, 9, 8, 9, 6, 2, 2, 4, 5, 8, 7, 7, 8, 10, 3, 7, 8, 7, 7, 8, 4, 3, 6, 7, 9, 10, 10, 8, 11, 10, 8, 12, 8, 12, 10, 8, 11, 7, 2, 1, 5, 12, 12, 8, 10, 9, 8, 9, 9, 9, 10, 9, 9, 6, 10, 3, 3, 8, 6, 6, 6, 5, 11, 9, 11, 9, 9, 9, 9, 9 },
        { 7, 11, 8, 5, 6, 7, 6, 11, 2, 10, 2, 4, 5, 11, 6, 7, 8, 8, 6, 8, 11, 8, 5, 8, 6, 10, 10, 12, 4, 3, 4, 6, 3, 10, 8, 9, 7, 7, 5, 9, 6, 6, 10, 9, 5, 5, 6, 9, 11, 10, 9, 10, 10, 10, 11, 11, 8, 12, 11, 10, 12, 7, 5, 5, 1, 11, 10, 6, 9, 7, 10, 6, 7, 11, 11, 11, 11, 8, 12, 3, 4, 5, 4, 9, 8, 7, 10, 9, 9, 11, 11, 11, 11, 11 },
        { 5, 5, 6, 9, 8, 11, 7, 5, 12, 5, 11, 10, 9, 8, 9, 9, 10, 6, 8, 5, 10, 7, 9, 4, 7, 7, 6, 12, 9, 11, 12, 11, 9, 9, 8, 8, 7, 5, 12, 7, 7, 8, 9, 7, 10, 11, 9, 9, 9, 4, 3, 9, 2, 3, 10, 2, 6, 7, 6, 8, 6, 7, 12, 12, 11, 1, 2, 6, 3, 6, 8, 7, 6, 6, 7, 6, 6, 9, 6, 11, 11, 10, 8, 10, 8, 8, 2, 5, 3, 6, 6, 6, 6, 6 },
        { 5, 5, 6, 8, 8, 10, 7, 5, 11, 5, 10, 9, 9, 8, 9, 9, 10, 6, 8, 4, 10, 7, 9, 3, 6, 7, 6, 12, 8, 11, 11, 10, 8, 9, 8, 8, 6, 4, 11, 7, 6, 7, 9, 7, 10, 10, 8, 9, 9, 4, 3, 9, 3, 3, 10, 3, 6, 7, 6, 8, 6, 7, 11, 12, 10, 2, 1, 5, 3, 5, 8, 6, 6, 6, 7, 6, 6, 9, 6, 10, 10, 9, 8, 10, 8, 8, 2, 5, 2, 6, 6, 6, 6, 6 },
        { 2, 7, 3, 5, 3, 6, 2, 7, 7, 5, 6, 5, 5, 8, 5, 6, 7, 4, 5, 2, 9, 4, 6, 4, 2, 6, 6, 10, 4, 7, 8, 7, 4, 8, 5, 6, 2, 3, 8, 5, 2, 2, 8, 5, 6, 7, 2, 7, 8, 6, 4, 7, 6, 5, 9, 6, 2, 8, 7, 7, 8, 2, 9, 8, 6, 6, 5, 1, 2, 2, 6, 3, 3, 6, 7, 6, 6, 6, 8, 6, 6, 5, 4, 7, 6, 5, 5, 5, 5, 6, 6, 6, 6, 6 },
        { 3, 5, 4, 7, 6, 9, 6, 5, 10, 3, 9, 8, 7, 7, 7, 7, 8, 5, 7, 2, 9, 6, 8, 2, 4, 6, 6, 10, 7, 9, 10, 9, 7, 8, 6, 6, 4, 2, 10, 6, 4, 5, 8, 5, 8, 9, 6, 7, 8, 3, 2, 7, 3, 3, 9, 4, 3, 6, 6, 7, 6, 4, 10, 10, 9, 3, 3, 3, 1, 3, 7, 5, 4, 5, 6, 5, 5, 8, 6, 9, 9, 8, 6, 8, 7, 7, 2, 3, 2, 5, 5, 5, 5, 5 },
        { 2, 6, 2, 5, 5, 7, 3, 6, 8, 3, 7, 6, 5, 7, 5, 6, 7, 3, 5, 2, 8, 3, 6, 3, 4, 6, 6, 10, 5, 8, 8, 7, 5, 7, 4, 5, 3, 2, 8, 5, 2, 3, 7, 3, 7, 7, 5, 6, 8, 5, 3, 7, 5, 5, 8, 5, 2, 7, 6, 6, 7, 3, 9, 9, 7, 6, 5, 2, 3, 1, 6, 3, 3, 5, 7, 5, 5, 6, 7, 7, 7, 6, 4, 7, 6, 5, 4, 3, 4, 5, 5, 5, 5, 5 },
        { 6, 5, 5, 10, 9, 11, 8, 6, 9, 5, 9, 7, 10, 3, 6, 4, 4, 3, 5, 6, 4, 4, 5, 7, 7, 3, 2, 5, 9, 8, 7, 6, 9, 3, 3, 2, 8, 7, 7, 2, 6, 7, 3, 3, 6, 7, 8, 2, 3, 5, 6, 2, 7, 6, 4, 7, 4, 6, 4, 2, 5, 5, 7, 8, 10, 8, 8, 6, 7, 6, 1, 7, 8, 4, 4, 4, 4, 3, 4, 8, 7, 10, 9, 3, 3, 4, 7, 4, 7, 4, 4, 4, 4, 4 },
        { 2, 7, 4, 3, 2, 6, 3, 7, 7, 5, 7, 6, 5, 9, 6, 7, 8, 5, 6, 4, 10, 6, 7, 4, 3, 8, 7, 11, 5, 7, 8, 8, 5, 9, 6, 7, 2, 3, 9, 6, 3, 4, 9, 6, 8, 8, 5, 8, 9, 7, 5, 8, 7, 6, 10, 7, 5, 9, 8, 8, 8, 4, 9, 9, 7, 7, 6, 3, 5, 3, 7, 1, 2, 7, 8, 7, 7, 8, 8, 7, 7, 6, 5, 8, 7, 6, 7, 5, 5, 7, 7, 7, 7, 7 },
        { 2, 7, 4, 5, 3, 6, 4, 7, 8, 5, 7, 7, 5, 9, 6, 7, 8, 5, 6, 4, 10, 6, 8, 4, 4, 8, 7, 11, 5, 8, 8, 9, 5, 9, 6, 7, 3, 3, 9, 6, 4, 4, 9, 6, 8, 9, 5, 8, 9, 7, 5, 8, 7, 6, 10, 6, 5, 9, 8, 8, 8, 5, 9, 9, 7, 6, 6, 3, 4, 3, 8, 2, 1, 7, 8, 7, 7, 8, 8, 7, 8, 6, 6, 9, 7, 6, 7, 5, 5, 7, 7, 7, 7, 7 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 7, 3, 6, 11, 10, 12, 9, 5, 10, 4, 10, 9, 10, 3, 8, 6, 6, 5, 7, 6, 5, 6, 7, 7, 8, 2, 3, 6, 10, 9, 9, 7, 10, 4, 5, 4, 8, 7, 9, 4, 7, 8, 5, 4, 8, 8, 9, 4, 4, 4, 5, 4, 6, 5, 5, 6, 5, 3, 2, 3, 3, 6, 9, 10, 11, 7, 7, 7, 6, 7, 4, 8, 8, 4, 1, 4, 4, 6, 2, 9, 9, 11, 10, 6, 5, 6, 6, 5, 7, 4, 4, 4, 4, 4 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 7, 7, 5, 10, 9, 11, 8, 8, 7, 6, 7, 6, 9, 5, 5, 2, 2, 4, 4, 7, 5, 4, 3, 7, 7, 5, 5, 5, 8, 6, 5, 3, 8, 3, 3, 3, 8, 7, 5, 4, 6, 6, 3, 4, 5, 5, 7, 2, 5, 7, 7, 3, 8, 7, 4, 8, 5, 8, 6, 4, 7, 5, 5, 6, 8, 9, 9, 6, 8, 6, 3, 8, 8, 6, 6, 6, 6, 1, 7, 6, 5, 10, 9, 2, 2, 3, 8, 6, 8, 6, 6, 6, 6, 6 },
        { 7, 2, 6, 11, 10, 12, 9, 3, 11, 4, 11, 9, 11, 4, 9, 7, 7, 5, 8, 6, 6, 6, 8, 6, 8, 3, 4, 8, 10, 10, 10, 8, 10, 6, 5, 5, 8, 7, 9, 5, 7, 8, 6, 4, 9, 9, 9, 5, 4, 3, 5, 5, 5, 4, 7, 5, 5, 2, 2, 4, 2, 7, 10, 10, 12, 6, 6, 8, 6, 7, 4, 8, 8, 4, 2, 4, 4, 7, 1, 10, 9, 11, 10, 7, 6, 7, 6, 4, 7, 4, 4, 4, 4, 4 },
        { 7, 10, 6, 6, 6, 7, 6, 10, 3, 8, 2, 2, 5, 9, 3, 5, 6, 7, 4, 8, 9, 5, 4, 8, 6, 9, 8, 10, 3, 2, 3, 4, 2, 9, 6, 7, 7, 8, 4, 7, 6, 5, 8, 7, 3, 3, 3, 7, 10, 9, 9, 8, 10, 10, 9, 11, 7, 11, 9, 8, 11, 5, 4, 3, 3, 11, 10, 6, 9, 7, 8, 7, 7, 9, 9, 9, 9, 6, 10, 1, 2, 6, 5, 7, 6, 5, 10, 8, 9, 9, 9, 9, 9, 9 },
        { 7, 9, 6, 7, 7, 8, 6, 10, 3, 8, 3, 2, 6, 9, 3, 4, 5, 6, 3, 8, 9, 5, 3, 9, 6, 8, 8, 9, 3, 2, 2, 3, 3, 8, 6, 6, 7, 8, 3, 7, 6, 5, 7, 7, 2, 2, 3, 7, 9, 9, 9, 7, 10, 9, 8, 11, 7, 10, 9, 8, 10, 5, 3, 3, 4, 11, 10, 7, 9, 7, 7, 7, 8, 8, 9, 8, 8, 5, 9, 2, 1, 7, 5, 6, 5, 4, 10, 8, 10, 8, 8, 8, 8, 8 },
        { 6, 10, 7, 2, 3, 2, 4, 11, 6, 9, 5, 6, 2, 11, 7, 9, 10, 8, 8, 7, 12, 8, 8, 7, 4, 10, 10, 12, 4, 6, 7, 9, 4, 12, 8, 9, 5, 7, 8, 9, 5, 6, 12, 9, 7, 7, 5, 10, 12, 9, 8, 11, 9, 9, 12, 10, 7, 12, 11, 10, 11, 7, 8, 8, 5, 10, 9, 5, 8, 6, 10, 5, 6, 10, 11, 10, 10, 10, 11, 6, 7, 1, 2, 11, 9, 9, 9, 8, 8, 10, 10, 10, 10, 10 },
        { 4, 9, 6, 2, 3, 3, 2, 9, 5, 7, 4, 3, 2, 10, 6, 8, 9, 7, 7, 6, 11, 7, 7, 6, 2, 9, 8, 12, 2, 5, 6, 7, 3, 10, 7, 8, 3, 5, 7, 8, 3, 3, 10, 8, 6, 6, 3, 9, 10, 8, 7, 9, 8, 8, 11, 8, 6, 10, 10, 9, 10, 6, 7, 6, 4, 8, 8, 4, 6, 4, 9, 4, 5, 8, 10, 8, 8, 9, 10, 4, 5, 2, 1, 9, 8, 7, 7, 7, 7, 8, 8, 8, 8, 8 },
        { 7, 7, 6, 10, 10, 12, 9, 8, 7, 7, 8, 7, 10, 5, 6, 3, 2, 5, 5, 7, 4, 5, 3, 8, 8, 5, 5, 5, 9, 7, 6, 3, 9, 3, 4, 3, 8, 8, 5, 4, 7, 7, 2, 5, 6, 5, 8, 2, 5, 7, 7, 3, 9, 8, 3, 9, 5, 8, 6, 4, 7, 6, 6, 6, 9, 10, 10, 7, 8, 7, 3, 8, 9, 6, 6, 6, 6, 2, 7, 7, 6, 11, 9, 1, 3, 4, 9, 6, 9, 6, 6, 6, 6, 6 },
        { 6, 6, 4, 9, 8, 10, 7, 7, 7, 5, 7, 5, 9, 5, 5, 2, 3, 3, 3, 6, 5, 3, 3, 7, 7, 5, 4, 6, 8, 6, 5, 3, 8, 3, 2, 2, 7, 6, 5, 3, 6, 6, 3, 4, 5, 5, 7, 2, 5, 6, 6, 3, 7, 7, 4, 8, 4, 7, 5, 4, 7, 4, 6, 6, 8, 9, 8, 6, 7, 6, 3, 7, 7, 5, 5, 5, 5, 2, 6, 6, 5, 9, 8, 3, 1, 2, 7, 5, 8, 5, 5, 5, 5, 5 },
        { 5, 7, 3, 8, 8, 10, 6, 7, 6, 5, 6, 5, 8, 6, 3, 2, 3, 3, 2, 5, 6, 2, 2, 6, 6, 5, 5, 7, 7, 5, 5, 3, 6, 5, 2, 3, 6, 6, 5, 3, 5, 5, 4, 4, 3, 3, 5, 3, 6, 6, 6, 5, 7, 7, 6, 8, 4, 8, 6, 5, 7, 3, 5, 5, 7, 9, 8, 5, 7, 5, 4, 6, 6, 5, 6, 5, 5, 3, 7, 5, 4, 9, 7, 4, 2, 1, 7, 5, 7, 5, 5, 5, 5, 5 },
        { 4, 5, 5, 8, 7, 10, 6, 3, 10, 3, 9, 9, 8, 7, 8, 8, 9, 6, 8, 3, 9, 6, 8, 3, 6, 6, 6, 11, 7, 10, 10, 9, 8, 8, 6, 7, 6, 3, 10, 6, 6, 6, 8, 6, 9, 10, 8, 8, 8, 3, 2, 8, 2, 2, 9, 3, 5, 6, 6, 7, 6, 6, 11, 11, 10, 3, 2, 5, 2, 4, 7, 5, 5, 5, 6, 5, 5, 8, 6, 10, 10, 9, 7, 9, 7, 7, 1, 4, 2, 5, 5, 5, 5, 5 },
        { 4, 3, 3, 8, 7, 9, 6, 4, 9, 2, 9, 7, 8, 5, 6, 6, 6, 2, 6, 2, 7, 4, 6, 4, 6, 4, 3, 8, 7, 8, 8, 7, 7, 6, 3, 4, 6, 3, 8, 3, 5, 5, 6, 2, 7, 7, 6, 5, 6, 3, 3, 5, 4, 4, 7, 5, 2, 5, 3, 5, 5, 4, 8, 9, 9, 5, 5, 5, 3, 3, 4, 5, 5, 3, 5, 3, 3, 6, 4, 8, 8, 8, 7, 6, 5, 5, 4, 1, 4, 3, 3, 3, 3, 3 },
        { 4, 5, 5, 8, 7, 9, 6, 5, 10, 4, 9, 9, 8, 8, 8, 8, 9, 6, 7, 3, 10, 6, 8, 2, 6, 7, 6, 11, 7, 10, 10, 9, 8, 9, 6, 7, 6, 3, 10, 7, 5, 6, 9, 6, 9, 10, 7, 8, 8, 4, 3, 8, 3, 3, 10, 4, 5, 7, 6, 7, 7, 6, 11, 11, 9, 3, 2, 5, 2, 4, 7, 5, 5, 6, 7, 6, 6, 8, 7, 9, 10, 8, 7, 9, 8, 7, 2, 4, 1, 6, 6, 6, 6, 6 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
        { 6, 3, 4, 9, 9, 11, 8, 4, 10, 3, 10, 8, 9, 4, 7, 6, 6, 4, 6, 5, 6, 5, 6, 5, 7, 3, 3, 7, 9, 9, 8, 7, 9, 5, 4, 4, 7, 6, 8, 4, 6, 7, 5, 3, 8, 8, 8, 4, 4, 3, 4, 4, 5, 4, 6, 5, 4, 4, 3, 4, 4, 5, 9, 9, 11, 6, 6, 6, 5, 6, 4, 7, 7, 2, 4, 2, 2, 6, 4, 9, 8, 10, 8, 6, 5, 5, 5, 3, 6, 2, 2, 2, 2, 2 },
    };
    
    do {
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
        
        printf("Zone = %d\n", table[arr][dep]);
        
        printf("\nContinuer ? ");
        scanf("%d", &run);
        printf("\n");
    } while (run);
    
    
    return 0;
}
