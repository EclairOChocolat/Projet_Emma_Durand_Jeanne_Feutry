#pragma once
#include <iostream>
#include <string>
#include "Case.h"
#include <vector>
class Joueur
{

protected :
	int couleur;
public :
	Joueur(int couleur);
	Joueur();
	int getCouleurJoueur() const;
	void setCouleurJoueur(int couleur);
	virtual void type() const;
	virtual void afficher() const;
};

