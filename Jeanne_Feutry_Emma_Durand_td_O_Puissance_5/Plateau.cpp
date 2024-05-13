#include "Plateau.h"
#include <iostream>
#include <vector>
#include "Case.h"


Plateau::Plateau() : 
    largeur(9), hauteur(8) {
    std::vector<std::vector<Case>> cases;
    for (int i = 0; i < this->hauteur; ++i) {
        std::vector<Case> ligne; // Crée une ligne vide
        for (int j = 0; j < this->largeur; ++j) {
            // Ajoute une Case vide à chaque colonne de la ligne
            ligne.push_back(Case(false, i, j, 0)); // Modifier les arguments selon votre besoin
        }
        // Ajoute la ligne remplie au pla.teau
        cases.push_back(ligne);
    }
}