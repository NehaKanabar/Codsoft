#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool isCheckedOut = false;
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void searchBooks(const std::string& searchTerm) {
        std::cout << "Search Results:\n";
        for (const Book& book : books) {
            if (book.title.find(searchTerm) != std::string::npos ||
                book.author.find(searchTerm) != std::string::npos ||
                book.ISBN.find(searchTerm) != std::string::npos) {
                std::cout << "Title: " << book.title << "\n";
                std::cout << "Author: " << book.author << "\n";
                std::cout << "ISBN: " << book.ISBN << "\n";
                std::cout << "Availability: " << (book.isCheckedOut ? "Checked Out" : "Available") << "\n\n";
            }
        }
    }

    void checkoutBook(const std::string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN && !book.isCheckedOut) {
                book.isCheckedOut = true;
                std::cout << "Book checked out successfully.\n";
                return;
            }
        }
        std::cout << "Book not found or already checked out.\n";
    }

    void returnBook(const std::string& ISBN) {
        for (Book& book : books) {
            if (book.ISBN == ISBN && book.isCheckedOut) {
                book.isCheckedOut = false;
                std::cout << "Book returned successfully.\n";
                return;
            }
        }
        std::cout << "Book not found or not checked out.\n";
    }
};

int main() {
    Library library;

    Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565"};
    Book book2 = {"To Kill a Mockingbird", "Harper Lee", "978-0061120084"};

    library.addBook(book1);
    library.addBook(book2);

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Search Books\n";
        std::cout << "2. Checkout Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();
            std::cout << "Enter search term: ";
            std::string searchTerm;
            std::getline(std::cin, searchTerm);
            library.searchBooks(searchTerm);
        } else if (choice == 2) {
            std::cout << "Enter ISBN of the book to checkout: ";
            std::string ISBN;
            std::cin >> ISBN;
            library.checkoutBook(ISBN);
        } else if (choice == 3) {
            std::cout << "Enter ISBN of the book to return: ";
            std::string ISBN;
            std::cin >> ISBN;
            library.returnBook(ISBN);
        } else if (choice == 4) {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
