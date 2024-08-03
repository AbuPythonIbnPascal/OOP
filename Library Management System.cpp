//Library Management System

#include <iostream>
#include <vector>

using namespace std;

class Book {
private:
    string title;
    string author;

public:

    Book(const string& title, const string& author) : title(title), author(author) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    virtual void displayInfo() const {
        cout << "Title: " << title << "\nAuthor: " << author << endl;
    }
};

class FictionBook : public Book {
private:
    string genre;

public:
    FictionBook(const string& title, const string& author, const string& genre)
        : Book(title, author), genre(genre) {}

    void displayInfo() const override {
        cout << "Fiction Book\n";
        Book::displayInfo();
        cout << "Genre: " << genre << endl;
    }
};

class Library {

private:
    vector<Book*> books;

public:
    void addBook(Book* book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        cout << "Library Inventory:\n";
        for (const Book* book : books) {
            book->displayInfo();
            cout << "----------------------\n";
        }
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger");
    FictionBook fictionBook1("To Kill a Mockingbird", "Harper Lee", "Fiction");

    Library library;
    library.addBook(&book1);
    library.addBook(&fictionBook1);

    library.displayAllBooks();

    return 0;
}
