#include "function.h"
std::vector<MyString> MyString::list;
void* MyString::operator new(size_t size) {
    std::cout << "Выделение памяти с помощью оператора new\n";
    void* p = ::operator new(size);

    // Добавление новой строки в список
    MyString* newString = static_cast<MyString*>(p);
    std::cout << "Введите строку: ";
    std::cin >> *newString;

    list.push_back(*newString);

    return p;
}

void MyString::operator delete(void* p) {
    std::cout << "Освобождение памяти с помощью оператора delete\n";

    // Удаление последней строки из списка
    if (!list.empty()) {
        delete[] list.back().string;
        list.pop_back();
    }

    ::operator delete(p);
}

std::istream& operator>>(std::istream& is, MyString& myString) {
    std::string input;
    std::getline(is, input);
    myString.size_string = input.size();
    myString.string = new char[input.size() + 1];
    std::copy(input.begin(), input.end(), myString.string);
    myString.string[input.size()] = '\0';
    return is;
}

std::ostream& operator<<(std::ostream& os, const std::vector<MyString>& list) {
    for (int i = 0; i < list.size(); ++i) {
        os << "Строка " << (i + 1) << ": " << list[i].string << "  Размер:" << list[i].size_string << "\n";
    }
    return os;
}

MyString MyString::operator+(const MyString& other) {
    MyString result;
    result.size_string = this->size_string + other.size_string + 1;
    result.string = new char[result.size_string + 1];
    std::copy(this->string, this->string + this->size_string, result.string);
    result.string[this->size_string] = ' ';
    std::copy(other.string, other.string + other.size_string, result.string + this->size_string + 1);
    result.string[result.size_string] = '\0';
    return result;
}

MyString& MyString::operator+=(const MyString& other) {
    char* new_string = new char[this->size_string + other.size_string + 2];
    std::copy(this->string, this->string + this->size_string, new_string);
    new_string[this->size_string] = ' ';
    std::copy(other.string, other.string + other.size_string, new_string + this->size_string + 1);
    new_string[this->size_string + other.size_string + 1] = '\0';
    delete[] this->string;
    this->string = new_string;
    this->size_string += other.size_string + 1;
    return *this;
}

MyString MyString::operator-(const MyString& other) {
    std::string strA(this->string);
    std::string strB(other.string);
    size_t pos = 0;
    while ((pos = strA.find(strB, pos)) != std::string::npos) {
        strA.erase(pos, strB.length());
    }
    // Удаление двойных пробелов
    while ((pos = strA.find("  ")) != std::string::npos) {
        strA.erase(pos, 1);
    }
    MyString result;
    result.size_string = strA.size();
    result.string = new char[result.size_string + 1];
    std::copy(strA.begin(), strA.end(), result.string);
    result.string[result.size_string] = '\0';
    return result;
}

MyString& MyString::operator-=(const MyString& other) {
    std::string strA(this->string);
    std::string strB(other.string);
    size_t pos = 0;
    while ((pos = strA.find(strB, pos)) != std::string::npos) {
        strA.erase(pos, strB.length());
    }
    // Удаление двойных пробелов
    while ((pos = strA.find("  ")) != std::string::npos) {
        strA.erase(pos, 1);
    }
    delete[] this->string;
    this->size_string = strA.size();
    this->string = new char[this->size_string + 1];
    std::copy(strA.begin(), strA.end(), this->string);
    this->string[this->size_string] = '\0';
    return *this;
}

MyString MyString::operator*(int n) {
    std::string strA(this->string);
    std::string resultStr = "";
    for (int i = 0; i < n; ++i) {
        resultStr += strA;
        if (i < n - 1) {
            resultStr += " ";
        }
    }
    MyString result;
    result.size_string = resultStr.size();
    result.string = new char[result.size_string + 1];
    std::copy(resultStr.begin(), resultStr.end(), result.string);
    result.string[result.size_string] = '\0';
    return result;
}

MyString& MyString::operator*=(int n) {
    std::string strA(this->string);
    std::string resultStr = "";
    for (int i = 0; i < n; ++i) {
        resultStr += strA;
        if (i < n - 1) {
            resultStr += " ";
        }
    }
    delete[] this->string;
    this->size_string = resultStr.size();
    this->string = new char[this->size_string + 1];
    std::copy(resultStr.begin(), resultStr.end(), this->string);
    this->string[this->size_string] = '\0';
    return *this;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // защита от самоприсваивания
        delete[] this->string;
        this->size_string = other.size_string;
        this->string = new char[this->size_string + 1];
        std::copy(other.string, other.string + other.size_string, this->string);
        this->string[this->size_string] = '\0';
    }
    return *this;
}

bool MyString::operator==(const MyString& other) const {
    return std::strcmp(this->string, other.string) == 0;
}

bool MyString::operator>(const MyString& other) const {
    return this->size_string > other.size_string;
}

bool MyString::operator<(const MyString& other) const {
    return this->size_string < other.size_string;
}

