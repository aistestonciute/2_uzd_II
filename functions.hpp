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

bool Confirm();
void Sorting(vector <int>&);
bool CompareLastNames(Student&, Student&);
void Sorting(vector <Student>& );
bool isCorrectNumber(string, int, int);
int CorrectNumber(string, int, int, bool);
int CorrectNumber(string);
void Stop(string, int, int, vector<int>&, int& );
int RandomGrade();
bool isCorrectString(string);
string CorrectString(string);
int Sum(int, vector<int>);
double Average(int, vector <int>, int);
int Max(vector <Student>&, int, bool);
double Median(vector <int>, int, int);
void Print(vector <Student>, int, string);
void MainFunction(vector <Student>& , bool);
void ManualInput(int, vector <Student>&, bool);
void UnknownInput(int&, vector <Student>&, bool);

#endif
