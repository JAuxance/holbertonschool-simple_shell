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
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Iinclude src/*.c -o simple_shell
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
AUTHORS  README.md  simple_shell  Makefile  src/  include/
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
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g -Iinclude src/*.c -o simple_shell
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./simple_shell
```

### Expected result (no leaks) ✅

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

## 📚 Project Structure

```
holbertonschool-simple_shell/
│
├── 📁 src/                    # Source files (.c)
│   ├── Simple_main.c          # Main entry point
│   ├── read_and_parse.c       # Input reading and parsing
│   ├── execute_command.c      # Command execution with fork/execve
│   ├── find_path.c            # PATH resolution
│   └── handle_builtins.c      # Built-in commands (exit, env)
│
├── 📁 include/                # Header files (.h)
│   └── main.h                 # Function prototypes and declarations
│
├── 📁 obj/                    # Object files (auto-generated)
│   └── *.o                    # Compiled object files
│
├── 📁 tests/                  # Test scripts
│   └── test_shell.sh          # Automated test script
│
├── 📁 man_pages/              # Manual pages
│   ├── simple_shell.1.en      # English manual page
│   └── simple_shell.1.fr      # French manual page
│
├── 📁 concept_exo/            # Concept exercises and examples
│   └── ...
│
├── 🛠️ Makefile               # Build automation
├── 📖 README.md               # English documentation (this file)
├── 📖 README.fr.md            # French documentation
└── 📋 AUTHORS                 # Project contributors
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

## 🧪 Running Tests

Run the automated test suite:

```bash
# Make sure the shell is compiled
make

# Run all tests
bash tests/test_shell.sh
```

The test script will verify:
- Basic command execution (ls, pwd, echo)
- Built-in commands (env, exit)
- Error handling
- EOF handling
- PATH resolution
- Multiple commands execution

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

**Made with ❤️ by Simple Shell Team**






