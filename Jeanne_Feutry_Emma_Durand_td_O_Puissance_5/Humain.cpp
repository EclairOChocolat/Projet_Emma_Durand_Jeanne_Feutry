#include "Humain.h"
Humain::Humain(int c, std::vector<Case> jetons, std::string _nom)
	: Joueur(0, jetons), nom(_nom) {
	std::cout << "\n1 : Bleu fonce\t2 : Vert fonce\n3 : Turquoise\t4 : Rouge fonce ";
	std::cout << "\n5 : Violet\t6 : Vert caca d'oie \n7 : Gris clair\t8 : Gris fonce \n9 : Bleu fluo\t10 : Vert fluo";
	std::cout << "\n11 : Turquoise\t12 : Rouge fluo \n13 : Violet 2\t14 : Jaune" << std::endl;
	std::cout << "Entrez la couleur (entre 1 et 14) : ";
	std::cin >> this->couleur;
	// Vérifiez si la couleur est dans la plage valide
	while (this->couleur < 1 || this->couleur> 14) {
		std::cout << "La couleur doit etre entre 1 et 14. Reessayez : ";
		std::cin >> this->couleur;
	}
}
;
Humain::Humain(int c)
	: Joueur(0){
	std::cout << "Entrez votre nom : ";
	std::cin >> this->nom;
	std::cout << "\n1 : Bleu fonce\t2 : Vert fonce\n3 : Turquoise\t4 : Rouge fonce ";
	std::cout << "\n5 : Violet\t6 : Vert caca d'oie \n7 : Gris clair\t8 : Gris fonce \n9 : Bleu fluo\t10 : Vert fluo";
	std::cout << "\n11 : Turquoise\t12 : Rouge fluo \n13 : Violet 2\t14 : Jaune" << std::endl;
	std::cout << "Entrez la couleur (entre 1 et 14) : ";
	std::cin >> this->couleur;
	// Vérifiez si la couleur est dans la plage valide
	while (this->couleur < 1 || this->couleur> 14) {
		std::cout << "La couleur doit etre entre 1 et 14. Reessayez : ";
		std::cin >> this->couleur;
	}
}
;
void Humain::afficher() const {
	std::cout << "Humain: " <<nom << " ";
	Joueur::afficher();
}