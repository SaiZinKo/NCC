//
// Created by Zin Ko Winn on 10/2/2022.
//

#include <iostream>
#include <fstream>

using namespace std;

char isExit() {
    char isExit;
    cout << "Do you want to exit? (y/n) : " << endl;
    cin >> isExit;
    return isExit;
}

class User {
private:
    int id = 0;
    string userName;
    string password;
    string confirmPassword;
public:
    void getUserData() {
        cout << endl;
        cout << "****************************************************" << endl;
        cout << "Registration Form" << endl;
        cout << "****************************************************" << endl << endl;
        cout << "Enter your id to register:";
        cin >> id;
        cout << "Enter your name to register:";
        cin >> userName;
        cout << "Enter your password to register:";
        cin >> password;
        cout << "Confirm password to register:";
        cin >> confirmPassword;
    }

    void showData() {
        cout << "Id : " << id << endl;
        cout << "UserName : " << userName << endl;
        cout << "Password : " << password << endl;
    }

    string getUserName() {
        return userName;
    }

    static int registration();

    static int login();

    static void findAllUser();

    static User findUserByUserId(int userId);

    static User findUserByUserName(string userName);

    static void updateUserByUserId(int userId, User newUser);

    static void updateUserByUserName(string userName, User newUser);

    static void deleteUserByUserId(int userId);

    static void deleteUserByUserName(string userName);
};

User userInstance;

int User::registration() {
    fstream file;
    file.open("user_data.txt", ios::app);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }
    userInstance.getUserData();
    if (userInstance.password == userInstance.confirmPassword) {
        file << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
             << userInstance.confirmPassword << ' ' << '\n';
        cout << "Registration Success!" << endl;
        userInstance.showData();
        file.close();
    } else {
        cout << "Registration failed. Password does not match." << endl;
    }
    return 0;
}

int User::login() {
    string userName;
    string password;
    cout << endl;
    cout << "****************************************************" << endl;
    cout << "Login Form" << endl;
    cout << "****************************************************" << endl << endl;
    cout << "Enter username to login:";
    cin >> userName;
    cout << "Enter password to login:";
    cin >> password;

    User user = User::findUserByUserName(userName);

    if (user.userName == userName && user.password == password) {
        cout << "Login Success" << endl;
        return user.id;
    } else {
        cout << "Invalid user name or password" << endl;
    }

    return user.userName == userName && user.password == password ? user.id : 0;
}

void User::findAllUser() {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;
        userInstance.showData();
    }

    file.close();
}

User User::findUserByUserId(int userId) {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isUserFound = 0;

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userId == userInstance.id) {
            isUserFound = 1;
            break;
        }
    }

    if (isUserFound == 0) {
        cout << "User not found!" << endl;
    } else {
        cout << "User found with user id : " << userInstance.id << endl;
        userInstance.showData();
    }
    file.close();
    return userInstance;
}

User User::findUserByUserName(string userName) {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isUserFound = 0;

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userName == userInstance.userName) {
            isUserFound = 1;
            break;
        }
    }

    if (isUserFound == 0) {
        cout << "User not found!" << endl;
    } else {
        cout << "User found with user user name : " << userInstance.userName << endl;
        userInstance.showData();
    }
    file.close();
    return userInstance;
}

void User::updateUserByUserId(int userId, User newUser) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }


    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userId == userInstance.id) {
            tmpFile << newUser.id << ' ' << newUser.userName << ' ' << newUser.password << ' '
                    << newUser.confirmPassword
                    << ' ' << '\n';
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.confirmPassword << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("user_data.txt");
    rename("temp.txt", "user_data.txt");
}

void User::updateUserByUserName(std::string userName, User newUser) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }


    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userName == userInstance.userName) {
            tmpFile << newUser.id << ' ' << newUser.userName << ' ' << newUser.password << ' '
                    << newUser.confirmPassword << ' ' << '\n';
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.confirmPassword << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("user_data.txt");
    rename("temp.txt", "user_data.txt");
}

void User::deleteUserByUserId(int userId) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userId == userInstance.id) {
            cout << "Deleted user : " << userInstance.id << endl;
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.confirmPassword << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("user_data.txt");
    rename("temp.txt", "user_data.txt");
}

void User::deleteUserByUserName(string userName) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.confirmPassword;

        if (userName == userInstance.userName) {
            cout << "Deleted user : " << userInstance.userName << endl;
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.confirmPassword << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("user_data.txt");
    rename("temp.txt", "user_data.txt");
}

class Book {
private:
    int id;
    string bookName;
    string authorName;
    string publisher;
    int price;
public:

    Book() {
        this->id = 0;
        this->price = 0;
    }

    void getBookData() {
        cout << "This is from registration" << endl;
        cout << "Enter id:";
        cin >> id;
        cout << "Enter book name:";
        cin >> bookName;
        cout << "Enter author name:";
        cin >> authorName;
        cout << "Enter publisher:";
        cin >> publisher;
        cout << "Enter price:";
        cin >> price;
    }

    void showData() {
        cout << "Id : " << id << endl;
        cout << "Book Name : " << bookName << endl;
        cout << "Author Name : " << authorName << endl;
        cout << "Publisher : " << publisher << endl;
        cout << "Price : " << price << endl;
    }

    static void addBook();

    static void findAllBook();

    static Book findBookByBookId(int bookId);

    static Book findBookByBookName(string bookName);

    static void updateBookByBookId(int bookId, Book newBook);

    static void updateBookByBookName(string bookName, Book newBook);

    static void deleteBookByBookId(int bookId);

    static void deleteBookByBookName(string bookName);
};

Book bookInstance;

void Book::addBook() {
    fstream file;
    file.open("book_data.txt", ios::app);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }
    bookInstance.getBookData();

    file << bookInstance.id << ' ' << bookInstance.bookName << ' ' << bookInstance.authorName << ' '
         << bookInstance.publisher << ' ' << bookInstance.price << ' ' << '\n';
    userInstance.showData();
    file.close();

}

void Book::findAllBook() {
    fstream file;
    file.open("book_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;
        bookInstance.showData();
    }

    file.close();
}

Book Book::findBookByBookId(int bookId) {
    fstream file;
    file.open("book_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isBookFound = 0;

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookId == bookInstance.id) {
            isBookFound = 1;
            break;
        }
    }

    if (isBookFound == 0) {
        cout << "Book not found!" << endl;
    } else {
        cout << "Book found with book id : " << bookInstance.id << endl;
        bookInstance.showData();
    }
    file.close();
    return bookInstance;
}

Book Book::findBookByBookName(string bookName) {
    fstream file;
    file.open("book_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isBookFound = 0;

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookName == bookInstance.bookName) {
            isBookFound = 1;
            break;
        }
    }

    if (isBookFound == 0) {
        cout << "Book not found!" << endl;
    } else {
        cout << "Book found with book name : " << bookInstance.id << endl;
        bookInstance.showData();
    }
    file.close();
    return bookInstance;
}

void Book::updateBookByBookId(int bookId, Book newBook) {
    fstream file, tmpFile;
    file.open("book_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookId == bookInstance.id) {
            file << newBook.id << ' ' << newBook.bookName << ' ' << newBook.authorName << ' '
                 << newBook.publisher << ' ' << newBook.price << ' ' << '\n';
        } else {
            tmpFile << bookInstance.id << ' ' << bookInstance.bookName << ' ' << bookInstance.authorName << ' '
                    << bookInstance.publisher << ' ' << bookInstance.price << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("book_data.txt");
    rename("temp.txt", "book_data.txt");
}

void Book::updateBookByBookName(string bookName, Book newBook) {
    fstream file, tmpFile;
    file.open("book_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }
    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookName == bookInstance.bookName) {
            file << newBook.id << ' ' << newBook.bookName << ' ' << newBook.authorName << ' '
                 << newBook.publisher << ' ' << newBook.price << ' ' << '\n';
        } else {
            tmpFile << bookInstance.id << ' ' << bookInstance.bookName << ' ' << bookInstance.authorName << ' '
                    << bookInstance.publisher << ' ' << bookInstance.price << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("book_data.txt");
    rename("temp.txt", "book_data.txt");
}

void Book::deleteBookByBookId(int bookId) {
    fstream file, tmpFile;
    file.open("book_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookId == bookInstance.id) {
            cout << "Deleted book : " << bookInstance.id << endl;
        } else {
            tmpFile << bookInstance.id << ' ' << bookInstance.bookName << ' ' << bookInstance.authorName << ' '
                    << bookInstance.publisher << ' ' << bookInstance.price << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("book_data.txt");
    rename("temp.txt", "book_data.txt");
}

void Book::deleteBookByBookName(string bookName) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

    while (!file.eof()) {
        file >> bookInstance.id >> bookInstance.bookName >> bookInstance.authorName
             >> bookInstance.publisher >> bookInstance.price;

        if (bookName == bookInstance.bookName) {
            cout << "Deleted book : " << bookInstance.bookName << endl;
        } else {
            tmpFile << bookInstance.id << ' ' << bookInstance.bookName << ' ' << bookInstance.authorName << ' '
                    << bookInstance.publisher << ' ' << bookInstance.price << ' ' << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("book_data.txt");
    rename("temp.txt", "book_data.txt");
}

class BookStore {
public:
    int mainMenu();

    int adminSubMenu();

    int userUsbMenu();
};

BookStore bookStoreInstance;

int BookStore::mainMenu() {
    int option = 0;
    int userId;
    do {
        cout << endl;
        cout << "****************************************************" << endl;
        cout << "Main Menu" << endl;
        cout << "****************************************************" << endl << endl;
        cout << "1. Register;" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cin >> option;
        switch (option) {
            case 1:
                User::registration();
                break;
            case 2:
                userId = userInstance.login();
                if (userId > 0) {
                    User user = userInstance.findUserByUserId(userId);
                    if (user.getUserName() == "admin") {
                        adminSubMenu();
                    } else {
                        userUsbMenu();
                    }
                }
                break;
            case 3:
                cout << "Bye Bye" << endl;
                break;
            default:
                return 0;
        }
    } while (option != 3);
    return 0;
}

int BookStore::adminSubMenu() {
    int option;
    string userName;
    int userId;
    string bookName;
    int bookId;

    do {
        cout << endl;
        cout << "****************************************************" << endl;
        cout << "Admin Menu" << endl;
        cout << "****************************************************" << endl << endl;
        cout << "1. Add user" << endl;
        cout << "2. Find all user" << endl;
        cout << "3. Find user by user id" << endl;
        cout << "4. Find user by user name" << endl;
        cout << "5. Update user by user id" << endl;
        cout << "6. Update user by user name" << endl;
        cout << "7. Delete user by user id" << endl;
        cout << "8. Delete user by user name" << endl;
        cout << "9. Add book" << endl;
        cout << "10. Find all book" << endl;
        cout << "11. Find book book id" << endl;
        cout << "12. Find book book name" << endl;
        cout << "13. Update book by book id" << endl;
        cout << "14. Update book by book name" << endl;
        cout << "15. Delete book by book id" << endl;
        cout << "16. Delete book by book name" << endl;
        cout << "17. Exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                User::registration();
                break;
            case 2:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find All Users" << endl;
                cout << "****************************************************" << endl << endl;
                User::findAllUser();
                break;
            case 3:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find User By User Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user id : ";
                cin >> userId;
                User::findUserByUserId(userId);
                break;
            case 4:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find User By User Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user name : ";
                cin >> userName;
                User::findUserByUserName(userName);
                break;
            case 5:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Update User By User Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user id : ";
                cin >> userId;
                cout << "Current user data : " << endl;
                userInstance.findUserByUserId(userId);
                cout << endl;
                cout << "Please enter modify data : " << endl;
                userInstance.getUserData();
                User::updateUserByUserId(userId, userInstance);
                break;
            case 6:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Update User By User Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user name : ";
                cin >> userName;
                cout << "Current user data : " << endl;
                userInstance.findUserByUserName(userName);
                cout << endl;
                cout << "Please enter modify data : " << endl;
                userInstance.getUserData();
                User::updateUserByUserName(userName, userInstance);
                break;
            case 7:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Delete User By User Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user id : ";
                cin >> userId;
                User::deleteUserByUserId(userId);
                break;
            case 8:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Delete User By User Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a user name : ";
                cin >> userName;
                User::deleteUserByUserName(userName);
                break;
            case 9:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Add New Book" << endl;
                cout << "****************************************************" << endl << endl;
                Book::addBook();
                break;
            case 10:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find All Book" << endl;
                cout << "****************************************************" << endl << endl;
                Book::findAllBook();
                break;
            case 11:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find Book By Book Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book id : ";
                cin >> userId;
                Book::findBookByBookId(bookId);
                break;
            case 12:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find Book By Book Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book name : ";
                cin >> bookName;
                Book::findBookByBookName(bookName);
                break;
            case 13:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Update Book By Book Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book id : ";
                cin >> bookId;
                cout << "Current book data : " << endl;
                bookInstance.findBookByBookId(bookId);
                cout << endl;
                cout << "Please modify data : " << endl;
                bookInstance.getBookData();
                Book::updateBookByBookId(bookId, bookInstance);
                break;
            case 14:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Find Book By Book Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book name : ";
                cin >> userName;
                cout << "Current book data : " << endl;
                bookInstance.findBookByBookName(bookName);
                cout << endl;
                cout << "Please modify data : " << endl;
                bookInstance.getBookData();
                Book::updateBookByBookName(bookName, bookInstance);
                break;
            case 15:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Delete Book By Book Id" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book id : ";
                cin >> bookId;
                Book::deleteBookByBookId(bookId);
                break;
            case 16:
                cout << endl;
                cout << "****************************************************" << endl;
                cout << "Delete Book By Book Name" << endl;
                cout << "****************************************************" << endl << endl;
                cout << "Enter a book name : ";
                cin >> bookName;
                Book::deleteBookByBookName(bookName);
                break;
            case 17:
                return 0;
        }
    } while (isExit() != 'y');
    return 0;
}

int BookStore::userUsbMenu() {
    cout << "user sub menu" << endl;
    return 0;
}

int main() {
    bookStoreInstance.mainMenu();
    return 0;
}