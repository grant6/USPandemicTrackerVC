#pragma once
//
// Created by mzig0203 on 7/9/2020.
//

#ifndef USPANDEMICTRACKER_DATA_H
#define USPANDEMICTRACKER_DATA_H
#endif

#include "state.h"
/* Methods */
int* fileRead(std::string filename, std::string stateName);
int findNumDays(std::string filename, std::string stateName);
double arrayAvg(int* a, int d, int* numDays);
int arrayMaxVal(int* a, int size, int* numDays);
int arrayMinVal(int* a, int size, int* numDays);
int calcTotalCases(int* a, int size);
int calcTotalDeaths(int* a, int size);
int* calcTotalCasesByDay(int* a, int size);
int* calcTotalDeathsByDay(int* a, int size);
int* calcActiveCasesByDay(int* a, int* b, int size);
int calcActiveCases(int* a, int* b, int size);
