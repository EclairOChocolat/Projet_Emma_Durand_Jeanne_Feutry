#include "Case.h"
#include <iostream>

//Constructeurs
Case::Case() 
: t(false), x(0), y(0), couleur(0)
{}
Case::Case(int const y_, int const x_)
	: t(false), x(x_), y(y_), couleur(0)
{}

Case::Case(bool t_, int const y_, int x_, int couleur_)
	: t(t_), x(x_), y(y_), couleur(couleur_)
{
	if (couleur_ < 0 || couleur_ > 15) {
		throw std::out_of_range("La couleur doit être comprise entre 0 et 15.");
	}
	couleur = couleur_;
}

// Getter

/// <summary>
/// Retourne l'etat de la case
/// </summary>
/// <returns>True si la case est occupée, false sinon</returns>
bool Case::getT() const { return t; }
int Case::getX() const { return x; }
int Case::getY() const { return y; }
int Case::getCouleur() const { return couleur; }

//Setter

/// <summary>
/// Change l'état de la case
/// </summary>
/// <param name="newT">Nouvel état de la case</param>
void Case::setT(bool newT) { t = newT; }
void Case::setCouleur(int c) {
	if (c < 0 || c > 15) {
		throw std::out_of_range("La couleur doit être comprise entre 0 et 15.");// dans le reste du code cette valeur est toujours comprise entre 0 et 15
	}
	else {
		couleur = c;
	}
}
//Methodes 

/// <summary>
/// Methode statique qui change grâce à la biblioteque windows.h la couleur du fond et de l'ecriture de la console
/// </summary>
/// <param name="couleurDuTexte">Couleur du texte</param>
/// <param name="couleurDeFond">Couleur du fond</param>
void Case::winColor(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
    /*
    0 : Noir
    1 : Bleu foncé
    2 : Vert foncé
    3 : Turquoise
    4 : Rouge foncé
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris foncé
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */
}

/// <summary>
/// Methode utilisé pour nos tests pour afficher tous les attributs de la case
/// </summary>
void Case::afficherTest() const {
	std::cout << "Case (" << x << ", " << y << "):" << std::endl;
	std::cout << "  Occupee: " << (t ? "Oui" : "Non") << std::endl;
	std::cout << "  Couleur: " << couleur << std::endl;
}

/// <summary>
/// Methode qui affiche la case dans le plateau avec la bonne couleur
/// </summary>
void Case::afficherCase() const {
    winColor(couleur, couleur);
    std::cout << " ";
    winColor(7, 0);

}