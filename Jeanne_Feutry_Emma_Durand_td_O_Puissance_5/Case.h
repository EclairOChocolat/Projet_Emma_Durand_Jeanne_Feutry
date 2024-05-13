#pragma once
#include <iostream>
#include <windows.h>
class Case
{
private :
    bool t; //Pour savoir si la case est occupée ou non
    int const x;   
    int const y;   
    int couleur; // int entre 0 et 15 pour la couleur
public :
    //Constructeurs
    Case();
    Case(int const x, int const y);
    Case(bool t, int const x, int const y, int couleur);
    

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

