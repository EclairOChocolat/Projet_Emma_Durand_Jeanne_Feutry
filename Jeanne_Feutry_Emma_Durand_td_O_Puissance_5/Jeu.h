#pragma once
#include <iostream>
#include "Plateau.h"
#include "Joueur.h"
#include "Humain.h"
#include <windows.h>
#include <string>
#include <vector>
#include "Case.h"
class Jeu
{
private:
	Plateau* p;
	Joueur a;
	Joueur b;
public:
	//Constructeurs
	Jeu(Plateau p,Humain a, Humain b);
	Jeu(Humain a, Humain b);
	//Getteurs
	
	//Methodes
	
	bool testGagnant(int couleur);
	bool testPlateau();
	bool testColonne(int c);
	int cherchePlacementJeton(int& x);
	bool mancheA(const Joueur& joueurA);
	bool mancheB(const Joueur& joueurB);
	void affichageFinPartie();
	void affichageFinPartie(const Joueur& joueur);

};

