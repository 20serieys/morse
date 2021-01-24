#include <iostream>
#include "texte_morse.h"
#include "Dico.h"
#include <string>
#include <cstring>

// cette classe traduit un texte morse ne un texte en français

// espace entre les mots >= 2 et espace entre les lettres 1

texte_morse_to_fr::texte_morse_to_fr() : indice(0) {};

int texte_morse_to_fr::nombre_espaces(int i, int taille, std::string texte){
    int compte = 0;
    int ind = i; 
    while ((ind < taille) && (texte[ind] == ' ')){ 
    compte ++;
    ind ++;
    }
    return compte;
}

int texte_morse_to_fr::indice_fin_mot(int i, int taille, std::string texte){ 
    int k = i; 
    while ((k < taille) && (texte_morse_to_fr::nombre_espaces(k, taille, texte) < 2)){
        k++;
    }
    return k-1;
}

int texte_morse_to_fr::indice_fin_lettre(int i, int taille, std::string texte){
    int k = i; // aliasing ?
    while ((k < taille) && (!(texte[k] == ' '))){
        k++;
    }
    return k-1;
}

char* texte_morse_to_fr::mot_to_fr(int i, int taille, std::string texte){ // la fonction modifie aussi "indice" :  à la fin indice = fin du mot + 1 ATTENTION MODIF GLOBALE ?
    int l = i;
    int fin = texte_morse_to_fr::indice_fin_mot(i, taille, texte);
    int indice_mot = 0;
    char* mot = new char[fin - i + 1];
    while (l <= fin){
        int fin_lettre = texte_morse_to_fr::indice_fin_lettre(l, taille, texte);
        mot[indice_mot] = dico_m_t_f(texte.substr(l, fin_lettre - l + 1));
        l = fin_lettre + texte_morse_to_fr::nombre_espaces(fin_lettre + 1, taille, texte) + 1; // sauter les espaces
        indice_mot ++;
    }
    //slicing pour avoir seulement le mot
    char* mot_final = new char[indice_mot];
    for (int r = 0; r < indice_mot; r ++){
        mot_final[r] = mot[r];
    }
    indice = fin + 1;
    return mot_final;
    }

char* texte_morse_to_fr::conversion(std::string t){
    char* texte_fr = new char [100];
    int indice_fr = 0;
    int taille = t.length();
    while (indice < taille){ 
        if ((t[indice] == ' ') && (texte_morse_to_fr::nombre_espaces(indice, taille, t) > 1)) { 
            texte_fr[indice_fr] = ' ';
            indice_fr ++;
            indice += texte_morse_to_fr::nombre_espaces(indice, taille, t);
        }
        else if(t[indice] == ' '){
            indice ++;
        }
        else{
            char* mot = texte_morse_to_fr::mot_to_fr(indice, taille, t);
            int longueur = std::strlen(mot);
            for (int r = 0; r < longueur; r++){
                texte_fr[r + indice_fr] = mot[r];
            }
            indice_fr += longueur;
        }
    }
    char* resultat = new char [indice_fr + 1]; // pas indice_fr - 1 car indice_fr = taille du mot
    for (int s = 0; s < indice_fr; s ++){
        resultat[s] = texte_fr[s];
    }
    indice = 0; // indice remis à 0 : on est à prêts à traduire un nouveau texte.
    return resultat;
}