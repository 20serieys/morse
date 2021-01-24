Utiliser la commande make pour créer les exécutables main et test. (Je n'ai pas fait la conversion de l'audio morse au texte morse... Le reste marche avec les tests que j'ai effectués.)

main : 
- Faire ./main
- rentrer a pour transcrire un texte en morse (avec des . et des - et avec un espace entre les lettres et deux espaces entre les mots)
- rentrer b pour transcire du français (en majuscules, sans mettre de guillemets) en audio morse dans le fichier morse.wav.  chauqe espace dure une seconde (donc deux secondes de vide entre les mots), un point = 1/4 de seconde de son, 3/4 de seconde de vide. Un tiret = 3/4 de seconde de son, 1/4 de vide.

test: 
- faire ./test
On teste la classe qui traduit de texte morse à texte français, et la classe qui traduit de texte français à texte morse.
Puis on teste la classe wave_sinus du fichier wave.cpp qui doit créer un sinus dans le fichier sinus.wav
Enfin on teste la classe wave du fichier wave_final qui transcrit un texte français à un audio morse dans essai.wav.