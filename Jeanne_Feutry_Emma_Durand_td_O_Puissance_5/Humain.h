#pragma once
#include "Joueur.h"
#include <iostream>
#include <string>

class Humain : public Joueur
{
private :
	std::string nom;
public:
	Humain(int couleur, std::vector<Case> jetons, std::string nom);
	Humain(int couleur);
	virtual void afficher() const override;

};

