/* 
 * File:   main.cpp
 * Author: Samra
 *
 * Created on May 4, 2021, 6:35 PM
 * Version 1 proved incompatible for the way I implemented code here
 * A lot of the comments are code bloopers
 */

#include <iostream>

#include <cstdlib>

#include <string>

#include <list>

#include <algorithm>

#include <queue>

#include <set>

#include "engine.h"

using namespace std;

string checkMenuInput(string s){
    set<string> playerOptions;
    
    typedef set<string>::iterator optionIt;
    
    optionIt iteratory;
    
    optionIt iteratorn;
    
    optionIt iteratorY;
    
    optionIt iteratorN;
    
    playerOptions.insert("y");
    iteratory = playerOptions.find("y");
    
    playerOptions.insert("Y");
    iteratorY = playerOptions.find("Y");
    
    playerOptions.insert("n");
    iteratorn = playerOptions.find("n");
    
    playerOptions.insert("N");
    iteratorN = playerOptions.find("N");
    
    string temp;
    cout << "New Game? Y/N" <<endl;
    cin >>temp;
    if(playerOptions.find(temp) == iteratory)
    {
        s == "y";
    }
    else if(playerOptions.find(temp) == iteratorY)
    {
        s = "Y";
    }
    else if(playerOptions.find(temp) == iteratorn)
    {
        s == "n";
    }
    else if(playerOptions.find(temp) == iteratorN)
    {
        s = "N";
    }
    else
    {
        s == "A";
    }
    return s;
}

int main(int argc, char** argv) {
        string hitOpt;
        hitOpt = " ";
        string player;
        player = " ";
	string new_game;
        new_game = " ";
        list<int> winners = 
        {
        };
        list<int>::iterator count = winners.begin();
        
//       int count = 0;
        //feel more like a game and less robotic
	cout<<"Welcome to BlackJack! As your host I bid you a warm welcome"<<
               '\n' << "Now that you are feeling welcome... What is your name?";
        cout << "\n";
        cout<<"Please enter your name: ";//Gets the players name
		cin>>player;
        cout<<"Please enjoy your stay. "
                << "Enter anything other than Y or N to exit.";
        cout << "\n";
	do //do while used so that the code runs once before. 
        { //If you ran the program that means you want to play it
		cout<<"The rules are standard. Let us begin.\n";																				
		cout<<"Dealing first two cards - - - \n \n";
                engine game(player);

		game.displayDealer();
		game.displayPlayer();
                
                cout<< "would you like to hit?" << endl;
                cin >> hitOpt;
                if(hitOpt == "Y")
                {
                    game.hit();
                } 
                else
                {
                    
                }
                
		if(game.findWinner()){
			cout<<'\n'<<"\t \t \tWinner is Dealer!!! "<<
                                "\n \n";
                        winners.insert(count, 0);
                        game.stackDealerValue();
                        int dDS = game.displayDealerStack();
                        cout << dDS << endl;
		}
                else
                {
			cout<<'\n'<<"\t \t \tWinner is "<<player<<"!!! "<<
                                "\n \n";
                        winners.insert(count, 1);
                        cout << endl;
                        game.stackPlayerValue();
                        int dPS = game.displayPlayerStack();
                        cout << dPS << endl;
                }
                
                //attempted method that would not work
//                string temp;
//                checkMenuInput(temp);
//                new_game == temp;
//                cout << temp << endl;
                
                
                //checkMenuInput Set
                string temp;
                new_game = checkMenuInput(temp);
		
                
                //old method of checking input for new games
                //To start a new game, enter a choice ~~~
//		cout<<"A new game?(Y/N) : ";
//		cin>>new_game;
//		cout<<'\n';
		
		// if(new_game == 'y' || new_game == 'Y')
		// game.clearScreen();
                
	}
        
        //end of do while loop
        
        while(new_game == "y" || new_game == "Y");
        
        //close winners list
        
        winners.end();
        
        //printing the unsorted winners list for reference
        
        cout<< "Unsorted win list" << endl;
        auto print = [](const int& n) 
        {
            std::cout << " " << n;
        };
        
        //for_each loop prints out the value of list
        
        std::for_each(winners.cbegin(), winners.cend(), print);
        cout << "\n" << endl;
        
        //sorts ascending
        
        winners.sort(); 
        
        // flip around so that 0's are displayed first
        
        winners.reverse(); 
        
//    string winningRecord = winners;
//    int winningRecord[] = {};
//    for(int x : winners){
//        winningRecord[x] = x;
//    }
//    for(int i = 0; i < winners.size(); i ++){
//        winningRecord[i] = winners;
//    }
    
        //counter for all the times the dealer has won
        
    int dealerWin;
    
    dealerWin = 0;
    
    //count for all the times player has won
    
    int playerWin;
    
    playerWin = 0;
    
    //enhanced for each loop to go through the list and iterate the counters up
    
    for(int x : winners)
    {
        if(x == 1){
            playerWin++;
        } 
        else
        {
            dealerWin++;
        }
        
//        cout << x << "\n";
    }
    
        //taking out the first zero and 1 that was use for initialization
    
        dealerWin - 1;
        
        playerWin - 1;
    
        //print statement to display the wins of each party
        
    cout<<"Dealer: " << dealerWin << "\nPlayer: " << playerWin << "\n";
    
    //freeing up all spaces from the list
    //similar to a deconstructor
    
    for(int x : winners)
    {
        winners.remove(x);
    }
    
    //using a priority queue to determine winner for absolute certainty using 
    //the above dealerWin and playerWin counters
    
    //creation of the priority queue
    
    std::priority_queue<int> displayWinner;
    
    //adding dealerWin value to the priority queue
    
    displayWinner.push(dealerWin);
    
    //adding playerWin value to the priority queue
    
    displayWinner.push(playerWin);
    
    //priority_queue automatically sort the list from greatest to least
    
    //comparing the two wins as the bigger value will be the overall winner
    //calling the priority_queue displayWinner.top() ensures that the greater
    //value of the two is displayed due to how the priority_queue automatically
    //displays the bigger value first. Therefore the bigger value is the winner
    //and who won can be determined by a simple if statement which checks for
    //the values of the two win counters which were incremented above using 
    //the enhanced for loop that counted up whenever a 0 or 1 was detected.
    
    if(dealerWin > playerWin)
    {
        cout << "The Dealer is the Overall Winner at " << displayWinner.top() << " wins!";
    } 
    else
    {
        cout << player << " is the Overall Winner at " << displayWinner.top() << " wins!";
    }
    
    //failed attempt as trying to print
    
//    for(int i = 0; i < winners.size(); i++)
//    {
//        
//    }
    
    return 0;
}
