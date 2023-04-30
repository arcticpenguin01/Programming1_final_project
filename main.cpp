#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


void playGame();
void hangman(int incorrectGuesses);


void playGame()
{
    int incorrectGuesses = 0;

    vector<string> words = {"innovation", "stroll", "finger", "pan", "sleeve","run","frequency","justice","development","chimney","hobby","shelf","challenge","pledge","tenant","nursery","chief","humanity","hit","obligation","safety","throat","absence","coincide","station","belong","enter","mosaic","straight","refuse","fastidious","commission","fairy","brainstorm","passage","dribble","fill","graduate","fill","able","yard","confession","tower","chop","strong","dominant","crowd","rehabilitation","advance","departure","quarter"};

    // Generate a random index
    srand(time(nullptr));
    string word = words[rand() % words.size()];
    int lengthword = word.length();

    // Create a string with underscores to represent the word
    string wordGuessed(word.size(), '_');

    // Start the game loop
    int numGuesses = 0;
    int maxGuesses = 7;

    bool gameWon = false;

    while (numGuesses < maxGuesses && !gameWon)
    {
        cout << "\nguess the word: ";
        for (int i = 0; i < lengthword; i++)
        {
            if (wordGuessed[i] != '_')
            {
                cout << " " << wordGuessed[i] << " ";
            }
            else
            {
                cout << " _ ";
            }
        }

        cout << "\n";
        char guess;
        cin >> guess;

        // Check if the guess is correct
        bool correct = false;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == guess)
            {
                wordGuessed[i] = guess;
                correct = true;
            }
        }

        if (correct)
        {
            cout << "Good guess! The word looks like this: ";
            for (int i = 0; i < lengthword; i++)
            {
                if (wordGuessed[i] != '_')
                {
                    cout << " " << wordGuessed[i] << " ";
                }
                else
                {
                    cout << " _ ";
                }
            }
            cout << "\n";

            if (wordGuessed == word)
            {
                gameWon = true;
            }
        }
        else
        {
            cout << "Sorry, that letter is not in the word. You have " << maxGuesses - numGuesses - 1 << " guesses left." << endl;
            numGuesses++;
            incorrectGuesses++;
            hangman(incorrectGuesses);
        }
    }

    if (gameWon)
    {
        cout << "\nCongratulations, you guessed the word: " << word << endl;
    }
    else
    {
        cout << "\nSorry, you ran out of guesses. The word was: " << word << endl;
    }
}






void hangman(int incorrectGuesses)
{
    switch (incorrectGuesses)
    {
        case 1:
            cout << R"(
        /  \_______________________________________
        |  |                                       |
        |  |_______________________________________|
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |__|________________________________________
        )" << endl;
        break;


        case 2:
            cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                    |
        |  |                    |
        |  |                    |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |__|________________________________________
        )" << endl;
        break;

        case 3:
            cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                    |
        |  |                    |
        |  |                 ___|___
        |  |                / __  __\
        |  |                \    _\ /
        |  |                 \_____/
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |  |
        |__|________________________________________
        )"<< endl;
        break;

        case 4:
            cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                 ___|___
        |  |                / __  __\
        |  |                \    _\ /
        |  |                 \_____/
        |  |                    |
        |  |                    |
        |  |                   /|
        |  |                  / |
        |  |                 /  |
        |  |                    |
        |  |                    |
        |  |                    |
        |  |
        |  |
        |__|________________________________________
        )"<< endl;
        break;

        case 5:
            cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                 ___|___
        |  |                / __  __\
        |  |                \    _\ /
        |  |                 \_____/
        |  |                    |
        |  |                    |
        |  |                   /|
        |  |                  / | \
        |  |                 /  |  \
        |  |                    |
        |  |                    |
        |  |                    |
        |  |
        |  |
        |__|________________________________________
        )"<< endl ;
        break;

        case 6:
             cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                 ___|___
        |  |                / __  __\
        |  |                \    _\ /
        |  |                 \_____/
        |  |                    |
        |  |                    |
        |  |                   /|
        |  |                  / | \
        |  |                 /  |  \
        |  |                    |
        |  |                    |
        |  |                    |
        |  |                   /
        |  |                  /
        |  |                 /
        |  |
        |__|________________________________________
        )"<< endl;
        break;

         case 7:
             cout << R"(
        /  \_______________________________________
        |  |                   \                   |
        |  |____________________\__________________|
        |  |                    |
        |  |                 ___|___
        |  |                / __  __\
        |  |                \    _\ /
        |  |                 \_____/
        |  |                    |
        |  |                    |
        |  |                   /|
        |  |                  / | \
        |  |                 /  |  \
        |  |                    |
        |  |                    |
        |  |                    |
        |  |                   / \
        |  |                  /   \
        |  |                 /     \
        |  |
        |__|________________________________________


        ********************************************
        *                                          *
        *               GAME OVER                  *
        *            STICK MAN DEAD :(             *
        *     STICK WIFE AND STICK CHILDREN SAD    *
        *                                          *
        ********************************************
        )" << endl;
        break;
    }

}

int main()
{

    cout << R"(
               *************************************************
               *                                               *
               *                                               *
               *            WELCOME TO HANGMAN                 *
               *                                               *
               *    YOU WILL HAVE 7 GUESSES FOR EACH WORD      *
               *                                               *
               *      FAILURE TO GUESS THE WORD CORRECTLY      *
               *                                               *
               *          WILL RESULT IN THE MURDER            *
               *                                               *
               *          OF A INNOCENT STICKMAN               *
               *                                               *
               *        (He has a family of four btw)          *
               *                                               *
               *        HIS FATE RESTS IN YOUR HANDS           *
               *                                               *
               *                                               *
               *                                               *
               *************************************************

            )";


    playGame();


    return 0;
}






