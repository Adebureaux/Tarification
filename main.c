//
//  main.c
//  Tarification
//
//  Created by Augustin Debureaux on 29/07/2019.
//  Copyright © 2019 Augustin Debureaux. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
# include "zone.h"
# include "tarif.h"

int main(int argc, const char * argv[])
{
    // A faire : Finir tableau tarifs base
    // A faire : Trouver un moyen d'arrondire à 0.00 près
    // A faire : Tarifs +100 KG
    // A faire : Calibrage des prix base + marge
    // A faire : Corse

    // Definition de la zone
    int arr = 0, dep = 0, zoneMessagerie = 0;
    // Definition du poids
    int poids = 0;
    //Definition du tarif
    int rdv = 0;
    const double tgo = 1.13;
    double prixBase = 0, prixReel = 0.99;

    printf("Departement de depart : ");
    scanf("%d", &dep);
    printf("\nDepartement de d'arrive : ");
    scanf("%d", &arr);
    zoneMessagerie = zone(arr, dep);

    printf("\nPoids du colis : ");
    scanf("%d", &poids);
    prixBase = tarif(zoneMessagerie, poids);

    printf("\nPrise de RDV ?\n1 pour OUI 0 pour NON : ");
    scanf("%d", &rdv);
    if (rdv)
    {
        prixReel = prixReel + 2;
    }
    prixReel = (prixBase + prixReel) * tgo;
    printf("\n\nLe tarif d'achat de %lf Euros\n", prixReel);

    double prixMarge = 0;
    prixMarge = prixReel / 0.6;
    printf("\nLe tarif de vente de %lf Euros\n\n", prixMarge);

    return 0;
}
