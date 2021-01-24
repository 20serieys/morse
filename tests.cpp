#include <iostream>
#include "texte_morse.h"
#include "Dico.h"
#include "texte_français.h"
#include "wave_final.h"
#include "wave.h"


int main(){

    std::string mines = "-- .. -. . ...  -.. .  .--. .- .-. .. ...";
    texte_morse_to_fr mine;
    std::cout<< mine.conversion(mines) <<std::endl; // Renvoie MINES DE PARIS

    std::string essai = "AM A M";
    texte_fr_to_morse essai_;
    std::cout<< essai_.construction(essai) << std::endl; // Renvoie   -- .. -. . ...  -.. .  .--. .- .-. .. ... comme prévu

    // Pour tester wave, qui renvoie un sinus dans sinus.wav (doit être vide)
    wave_sinus lecteur_sinus;
    unsigned int temps_sinus = 5;
    char* nom_sinus = "sinus.wav";
    // on fait en sorte que sinus.wav soit vide
    FILE* fichier_sinus = std::fopen(nom_sinus,"wb");
    std::remove(nom_sinus);
    fichier_sinus = std::fopen(nom_sinus,"wb");
    unsigned int f_son_sinus = 440;
    unsigned int frequence_sinus = 44100;
    unsigned int amplitude_sinus = 1000;
    int stereo_sinus = 2;
    lecteur_sinus.ecrire_entete(temps_sinus,frequence_sinus,stereo_sinus, fichier_sinus);
    lecteur_sinus.ecrire_sinus(temps_sinus, frequence_sinus, amplitude_sinus, f_son_sinus, fichier_sinus);

    // Pour tester wave_final : écrit dans essai.wav (doit être vide)
    wave lecteur;
    std::string texte = ".- --  .-  --";
    unsigned int temps = texte.length();
    char* nom = "essai.wav";
    //On fait en sorte que essai.wav soit vide
    FILE* fichier = std::fopen(nom,"wb");
    std::remove(nom);
    fichier = std::fopen(nom,"wb");
    unsigned int f_son = 440;
    unsigned int frequence = 44100;
    unsigned int amplitude = 1000;
    int stereo = 2;
    lecteur.ecrire_entete(temps,frequence,stereo, fichier);
    lecteur.traduction(temps, frequence, amplitude, f_son, fichier, texte);


    return 0;
}