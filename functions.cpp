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
#include <cstdlib>
#include <chrono>
#include <cmath>
#include <random>
#include "functions.hpp"


unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  std::uniform_real_distribution<double> distribution (1, 11);

using namespace std;
bool Confirm()
{
    bool isCorrect = true;
    bool confirm = true;
    string yn;
    do
    {   cin >> yn;
        if (yn.length() == 1 && (tolower(yn[0]) == 'y' || tolower(yn[0]) == 'n')) 
        {   isCorrect = true;
            if(tolower(yn[0]) == 'y') confirm = true;
            else confirm = false;
        }
        else
        {   cout << "Error! Enter letter 'y' (yes) or 'n' (no): ";
            isCorrect = false;
        }
    } while (!isCorrect);
    return confirm;
}

void Sorting(vector <int> &nd)
{
    sort(nd.begin(), nd.end());
}

bool CompareLastNames(Student &a,  Student &b)
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
    int length = temp.length();
    for (int i = 0;  i < length; i++)
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
    return distribution(generator);
}

bool isCorrectString(string var)
{
    bool isCorrect = true;
    int length = var.length();
    for (int i = 0; i < length; i++)
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
    return round(average);
}

int Max(vector <Student>& S, long int s, bool isTrue)
{
    int max = 0;

    for (int i = 0; i < s; i++)
    {
        if (S[i].lastName.length() > max && isTrue) max = S[i].lastName.length();
        else if (S[i].name.length() > max && !isTrue) max = S[i].name.length();
    }
    return max;
}

double Median(vector <int>nd, int n, int egz)
{
    double median;
    Sorting(nd);
    if (nd.size() % 2 != 0) median = nd[(nd.size() + 1) / 2];  
    else median = ((nd[nd.size() / 2 ] + nd[(nd.size() + 1) / 2]) / 2.0) * 0.4 + egz * 0.6;
    return round(median);
}

void Print(vector <Student> Students, long int s, string output, string fileName)
{
    Sorting(Students);
    string line = "";
    int maxLastName = Max(Students, s, true);
    int maxName = Max(Students, s, false);
    string file = fileName + ".txt";
    ofstream out(file);
    line.append(maxLastName + maxName + 40, '-');
    out << endl << left << setw(maxLastName + 10) << "Last name" << setw(maxName + 10) << "Name" << "Final (" << output << ")" << endl << line << endl;
    for (int i = 0; i < s; i++) out << left << setw(maxLastName + 10) << Students[i].lastName << setw(maxName + 10) << Students[i].name << fixed << setprecision(2) << Students[i].final << endl;
    out << endl;
    out.close();
}

void MainFunction(vector <Student>& Students, bool final)
{
    string inputName = " name";
    string inputLastName = " last name";
    string input_n = "Enter the number of homework tasks: ";
    string input_nd = "Enter homework grades: ";
    string input_egz = "Enter exam grade: ";
    Student S;

    int maxGrade = 10, minGrade = 1;
    double median;

    S.name = CorrectString(inputName);
    S.lastName = CorrectString(inputLastName);
    S.name[0] = toupper(S.name[0]);
    S.lastName[0] = toupper(S.lastName[0]);

    cout << "Do you want to enter the number of grades? (y/n) ";

    if (Confirm())
    {   S.n = CorrectNumber(input_n);
        cout << "Do you want to enter grades manually? (y/n) ";
        if (Confirm()) { for (int j = 0; j < S.n; j++) S.nd.push_back(CorrectNumber(input_nd, maxGrade, minGrade, false)); }
        
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
    if (Confirm())  S.egz = CorrectNumber(input_egz, maxGrade, minGrade, false);
    else
    {   S.egz = RandomGrade();
        cout << "Generated exam grade: " << S.egz << endl;
    }

    if (final)  S.final = Average(S.n, S.nd, S.egz);
    else  S.final = (Median(S.nd, S.n, S.egz));

    Students.push_back(S);
    S.nd.clear();
}

void ManualInput(long int s, vector <Student>& Students, bool final)
{
    for (int i = 0; i < s; i++) MainFunction(Students, final);
}

void UnknownInput(long int& s, vector <Student>& Students, bool final)
{
    bool Continue = true;

    while (Continue)
    {   MainFunction(Students, final);
        cout << "Do you want to add another student? (y/n) ";
        if (!Confirm())
        {   Continue = false;
            break;
        }
        else s++;   
    }
}

void GenerateStudent(long int s)
{ 
    
     start = std::chrono::steady_clock::now();

    string file = "kursiokai" + to_string(s) + ".txt";
    int n = RandomGrade();

    ofstream out(file);
    out << "Name" << setw(23) << "Last name" << setw(14);
    for (int i = 0; i < n; i ++) out << "Grade" + to_string(i + 1) << setw(8); 
    out << "Exam" <<  endl;

    for (int i = 0; i < s; i++){

    out << "Vardenis" + to_string(i);
    out << setw(20) << "Pavardenis" + to_string(i) << setw(10);
    for (int j = 0; j <= n; j ++) out << RandomGrade() << setw(8);
    out << endl; 
    }
    out.close();
    cout << "Time taken to generate students: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
}

void InputFiles(bool final, vector <Student> &Students, string file)
{
    start = std::chrono::steady_clock::now();
    stringstream buffer;
    ifstream in;
    try {
    in.open(file);
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
    }
        catch (int e)
    {
        cout << "Error! ";
        switch (e) {
        case 1:
            cout << "File not opened." << endl;
            break;
        case 2:
            cout << "File contains illegal characters." << endl;
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
    cout << "Time taken to input data: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
  
}

void Group(vector <Student> Students, long int s, vector <Student> &Losers, vector <Student> &Winners)
{
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < s; i++) 
    {
        if(isWinner(Students[i].final)) Winners.push_back(Students[i]);
        else Losers.push_back(Students[i]);
    }
    Students.clear();
    cout << "Time taken to group students: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;

}

bool isWinner(int final)
{
    bool winner = true;
    if (final < 5) winner = false;
    return winner;
}

int FileNumber()
{
    string number;
    bool isCorrect = true;
    do
    {   cin >> number;
        if (isdigit(number[0]) == true && (stoi(number) >= 1 && stoi(number) <= 5)) isCorrect = true;
        else
        {   cout << "Error! Enter a number in range 1 to 5: ";
            isCorrect = false;
        }
    } while (!isCorrect);
    int fileNumber = stoi(number);
    return fileNumber;
}
