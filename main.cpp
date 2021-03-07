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
#include <random>
#include <chrono>
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
    long int s = 0;
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
                    cout << endl << "> Using kursiokai1000.txt." << endl;
                    GenerateStudent(1000);
                    InputFiles(final, Students, "kursiokai1000.txt");
                
                    cout << endl << "> Using kursiokai10000.txt." << endl;
                    GenerateStudent(10000);
                    InputFiles(final, Students, "kursiokai10000.txt");
                
                    cout << endl << "> Using kursiokai100000.txt." << endl;
                    GenerateStudent(100000);
                    InputFiles(final, Students, "kursiokai100000.txt");

                    cout << endl << "> Using kursiokai1000000.txt." << endl;
                    GenerateStudent(1000000);
                    InputFiles(final, Students, "kursiokai1000000.txt");

                    cout << endl << "> Using kursiokai10000000.txt." << endl;
                    GenerateStudent(10000000);
                    InputFiles(final, Students, "kursiokai10000000.txt");          
        }
    
    WINPAUSE;
}
