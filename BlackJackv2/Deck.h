/* 
 * File:   Deck.h
 * Author: Samra
 *
 * Created on May 4, 2021, 7:42 PM
 */

#ifndef DECK_H
#define DECK_H

#include <string>

using namespace std;

#define DECK_SIZE 4

class Deck
{

public:
	string deck[DECK_SIZE] = 
        {
            "Spades",
            "Hearts",
            "Clubs",
            "Diamonds"
        };
	//Constructor initializes the deck.
	Deck()
	{

	}

	//Generates a random deck and returns for Card generation
	string getDeck()
	{
		int random_deck = rand() % DECK_SIZE;
		return deck[random_deck];
	}

};

#endif /* DECK_H */

