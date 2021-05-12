#include "functions.hpp"

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator (seed);

  std::uniform_real_distribution<double> distribution (1, 11);


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

void Sorting(vector <int>& hw)
{
    sort(hw.begin(), hw.end());
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
        cout << "Error! Number must be in range " << minGrade << " to "<< maxGrade << "! ";
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

void Stop(string input, int maxGrade, int minGrade, vector<int>& hw, int& n)
{
    bool stop = true;
    int temp;
    n = 0;

    while (stop)
    {   temp = CorrectNumber(input, maxGrade, minGrade, true);
        if (temp != -1)
        { hw.push_back(temp);
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

int Sum(vector<int> hw)
{ 
    int sum;
    sum = accumulate(hw.begin(), hw.end(), 0);
    return sum;
}

double Average(int n, vector <int> hw, int exam)
{
    double average = 0.4 * (Sum(hw) * 1.0 / n) + 0.6 * exam;
    return round(average);
}

double Median(vector <int>hw, int n, int exam)
{
    double median;
    Sorting(hw);
    if (hw.size() % 2 != 0) median = hw[(hw.size() + 1) / 2];  
    else median = ((hw[hw.size() / 2 ] + hw[(hw.size() + 1) / 2]) / 2.0) * 0.4 + exam * 0.6;
    return round(median);
}

int Max(long int s)
{
    int digits = 0;
    while (s != 0)
    {
        s = s / 10;
        ++digits;
    }
    return digits;
}

template <class T>
void Print(T Students, long int s, string output, string fileName)
{
    string line = "";
    int maxName = 8 + Max(s);
    int maxLastName = 10 + Max(s);
    string file = fileName + ".txt";
    ofstream out(file);
    line.append(maxLastName + maxName + 40, '-');
    out << endl << left << setw(maxLastName + 10) << "Last name" << setw(maxName + 10) << "Name" << "Final (" << output << ")" << endl << line << endl;
    for (long int i = 0; i < s; i++)
    {
        out << left << setw(maxLastName + 10) << Students.back().getLastName() << setw(maxName + 10) << Students.back().getName() << fixed << setprecision(2) << Students.back().getFinalGrade() << endl;
        Students.pop_back();
    }
    out << endl;
    out.close();
    Students.clear();
}

template <class T>
void MainFunction(T& Students, bool isAverage)
{
    int maxGrade = 10, minGrade = 1;
    double median;
    Student S;
    string name = CorrectString(" name");
    string lastName = CorrectString(" last name");
    name[0] = toupper(name[0]);
    lastName[0] = toupper(lastName[0]);
    S.setName(name);
    S.setLastName(lastName);
    int tempN = 0;
    vector <int> hw;

    cout << "Do you want to enter the number of grades? (y/n) ";

    if (Confirm())
    {
        tempN = CorrectNumber("Enter the number of homework tasks: ");
        cout << "Do you want to enter grades manually? (y/n) ";
        if (Confirm()) { for (int j = 0; j < tempN; j++) hw.push_back(CorrectNumber("Enter homework grades : ", maxGrade, minGrade, false)); }

        else {
            for (int j = 0; j < tempN; j++) hw.push_back(RandomGrade());
            cout << "Generated grades: ";
            for (int j = 0; j < tempN- 1; j++) cout << hw[j] << ", ";
            cout << hw[tempN - 1] << "." << endl;
        }
    }
    else
    {
        int j = 0;
        cout << "Enter grades (to end the cycle, enter 'stop'). " << endl;
        Stop("Enter homework grades : ", maxGrade, minGrade, hw, tempN);
    }

    S.setHw(hw);

    cout << "Do you want to enter exam grade manually? (y/n) ";
    if (Confirm())  S.setExam(CorrectNumber("Enter exam grade: ", maxGrade, minGrade, false));
    else
    {
        S.setExam(RandomGrade());
        cout << "Generated exam grade: " << S.getExam() << endl;
    }

    if (isAverage)  S.setFinalGrade(Average(tempN, hw, S.getExam()));
    else  S.setFinalGrade(Median(hw, tempN, S.getExam()));

    Students.push_back(S);
    hw.clear();
}

template <class T>
void ManualInput(long int s, T& Students, bool isAverage)
{
    for (int i = 0; i < s; i++) MainFunction(Students, isAverage);
}

template <class T>
void UnknownInput(long int& s, T& Students, bool isAverage)
{
    bool Continue = true;

    while (Continue)
    {
        MainFunction(Students, isAverage);
        cout << "Do you want to add another student? (y/n) ";
        if (!Confirm())
        {
            Continue = false;
            break;
        }
        else s++;
    }
}

void GenerateStudent(long int s)
{ 
    string file = "kursiokai" + to_string(s) + ".txt";
    int n = 25;
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
}

template <class T>
void InputFiles(T& Students, string file, bool isAverage)
{
    start = std::chrono::steady_clock::now();
    vector <int> hw;
    string name, lastName;
    Student S;
    
    stringstream buffer;
    ifstream in;
    try {
        in.open(file);
        if (!in) throw 1;
        buffer << in.rdbuf();
        in.close();
        string line;
        getline(buffer, line);
        int tempN = 0;
        while (getline(buffer, line))
        {
            Students.resize(Students.size()+ 1);
            stringstream in(line);
            int grade;
            in >> name >> lastName;
            S.setName(name);
            S.setLastName(lastName);

            while (in >> grade)
            {
                if (grade > 10 || grade < 1) throw 3;
                else hw.push_back(grade);
            }
            if (hw.size() == 0) throw 2;
            hw.pop_back();
            S.setHw(hw);
            tempN = hw.size();
            S.setExam(grade);
            if (isAverage)  S.setFinalGrade (Average(tempN, S.getHw(), S.getExam()));
            else  S.setFinalGrade ( Median(S.getHw(), tempN, S.getExam()));
            Students.push_back(S);
			hw.clear();
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
    double end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() / 1000.0;
    cout << "Time taken to input data: " << end << " s" << endl;

}

int StrategyNumber()
{
    cout << endl <<"> Choose grouping strategy:" << endl
    << "1. Grouping with two containers" << endl
    << "2. Grouping with one container" << endl
    << "3. Grouping with one container (optimized)" << endl;
    int strategy = CorrectNumber("Enter number: ", 3, 1, false);
    return strategy;
}

void Container(int container)
{
    bool isAverage = IsAverage();
    int strategy = StrategyNumber();
    
    if (container == 1) 
    {
        deque <Student> Students; 
        deque <Student> Winners;
        deque <Student> Losers;
        AutomaticOrManual(Students, isAverage);
        if (strategy == 2 || strategy == 3) PreGroup(Students, Winners, strategy);
        else Group(Students, Winners, Losers);
        sort(Students.begin(), Students.end(), CompareLastNames());
        sort(Losers.begin(), Losers.end(), CompareLastNames());
        sort(Winners.begin(), Winners.end(), CompareLastNames());
        if (strategy == 2 || strategy == 3)PrePrint(isAverage, Winners, Students);
        else PrePrint(isAverage, Winners, Losers);
    }
    else if (container == 2) 
    {
        list <Student> Students;
        list <Student> Winners; 
        list <Student> Losers;
        AutomaticOrManual(Students, isAverage);
        if (strategy == 2 || strategy == 3) PreGroup(Students, Winners, strategy);
        else Group(Students, Winners, Losers);
        Students.sort(CompareLastNames());
        Winners.sort(CompareLastNames());
        Losers.sort(CompareLastNames());
        if (strategy == 2 || strategy == 3)PrePrint(isAverage, Winners, Students);
        else PrePrint(isAverage, Winners, Losers);
    }
    else if (container == 3)
    {
        vector <Student> Students;
        vector <Student> Winners;
        vector <Student> Losers;
        AutomaticOrManual(Students, isAverage);
        if (strategy == 2 || strategy == 3) PreGroup(Students, Winners, strategy);
        else Group(Students, Winners, Losers);
        sort(Students.begin(), Students.end(), CompareLastNames());
        sort(Losers.begin(), Losers.end(), CompareLastNames());
        sort(Winners.begin(), Winners.end(), CompareLastNames());
        if (strategy == 2 || strategy == 3)PrePrint(isAverage, Winners, Students);
        else PrePrint(isAverage, Winners, Losers);
    }
}

bool IsAverage()
{
    bool isAverage;
    cout << "Do you want the final grade to be mean (average)? (y/n) ";
    if (Confirm()) isAverage = true;
    else isAverage = false;
    return isAverage;
}

template <class T>
void Manual(long int &s, T &Students, bool isAverage)
{
    cout << "Do you want to enter the number of students? (y/n) ";
    if (Confirm())
    {
        s = CorrectNumber("Enter the number of students: ");
        ManualInput(s, Students, isAverage);
    }
    else UnknownInput(++s, Students, isAverage);
}


template <class T>
void Automatic(long int &s, T &Students, bool isAverage)
{
    cout << endl << "> Choose file:" << endl
        << "1. kursiokai1000.txt" << endl
        << "2. kursiokai10000.txt" << endl
        << "3. kursiokai100000.txt" << endl
        << "4. kursiokai1000000.txt" << endl
        << "5. kursiokai10000000.txt" << endl;

    int fileSize = CorrectNumber("Enter number: ", 5, 1, false);
    if (fileSize == 1) s = 1000;
    else if (fileSize == 2) s = 10000;
    else if (fileSize == 3) s = 100000;
    else if (fileSize == 4) s = 1000000;
    else if (fileSize == 5) s = 10000000;

    cout << endl << "> Using kursiokai" + to_string(s) + ".txt" << endl;
    GenerateStudent(s);
    InputFiles(Students, "kursiokai" + to_string(s) + ".txt", isAverage);
}

template <class T>
void PrePrint(bool isAverage, T Winners, T Losers)
{
    if (isAverage)
    {
        Print(Winners, Winners.size(), outputAverage, "Winners");
        Print(Losers, Losers.size(), outputAverage, "Losers");
    }
    else
    {
        Print(Winners, Winners.size(), outputMedian, "Winners");
        Print(Losers, Losers.size(), outputMedian, "Losers");
    }
}

template <class T>
void AutomaticOrManual(T &Students, bool isAverage)
{
    long int s = 0;
    cout << "Do you want to enter data manually? (y/n) ";
    if (Confirm()) Manual(s, Students, isAverage);
    else Automatic(s, Students, isAverage);
}

// 2,3
template <class T>
void PreGroup(T&Students, T&Winners, int strategy)
{
    if(strategy == 2) Group(Students, Winners);
    else Group(Students, Winners, true);
}

//1
template <class T>
void Group(T& Students, T& Winners, T& Losers)
{
    start = std::chrono::steady_clock::now();

    copy_if(Students.begin(), Students.end(), back_inserter(Winners), [](Student const& S) {return S.getFinalGrade() >= 5; });
    copy_if(Students.begin(), Students.end(), back_inserter(Losers), [](Student const& S) {return S.getFinalGrade() < 5; });

    double end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() / 1000.0;
    cout << "Time taken to group students: " << fixed << setprecision(4) << end << " s" << endl;
}


//2
template <class T>
void Group(T& Students, T& Winners)
{
    start = std::chrono::steady_clock::now();
    copy_if(Students.begin(), Students.end(), back_inserter(Winners), [](Student const& S) {return S.getFinalGrade() >= 5; });
    Students.erase(remove_if(Students.begin(), Students.end(), [](Student const& S) {return S.getFinalGrade() >= 5; }), Students.end());
    double end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() / 1000.0;
    cout << "Time taken to group students: " << fixed << setprecision(4) << end << " s" << endl;
}

//3
template <class T>
void Group(T& Students, T& Winners, bool temp)
{
    start = std::chrono::steady_clock::now();
    auto it = stable_partition(Students.begin(), Students.end(), [](Student const& S) {return S.getFinalGrade() < 5;});
    Winners.assign(it, Students.end());
    Students.erase(it, Students.end());
    double end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() / 1000.0;
    cout << "Time taken to group students: " << fixed << setprecision(4) << end << " s" << endl;

}


