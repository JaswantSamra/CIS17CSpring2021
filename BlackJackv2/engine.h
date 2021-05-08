/* 
 * File:   engine.h
 * Author: Samra
 *
 * Created on May 4, 2021, 7:40 PM
 */

#include <map>

#include <utility>

#include <string>

#include <stack>

#include "Cards.h"

#include "Deck.h"


map<pair<char,string>, bool> used_cards; //HashMap used to check uniqueness 
                                        //cards in hand

#ifndef ENGINE_H
#define ENGINE_H

class engine
{
	/*
	*	card = gets the card for the set
	*	player_value = stores the value of player's cards
	*	dealer_value = stores the value of Dealer's cards
	*	i = for loop counter and cross checking
	*	dealer and players = are sets of cards generated
	*	player = stores the name of the player
	*	decks = used in storing the value of decks generated
	*/
	
	char card;
	int player_value , dealer_value ;
	int  i;
        std::stack<int> dealerStack;
        std::stack<int> playerStack; 
        
	pair<char,std::string> dealer[4],players[4];
	std::string player,decks;

	Deck deck;
	Cards cards;

	public:

	/*
	*	The Constructor initializes the values for the
	*	variables declared in private and starts the game
	*	engine by calling the startGame function. 
	*/

	engine(string x)
	{
		player = x;
                player_value = 0;
                dealer_value = 0;
                i = 0;
		startGame();
	}

	/*
        * Displays the cards of the Dealer
	*/

	void displayDealer()
	{
		cout<<"Dealer's cards "<<"\n";
		for (int i = 0; i < 4; ++i)
		{	
			if(dealer[i].first == 'X')
                        {
				cout<<10<<" "<<dealer[i].second<<" ";
                        }
			else
                        {
				cout<<dealer[i].first<<" "<<dealer[i].second<<" ";
                        }
		}
		cout<<'\n';
	}

	/*
        * Calculates the value of cards of the Dealer
	*/

	void dealerValue()
	{
		for (int i = 0; i < 4; ++i)
		{
			//cout<<dealer[i].first<<" value "<<cards.cardValue(dealer[i].first)<<'\n';
			dealer_value += cards.cardValue(dealer[i].first); 
		}
		if((dealer[0].first == 'A' || dealer[1].first == 'A') && dealer_value > 21)
                {
			dealer_value -= 10;
                }
                if(dealer_value < 17)
                {
                    dealerHit();
                }
                else
                {
                    
                }
                if(dealer_value >21)
                {
                    dealer_value = 0;
                    cout << "Dealer bust" << endl;
                    stackDealerValue();
                }
                    
                
               
		//cout<<"Dealer's Value: "<<dealer_value<<'\n';
	}
        
        //being completely honest this was only to fulfill the stack requirement
        //stores dealer hand to stack
        
        void stackDealerValue()
        {
            dealerStack.push(dealer_value);
        }
        
        //basically the get method for the stack
        
        int displayDealerStack()
        {
            return dealerStack.top();
        }

	/*
        *    Calculates the value of cards of the Player
	*/

	void playerValue()
	{
		for (int i = 0; i < 4; ++i)
		{
			//cout<<players[i].first<<" value "<<cards.cardValue(players[i].first)<<'\n';
			player_value += cards.cardValue(players[i].first); 
		}
		if((players[0].first == 'A' || players[1].first == 'A') && player_value > 21)
                {
			player_value -= 10;
                }
                if(player_value > 21)
                {
                    player_value = 0;
                    cout << "Player Bust" < <endl;
                    stackPlayerValue();
                }

		//cout<<"Player's Value: "<<player_value<<'\n';
	}
        
        //being completely honest this was only to fulfill the stack requirement
        //stores player hand to stack
        
        void stackPlayerValue()
        {
            playerStack.push(player_value);
        }
        //basically the get method for the stack
        int displayPlayerStack()
        {
            return playerStack.top();
        }

	/*
	*	Description = Displays the cards of the Player
	*/

	void displayPlayer()
	{
		cout<<player<<"'s cards "<<"\n";
		for (int i = 0; i < 4; ++i)
		{
			if(players[i].first == 'X')
                        {
				cout<<10<<" "<<players[i].second<<" ";
			}
                        else
                        {
				cout<<players[i].first<<" "
                                        <<players[i].second<<" ";
                        }
		}
		cout<<'\n';
	}

	/*
	* Checks the value of the hand and compares with used_cards
	*/

	bool handChecker(pair<char,string> check)
	{
		if(used_cards.find(check) != used_cards.end())
                {
			return true;
                }
		else
                {
			return false;
                }
	}
        
        //just spams spaces to "clear." Didn't end up actually using this
        //this turned out to be obsolete code that was not practical and 
        //therefore did not end up into the  final code
        
	void clearScreen()
	{
		for (int i = 0; i < 50; ++i)
                {
			cout<<'\n';
                }
	}

	/*
        * Decides the winner by comparing Player and Dealer cards True if Dealer
        * wins, False if Player wins.
	*/

	bool findWinner()
	{
		return dealer_value >= player_value ? true : false;
                if(dealer_value == player_value){
                    cout << "Both Sides bust, No winner";
                }
	}

	/*
	*Start of BlackJack game. Deals the first two cards. 
	*/	

	void startGame()
	{
		while(i<2)
		{
			card = cards.generateCard();
			decks = deck.getDeck();
			dealer[i] = make_pair(card,decks);
			if(handChecker(dealer[i]))
			{
				if(i == 0)
                                {
					continue;
                                }
				else
                                {
					i--;
                                }
			}
			else
			{
				used_cards[dealer[i]] = true;
				i++;
			}
		}

		dealerValue();
		
		i = 0;

		while(i<2)
		{
			card = cards.generateCard();
			decks = deck.getDeck();
			players[i] = make_pair(card,decks);
			if(handChecker(players[i]))
			{
				if(i == 0)
                                {
					continue;
                                }
				else
                                {
					i--;
                                }
			}
			else
			{
				used_cards[players[i]] = true;
				i++;
			}
		}
		
                
		playerValue();
	}
        void dealerHit()
        {
            card = cards.generateCard();
            decks = deck.getDeck();
            i = 2;
            dealer[i] = make_pair(card,decks);
            while(i<3)
            {
            if(handChecker(dealer[i]))
            {
		if(i == 0)
                {
		continue;
                }
                else
                {
		i--;
                 }
		}
            else
            {
		used_cards[dealer[i]] = true;
		i++;
                dealerValue();
            }
         }
        }
        void hit()
        {
            card = cards.generateCard();
            decks = deck.getDeck();
            i = 2;
            players[i] = make_pair(card,decks);
            while(i<3)
            {
            if(handChecker(players[i]))
            {
		if(i == 0)
                {
		continue;
                }
                else
                {
		i--;
                 }
		}
            else
            {
		used_cards[players[i]] = true;
		i++;
                playerValue();
		}
         }
        }
	~engine()
	{
		used_cards.clear();
	}
};

#endif /* ENGINE_H */

