#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/cfonb_types.h"

void afficherUsage(const char *nomProgramme) {
    printf("Usage : %s <commande> <fichier> [options]\n\n", nomProgramme);
    printf("Commandes :\n");
    printf("  load <fichier>       Charger et afficher un résumé\n");
    printf("  validate <fichier>   Valider la cohérence des données\n");
    printf("  stats <fichier>      Afficher les statistiques\n");
    printf("  search <fichier>     Rechercher des opérations\n\n");
    printf("Options pour 'search' :\n");
    printf("  --compte <num>       Filtrer par numéro de compte\n");
    printf("  --montant-min <n>    Montant minimum en centimes\n");
    printf("  --date <JJMMAA>      Filtrer par date\n\n");
    printf("Options générales :\n");
    printf("  --verbose, -v        Affichage détaillé\n");
    printf("  --help, -h           Afficher cette aide\n");
}

int parserArguments(int argc, char *argv[], Arguments *args) {
    // Initialiser avec des valeurs par défaut
    memset(args, 0, sizeof(Arguments));
    args->montantMin = -1;  // -1 = pas de filtre

    // Vérifier le minimum d'arguments
    if (argc < 2) {
        return -1;
    }

    // Gérer --help en premier
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        return 0;  // Code spécial pour afficher l'aide
    }

    // Commande obligatoire
    strncpy(args->commande, argv[1], 19);

    // Fichier obligatoire (sauf pour help)
    if (argc < 3) {
        printf("Erreur : fichier manquant\n");
        return -1;
    }
    strncpy(args->fichier, argv[2], 255);

    // Parser les options
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "--compte") == 0 && i + 1 < argc) {
            strncpy(args->numeroCompte, argv[++i], 11);
        }
        else if ((strcmp(argv[i], "--montant-min") == 0 || strcmp(argv[i], "-m") == 0) && i + 1 < argc) {
            args->montantMin = atol(argv[++i]);
        }
        else if (strcmp(argv[i], "--date") == 0 && i + 1 < argc) {
            strncpy(args->date, argv[++i], 6);
        }
        else if (strcmp(argv[i], "--verbose") == 0 || strcmp(argv[i], "-v") == 0) {
            args->verbose = 1;
        }
        else if (argv[i][0] == '-') {
            printf("Erreur : option inconnue '%s'\n", argv[i]);
            return -1;
        }
    }

    return 1;  // Succès
}

int main(int argc, char *argv[]) {
        Arguments args;

        int resultat = parserArguments(argc, argv, &args);

        if (resultat <= 0) {
            afficherUsage(argv[0]);
            return (resultat < 0) ? 1 : 0;
        }

        // Exécuter la commande demandée
        if (strcmp(args.commande, "load") == 0) {
            chargerEtAfficher(args.fichier);
            printf("Chargement de %s...\n", args.fichier);
        }
        else if (strcmp(args.commande, "validate") == 0) {
            // validerFichier(args.fichier);
            printf("Validation de %s...\n", args.fichier);
        }
        else if (strcmp(args.commande, "stats") == 0) {
            // afficherStats(args.fichier);
            printf("Statistiques de %s...\n", args.fichier);
        }
        else if (strcmp(args.commande, "search") == 0) {
            // rechercherOperations(args.fichier, &args);
            printf("Recherche dans %s...\n", args.fichier);
            if (args.numeroCompte[0] != '\0') {
                printf("  Filtre compte : %s\n", args.numeroCompte);
            }
        }
        else {
            printf("Erreur : commande '%s' inconnue\n", args.commande);
            afficherUsage(argv[0]);
            return 1;
        }

        return 0;
    }