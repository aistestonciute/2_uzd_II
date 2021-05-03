#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
#include <list>
#include <deque>
#include "student.hpp"

static std::chrono::steady_clock::time_point start;

using namespace std;

struct CompareLastNames
{
    bool operator()(Student& a, Student& b) { return (a.getLastName().compare(b.getLastName())); }
};

#define outputMedian  "median"
#define outputAverage  "mean"


bool Confirm();
void Sorting(vector <int>&);
bool isCorrectNumber(string, int, int);
int CorrectNumber(string, int, int, bool);
int CorrectNumber(string);
void Stop(string, int, int, vector<int>&, int& );
int RandomGrade();
bool isCorrectString(string);
string CorrectString(string);
int Sum(vector<int>);
double Average(int, vector <int>, int);
double Median(vector <int>, int, int);
int Max(long int);

template <class T>
void Print(T, long int, string, string);

template <class T>
void MainFunction(T&, bool);

template <class T>
void ManualInput(long int, T&, bool);

template <class T>
void UnknownInput(long int&, T&, bool);
void GenerateStudent(long int);

template <class T>
void InputFiles(T&, string, bool);
void Container(int);

template <class T>
void PrePrint(bool, T, T);

template <class T>
void PreGroup(T&, T&, int);

template <class T>
void AutomaticOrManual(T&, bool);

bool Final();

template <class T>
void Manual(long int&, T&, bool);

template <class T>
void Automatic(long int&, T&, bool);

template <class T>
void Group(T&, T&);

template <class T>
void Group(T&, T&, T&);

template <class T>
void Group(T&, T&, bool);

int StrategyNumber();

#endif
