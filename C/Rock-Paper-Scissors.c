#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Function to print Rock using ASCII art
void printRock()
{
    printf("    _______\n");
    printf("---'   ____) \n");
    printf("      (_____) \n");
    printf("      (_____) \n");
    printf("      (___) \n");
    printf("---.__(___) \n");
}

// Function to print Paper using ASCII art
void printPaper()
{
    printf("     _______\n");
    printf("---'   ____)____ \n");
    printf("          ______) \n");
    printf("          _______) \n");
    printf("         _______) \n");
    printf("---.__________) \n");
}

// Function to print Scissors using ASCII art
void printScissors()
{
    printf("    _______\n");
    printf("---'   ____)____ \n");
    printf("          ______) \n");
    printf("       __________) \n");
    printf("      (____) \n");
    printf("---.__(___) \n");
}

// Helper that prints a choice based on the passed integer
void printChoice(int choice)
{
    switch (choice)
    {
    case 1:
        printRock();
        break;
    case 2:
        printPaper();
        break;
    case 3:
        printScissors();
        break;
    default:
        printf("Invalid choice");
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int userChoice, computerChoice;
    char playAgain;

    // Seed the random number generator
    srand((unsigned)time(NULL));

    do
    {
        printf("Rock, Paper, Scissors Game\n");
        printf("Choose your hand:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Your choice: ");
        scanf("%d", &userChoice);

        // Ensure correct user input
        while (userChoice < 1 || userChoice > 3)
        {
            printf("Invalid choice. Please enter 1, 2, or 3: ");
            scanf("%d", &userChoice);
        }

        // Computer makes its choice
        computerChoice = rand() % 3 + 1;

        printf("\nYou chose:\n");
        printChoice(userChoice);
        printf("\nComputer chose:\n");
        printChoice(computerChoice);
        printf("\n");

        // Decide the winner
        if (userChoice == computerChoice)
        {
            printf("It's a tie!\n");
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2))
        {
            printf("You win!\n");
        }
        else
        {
            printf("Computer wins!\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain); // Leading whitespace to consume any leftover newline
        printf("\n");

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}