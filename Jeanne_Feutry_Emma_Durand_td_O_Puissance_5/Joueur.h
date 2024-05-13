#pragma once
#include <iostream>
#include <string>
#include "Case.h"
#include <vector>
class Joueur
{
private :
	
	std::vector<Case> jetons;
protected :
	int couleur;
public :
	Joueur(int couleur, std::vector<Case> jetons);
	Joueur(int couleur);
	int getCouleurJoueur() const;
	//virtual void setCouleurJoueur();
	std::vector<Case>& getJetons();
	void ajoutezJeton(Case j);
	bool testVictoire();
	virtual void afficher() const;
};

