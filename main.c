//
//  main.c
//  Tarification
//
//  Created by Augustin Debureaux on 29/07/2019.
//  Copyright © 2019 Augustin Debureaux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "zone.h"
#include "tarif.h"

int main(int argc, const char * argv[])
{
    // A faire : Corse

    // Definition de la zone
    int arr = 0, dep = 0, zoneMessagerie = 0;
    // Definition du poids
    int poids = 0;
    //Definition du tarif
    const double tgo = 1.13;
    double prixBase = 0, prixReel = 2.99, prixMarge = 0;

    printf("Departement de depart : ");
    scanf("%d", &dep);
    printf("Departement de d'arrive : ");
    scanf("%d", &arr);
    zoneMessagerie = zone(arr, dep);

    printf("Poids du colis : ");
    scanf("%d", &poids);
    prixBase = tarif(zoneMessagerie, poids);

    prixReel = (prixBase + prixReel) * tgo;
    printf("\n\nLe tarif d'achat de %.2lf Euros\n", prixReel);

    if (prixReel < 100)
    {
        prixMarge = prixReel / 0.50;
    }
    else if (prixReel >= 100 && prixReel <= 199)
    {
        prixMarge = prixReel / 0.55;
    }
    else if (prixReel >= 200  && prixReel <= 299)
    {
        prixMarge = prixReel / 0.60;
    }
    else if (prixReel >= 300  && prixReel <= 399)
    {
        prixMarge = prixReel / 0.65;
    }
    else if (prixReel >= 400  && prixReel <= 499)
    {
        prixMarge = prixReel / 0.70;
    }
    else if (prixReel >= 500  && prixReel <= 599)
    {
        prixMarge = prixReel / 0.75;
    }
    else
    {
        prixMarge = prixReel / 0.80;
    }
    
    printf("Le tarif de vente de %.2lf Euros\n\n", prixMarge);

    return 0;
}
