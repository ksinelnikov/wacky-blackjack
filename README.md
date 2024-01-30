# WACKY BLACKJACK
#### Video Demo:  https://youtu.be/SDSgkcxJIVk
#### Description: A command-line blackjack game written in C for up to four players

Wacky Blackjack is a modified version of the traditional blackjack game.

It is designed to be played through the command line for up to four players. The maximum number of players that has been chosen is arbitrary and can be changed quite easily to accommodate more players.

The rules are modified to make the game more simple. For example, an Ace only counts as 11 points (not 1 or 11, as in the standard version of the game). While cards for each player and the dealer are randomly generated, this is not based on a set number of card decks (e.g. eight decks as might be the case in the casino) but on a single algorithm which generates a random number.

The random number is given a range to then match it to a possible number of cards. As can be expected, the possible cards range through A, 2, 3, 4, 5, 6, 7, 8, 9, 10 (represented by 'T' in the game), J, Q and K. The total number of points is calculated based on the cards that each player gets.

The code for this game is written in C. For simplicity, it is contained in just a single 'game.c' file. This was a design choice in order to reduce complexity and allow for ease of coding the program by only working on a single file.

This file contains the main function which runs the game, as well as three functions:
1. A function to generate a random card.
2. A function to give a value in points to each card.
3. A separate function for generating and calculating the dealer's hand.

Splitting the code into these additional functions made the design more coherent. It also allowed me to work on discrete pieces of code and put forward specific goals to progress the project.

A set of libraries is also used to make the code run, including the useful CS50 library (<cs50.h>).

The game runs as follows:
- The number of players (up to 4) is set by asking for input from the user(s)/player(s).
- Starting with Player 1, each player is dealt two cards and asked if they would like additional cards.
- The maximum number of cards dealt to each player and the dealer is 5.
- If a player accumulates more than 21 points based on (more-or-less) standard values for each card, they lose the game.
- The Dealer is then dealt two cards, and if the total points is under 17 then subsequent cards are dealt.
- Points totals between each player and the dealer are compared to see who wins, is tied or loses the game.

Possible future improvements to the game include changing the random card function to generate cards based on a number of standard card decks and the ability for players to split hands if two picture cards are dealt.
