# 💻 Simple Shell

> Un interpréteur de commandes UNIX minimaliste écrit en C

[![🇬🇧 English](https://img.shields.io/badge/lang-🇬🇧_English-blue.svg)](README.md)
[![📖 Man Page FR](https://img.shields.io/badge/man_page-🇫🇷_Français-green)](man_pages/simple_shell.1.fr)
[![C](https://img.shields.io/badge/langage-C-blue.svg)](https://fr.wikipedia.org/wiki/C_(langage))

---

## C'est quoi ?

**Simple Shell** est une implémentation basique d'un interpréteur de commandes UNIX écrite en langage C.  
Le programme reproduit le comportement minimal d'un shell en affichant un prompt, en lisant l'entrée utilisateur et en exécutant les commandes à l'aide de `fork()` et `execve()`.

Ce projet a pour objectif de mieux comprendre les concepts fondamentaux de la programmation système UNIX tels que :
- La gestion des processus (`fork()`, `execve()`, `wait()`)
- La manipulation des variables d'environnement
- La résolution du PATH et la recherche de commandes
- La gestion des erreurs et des signaux

---

## Fonctionnalités supportées

| Fonctionnalité | Description | Statut |
|----------------|-------------|--------|
| Prompt interactif | Affiche un prompt et attend une commande utilisateur |
| Exécution de commandes | Utilise `fork()` et `execve()` |
| Commandes avec arguments | Gère les arguments passés aux commandes |
| Gestion du PATH | Recherche les exécutables via la variable PATH |
| Environnement | Passe `environ` à `execve()` |
| Built-in `exit` | Quitte le shell |
| Built-in `env` | Affiche l'environnement courant |
| Gestion des erreurs | Gère les commandes invalides et erreurs d'exécution |
| Gestion de l'EOF | Gère `Ctrl + D` (fin de fichier) |
| Optimisation | `fork()` n'est pas appelé si la commande n'existe pas |
---

## Flowchart

<img src="image/flowchart.svg" alt="Flowchart" width="1120" height="1500">

---

## Prérequis

- **OS** : Ubuntu 20.04 LTS
- **Compilateur** : GCC 9.4.0 ou supérieur
- **Éditeur** : vi, vim, emacs ou VS Code
- **Git** : Gestion du versioning
- **Style** : Code conforme à la norme Betty

---

## Comment compiler ?

### Avec Makefile (Recommandé)

```bash
# Compiler le projet
make

# Ou compiler et exécuter immédiatement
make run

# Compiler avec les symboles de débogage
make debug

# Nettoyer les fichiers objets
make clean

# Tout nettoyer
make fclean

# Recompiler depuis zéro
make re

# Exécuter avec Valgrind
make valgrind

# Afficher toutes les commandes disponibles
make help
```

### Compilation manuelle

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Iinclude src/*.c -o simple_shell
```

---

## Exemples d'utilisation

### Démarrage du Shell

```bash
$ ./simple_shell
$ 
```

### Commandes de base

```bash
$ ./simple_shell
$ ls
AUTHORS  README.md  simple_shell  Makefile  src/  include/
$ pwd
/home/user/holbertonschool-simple_shell
$ echo "Bonjour, Monde!"
Bonjour, Monde!
$ env
PATH=/usr/bin:/bin
HOME=/home/user
USER=user
$ exit
```

### Avec des arguments

```bash
$ ./simple_shell
$ ls -la /tmp
total 48
drwxrwxrwt 12 root root 4096 Jan  8 10:30 .
drwxr-xr-x 20 root root 4096 Jan  1 00:00 ..
$ cat /etc/os-release
NAME="Ubuntu"
VERSION="20.04 LTS (Focal Fossa)"
$ exit
```

---

## Gestion des erreurs

- Si une commande n'est pas trouvée, un message d'erreur est affiché
- Le shell continue de fonctionner après une erreur
- Aucun processus n'est créé si la commande est invalide

### Exemple : 

```bash
$ ./simple_shell
$ commande_invalide
./simple_shell: 1: commande_invalide: not found
$ autre_commande_invalide
./simple_shell: 2: autre_commande_invalide: not found
$ ls
AUTHORS  README.md  simple_shell
$ exit
```

---

## Tests avec Valgrind

Pour vérifier l'absence de fuites mémoire :

```bash
# Avec Makefile (recommandé)
make valgrind

# Ou manuellement
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g -Iinclude src/*.c -o simple_shell
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simple_shell
```

### Résultat attendu (pas de fuites)

```
==75837== HEAP SUMMARY:
==75837==     in use at exit: 0 bytes in 0 blocks
==75837==   total heap usage: 2 allocs, 2 frees, 1,144 bytes allocated
==75837== 
==75837== All heap blocks were freed -- no leaks are possible
==75837== 
==75837== For lists of detected and suppressed errors, rerun with: -s
==75837== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
---
## Betty

Le projet minishell respecte la norme de code **Betty**. 


👉 [Betty Coding Style](https://github.com/holbertonschool/Betty)


---

## 📚 Structure du projet

```
holbertonschool-simple_shell/
│
├── src/                    # Fichiers sources (.c)
│   ├── Simple_main.c          # Point d'entrée principal
│   ├── read_and_parse.c       # Lecture et analyse de l'entrée
│   ├── execute_command.c      # Exécution avec fork/execve
│   ├── find_path.c            # Résolution du PATH
│   └── handle_builtins.c      # Commandes intégrées (exit, env)
│
├── include/                # Fichiers d'en-tête (.h)
│   └── main.h                 # Prototypes et déclarations
│
├── obj/                    # Fichiers objets (auto-générés)
│   └── *.o                    # Fichiers objets compilés
│
├── tests/                  # Scripts de test
│   └── test_shell.sh          # Script de test automatique
│
├── man_pages/              # Pages de manuel
│   ├── simple_shell.1.en      # Page de manuel anglaise
│   └── simple_shell.1.fr      # Page de manuel française
│
├── concept_exo/            # Exercices et exemples de concepts
│   └── ...
│
├── Makefile               # Automatisation de la compilation
├── README.md               # Documentation anglaise
├── README.fr.md            # Documentation française (ce fichier)
└── AUTHORS                 # Contributeurs du projet
```

---

## Pages de manuel

Accéder aux pages de manuel :

```bash
# Version anglaise
man ./man_pages/simple_shell.1.en

# Version française
man ./man_pages/simple_shell.1.fr
```

---

## Objectifs d'apprentissage

Après avoir terminé ce projet, vous devriez pouvoir expliquer :

- Ce qu'est un shell et comment il fonctionne
- La différence entre une fonction et un appel système
- Comment créer des processus avec `fork()`
- Comment exécuter des programmes avec la famille `execve()`
- Comment attendre un processus fils avec `wait()`
- Ce qu'est l'environnement et comment y accéder
- Comment gérer la variable PATH
- Comment implémenter des commandes intégrées

---

## Exécution des tests

Lancer la suite de tests automatisée :

```bash
# S'assurer que le shell est compilé
make

# Lancer tous les tests
bash tests/test_shell.sh
```

Le script de test vérifie :
- Exécution de commandes de base (ls, pwd, echo)
- Commandes intégrées (env, exit)
- Gestion des erreurs
- Gestion de l'EOF
- Résolution du PATH
- Exécution de plusieurs commandes

---

<!-- Section "Comment ça fonctionne ?" supprimée pour cohérence avec la version anglaise -->

1. Le shell affiche un prompt
2. Il lit l'entrée utilisateur
3. La ligne de commande est analysée et découpée
4. Le PATH est parcouru pour trouver l'exécutable
5. Si la commande existe :
6. `fork()` est appelé pour créer un processus fils
7. `execve()` exécute la commande dans le processus fils
8. Le processus parent attend la fin du processus fils
6. Le prompt est affiché à nouveau

---

## Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
- Signaler des bugs
- Suggérer de nouvelles fonctionnalités
- Soumettre des pull requests

---

## 👥 Auteurs

Voir le fichier [AUTHORS](AUTHORS) pour la liste des contributeurs à ce projet.

---

**Fait avec passion ❤️ par Auxance et Julien**






