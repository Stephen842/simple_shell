This is a team project of which me and my partner opera Nyamosi will be on creation of a Unix CLI.
In this task we are gonna be coming up with the following,

Writing a UNIX command line interpreter.

Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)

the shell can be able to handle command line with argument

can handle the PATH

can implement the exit built-in, that exits the shell

will implement the env builtin, whose purpose is to print the current environment.

we are gonna be writing our getline function, using a buffer to read multiple chars at once.

it will handle argument for the built-in exit

it will implement the set environment and unset environment builtin command

implementing the cd builtin command that help in changing the current directory
handle environment seperator

it will handle the && and || logical operators
implement the built in alias command
can handle variable replacement
handle comment
and lastly can be able to take file as an input.
