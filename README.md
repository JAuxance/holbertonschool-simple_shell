# simple_shell

[![en](https://img.shields.io/badge/lang-en-red.svg)](README.en.md)                                       
[![man-page](https://img.shields.io/badge/man%20page-fr-blue)](man_pages/simple_shell.1.fr)
---

## What is it?

**Simple Shell** is a basic implementation of a UNIX command line interpreter written in C.  
The program reproduces the minimal behavior of a shell by displaying a prompt, reading user input, and executing commands using `fork()` and `execve()`.

This project aims to provide a deeper understanding of UNIX system programming concepts such as process management, environment variables, PATH handling, and error management.

---

## Supported Features

| Feature | Description |
|-------|-------------|
| Interactive prompt | Displays a prompt and waits for user input |
| Command execution | Uses `fork()` and `execve()` |
| Commands with arguments | Handles arguments passed to commands |
| PATH handling | Searches executables using the PATH variable |
| Environment | Passes `environ` to `execve()` |
| Built-in `exit` | Exits the shell |
| Built-in `env` | Prints the current environment |
| Error handling | Handles invalid commands and execution errors |
| EOF handling | Handles `Ctrl + D` (end of file) |
| Optimization | `fork()` is not called if the command does not exist |

---

## Requirements

- **OS**: Ubuntu 20.04 LTS
- **Compiler**: GCC 9.4.0 or higher
- **Editor**: vi, vim, emacs, or VS Code
- **Git**: Version control system
- **Style**: Code compliant with the Betty style guide

---

## How to Compile

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

---

## Usage examples
---
### Expected output

```bash
$./simple_shell
$ ls
AUTHORS README.md simple_shell
$ pwd
/home/user/simple_shell
$ env
PATH=/usr/bin:/bin
HOME=/home/user
$ exit
```
---

## Error Handling

If a command cannot be found, an error message is displayed

The shell continues running after an error

No process is created if the command does not exist

Example: 
```bash
$ wrong_command
./simple_shell: 1: wrong_command: not found
```
---

## Valgrind Tests
To check for memory leaks:

```bash
# Compile with debug symbols
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o simple_shell

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simple_shell
```
### Expected result (no leaks)

```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: X allocs, X frees, X bytes allocated
==12345==
==12345== All heap blocks were freed -- no leaks are possible
```

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






