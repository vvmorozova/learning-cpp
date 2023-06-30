#ifndef EX01_H
#include <iostream>
using namespace std;
// TO DO:
// Fix all the calculations with leap year and add two dates summation
class Date {
private:
    int day;
    int month;
    int year;
    const int leap_year = 1968;
    int isLeapYear(int year) {
        if ((year - leap_year) % 4)
            return (0);
        else
            return (1);
    }
    void    Normalize() {
        while ((day > 29 && month == 2) || (day > 30 && (month == 4 || month == 6 || 
            month == 9 || month == 11)) || (day > 31 && (month == 1 || month == 3 || 
            month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) ){
            month++;
            switch (month) {
                case 3:
                    day -= 29;
                    break;
                case 5:
                case 7:
                case 10:
                case 12:
                    day -= 30;
                    break;
                case 13:
                    month = 1;
                    year++;
                case 2:
                case 4:
                case 6:
                case 8:
                case 9:
                case 11:
                    day -= 31;
                    break;
            }
        }
        while (day < 0) {
            month--;
            switch (month) {
                case 1:
                    day += 29;
                    break;
                case 3:
                case 5:
                case 8:
                case 10:
                    day += 30;
                    break;
                case 0:
                    month == 12;
                    year--;
                case 11:
                case 2:
                case 4:
                case 6:
                case 7:
                case 9:
                    day += 31;
                    break;
            }
        }
        if (year < 1970 || year > 2099){
            day = 1;
            month = 1;
            year = 1970;
        }
    }
public:
    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
        Normalize();
    }
    Date() {
        day = 0;
        month = 0;
        year = 0;
        Normalize();
    }
    int GetDay()  const{
        return (day);
    }
    int GetMonth() const{
        return (month);
    }
    int GetYear() const {
        return (year);
    }
    Date & operator + (int d) {
        day += d;
        Normalize();
        return *this;
    }
    Date & operator - (int d) {
        day -= d;
        Normalize();
        return *this;
    }
    // int operator - (Date a) {
    //     int rez;
    //     int sign = 1;
    //     int ad, am, ay, bd, bm, by;
    
    //     if (year < a.GetYear() || (year == a.GetYear() && month < a.GetMonth()) || 
    //         (year == a.GetYear() && month == a.GetMonth() && day < a.GetDay())) {
    //         sign = -1;
    //         ad = a.GetDay();
    //         am = a.GetMonth();
    //         ay = a.GetMonth();
    //         bd = day;
    //         bm = month;
    //         by = year;
    //     }
    //     else {
    //         bd = a.GetDay();
    //         bm = a.GetMonth();
    //         by = a.GetMonth();
    //         ad = day;
    //         am = month;
    //         ay = year;
    //     }

    //     return rez;
    // }
    
};
#endif