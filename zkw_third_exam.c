//
// Created by Zin Ko Winn on 9/4/2022.
//

#include <stdio.h>

#define MAX_SIZE 100

int *mergeTwoArray(int *firstArray, int firsArrSize, int *secondArray, int secondArrSize);

void replace(int *source, int index, int newValue);

void copyOf(int *destination, int *source, int size);

void swapArray(int *source, int *destination, int size);

void insertIntoArray(int *arr, int size);

void printResult(int *arr, int size);

void doOperation();

void arrayCopyTest();

void swappingArrayTest();

void replaceElementTest();

void mergeTwoArrayTest();

int main() {
    doOperation();
    return 0;
}

void doOperation() {
    int choose = 0;
    do {
        printf("\n");
        printf("Please choose\n");
        printf("1. Merge Two Array\n");
        printf("2. Replace Element\n");
        printf("3. Array Copy\n");
        printf("4. Array Swapping\n");
        printf("5. Exit\n");
        scanf("%d", &choose);


        switch (choose) {
            case 1:
                mergeTwoArrayTest();
            case 2:
                replaceElementTest();
                break;
            case 3:
                arrayCopyTest();
                break;
            case 4:
                swappingArrayTest();
                break;
        }
    } while (choose != 5);
}

void mergeTwoArrayTest() {
    int firstArraySize = 0;
    int secondArraySize = 0;
    int firstArray[MAX_SIZE];
    int secondArray[MAX_SIZE];
    int *firstArrPtr;
    int *secondArrPtr;
    int *mergedArray;

    printf("Enter size of first array : ");
    scanf("%d", &firstArraySize);

    printf("Enter %d elements in first array: ", firstArraySize);
    insertIntoArray(firstArray, firstArraySize);
    firstArrPtr = &firstArray;

    printf("Enter size of second array : ");
    scanf("%d", &secondArraySize);

    printf("Enter %d elements in second array: ", secondArraySize);
    insertIntoArray(secondArray, secondArraySize);
    secondArrPtr = &secondArray;

    mergedArray = mergeTwoArray(firstArrPtr, firstArraySize, secondArrPtr, secondArraySize);

    printf("The value of merged array are : ");
    printResult(mergedArray, firstArraySize + secondArraySize);
}

void replaceElementTest() {
    int size = 0;
    int index = 0;
    int replaceValue = 0;
    int sourceArr[MAX_SIZE];
    int *sourceArrptr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements in source array: ", size);
    insertIntoArray(sourceArr, size);
    sourceArrptr = &sourceArr;

    do {
        printf("Enter position of array which you want to replace : ");
        scanf("%d", &index);
        if (index > size - 1 || index < 0) {
            printf("Invalid element position. Please try again!\n");
        }
    } while (index > size - 1 || index < 0);

    printf("Enter value of array which you want to replace : ");
    scanf("%d", &replaceValue);

    printf("Before Replace Value : ");
    printResult(sourceArrptr, size);

    replace(sourceArrptr, index, replaceValue);

    printf("After Replace Value : ");
    printResult(sourceArrptr, size);

}

void arrayCopyTest() {
    int size = 0;
    int sourceArr[MAX_SIZE];
    int destArr[MAX_SIZE];
    int *sourceArrPtr;
    int *destArrPtr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements in source array: ", size);
    insertIntoArray(sourceArr, size);
    sourceArrPtr = &sourceArr;

    printf("The value of source array are : ");
    printResult(sourceArrPtr, size);
    destArrPtr = destArr;

    printf("The value of destination array are (before copy) : ");
    printResult(destArrPtr, size);

    copyOf(destArrPtr, sourceArrPtr, size);
    printf("The value of destination array are (after copy) : ");
    printResult(destArrPtr, size);
}

void swappingArrayTest() {
    int size = 0;
    int sourceArr[MAX_SIZE];
    int destArr[MAX_SIZE];
    int *sourceArrPtr;
    int *destArrPtr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter %d elements in source array: ", size);
    insertIntoArray(sourceArr, size);
    sourceArrPtr = &sourceArr;

    printf("Enter %d elements in destination array: ", size);
    insertIntoArray(destArr, size);
    destArrPtr = &destArr;

    printf("Source Array Before Swapping : \n");
    printResult(sourceArrPtr, size);

    printf("Destination Array Before Swapping : \n");
    printResult(destArrPtr, size);

    swapArray(sourceArrPtr, destArrPtr, size);

    printf("Source Array After Swapping : \n");
    printResult(sourceArrPtr, size);

    printf("Destination  Array After Swapping : \n");
    printResult(destArrPtr, size);
}

int *mergeTwoArray(int *firstArray, int firsArrSize, int *secondArray, int secondArrSize) {
    int mergedArray[MAX_SIZE];
    int *mergeArrPtr;

    for (int i = 0; i < firsArrSize; i++) {
        mergedArray[i] = firstArray[i];
    }

    for (int i = 0; i < secondArrSize; i++) {
        mergedArray[i + firsArrSize] = secondArray[i];
    }

    mergeArrPtr = mergedArray;
    return mergeArrPtr;
}

void replace(int *source, int index, int newValue) {
    source[index] = newValue;
}

void copyOf(int *destination, int *source, int size) {
    int *lastSourceValue = (source + (size - 1));
    while (source <= lastSourceValue) {
        *destination = *source;
        destination++;
        source++;
    }
}

void swapArray(int *source, int *destination, int size) {
    int *sourceArrEnd = (source + (size - 1));
    int *destArrEnd = (destination + (size - 1));
    int *temp;
    while (source <= sourceArrEnd && destination <= destArrEnd) {
        temp = *destination;
        *destination = *source;
        *source = temp;
        source++;
        destination++;
    }
}

void insertIntoArray(int *arr, int size) {
    int *arrEnd = (arr + (size - 1));

    while (arr <= arrEnd) {
        scanf("%d", arr++);
    }
}

void printResult(int *arr, int size) {
    int *lastArrayValue = (arr + (size - 1));
    while (arr <= lastArrayValue) {
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
}
