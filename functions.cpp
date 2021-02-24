#include <iostream>
#include <iomanip>
#include <vector>
#include <string> 
#include <numeric>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <sstream> 
#include "functions.hpp"


using namespace std;

string YN()
{
    bool isCorrect = true;
    string yn;

    do
    {   cin >> yn;
        if (yn.length() == 1 && (tolower(yn[0]) == 'y' || tolower(yn[0]) == 'n')) isCorrect = true;
        else
        {
            cout << "Error! Enter letter 'y' (yes) or 'n' (no): ";
            isCorrect = false;
        }
    } while (!isCorrect);
    return yn;
}

void Sorting(vector <int> &nd)
{
    sort(nd.begin(), nd.end());
}

bool CompareLastNames(Student a,  Student b)
{
    return a.lastName < b.lastName;
}

void Sorting(vector <Student>& S)
{
    sort(S.begin(), S.end(), CompareLastNames); 
}

bool isCorrectNumber(string temp, int maxGrade, int minGrade)
{
    bool isCorrectValue = true;

    for (int i = 0; i < temp.length(); i++)
    {
        if (!isdigit(temp[i]))
        {   isCorrectValue = false;
            cout << "Error! ";
            break;
        }
    }
    if (isCorrectValue == true && stoi(temp) < 1 && maxGrade == 0 && minGrade == 0)
    {   isCorrectValue = false;
        cout << "Error! Number must be greater than 0! ";
    }

    else if (isCorrectValue == true && (stoi(temp) < minGrade || stoi(temp) > maxGrade) && maxGrade != 0)
    {   isCorrectValue = false;
        cout << "Error! Number must be in range 1 to 10! ";
    }
    return isCorrectValue;
}

int CorrectNumber(string input, int maxGrade, int minGrade, bool stop)
{
    int x;
    string temp;

    do
    {   cout << input;
        cin >> temp;
        if (temp == "stop" && stop == true) break;
    }   while (!isCorrectNumber(temp, maxGrade, minGrade));

    if (temp != "stop")x = stoi(temp);
    else x = -1;
    return x;
}

int CorrectNumber(string input)
{
    int a = CorrectNumber(input, 0, 0, false);
    return a;
}

void Stop(string input, int maxGrade, int minGrade, vector<int>& nd, int& n)
{
    bool stop = true;
    int temp;
    n = 0;

    while (stop)
    {   temp = CorrectNumber(input, maxGrade, minGrade, true);
        if (temp != -1)
        { nd.push_back(temp);
            n++;
        }
        else
        {   if (n == 0)cout << "Error! Enter at least one number! ";
            else stop = false;
        }
    }
}

int RandomGrade()
{
    using hrClock = chrono::high_resolution_clock;
    mt19937 mt(static_cast<long unsigned int> (hrClock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 10);
    int grade = dist(mt);
    return grade;
}

bool isCorrectString(string var)
{
    bool isCorrect = true;

    for (int i = 0; i < var.length(); i++)
    {   if (isalpha(var[i]) == false)
        {isCorrect = false;
            cout << "Error! Name must contain only letters! " << endl;
            break;
        }
        else isCorrect = true;
    }
    return isCorrect;
}

string CorrectString(string input)
{
    string var;
    do
    {   cout << "Enter student's" << input << ": ";
        cin >> var;
    } while (!isCorrectString(var));

    return var;
}

int Sum(int n, vector<int> nd)
{ 
    int sum;
    sum = accumulate(nd.begin(), nd.end(), 0);
    return sum;
}

double Average(int n, vector <int> nd, int egz)
{
    double average = 0.4 * (Sum(n, nd) * 1.0 / n) + 0.6 * egz;
    return average;
}

int Max(vector <Student>& S, int s, bool isTrue)
{
    int max = 0;

    for (int i = 0; i < s; i++)
    {
        if (S[i].lastName.length() > max && isTrue) max = S[i].lastName.length();
        else if (S[i].name.length() > max && !isTrue) max = S[i].name.length();
    }
    return max;
}

double Median(vector <int>nd, int n)
{
    double median;
    Sorting(nd);
    if (nd.size() % 2 != 0) median = nd[(nd.size() + 1) / 2];  
    else median = (nd[nd.size() / 2 ] + nd[(nd.size() + 1) / 2]) / 2.0;
    return median;
}

void Print(vector <Student> Students, int s, string output)
{
    Sorting(Students);
    string line = "";
    int maxLastName = Max(Students, s, true);
    int maxName = Max(Students, s, false);
    line.append(maxLastName + maxName + 40, '-');
    cout << endl << left << setw(maxLastName + 10) << "Last name" << setw(maxName + 10) << "Name" << "Final (" << output << ")" << endl << line << endl;
    for (int i = 0; i < s; i++) cout << left << setw(maxLastName + 10) << Students[i].lastName << setw(maxName + 10) << Students[i].name << fixed << setprecision(2) << Students[i].final << endl;
    cout << endl;
}

void MainFunction(vector <Student>& Students, char yn, bool final)
{
    string inputName = " name";
    string inputLastName = " last name";
    string input_n = "Enter the number of homework tasks: ";
    string input_nd = "Enter homework grades: ";
    string input_egz = "Enter exam grade: ";
    srand(time(0));
    Student S;

    int maxGrade = 10, minGrade = 1;
    double median;

    S.name = CorrectString(inputName);
    S.lastName = CorrectString(inputLastName);
    S.name[0] = toupper(S.name[0]);
    S.lastName[0] = toupper(S.lastName[0]);

    cout << "Do you want to enter the number of grades? (y/n) ";
    char ynGrades = (YN()[0]);

    if (ynGrades == 'y')
    {   S.n = CorrectNumber(input_n);
        cout << "Do you want to enter grades manually? (y/n) ";
        ynGrades = (YN()[0]);
        if (ynGrades == 'y') { for (int j = 0; j < S.n; j++) S.nd.push_back(CorrectNumber(input_nd, maxGrade, minGrade, false)); }
        
        else{   for (int j = 0; j < S.n; j++) S.nd.push_back(RandomGrade());
                cout << "Generated grades: ";
                for (int j = 0; j < S.n - 1; j++) cout << S.nd[j] << ", ";
                cout << S.nd[S.n - 1] << "." << endl;
            }
    }
    else
    {   int j = 0;
        cout << "Enter grades (to end the cycle, enter 'stop'). " << endl;
        Stop(input_nd, maxGrade, minGrade, S.nd, S.n);
    }

    cout << "Do you want to enter exam grade manually? (y/n) ";
    ynGrades = (YN()[0]);

    if (ynGrades == 'y')  S.egz = CorrectNumber(input_egz, maxGrade, minGrade, false);
    else
    {   S.egz = RandomGrade();
        cout << "Generated exam grade: " << S.egz << endl;
    }

    if (final)  S.final = Average(S.n, S.nd, S.egz);
    else  S.final = (Median(S.nd, S.n));

    Students.push_back(S);
    S.nd.clear();
}

void ManualInput(int s, vector <Student>& Students, char yn, bool final)
{
    for (int i = 0; i < s; i++) MainFunction(Students, yn, final);
}

void UnknownInput(int& s, vector <Student>& Students, char yn, bool final)
{
    bool Continue = true;

    while (Continue)
    {   MainFunction(Students, yn, final);
        cout << "Do you want to add another student? (y/n) ";
        char ynContinue = (YN()[0]);
        if (ynContinue == 'n')
        {   Continue = false;
            break;
        }
        else s++;   
    }
}
