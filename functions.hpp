#ifndef FUNCTIONS_H
#define FUNCTIONS_H

static std::chrono::steady_clock::time_point start;

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
int Max(vector <Student>&, long int, bool);
double Median(vector <int>, int, int);
void Print(vector <Student>, long int, string, string);
void MainFunction(vector <Student>& , bool);
void ManualInput(long int, vector <Student>&, bool);
void UnknownInput(long int&, vector <Student>&, bool);
void GenerateStudent(long int);
void InputFiles(bool, vector <Student> &, string);
void Group(vector <Student>, long int, vector <Student> &, vector <Student> &);
bool isWinner(int);
int FileNumber();
#endif
