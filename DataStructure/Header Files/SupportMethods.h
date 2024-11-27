#pragma once
#include <iostream>
#include <string>
using namespace std;

//! \brief Display main menu
void ShowMainMenu();

//! \brief Prompts the user for input and retrieves an integer value.
//! \param prompt A string containing the text of the prompt to display to 
//! the user.
//! \return The integer value entered by the user.
int GetInput(const string& prompt);

//! \brief Clear any menu
void ClearScreen();

void ContinueCheck();