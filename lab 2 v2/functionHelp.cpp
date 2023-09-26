#include "function.h"
#include "functionHelp.h"

void printList() {
    std::cout << "------------------------------\n";
    if (MyString::list.size() == 0)
    {
        std::cout << "Список пуст!\n";
        std::cout << "------------------------------\n";
        return;
    }
    std::cout << MyString::list;
    std::cout << "------------------------------\n";
}

void deleteStringByIndex() {
    int index;
    std::cout << "Введите индекс строки для удаления: ";
    std::cin >> index;

    // Переводим индексацию в стиле пользователя (начиная с 1) в индексацию в стиле C++ (начиная с 0)
    index--;

    if (index < 0 || index >= MyString::list.size()) {
        std::cout << "Неверный индекс.\n";
        return;
    }

    // Удаляем строку из списка
    MyString::list.erase(MyString::list.begin() + index);
}
// delete last string
void deleteLastString() {
    if (!MyString::list.empty()) {
        delete[] MyString::list.back().string; // освобождаем память, выделенную под строку
        MyString::list.pop_back(); // удаляем элемент из списка
    }
}
//+
void peregruzkaPlus() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    MyString newString = MyString::list[indexA - 1] + MyString::list[indexB - 1];
    MyString::list.push_back(newString);
}
//+=
void peregruzkaPlusEquals() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    MyString::list[indexA - 1] += MyString::list[indexB - 1];
}
//-
void peregruzkaMinus() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    MyString newString = MyString::list[indexA - 1] - MyString::list[indexB - 1];
    MyString::list.push_back(newString);
}
//-=
void peregruzkaMinusEquals() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    MyString::list[indexA - 1] -= MyString::list[indexB - 1];
}
//*
void overloadMultiply() {
    int indexA, n;
    std::cout << "Введите индекс строки: ";
    std::cin >> indexA;
    std::cout << "Введите число: ";
    std::cin >> n;
    MyString newString = MyString::list[indexA - 1] * n;
    MyString::list.push_back(newString);
}
//*=
void overloadMultiplyExactly() {
    int indexA, n;
    std::cout << "Введите индекс строки: ";
    std::cin >> indexA;
    std::cout << "Введите число: ";
    std::cin >> n;
    MyString::list[indexA - 1] *= n;
}
// =
void assignmentOperatorOverload() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    MyString::list[indexA - 1] = MyString::list[indexB - 1];
}
//==
void overloadingTheEqualityOperator() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    system("cls");
    if (MyString::list[indexA - 1] == MyString::list[indexB - 1]) {
        std::cout << "Строки " << MyString::list[indexA - 1].string << " и " << MyString::list[indexB - 1].string << " равны\n";
    }
    else {
        std::cout << "Строки " << MyString::list[indexA - 1].string << " и " << MyString::list[indexB - 1].string << " не равны\n";
    }
}
//>
void operatorOverloadIsGreater() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    system("cls");
    if (MyString::list[indexA - 1] > MyString::list[indexB - 1]) {
        std::cout << "Cтрока " << MyString::list[indexA - 1].string << " больше строки " << MyString::list[indexB - 1].string << "\n";
    }
    else {
        std::cout << "Cтрока " << MyString::list[indexA - 1].string << " не больше строки " << MyString::list[indexB - 1].string << "\n";
    }
}
//<
void LessOperatorOverload() {
    int indexA, indexB;
    std::cout << "Введите индекс первой строки: ";
    std::cin >> indexA;
    std::cout << "Введите индекс второй строки: ";
    std::cin >> indexB;
    system("cls");
    if (MyString::list[indexA - 1] < MyString::list[indexB - 1]) {
        std::cout << "Cтрока " << MyString::list[indexA - 1].string << " меньше строки " << MyString::list[indexB - 1].string << "\n";
    }
    else {
        std::cout << "Cтрока " << MyString::list[indexA - 1].string << " не меньше строки " << MyString::list[indexB - 1].string << "\n";
    }
}

void peregruzSkobki() {
    size_t stringIndex;
    std::cout << "Введите индекс строки: ";
    std::cin >> stringIndex;
    std::cin.ignore();
    stringIndex--;
    size_t charIndex;
    std::cout << "Введите индекс символа: ";
    std::cin >> charIndex;
    std::cin.ignore();
    charIndex--;
    if (stringIndex >= 0 && stringIndex < MyString::list.size()) {
        MyString& selectedString = MyString::list[stringIndex];
        if (charIndex >= 0 && charIndex < selectedString.size_string) {
            char& character = selectedString[charIndex];
            std::cout << "Символ с индексом " << charIndex + 1 << " в строке с индексом " << stringIndex + 1 << ": " << character << std::endl;
        }
        else {
            std::cout << "Ошибка: недопустимый индекс символа!" << std::endl;
        }
    }
    else {
        std::cout << "Ошибка: недопустимый индекс строки!" << std::endl;
    }
}