#include "Jeu.h"

//Constructeurs
Jeu::Jeu(Plateau _p, Humain _a, Humain _b)
: p(&_p), a(_a), b(_b), ga(false), gb(false)
{}
Jeu::Jeu( Humain _a, Humain _b)
	: a(_a), b(_b), ga(false), gb(false)
{
	int l(0);
	int h(0);
	do {
		std::cout << "Entrez la largeur du tableau : ";
		std::cin >> l;
	} while (l<=5 );// Car sinon le jeu n'est pas jouable
	do {
		std::cout << "Entrez la hauteur du tableau : ";
		std::cin >> h;
	} while (h <= 5);// car sinon le jeu n'est pas jouable
	this->p = new Plateau(l,h);
}

//Methodes
bool Jeu::testGagnant(std::vector<Case>& Joueur) {
	
	return true;
}
bool Jeu::testPlateau(int c) {
	bool t = false;
		
	//Test si la colonne choisie est bient dans le plateau
	if (c >= this->p->getLargeur()||c<0) {
		t = true;
	}
	else {
		
		//Test si un jeton le plus haut de la colonne est deja posé
		if (this->p->getTCase(c, 0)) {
				t = true;
			}
	}
	return t;
}
/// <summary>
///Cherche dans le plateau le jeton le plus bas possible
/// </summary>
/// <param name="c">Colonne</param>
/// <returns>retourne la hauteur ou le jeton a ete placé</returns>
int Jeu::cherchePlacementJeton(int& x) {
	int y(this->p->getHauteur() - 1);
	while (this->p->getTCase(x, y)||y==0) {
		y--;
	}
	return y;
}
void Jeu::mancheA() {

	this->p->afficherPlateau();
	int x(0);
	int y(0);
	do {
	std::cout << "Choisir la colonne ou vous voulez jouer : ";
	std::cin >> x;
	x = x - 1;
	} while (testPlateau(x));

	y = cherchePlacementJeton(x);
	this->p->setCase(x, y, this->a.getCouleurJoueur());

	a.ajoutezJeton(this->p->getCase(x,y));
	this->ga = testGagnant(this->a.getJetons());
}
void Jeu::mancheB() {
	this->p->afficherPlateau();
	int x(0);
	int y(0);
	do {
		std::cout << "Choisir la colonne ou vous voulez jouer : ";
		std::cin >> x;
		x = x - 1;
	} while (testPlateau(x));

	y = cherchePlacementJeton(x);
	this->p->setCase(x, y, this->b.getCouleurJoueur());

	b.ajoutezJeton(this->p->getCase(x, y));
	//this->gb = testGagnant(this->b.getJetons());
}

void Jeu::affichageFinPartie() {
	this->p->afficherPlateau();
	std::cout << "--- FIN DE LA PARTIE ---" << std::endl;
	std::cout << "Bravo ! ";
	ga ? a.afficher() : b.afficher(); // si ga = true alors on affiche a gagnant, b sinon

}

