#include "functions.hpp"

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

int main()
{
    cout << endl << "> Choose container:" << endl
        << "1. Deque" << endl
        << "2. List" << endl
        << "3. Vector" << endl;

    int container = CorrectNumber("Enter number: ", 3, 1, false);
    Container(container);
    
    WINPAUSE;
}
