#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#define n 10
#define u 2
class BOOK {
public:
    int num;// registration number of the book
    string author;// author
    string name;// bookname
    int year;// year of publishment
    string edition;// edition
    int pages;// number of pages
    int  ticket;// reader's ticket number (six digits) of the recent reader
    char av;// location of the book (library or with the reader
    string user;// login
    int pass;// password
}b;
struct BOOK arr[n];
struct BOOK temp;
int count() {//determine the number of lines in the accounts file
    ifstream Book("book.txt");
    int h = 0;
    string line;
    while (getline(Book, line))
        h++;
    return h;
    Book.close();
}
void display() {//display all book data
    ifstream Book("book.txt");
    int h = count();
    cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  "<<
        "EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
    for (int i = 0; i < h; i++) {
        Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << 
            arr[i].year << setw(15) << arr[i].edition << setw(10) << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
    }
    cout << "\xc8\n";
    Book.close();
}
void find() {//find  a book by a certain parameter
    int f,k=0;
    ifstream Book("book.txt");
    int h = count();
    cout << "\n  FIND a book by: \n  1 - number\n  2 - author\n  3 - name \n  4 - written after _ year \n  5 - Back to the menu \n  Your choice: ";
    cin >> f;
    switch (f)
    {
    case 1:
        int nu;
        cout << "  Enter number: ";
        cin >> nu;
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        
            if (nu == arr[i].num) {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                    << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
                k++;
            }
        }
        if (k == 0) {
            cout << "\n\t The record is not found" << endl;
        }
        break;
    case 2: {
        string au;
        cout << "  Enter author name: ";
        cin >> au;
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;

            if (au == arr[i].author) {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                    << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
                k++;
            }
        }
        if (k == 0) {
            cout << "\n\t The record is not found" << endl;
        }
        break;
    }
    case 3: {
        string na;
        cout << "  Enter name of a book: ";
        cin >> na;
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;

            if (na == arr[i].name) {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                    << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
                k++;
            }
        }
        if (k == 0) {
            cout << "\n\t The record is not found" << endl;
        }
        break;
    }
    case 4:
        int ye;
        cout << "  Enter year: ";
        cin >> ye;
        if (ye > 2021) {
            cout << " Incorrect year! ";
            find();
        }
            
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        }
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            if (ye < arr[i].year) {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                    << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
                k++;
            }
        }
        if (k == 0) {
            cout << "\n\t The record is not found" << endl;
        }
        break;
    
    case 5:
        break;
    }

}
void sorting() {//sort books by a certain parameter
    int s;
    ifstream Book("book.txt");
    int h = count();
    cout << "\n  SORT books by: \n  1 - author name\n  2 - book name\n  3 - year(oldest - newest)\n  4 - year(newest - oldest) \n  5 - Back to the menu\n  Your choice: ";
    cin >> s;
    switch (s)
    {
    case 1:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < n; i++){
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        }
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < h; j++)
            {
                if (arr[i].author < arr[j].author)
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        } 
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
        }
        break;
    case 2:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        }
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < h; j++)
            {
                if (arr[i].name < arr[j].name)
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
        }
        break;
    case 3:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        }
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < h; j++)
            {
                if (arr[i].year < arr[j].year)
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
        }
        break;
    case 4:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        }
        for (auto i = 0; i < h; i++)
        {
            for (auto j = 0; j < n; j++)
            {
                if (arr[i].year > arr[j].year)
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(16) << arr[i].name << setw(9) << arr[i].year << setw(15) << arr[i].edition << setw(10) 
                << arr[i].pages << setw(12) << arr[i].ticket << setw(12) << arr[i].av << endl;
        }
        break;
    case 5:
        break;
    }
    Book.close();
    }
void status() {//display a list of books that are currently with readers or in the library
    int s;
    ifstream Book("book.txt");
    int h = count();
    cout << "  Show:  \n  1 - Avialable books \n  2 - Unvialable books\n  3 - Back to the menu\n  Your choice: ";
    cin >> s;
    switch (s)
    {
    case 1:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            if (arr[i].av == 'l') {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(15) << arr[i].name << setw(9) << arr[i].year << "      " << arr[i].edition << "       " << arr[i].pages
                    << "      " << arr[i].ticket << setw(11) << arr[i].av << endl;
            }
        }
            break;
    case 2:
        cout << "\xc9 N \xcd\xcb\xcd AUTHOR  \xcd\xcb\xcd   NAME   \xcd\xcb\xcd YEAR  \xcd\xcb\xcd  EDITION  \xcd\xcb\xcd  PAGES \xcd\xcb\xcd TICKET \xcd\xcb\xcd Placement(l/r) \xbb" << endl;
        for (int i = 0; i < h; i++) {
            Book >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
            if (arr[i].av == 'r') {
                cout << "\xba" << arr[i].num << " \xba  " << arr[i].author << setw(15) << arr[i].name << setw(9) << arr[i].year << "      " << arr[i].edition << "       " << arr[i].pages 
                    << "      " << arr[i].ticket << setw(11) << arr[i].av << endl;
            }
        }
        break;
    case 3:
        break;
        }
    Book.close();
}
void writefile() {//write data to a file;
    ofstream Book("book.txt");
    int n1, y1, p1, t1, l;
    string a1, na1,e1;
    char av1;
    cout << " How many books would u like to add? ";
    cin >> l;
    for (int i = 0; i < l; i++) {
        cout << " \xf9 Enter Book NUMBER  "; cin >> n1;
        cout << " \xf9 Enter Books AUTHOR  "; cin >> a1;
        cout << " \xf9 Enter Books NAME  "; cin >> na1;
        cout << " \xf9 Enter Books YEAR  "; cin >> y1;
        if (y1 > 2021) {
            cout << " INCORRECT YEAR! \n   Enter again: ";
            cin >> y1;
        }
        cout << " \xf9 Enter Books EDITION  "; cin >> e1;
        cout << " \xf9 Enter number of PAGES  "; cin >> p1;
        cout << " \xf9 Enter READERS TICKET number ( 6 digits )  "; cin >> t1;
        if (t1 < 99999 || t1 > 1000000) {
            cout << " INCORRECT TICKET! \n   Enter again: ";
            cin >> t1;
        }
        cout << " \xf9 Enter Books PLACEMENT(l/r)  "; cin >> av1;
        if (av1 != 'l' && av1 != 'r') {
            cout << " INCORRECT PLACEMENT! \n   Enter again(l/r): ";
            cin >> av1;
        }
        cout << endl;
        Book << n1 << " " << a1 << " " << na1 << " " << y1 << " " << e1 << " " << p1 << " " << t1 << " " << av1 << endl;
        }
    Book.close();
    }
void addfile() {//adding a new book to an existing file at the end 
    ofstream Book;
    Book.open("book.txt", std::ios_base::app);
    int n1, y1, p1, t1, l;
    string a1, na1, e1;
    char av1;
    cout << " How many books would u like to add? ";
    cin >> l;
    for (int i = 0; i < l; i++) {
        cout << " \xf9 Enter Book NUMBER  "; cin >> n1;
        if (n1 < 0) {
            cout << " INCORRECT NUMBER! \n   Enter again: ";
            cin >> n1;
        }
        cout << " \xf9 Enter Books AUTHOR  "; cin >> a1;
        cout << " \xf9 Enter Books NAME  "; cin >> na1;
        cout << " \xf9 Enter Books YEAR  "; cin >> y1;
        if (y1 > 2021||y1<1) {
            cout << " INCORRECT YEAR! \n   Enter again: ";
            cin >> y1;
        }
        cout << " \xf9 Enter Books EDITION  "; cin >> e1;
        cout << " \xf9 Enter number of PAGES  "; cin >> p1;
        cout << " \xf9 Enter READERS TICKET number ( 6 digits )  "; cin >> t1;
        if (t1 < 99999 || t1 > 1000000) {

            cout << " INCORRECT TICKET! \n   Enter again: ";
            cin >> t1;
        }
        cout << " \xf9 Enter Books PLACEMENT(l/r)  "; cin >> av1;
        if (av1 != 'l' && av1 != 'r') {
            cout << " INCORRECT PLACEMENT! \n   Enter again(l/r): ";
            cin >> av1;
        }
        cout << endl;
        Book << n1 << " " << a1 << " " << na1 << " " << y1 << " " << e1 << " " << p1 << " " << t1 << " " << av1 << endl;
    }
    Book.close();
}
void delfile() {//deleting file
    int c;
    char Book[] = "book.txt"; 
    cout << "  Are you sure you want to delete file? \n  1 - Yes   2 - No \n  Your choice: ";
    cin >> c;
    if (c == 1) {
        if (remove("book.txt") != 0)
            perror("File deletion failed");
        else
            cout << " \xf9 File deleted successfully \xf9 \n";
    }
}
void delrec() {//deleting book record
    int h = count(),k=0,c;
    ifstream Users;
    ofstream temp;
    Users.open("book.txt");
    temp.open("temp.txt");
    string line, name;
    for (int i = 0; i < h; i++) {
        Users >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        cout << " \xf9 " << arr[i].name << endl;
    }
    cout << "  Please Enter the name of book you want to delete: ";
    cin >> name;
    cout << "  Are you sure you want to delete " << name << "? \n  1 - Yes   2 - No \n  Your choice: ";
    cin >> c;
    if (c == 1) {
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].name)) {
                temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << 
                    arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
                k++;
            }

        }
        if (k == h) {
            cout << "\n The book with the name " << name << " not found" << endl;
        }
        else
            cout << "\n The book with the name " << name << " has been deleted" << endl;
        Users.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}
void editrec() {//editing book record 
    string line, name, letter;
    int h = count(),c, number;
    ifstream Users;
    ofstream temp;
    Users.open("book.txt");
    temp.open("temp.txt");
    int skip = 0;

    for (int i = 0; i < h; i++) {
        Users >> arr[i].num >> arr[i].author >> arr[i].name >> arr[i].year >> arr[i].edition >> arr[i].pages >> arr[i].ticket >> arr[i].av;
        cout << " \xf9 " << arr[i].name << endl;
    }
    cout << "  Please Enter the name of book you want to edit: ";
    cin >> name;
    cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb" <<
        endl << "\xba  Change:             \xba" << endl << "\xba\xf9 1 - Number          \xba" << endl << "\xba\xf9 2 - Authors name    \xba" << endl << "\xba\xf9 3 - Books name      \xba" << 
        endl << "\xba\xf9 4 - Year            \xba" << endl << "\xba\xf9 5 - Edition         \xba" << endl << "\xba\xf9 6 - Pages           \xba" << endl << "\xba\xf9 7 - Readers ticket  \xba" 
        << endl << "\xba\xf9 8 - Placement(l/r)  \xba" << endl << "\xba\xf9 9 - Close           \xba\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" 
        << endl << " Your option: ";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << " Enter new Number: ";
        cin >> number;
            for (int i = 0; i < h; i++) {
                getline(Users, line);
                if ((name != arr[i].name) && !(skip > 0)) {
                    temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
                }else
                    temp << number << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
            }
        break;
    case 2:
        cout << " Enter new Author: ";
        cin >> letter;
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].name) && !(skip > 0)) {
                temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
            }
            else
                temp << arr[i].num << " " << letter << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
        }
        break;
    case 3:
        cout << " Enter new Books name: ";
        cin >> letter;
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].name) && !(skip > 0)) {
                temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
            }
            else
                temp << arr[i].num << " " << arr[i].author << " " << letter << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
        }
        break;
    case 4:
        cout << " Enter new Year: ";
        cin >> number;        
        if (number > 2021 || number < 1) {
            cout << " INCORRECT YEAR! \n   Enter again: ";
            cin >> number;
        }
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].name) && !(skip > 0)) {
                temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
            }
            else
                temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << number << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
        }
        break;   
       case 5:
           cout << " Enter new Edition: ";
           cin >> letter;
           for (int i = 0; i < h; i++) {
               getline(Users, line);
               if ((name != arr[i].name) && !(skip > 0)) {
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
               }
               else
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << letter << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
           }
           break;
       case 6:
           cout << " Enter new number of Pages: ";
           cin >> number;
           for (int i = 0; i < h; i++) {
               getline(Users, line);
               if ((name != arr[i].name) && !(skip > 0)) {
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
               }
               else
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << number << " " << arr[i].ticket << " " << arr[i].av << endl;
           }
           break;
       case 7:
           cout << " Enter new Readers ticket: ";
           cin >> number;
           if (number < 99999 || number > 1000000) {
               cout << " INCORRECT TICKET! \n   Enter again(l/r): ";
               cin >> number;
           }
           for (int i = 0; i < h; i++) {
               getline(Users, line);
               if ((name != arr[i].name) && !(skip > 0)) {
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
               }
               else
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << number << " " << arr[i].av << endl;
           }
           break;
       case 8:
           cout << " Enter new Placement(l/r): ";
           cin >> letter;
           if (letter != "l" && letter != "r") {
               cout << " INCORRECT PLACEMENT! \n   Enter again(l/r): ";
               cin >> letter;
           }
           for (int i = 0; i < h; i++) {
               getline(Users, line);
               if ((name != arr[i].name) && !(skip > 0)) {
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << arr[i].av << endl;
               }
               else
                   temp << arr[i].num << " " << arr[i].author << " " << arr[i].name << " " << arr[i].year << " " << arr[i].edition << " " << arr[i].pages << " " << arr[i].ticket << " " << letter << endl;
           }
           break;
       case 9: 
           break;
    }
    cout << "\n The book with the name " << name << " has been changed" << endl;
    Users.close();
    temp.close();
    remove("book.txt");
    rename("temp.txt", "book.txt");
}
void booksed() {//menu for editing books file
    int b;
    cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\xba  "<<
        "Library book info:  \xba\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9" <<
        endl << "\xba Choose option:       \xba" << endl << "\xba\xf9 1 - Read file       \xba" << endl 
        << "\xba\xf9 2 - Write to file   \xba" << endl << "\xba\xf9 3 - Add to file     \xba" << endl 
        << "\xba\xf9 4 - Edit record     \xba" << endl << "\xba\xf9 5 - Delete record   \xba" << endl 
        << "\xba\xf9 6 - Delete file     \xba" << endl << "\xba\xf9 7 - Close           \xba\n\xc8\xcd\xcd\xcd\xcd\xcd" << 
        "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << endl << " Your option: ";
    cin >> b;
    switch (b)
    {
    case 1:
        display();
        break;
    case 2:
        writefile();
        break;
    case 3:
        addfile();
        break;
    case 4:
        editrec();
        break;
    case 5:
        delrec();
        break;
    case 6:
        delfile();
        break;
    case 7:
        break;
    }
}
int countus() {determine the number of lines in the users file
    ifstream Users("users.txt");
    int h = 0;
    string line;
    while (getline(Users, line))
        h++;
    return h;
    Users.close();
}
void userdisplay() {//display all users
    ifstream Users("users.txt");
    int h = countus();
    cout << "  USERS:  \n";
    for (int i = 0; i < h; i++) {
        Users >> arr[i].user >> arr[i].pass;
        cout <<" \xf9 "<< arr[i].user  << endl;
    }
    Users.close();
}
void adduser() {//add new user
    string us;
    int p,k=0;
    ofstream Users;
    ifstream Us;
    Us.open("users.txt");
    int h = countus();
    Users.open("users.txt", std::ios_base::app);          
    cout << " \xf9 Enter Username  "; cin >> us;
    cout << " \xf9 Enter Password  "; cin >> p;                
    for (int i = 0; i < h; i++) {
        Us >> arr[i].user >> arr[i].pass;
        if ((us == arr[i].user)) {
            k++;
        }
    }
    if(k==0)
    {
        Users << us << " " << p << endl;       
    }
    else {
        cout << " User with this name already exists \n  Try again: \n";
        adduser();
    }
    Us.close();
    Users.close();
}
void edit() {// edit user
    string line, name, newus;
    int h = countus(),k=0, c;
    ifstream Users;
    ofstream temp;
    Users.open("users.txt");
    temp.open("temp.txt");
    cout << " Which user do you want to change? \n  USERS:  \n";
    for (int i = 0; i < h; i++) {
        Users >> arr[i].user >> arr[i].pass;
        cout << " \xf9 " << arr[i].user << endl;
    }
    cout << " Enter user: ";
    cin >> name;
    cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb" <<
        endl << "\xba  Change:             \xba" << endl << "\xba\xf9 1 - Username        \xba" << endl << "\xba\xf9 2 - Password        \xba" << 
        endl << "\xba\xf9 3 - Close           \xba\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << endl << " Your option: ";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << " Enter new Username: ";
        cin >> newus;
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].user)) {
                temp << arr[i].user << " " << arr[i].pass << endl;
                k++;
            }
            else {
                temp << newus << " " << arr[i].pass << endl;             
            }
        }
        break;
    case 2:
        cout << " Enter new Password: ";
        cin >> newus;
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].user)) {
                temp << arr[i].user << " " << arr[i].pass << endl;
                k++;
            }
            else {
                temp << arr[i].user << " " << newus << endl;
            }
        }
        break;
    }
    if (k == h) {
        cout << "\n The record with the name " << name << " is not found" << endl;
    }
    else
        cout << "The record with the name " << name << " has been changed" << endl;
        Users.close();
        temp.close();
        remove("users.txt");
        rename("temp.txt", "users.txt");
}
void delus() {// delete user
    string line, name;   
    int h = countus(),k=0,c;
    ifstream Users;
    ofstream temp;
    Users.open("users.txt");
    temp.open("temp.txt");
    for (int i = 0; i < h; i++) {
        Users >> arr[i].user >> arr[i].pass;
        cout << " \xf9 " << arr[i].user << endl;
    }
    cout << "  Please Enter the name of user you want to delete: ";
    cin >> name;
    cout << "  Are you sure you want to delete "<<name<<"? \n  1 - Yes   2 - No \n  Your choice: ";
    cin >> c;
    if(c==1){
        for (int i = 0; i < h; i++) {
            getline(Users, line);
            if ((name != arr[i].user)) {
                temp << arr[i].user <<" "<< arr[i].pass << endl;
                k++;     
            }
        }
        if (k == h) {
            cout << "\n The record with the name " << name << " is not found" << endl;
        }
        else
            cout << "\n The record with the name " << name << " has been deleted" << endl;
        Users.close();
        temp.close();
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
}
void users() {// menu for working with the users file 
    int b;
    cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\xba "<<
        " Library book info:  \xba\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9" <<
        endl << "\xba Choose option:       \xba" << endl << "\xba\xf9 1 - Show all users  \xba" << endl 
        << "\xba\xf9 2 - Add new user    \xba" << endl << "\xba\xf9 3 - Edit user       \xba" << endl 
        << "\xba\xf9 4 - Delete user     \xba" << endl << "\xba\xf9 5 - Close           \xba\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<
        "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << endl << " Your option: ";
    cin >> b;
    switch (b)
    {
    case 1:
        userdisplay();
        break;
    case 2:
        adduser();
        break;
    case 3:
        edit();
        break;
    case 4:
        delus();
        break;
    case 5:
        break;
    }
}
void menuus() {//user module
    int c = 0;
    do {
        cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<
            "\xcd\xcd\xcd\xcd\xcd\xbb\n\xba  Library book info:  \xba\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd"<<
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9" <<
            endl<< "\xba Choose option:       \xba" << endl << "\xba\xf9 1 - Show all books  \xba" <<
            endl << "\xba\xf9 2 - Find a book     \xba" << endl << "\xba\xf9 3 - Sort books      \xba" << 
            endl << "\xba\xf9 4 - Show book status\xba"<< endl << "\xba\xf9 5 - Close           \xba\n\xc8"<<
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << 
            endl << " Your option: ";
        cin >> c;
        switch (c)
        {
        case 1:

            display();
            break;
        case 2:
            find();
            break;
        case 3:
            sorting();
            break;
        case 4:
            status();
            break;
        }
    } while (c != 5);
}
void books() {//menu for working with the books file
    int b;
    cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\xba  " <<
        "Library book info:  \xba\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9" <<
        endl << "\xba Choose option:       \xba" << endl << "\xba\xf9 1 - Editing file    \xba" << endl
        << "\xba\xf9 2 - Processing file \xba" << endl <<"\xba\xf9 3 - Close           \xba\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" <<
        "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << "\n Your option: ";
    cin >> b;
    switch (b)
    {
    case 1:
        booksed();
        break;
    case 2:
        menuus();
        break;
    case 3:
        break;
    }
}
void menuad() {//administrator module
    int c = 0;
    do {
        cout << "\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\xba  Library book info:  "<<
            "    \xba\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9" <<
            endl << "\xba Choose option:           \xba" << 
            endl << "\xba\xf9 1 - Work with user file \xba" << 
            endl << "\xba\xf9 2 - Work with book file \xba" << 
            endl << "\xba\xf9 3 - Close               \xba\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<
            "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc" << 
            endl << " Your option: ";
        cin >> c;
        switch (c)
        {
        case 1:
            users();
            break;
        case 2:
            books();
            break;
        }
    } while (c != 3);
}
int registration() {//registration
    ifstream Users("users.txt");
    string login, line;
    int pass, o=0;
    int h = countus();
    int role = 0;
    cout << " Enter login: ";
    cin >> login;
    cout << " Enter Password: ";
    cin >> pass;
    for (int i = 0; i < h; i++) {
        Users >> arr[i].user >> arr[i].pass;
        if (login != arr[i].user|| pass != arr[i].pass) {
            o++; 
         }
    }
    if (o / h == 1) {
        cout << " No user found! " << endl;
        registration();
    }
    Users.close();
    
    if (login == "admin")
        role = 1;
    else 
        role = 0;
    return role;
}
int main() {
     ifstream Users("users.txt");
     ifstream Book("book.txt");
     if(!Book)
        cout << "Error: file could not be opened" << endl;
     if (!Users)
         cout << "Error: file could not be opened" << endl;
    Book.close();
    Users.close();
    int role = 0;
    system("color F3");
    role = registration();
    if (role == 0) {
        menuus();
    }else if (role == 1) {
        menuad();
    }
}
