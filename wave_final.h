#include <string>

class wave{
    public:
      void ecrire_entete(unsigned int temps, unsigned int frequence, int nb_canaux, FILE* fichier);
      void ecrire_sinus(unsigned int taille, unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier);
      void ecrire_little_endian(int octets, unsigned int taille, FILE *fichier);
      double valeur_max(FILE* fichier, double* gauche, double* droite, unsigned int taille, double amplitude);
      double* creer_tableau_sinus(unsigned int taille, unsigned int f, unsigned int frequence);
      void ecrire_blanc(unsigned int taille, unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier);
      void ecrire_point(unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier);
      void ecrire_barre(unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier);
      void traduction(unsigned int temps, unsigned int frequence, double amplitude, unsigned int f_son, FILE* fichier, std::string texte);
};