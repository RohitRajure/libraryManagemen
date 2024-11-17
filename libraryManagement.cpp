#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book structure to store book details
struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int bookId, string bookTitle, string bookAuthor)
        : id(bookId), title(bookTitle), author(bookAuthor), isAvailable(true) {}
};

// Library class
class Library {
private:
    vector<Book> books;

    // Helper function to find book by ID
    int findBookById(int id) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].id == id) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    // Add a new book to the library
    void addBook(int id, string title, string author) {
        if (findBookById(id) != -1) {
            cout << "A book with this ID already exists.\n";
            return;
        }
        books.emplace_back(id, title, author);
        cout << "Book added successfully!\n";
    }

    // Display all books in the library
    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }

        cout << "\nList of Books:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << "\n";
        }
    }

    // Search for a book by ID
    void searchBook(int id) {
        int index = findBookById(id);
        if (index == -1) {
            cout << "Book not found.\n";
        } else {
            const Book& book = books[index];
            cout << "Book Found: ID: " << book.id
                 << ", Title: " << book.title
                 << ", Author: " << book.author
                 << ", Available: " << (book.isAvailable ? "Yes" : "No") << "\n";
        }
    }

    // Delete a book by ID
    void deleteBook(int id) {
        int index = findBookById(id);
        if (index == -1) {
            cout << "Book not found.\n";
        } else {
            books.erase(books.begin() + index);
            cout << "Book deleted successfully.\n";
        }
    }
};

// Main function
int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // Ignore newline character
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            library.searchBook(id);
            break;

        case 4:
            cout << "Enter Book ID to delete: ";
            cin >> id;
            library.deleteBook(id);
            break;

        case 5:
            cout << "Exiting the system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
