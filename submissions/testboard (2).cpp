#include <string.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

int Zombie;
int row;
int column;
vector<vector<string>> gridbox;

void Command()
{
    cout << "1. up     - Move up." << endl;
    cout << "2. down   - Move down." << endl;
    cout << "3. left   - Move left." << endl;
    cout << "4. right  - Move right." << endl;
    cout << "5. arrow  - Change the direction of an arrow." << endl;
    cout << "6. help   - Display these user commands." << endl;
    cout << "7. save   - Save the game." << endl;
    cout << "8. load   - Load the game." << endl;
    cout << "9. quit   - Quit the game" << endl;
}

void randomObject()
{
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int randomIndex = rand() % 12;
            string objects[] = {"h", "<", ">", "v", "^", "r", "p", " ", " ", " ", " ", " "};
            gridbox[i][j] = "[" + objects[randomIndex] + "]";

            // alien at center
            int Rowalien = row / 2;
            int Colalien = column / 2;
            gridbox[Rowalien][Colalien] = "[A]";
        }
    }
}

void zombie()
{
    for (int i = 0; i < Zombie; i++)
    {
        int zombieRow = rand() % row;
        int zombieCol = rand() % column;
        gridbox[zombieRow][zombieCol] = "[Z]";
    }
}

int main()
{
    int Zombie;

    cout << "Default Game Setting" << endl;
    cout << "--------------------" << endl;
    cout << "Board Rows     : 5" << endl;
    cout << "Board Collums  : 9" << endl;
    cout << "Zombie         : 1" << endl;
    cout << "--------------------" << endl;

    string gameSetting;
    cout << "Do you want to change setting?(y/n) ";
    cin >> gameSetting;
    


    if (gameSetting == "y")
    {
        cout << "Board Setting" << endl;
        cout << "-------------" << endl;
        cout << "Please enter odd number only" << endl;
        cout << "Enter row => ";
        cin >> row;
        while (row % 2 == 0 || row > 50)
        {
            cout << "Please enter odd number or lower than 50 only ^_^" << endl;
            cout << "Enter row => ";
            cin >> row;
        }
        cout << "Enter column => ";
        cin >> column;
        while (column % 2 == 0 || column > 50)
        {
            cout << "Please enter odd number or lower than 50 only ^_^" << endl;
            cout << "Enter column => ";
            cin >> column;
        }
        cout << "How many zombie => ";
        cin >> Zombie;
        while (Zombie > 9)
        {
            cout << "Zombie are allowed lower than 9 only ^_^" << endl;
            cout << "How many zombie => ";
            cin >> Zombie;
        }
        int table[row][column];

        for (int i = 0; i < row; i++)
        {
            vector<string> row;
            for (int j = 0; j < column; j++)
            {
                if (j == 0)
                    row.push_back("[ ]");
                else
                    row.push_back("[ ]");
            }
            gridbox.push_back(row);
        }

        randomObject();
        zombie();
        
        // printing gridbox
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << gridbox[i][j].c_str();
            }
            cout << endl;
        }
    }

    if (gameSetting == "n")
    {
        int row = 5;
        int column = 9;
        int Zombie = 1;
        int table[row][column];

        for (int i = 0; i < row; i++)
        {
            vector<string> row;
            for (int j = 0; j < column; j++)
            {
                if (j == 0)
                    row.push_back("[ ]");
                else
                    row.push_back("[ ]");
            }
            gridbox.push_back(row);
        }

        // initializing random
        srand(time(0));
    

        // random objects
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                int randomIndex = rand() % 10;
                string objects[] = {"h", "<", ">", "v", "^", "r", "p", " ", " ", " "};
                gridbox[i][j] = "[" + objects[randomIndex] + "]";

                // alien at center
                int Rowalien = row / 2;
                int Colalien = column / 2;
                gridbox[Rowalien][Colalien] = "[A]";
            }
        }

        // zombies
        for (int i = 0; i < Zombie; i++)
        {
            int zombieRow = rand() % row;
            int zombieCol = rand() % column;
            gridbox[zombieRow][zombieCol] = "[Z]";
        }

        // printing gridbox
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << gridbox[i][j].c_str();
            }

            cout << endl;
        }
    }

    string command;
    cout << "command => ";
    cin >> command;

    if (command == "help")
    {
        Command();
    }

    else
    {
        cout << "invalid";
    }
}
