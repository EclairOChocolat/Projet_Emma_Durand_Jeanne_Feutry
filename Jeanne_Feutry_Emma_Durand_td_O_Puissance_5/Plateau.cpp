#include "Plateau.h"
#include <iostream>
#include <vector>
#include "Case.h"

//Constructeurs
Plateau::Plateau() : 
    largeur(5), hauteur(5)
{

    std::vector<std::vector<Case>> cases;
    for (int i = 0; i < this->hauteur; ++i) {
        std::vector<Case> ligne;
        for (int j = 0; j < this->largeur; ++j) {
            ligne.push_back(Case(false, i, j, 0)); 
        }
        
        cases.push_back(ligne);
    }
    this->cases = cases;
}
Plateau::Plateau(int l, int h) :
    largeur(l), hauteur(l) {
    std::vector<std::vector<Case>> cases;
    for (int i = 0; i < this->hauteur; ++i) {
        std::vector<Case> ligne;
        for (int j = 0; j < this->largeur; ++j) {
            
            ligne.push_back(Case(false, i, j, 0)); 
        }
        cases.push_back(ligne);
    }
    this->cases = cases;
}
Plateau::Plateau(int l, int h, std::vector<std::vector<Case>> cases) :
    largeur(l), hauteur(l), cases(cases)
{}

// Getter
int Plateau::getLargeur() const { return largeur; }
int Plateau::getHauteur() const { return hauteur; }
Case Plateau::getCase(int x, int y) { return cases[y][x]; };
bool Plateau::getTCase(int x, int y) {
    return cases[y][x].getT();
};

//Setter
void Plateau::setCase(int x, int y,int ncouleur) {
    if (!cases[y][x].getT()) {
        cases[y][x].setT(true);
        cases[y][x].setCouleur(ncouleur);
    }
};

//Methodes
void Plateau::afficherPlateau() {

    for (int i = 0; i < this->hauteur; ++i) {
        std::cout << "|";
        for (int j = 0; j < this->largeur; ++j) {
            cases[i][j].afficherCase();
            cases[i][j].afficherCase();
            std::cout << "|";
        }
        /*std::cout << std::endl;
        for (int j = 0; j < this->largeur; ++j) {
            std::cout << "---";
        }*/
        std::cout << std::endl;
    }
    for (int j = 0; j < this->largeur; ++j) {
        if (j + 1 < 10) {
            std::cout << "  " << j+1;
        }
        else {
            std::cout << " " << j + 1;
        }
        
    }
    std::cout << std::endl;
};