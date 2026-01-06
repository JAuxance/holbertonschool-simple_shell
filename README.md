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
