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
#include "Jeu.h"


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

    /*
    Humain a(1,"Emma");
    Humain b(2, "Jeanne");*/

    #pragma region Jeu
        #pragma region Initialisation des joueurs

            // Initialisation des joueurs
            std::cout << "Joueur 1:" << std::endl;
            
            Humain a(0);
            a.initialisationNom();

            std::cout << "\nJoueur 2:" << std::endl;
            Humain b(0);
            b.initialisationNom();
            int bcouleur = b.getCouleurJoueur();
            while (a.getCouleurJoueur() == b.getCouleurJoueur()) {
                std::cout << "La couleur doit-etre differente que l'autre joueur. Reessayez : ";
                std::cin >> bcouleur;
                // Vérifiez si la couleur est dans la plage valide
                while (bcouleur < 1 || bcouleur> 14) {
                    std::cout << "La couleur doit etre entre 1 et 14. Reessayez : ";
                    std::cin >> bcouleur;
                }
                b.setCouleurJoueur(bcouleur);
            }
        #pragma endregion
        #pragma region Partie
        // Partie
            Jeu jeu(a,b);
            bool findepartie = false;
    
            while (findepartie == false) {
                if (!jeu.testPlateau()) {
                findepartie = jeu.mancheA(a);
                        if (!findepartie && !jeu.testPlateau()) {
                            findepartie = jeu.mancheB(b);
                            if (findepartie) {
                                jeu.affichageFinPartie(b);
                            }
                        }
                        else {
                            findepartie ? jeu.affichageFinPartie(a) : jeu.affichageFinPartie();
                        }
                }
        
            }
        #pragma endregion
    #pragma endregion



    

     


}
