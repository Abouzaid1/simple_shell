# Simple Shell Project

This Simple Shell project serves as an introductory Unix command line interpreter developed as part of the ALX SE program.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Compilation](#compilation)
- [Testing](#testing)
- [Acknowledgements](#acknowledgements)
- [Contributors](#contributors)

## Description

The Simple Shell is a fundamental project aimed at replicating basic shell functionalities within a Unix-based environment. This project introduces essential concepts related to command execution and error handling.


## Features

- **Displays Prompt:** Displays a prompt and accepts user input for command execution.
- **Argument Handling:** Handles command lines with arguments.
- **Error Handling:** Implements basic error handling when an executable cannot be found.
- **EOF Handling:** Manages the "end of file" condition (Ctrl+D).


## Getting Started

To begin using the Simple Shell project, clone the repository and follow the specified compilation instructions detailed in the [Compilation](#compilation) section.


## Usage

The shell supports both interactive and non-interactive modes, allowing users to execute simple commands. Refer to the [Testing](#testing) section for usage examples.


## File Descriptions

- **shell.h** Main header file that contains all functions used.
- **shell.c** Main file responsible for starting the shell, prompt display, input handling, and command execution.
- ***.c** All functions used to get input, handle errors, execute commands, and manipulate strings.


## Compilation
To compile the shell, use the following command:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```


## Testing
Shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Acknowledgements
This project was developed as part of the ALX SE program.


## Contributors
Fady Alaa - (Software Engineer)
