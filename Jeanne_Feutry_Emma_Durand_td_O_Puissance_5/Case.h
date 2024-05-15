#pragma once
#include <iostream>
#include <windows.h>
class Case
{
private :
    bool t; //Pour savoir si la case est occupée ou non
    int x;   
    int y;   
    int couleur; // int entre 0 et 15 pour la couleur
public :
    //Constructeurs
    Case();
    Case(int const y, int const x);
    Case(bool t, int const y, int const x, int couleur);
    

    // Getter
    bool getT() const;
    int getX() const;
    int getY() const;
    int getCouleur() const;

    //Setter
    void setT(bool newT);
    void setCouleur(int newCouleur);
    
    // Fonction pour afficher les informations de la case
    static void winColor(int couleurDuTexte, int couleurDeFond);
    void afficherTest() const;
    void afficherCase() const;

};

