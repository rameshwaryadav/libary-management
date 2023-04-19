
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    private:
        string title;
        string author;
        int id;
    public:
        Book(string title, string author, int id) {
            this->title = title;
            this->author = author;
            this->id = id;
        }
        string getTitle() {
            return title;
        }
        string getAuthor() {
            return author;
        }
        int getId() {
            return id;
        }
};

class Library {
    private:
        vector<Book> books;
    public:
        void addBook(string title, string author, int id) {
            Book book(title, author, id);
            books.push_back(book);
        }
        void removeBook(int id) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getId() == id) {
                    books.erase(books.begin() + i);
                    return;
                }
            }
        }
        void displayBooks() {
            for (int i = 0; i < books.size(); i++) {
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << " (ID: " << books[i].getId() << ")" << endl;
            }
        }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "Enter your choice:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Display books" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book author: ";
                cin >> author;
                cout << "Enter book ID: ";
                cin >> id;
                library.addBook(title, author, id);
                break;
            case 2:
                cout << "Enter book ID to remove: ";
                cin >> id;
                library.removeBook(id);
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, try again!" << endl;
        }
    }
    return 0;
}
