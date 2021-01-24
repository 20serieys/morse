#include <iostream>
#include "texte_français.h"
#include "Dico.h"
#include <string>
#include <cstring>

// Cette classe va servir à convertir un texte en français en texte en morse.

std::string texte_fr_to_morse::lettre_to_morse(char ch){
    return dico_f_t_m(ch);
}

std::string texte_fr_to_morse::construction(std::string texte_fr){
    int taille = texte_fr.length();
    int indice_fr = 0;
    std::string texte_m;
    while (indice_fr < taille){
        if (texte_fr[indice_fr] == ' '){
            texte_m.append(" ");  // espace entre les mots
        }
        else {
            texte_m.append(texte_fr_to_morse::lettre_to_morse(texte_fr[indice_fr]));
            texte_m.append(" "); //espace entre les lettres
        }
        indice_fr ++;
    }
    return texte_m;
}