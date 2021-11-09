//---------------------------------------------------
// Purpose: Implement menu-based spreadsheet program.
// Author:  Cody Lowery
//---------------------------------------------------

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 9;
const int COLS = 9;

//---------------------------------------------------
// Read and convert location string to row col value
//---------------------------------------------------
void get_location(int& row, int& col)
{
    // Initialize variables
    row = -1;
    col = -1;

    // Loop until a valid location is entered
    while (row < 0 || row > ROWS - 1 || col < 0 || col > COLS - 1)
    {
        // Get user input
        cout << "Enter location between A1 and I9: " << endl;
        string location = "";
        cin >> location;

        // Calculate col between 0 and COLS-1
        if (location.length() > 0)
            col = location[0] - 'A';

        // Print error message
        if (col < 0 || col > COLS - 1)
            cout << "Error: column should be between A and I" << endl;

        // Calculate row between 0 and ROWS-1
        if (location.length() > 1)
            row = location[1] - '1';

        // Print error message
        if (row < 0 || row > ROWS - 1)
            cout << "Error: row should be between 1 and 9" << endl;
    }
}

//---------------------------------------------------
// Print command menu to user and get input
//---------------------------------------------------
int get_menu_choice()
{
    // Print command menu
    cout << "Welcome to MiniCalc the PF1 Killer App\n"
        << "   0) Quit the program\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate product of data values\n"
        << "   7) Calculate average of data values\n"
        << "   8) Calculate standard deviation of data values\n";

    // Initialize variables
    string input = "";
    int command = -1;

    // Loop until a valid location is entered
    while (command < 0 || command > 8)
    {
        // Get user input
        cout << "Enter command: ";
        cin >> input;
        if (input.length() == 1)
            command = input[0] - '0';

        // Print error message
        if (command < 0 || command > 8)
            cout << "Error: command should be between 0 and 8" << endl;
    }
    return command;
}

//print data table
void print(float data[ROWS][COLS])
{
    //Print values
    cout << "     ";
    for (int col = 0; col < COLS; col++)
        cout << char('A' + col) << "   ";
    cout << endl;

    //Print line
    cout << "   +";
    for (int col = 0; col < COLS; col++)
        cout << "---+";
    cout << "\n";

    //Print board
    for (int row = 0; row < ROWS; row++)
    {
        //Print values
        cout << " " << row + 1 << " | ";
        for (int col = 0; col < COLS; col++)
            cout << data[row][col] << " | ";
        cout << endl;

        //Print line
        cout << "   +";
        for (int col = 0; col < COLS; col++)
            cout << "---+";
        cout << "\n";
    }
}
//function to store specific value
void storeSpecific(float data[ROWS][COLS])
{
    float value;
    int row1, row2, col1, col2;

    cout << "What value do you want to store: ";
    cin >> value;

    cout << "Where do you want to store this value\n";
    get_location(row1, col1);
    get_location(row2, col2);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            data[row][col] = value;
        }
    }
}
void storeRandom(float data[ROWS][COLS])
{
    int maxValue, minValue, row1, row2, col1, col2;

    cout << "Choose a minimum value: ";
    cin >> minValue;
    cout << "Choose a maximum value: ";
    cin >> maxValue;

    cout << "Where do you want to store this value?  ";
    get_location(row1, col1);
    get_location(row2, col2);

   // srand(time(NULL));

    for (int row = row1; row <= row2; row++)
        for (int col = col1; col <= col2; col++)
            data[row][col] = rand() % maxValue + minValue;
}
void calcMinimum(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;

    cout << "Choose the range for the minimum: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the minimum: ";
    get_location(row3, col3);

    float min = data[row1][col1];

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            if (min > data[row][col])
            {
                min = data[row][col];
            }
        }
    }
    data[row3][col3] = min;
}
void calcMaximum(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;

    cout << "Choose a range for the maximum: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the maximum: ";
    get_location(row3, col3);
    
    float max = data[row1][col1];

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            if (max < data[row][col])
            {
                max = data[row][col];
            }
        }
    }
    data[row3][col3] = max;
}
void calc_sum(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;
    float sum = 0;

    cout << "Choose a range for the sum: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the sum: ";
    get_location(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            sum += data[row][col];
        }
    }
    data[row3][col3] = sum;
}
void calc_mult(float data[ROWS][COLS])
{
    int row1, row2, row3, col1, col2, col3;
    float mult = 1;

    cout << "Choose where to multiply from: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the product: ";
    get_location(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            mult = mult * data[row][col];
        }
    }
    data[row3][col3] = mult;
}
void calc_average(float data[ROWS][COLS])
{
    int i = 0, row1, row2, row3, col1, col2, col3;
    float sum = 0, average = 0;

    cout << "Choose where to average from: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the average: ";
    get_location(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            i++;
            sum += data[row][col];
        }
    }
    average = sum / i;
    data[row3][col3] = average;
}
void calc_standard(float data[ROWS][COLS])
{
    float sum = 0, standard = 0, mean;
    int i = 0, row1, row2, row3, col1, col2, col3;

    cout << "Choose the range for the deviation: ";
    get_location(row1, col1);
    get_location(row2, col2);

    cout << "Choose where to store the deviation: ";
    get_location(row3, col3);

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            i++;
            sum = sum + data[row][col];
        }
    }

    mean = sum / i;

    for (int row = row1; row <= row2; row++)
    {
        for (int col = col1; col <= col2; col++)
        {
            standard = pow(data[row][col] - mean, 2);
        }
    }
    data[row3][col3] = sqrt(standard / i);
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
    // Initialize spreadsheet array
    float data[ROWS][COLS];
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            data[row][col] = 0;

    // Loop processing menu commands
    int command = get_menu_choice();
    while (command != 0)
    {
        // TODO - ADD CODE HERE
        if (command == 1)
        {
            storeSpecific(data);
        }
        else if (command == 2)
        {
            storeRandom(data);
        }
        else  if (command == 3)
        {
            calcMinimum(data);
        }
        else  if (command == 4)
        {
            calcMaximum(data);
        }
        else  if (command == 5)
        {
            calc_sum(data);
        }
        else  if (command == 6)
        {
            calc_mult(data);
        }
        else  if (command == 7)
        {
            calc_average(data);
        }
        else if (command == 8)
        {
            calc_standard(data);
        }
        print(data);

        // Get next command
        command = get_menu_choice();
    }
    return 0;
}
