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

To include these words in the program, copy and paste the words you want into the vector and put double quotes around each word you include.

When you run the program, it will output in the terminal of your IDE. It should look like this:

![Screenshot 2023-04-30 133125](https://user-images.githubusercontent.com/101565107/235368051-460f2294-61fe-48b8-aa23-4e2bb733c868.png)

This is the welcoming screen of the game and it gives you the rules and prompts you to guess the letters for a word. It is a normal hangman game, if you don't know how to play hangman here's a link for more info on how to play:

https://www.hangmanwords.com/how-to

Playing the game
-----------------
The program prompts the user to guess the correct spelling of a word and gives the user a maximum of seven incorrect guesses to guess the word correctly. After each incorrect guess, the user will be notified how many guesses they have left. Below is an example of that feature.

![Screenshot 2023-04-30 152240](https://user-images.githubusercontent.com/101565107/235372514-f2f85800-c558-4243-9857-8dedb64f0fdb.png)



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

Hangman function
-----------------
This function draws the hangman each time the user makes an incorrect guess. It uses a switch case that uses the value of a variable called "incorrectguesses" whose value is updated everytime the user guesses a wrong character. If the user guesses incorrectly seve times, this function will print out the full hangman image and will print out a game over message along with it. The image was drawn using the R"() string method and was drawn using dash marks. Below is the function:

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

Main function
--------------

The main function prints out an introduction/ welcoming screen to the user and calls the playGame function, the playGame function calls the hangman function in the event that the user makes an incorrect guess. The main function is shown below:

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

Feel free to use this project as a template and add any features that you wish to add. Have fun playing the game!
