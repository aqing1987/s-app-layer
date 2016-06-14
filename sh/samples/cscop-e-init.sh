#!/bin/sh

# expr1 -o expr2
#   Or; expr2 is not evaluated if expr1 is true.

# expr1 expr2
#   Two expressions in a row are taken to be joined with an  implied
#   "and"; expr2 is not evaluated if expr1 is false.

# expr1 -a expr2
#   Same with expr1 expr2

# -print
#    True; print the full file name on the standard output, followed
#    by a newline. If  you  are  piping  the output of find into
#    another program and there is the faintest possibility  that  the
#    files  which you are searching for might contain a newline, then
#    you should seriously consider using the -print0  option  instead
#    of  -print. 

CSCOPE_NAME=cscope.files
CSCOPE_DB=cscope.out

if [ $# -ne 1 ]; then
    echo "$0 [update|create]"
    exit
fi

if [ $1 = "update" ]; then
    if [ ! -f "$CSCOPE_NAME" ]; then
        echo "$CSCOPE_NAME not exist."
        exit
    else
        echo "> cscope database updating <"
        cscope -Rbk -i "$CSCOPE_NAME"
        echo "< cscope database updatated >"
    fi
else
    echo "> cscope database creating <"
    find . \
	     -path "./target" -prune -o \
	     -path "./tftp" -prune -o \
	     -path "./ipnc_app/mxt_apps/out" -prune -o \
	     -name "*.[ch]" -o \
	     -name "*.cpp" -o \
	     -name "*.hh" -o \
	     -name "*.[sS]" -o \
	     -name "Makefile" -o \
	     -name "*.[mM][kK]" -o \
	     -name "*.make" -o \
	     -name "[Cc]onfigure" -o \
	     -name "*.conf" -o \
	     -name "*.config" -o \
	     -name "*.cfg" -o \
	     -name "*.sh" -o \
	     -name "*.py" \
	     > "$CSCOPE_NAME"

    if [ -f "$CSCOPE_NAME" ]; then
        if [ -f "$CSCOPE_DB" ]; then
            rm "$CSCOPE_DB"
        fi
	    cscope -Rbk -i "$CSCOPE_NAME"
        echo "< cscope database created >"
    fi
fi
