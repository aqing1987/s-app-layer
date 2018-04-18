## start the interpreter
* python
* python3
* python -c command [arg] ...
  Since Python statements often contain spaces or other characters that are
  special to the shell, it is usually advised to quote command in its entirety
  with single quotes.

* python -m module [arg] ...
  executes the source file for module as if you had spelled out its full name
  on the command line.

* python myscript.py
  The most common use case is, of course, a simple invocation of a script

## exit the interpreter
Typing an end-of-file character (Control-D on Unix, Control-Z on Windows) at
the primary prompt causes the interpreter to exit with a zero exit status. If
that doesn't work, you can exit the interpreter by typing the command: quit()

## command line editing
The interpreter's line-editing features include interactive editing, history
substitution and code completion on systems that support readline.
e.g. Control-P

## argument passing
When known to the interpreter, the script name and additional arguments
thereafter are turned into a list of strings and assigned to the **argv**
variable in the **sys** module. You can access this list by executing **import
sys**. The length of the list is at least one; when no script and no arguments
are given, **sys.argv[0]** is an empty string. When the script name is given
as '-' (meaning standard input), sys.argv[0] is set to '-'. When *-c command*
is used, sys.argv[0] is set to '-c'. When *-m module* is used, sys.argv[0] is
set to the full name of the located module. Options found after *-c command* or
*-m module* are not consumed by the Python interpreter's option processing but
left in sys.argv for the command or module to handle.

## interactive mode
When commands are read from a tty, the interpreter is said to be in *interactive
mode*. In this mode it prompts for the next command with the *primary prompt*,
usually three greater-than sings(>>>); for continuation lines it prompts with
the *secondary prompt*, by default three dots (...).

## source code encoding
By default, Python source files are treated as encoded in UTF-8. In that enco-
ding, characters of most languages in the world can be used simultaneously in
string literals, identifiers and comments. To display all these characters
properly, your editor must recognize that the file is UTF-8, and it must use
a font that supports all the characters in the file.
