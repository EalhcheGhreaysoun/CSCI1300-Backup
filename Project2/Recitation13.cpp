#include "Board.h"
#include <iostream>

using namespace std;

void PrintMenu(){

    cout << "Main Menu: Select an option to continue" << endl;
    
    cout << "1. Check Player Progress (1)" << endl;
    
    cout << "2. Review Character (2)" << endl;
    
    cout << "3. Check Position (3)" << endl;
    
    cout << "4. Review your Advisor (4)" << endl;
    
    cout << "5. Move Forward (5)" << endl;
    
    cout << "Please choose an option using the corresponding number:" << endl;
}

int main(){
    Board board(2);
    char input;
    bool playing = true;
    bool isTurn = true;
    char currentTileColor= ' ';

    for (int i = 0; i < 2; i++){
        board.initializeBoard();
    }
    board.displayBoard();

    while(playing){
        for(int i = 0; i < 2; i++){
            isTurn = true;
            while(isTurn){
                cout << "player " << i+1 << " s turn" << endl;
                PrintMenu();
                cin >> input;

                switch (input)
                {
                case '1':
                    /* code */
                    break;
                case '2':
                    /* code */
                    break;
                case '3':
                    board.displayBoard();
                    break;
                case '4':
                    /* code */
                    break;
                case '5':
                    board.movePlayer(i);
                    isTurn = false;
                    break;
                
                default:
                    playing = false;
                    isTurn = false;
                    break;
                }
                board.displayBoard();
                currentTileColor = board.getTile(i, board.getPlayerPosition(i));

                switch (currentTileColor)
                {
                case 'B':
                    cout << "on a blue tile" << endl;
                    break;
                case 'P':
                    cout << "on a pink tile" << endl;
                    break;
                case 'N':
                    cout << "on a brown tile" << endl;
                    break;
                case 'R':
                    cout << "on a red tile" << endl;
                    break;
                case 'U':
                    cout << "on a purple tile" << endl;
                    break;
                case 'G':
                    cout << "on a green tile" << endl;
                    break;
                default:
                    break;
                }
                cout << endl;
            }
        }
    }
}