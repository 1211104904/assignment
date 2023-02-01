#include <iostream>
using namespace std;

// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L | TT4L
// Names: Emeer Aneeq | Fateena | Nur Ayu Farisha
// IDs: 1211104904 | 1211307542 | 1211101924
// Emails: 1211104904@student.mmu.edu.my | 1211307542@student.mmu.edu.my | 1211101924@student.mmu.edu.my
// Phones: 0168644614 | 0176006405 | 0136001359
// *********************************************************


// ------------------------------------------------------------------
// THIS FILE IS ONLY TO PREVIEW A PROTOTYPE MOVEMENT OF THE ALIEN!!!
// ------------------------------------------------------------------

struct GridObject{
    int x; // variables for putting alien on grid
    int y;
};

struct Grid{

    int totalX; // variables for the grid
    int totalY;

    void Render(GridObject obj){
        for(int row = 1; row <= totalX; row++){
            for(int col = 1; col <= totalY; col++){
                if(obj.x == row && obj.y == col){
                    cout << "A ";
                }
                else{
                    std::cout << ". ";
                }
            }
        std::cout << std::endl;
            }
    }
};

struct PlayerInput{

    std::string yourString;

    char GetInput(){
        std::cout << "say something: ";
        std::cin >> yourString;

        std::cout << std::endl;
        std::cout << "you said:" << yourString << std::endl;
        std::cout << "first letter: " << yourString[0] << std::endl; // yourString[0] meaning dia read first letter of the string je 

        std::cin.clear(); // to clear errors
        
        std::cout << std::endl;

        return yourString[0]; 
    }
};

int main(){
    Grid grid; // grid itself
    grid.totalX = 11;
    grid.totalY = 11;

    GridObject obj; //Alien on the center when start board
    obj.x = 6;
    obj.y = 6;


    PlayerInput playerInput; //accepts inputs such as 'u','l','r','d'
    char input = '0';

    while(input != 'q'){
        grid.Render(obj);

        input = playerInput.GetInput(); // takes input from user input

        if(input == 'u'){ //up
            obj.x -= 1;
        }
        else if(input == 'l'){ //left
            obj.y -= 1;
        }
        else if(input == 'r'){ //right
            obj.y += 1;
        }
        else if(input == 'd'){ //down
            obj.x += 1;
        }
        
    }
}