#include "Board.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

string readNthLine(const string filename, int N){

    ifstream in(filename);

    string s;   
    //skip N lines
    for(int i = 0; i < N; ++i){
        getline(in, s);
    }
    getline(in,s);
    in.close();
    return s; 
}

int main(){
    char input;
    bool playing = true;
    bool isTurn = true;
    bool flag = true;
    char currentTileColor= ' ';
    string line;
    string element;
    string elementOut;
    int move_distance = 0;
    int randomLine;

    string temp_name;
    int temp_age;
    int temp_strength;
    int temp_stamina;
    int temp_wisdom;
    int temp_pridePts;

    ifstream fileIn;
    int row;
    int elem;
    int n;

    stringstream s;

    //character list output
    while(flag){
        fileIn.open("characters.txt");
        row = 0;
        cout << "Player 1:" << endl;
        cout << "Choose a character out of the following list." << endl;
        elem = 0;
        while(getline(fileIn, line)){
            if (row != 0){
                cout << row << ": ";
                stringstream s(line);
                elem = 0;
                while(getline(s, element, '|')){
                    switch (elem)
                    {
                    case 0:
                        cout << "Name: " << element << " ";
                        break;
                    case 1:
                        cout << "Age: " << element << " ";
                        break;
                    case 2:
                        cout << "Strength: " << element << " ";
                        break;
                    case 3:
                        cout << "Stamina: " << element << " ";
                        break;
                    case 4:
                        cout << "Wisdom: " << element << " ";
                        break;
                    case 5:
                        cout << "Pride Points: " << element << " ";
                        break;
                    default:
                        break;
                    }
                    elem++;
                }
                cout << endl;
            }
            row++;
        }
        cin >> input;
        n = input - '0';
        row = 0;
        if (n < 1 || n > 5){
            cout << "Not an option." << endl;
            fileIn.close();
        }else{
            flag = false;
            fileIn.close();
        }
    }
    flag = true;
    //end character list output

    //player 1 setting
    fileIn.open("characters.txt");
    //set player 1 to chosen character
    while(getline(fileIn, line)){
        if(row == (n)){
            stringstream a(line);
            elem = 0;
            while(getline(a, element, '|')){
                switch (elem)
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
                elem++;
            }
        }
        row++;
    }
    fileIn.close();
    Player player1(temp_name, temp_age, temp_strength, temp_stamina, temp_wisdom, temp_pridePts);
    //end player 1 setting

    //output player1 stats
    cout << "Player 1 is " << player1.getPlayerName() << " at age " << player1.getPlayerAge() << " with " << player1.getPlayerStrength() << " strength, " << player1.getPlayerStamina() << " stamina, " << player1.getPlayerWisdom() << " wisdom, and a starting " << player1.getPlayerPridePts() << " pride points" << endl;

    cout << endl;
    //end output player 1 stats

    //ask about which path to choose
    while(flag){
        fileIn.open("Advisor.txt");
        cout << "Which path do you want to take?" << endl;
        cout << "1. Cub Training" << endl;
        cout << "2. Straight to the Pride Lands" << endl;
        cin >> input;
        n = input - '0';
        if(n == 1 || n == 2){
            flag = false;
            fileIn.close();
        }else{
            cout << "Not a choice" << endl;
            fileIn.close();
        }
    }
    flag = true;
    if(n == 1){
        Board board1(1, 1);
        player1.setBoard(board1);
        player1.setPridePts(-5000);
        while(flag){
            fileIn.open("Advisor.txt");
            row = 0;
            cout << "Choose an advisor out of the following list." << endl;
            elem = 0;
            while(getline(fileIn, line)){
                    cout << line << endl;
                row++;
            }
            cin >> input;
            n = input - '0';
            row = 0;
            if (n < 1 || n > 5){
                cout << "Not an option." << endl;
                fileIn.close();
            }else{
                flag = false;
                fileIn.close();
            }
            fileIn.close();
        }
        player1.setAdvisor(n);
        flag = true;
    }else if(n == 2){
        Board board1(2, 1);
        player1.setBoard(board1);
        player1.setPridePts(5000);
        player1.setAdvisor(-1);
    }
    //end ask about which path to choose

    //character list output
    while(flag){
        fileIn.open("characters.txt");
        row = 0;
        cout << "Player 2:" << endl;
        cout << "Choose a character out of the following list." << endl;
        elem = 0;
        while(getline(fileIn, line)){
            if (row != 0){
                cout << row << ": ";
                stringstream s(line);
                elem = 0;
                while(getline(s, element, '|')){
                    switch (elem)
                    {
                    case 0:
                        cout << "Name: " << element << " ";
                        break;
                    case 1:
                        cout << "Age: " << element << " ";
                        break;
                    case 2:
                        cout << "Strength: " << element << " ";
                        break;
                    case 3:
                        cout << "Stamina: " << element << " ";
                        break;
                    case 4:
                        cout << "Wisdom: " << element << " ";
                        break;
                    case 5:
                        cout << "Pride Points: " << element << " ";
                        break;
                    default:
                        break;
                    }
                    elem++;
                }
                cout << endl;
            }
            row++;
        }
        cin >> input;
        n = input - '0';
        row = 0;
        if (n < 1 || n > 5){
            cout << "Not an option." << endl;
        }else{
            flag = false;
        }
        fileIn.close();
    }
    flag = true;
    //end character list output

    //player 2 setting
    fileIn.open("characters.txt");
    //set player 2 to chosen character
    while(getline(fileIn, line)){
        if(row == (n)){
            stringstream a(line);
            elem = 0;
            while(getline(a, element, '|')){
                switch (elem)
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
                elem++;
            }
        }
        row++;
    }
    Player player2(temp_name, temp_age, temp_strength, temp_stamina, temp_wisdom, temp_pridePts);
    //end player 2 setting

    //output player 2 stats
    cout << "Player 2 is " << player2.getPlayerName() << " at age " << player2.getPlayerAge() << " with " << player2.getPlayerStrength() << " strength, " << player2.getPlayerStamina() << " stamina, " << player2.getPlayerWisdom() << " wisdom, and a starting " << player2.getPlayerPridePts() << " pride points" << endl;

    cout << endl;
    //end output player 2 stats

    //ask about which path to choose
    while(flag){
        fileIn.open("Advisor.txt");
        cout << "Which path do you want to take?" << endl;
        cout << "1. Cub Training" << endl;
        cout << "2. Straight to the Pride Lands" << endl;
        cin >> input;
        n = input - '0';
        if(n == 1 || n == 2){
            flag = false;
        }else{
            cout << "Not a choice" << endl;
        }
        fileIn.close();
    }
    flag = true;
    if(n == 1){
        Board board2(1, 2);
        player2.setBoard(board2);
        player2.setPridePts(5000);
        while(flag){
            row = 0;
            cout << "Choose an advisor out of the following list." << endl;
            elem = 0;
            while(getline(fileIn, line)){
                    cout << line << endl;
                row++;
            }
            cin >> input;
            n = input - '0';
            row = 0;
            if (n < 1 || n > 5){
                cout << "Not an option." << endl;
            }else{
                flag = false;
            }
        }
        player2.setAdvisor(n);
        flag = true;
    }else if(n == 2){
        Board board2(2, 2);
        player2.setBoard(board2);
        player2.setPridePts(-5000);
        player2.setAdvisor(-1);
    }
    //end ask about which path to choose

    while(playing){
        for(int i = 0; i < 2; i++){
            isTurn = true;
            move_distance = 0;
            while(isTurn){
                //a player is at the end, skip turn
                if(i == 0 && player1.playerGetPlayerPos() >= 52){
                    isTurn = false;
                }else if(i == 1 && player2.playerGetPlayerPos() >= 52){
                    isTurn = false;
                }

                cout << "player " << i+1 << " s turn" << endl;
                if(i == 0){
                    player1.playerDisplayBoard();
                }else if(i == 1){
                    player2.playerDisplayBoard();
                }
                PrintMenu();
                cin >> input;

                // menu input switch case
                switch (input)
                {
                    case '1':
                        if (i == 0){
                            cout << "Player 1 has " << player1.getPlayerStrength() << " strength, " << player1.getPlayerStamina() << " stamina, " << player1.getPlayerWisdom() << " wisdom, and " << player1.getPlayerPridePts() << " pride points" << endl;
                        }
                        else if(i == 1){
                            cout << "Player 2 has " << player2.getPlayerStrength() << " strength, " << player2.getPlayerStamina() << " stamina, " << player2.getPlayerWisdom() << " wisdom, and " << player2.getPlayerPridePts() << " pride points" << endl;
                        }
                        break;
                    case '2':
                        if (i == 0){
                            cout << "Player 1 is " << player1.getPlayerName() << " and is " << player1.getPlayerAge() << " years old." << endl;
                        }
                        else if(1 == 1){
                            cout << "Player 2 is " << player2.getPlayerName() << " and is " << player2.getPlayerAge() << " years old." << endl;
                        }
                        break;
                    case '3':
                        if(i == 0){
                            player1.playerDisplayBoard();
                        }else if(i == 1){
                            player2.playerDisplayBoard();
                        }
                        break;
                    case '4':
                        if (i == 0){
                            cout << "Player 1's advisor is " << readNthLine("Advisor.txt", player1.getAdvisor()) << endl;
                        }
                        else if(i == 1){

                        }
                        break;
                    case '5':
                        srand(time(0));
                        move_distance = rand()%5+1;
                        //if both players are at the end, end game
                        if(player1.playerMovePlayer(move_distance) == true && player2.playerMovePlayer(move_distance) == true){
                            playing = false;
                        }
                        if(i == 0){
                            player1.playerMovePlayer(move_distance);
                            cout << "Moving " << move_distance << " tiles." << endl;
                            player1.playerDisplayBoard();
                            break;
                        }else if(i == 1){
                            player2.playerMovePlayer(move_distance);
                            cout << "Moving " << move_distance << " tiles." << endl;
                            player2.playerDisplayBoard();
                            break;

                        }
                        break;
                    
                    default://exit mode for testing
                        playing = false;
                        isTurn = false;
                        break;
                }

                if(i == 0){
                    currentTileColor = player1.playerGetTile(player1.playerGetPlayerPos());
                }else if(i == 1){
                    currentTileColor = player2.playerGetTile(player2.playerGetPlayerPos());
                }
                
                switch (currentTileColor)
                {
                    case 'B':
                        cout << "you've found a peaceful oasis! You are granted an extra turnas as well as 200 Stamina, Strength, and Wisdom Points" << endl;
                        if(n == 0){
                            player1.setPlayerStrength(200);
                            player1.setPlayerStamina(200);
                            player1.setPlayerWisdom(200);
                        }else if(n == 1){
                            player2.setPlayerStrength(200);
                            player2.setPlayerStamina(200);
                            player2.setPlayerWisdom(200);
                        }
                        break;
                    case 'P':
                        cout << "Welcome to the land of enrichment, your Stamina, Strength, and Wisdom Points are increased by 300, and you get to choose an advisor from the available list of advisors. If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor. Don't forget - an advisor can protect you from random events that negatively impact your Pride Points." << endl;
                        //set advisor
                        while(flag){
                            fileIn.open("Advisor.txt");
                            row = 0;
                            cout << "Choose an advisor out of the following list." << endl;
                            elem = 0;
                            while(getline(fileIn, line)){
                                    cout << line << endl;
                                row++;
                            }
                            cin >> input;
                            n = input - '0';
                            row = 0;
                            if (n < 1 || n > 5){
                                cout << "Not an option." << endl;
                                fileIn.close();
                            }else{
                                flag = false;
                                fileIn.close();
                            }
                        }
                        if(i == 0){
                            player1.setAdvisor(n);
                            player1.setPlayerStamina(300);
                            player1.setPlayerStrength(300);
                            player1.setPlayerWisdom(300);
                        }else if(i == 1){
                            player2.setAdvisor(n);
                            player2.setPlayerStamina(300);
                            player2.setPlayerStrength(300);
                            player2.setPlayerWisdom(300);
                        }
                        flag = true;
                        //end set advisors
                        isTurn = false; //end turn
                        break;
                    case 'N':
                        cout << "The Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost. In addition, the player's Stamina Points decrease by 300 Points." << endl;
                        if(i == 0){
                            player1.playerMovePlayer(-move_distance);
                            player1.setPlayerStamina(-300);
                            player1.playerDisplayBoard();
                        }else if(i == 1){
                            player2.playerMovePlayer(-move_distance);
                            player2.setPlayerStamina(-300);
                            player2.playerDisplayBoard();
                        }
                        isTurn = false;
                        break;
                    case 'R':
                        cout << "Uh-oh, you've stumbled into the Graveyard! You move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points." << endl;
                        if(i == 0){
                            player1.playerMovePlayer(-10);
                            player1.setPlayerStamina(300);
                            player1.setPlayerStrength(300);
                            player1.setPlayerWisdom(300);
                            player1.playerDisplayBoard();
                        }else if(i == 1){
                            player2.playerMovePlayer(-10);
                            player2.setPlayerStamina(300);
                            player2.setPlayerStrength(300);
                            player2.setPlayerWisdom(300);
                            player2.playerDisplayBoard();
                        }
                        isTurn = false;
                        break;
                    case 'U':
                        cout << "Time for a test of wits! Answer the following riddle, Answer correctly, and you'll earn a boost of 500 Points to your Wisdom Trait — your cleverness pays off!" << endl;
                        randomLine = rand()%28;
                        s << readNthLine("riddles.txt", randomLine);
                        getline(s, line, '|');
                        cout << line;
                        cin >> element;
                        getline(s, line, '|');
                        cout << line << endl;
                        if(element == line){
                            cout << "You got it correct and earned 500 wisdom points!" << endl;
                            if(i == 0){
                                player1.setPlayerWisdom(500);
                            }else if(i == 1){
                                player2.setPlayerWisdom(500);
                            }
                        }else{
                            cout << "That is incorrect, sorry!" << endl;
                        }
                        isTurn = false;
                        break;
                    case 'G':
                        if ((rand() % 2) == 0){
                            cout << "You landed on a Savana tile. Nothing happens." << endl;
                        }else if((rand() % 2) == 1){
                            cout << "You landed on a savana tile. ";
                            s << readNthLine("random_events.txt", (rand() % 50)+1);
                            //description
                            getline(s, elementOut, '|');
                            cout << element << endl;
                            //path type
                            getline(s, element, '|');
                            if(i == 0){//player 1
                                if(stoi(element) == 0 && player1.getAdvisor() != -1){
                                    //advisor
                                    getline(s, element, '|');
                                    if (stoi(element) != 0 && stoi(element) == player1.getAdvisor()){
                                        cout << elementOut << " but you are protected by your advisor" << endl;
                                    }else if(stoi(element) != 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You lost " << stoi(element) * -1 << "Pride Points" << endl; 
                                        player1.setPridePts(stoi(element));
                                    }else if(stoi(element) == 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You gained " << element << " Pride Points" << endl;
                                        player1.setPridePts(stoi(element));
                                    }
                                }if(player1.getAdvisor() == -1){
                                    if(stoi(element) != 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You lost " << stoi(element) * -1 << "Pride Points" << endl; 
                                        player1.setPridePts(stoi(element));
                                    }else if(stoi(element) == 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You gained " << element << " Pride Points" << endl;
                                        player1.setPridePts(stoi(element));
                                    }
                                }
                            } else if(i == 1){ //player 2
                                if(stoi(element) == 0 && player2.getAdvisor() != -1){
                                    //advisor
                                    getline(s, element, '|');
                                    if (stoi(element) != 0 && stoi(element) == player2.getAdvisor()){
                                        cout << elementOut << " but you are protected by your advisor" << endl;
                                    }else if(stoi(element) != 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You lost " << stoi(element) * -1 << "Pride Points" << endl; 
                                        player2.setPridePts(stoi(element));
                                    }else if(stoi(element) == 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You gained " << element << " Pride Points" << endl;
                                        player2.setPridePts(stoi(element));
                                    }
                                }if(player2.getAdvisor() == -1){
                                    if(stoi(element) != 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You lost " << stoi(element) * -1 << "Pride Points" << endl; 
                                        player2.setPridePts(stoi(element));
                                    }else if(stoi(element) == 0){
                                        cout << elementOut;
                                        //pride points
                                        getline(s, element, '|');
                                        cout << ". You gained " << element << " Pride Points" << endl;
                                        player2.setPridePts(stoi(element));
                                    }
                                }
                            }
                        }

                        isTurn = false;
                        break;

                    default:
                        break;
                }
                cout << endl;

            }
        }
    }
    //calculate player 1 score
    player1.setPridePts(1000 * ((player1.getPlayerStamina() + player1.getPlayerStrength() + player1.getPlayerWisdom())/100));

    //calculate player 2 score
    player2.setPridePts(1000 * ((player2.getPlayerStamina() + player2.getPlayerStrength() + player2.getPlayerWisdom())/100));

    ofstream gameStats;
    gameStats.open("gameStats.txt");
    gameStats << "Player 1 stats: \n";
    gameStats << "    Stamina: " << player1.getPlayerStamina() << "\n    Strength: " << player1.getPlayerStrength() << "\n    Wisdom: " << player1.getPlayerWisdom() << "\n final pride points: " << player1.getPlayerPridePts();

    gameStats << "Player 2 stats: \n";
    gameStats << "    Stamina: " << player2.getPlayerStamina() << "\n    Strength: " << player2.getPlayerStrength() << "\n    Wisdom: " << player2.getPlayerWisdom() << "\n final pride points: " << player2.getPlayerPridePts();

    if(player1.getPlayerPridePts() > player2.getPlayerPridePts()){
        cout << "Player 1, " << player1.getPlayerName() << ", won with " << player1.getPlayerPridePts() << " pride points." << endl;
        cout << player1.getPlayerName() << " had " << player1.getPlayerStamina() << " stamina points, " << player1.getPlayerStrength() << " strength points, and " << player1.getPlayerWisdom() << " wisdom points." << endl;
        gameStats << "Player 1 won.";
    }else if(player2.getPlayerPridePts() > player1.getPlayerPridePts()){
        cout << "Player 2, " << player2.getPlayerName() << ", won with " << player2.getPlayerPridePts() << " pride points." << endl;
        cout << player2.getPlayerName() << " had " << player2.getPlayerStamina() << " stamina points, " << player2.getPlayerStrength() << " strength points, and " << player2.getPlayerWisdom() << " wisdom points." << endl;
        gameStats << "Player 2 won.";
    }else if(player1.getPlayerPridePts() == player2.getPlayerPridePts()){
        cout << "the two players tied in points and there is no winner." << endl;
        cout << "Player 1 stats:" << endl;
        cout << player1.getPlayerName() << " had " << player1.getPlayerStamina() << " stamina points, " << player1.getPlayerStrength() << " strength points, and " << player1.getPlayerWisdom() << " wisdom points." << endl;

        cout << "Player 2 stats:" << endl;
        cout << player2.getPlayerName() << " had " << player2.getPlayerStamina() << " stamina points, " << player2.getPlayerStrength() << " strength points, and " << player2.getPlayerWisdom() << " wisdom points." << endl;
        gameStats << "Game ended in a tie.";
    }
    cout << endl;
    cout << "all data writen to file: gameStats.txt" << endl;

    
}