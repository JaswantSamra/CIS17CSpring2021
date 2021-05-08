/* 
 * File:   Cards.h
 * Author: Samra
 *
 * Created on May 4, 2021, 7:42 PM
 */

#define CARD_SIZE 13

class Cards
{
	

public:

	char cards[CARD_SIZE] = 
        {
            'A',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            'X',
            'J',
            'Q',
            'K'
        };
	//Constructor initializes the cards.
	Cards()
	{
	
	}

	//Generates a random card and returns for Card generation
	char generateCard()
	{
		int random_card = rand() % 13;
		return cards[random_card];
	}

	int cardValue(char card)
	{
		if(card >= '2' && card <= '9')
                {
			return card - '0';
                }
		else if(card == 'J' || card == 'Q' || card == 'K' || card == 'X')
                {
			return 10;
                }
		else if(card == 'A')
                {
			return 11;
                }
		else
                {
			return 0;
                }
	}


};