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
    double prixBase = 0, prixReel = 2.99, prixMarge = 0;

do
{
    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Geodis                      ----\n");
    printf("----                                               ----\n");
    printf("----     Tapez 1 pour un tarif en messagerie       ----\n");
    printf("----  Tapez 0 pour un tarif en messagerie express  ----\n");
    printf("-------------------------------------------------------\n");

    scanf("%d", &mode);
    do {
    printf("\nDepartement de depart : ");
    scanf("%d", &dep);
    printf("Departement de d'arrive : ");
    scanf("%d", &arr);
    if (arr == 20 || dep == 20)
    {
        printf("\nErreur : Enlevement ou livraison en corse\n");
        printf("Merci de ressaisir\n");
    }
    } while (arr == 20 || dep == 20);

    zoneMessagerie = zone(arr, dep, mode);

    printf("Poids total : ");
    scanf("%d", &poids);

    if (mode)
    {
    prixBase = tarif(zoneMessagerie, poids, mode);
    prixReel = (prixBase + prixReel) * tgo;
    }
    else
    {
    prixBase = tarif(zoneMessagerie, poids, mode);
    prixReel = (prixBase + prixReel) * tgo;
    prixReel = prixReel + 9;
    }

    printf("\n\nTarif d'achat : %.2lf Euros\n", prixReel);

    if (prixReel < 50)
    {
        prixMarge = prixReel / 0.40;
    }
    else if (prixReel >= 50 && prixReel <= 99)
    {
        prixMarge = prixReel / 0.45;
    }
    else if (prixReel >= 100 && prixReel <= 149)
    {
        prixMarge = prixReel / 0.50;
    }
    else if (prixReel >= 150 && prixReel <= 199)
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

    printf("Tarif de vente : %.2lf Euros\n\n", prixMarge);

    printf("Voulez-vous continuer ? 1 -> OUI 0 -> NON : ");
    scanf("%d", &run);
    prixBase = 0;
    prixReel = 2.99;
    prixMarge = 0;
    printf("\n\n\n\n\n");
} while (run);

    return 0;
}
