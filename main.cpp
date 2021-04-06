/*
 1) Реализуйте функцию strCpy() (копирует один массив посимвольно в другой)
 2) Реализуйте функцию strCat() (конкатенирует(т.е. соединяет 2 массива в один))
 3) Реализуйте функцию strCmp() (сравнивает одну строку с другой, т.е. "Minsk" и "minsk" и функция сравнения)
 4) Реализовать isSeparator() - функция, которая определяет, является ли символ знаком пунктуации
 */
#include <iostream>
using namespace std;

#define TEXT_SIZE_1 15
#define TEXT_SIZE_2 20
#define TEXT_SIZE_3 20
#define SIMBOL_SIZE_4 9
#define SIZE1 11
#define SIZE2 6

void strCpy(char word1[], char word2[]);
int strCmp(char word1[], char word2[]);
void strCat(char word1[], char word2[]);
int strLen(char text[]);
int isSeparator(char text1[], char simbol[]);
void printOnConsole(string massage);
void printOnConsole(string massage, char parametr);

int main()
{
    char text1[TEXT_SIZE_1] = "Hello world";
    char text2[TEXT_SIZE_2] = "";
    char text3[TEXT_SIZE_3] = "Hello world";
    char word1[SIZE1] = "Hello\0", word2[SIZE2] = "world";
    char simbol[SIMBOL_SIZE_4] = {'.', ',', '!', '?', ';', ':', '-', ' '};
    
    // task_1
    printOnConsole("1. Overwrite array: ");
    strCpy(text1, text2);
    cout << text2 << endl;
    
    // task_2
    cout << "2. First word is " << word1 << endl;
    cout << "Second word is " << word2<< endl;
    strCat(word1, word2);
    cout << "Modified word1 is " << word1 << endl;
    
    // task_3
    strCmp(text1, text3);
    if(strCmp(text1, text3) == true) {
        printOnConsole("3. Arrays are equal (true = 1): ");
        cout << strCmp(text1, text3) << endl;
    } else {
        printOnConsole("3. Arrays aren't equal (false = 0): ");
        cout << strCmp(text1, text3) << endl;
    }
    
    // task_4
    isSeparator(text1, simbol);
    if(isSeparator(text1, simbol) == true) {
        printOnConsole("4. There are punctuation marks (true = 1): ");
        cout << isSeparator(text1, simbol) << endl;
    } else {
        printOnConsole("4. There aren't punctuation marks (false = 0): ");
        cout << isSeparator(text1, simbol) << endl;
    }
    return 0;
}

// 1.
void strCpy(char word1[], char word2[]) {
    for(int i = 0; i < TEXT_SIZE_1; i++) {
        word2[i] = word1[i];
    }
}

// 2.1
int strLen(char text[]){
    int length = 0;
    while(text[length] != '\0'){
        length++;
    }
    return length;
}

// 2.2
void strCat(char word1[], char word2[]){
    int startIndex = strLen(word1), i = 0;
    cout << "startIndex is " <<startIndex << endl;
    while(word2[i] != '\0'){
        word1[startIndex] = word2[i];
        startIndex++;
        i++;
    }
}

// 3.
int strCmp(char word1[], char word3[]){
    if(strLen(word1) != strLen(word3)) {
        return false;
    } else {
        for(int i = 0; i < TEXT_SIZE_1; i++) {
            if(word1[i] != word3[i]) {
                return false;
            }
        }
    }
    return true;
}

// 4.
int isSeparator(char text1[], char simbol[]) {
    int count = 0;
    for(int i = 0; i < SIMBOL_SIZE_4; i++) {
        for(int j = 0; j < TEXT_SIZE_1; j++) {
            if(simbol[i] == text1[j] and simbol[i] != '\0') {
                count++;
                return true;
            }
        }
    }
    return false;
}

// 5.
void printOnConsole(string massage) {
    cout << massage;
}
// 6.
void printOnConsole(string massage, char parametr) {
    cout << massage << parametr;
}

