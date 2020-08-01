#pragma once

//
// Created by grant on 7/9/2020.
//


#include <string>


#ifndef PANDEMICTRACKER_STATE_H
#define PANDEMICTRACKER_STATE_H

/* State Object */
class State {
private:
    //Variables
    std::string name;                //State Name
    std::string dataSetType;         //type of data set
    int* dailyNewCases;    //Array of daily new cases in the state starting on 1/21/2020
    int* dailyNewDeaths;   //Array of daily new deaths in the state starting on 1/21/2020
    int days;
    int* totalCases;       //Array of the total cases in the state starting on 1/21/2020
    int* totalDeaths;      //Array of the total deaths in the state starting on 1/21/2020
    int* activeCases;      //Array of the active cases (30 onset) in the state starting on 1/21/2020

public:
    //State Constructors
    State();
    State(std::string n, std::string d);

    //Methods
    //std::string getStateData();
    void State::getStateData(std::string* line1, std::string* line2, std::string* line3);

    //getters
    std::string getName() { return name; }
    std::string getDataName() { return dataSetType; }
    int* getDailyCases() { return dailyNewCases; }
    int* getDailyDeaths() { return dailyNewDeaths; }
    int* getActiveCases() { return activeCases;  }
    int* getTotalCases() { return totalCases; }
    int* getTotalDeaths() { return totalDeaths;  }
    int getDays() { return days; }

    //setters
    void setName(std::string n) { name = n; }
    void setDataName(std::string d) { dataSetType = d; }
    void setDailyCases(int* dc) { dailyNewCases = dc; }
    void setDailyDeaths(int* dd) { dailyNewDeaths = dd; }
    void setDays(int d) { days = d; }
};

#endif //PANDEMICTRACKER_STATE_H





