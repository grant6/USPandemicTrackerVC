//
// Created by grant on 7/11/2020.
//

#include "date.h"
#include <iostream>

/*******************************************************************
 * returns number of days in any given month
 * @param monthNum
 * @param year
 * @return
 */
int numDaysInMonth(int monthNum, int year) {
    if (monthNum == 2) {
        //Leap Year Algorithm is from:
        //https://www.geeksforgeeks.org/print-calendar-for-a-given-year/
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
            return (29);
        }
        else {
            return (28);
        }
    }
    else if (monthNum <= 7) {
        if (monthNum % 2 != 0) {
            return 31;
        }
        else {
            return 30;
        }
    }
    else if (monthNum >= 8) {
        if (monthNum % 2 != 0) {
            return 30;
        }
        else {
            return 31;
        }
    }
    exit(1);
}

/*******************************************************************
 * This method returns a string month when given the number
 * @param month
 * @return
 */
std::string getMonth(int month) {
    std::string months[] = { "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November",
        "December" };
    return months[month - 1];
}

/*******************************************************************
 * This method returns a string version of a date x # of days after
 * the beginning date
 * @param startDay
 * @param startMonth
 * @param startYear
 * @param numDays
 * @return
 */
std::string getDate(int startDay, int startMonth, int startYear, int numDays) {
    int month = startMonth;
    int year = startYear;
    int totalDays = numDaysInMonth(month, startYear) - startDay;
    while (numDays > totalDays) {
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
        totalDays += numDaysInMonth(month, year);
    }
    int leftInMonth = numDaysInMonth(month, year) - (totalDays - numDays);
    return (getMonth(month) + " " + std::to_string(leftInMonth) + ", " + std::to_string(year));
}
