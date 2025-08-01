#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    void input() {
        cout << "xxxxxxxxxxxxxxxxxxBook ID: ";
        cin >> id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
    }

    void show() const {
        cout << id << ": " << title << " by " << author << endl;
    }
};

void addBook(Book books[], int &n) {
    if (n < 100) {
        cout << "Book ID: ";
        cin >> books[n].id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, books[n].title);
        cout << "Author: ";
        getline(cin, books[n].author);
        n++;
    } else {
        cout << "Full\n";
    }
}

void showBooks(Book books[], int n) {
    if (n == 0) {
        cout << "Empty\n";
    } else {
        for (int i = 0; i < n; ++i)
            cout << books[i].id << ": " << books[i].title << " by " << books[i].author << endl;
    }
}

void searchBook(Book books[], int n) {
    cout << "ID: ";
    int id;
    cin >> id;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        if (books[i].id == id) {
            cout << books[i].id << ": " << books[i].title << " by " << books[i].author << endl;
            return;
        }
    }
    cout << "Not found\n";
}

void deleteBook(Book books[], int &n) {
    cout << "ID: ";
    int id;
    cin >> id;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        if (books[i].id == id) {
            for (int j = i; j < n - 1; ++j)
                books[j] = books[j + 1];
            n--;
            cout << "Deleted\n";
            return;
        }
    }
    cout << "Not found\n";
}

void editBook(Book books[], int n) {
    cout << "ID: ";
    int id;
    cin >> id;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        if (books[i].id == id) {
            cout << "New Title: ";
            getline(cin, books[i].title);
            cout << "New Author: ";
            getline(cin, books[i].author);
            cout << "Updated\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    Book books[100];
    int n = 0, c;
    while (true) {
        cout << "\n1.Add 2.Show 3.Search 4.Delete 5.Edit 0.Exit\nChoice: ";
        cin >> c;
        cin.ignore();
        if (c == 0) break;
        if (c == 1) addBook(books, n);
        else if (c == 2) showBooks(books, n);
        else if (c == 3) searchBook(books, n);
        else if (c == 4) deleteBook(books, n);
        else if (c == 5) editBook(books, n);
        else cout << "Invalid choice\n";
    }
    return 0;
}