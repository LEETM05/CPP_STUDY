#include <string.h>

#include <cstdlib>
#include <iostream>

using namespace std;

class MyString {
    char *string_content;
    int string_length;

    int memory_capacity;

   public:
    MyString(char c);
    MyString(const char *str);
    MyString(const MyString &str);

    ~MyString();
    int length() const;
    int capacity() const;
    void reserve(int size);
    char at(int i) const;

    bool operator==(MyString &str);

    void print() const;
    void println() const;

    int compare(MyString &str);
    char &operator[](const int index) { return string_content[index]; }
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char *str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
}

MyString::MyString(const MyString &str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void MyString::print() const {
    for (int i = 0; i != string_length; i++) cout << string_content[i];
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++) cout << string_content[i];
    cout << "\n";
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != string_length; i++) string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
}

char MyString::at(int i) const {
    if (i >= string_length || i < 0)
        return 0;
    else
        return string_content[i];
}

bool MyString::operator==(MyString &str) { return !compare(str); }

int MyString::compare(MyString &str) {
    for (int i = 0; i < min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }
    if (string_length == str.string_length)
        return 0;
    else if (string_length > str.string_length)
        return 1;
    return -1;
}

int main() {
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3("sentence");

    if (str1 == str2)
        cout << "str1 와 str2 같다.\n";
    else
        cout << "str1 와 str2 는 다르다.\n";
    if (str2 == str3)
        cout << "str2 와 str3 는 같다.\n";
    else
        cout << "str2 와 str3 는 다르다.\n";
}