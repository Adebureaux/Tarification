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
    // Definition du mode
    int mode = 1, run = 1;
    // Definition de la zone
    int arr = 0, dep = 0, zoneMessagerie = 0;
    // Definition du poids
    int poids = 0;
    //Definition du tarif
    const double tgo = 1.13;

do
{
    double prixBase = 0, prixReel = 0, prixMarge = 0;
    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Geodis                      ----\n");
    printf("----                                               ----\n");
    printf("----     Tapez 1 pour un tarif en messagerie       ----\n");
    printf("----  Tapez 0 pour un tarif en messagerie express  ----\n");
    printf("-------------------------------------------------------\n");

    printf("\nMode de transport : ");
    scanf("%d", &mode);

    printf("Departement de depart : ");
    scanf("%d", &dep);
    printf("Departement de d'arrive : ");
    scanf("%d", &arr);

    zoneMessagerie = zone(arr, dep, mode);

    printf("Poids total : ");
    scanf("%d", &poids);

    if (mode)
    {
    prixBase = tarif(zoneMessagerie, poids, mode);
    prixReel = (prixBase * tgo) + 0.99 + 2;
    }
    else
    {
    prixBase = tarif(zoneMessagerie, poids, mode);
    prixReel = (prixBase * tgo) + 0.99 + 2 + 9;
    }

    printf("\n\nTarif d'achat : %.2lf Euros\n", prixReel);

    // Calcul du tarif avec la marge
    double diviseurMarge;
    double diviseur[30] = {0.40, 0.41, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47, 0.48, 0.49, 0.50, 0.52, 0.54, 0.56, 0.58, 0.60, 0.62, 0.64, 0.66, 0.68, 0.70, 0.71, 0.72, 0.73, 0.74, 0.75, 0.76, 0.77, 0.78, 0.79, 0.80};
    int div;

    if (prixReel < 600)
    {
    div = prixReel / 20;
    diviseurMarge = diviseur[div];
    }
    else
    {
        diviseurMarge = 0.80;
    }

    prixMarge = prixReel / diviseurMarge;

    printf("Tarif de vente : %.2lf Euros\n\n", prixMarge);

    printf("Voulez-vous continuer ? 1 -> OUI 0 -> NON : ");
    scanf("%d", &run);
    printf("\n\n\n\n\n");
} while (run);

    return 0;
}

