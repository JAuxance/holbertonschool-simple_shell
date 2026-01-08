# 🐚 Simple Shell

> Un interpréteur de commandes UNIX minimaliste écrit en C

[![🇬🇧 English](https://img.shields.io/badge/lang-🇬🇧_English-blue.svg)](README.md)
[![🇫🇷 Français](https://img.shields.io/badge/lang-🇫🇷_Français-red.svg)](README.fr.md)
[![📖 Man Page FR](https://img.shields.io/badge/man_page-🇫🇷_Français-green)](man_pages/simple_shell.1.fr)
[![C](https://img.shields.io/badge/langage-C-blue.svg)](https://fr.wikipedia.org/wiki/C_(langage))
[![License](https://img.shields.io/badge/licence-MIT-green.svg)](LICENSE)

---

## 📌 C'est quoi ?

**Simple Shell** est une implémentation basique d'un interpréteur de commandes UNIX écrite en langage C.  
Le programme reproduit le comportement minimal d'un shell en affichant un prompt, en lisant l'entrée utilisateur et en exécutant les commandes à l'aide de `fork()` et `execve()`.

🎯 Ce projet a pour objectif de mieux comprendre les concepts fondamentaux de la programmation système UNIX tels que :
- 🔄 La gestion des processus (`fork()`, `execve()`, `wait()`)
- 🌍 La manipulation des variables d'environnement
- 🔍 La résolution du PATH et la recherche de commandes
- ⚠️ La gestion des erreurs et des signaux

---

## ✨ Fonctionnalités supportées

| Fonctionnalité | Description | Statut |
|----------------|-------------|--------|
| 💬 Prompt interactif | Affiche un prompt et attend une commande utilisateur | ✅ |
| ⚙️ Exécution de commandes | Utilise `fork()` et `execve()` | ✅ |
| 📝 Commandes avec arguments | Gère les arguments passés aux commandes | ✅ |
| 🔍 Gestion du PATH | Recherche les exécutables via la variable PATH | ✅ |
| 🌍 Environnement | Passe `environ` à `execve()` | ✅ |
| 🚪 Built-in `exit` | Quitte le shell | ✅ |
| 📋 Built-in `env` | Affiche l'environnement courant | ✅ |
| ⚠️ Gestion des erreurs | Gère les commandes invalides et erreurs d'exécution | ✅ |
| 📄 Gestion de l'EOF | Gère `Ctrl + D` (fin de fichier) | ✅ |
| 🚀 Optimisation | `fork()` n'est pas appelé si la commande n'existe pas | ✅ |

---

## 📋 Prérequis

- **OS** : Ubuntu 20.04 LTS 🐧
- **Compilateur** : GCC 9.4.0 ou supérieur
- **Éditeur** : vi, vim, emacs ou VS Code
- **Git** : Gestion du versioning
- **Style** : Code conforme à la norme Betty ✨

---

## 🛠️ Comment compiler ?

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
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

---

## 🚀 Exemples d'utilisation

### Démarrage du Shell

```bash
$ ./simple_shell
$ 
```

### Commandes de base

```bash
$ ./simple_shell
$ ls
AUTHORS  README.md  simple_shell  Makefile  *.c  *.h
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

## ⚠️ Gestion des erreurs

- ❌ Si une commande n'est pas trouvée, un message d'erreur est affiché
- 🔄 Le shell continue de fonctionner après une erreur
- 🚫 Aucun processus n'est créé si la commande est invalide

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

## 🔍 Tests avec Valgrind

Pour vérifier l'absence de fuites mémoire :

```bash
# Avec Makefile (recommandé)
make valgrind

# Ou manuellement
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o simple_shell
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simple_shell
```

### Résultat attendu (pas de fuites) ✅

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: X allocs, X frees, X bytes allocated
==12345==
==12345== All heap blocks were freed -- no leaks are possible
==12345==
==12345== ERROR SUMMARY: 0 errors from 0 contexts
```

---

## 📚 Structure du projet

```
holbertonschool-simple_shell/
│
├── 📄 Simple_main.c           # Point d'entrée principal
├── 📄 read_and_parse.c        # Lecture et analyse de l'entrée
├── 📄 execute_command.c       # Exécution avec fork/execve
├── 📄 find_path.c             # Résolution du PATH
├── 📄 handle_builtins.c       # Commandes intégrées (exit, env)
├── 📄 main.h                  # Fichier d'en-tête avec prototypes
│
├── 🛠️ Makefile                # Automatisation de la compilation
├── 📖 README.md               # Documentation anglaise
├── 📖 README.fr.md            # Documentation française
├── 📋 AUTHORS                 # Contributeurs du projet
│
├── 📁 man_pages/
│   ├── simple_shell.1.en     # Page de manuel anglaise
│   └── simple_shell.1.fr     # Page de manuel française
│
└── 📁 concept_exo/           # Exercices et exemples de concepts
    └── ...
```

---

## 📖 Pages de manuel

Accéder aux pages de manuel :

```bash
# Version anglaise
man ./man_pages/simple_shell.1.en

# Version française
man ./man_pages/simple_shell.1.fr
```

---

## 🎓 Objectifs d'apprentissage

Après avoir terminé ce projet, vous devriez pouvoir expliquer :

- ✅ Ce qu'est un shell et comment il fonctionne
- ✅ La différence entre une fonction et un appel système
- ✅ Comment créer des processus avec `fork()`
- ✅ Comment exécuter des programmes avec la famille `execve()`
- ✅ Comment attendre un processus fils avec `wait()`
- ✅ Ce qu'est l'environnement et comment y accéder
- ✅ Comment gérer la variable PATH
- ✅ Comment implémenter des commandes intégrées

---

## 💡 Comment ça fonctionne ?

1. 🖥️ Le shell affiche un prompt
2. ⌨️ Il lit l'entrée utilisateur
3. 📋 La ligne de commande est analysée et découpée
4. 🔍 Le PATH est parcouru pour trouver l'exécutable
5. ✅ Si la commande existe :
   - `fork()` est appelé pour créer un processus fils
   - `execve()` exécute la commande dans le processus fils
   - Le processus parent attend la fin du processus fils
6. 🔁 Le prompt est affiché à nouveau

---

## 🤝 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
- 🐛 Signaler des bugs
- 💡 Suggérer de nouvelles fonctionnalités
- 🔧 Soumettre des pull requests

---

## 👥 Auteurs

Voir le fichier [AUTHORS](AUTHORS) pour la liste des contributeurs à ce projet.

---

## 📜 Licence

Ce projet fait partie du cursus de l'école Holberton School.

---

## 🙏 Remerciements

- Holberton School pour les directives du projet
- La communauté UNIX/Linux pour la documentation et l'inspiration

---

**Fait avec ❤️ par l'équipe Simple Shell**






