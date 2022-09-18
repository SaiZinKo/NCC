//
// Created by Zin Ko Winn on 9/18/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

struct User {
    int id;
    char username[100];
    char password[20];
    int amount;
    int age;
    char location[100];
};

int userDataSize = 0;

char isExit();

struct User *readFile();

void insertData();

struct User findData();

void updateData();

void showData(struct User user);

int main() {
    int choose = 0;
    struct User user;
    do {
        printf("1. Insert Data\n");
        printf("2. Find Data\n");
        printf("3. Update Data\n");

        printf("Choose : ");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                insertData();
                break;
            case 2:
                user = findData();
                showData(user);
                break;
            case 3:
                updateData();
                break;
            default:
                printf("Invalid operation\n");
                break;
        }
    } while (isExit() != 'y');
    return 0;
}

void insertData() {
    struct User user;
    FILE *fptr;
    fptr = fopen("userData.txt", "a");

    if (fptr == NULL) {
        printf("File opening error");
        exit(1);
    }

    printf("Please enter user data : \n");
    scanf("%d%s%s%d%d%s", &(user.id), &(user.username), &(user.password), &(user.amount), &(user.age),
          &(user.location));


    fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,
            user.location);
    fclose(fptr);
}


struct User *readFile() {
    FILE *fptr;
    struct User users[MAX_LENGTH];
    struct User *uptr;
    struct User user;

    fptr = fopen("userData.txt", "r");

    if (fptr == NULL) {
        printf("File opening error");
        exit(1);
    }

    while (fscanf(fptr, "%d%s%s%d%d%s", &user.id, &user.username, &user.password, &user.amount, &user.age,
                  &user.location) != EOF) {
        users[userDataSize] = user;
        userDataSize++;
    }
    uptr = users;
    fclose(fptr);
    return uptr;
}

struct User findData() {
    struct User *users = readFile();
    char toFind[100];
    printf("Enter username to find : ");
    scanf("%s", &toFind);
    if (userDataSize > 0) {
        for (int i = 0; i < userDataSize; i++) {
            struct User user = users[i];
            if (strcmp(user.username, toFind) == 0) {
                printf("User Data Found at line number %d\n", i + 1);
                return user;
            }
        }
        printf("Not found %s\n", toFind);
        exit(1);
    } else {
        printf("There is no data");
        exit(1);
    }
}


void updateData() {
    FILE *fptr;
    fptr = fopen("userData.txt", "r+");
    int choose = 0;
    struct User user = findData();
    showData(user);

    printf("Please choose to update data :\n");
    printf("1. Id\n");
    printf("2. User Name\n");
    printf("3. Password\n");
    printf("4. Amount\n");
    printf("5. Age\n");
    printf("6. Location\n");
    scanf("%d", &choose);

    switch (choose) {
        case 1:
            printf("Please enter new id to update : ");
            scanf("%d", &user.id);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        case 2:
            printf("Please enter new user name to update : ");
            scanf("%s", &user.username);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        case 3:
            printf("Please enter new password to update : ");
            scanf("%s", &user.password);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        case 4:
            printf("Please enter new amount to update : ");
            scanf("%d", &user.amount);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        case 5:
            printf("Please enter new age to update : ");
            scanf("%d", &user.age);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        case 6:
            printf("Please enter new location to update : ");
            scanf("%s", &user.location);
            fprintf(fptr, "%d%30s%30s\t%d\t%d%30s\n", user.id, user.username, user.password, user.amount, user.age,user.location);
            fclose(fptr);
            break;
        default:
            printf("Invalid operation");
            exit(1);
    }
}


void showData(struct User user) {
    printf("Id : %d\nUser Name : %s\nPassword : %s\nAmount : %d\nAge : %d\nLocation = %s\n",
           user.id, user.username, user.password, user.amount, user.age, user.location);
}

char isExit() {
    char isExit;
    printf("Do you want to exit? (y/n) : ");
    scanf(" %c", &isExit);
    return isExit;
}