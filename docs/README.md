# 🐚 Simple Shell

> A minimalist UNIX command line interpreter written in C


[![🇫🇷 Français](https://img.shields.io/badge/lang-🇫🇷_Français-red.svg)](README.fr.md)
[![📖 Man Page EN](https://img.shields.io/badge/man_page-🇬🇧_English-green)](man_pages/simple_shell.1.en)
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))


---

## 📌 What is it?

**Simple Shell** is a basic implementation of a UNIX command line interpreter written in C.  
The program reproduces the minimal behavior of a shell by displaying a prompt, reading user input, and executing commands using `fork()` and `execve()`.

🎯 This project aims to provide a deeper understanding of UNIX system programming concepts such as:
- 🔄 Process management (`fork()`, `execve()`, `wait()`)
- 🌍 Environment variables handling
- 🔍 PATH resolution and command search
- ⚠️ Error management and signal handling

---

## ✨ Supported Features

| Feature | Description | Status |
|---------|-------------|--------|
| 💬 Interactive prompt | Displays a prompt and waits for user input | ✅ |
| ⚙️ Command execution | Uses `fork()` and `execve()` | ✅ |
| 📝 Commands with arguments | Handles arguments passed to commands | ✅ |
| 🔍 PATH handling | Searches executables using the PATH variable | ✅ |
| 🌍 Environment | Passes `environ` to `execve()` | ✅ |
| 🚪 Built-in `exit` | Exits the shell | ✅ |
| 📋 Built-in `env` | Prints the current environment | ✅ |
| ⚠️ Error handling | Handles invalid commands and execution errors | ✅ |
| 📄 EOF handling | Handles `Ctrl + D` (end of file) | ✅ |
| 🚀 Optimization | `fork()` is not called if the command does not exist | ✅ |

---

## 📋 Requirements

- **OS**: Ubuntu 20.04 LTS 🐧
- **Compiler**: GCC 9.4.0 or higher
- **Editor**: vi, vim, emacs, or VS Code
- **Git**: Version control system
- **Style**: Code compliant with the Betty style guide ✨

---

## 🛠️ How to Compile

### Using Makefile (Recommended)

```bash
# Compile the project
make

# Or compile and run immediately
make run

# Compile with debug symbols
make debug

# Clean object files
make clean

# Clean everything
make fclean

# Rebuild from scratch
make re

# Run with Valgrind
make valgrind

# Show all available commands
make help
```

### Manual Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

---

## 🚀 Usage Examples

### Starting the Shell

```bash
$ ./simple_shell
$ 
```

### Basic Commands
---
### Expected output

```bash
$ ./simple_shell
$ ls
AUTHORS  README.md  simple_shell  Makefile  *.c  *.h
$ pwd
/home/user/holbertonschool-simple_shell
$ echo "Hello, World!"
Hello, World!
$ env
PATH=/usr/bin:/bin
HOME=/home/user
USER=user
$ exit
```

### With Arguments

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

## ⚠️ Error Handling

- ❌ If a command cannot be found, an error message is displayed
- 🔄 The shell continues running after an error
- 🚫 No process is created if the command does not exist

### Example: 
```bash
$ ./simple_shell
$ wrong_command
./simple_shell: 1: wrong_command: not found
$ another_wrong_cmd
./simple_shell: 2: another_wrong_cmd: not found
$ ls
AUTHORS  README.md  simple_shell
$ exit
```
---

## 🔍 Valgrind Tests

To check for memory leaks:

```bash
# Using Makefile (recommended)
make valgrind

# Or manually
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o simple_shell
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simple_shell
```

### Expected result (no leaks) ✅

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

## 📚 Project Structure

```
holbertonschool-simple_shell/
│
├── 📄 Simple_main.c           # Main entry point
├── 📄 read_and_parse.c        # Input reading and parsing
├── 📄 execute_command.c       # Command execution with fork/execve
├── 📄 find_path.c             # PATH resolution
├── 📄 handle_builtins.c       # Built-in commands (exit, env)
├── 📄 main.h                  # Header file with prototypes
│
├── 🛠️ Makefile                # Build automation
├── 📖 README.md               # English documentation
├── 📖 README.fr.md            # French documentation
├── 📋 AUTHORS                 # Project contributors
│
├── 📁 man_pages/
│   ├── simple_shell.1.en     # English manual page
│   └── simple_shell.1.fr     # French manual page
│
└── 📁 concept_exo/           # Concept exercises and examples
    └── ...
```

---

## 📖 Man Pages

Access the manual pages:

```bash
# English version
man ./man_pages/simple_shell.1.en

# French version
man ./man_pages/simple_shell.1.fr
```

---

## 🎓 Learning Objectives

After completing this project, you should be able to explain:

- ✅ What is a shell and how it works
- ✅ The difference between a function and a system call
- ✅ How to create processes with `fork()`
- ✅ How to execute programs with the `execve()` family
- ✅ How to wait for a child process with `wait()`
- ✅ What is the environment and how to access it
- ✅ How to handle the PATH variable
- ✅ How to implement built-in commands

---

## 🤝 Contributing

Contributions are welcome! Feel free to:
- 🐛 Report bugs
- 💡 Suggest new features
- 🔧 Submit pull requests

---

## 👥 Authors

See the [AUTHORS](AUTHORS) file for the list of contributors to this project.

---

## 📜 License

This project is part of the Holberton School curriculum.

---

## Man pages
```bash
# English version
man ./man_pages/simple_shell.1.en

# French version
man ./man_pages/simple_shell.1.fr
```

---

## Project Files
| File | Description |
|------|-------------|
| `Simple_main.c` | The main function|
| `env_command.c` | Implements the env built-in to print environment variables | 
| `execute_command.c` | Handles process creation and command execution using fork() and execve() |
| `find_path.c` | Searches for executable files using the PATH environment variable |
| `read_and_parse.c` | Reads user input and parses the command line into tokens |
| `main.h` | Header file containing function prototypes, macros, and shared structures |

---
## How it works

1. The shell displays a prompt
2. It reads user input
3. The command line is parsed into tokens
4. The PATH is searched to locate the executable
5. If the command exists:
6. fork() is called
7. execve() executes the command
8. The parent process waits for the child to finish
9. The prompt is displayed again

---
## Authors

- Auxance JOURDAN
- Julien HINLANG

---

*Holberton School Project*






