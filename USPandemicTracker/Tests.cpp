///*******************************************************************
// * This function acts to test the methods written in other classes.
// * There was an issue with the linker when implementing unit tests.
// * In order for these tests to work, The data, date, and state files
// * must be transferred to a regular (Non-Visual) C++ project, so the 
// * output can be seen on the console.
// ******************************************************************/
//#include "data.h"
//#include "date.h"
//#include "state.h"
//#include <iostream>
//
//using namespace std;
//
//int main() {
//    //filenames
//    string dailyCasesFile = "daily_cases.txt";
//    string dailyDeathsFile = "daily_deaths.txt";
//
//    //Welcome Message
//    cout << "Welcome to the Pandemic Tracker Testing Function." << endl;
//
//    /***************************************************************
//     * state.cpp printState printStateData
//     * userInput.cpp chooseState chooseData
//     **************************************************************/
//
//    State state("Missouri", "ACTIVE CASES");
//
//    //test getDays
//    state.setDays(170);
//    if (state.getDays() == 170)
//        cout << "getDays passed" << endl;
//    else
//        cout << "getDays failed" << endl;
//
//    //test getName
//    state.setName("Michigan");
//    if (state.getName() == "Michigan")
//        cout << "getName passed" << endl;
//    else
//        cout << "getName failed" << endl;
//
//    //test getDataName
//    state.setDataName("ACTIVE CASES");
//    if (state.getDataName() == "ACTIVE CASES")
//        cout << "getDataName passed" << endl;
//    else
//        cout << "getDataName failed" << endl;
//
//    State state1("UTAH", "DAILY NEW CASES");
//    State state2("ALABAMA", "DAILY NEW DEATHS");
//    State state3("OHIO", "TOTAL CASES");
//    State state4("KANSAS", "TOTAL DEATHS");
//    State state5("CALIFORNIA", "ACTIVE CASES");
//
//    std::string line1;
//    std::string line2;
//    std::string line3;
//    std::string* ptr1 = &line1;
//    std::string* ptr2 = &line2;
//    std::string* ptr3 = &line3;
//
//    //test print statements
//    cout << endl;
//    state1.getStateData(ptr1, ptr2, ptr3);
//    cout << *ptr1 + "\r\n" + *ptr2 + "\r\n" + *ptr3 << endl;
//
//    state2.getStateData(ptr1, ptr2, ptr3);
//    cout << *ptr1 + "\r\n" + *ptr2 + "\r\n" + *ptr3 << endl;
//
//    state3.getStateData(ptr1, ptr2, ptr3);
//    cout << *ptr1 + "\r\n" + *ptr2 + "\r\n" + *ptr3 << endl;
//
//    state4.getStateData(ptr1, ptr2, ptr3);
//    cout << *ptr1 + "\r\n" + *ptr2 + "\r\n" + *ptr3 << endl;
//
//    state5.getStateData(ptr1, ptr2, ptr3);
//    cout << *ptr1 + "\r\n" + *ptr2 + "\r\n" + *ptr3 << endl;
//    /***************************************************************
//    * data.cpp
//    * fileRead, arrayAvg, arrayMaxVal, arrayMinVal, findNumDays,
//    * calcTotalCases, CalcTotalDeaths, calcTotalDeathsByDay,
//    * calcActiveCases, printActiveCases, printDailyNewCasesTextFile,
//    * printDailyNewDeathsTextFile
//    **************************************************************/
//
//    /***************************************************************
//     * date.cpp
//     * getDate
//     **************************************************************/
//    string date = getDate(21, 1, 2020, 169);
//    string expected = "July 8, 2020";
//    if (date == expected)
//        cout << "getDate passed" << endl;
//    else {
//        cout << "getDate failed" << endl;
//        cout << date << " != " << expected << endl;
//    }
//
//    string date1 = getDate(21, 12, 2019, 45);
//    string expected1 = "February 4, 2020";
//    if (date1 == expected1)
//        cout << "getDate passed" << endl;
//    else {
//        cout << "getDate failed" << endl;
//        cout << date1 << " != " << expected1 << endl;
//    }
//
//    string date2 = getDate(21, 2, 2019, 320);
//    string expected2 = "January 7, 2020";
//    if (date2 == expected2)
//        cout << "getDate passed" << endl;
//    else {
//        cout << "getDate failed" << endl;
//        cout << date2 << " != " << expected2 << endl;
//    }
//
//    return 0;
//}
