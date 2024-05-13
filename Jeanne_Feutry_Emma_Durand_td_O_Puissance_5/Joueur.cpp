#include "Joueur.h"

//Constructeurs
Joueur::Joueur(int c, std::vector<Case> j)
	: couleur(c), jetons(j) {}
;

Joueur::Joueur(int c)
	: couleur(c) {
	std::vector<Case> j;
	this->jetons = j;
};

// Getter
int Joueur::getCouleurJoueur() const { return couleur ; }
std::vector<Case>& Joueur::getJetons() { return jetons; }

//Methodes
void Joueur::ajoutezJeton(Case j) {
	this->jetons.push_back(j);
};

bool Joueur::testVictoire() {
	return true;
};
void Joueur::afficher() const {
	std::cout << "Couleur: " << couleur << std::endl;
}