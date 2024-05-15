#include "Joueur.h"

//Constructeurs
Joueur::Joueur(int c, std::vector<Case> j)
	: couleur(c), jetons(j) {}
Joueur::Joueur(int c)
	: couleur(c) {
	std::vector<Case> j;
	this->jetons = j;
};

// Getter
int Joueur::getCouleurJoueur() const { return couleur ; }
std::vector<Case>& Joueur::getJetons() { return jetons; }
//Setter
void Joueur::setCouleurJoueur(int couleur) {
	this->couleur = couleur;
}

//Methodes
void Joueur::ajoutezJeton(Case j) {
	this->jetons.push_back(j);
};
void Joueur::afficher() const {
	std::cout << " a gagne !" << couleur << std::endl;
}