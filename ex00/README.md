std::flush :

Flush sert a forcer le vidage du tampon associé à un flux de sortie. Cela garantit que les données mises en mémoire tampon son immédiatement écrites. Bien que le vidage soit souvent géré automatiquement (par exemple, lors de la lecture depuis std::cin ou à la fin du programme), une utilisation explicite de std::flush peut être nécessaire pour assurer une synchronisation immédiate entre le flux de sortie et le destinataire.

En gros flush vide le buffer interne de cout et force l'ecriture sur le flux de sortie.
Si on utilise pas flush la garantit que la string écrite seras écrit sur le flux de sorti au moment oou on lui demande de le faire
dans le programme n'est pas garantit.

Cependant dans le cadre de l'exercice megaphone, le flush n'est pas nécessaire car il est vraiment utile pour les programmes interactifs ou l'utilisateur a besoins de lire l'output en temps réel. Vider le buffer de cout a chaque fois peut ralentir le programme, le rendre moins efficace.

std::endl :

Même utilisation que flush mais rajoute le caractère '\n'.

std::transform :

Transform applique la fonction donné aux element donné en entré dans une range donné.
Dans l'exercice on lui passe en argument notre string qu'on a convertit en std::string. On utilise la fonction begin pour renvoyer un itérateur sur le premier caractère de notre string.

EX