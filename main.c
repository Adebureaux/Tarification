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
#include "ecriture.h"

int main(int argc, const char * argv[])
{
    // Definition du mode
    int corse = 0;
    char run[2];
    char mode[2];
    long conv_run = 0;
    long conv_mode = 0;
    // Definition de la zone
    int zoneMessagerie = 0;
    char arr[3];
    char dep[3];
    long conv_arr = 0;
    long conv_dep = 0;
    // Definition du poids
    char poids[4];
    long conv_poids = 0;
    //Definition du tarif
    const double tgo = 1.13;
    int div = 0;
    double marge = 0, diviseurMarge = 0;

do
{
    double prixBase = 0, prixReel = 0, prixMarge = 0, prixTTC = 0;
    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Geodis                      ----\n");
    printf("----                                               ----\n");
    printf("----     Tapez 1 pour un tarif en messagerie       ----\n");
    printf("----  Tapez 0 pour un tarif en messagerie express  ----\n");
    printf("-------------------------------------------------------\n");

    printf("\nMode de transport : ");
    conv_mode = lire(mode, 2);

    printf("Departement de depart : ");
    conv_dep = lire(dep, 3);

    printf("Departement de d'arrive : ");
    conv_arr = lire(arr, 3);

    if (conv_dep == 20 || conv_arr == 20)
    {
        corse = 1;
    }
    else
    {
        corse = 0;
    }

    zoneMessagerie = zone(conv_arr, conv_dep, conv_mode);

    printf("Poids total : ");
    conv_poids = lire(poids, 4);

    printf("Zone : %d", zoneMessagerie);

    if (conv_mode)
    {
    prixBase = tarif(zoneMessagerie, conv_poids, conv_mode, corse);
    prixReel = (prixBase * tgo) + 0.99 + 2;
    }
    else
    {
    prixBase = tarif(zoneMessagerie, conv_poids, conv_mode, corse);
    prixReel = (prixBase * tgo) + 0.99 + 2 + 9;
    }

    printf("\n\nTarif d'achat : %.2lf Euros\n", prixReel);

    // Calcul du tarif avec la marge
    double diviseur[40] = { 0.30, 0.40, 0.45, 0.50, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.60, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69, 0.70, 0.71, 0.72, 0.73, 0.735, 0.740, 0.745, 0.750, 0.755, 0.760, 0.765, 0.770, 0.775, 0.780, 0.785, 0.790, 0.795 };

    if (prixReel < 500)
    {
        div = prixReel / 12.5;
        diviseurMarge = diviseur[div];
    }
    else
    {
        diviseurMarge = 0.80;
    }

    prixMarge = prixReel / diviseurMarge;

    printf("Tarif de vente HT : %.2lf Euros\n", prixMarge);

    prixTTC = prixMarge * 1.2;
    printf("Tarif de vente TTC : %.2lf Euros\n", prixTTC);

    // Affichage de la marge
    marge = (1 - (diviseurMarge)) * 100;
    printf("Marge : %.0lf%%\n\n", marge);

    printf("Voulez-vous continuer ? 1 -> OUI 0 -> NON : ");
    conv_run = lire(run, 2);
    printf("\n\n\n\n\n");
} while (conv_run);

    return 0;
}

