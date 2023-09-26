#include <iostream>
#include <vector>
#include <string>

class MyString {
public:
    int size_string;
    char* string;

    static std::vector<MyString> list;

    friend std::istream& operator>>(std::istream& is, MyString& myString);
    void* operator new(size_t size);
    void operator delete(void* p);
    friend std::ostream& operator<<(std::ostream& os, const std::vector<MyString>& list);
    MyString operator+(const MyString& other);
    MyString& operator+=(const MyString& other);
    MyString operator-(const MyString& other);
    MyString& operator-=(const MyString& other);
    MyString operator*(int n);
    MyString& operator*=(int n);
    MyString& operator=(const MyString& other);
    bool operator==(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator<(const MyString& other) const;

    char& operator[](size_t index) {
        if (index >= 0 && index < size_string) {
            return string[index];
        }
        else {
            throw std::out_of_range("Индекс вне диапазона");
        }
    }
};
