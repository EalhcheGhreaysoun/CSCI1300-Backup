/*
notes:
advisors start at 0
path is 0 or 1

for setPlayerValue: 0 = name, 1 = age, 2 = strength, 3 = stamina, 4 = wisdom, 5 = pridepoints, 6 = advisor, 7 = path

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

int printMenu(){
    bool flag = true;
    char in;
    int n = -1;

    while(flag){
        cout << "Main Menu: Select an option to continue" << endl;
        cout << "1. Check Player Progress (1)" << endl;
        cout << "2. Review Character (2)" << endl;
        cout << "3. Check Position (3)" << endl;
        cout << "4. Review your Advisor (4)" << endl;
        cout << "5. Move Forward (5)" << endl;
        cout << "Please choose an option using the corresponding number: ";

        cin >> in;
        n = in - '0';

        if(n < 1 || n > 5){
            cout << "Not an option." << endl;
        }else{
            flag = false;
        }
    }
    return n;
}

int main(){
    Board board(2);

    //strings and streams
    ifstream Characters;
    ifstream Advisors;
    string line;
    string element;

    int moveDistance;
    char currentColor = ' ';

    //flags
    bool playing = true;
    bool isTurn = true;
    bool flag = true;
        
    //input
    char in;
    int n = -1;

    //character setting
    string temp_name;
    int temp_age;
    int temp_strength;
    int temp_stamina;
    int temp_wisdom;
    int temp_pridePts;
    int a;

    //choosing characters
    for (int i = 0; i < 2; i++){
        Characters.open("files/characters.txt");
        //start test
        stringstream s;
        //while no valid input has been given
        while(flag){
            cout << "Player " << i + 1 << " choose a character:" << endl;
            //loop through file
            for(int k = 0; k < 5; k++){
                getline(Characters, line);
                s.str(line);
                cout << "(" << k + 1 << ") ";
                for(int j = 0; j < 6; j++){
                    getline(s, element, '|');
                    switch (j)
                    {
                        case 0:
                            cout << "Name: " << element;
                            break;
                        case 1:
                            cout << ", Age: " << element;
                            break;
                        case 2:
                            cout << ", Strength: " << element;
                            break;
                        case 3:
                            cout << ", Stamina: " << element;
                            break;
                        case 4:
                            cout << ", Wisdom: " << element;
                            break;
                        case 5:
                            cout << ", Pride Points: " << element;
                            break;
                        default:
                            cout << "default" << endl;
                            break;
                    }
                }
                cout << endl;
            }

            cin >> in;
            n = in - '0';

            if(n < 1 || n > 5){
                cout << "Not an option." << endl;
            }else{
                flag = false;
            }
        }
        flag = true;
        Characters.clear();
        Characters.seekg(0);

        //get desired character line
        for(int k = 0; k < n; k++){
            getline(Characters, line);
        }
        
        s.str(line);
        for(int k = 0; k < 6; k++){
            getline(s, element, '|');
            switch (k)
            {
            case 0:
                temp_name = element;
                break;
            case 1:
                temp_age = stoi(element);
                break;
            case 2:
                temp_strength = stoi(element);
                break;
            case 3:
                temp_stamina = stoi(element);
                break;
            case 4:
                temp_wisdom = stoi(element);
                break;
            case 5:
                temp_pridePts = stoi(element);
                break;
            default:
                break;
            }
        }
        
        Characters.clear();
        Characters.seekg(0);
        Characters.close();

        board.player[i].name = temp_name;
        board.player[i].age = temp_age;
        board.player[i].strength = temp_strength;
        board.player[i].stamina = temp_stamina;
        board.player[i].wisdom = temp_wisdom;
        board.player[i].pridePts = temp_pridePts;

        cout << "Player " << i + 1 << " is: " << board.player[i].name << " and is " << board.player[i].age << " years old, with " << board.player[i].strength << " strength, " << board.player[i].stamina << " stamina, " << board.player[i].wisdom << " wisdom, and " << board.player[i].pridePts << " pride points." << endl;

        while(flag){
            cout << "Choose one of the paths below:" << endl;
            cout << "(1) Cub Training" << endl;
            cout << "(2) Straight to the pride lands" << endl;
            cin >> in;
            n = in - '0';
            if(n == 1 || n == 2){
                flag = false;
            }else{
                cout << "Not an option." << endl;
            }
        }
        flag = true;
        Advisors.open("files/advisors.txt");
        if(n == 1){ // cub training
            
            Advisors.clear();
            Advisors.seekg(0);
            while(flag){
                cout << "Choose an advisor from the list below:" << endl;
                for(int i = 0; i < 5; i++){
                    getline(Advisors, line);
                    cout << line << endl;
                }
                cin >> in;
                a = in - '0';
                if(a < 1 || a > 5){
                    cout << "Not an option." << endl;
                }else{
                    flag = false;
                }
            }
            flag = true;
            
            

            board.player[i].pridePts -= 5000;
            board.player[i].stamina += 500;
            board.player[i].strength += 500;
            board.player[i].wisdom += 1000;

            board.player[i].advisor = a-1;
            
            board.setPlayerPath(i, 0);
            
        }else if(n == 2){ // straight to the pride lands
            board.player[i].pridePts += 5000;
            board.player[i].stamina += 200;
            board.player[i].strength += 200;
            board.player[i].wisdom += 200;

            board.player[i].advisor = -1;

            board.setPlayerPath(i, 1);
        }else{
            cout << "something has gone terribly wrong" << endl;
            return 100;
        }
        Advisors.close();
    }

    // core game loop
    while(playing){
        for(int i = 0; i < 2; i++){
            isTurn = true;
            while(isTurn){
                board.displayBoard();
                cout << "Player " << i + 1 << "'s turn." << endl;
                switch (printMenu())
                {
                case 1:
                    cout << "Player " << i + 1 << " is " << board.player[i].name << " with " << board.player[i].strength << " strength, " << board.player[i].stamina << " stamina, " << board.player[i].wisdom << " wisdom, and " << board.player[i].pridePts << " pride points." << endl;
                    break;
                case 2:
                    cout << "Player " << i + 1 << " is " << board.getPlayerName(i) << " and is " << board.getPlayerAge(i) << " years old." << endl;
                    break;
                case 3:
                    board.displayBoard();
                    break;
                case 4:
                    if(board.getPlayerAdvisor(i) >= 0){
                        cout << "Your advisor is ";
                        for(int i = 0; i < board.getPlayerAdvisor(i); i++){
                            getline(Advisors, line);
                        }
                        getline(Advisors, line);
                        cout << line << endl;
                        Advisors.clear();
                        Advisors.seekg(0);
                    }else{
                        cout << "You do not have an advisor." << endl;
                    }
                    break;
                case 5:
                    srand(time(0));
                    moveDistance = (rand()%5)+1;
                    cout << "Moving " << moveDistance << " tiles." << endl;
                    board.movePlayer(i, moveDistance);
                    isTurn = false;
                    break;
                
                default:
                    cout << "something terrible has occured!" << endl;
                    break;
                }
            }

            // currentColor = board.getTile(board.getPlayerPath(i), board.getPlayerPosition(i));
            currentColor = 'P';

            switch (currentColor)
            {
            case 'R': // red
                cout << "Uh-oh, you've stumbled into the Graveyard! You move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points." << endl;
                if(board.getPlayerPosition(i) - 10 < 0){
                    board.movePlayer(i, -board.getPlayerPosition(i));
                }else{
                    board.movePlayer(i, -(board.getPlayerPosition(i)-10));
                }
                board.player[i].stamina -= 100;
                board.player[i].strength -= 100;
                board.player[i].wisdom -= 100;
                break;
            case 'G': // green
                /* code */
                break;
            case 'B': // blue
                cout << "You've found a peaceful oasis! You are granted an extra turn to keep moving forward and gain 200 Stamina, Strength, and Wisdom Points." << endl;
                isTurn = true;
                board.player[i].stamina += 200;
                board.player[i].strength += 200;
                board.player[i].wisdom += 200;
                break;
            case 'U': // purple
                /* code */
                break;
            case 'N': // brown
                cout << "The Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost. In addition, your Stamina Points decrease by 300 Points." << endl;
                board.movePlayer(i, -moveDistance);
                board.player[i].stamina -= 300;
                break;
            case 'P': // pink
                Advisors.open("files/advisors.txt");
                while(flag){
                    cout << "Choose a new advisor from the list below:" << endl;
                    cout << "(0) Keep previous advisor" << endl;
                    while(getline(Advisors, line)){
                        cout << line << endl;
                    }
                    cin >> in;
                    n = in -'0';
                    if(n < 0 || n > 5){
                        cout << "Not an option." << endl;
                    }else{
                        flag = false;
                    }
                    Advisors.clear();
                    Advisors.seekg(0);
                }
                if(n == 0){
                    cout << "Keeping the same advisor." << endl;
                }else{
                    board.player[i].advisor = n;
                }
                Advisors.close();
                break;
            
            default:
                break;
            }
        }
    }
}