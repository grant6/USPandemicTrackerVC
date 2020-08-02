//
// Created by grant on 7/9/2020.
//

#include "state.h"
#include "data.h"
#include "date.h"
#include "MyForm.h"
#include <iostream>
#define dailyCasesFile "daily_cases.txt"
#define dailyDeathsFile "daily_deaths.txt"

void State::getStateData(std::string* line1, std::string* line2, std::string* line3) {
    int numDays = 0;
    int startDay = 21;
    int startMonth = 1;
    int startYear = 2020;
    int* pNumDays = &numDays;
    std::string result1 = " ";
    std::string result2 = " ";
    std::string result3 = " ";
    int avg, gst, lst;

    if (dataSetType == "DAILY NEW CASES") {
        avg = arrayAvg(dailyNewCases, days, pNumDays); //
        result1 = "Average Daily New Cases: "
            + std::to_string(avg);
        gst = arrayMaxVal(dailyNewCases, days, pNumDays); //
        result2 = "Greatest Daily New Cases: "
            + std::to_string(gst)
            + " cases on " + getDate(startDay, startMonth, startYear, numDays);
        lst = arrayMinVal(dailyNewCases, days, pNumDays); //
        result3 = "Least Daily New Cases: "
            + std::to_string(lst)
            + " cases on " + getDate(startDay, startMonth, startYear, numDays);
    }
    else if (dataSetType == "DAILY NEW DEATHS") {
        avg = arrayAvg(dailyNewDeaths, days, pNumDays); //
        result1 = "Average Daily New Deaths: "
            + std::to_string(avg);
        gst = arrayMaxVal(dailyNewDeaths, days, pNumDays); //
        result2 = "Greatest Daily New Deaths: "
            + std::to_string(gst)
            + " deaths on " + getDate(startDay, startMonth, startYear, numDays);
        lst = arrayMinVal(dailyNewDeaths, days, pNumDays); //
        result3 = "Least Daily New Deaths: "
            + std::to_string(lst)
            + " deaths on " + getDate(startDay, startMonth, startYear, numDays);
    }
    else if (dataSetType == "TOTAL CASES") {
        result1 = "Total Cases: "
            + std::to_string(calcTotalCases(dailyNewCases, days - 1))
            + " as of " + getDate(startDay, startMonth, startYear, days - 1);
    }
    else if (dataSetType == "TOTAL DEATHS") {
        result1 = "Total Deaths: "
            + std::to_string(calcTotalDeaths(dailyNewDeaths, days - 1))
            + " as of " + getDate(startDay, startMonth, startYear, days - 1);
    }
    else if (dataSetType == "ACTIVE CASES") {


        result1 = "Active Cases: "
        + std::to_string(calcActiveCases(dailyNewCases, dailyNewDeaths, days))
        + " as of " + getDate(startDay, startMonth, startYear, days - 1);

    }

    *line1 = result1;
    *line2 = result2;
    *line3 = result3;
}

State::State() {}

State::State(std::string n, std::string d) {
    name = move(n);
    dataSetType = move(d);

    dailyNewCases = fileRead(dailyCasesFile, name);
    dailyNewDeaths = fileRead(dailyDeathsFile, name);
    days = findNumDays(dailyCasesFile, name);
    totalCases = calcTotalCasesByDay(dailyNewCases, days);
    totalDeaths = calcTotalDeathsByDay(dailyNewDeaths, days);
    activeCases = calcActiveCasesByDay(dailyNewCases, dailyNewDeaths, days);
}