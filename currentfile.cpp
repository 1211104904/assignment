#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L | TT4L | TT4L
// Names: Emeer Aneeq | Fateena | Nur Ayu Farisha
// IDs: 1211104904 | 1211307542 | 1211101924
// Emails: 1211104904@student.mmu.edu.my | 1211307542@student.mmu.edu.my | 1211101924@student.mmu.edu.my
// Phones: 0168644614 | 0176006405 | 0136001359
// *********************************************************

// function to create the game board
vector<vector<string>> boardGen()
{
    int row, column, zombies;

    while (true)
    {
        cout << "How many rows?: ";
        cin >> row;
        if (row % 2 != 0 && row > 0)
        {
            break;
        }
        else
        {
            cout << "Odd number only!" << endl;
        }
    }

    while (true)
    {
        cout << "How many columns?: ";
        cin >> column;
        if (column % 2 != 0 && column > 0)
        {
            break;
        }
        else
        {
            cout << "Odd number only!" << endl;
        }
    }

    while (true)
    {
        cout << "How many zombies?: ";
        cin >> zombies;
        if (zombies >= 0 && zombies <= (row * column) / 2)
        {
            break;
        }
        else
        {
            cout << "Invalid number of zombies" << endl;
        }
    }

    vector<vector<string>> board(row, vector<string>(column, " ")); // initialize all elements to " "

    // define your own array of single characters
    vector<string> contents = {"^", "<", ">", "v", "h", "p", "r", " "};

    // create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, contents.size() - 1);

    // randomly select cells to place the zombies
    for (int i = 0; i < zombies; i++)
    {
        int r, c;
        do
        {
            r = dis(gen) % row;
            c = dis(gen) % column;
        } while (board[r][c] != " ");
        board[r][c] = "Z";
    }

    // loop through each remaining cell and randomly select a character from the array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (board[i][j] == " ")
            {
                int idx = dis(gen);
                board[i][j] = contents[idx];
            }
        }
    }

    return board;
}

class Objects
{
public:
    string characters;
    string life;
    string attack;
    string range;
    int lifeValue;
    int attackValue;
    int rangeValue;
};
// function to change the direction of an arrow on the game board
void changeArrowDirection(vector<vector<string>> &gameboard)
{
    int row, col;

    while (true)
    {
        cout << "Enter the row of the arrow you want to change (0-" << gameboard.size() - 1 << "): ";
        cin >> row;

        if (row >= 0 && row < gameboard.size())
        {
            break;
        }
        else
        {
            cout << "Invalid row!" << endl;
        }
    }

    while (true)
    {
        cout << "Enter the column of the arrow you want to change (0-" << gameboard[0].size() - 1 << "): ";
        cin >> col;

        if (col >= 0 && col < gameboard[0].size())
        {
            break;
        }
        else
        {
            cout << "Invalid column!" << endl;
        }
    }

    string newDirection;
    while (true)
    {
        cout << "Enter the new direction of the arrow (^, v, <, >): ";
        cin >> newDirection;

        if (newDirection == "^" || newDirection == "v" || newDirection == "<" || newDirection == ">")
        {
            break;
        }
        else
        {
            cout << "Invalid direction!" << endl;
        }
    }

    gameboard[row][col] = newDirection;
}

// modified function to display the game board with an option to change the direction of an arrow
void displayBoard(vector<vector<string>> &gameboard, int aRow, int aCol)
{
    int row = gameboard.size();
    int column = gameboard[0].size();

    // loop through each cell and print the corresponding character
    cout << "" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == aRow && j == aCol)
            {
                cout << "| A ";
            }
            else
            {
                cout << "| " << gameboard[i][j] << " ";
            }
        }
        cout << "|" << endl;
    }

    // prompt the user to change the direction of an arrow
    string changeDirection;
    while (true)
    {
        cout << "\nDo you want to change the direction of an arrow? (y/n): ";
        cin >> changeDirection;

        if (changeDirection == "y")
        {
            changeArrowDirection(gameboard);
        }
        else if (changeDirection == "n")
        {
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }
    Objects objectsObj1;
    objectsObj1.characters = "\n-> Alien  :";
    objectsObj1.life = "Life";
    objectsObj1.lifeValue = 100;
    objectsObj1.attack = "Attack";
    objectsObj1.attackValue = 0;

    Objects objectsObj2;
    objectsObj2.characters = "  Zombie 1:";
    objectsObj2.life = "Life";
    objectsObj2.attack = "Attack";
    objectsObj2.range = "Range";

    Objects objectsObj3;
    objectsObj3.characters = "  Zombie 2:";
    objectsObj3.life = "Life";
    objectsObj3.attack = "Attack";
    objectsObj3.range = "Range";

    cout << objectsObj1.characters << " " << objectsObj1.life << " " << objectsObj1.lifeValue << " " << objectsObj1.attack << " " << objectsObj1.attackValue << "\n";

    srand((unsigned)time(NULL));

    // Loop to get 2 random numbers
    for (int i = 2; i <= 2; i++)
    {
        // Retrieve a random number between 100 and 250
        int random = 100 + (rand() % 150);
        int random1 = 100 + (rand() % 150);
        int random2 = 1 + (rand() % 20);
        int random3 = 1 + (rand() % 20);
        int random4 = 1 + (rand() % 5);
        int random5 = 1 + (rand() % 5);

        objectsObj2.lifeValue = random;
        objectsObj2.attackValue = random2;
        objectsObj2.rangeValue = random4;
        objectsObj3.lifeValue = random1;
        objectsObj3.attackValue = random3;
        objectsObj3.rangeValue = random5;
    }
    cout << objectsObj2.characters << " " << objectsObj2.life << " " << objectsObj2.lifeValue << " " << objectsObj2.attack << " " << objectsObj2.attackValue << " " << objectsObj2.range << " " << objectsObj2.rangeValue << "\n";
    cout << objectsObj3.characters << " " << objectsObj3.life << " " << objectsObj3.lifeValue << " " << objectsObj3.attack << " " << objectsObj3.attackValue << " " << objectsObj3.range << " " << objectsObj3.rangeValue << "\n";
}

// function to handle movement of the "A" character
void moveA(vector<vector<string>> &gameboard, int &aRow, int &aCol, string direction)
{
    if (direction == "up" && aRow > 0)
    {
        aRow--;
    }
    else if (direction == "down" && aRow < gameboard.size() - 1)
    {
        aRow++;
    }
    else if (direction == "left" && aCol > 0)
    {
        aCol--;
    }
    else if (direction == "right" && aCol < gameboard[0].size() - 1)
    {
        aCol++;
    }
    else
    {
        cout << "Invalid direction" << endl;
    }
}


int main()
{
    cout << "" << endl;
    cout << "[=========================]" << endl;
    cout << "[|--/ALIEN---------------|]" << endl;
    cout << "[|--------VERSUS---------|]" << endl;
    cout << "[|--------------ZOMBIE/--|]" << endl;
    cout << "[=========================]" << endl;
    cout << "" << endl;

    vector<vector<string>> start = boardGen();
    int aRow = start.size() / 2;
    int aCol = start[0].size() / 2;

    displayBoard(start, aRow, aCol);

    while (true)
    {
        bool valid_input = false;
        string input;
        while (!valid_input)
        {
            cout << "\nEnter command (up/down/left/right/help/save/load/q): " << endl;
            cin >> input;

            if (input == "q")
            {
                return 0;
            }
            else if (input == "up")
            {
                if (aRow > 0)
                {
                    aRow--;
                    valid_input = true;
                }
                else
                {
                    cout << "Cannot move up. You're at the top border." << endl;
                }
            }
            else if (input == "down")
            {
                if (aRow < start.size() - 1)
                {
                    aRow++;
                    valid_input = true;
                }
                else
                {
                    cout << "Cannot move down. You're at the bottom border." << endl;
                }
            }
            else if (input == "left")
            {
                if (aCol > 0)
                {
                    aCol--;
                    valid_input = true;
                }
                else
                {
                    cout << "Cannot move left. You're at the left border." << endl;
                }
            }
            else if (input == "right")
            {
                if (aCol < start[0].size() - 1)
                {
                    aCol++;
                    valid_input = true;
                }
                else
                {
                    cout << "Cannot move right. You're at the right border." << endl;
                }
            }
            else if (input == "save")
            {
                string save, key;
                cout << "Enter the file name to save the current game:";
                cin >> save;
                cout << "Game Saved" << endl;
                cout << "Press any key to continue. . ." << endl;
                cin >> key;
            }
            else if (input == "load")
            {
                string load, key;
                cout << "Do you want to save the current game? (y/n)";
                cin >> load;
                if (load == "y")
                {
                    cout << "Enter the file name to save the current game:";
                    cin >> load;
                    cout << "Game saved." << endl;
                    cout << "Press any key to continue. . .";
                    cin >> key;
                    cout << "Enter file name to load:";
                    cin >> key;
                    cout << "Game loaded." << endl;
                    cout << "Press any key to continue. . .";
                    cin >> key;
                }
                if (load == "n")
                {
                    cout << "Enter the file name to load:";
                    cin >> load;
                    cout << "Game loaded." << endl;
                    cout << "Press any key to continue. . .";
                    cin >> key;
                }
            }
            else if (input == "quit")
            {
                string quit;
                cout << "Are you sure? (y/n):";
                cin >> quit;
                if (quit == "y")
                {
                    cout << "Goodbye!";
                }
                return 0;
            }
            else if (input == "help")
            {
                cout << "\nCommands: " << endl;
                cout << "up - move the character up" << endl;
                cout << "down - move the character down" << endl;
                cout << "left - move the character left" << endl;
                cout << "right - move the character right" << endl;
                cout << "help - display list of commands and instructions" << endl;
                cout << "save - save the game onto a file" << endl;
                cout << "load - loads game from a file onto the board" << endl;
                cout << "q - quit the game" << endl;
            }
            else
            {
                cout << "Invalid input." << endl;
            }
        }

        displayBoard(start, aRow, aCol);
    }

    return 0;
}