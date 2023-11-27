#include <iostream>

using namespace std;

class Date {
    int year;
    int month;
    int day;
    int MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   public:
    Date(int year, int month, int date) : year(year), month(month), day(date) {}
    Date() {}
    void SetDate(int year, int month, int date) {
        this->year = year;
        this->month = month;
        this->day = date;
    }
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);
    void ShowDate();
    bool isLeapYear();
};

void Date::AddDay(int inc) {
    if (inc < 0) return;
    inc += this->day;
    while (inc > MONTH[month - 1]) {  // index를 맞추기 위해서 -1 을 한다.
        if (isLeapYear())
            MONTH[1] = 29;
        else
            MONTH[1] = 28;
        inc -= MONTH[month - 1];  // 여기서 막힘 다시 한 번 풀어봐
        AddMonth(1);
    }
    day = --inc;
}

void Date::ShowDate() { cout << year << "년 " << month << "월 " << day << "일입니다.\n"; }

void Date::AddMonth(int inc) {
    if (inc < 0) return;
    month += inc;
    if (month > 12) {
        AddYear(month / 12);
        month %= 12;
    }
}

void Date::AddYear(int inc) {
    if (inc < 0) return;
    year += inc;
}

bool Date::isLeapYear() {
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) return true;
    return false;
}

int main() {
    Date day(2001, 5, 20);
    day.AddDay(9999);
    day.ShowDate();
}