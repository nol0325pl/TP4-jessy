//
// Created by e2508615 on 11/12/2025.
//

#ifndef CFONB_ANALYZER_CFONB_TYPES_H
#define CFONB_ANALYZER_CFONB_TYPES_H

// Dans cfonb_types.h
typedef struct {
    char commande[20];        // "load", "validate", "stats", "search"
    char fichier[256];        // Chemin du fichier
    char numeroCompte[12];    // Filtre par compte (optionnel)
    long montantMin;          // Filtre montant minimum
    char date[7];             // Filtre par date JJMMAA
    short verbose;            // Mode détaillé
} Arguments;

// Fonction pour parser les arguments
int parserArguments(int argc, char *argv[], Arguments *args);

#endif //CFONB_ANALYZER_CFONB_TYPES_H
