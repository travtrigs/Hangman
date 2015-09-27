#include <iostream>
#include <string>
using namespace std;


//gets phrase from user
string getPhrase() {
    string phrase;
    cout << "Please type a phrase: ";
    getline(cin, phrase);
    for (int i = 0; i < 5; i++) cout << "\n";
    return phrase;
}
string phrase = getPhrase();

//gets size of phrase
int getSize() {
    int size = (int) phrase.size();
    return size;
}
int size = getSize();

//makes arrays for input, found letters, and output
void makeArray(char input[], bool found[], char output[]) {
    for (int i = 0; i < size; i++) {
        input[i] = phrase.at(i);
        if (input[i] == ' ') {
            found[i] = true;
            output[i] = ' ';
        }
        else {
            found[i] = false;
            output[i] = '_';
        }
        cout << output[i] << " ";
    }
}

//checks if game is won
bool win(bool found[]) {
    for (int i = 0; i < size; i++) {
        if (!found[i]) return false;
    }
    return true;
}

//checks if letter is wrong
bool isWrong(char input[], char letter) {
    for (int i = 0; i < size; i++) {
        if (input[i] == letter) {
            return false;
        }
    }
    return true;
}

//gets letter from user
void getLetter(char input[], bool found[], char output[]) {
    int wrong;
    char letter;
    string errors;
    while (!win(found)) {
        cout << "\nGuess a letter: "; cin >> letter;
        for (int i = 0; i < size; i++) {
            if (!found[i]) {
                if (input[i] == letter) {
                    found[i] = true;
                    output[i] = letter;
                }
            }
        }
        if (isWrong(input, letter)) {
            wrong++;
            errors += letter;
            if (wrong == 6) {
                cout << "You lose!";
                return;
            }
            cout << letter << " was not found. You have ";
            cout << 6 - wrong << " errors left!\n";
        }
        if (win(found)) {
            cout << "You win!";
            return;
        }
        cout << "Incorrect letters: " << errors << "\n";
        for (int i = 0; i < size; i++) {
            cout << output[i] << " ";
        }
    }
}

//main function
int main() {
    char input [size];
    bool found [size];
    char output [size];

    makeArray(input, found, output);
    getLetter(input, found, output);
}