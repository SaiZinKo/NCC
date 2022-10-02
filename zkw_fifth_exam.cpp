//
// Created by Zin Ko Winn on 9/25/2022.
// Reference : https://cplusplus.com/doc/tutorial/files/
//

#include <iostream>
#include <fstream>

using namespace std;

class User {
private:
    int id;
    string userName;
    string password;
    string email;
    string phone;
    int age;
    string location;

public:
    void getUserData() {
        cout << "Enter a Id :";
        cin >> id;
        cout << "Enter a userName :";
        cin >> userName;
        cout << "Enter a password :";
        cin >> password;
        cout << "Enter a email :";
        cin >> email;
        cout << "Enter a phone :";
        cin >> phone;
        cout << "Enter a age :";
        cin >> age;
        cout << "Enter a location :";
        cin >> location;
    }

    void showData() {
        cout << "Id : " << id << endl;
        cout << "UserName : " << userName << endl;
        cout << "Password : " << password << endl;
        cout << "Email : " << email << endl;
        cout << "Phone : " << phone << endl;
        cout << "Age : " << age << endl;
        cout << "Location : " << location << endl;
    }

    static void addUser();

    static void findAllUser();

    static void findUserByUserId(int userId);

    static void findUserByUserName(string userName);

    static void updateUserByUserId(int userId, User newUser);

    static void updateUserByUserName(string userName, User newUser);

    static void deleteUserByUserId(int userId);

    static void deleteUserByUserName(string userName);
};

User userInstance;

void User::addUser() {
    fstream file;
    file.open("user_data.txt", ios::app);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    userInstance.getUserData();

//      For Binary
//    file.write((char *) &userInstance, sizeof(userInstance));

    file << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' ' << userInstance.email
         << ' ' << userInstance.phone << ' ' << userInstance.age << ' ' << userInstance.location << ' ' << '\n';

    cout << "User added successfully" << endl;
    file.close();
}

void User::findAllUser() {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

//  For Binary
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        userInstance.showData();
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;
        userInstance.showData();
    }

    file.close();
}

void User::findUserByUserId(int userId) {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isUserFound = 0;

//    For Binary
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userId == userInstance.id) {
//            isUserFound = 1;
//            break;
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userId == userInstance.id) {
            isUserFound = 1;
            break;
        }
    }

    if (isUserFound == 0) {
        cout << "User not found!" << endl;
    } else {
        cout << "User found" << userInstance.id << endl;
        userInstance.showData();
    }
    file.close();
}

void User::findUserByUserName(string userName) {
    fstream file;
    file.open("user_data.txt", ios::in);

    if (!file.is_open()) {
        printf("File opening error");
        exit(1);
    }

    int isUserFound = 0;

//    For Binary
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userId == userInstance.id) {
//            isUserFound = 1;
//            break;
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userName == userInstance.userName) {
            isUserFound = 1;
            break;
        }
    }

    if (isUserFound == 0) {
        cout << "User not found!" << endl;
    } else {
        cout << "User found" << userInstance.userName << endl;
        userInstance.showData();
    }
    file.close();
}

void User::updateUserByUserId(int userId, User newUser) {
    fstream file, tmpFile;
    file.open("user_data.txt", ios::in);
    tmpFile.open("temp.txt", ios::app);

    if (!file.is_open() || !tmpFile.is_open()) {
        printf("File opening error");
        exit(1);
    }

//    For Binary
//
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userId == userInstance.id) {
//            tmpFile.write((char *) &newUser, sizeof(newUser));
//        } else {
//            tmpFile.write((char *) &userInstance, sizeof(userInstance));
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userId == userInstance.id) {
            tmpFile << newUser.id << ' ' << newUser.userName << ' ' << newUser.password << ' ' << newUser.email
                    << ' ' << newUser.phone << ' ' << newUser.age << ' ' << newUser.location << ' ' << '\n';
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.email
                    << ' ' << userInstance.phone << ' ' << userInstance.age << ' ' << userInstance.location << ' '
                    << '\n';
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

//    For Binary
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userId == userInstance.id) {
//            tmpFile.write((char *) &newUser, sizeof(newUser));
//        } else {
//            tmpFile.write((char *) &userInstance, sizeof(userInstance));
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userName == userInstance.userName) {
            tmpFile << newUser.id << ' ' << newUser.userName << ' ' << newUser.password << ' ' << newUser.email
                    << ' ' << newUser.phone << ' ' << newUser.age << ' ' << newUser.location << ' ' << '\n';
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.email
                    << ' ' << userInstance.phone << ' ' << userInstance.age << ' ' << userInstance.location << ' '
                    << '\n';
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

//    For Binary
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userId == userInstance.id) {
//            cout << "Deleted user : " << userInstance.id << endl;
//        } else {
//            tmpFile.write((char *) &userInstance, sizeof(userInstance));
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userId == userInstance.id) {
            cout << "Deleted user : " << userInstance.id << endl;
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.email
                    << ' ' << userInstance.phone << ' ' << userInstance.age << ' ' << userInstance.location << ' '
                    << '\n';
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

//    For Binary
//
//    file.seekg(0, ios::end);
//    int size = file.tellg() / sizeof(userInstance);
//    file.seekg(0, ios::beg);
//    for (int i = 1; i <= size; i++) {
//        file.read((char *) &userInstance, sizeof(userInstance));
//        if (userName == userInstance.userName) {
//            cout << "Deleted user : " << userInstance.userName << endl;
//        } else {
//            tmpFile.write((char *) &userInstance, sizeof(userInstance));
//        }
//    }

    while (!file.eof()) {
        file >> userInstance.id >> userInstance.userName >> userInstance.password >> userInstance.email
             >> userInstance.phone >> userInstance.age >> userInstance.location;

        if (userName == userInstance.userName) {
            cout << "Deleted user : " << userInstance.userName << endl;
        } else {
            tmpFile << userInstance.id << ' ' << userInstance.userName << ' ' << userInstance.password << ' '
                    << userInstance.email
                    << ' ' << userInstance.phone << ' ' << userInstance.age << ' ' << userInstance.location << ' '
                    << '\n';
        }
    }

    file.close();
    tmpFile.close();
    remove("user_data.txt");
    rename("temp.txt", "user_data.txt");
}

char isExit() {
    char isExit;
    cout << "Do you want to exit? (y/n) : " << endl;
    cin >> isExit;
    return isExit;
}

int main() {
    int choose;
    string userName;
    int userId;
    do {
        cout << "Choose operation" << endl;
        cout << "1. Add user" << endl;
        cout << "2. Find all user" << endl;
        cout << "3. Find user by user id" << endl;
        cout << "4. Find user by user name" << endl;
        cout << "5. Update user by user id" << endl;
        cout << "6. Update user by user name" << endl;
        cout << "7. Delete user by user id" << endl;
        cout << "8. Delete user by user name" << endl;
        cout << "9. Exit" << endl;
        cin >> choose;

        switch (choose) {
            case 1:
                User::addUser();
                break;
            case 2:
                User::findAllUser();
                break;
            case 3:
                cout << "Enter a user id : ";
                cin >> userId;
                User::findUserByUserId(userId);
                break;
            case 4:
                cout << "Enter a user name : ";
                cin >> userName;
                User::findUserByUserName(userName);
                break;
            case 5:
                cout << "Enter a user id : ";
                cin >> userId;
                cout << "Current user data : " << endl;
                userInstance.findUserByUserId(userId);
                cout << "Please modify data : " << endl;
                userInstance.getUserData();
                User::updateUserByUserId(userId, userInstance);
                break;
            case 6:
                cout << "Enter a user name : ";
                cin >> userName;
                cout << "Current user data : " << endl;
                userInstance.findUserByUserId(userId);
                cout << "Please modify data : " << endl;
                userInstance.getUserData();
                User::updateUserByUserName(userName, userInstance);
                break;
            case 7:
                cout << "Enter a user id : ";
                cin >> userId;
                User::deleteUserByUserId(userId);
                break;
            case 8:
                cout << "Enter a user name : ";
                cin >> userName;
                User::deleteUserByUserName(userName);
                break;
            case 9:
                return 0;
        }
    } while (isExit() != 'y');
    return 0;
}
