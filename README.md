# dispatch_game
A simple application to traverse a user through a theoretical 2D plane with (x, y) coordinates. You can create a player by designating an ID for the player on startup. Then, you are able to move that user through the plane using 'wsad', which increments/decrements the (x,y) coordinates. 

# Authors/Contributors
Chris Anderson (ChrisShocker)
Micah Blasko (micahblasko) 
Samuel Parker (pdxsam2)

# Technical Description
Users are stored in a hash-table consisting of an array of dynamically allocated linked lists, the hashing function relies on the user's ID. 

Users privately contain (x, y) coordinates, their ID, and a dynamically allocated linked list of their previous moves.
A publically accessible function dispatch table (fdt) contains the following moves:
- up()
- down()
- left()
- right()
Of which alter the user's coordinates. 

NOTE: the list of moves stores *function pointers* to the user's fdt. The user's `display()` prints the user's ID, and then calls the move list's `display()`. The list's display creates a 'mock' user called a 'ct_dummy' (for crash test dummy) which traverses the list of moves and calls each function pointer on the ct_dummy, and displays the change in coordinates.

# Compilation and Execution
Make sure you have the GNU C++ compiler downloaded, in the repository's directory enter:

`g++ *.cpp`

To execute:

`./a.out`

# Style Guide

This repository is implemented using the following style guide, based on tips from Rob Martin's Clean Code book:
## Meaningful Names
- Use intention-revealing names
- No Puns
- Avoid using the same word for more than one purpose
- Make meaningful distinctions between names:
    - I.e. if copying to an array, use duplicate_array instead of array2
- Use pronounceable names
- Don't abbreviate, use full words you can read and understand to help understand it later. This leads to better conversation about the variable.
- 
## Functions
- Functions should DO ONE THING
- Avoid passing a binary flag into a function, if that’s the case just use a function for each case
- Don’t use an argument as a return value 0  

## Comments
- TODOs are useful! Remember to remove them afterward
- Commented out code should be removed or tagged as TODO
- Leave a description above function implementation
- Multi-line comments should use multi-line comment syntax 

## Formatting
- Snake case entity names
- Use All-Caps globals
- Allman Indentation Style
- Curly braces should wrap implementation
- Use spaces before and after operators
    - +, =, -, *, <, >, ==, etc. 
- Lines should not exceed 120 characters
- Functions have a newline before their declaration and after their closing curly brace

## Objects and Data Structures
- One class per file
- Use ‘this’ for the current object’s members and methods
- Avoid train wrecks (also just a good life tip)
    - Chaining multiple functions on one line is indicative of a design issue

## Error Handling and Preventing Errors
- Initialize all variables to a value (even if it is NULL, or 0)
- Try - Catch blocks for handling errors
- Use Enum error codes
    - I.e. Don’t return or pass NULL.
## Best Practices 
- Compile with -g and -Wall flags to enable warnings and gdb
