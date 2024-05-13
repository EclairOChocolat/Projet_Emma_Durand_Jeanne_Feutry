// Jeanne_Feutry_Emma_Durand_td_O_Puissance_5.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "Case.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Humain.h"


void Color(int couleurDuTexte, int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
    /*
    0 : Noir 
    1 : Bleu foncé 
    2 : Vert foncé 
    3 : Turquoise 
    4 : Rouge foncé 
    5 : Violet 
    6 : Vert caca d'oie 
    7 : Gris clair 
    8 : Gris foncé 
    9 : Bleu fluo 
    10 : Vert fluo 
    11 : Turquoise 
    12 : Rouge fluo 
    13 : Violet 2 
    14 : Jaune 
    15 : Blanc 
    */
}
int main()
{ 
    /*
    #pragma region TestCase
    // TEST CASE ET ECRITURE 

        Case case1 (true, 10, 1, 13);
        case1.afficherTest();
        case1.afficherCase();  
        std::cout <<"test" <<std::endl;
        case1.setCouleur(2);
        case1.afficherCase();
        std::cout << "test" << std::endl;
    #pragma endregion
        */

    /*
    #pragma region TestPlateau
    // TEST PLATEAU ET ECRITURE
        Plateau p(11,9);
        //p.afficherPlateau();
        //std::cout<<"\n" << p.getTCase(0, 0) << "\n" << std::endl;
        p.setCase(10, 0, 3);
        p.setCase(9, 0, 5);
        p.afficherPlateau();


    #pragma endregion
*/

    #pragma region TestJoueurHumain
            Humain h1(0);
            h1.afficher();
    #pragma endregion


    

     


}
