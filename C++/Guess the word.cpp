#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
   // List of words
   string list[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
   string user_guess, computer_choice;
   int length_of_list = sizeof(list) / sizeof(list[0]);

   // Seed the random number generator
   srand(time(0));
   computer_choice = list[rand() % length_of_list];

   // Initialize the word list with underscores
   vector<string> w_list(computer_choice.size(), "_ ");
   cout << endl;

   bool end = false;
   while (!end)
   {
      // Display the current state of the word list with underscores
      for (const auto &x : w_list)
      {
         cout << x;
      }
      cout << endl;

      // Getting the user's guess
      cout << "Guess a letter: ";
      cin >> user_guess;

      // Convert the guess to lowercase
      for (char &x : user_guess)
      {
         x = tolower(x);
      }

      // Check if the guess is correct and update the word list
      for (size_t i = 0; i < computer_choice.size(); i++)
      {
         if (user_guess[0] == computer_choice[i])
         {
            w_list[i] = user_guess[0];
         }
      }

      // Check if the word list still contains any underscores
      end = true;
      for (const string &item : w_list)
      {
         if (item == "_ ")
         {
            end = false;
            break;
         }
      }
   }

   // Display the final result
   for (const auto &x : w_list)
   {
      cout << x;
   }
   cout << endl;

   cout << "You won!" << endl;
   return 0;
}