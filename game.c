/* Wacky Blackjack: a blackjack game for up to 4 players written in C*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* Including the CS50 library to get_int */
#include <cs50.h>

/* Declaring separate functions to be used in main */
char randomCard();
int cardValue(char card);
int dealerHand();

/* Struct to hold player info */
struct player
{
    int cardValue;
    bool active;
};

/* Main function to run the game */
int main(void)
{
    /* Little card logo */
    printf("\n+-----+\n");
    printf("|     |\n");
    printf("|  \xE2\x99\xA0  |\n");
    printf("|     |\n");
    printf("+-----+\n");

    /* Introduction to game */
    printf("\nWelcome to Wacky Blackjack!\n");
    printf("Press Enter to continue.");
    getc(stdin);

    /* Seeding the random function */
    srand(time(NULL));

    /* Initialising number of players */
    int players;
    players = get_int("\nEnter the number of players (maximum of 4): ");

    while (players > 4 || players < 1)
    {
        printf("You have entered an invalid number of players. Try again.\n");
        players = get_int("\nEnter the number of players (maximum of 4): ");
    };

    printf("\nLet's begin!\n");

    /* Creating struct with player numbers and first two cards */
    struct player pl[players];
    int dealerTotal;

    /* Each player accumulates points based on the cards they are dealt */
    for (int i = 0; i < players; i++)
    {
        pl[i].cardValue = 0;
        pl[i].active = true;

        char card_1 = randomCard();
        char card_2 = randomCard();

        printf("\nCards for Player %i: %c %c\n", i + 1, card_1, card_2);

        int card_1value = cardValue(card_1);
        int card_2value = cardValue(card_2);

        int total_value = card_1value + card_2value;
        pl[i].cardValue = total_value;
        printf("Total: %i\n", card_1value + card_2value);
        sleep(3);

        /* 'Hit me!' variable declared if a player wants another card */
        char hit1 = get_char("\nPlayer %i: Do you want another card? (y/n)", i + 1);

        if (hit1 == 'y')
        {

            char card_3 = randomCard();

            printf("\nCards for Player %i: %c %c %c\n", i + 1, card_1, card_2, card_3);

            int card_3value = cardValue(card_3);
            total_value += card_3value;

            printf("Total: %i\n", total_value);
            sleep(3);

            pl[i].cardValue = total_value;

            if (total_value > 21)
            {
                pl[i].cardValue = 0;
                pl[i].active = false;
                printf("\nSorry, Player %i, you lose!\n", i + 1);
            }
            else
            {
                char hit2 = get_char("\nPlayer %i: Do you want another card? (y/n)", i + 1);

                if (hit2 == 'y')
                {

                    char card_4 = randomCard();

                    printf("\nCards for Player %i: %c %c %c %c\n", i + 1, card_1, card_2, card_3, card_4);

                    int card_4value = cardValue(card_4);
                    total_value += card_4value;

                    printf("Total: %i\n", total_value);
                    sleep(3);

                    pl[i].cardValue = total_value;

                    if (total_value > 21)
                    {
                        pl[i].cardValue = 0;
                        pl[i].active = false;
                        printf("\nSorry, Player %i, you lose!\n", i + 1);
                    }
                    else if (total_value < 21)
                    {
                        char hit3 = get_char("\nPlayer %i: Do you want another card? (y/n)", i + 1);

                        if (hit3 == 'y')
                        {

                            char card_5 = randomCard();

                            printf("\nCards for Player %i: %c %c %c %c %c\n", i + 1, card_1, card_2, card_3, card_4, card_5);

                            int card_5value = cardValue(card_5);
                            total_value += card_5value;

                            printf("Total: %i\n", total_value);
                            sleep(3);

                            pl[i].cardValue = total_value;

                            if (total_value > 21)
                            {
                                pl[i].cardValue = 0;
                                pl[i].active = false;
                                printf("\nSorry, Player %i, you lose!\n", i + 1);
                            };
                        };
                    };
                };
            };
        };
    };
    sleep(3);

    /* Accessing the dealerHand function to get the dealer total */
    dealerTotal = dealerHand();

    /* Comparing each player's total to see who wins, loses or ties with the dealer */
    for (int i = 0; i < players; i++)
    {
        if (dealerTotal < pl[i].cardValue && pl[i].active == true)
        {
            printf("Player %i is a winner!\n", i + 1);
        }
        else if (dealerTotal == pl[i].cardValue && pl[i].active == true)
        {
            printf("Player %i and Dealer are tied.\n", i + 1);
        }
        else if (pl[i].active == true)
        {
            printf("Sorry, Player %i, you lose!\n", i + 1);
        };
    };
    sleep(3);

    /* Message and little card logo */
    printf("\nThank you for playing!\n");
    printf("\n+-----+\n");
    printf("|     |\n");
    printf("|  \xE2\x99\xA0  |\n");
    printf("|     |\n");
    printf("+-----+\n");

    return 0;
};

/*Function to generate random cards as needed*/
char randomCard()
{
    char card = 1;
    int random = (int) (12.0 * rand() / (RAND_MAX)) + 49;

    if (random > 49 && random < 58)
    {
        card = random;
    }
    else
    {
        switch (random)
        {
            case 49:
                card = 65;
                break;
            case 58:
                card = 84;
                break;
            case 59:
                card = 74;
                break;
            case 60:
                card = 81;
                break;
            case 61:
                card = 75;
                break;
        };
    };
    return card;
}

/* Function to convert each card to points value*/
int cardValue(char card)
{

    int value = 0;
    if (card > 49 && card < 58)
    {
        value = card - '0';
    }
    else
    {
        switch (card)
        {
            case 'A':
                value = 11;
                break;
            case 'J':
                value = 10;
                break;
            case 'Q':
                value = 10;
                break;
            case 'K':
                value = 10;
                break;
            case 'T':
                value = 10;
                break;
        }
    }

    return value;
}

/* Separate function for dealer hand */
int dealerHand()
{
    char housecard_1 = randomCard();
    char housecard_2 = randomCard();

    printf("\nDealer cards: %c %c\n", housecard_1, housecard_2);

    int card_1value = cardValue(housecard_1);
    int card_2value = cardValue(housecard_2);

    int total_value = card_1value + card_2value;

    printf("Dealer total: %i\n\n", total_value);
    sleep(3);

    if (total_value < 17)
    {
        char housecard_3 = randomCard();
        printf("Dealer cards: %c %c %c\n", housecard_1, housecard_2, housecard_3);

        int card_3value = cardValue(housecard_3);
        total_value += card_3value;
        printf("Dealer total: %i\n\n", total_value);
        sleep(3);

        if (total_value < 17)
        {
            char housecard_4 = randomCard();
            printf("Dealer cards: %c %c %c %c\n", housecard_1, housecard_2, housecard_3, housecard_4);

            int card_4value = cardValue(housecard_4);
            total_value += card_4value;
            printf("Dealer total: %i\n\n", total_value);
            sleep(3);

            if (total_value < 17)
            {
                char housecard_5 = randomCard();
                printf("Dealer cards: %c %c %c %c %c\n", housecard_1, housecard_2, housecard_3, housecard_4, housecard_5);

                int card_5value = cardValue(housecard_5);
                total_value += card_5value;
                printf("Dealer total: %i\n\n", total_value);
            }
            else if (total_value > 21)
            {
                printf("Dealer busts!\n\n");
                total_value = 0;
                return total_value;
            }
            else
            {
                return total_value;
            };
        }
        else if (total_value > 21)
        {
            printf("Dealer busts!\n\n");
            total_value = 0;
            return total_value;
        }
        else
        {
            return total_value;
        };
    }
    else if (total_value > 21)
    {
        total_value = 0;
        printf("Dealer busts!\n\n");
    }
    else
    {
        return total_value;
    };
    return total_value;
}
