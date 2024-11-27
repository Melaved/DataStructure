#include <iostream>
#include <string>
using namespace std;

//! \brief Display main menu
void ShowMainMenu()
{
    cout << "Main Menu:\n";
    cout << "1. Stack\n";
    cout << "2. Circular Buffer\n";
    cout << "3. Queue from Circular Buffer\n";
    cout << "4. Queue from Stacks\n";
    cout << "0. Exit\n";
}

//! \brief Prompts the user for input and retrieves an integer value.
//! \param prompt A string containing the text of the prompt to display to 
//! the user.
//! \return The integer value entered by the user.
int GetInput(const string& prompt)
{
    int value;
    string input;

    while (true)
    {
        cout << prompt;
        getline(cin, input);

        try
        {
            value = stoi(input);
            return value;
        }
        catch (const invalid_argument& e)
        {
            cout << "Invalid input. Please enter an integer value.\n";
        }
        catch (const out_of_range& e)
        {
            cout << "Input is out of range. Please enter a valid integer value.\n";
        }
    }
}

//! \brief Clear any menu
void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ContinueCheck()
{
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}