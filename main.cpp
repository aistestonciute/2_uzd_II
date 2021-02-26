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

    try {
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
            stringstream buffer;
            ifstream in;
            in.open("kursiokai.txt");
            if (!in) throw 1;
            buffer << in.rdbuf();
            in.close();
            string line;
            getline(buffer, line);

            while (getline(buffer, line))
            {
                Student student;
                stringstream in(line);
                int grade;
                in >> student.name >> student.lastName;

                while (in >> grade)
                {
                    if (grade > 10 || grade < 1) throw 3;
                    else student.nd.push_back(grade);
                }
                if (student.nd.size() == 0) throw 2;
                student.nd.pop_back();
                student.n = student.nd.size();
                student.egz = grade;
                if (final)  student.final = Average(student.n, student.nd, student.egz);
                else  student.final = Median(student.nd, student.n, student.egz);
                Students.push_back(student);
            }
            s = Students.size();
        }

    }
    catch (int e)
    {
        cout << "Error! ";
        switch (e) {
        case 1:
            cout << "File not opened." << endl;
            break;
        case 2:
            cout << "Empty lines in file." << endl;
            break;
        case 3:
            cout << "Grade must be in range 1 to 10." << endl;
            break;
        default:
            cout << "System failure." << endl;
            break;
        }
        exit(1);
    }
    if (final)Print(Students, s, outputAverage);
    else Print(Students, s, outputMedian);

    Students.clear();
    WINPAUSE;
}
