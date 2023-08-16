# Simple UNIX Command Interpreter (Shell)

This is a simple UNIX command interpreter (shell) written in C that provides basic command execution functionality. The shell displays a prompt, waits for user input, processes the input command, and executes it. It supports built-in commands, environmental variable printing, and basic command execution using the PATH environment variable.

## Features

- Prompt for user input and execute commands.
- Built-in commands: `exit` (terminate the shell) and `env` (print environment variables).
- Handles special characters: `" ' \` * & #`.
- Resolves command execution using the PATH environment variable.
- Handles end-of-file condition (Ctrl+D).

## Getting Started

### Prerequisites

- A Unix-like operating system (Linux, macOS, etc.).
- GCC compiler.

### Installation
You can install the simple shell cloning this repo:
```sh
$ git clone https://github.com/acostanahuel/holbertonschool-simple_shell
```
Next you can compile the files with this command:
```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
finally you can run our Shell writing:
```sh
./hsh
```

### Usage
1. Compile the shell as mentioned above.

2. Run the compiled shell executable:
```sh
./hsh
```
3. The shell will display a prompt `($ )` and wait for user input.

4. Enter commands and press `Enter`. The shell will execute the commands and display the output.

5. Use the `exit` command to terminate the shell.

### Examples
```sh
$ ./hsh
$ $ ls
file1 file2
$ env
PATH=/usr/local/bin:/usr/bin:/bin
...
$ exit
```
### Files and Functions

`main.c`: implements a basic shell that repeatedly prompts the user for input, tokenizes the input, checks for built-in commands like "exit," searches for and executes external commands using the PATH, and then continues the loop. The loop ends when the user exits the shell using the "exit" command.

`shell.h`: Header file that defines function prototypes, structures, and external variables used in the shell.

`shell.c`: Main shell code containing the core logic and user interaction loop.

`input.c`: Handles input-related functions.

`path.c`: Handles functions related to the PATH environment variable.

`fork_and_exec.c`: Handles the forking and execution of commands.

`auxiliar_functions.c` : Contains auxiliary functions for string manipulation.

`free.c`: Contains functions to free dynamically allocated memory.


### Authors
Martin Morales
Nahuel Acosta