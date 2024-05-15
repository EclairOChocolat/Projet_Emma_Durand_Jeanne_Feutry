#pragma once
#include "Joueur.h"
#include <iostream>
#include <string>

class Humain : public Joueur
{
private :
	std::string nom;
public:
	Humain(int couleur, std::string nom);
	Humain();
	Humain(int couleur);
	void initialisationNom();
	std::string getNom();
	virtual void afficher() const override;
	virtual void type() const override;


};

