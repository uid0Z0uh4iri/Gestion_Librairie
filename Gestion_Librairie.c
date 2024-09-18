#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVRE 100
#define MAX_CHAINE 50

void mettreAJourQuantite(char titres[MAX_LIVRE][MAX_CHAINE], int quantite[MAX_LIVRE], int n) {
    char titre[MAX_CHAINE];
    int nouvelleQuantite;
    int trouve = 0;

    printf("\nEntrez le titre du livre dont vous voulez mettre à jour la quantité : ");
    scanf(" %49[^\n]", titre);

    for (int i = 0; i < n; i++) {
        if (strcmp(titres[i], titre) == 0) {
            printf("Quantité actuelle : %d\n", quantite[i]);
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &nouvelleQuantite);
            quantite[i] = nouvelleQuantite;
            printf("Quantité mise à jour avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Livre non trouvé.\n");
    }
}

int supprimerLivre(char titres[MAX_LIVRE][MAX_CHAINE], char auteurs[MAX_LIVRE][MAX_CHAINE], 
                   float prix[MAX_LIVRE], int quantite[MAX_LIVRE], int *n) {
    char titre[MAX_CHAINE];
    int trouve = -1;

    printf("\nEntrez le titre du livre à supprimer : ");
    scanf(" %49[^\n]", titre);

    for (int i = 0; i < *n; i++) {
        if (strcmp(titres[i], titre) == 0) {
            trouve = i;
            break;
        }
    }

    if (trouve != -1) {
        for (int i = trouve; i < *n - 1; i++) {
            strcpy(titres[i], titres[i + 1]);
            strcpy(auteurs[i], auteurs[i + 1]);
            prix[i] = prix[i + 1];
            quantite[i] = quantite[i + 1];
        }
        (*n)--;
        printf("Livre supprimé avec succès.\n");
        return 1;
    } else {
        printf("Livre non trouvé.\n");
        return 0;
    }
}

int nombreTotalLivres(int quantite[MAX_LIVRE], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += quantite[i];
    }
    return total;
}

void afficherLivres(char titres[MAX_LIVRE][MAX_CHAINE], char auteurs[MAX_LIVRE][MAX_CHAINE], 
                    float prix[MAX_LIVRE], int quantite[MAX_LIVRE], int n) {
    printf("\nListe des livres :\n");
    for (int i = 0; i < n; i++) {
        printf("\nLivre %d:\n", i + 1);
        printf("Titre : %s\n", titres[i]);
        printf("Auteur : %s\n", auteurs[i]);
        printf("Prix : %.2f\n", prix[i]);
        printf("Quantité en stock : %d\n", quantite[i]);
    }
}

int main() {
    int n;
    char titres[MAX_LIVRE][MAX_CHAINE];
    char auteurs[MAX_LIVRE][MAX_CHAINE];
    float prix[MAX_LIVRE];
    int quantite[MAX_LIVRE];

    printf("Entrez le nombre de livres : ");
    scanf("%d", &n);

    if (n > MAX_LIVRE) {
        printf("Trop de livres. Maximum autorisé : %d\n", MAX_LIVRE);
        return 1;
    }

    // Saisie des informations pour chaque livre
    for (int i = 0; i < n; i++) {
        printf("\nLivre %d:\n", i + 1);
        printf("Titre : ");
        scanf(" %49[^\n]", titres[i]);
        printf("Auteur : ");
        scanf(" %49[^\n]", auteurs[i]);
        printf("Prix : ");
        scanf("%f", &prix[i]);
        printf("Quantité en stock : ");
        scanf("%d", &quantite[i]);
    }

    int choix;
    do {
        printf("\n1. Afficher tous les livres");
        printf("\n2. Mettre à jour la quantité d'un livre");
        printf("\n3. Supprimer un livre");
        printf("\n4. Afficher le nombre total de livres en stock");
        printf("\n5. Quitter");
        printf("\nChoisissez une option : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                afficherLivres(titres, auteurs, prix, quantite, n);
                break;
            case 2:
                mettreAJourQuantite(titres, quantite, n);
                break;
            case 3:
                supprimerLivre(titres, auteurs, prix, quantite, &n);
                break;
            case 4:
                printf("\nNombre total de livres en stock : %d\n", nombreTotalLivres(quantite, n));
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Option non valide. Veuillez réessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
