//Library Management System

#include <iostream>
#include <vector>

using namespace std;

// Base class representing a Book
class Book {
private:
    string title;
    string author;

public:
    // Constructor
    Book(const string& title, const string& author) : title(title), author(author) {}

    // Getter methods
    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    // Display book information
    virtual void displayInfo() const {
        cout << "Title: " << title << "\nAuthor: " << author << endl;
    }
};

// Derived class representing a Fiction Book
class FictionBook : public Book {
private:
    string genre;

public:
    // Constructor
    FictionBook(const string& title, const string& author, const string& genre)
        : Book(title, author), genre(genre) {}

    // Display fiction book information
    void displayInfo() const override {
        cout << "Fiction Book\n";
        Book::displayInfo();
        cout << "Genre: " << genre << endl;
    }
};

// Library class representing a collection of books
class Library {
private:
    vector<Book*> books;

public:
    // Add a book to the library
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Display information about all books in the library
    void displayAllBooks() const {
        cout << "Library Inventory:\n";
        for (const Book* book : books) {
            book->displayInfo();
            cout << "----------------------\n";
        }
    }
};

int main() {
    // Create some book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger");
    FictionBook fictionBook1("To Kill a Mockingbird", "Harper Lee", "Fiction");

    // Create a library and add books to it
    Library library;
    library.addBook(&book1);
    library.addBook(&fictionBook1);

    // Display all books in the library
    library.displayAllBooks();

    return 0;
}
