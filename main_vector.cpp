#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include <numeric>

using namespace std;


// Struktura saugo vieno studento informacija
struct Student
{
    string name;
    string lastName;
    int n;
    vector <int> nd;
    int egz;
    double final;

};

//Tikrina ar ivesta reiksme atititnka reikalavimus (yra skaicius, pazymys priklauso [0,10] intervalui)
bool isCorrectNumber(string temp, int maxGrade, int minGrade)
{
    bool isCorrectValue = true;

    for (int i = 0; i < temp.length(); i++)
    {
        if (!isdigit(temp[i]))
        {
            isCorrectValue = false;
            cout << "Error! ";
            break;
        }

    }
    if (isCorrectValue == true && stoi(temp) < 1 && maxGrade == 0 && minGrade == 0)
    {
        isCorrectValue = false;
        cout << "Error! Number must be greater than 0! ";
    }


    else if (isCorrectValue == true && (stoi(temp) < minGrade || stoi(temp) > maxGrade) && maxGrade != 0)
    {
        isCorrectValue = false;
        cout << "Error! Number must be in range 0 to 10! ";
    }

    return isCorrectValue;
}

//Skaiciaus ivedimo funkcija (si funkcija naudojama ir zinant n ir ne)
int CorrectNumber(string input, int maxGrade, int minGrade, bool stop)
{
    int x;
    string temp;

    do
    {
        cout << input;
        cin >> temp;
        if (temp == "stop" && stop == true) break;


    } while (!isCorrectNumber(temp, maxGrade, minGrade));

    if (temp != "stop")x = stoi(temp);
    else x = -1;
    return x;
}

//Skaiciaus ivedimo funkcija (su maziau parametru)
int CorrectNumber(string input)
{
    int a = CorrectNumber(input, 0, 0, false);
    return a;
}


//Patikrina ar ivesta reiksme nera "stop" (naudojama pazymiu rasymui, kai nezinoma n)
void Stop(string input, int maxGrade, int minGrade, vector<int> &nd, int& n)
{
    bool stop = true;
    int temp;
    n = 0;

    while (stop)
    {

        temp = CorrectNumber(input, maxGrade, minGrade, true);
        if (temp != -1)
        {
            nd.push_back(temp);
            n++;
        }
        else
        {
            if (n == 0)cout << "Error! Enter at least one number! ";
            else stop = false;
        }

    }
}

// Patikrinama ar ivesta varda/pavarde sudaro tik raides
bool isCorrectString(string var)
{
    bool isCorrect = true;

    for (int i = 0; i < var.length(); i++)
    {
        if (isalpha(var[i]) == false)
        {
            isCorrect = false;
            cout << "Error! Name must contain only letters! " << endl;
            break;
        }
        else isCorrect = true;
    }

    return isCorrect;
}

//Jei ivesta varda/pavarde sudaro tik raides, programa iraso ta kintamaji. Jei ne, prasoma ivesti is naujo.
string CorrectString(int x, string input)
{
    string var;
    do
    {
        cout << "Enter " << x + 1 << " student's" << input << " : ";
        cin >> var;
    } while (!isCorrectString(var));

    return var;
}

//Skaiciuojama pazymiu suma, reikalinga vidurkiui.
int Sum(int n, vector<int> nd)
{
    int sum;
    sum = accumulate(nd.begin(), nd.end(), 0);
    return sum;
}
//Galutinio vidurkio skaiciavimas
double Average(int n, vector <int> nd, int egz)

{
    double average = 0.4 * (Sum(n, nd) * 1.0 / n) + 0.6 * egz;
    return average;
}

//Pazymiu rikiavimas, reikalingas medianos radimui 
void Sorting(vector <int> &nd, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nd[i] < nd[j]) swap(nd[i], nd[j]);
        }
    }


}

//Studentu pavardziu rikiavimas, reikalingas programos isvedimui i ekrana.
void Sorting(Student S[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = i + 1; j < s; j++)
        {
            if (S[i].lastName > S[j].lastName) swap(S[i], S[j]);
        }
    }
}

//Ieskomas ilgiausias vardas/pavarde, reikalingas programos isvedimui i ekrana.
int Max(Student S[], int s, bool isTrue)
{
    int max = 0;

    for (int i = 0; i < s; i++)
    {

        if (S[i].lastName.length() > max && isTrue)
        {
            max = S[i].lastName.length();
        }

        else if (S[i].name.length() > max && !isTrue)
        {
            max = S[i].name.length();
        }
    }
    return max;
}

//Medianos skaiciavimas
double Median(vector <int>nd, int n)
{
    double median;
    Sorting(nd, n);
    if (n % 2 != 0) median = nd[n / 2];
    else median = (nd[n / 2 - 1] + nd[n / 2]) / 2.0;

    return median;
}

//Isvedimo i ekrana funkcija
void Print(Student S[], int s, string output)
{

    string line = "";
    Sorting(S, s);
    int maxLastName = Max(S, s, true);
    int maxName = Max(S, s, false);
    cout << endl << left << setw(maxLastName + 10) << "Last name" << setw(maxName + 10) << "Name" << "Final (" << output << ")" << endl;

    line.append(maxLastName + maxName + 40, '-');
    cout << line << endl;

    for (int i = 0; i < s; i++)
    {
        cout << left << setw(maxLastName + 10) << S[i].lastName << setw(maxName + 10) << S[i].name << fixed << setprecision(2) << S[i].final << endl;
    }
    cout << endl;
}

//Atsitiktinio pazymio generavimas
int RandomGrade()
{
    int grade;
    grade = rand() % (10 + 1);
    return grade;
}

//Tikrinama ar ivesta reiksme yra 'y' arba 'n'. Vykdoma tol, kol reiksme ivesta teisingai.
string YN()
{
    bool isCorrect = true;
    string yn;

    do
    {
        cin >> yn;
        if (yn.length() == 1 && (tolower(yn[0]) == 'y' || tolower(yn[0]) == 'n')) isCorrect = true;

        else
        {
            cout << "Error! Enter letter 'y' (yes) or 'n' (no): ";
            isCorrect = false;
        }

    } while (!isCorrect);

    return yn;
}


int main()
{
    //Klaidu kodai, leidziantys vartotojui geriau suprasti, kur padare klaida.
    string inputName = " name";
    string inputLastName = " last name";
    string input_s = "Enter the number of students: ";
    string input_n = "Enter the number of homework tasks: ";
    string input_nd = "Enter homework grades: ";
    string input_egz = "Enter exam grade: ";
    string outputMedian = "median";
    string outputAverage = "mean";

    //Reikalinga atsitiktinio pazymio generavimui
    srand(time(0));

    //Pazymiu intervalas
    int maxGrade = 10, minGrade = 0;

    double median;

    cout << "Do you want the final grade to be the mean (average)? (y/n) ";
    char yn = (YN())[0];

    char ynGrades;
    int s = CorrectNumber(input_s);

    Student* S = new Student[s];

    

    for (int i = 0; i < s; i++)
    {
        S[i].name = CorrectString(i, inputName);
        S[i].name[0] = toupper(S[i].name[0]);
        S[i].lastName = CorrectString(i, inputLastName);
        S[i].lastName[0] = toupper(S[i].lastName[0]);
        cout << "Do you want to enter the number of grades? (y/n) ";
        ynGrades = (YN()[0]);

        if (ynGrades == 'y')
        {
            S[i].n = CorrectNumber(input_n);
            cout << "Do you want to enter grades manually? (y/n) ";
            ynGrades = (YN()[0]);

            if (ynGrades == 'y')
            {

                for (int j = 0; j < S[i].n; j++)
                {
                    S[i].nd.push_back(CorrectNumber(input_nd, maxGrade, minGrade, false));
                }
            }

            else
            {
                for (int j = 0; j < S[i].n; j++) S[i].nd.push_back(RandomGrade());
                cout << "Generated grades: ";
                for (int j = 0; j < S[i].n - 1; j++) cout << S[i].nd[j] << ", ";
                cout << S[i].nd[S[i].n - 1] << "." << endl;
            }

            cout << "Do you want to enter exam grade manually? (y/n) ";
            ynGrades = (YN()[0]);

            if (ynGrades == 'y') S[i].egz = CorrectNumber(input_egz, maxGrade, minGrade, false);
            else
            {
                S[i].egz = RandomGrade();
                cout << "Generated exam grade: " << S[i].egz << endl;
            }
        }
        else
        {
            int j = 0;
            cout << "Enter grades (to end the cycle, enter 'stop'). " << endl;
            Stop(input_nd, maxGrade, minGrade, S[i].nd, S[i].n);
        }

        if (yn == 'y') S[i].final = Average(S[i].n, S[i].nd, S[i].egz);
        else S[i].final = Median(S[i].nd, S[i].n);

    }


    if (yn == 'y')Print(S, s, outputAverage);
    else Print(S, s, outputMedian);


    return 0;
}
