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
#include <chrono>
#include <random>
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
        char yn = (YN())[0];
        if (yn == 'y') final = true;
        else final = false;

        cout << "Do you want to enter data manually? (y/n) ";
        yn = (YN())[0];

        if (yn == 'y')
        {
            cout << "Do you want to enter the number of students? (y/n) ";
            yn = (YN())[0];

            if (yn == 'y')
            {
                s = CorrectNumber(input_s);
                ManualInput(s, Students, yn, final);
            }
            else UnknownInput(++s, Students, yn, final);

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
                string grade;
                int n = 0;
                stringstream in(line);
                in >> student.name >> student.lastName;

                while (in >> grade)
                {
                    if (grade.length() > 2) throw 3;
                    if (!isdigit(grade[0]) || (grade.length() == 2 && !isdigit(grade[1]))) throw 4;
                    if (stoi(grade) > 10 || stoi(grade) < 1) throw 5;
                    else student.nd.push_back(stoi(grade));
                    n++;
                }
                n--;
                student.n = n;
                if (student.nd.size() == 0) throw 2;
                student.nd.pop_back();
                student.egz = stoi(grade);
                if (final)  student.final = Average(student.n, student.nd, student.egz);
                else  student.final = (Median(student.nd, student.n)) * 0.4 + student.egz * 0.6;
                Students.push_back(student);
                s++;
            }

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
            cout << "Grade must contain only one or two symbols (digits)." << endl;
            break;
        case 4:
            cout << "Grade must contain only digits." << endl;
            break;
        case 5:
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
    return 0;
}
