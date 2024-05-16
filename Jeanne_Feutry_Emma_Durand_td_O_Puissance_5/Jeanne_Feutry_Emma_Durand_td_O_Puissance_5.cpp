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


int main()
{ 
#pragma region Jeu
    std::cout << "--- PUISSANCE 5 --- " << std::endl;
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
