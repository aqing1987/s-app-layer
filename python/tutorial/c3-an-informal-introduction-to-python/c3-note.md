Comments in python start with the hash character, #, and extend to the end of
the physical line. A hash character within a string literal is just a hash
character.

## Numbers
* The integer numbers (e.g. 2, 4, 20) have type int, the ones with a fractional
  part (e.g. 5.0, 1.6) have type float.
* Division (/) always returns a float.
* To do floor division and get an integer result, use // operator
* to calculatte the remainder use %
* use ** operator to calculate powers
* the equal sign (=) is used to assign a value to a variable
* if a variable is not "defined", trying to use it will give you an error
* in interactive mode, the last printed expression is assigned to the variable
  (_)

## Strings
* strings can be enclosed in single quotes('...') or double quotes("...")
* \ can be used to escape quotes
* The string is enclosed in double quotes if the string contains a single quote
  and no double quotes, otherwise it is enclosed in single quotes.
* If you don't want characters prefaced by \ to be interpreted as special
  characters, you can use *raw strings* by adding an r before the first quote

* String literals can span multiple lines. One way is using triple-quotes
  """...""" or '''...'''. End of lines are automatically included in the
  string, but it's possible to prevent this by adding a \ at the end of
  the line.

* strings can be concatenated (glued together) with the + operator, and
  repeated with *

* two or more string literals next to each other are automatically
  concatenated. This only works with two literals though, not with variables
  or expressions. This feature is particularly useful when you want to
  break long string.

* if you want to concatenate variables or a variable and a literal, use +
* strings can be indexed(subscripted), with the first character having index
  0. There is separate character type; a character is simply a string of
  size one.

* indices may also be negative numbers. to start counting from the right.
  Note that since -0 is the same as 0, negative indices start from -1.

* slicing is supported. While indexing is used to obtain individual characters
  slicing allows you to obtain substring.
  Note the start is always included, and the end always excluded. This makes
  sure that s[:i] + s[i:] is always equal to s

* an omitted first index defaults to 0, an omitted second index defaults to
  the size of the string being sliced.

* Attempting to use an index that is too large will result in an error,
  however, out of range slice indexes are handled gracefully when used for
  slicing.

* python strings cannot be changed - they are immutable. Therefore, assigning
  to an indexed position in the string results in an error.

* the built-in function len() returns the length of a string.

## Lists
python knows a number of compound data types, used to group together other
values. The most versatile is the list, which can be written as a list of
comma-separated values (items) between square brackets. Lists might contain
items of different types, but usually the items all have the same type.

* lists can be indexed and sliced
* all slice operations return a new list containing the requested elements.
  it's shallow copy.

* list supports operations like concatenation
* Unlike string, which are immutable, lists are a mutable type, i.g. it is
  possible to change their content.

* You can add new items at the end of the list, by using the append() method
* assignment to slices is also possible, and this can even change the size of
  the list or clear it entirely.

* the built-in function len() also applies to lists.
* it is possible to nest lists

## First Steps Towards Programming
* multiple assignment supported, e.g.
  a, b = 0, 1

* In python, like in C, any non-zero integer value is true; zero is false.
  The condition may also be a string or list value, in fact any sequence;
  anything with a non-zero length is true, empty sequences are false.

* indentation is Python's way of grouping statements.
