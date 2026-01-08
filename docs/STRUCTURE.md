# 🐚 Simple Shell - Structure du Projet

Ce document décrit l'organisation du projet Simple Shell.

## 📁 Structure des Dossiers

```
holbertonschool-simple_shell/
│
├── 📁 src/                    # Fichiers sources (.c)
│   ├── Simple_main.c          # Point d'entrée principal
│   ├── read_and_parse.c       # Lecture et analyse de l'entrée
│   ├── execute_command.c      # Exécution avec fork/execve
│   ├── find_path.c            # Résolution du PATH
│   └── handle_builtins.c      # Commandes intégrées (exit, env)
│
├── 📁 include/                # Fichiers d'en-tête (.h)
│   └── main.h                 # Prototypes et déclarations
│
├── 📁 obj/                    # Fichiers objets (.o) [généré]
│   └── *.o                    # Fichiers compilés
│
├── 📁 docs/                   # Documentation
│   ├── README.md              # Documentation anglaise
│   ├── README.fr.md           # Documentation française
│   └── STRUCTURE.md           # Ce fichier
│
├── 📁 tests/                  # Scripts de test
│   └── test_shell.sh          # Script de test automatique
│
├── 📁 man_pages/              # Pages de manuel
│   ├── simple_shell.1.en      # Page de manuel anglaise
│   └── simple_shell.1.fr      # Page de manuel française
│
├── 📁 concept_exo/            # Exercices et exemples
│   └── ...                    # Exercices de concepts
│
├── 🛠️ Makefile                # Automatisation de la compilation
├── 📋 AUTHORS                 # Contributeurs du projet
└── 🚀 simple_shell            # Exécutable [généré]
```

## 🔧 Utilisation

### Compilation
```bash
make              # Compiler le projet
make clean        # Nettoyer les fichiers objets
make fclean       # Tout nettoyer
make re           # Recompiler depuis zéro
```

### Tests
```bash
./tests/test_shell.sh    # Exécuter tous les tests
```

## 📝 Conventions

- **src/** : Tous les fichiers sources C
- **include/** : Tous les fichiers d'en-tête
- **obj/** : Fichiers objets générés (gitignore)
- **docs/** : Documentation du projet
- **tests/** : Scripts de test automatisés
