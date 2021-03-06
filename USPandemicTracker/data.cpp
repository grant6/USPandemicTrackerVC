//
// Created by mzig0203 on 7/9/2020.
//

//Temporary
#include <iostream>
#include <fstream>
#include <string>

#include "data.h"
#include "state.h"


/*******************************************************************
 * Will read a file and return the array of numbers under a certain
 * state
 * @param filename name of file to read
 * @param state name of state to search for
 * @return array list of data
 ******************************************************************/
int* fileRead(std::string filename, std::string stateName) {

    std::ifstream myFile(filename);
    std::string line;
    bool timeToRead = false;
    int* array;
    array = (int*)malloc(250 * sizeof(int));
    int i = 0;

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (!timeToRead) {
                for (auto& c : line) c = toupper(c);   //input to upper case
            }
            if (timeToRead) {
                if (line.empty()) { break; }
                array[i] = stoi(line);
                i++;
            }
            else if (stateName == line) {
                timeToRead = true;
            }
        }
        myFile.close();
    }
    else {
        exit(1);
    }
    return array;
}

/*******************************************************************
 * This method returns the average of an array
 * param a pointer to first element in array
 * param size number of elements in array
 * return the average of the array
 * @param a
 * @param size
 * @param numDays
 * @return sum/size
 ******************************************************************/
double arrayAvg(int* a, int size, int* numDays) {
    int sum = 0;
    bool numDaysSet = false;
    for (int i = 0; i != size; ++i) {
        sum += *(a + i);            //add all values
        *numDays = i;
        numDaysSet = true;
    }
    if (!numDaysSet) {
        *numDays = 0;
    }
    return (double)sum / size;       //divide sum by # of values
}

/*******************************************************************
 * This method finds the max value in an array.
 * @param a
 * @param size
 * @param numDays
 * @return max
 *******************************************************************/
int arrayMaxVal(int* a, int size, int* numDays) {
    int max = *a;
    bool numDaysSet = false;
    for (int i = 0; i != size; ++i) {
        if (*(a + i) > max) {
            *numDays = i;
            max = *(a + i);
            numDaysSet = true;
        }
    }
    if (!numDaysSet) {
        *numDays = 0;
    }
    return max;
}

/*******************************************************************
 * This method finds the max value in an array.
 * @param a
 * @param size
 * @param numDays
 * @return min
 *******************************************************************/
int arrayMinVal(int* a, int size, int* numDays) {
    bool numDaysSet = false;
    int min = *a;
    for (int i = 0; i != size; ++i) {
        if (*(a + i) < min) {
            min = *(a + i);
            *numDays = i;
            numDaysSet = true;
        }
    }
    if (!numDaysSet) {
        *numDays = 0;
    }
    return min;
}

/*******************************************************************
 * this method finds the number of days worth of data available.
 * @param filename
 * @param stateName
 * @return i
 *******************************************************************/
int findNumDays(std::string filename, std::string stateName) {
    std::ifstream myFile(filename);
    std::string line;
    bool timeToRead = false;
    int i = 0;

    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (!timeToRead) {
                for (auto& c : line) c = toupper(c);   //input to upper case
            }
            if (timeToRead) {
                if (line.empty()) { break; }
                i++;
            }
            else if (stateName == line) {
                timeToRead = true;
            }
        }
        myFile.close();
    }
    else {
        exit(1);
    }
    return i;
}

/*******************************************************************
 * This method calculates the total cases in a given state.
 * @param a
 * @param size
 * @return totalCases
 *******************************************************************/
int calcTotalCases(int* a, int size) {

    int totalCases{};
    int i = 0;
    while (size != i ) {
        if (i == 0)  totalCases = *a;
        else         totalCases = totalCases + *(a + i);
        i++;
    }
    return totalCases;
}

/*******************************************************************
 * This method calculates the total cases day by day in a given state.
 * @param a
 * @param size
 * @return totalCasesArray
 *******************************************************************/
int* calcTotalCasesByDay(int* a, int size) {

    static int totalCasesArray[MAX];
    int i = 0;
    while (size != i) {
        if (i == 0) totalCasesArray[i] = *a;
        else        totalCasesArray[i] = totalCasesArray[i - 1] + *a;

        a++; i++;
    }

    return totalCasesArray;
}

/*******************************************************************
 * This method calculates the total deaths in a given state and then
 * prints those day-by-day cases to a text file.
 * @param a
 * @param size
 * @return totalDeaths
 *******************************************************************/
int calcTotalDeaths(int* a, int size) {

    int totalDeaths{};
    int i = 0;
    while (size != i) {
        if (i == 0)  totalDeaths = *a;
        else        totalDeaths = totalDeaths + *(a + i);
        i++;
    }
    return totalDeaths;
}

/*******************************************************************
 * This method calculates the total deaths day by day in a given state
 * and then prints those day-by-day deaths to a text file.
 * @param a
 * @param size
 * @return totalDeathsArray
 *******************************************************************/
int* calcTotalDeathsByDay(int* a, int size) {

    static int totalDeathsArray[MAX];
    int i = 0;
    while (size != i) {
        if (i == 0) totalDeathsArray[i] = *a;
        else       totalDeathsArray[i] = totalDeathsArray[i - 1] + *a;

        a++; i++;
    }

    return totalDeathsArray;
}

/*******************************************************************
 * This method calculates the active cases in a given state, and then
 * prints those day-by-day active cases to a text file.
 * @param a
 * @param b
 * @param size
 * @return activeCasesArray
 *******************************************************************/
int* calcActiveCasesByDay(int* a, int* b, int size) {

    // a daily cases
    // b daily deaths

    int i = 0;
    int j = 0;
    int k = 0;

    int difference[MAX];
    static int activeCasesArray[MAX];

    while (k != size) {
        difference[k] = (*a) - (*b);
        activeCasesArray[k] = 0;
        a++; b++; k++;
    }

    while (size != i) {
        if (i == 0) activeCasesArray[i] = difference[i];
        if (i < 30) {
            while (j < i) {
                activeCasesArray[i] += difference[i];
                j++;
            }
            j = 0;
        }

        else {
            while (j < 30) {
                activeCasesArray[i] += difference[i + j - 30];
                j++;
            }
            j = 0;
        }

        i++;
    }


    return activeCasesArray;
}

/*******************************************************************
 * This method calculates the active cases in a given state, and then
 * returns the current day's active cases.
 * @param a
 * @param b
 * @param size
 * @return active
 *******************************************************************/
 int calcActiveCases(int* a, int* b, int size) {
    int* arr;
    int active;

    arr = calcActiveCasesByDay(a, b, size);

    active = arr[size-1];
    return active;
} 
