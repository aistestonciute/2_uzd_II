#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

struct Student
{
    string name;
    string lastName;
    int n;
    vector <int> nd;
    int egz;
    double final;
};

string YN();
void Sorting(vector <int>& nd);
bool CompareLastNames(Student a, Student b);
void Sorting(vector <Student>& S);
bool isCorrectNumber(string temp, int maxGrade, int minGrade);
int CorrectNumber(string input, int maxGrade, int minGrade, bool stop);
int CorrectNumber(string input);
void Stop(string input, int maxGrade, int minGrade, vector<int>& nd, int& n);
int RandomGrade();
bool isCorrectString(string var);
string CorrectString(string input);
int Sum(int n, vector<int> nd);
double Average(int n, vector <int> nd, int egz);
int Max(vector <Student>& S, int s, bool isTrue);
double Median(vector <int>nd, int n);
void Print(vector <Student> Students, int s, string output);
void MainFunction(vector <Student>& Students, char yn, bool final);
void ManualInput(int s, vector <Student>& Students, char yn, bool final);
void UnknownInput(int& s, vector <Student>& Students, char yn, bool final);

#endif
