#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "game.h"
#include "memory.h"

using namespace std;

string playerName;

int memoryNumber = 0;
int courage = 0;
int curiosity = 0;
int trust = 0;
int defiance = 0;
int predictions = 0;

int option1 = 0;
int option2 = 0;
int option3 = 0;

bool gameFinished = false;

void newGame();
void continueGame();
void playGame();
void memoryEvent(int number);
void makeChoice(int choice);
void showProfile();
void finalEnding();
void saveGame();
bool loadGame();
void remember(const string& text);
void pauseScreen();
void clearInput();

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void remember(const string& text)
{
    addMemory(text, memoryNumber);
}

void startGame()
{
    cout << "\n==================================================\n";
    cout << "                    M I R R O R\n";
    cout << "==================================================\n";
    cout << "       The mirror doesn't copy you.\n";
    cout << "                 It learns you.\n";
    cout << "==================================================\n";

    cout << "\n1. New Game\n";
    cout << "2. Continue\n";
    cout << "3. Exit\n";
    cout << "\nChoice: ";

    int choice;
    cin >> choice;

    if (choice == 1)
        newGame();
    else if (choice == 2)
        continueGame();
    else
        cout << "\nThe mirror watches you leave.\n";
}

void newGame()
{
    playerName = "";
    memoryNumber = 0;
    courage = curiosity = trust = defiance = predictions = 0;
    option1 = option2 = option3 = 0;
    gameFinished = false;

    clearMemories();

    cout << "\nEnter your name: ";
    cin >> playerName;

    cout << "\nWelcome, " << playerName << ".\n";
    cout << "\nThere is a mirror in front of you.\n";
    cout << "Your reflection looks completely normal.\n";

    pauseScreen();

    cout << "\nYou move your hand.\n";
    cout << "The reflection moves too.\n";

    pauseScreen();

    cout << "\nYou smile.\n";
    cout << "The reflection smiles.\n";

    pauseScreen();

    cout << "\nThen the reflection blinks first.\n";

    memoryNumber = 1;
    remember("The reflection blinked before the player.");
    pauseScreen();

    playGame();
}

void continueGame()
{
    if (!loadGame())
    {
        cout << "\nNo saved game found.\n";
        return;
    }

    if (gameFinished)
    {
        cout << "\nThe game remembers that you finished.\n";
        showProfile();
        return;
    }

    cout << "\nWelcome back, " << playerName << ".\n";
    cout << "The mirror remembers you.\n";

    playGame();
}

void playGame()
{
    while (memoryNumber < 10)
    {
        memoryNumber++;
        memoryEvent(memoryNumber);

        int choice;
        cout << "\nChoice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3)
        {
            clearInput();
            cout << "\nThe mirror says: \"That wasn't a choice.\"\n";
            choice = 3;
        }

        makeChoice(choice);
        saveGame();
    }

    finalEnding();
}

void memoryEvent(int number)
{
    cout << "\n==================================================\n";
    cout << "                 MIRROR MEMORY #" << number << "\n";
    cout << "==================================================\n";

    if (number == 2)
    {
        cout << "\nYour reflection smiles.\n";
        cout << "You are not smiling.\n";
        cout << "\n1. Smile back\n2. Ask why\n3. Walk away\n";
    }
    else if (number == 3)
    {
        cout << "\nThe mirror speaks:\n";
        cout << "\"I know what you are going to choose.\"\n";
        cout << "\n1. Prove it wrong\n2. Ask what it predicts\n3. Do nothing\n";
    }
    else if (number == 4)
    {
        cout << "\nA thin crack appears across the mirror.\n";
        cout << "\n1. Touch the crack\n2. Ignore it\n3. Break the mirror\n";
    }
    else if (number == 5)
    {
        cout << "\nA second reflection appears beside yours.\n";
        cout << "\n1. Trust the first reflection\n2. Trust the second reflection\n3. Trust neither\n";
    }
    else if (number == 6)
    {
        cout << "\nYour reflection disappears.\n";
        cout << "The glass is completely empty.\n";
        cout << "\n1. Touch the glass\n2. Call your name\n3. Wait\n";
    }
    else if (number == 7)
    {
        cout << "\nWords appear on the mirror:\n";
        cout << "\"I am learning you.\"\n";
        cout << "\n1. Ask what it learned\n2. Ask how\n3. Tell it to stop\n";
    }
    else if (number == 8)
    {
        cout << "\nThe reflection moves before you do.\n";
        cout << "\n1. Copy it\n2. Wait\n3. Challenge it\n";
    }
    else if (number == 9)
    {
        cout << "\nThe mirror asks:\n";
        cout << "\"Which one of us is real?\"\n";
        cout << "\n1. Me\n2. You\n3. Neither\n";
    }
    else
    {
        cout << "\nThe mirror becomes completely black.\n";
        cout << "\nThen your reflection appears behind you.\n";
        cout << "\n1. Turn around\n2. Look into the mirror\n3. Close your eyes\n";
    }
}

void makeChoice(int choice)
{
    if (choice == 1)
    {
        option1++;
        courage++;
        remember("The player chose option 1.");
    }
    else if (choice == 2)
    {
        option2++;
        curiosity++;
        remember("The player chose option 2.");
    }
    else
    {
        option3++;
        trust++;
        remember("The player chose option 3.");
    }

    // Simple prediction mechanic.
    if (option1 >= 3 || option2 >= 3 || option3 >= 3)
    {
        predictions++;

        cout << "\nThe mirror whispers:\n";

        if (option1 >= option2 && option1 >= option3)
            cout << "\"You usually choose 1.\"\n";
        else if (option2 >= option1 && option2 >= option3)
            cout << "\"You usually choose 2.\"\n";
        else
            cout << "\"You usually choose 3.\"\n";

        remember("The mirror predicted the player's behavior.");
    }

    if (choice == 3)
        defiance++;

    if (memoryNumber == 4 && choice == 3)
        remember("The player tried to break the mirror.");

    if (memoryNumber == 6 && choice == 1)
        remember("The player touched the empty mirror.");

    if (memoryNumber == 9 && choice == 3)
        remember("The player refused to decide which reflection was real.");
}

void showProfile()
{
    cout << "\n==================================================\n";
    cout << "                 MIRROR PROFILE\n";
    cout << "==================================================\n";

    cout << "\nPlayer: " << playerName << "\n";
    cout << "Memories: " << memoryCount() << "\n";
    cout << "Courage: " << courage << "\n";
    cout << "Curiosity: " << curiosity << "\n";
    cout << "Trust: " << trust << "\n";
    cout << "Defiance: " << defiance << "\n";
    cout << "Predictions: " << predictions << "\n";

    cout << "\nChoice Pattern:\n";
    cout << "Option 1: " << option1 << "\n";
    cout << "Option 2: " << option2 << "\n";
    cout << "Option 3: " << option3 << "\n";

    cout << "\nMirror's Conclusion: ";

    if (curiosity > courage && curiosity > trust)
        cout << "\"You keep looking for answers.\"\n";
    else if (defiance > curiosity && defiance > trust)
        cout << "\"You resist what you cannot understand.\"\n";
    else if (trust > courage && trust > curiosity)
        cout << "\"You are willing to believe.\"\n";
    else
        cout << "\"You are difficult to predict.\"\n";
}

void finalEnding()
{
    cout << "\n==================================================\n";
    cout << "                    MEMORY #10\n";
    cout << "                  THE LAST REFLECTION\n";
    cout << "==================================================\n";

    cout << "\nThe mirror becomes completely black.\n";
    pauseScreen();

    cout << "\nThen your reflection appears behind you.\n";
    cout << "\nThe mirror asks:\n";
    cout << "\"Do you want to see what is behind me?\"\n";

    showProfile();

    cout << "\n==================================================\n";
    cout << "FINAL CHOICE\n";
    cout << "==================================================\n";
    cout << "\n1. YES\n";
    cout << "2. NO\n";
    cout << "3. BREAK THE MIRROR\n";
    cout << "\nChoice: ";

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 3)
    {
        clearInput();
        choice = 3;
    }

    if (choice == 1)
    {
        cout << "\nENDING I — THE REFLECTION\n\n";
        cout << "The mirror becomes clear.\n";
        cout << "But it shows you from the beginning of the game.\n\n";
        cout << "\"You were never looking at yourself.\"\n";
        cout << "\"You were looking at your choices.\"\n";
    }
    else if (choice == 2)
    {
        cout << "\nENDING II — NOTHING\n\n";
        cout << "The mirror turns black.\n";
        cout << "\n\"Good.\"\n";
        cout << "\"You finally made a choice without asking what I would do.\"\n";
    }
    else
    {
        cout << "\nENDING III — THE LOOP\n\n";
        cout << "CRACK.\n";
        cout << "CRACK.\n";
        cout << "CRACK.\n\n";
        cout << "The mirror breaks.\n";
        cout << "\nMEMORY #11\n";
        cout << "\"The player broke the mirror.\"\n";
        cout << "\"The mirror did not break.\"\n";
    }

    cout << "\n==================================================\n";
    cout << "                     THE END\n";
    cout << "==================================================\n";

    gameFinished = true;
    saveGame();
}

void saveGame()
{
    ofstream file("mirror_save.txt");

    if (!file)
        return;

    file << playerName << "\n";
    file << memoryNumber << "\n";
    file << courage << "\n";
    file << curiosity << "\n";
    file << trust << "\n";
    file << defiance << "\n";
    file << predictions << "\n";
    file << option1 << "\n";
    file << option2 << "\n";
    file << option3 << "\n";
    file << gameFinished << "\n";

    file << memoryCount() << "\n";
    saveMemories(file);

    file.close();
}

bool loadGame()
{
    ifstream file("mirror_save.txt");

    if (!file)
        return false;

    getline(file, playerName);

    file >> memoryNumber;
    file >> courage;
    file >> curiosity;
    file >> trust;
    file >> defiance;
    file >> predictions;
    file >> option1;
    file >> option2;
    file >> option3;
    file >> gameFinished;

    int savedCount;
    file >> savedCount;
    file.ignore();

    loadMemories(file, savedCount);

    file.close();
    return true;
}
