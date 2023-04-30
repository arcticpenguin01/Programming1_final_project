# Programming1_final_project
This is the final project for a programming 1 class. It is a basic hangman game using C++.

User Guide
-----------

To play this Hangman game, you need to download the main.cpp file provided in this repository and you will need to download an IDE (integrated development environment) if you don't have one installed yet. Some popular IDEs for C++ are CLion and VScode. Once you've downloaded and IDE, you will need to install a compiler, MinGW (especially if you're using VScode). CLION may have a compiler packaged with the IDE, but as a general rule download MinGW.

Here are the links for VScode installation:

https://www.geeksforgeeks.org/how-to-install-visual-studio-code-on-windows/#   // Step by step tutorial
https://code.visualstudio.com/download   // download link


CLion links:
https://www.jetbrains.com/clion/download/#section=windows  // download link


MinGW link:
https://sourceforge.net/projects/mingw/  // download link


Once MinGW is installed, you're ready to run the main.cpp file that you downloaded from this repo. To run the program, find the run option in your IDE of choice and it will output the game in the terminal and you will be able to play the game. No other steps are needed to successfully compile an run this project.


No input data is needed, as a list of words is imbedded into the program. To change this list of words, you will need to access the  "void playGame()" function of the program and manually change the words in the string vector that holds the list of words:

void playGame()
{
    
    int incorrectGuesses = 0;

    vector<string> words = {"innovation", "stroll", "finger", "pan", "sleeve","run","frequency","justice","development","chimney","hobby","shelf",
                            "challenge","pledge","tenant","nursery","chief","humanity","hit","obligation","safety","throat","absence","coincide",
                            "station","belong","enter","mosaic","straight","refuse","fastidious","commission","fairy","brainstorm","passage",
                            "dribble","fill","graduate","fill","able","yard","confession","tower","chop","strong","dominant","crowd",
                            "rehabilitation","advance","departure","quarter"};
}

Here's a text file of additional words, feel free to include and use it for the program:

[words.txt.txt](https://github.com/elijah1108/Programming1_final_project/files/11361900/words.txt.txt)

When you run the program, it will output in the terminal of your IDE. It should look like this:

![Screenshot 2023-04-30 133125](https://user-images.githubusercontent.com/101565107/235368051-460f2294-61fe-48b8-aa23-4e2bb733c868.png)

This is the welcoming screen of the game and it gives you the rules and prompts you to guess the letters for a word. It is a normal hangman game, if you don't know how to play hangman here's a link for more info on how to play:

https://www.hangmanwords.com/how-to


Developer's guide
-----------------

This project was coded in C++ and it consists of three functions:

void hangman(), void playGame(), and the int main() functions.

The playGame() function contains the logic of the game loop. In this function, a vector was used to generate a list of words of which random words was pulled, convert each character of that randomly chosen word to the underline character and then prompt the user to guess the letters of that word.

The function looks like this:

void playGame()
{
    int incorrectGuesses = 0;

    vector<string> words = {"innovation", "stroll", "finger", "pan", "sleeve","run","frequency","justice","development","chimney","hobby","shelf",
                            "challenge","pledge","tenant","nursery","chief","humanity","hit","obligation","safety","throat","absence","coincide",
                            "station","belong","enter","mosaic","straight","refuse","fastidious","commission","fairy","brainstorm","passage",
                            "dribble","fill","graduate","fill","able","yard","confession","tower","chop","strong","dominant","crowd",
                            "rehabilitation","advance","departure","quarter"};

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

The 


