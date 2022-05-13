# Library book accounting program

- C ++ programming language.
- Microsoft Visual Studio 2019 development environment.
- Project form - console.
- Programming paradigm - object-oriented.
- Method of data organization - fields of the corresponding classes.
- Method of data storage - files.

## PROGRAM DESIGN
### Data organization:

- as a choice of input method description: BOOK class, fields: num, author, name, year, edition, pages, ticket, av, user, pass;

- as a way to combine input: the global variable arr [n] (# define n 10) and the global variable temp are created in BOOK

### Functionality

#### User functions:

- void display () - output of all data about books;
- void find () - search for a book by a certain parameter;
- void sorting () - sort books by a certain parameter;
- void status () - display a list of books that are currently with readers or in the library;

#### Administrator functions:

- userdisplay () - output of all user data;
- adduser () - add a new user;
- edit () - edit user data;
- delus () - delete user;
- writefile () - write data to a file
- addfile () - add a new book to the existing file at the end;
- editrec () - edit book data;
- delrec () - delete book data;
- delfile () - delete the file;
