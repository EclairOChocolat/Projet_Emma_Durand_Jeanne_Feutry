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
	bool ga;//Si A a gagné ga = true sinon false
	bool gb;//Si B a gagné gb = true sinon false
public:
	//Constructeurs
	Jeu(Plateau p,Humain a, Humain b);
	Jeu(Humain a, Humain b);
	//Getteurs
	
	//Methodes
	static bool testGagnant(std::vector<Case>& Joueur);
	void manche();
	void affichageFinPartie();

};

