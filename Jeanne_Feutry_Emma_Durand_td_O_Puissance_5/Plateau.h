#pragma once
#include <iostream>
#include <vector>
#include "Case.h"
class Plateau
{
private:
    int const largeur;
    int const hauteur;
    std::vector<std::vector<Case>> cases;
public:
    //Constructeurs
    Plateau();
    Plateau(int l, int h);
    Plateau(int l, int h, std::vector<std::vector<Case>> cases);
    //Getter
    int getLargeur() const;
    int getHauteur() const;
    int getCouleurCase(int x, int y)const;
    Case getCase(int x, int y); 
    bool getTCase(int x, int y);

    //Setter
    void setCase(int x, int y,int ncouleur);
    //Methodes
    void afficherPlateau();
};

