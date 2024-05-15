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
void Jeu::testGagnant() {
	this->ga = this->a.testVictoire();
	this->gb = this->b.testVictoire();
}
void Jeu::manche() {

}
void Jeu::affichageFinPartie() {

}

