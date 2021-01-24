#include <string>
class texte_morse_to_fr{
  public :
    texte_morse_to_fr();
    int indice;
    int nombre_espaces(int i, int taille, std::string texte); 
    char* conversion(std::string t);
    int indice_fin_mot(int i, int taille, std::string texte);
    int indice_fin_lettre(int i, int taille, std::string texte);
    char* mot_to_fr(int indice, int taille, std::string texte);
};