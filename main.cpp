#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include "functions.hpp"

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif


using namespace std;

int main()
{
    string input_s = "Enter the number of students: ";
    string outputMedian = "median";
    string outputAverage = "mean";
    int s = 0;
    vector <Student> Students;
    bool final;

   
        cout << "Do you want the final grade to be mean (average)? (y/n) ";
        if (Confirm()) final = true;
        else final = false;

        cout << "Do you want to enter data manually? (y/n) ";
        if (Confirm())
        {
            cout << "Do you want to enter the number of students? (y/n) ";

            if (Confirm())
            {
                s = CorrectNumber(input_s);
                ManualInput(s, Students, final);
            }
            else UnknownInput(++s, Students, final);

        }
        else
        {
            cout << "Do you want to generate *.txt files? (y/n) "; 
            if (Confirm())
            {
                GenerateStudent(1000);
                GenerateStudent(10000);
                GenerateStudent(100000);
                GenerateStudent(1000000);
                GenerateStudent(10000000);
                
                cout << "To use kursiokai1000.txt enter '1'." << endl;
                cout << "To use kursiokai10000.txt enter '2'." << endl;
                cout << "To use kursiokai100000.txt enter '3'." << endl;
                cout << "To use kursiokai1000000.txt enter '4'." << endl;
                cout << "To use kursiokai10000000.txt enter '5'." << endl;
                
                cout << "Enter which file do you want to use: ";
                int fileNumber = FileNumber();
                if (fileNumber == 1)InputFiles(final, Students, "kursiokai1000.txt");
                if (fileNumber == 2)InputFiles(final, Students, "kursiokai10000.txt");
                if (fileNumber == 3)InputFiles(final, Students, "kursiokai100000.txt");
                if (fileNumber == 4)InputFiles(final, Students, "kursiokai1000000.txt");
                if (fileNumber == 5)InputFiles(final, Students, "kursiokai10000000.txt");            

            }
            
            else InputFiles(final, Students, "kursiokai.txt"); 
            s = Students.size();
        }

    vector <Student> Winners;
    vector <Student> Losers;

    Group(Students, s, Losers, Winners);
    int w = Winners.size();
    int l = Losers.size();

    if (final)
    {
        Print(Winners, w, outputAverage, "Winners");
        Print(Losers, l, outputAverage, "Losers");
    }
    else
    { 
        Print(Winners, w, outputMedian, "Winners");
        Print(Losers, l, outputMedian, "Losers");
    }

    Winners.clear();
    Losers.clear();
    WINPAUSE;
}
