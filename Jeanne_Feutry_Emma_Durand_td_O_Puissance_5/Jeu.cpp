#include "Jeu.h"

//Constructeurs
Jeu::Jeu(Plateau _p, Humain _a, Humain _b)
: p(&_p), a(_a), b(_b)//, ga(false), gb(false)
{}
Jeu::Jeu( Humain _a, Humain _b)
	: a(_a), b(_b)//, ga(false), gb(false)
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
bool Jeu::testGagnant(int couleur) {
	bool t = false;
	//teste ligne
	for (int i = 0; i < this->p->getHauteur(); ++i) {
		for (int j = 0; j <= this->p->getLargeur() - 5; ++j) {
			if (this->p->getTCase(j,i) && this->p->getTCase(j+1, i) && this->p->getTCase(j + 2, i) && this->p->getTCase(j + 3, i) && this->p->getTCase(j + 4, i)) {
				if (this->p->getCouleurCase(j, i) == couleur && this->p->getCouleurCase(j + 1, i) == couleur && this->p->getCouleurCase(j + 2, i) == couleur && this->p->getCouleurCase(j + 3, i) == couleur && this->p->getCouleurCase(j + 4, i) == couleur) {
					t = true;
				}
			}
		}
	}
	//test colonne
	for (int j = 0; j < this->p->getLargeur(); ++j) {
		for (int i = 0; i <= this->p->getHauteur() - 5; ++i) {
			if (this->p->getTCase(j, i) && this->p->getTCase(j , i+ 1) && this->p->getTCase(j, i + 2) && this->p->getTCase(j , i+ 3) && this->p->getTCase(j , i+ 4)) {
				
				if (this->p->getCouleurCase(j, i) == couleur && this->p->getCouleurCase(j, i + 1) == couleur && this->p->getCouleurCase(j, i + 2) == couleur && this->p->getCouleurCase(j, i + 3) == couleur && this->p->getCouleurCase(j, i + 4) == couleur) {
					t = true;
				}
			}
		}
	}
	//test diagonale droite gauche
	for (int i = 0; i <= this->p->getHauteur() - 5; ++i) {
		for (int j = this->p->getLargeur() - 1; j >= 4; --j) {
			if (this->p->getTCase(j, i) && this->p->getTCase(j-1, i + 1) && this->p->getTCase(j-2, i + 2) && this->p->getTCase(j-3, i + 3) && this->p->getTCase(j-4, i + 4)) {

				if (this->p->getCouleurCase(j, i) == couleur && this->p->getCouleurCase(j-1, i + 1) == couleur && this->p->getCouleurCase(j-2, i + 2) == couleur && this->p->getCouleurCase(j-3, i + 3) == couleur && this->p->getCouleurCase(j-4, i + 4) == couleur) {
					t = true;
				}
			}
		}
	}
	//test diagonale gauche droite 
	for (int i = 0; i <= this->p->getHauteur() - 5; ++i) {
		for (int j = 0; j <= this->p->getLargeur() - 5; ++j) {
			if (this->p->getTCase(j, i) && this->p->getTCase(j + 1, i + 1) && this->p->getTCase(j + 2, i + 2) && this->p->getTCase(j + 3, i + 3) && this->p->getTCase(j + 4, i + 4)) {

				if (this->p->getCouleurCase(j, i) == couleur && this->p->getCouleurCase(j + 1, i + 1) == couleur && this->p->getCouleurCase(j + 2, i + 2) == couleur && this->p->getCouleurCase(j + 3, i + 3) == couleur && this->p->getCouleurCase(j + 4, i + 4) == couleur) {
					t = true;
				}
			}
		}
	}

	return t;
}
/// <summary>
/// teste si on peut jouer dans le plateau
/// </summary>
/// <returns>retourne true si il n'y plus de case et false si il reste de la place</returns>
bool Jeu::testPlateau() {
	bool t = true;
	for (int i = 0; i < this->p->getLargeur();i++) {
		if (!testColonne(i)) {
			t = false;
			i = this->p->getLargeur();
		}
	}
	return t;
}
/// <summary>
/// Teste si il est possible de jouer dans cette colonne
/// </summary>
/// <param name="c">numéro de la colonne</param>
/// <returns>true si on ne peut pas jouer</returns>
bool Jeu::testColonne(int c) {
	bool t = false;
		
	//Test si la colonne choisie est bien dans le plateau
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
bool Jeu::mancheA(const Joueur& joueurA) {

	this->p->afficherPlateau();
	int x(0);
	int y(0);
	std::cout << "Joueur : ";
	joueurA.type();
	do {
	std::cout << "Choisir la colonne ou vous voulez jouer : ";
	std::cin >> x;
	x = x - 1;
	} while (testColonne(x));

	y = cherchePlacementJeton(x);
	this->p->setCase(x, y, this->a.getCouleurJoueur());
	return testGagnant(a.getCouleurJoueur());
	//a.ajoutezJeton(this->p->getCase(x,y));
	
}
bool Jeu::mancheB(const Joueur& joueurB) {
	this->p->afficherPlateau();
	int x(0);
	int y(0);
	std::cout << "Joueur : ";
	joueurB.type();
	do {
		std::cout << "Choisir la colonne ou vous voulez jouer : ";
		std::cin >> x;
		x = x - 1;
	} while (testColonne(x));

	y = cherchePlacementJeton(x);
	this->p->setCase(x, y, this->b.getCouleurJoueur());
	return testGagnant(b.getCouleurJoueur());
	
}
void Jeu::affichageFinPartie() {
	this->p->afficherPlateau();
	std::cout << "--- FIN DE LA PARTIE ---" << std::endl;
	std::cout << "Egalite ! ";
}
void Jeu::affichageFinPartie(const Joueur& joueur) {
	this->p->afficherPlateau();
	std::cout << "--- FIN DE LA PARTIE ---" << std::endl;
	std::cout << " Bravo le joueur ";
	joueur.afficher();
}


