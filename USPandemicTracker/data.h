#pragma once
//
// Created by mzig0203 on 7/9/2020.
//

#ifndef USPANDEMICTRACKER_DATA_H
#define USPANDEMICTRACKER_DATA_H
#endif

#include "state.h"
using namespace std;

/* Methods */
int* fileRead(string filename, string stateName);
int findNumDays(string filename, string stateName);
double arrayAvg(int* a, int d, int* numDays);
int arrayMaxVal(int* a, int size, int* numDays);
int arrayMinVal(int* a, int size, int* numDays);
int calcTotalCases(int* a, int size);
int calcTotalDeaths(int* a, int size);
int* calcTotalCasesByDay(int* a, int size);
int* calcTotalDeathsByDay(int* a, int size);
int* calcActiveCases(int* a, int* b, int size);
void printActiveCasesTextFile(int* a, int size);
void printDailyNewCasesTextFile(int* a, int size);
void printDailyNewDeathsTextFile(int* a, int size);
