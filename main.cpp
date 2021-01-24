#include <iostream>
#include "texte_morse.h"
#include "Dico.h"
#include "texte_français.h"
#include "wave_final.h"

int main(){
    std::string choix;
    std::cout << "Déchiffrer un texte morse : rentrer a"<< std::endl;
    std::cout << "Créer un fichier audio en morse à partir d'un texte français : rentrer b" << std::endl;
    std::getline(std::cin, choix);
    if (choix[0] == 'a'){
        std::string texte;
        std::cout << "Rentrer le texte morse : ";
        std::getline(std::cin,texte);
        texte_morse_to_fr trad;
        std::cout<< trad.conversion(texte) << std::endl;
    }
    if (choix[0] == 'b'){
        std::string txt;
        std::cout << "Rentrer le texte en majuscules : ";
        std::getline(std::cin,txt);
        texte_fr_to_morse trad;
        std::string texte = trad.construction(txt);
        wave lecteur;

        unsigned int temps = texte.length();
        char* nom = "morse.wav";
        // on fait en sorte que "morse.wav soit vide
        FILE* fichier = std::fopen(nom,"wb");
        std::remove(nom);
        fichier = std::fopen(nom,"wb");
        unsigned int f_son = 440;
        unsigned int frequence = 44100;
        unsigned int amplitude = 1000;
        int stereo = 2;
        lecteur.ecrire_entete(temps,frequence,stereo, fichier);
        lecteur.traduction(temps, frequence, amplitude, f_son, fichier, texte);
    }
    return 0;
}