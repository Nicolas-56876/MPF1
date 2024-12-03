#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayWord(const string &word, const vector<bool> &guessed) {
    for (int i = 0; i < word.size(); i++) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const vector<bool> &guessed) {
    for (bool letterGuessed : guessed) {
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}

void drawHangman(int attemptsLeft) {
    switch (attemptsLeft) {
        case 6:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 5:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 4:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|       |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 3:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 2:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 1:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|      /" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
        case 0:
            cout << "_________" << endl;
            cout << "|       |" << endl;
            cout << "|       O" << endl;
            cout << "|      /|\\" << endl;
            cout << "|      / \\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            break;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Semilla para números aleatorios

    // Lista de palabras para adivinar
    vector<string> words = {"computadora", "programacion", "ahorcado", "algoritmo", "sistemas"};
    string word = words[rand() % words.size()]; // Selecciona una palabra aleatoria

    vector<bool> guessed(word.size(), false);   // Letras adivinadas
    int attemptsLeft = 6;                       // Intentos restantes
    vector<char> incorrectGuesses;              // Letras incorrectas

    cout << "¡Bienvenido al juego de Ahorcado!" << endl;

    while (attemptsLeft > 0 && !isWordGuessed(guessed)) {
        drawHangman(attemptsLeft);
        displayWord(word, guessed);
        cout << "Letras incorrectas: ";
        for (char c : incorrectGuesses) {
            cout << c << " ";
        }
        cout << endl;

        cout << "Intentos restantes: " << attemptsLeft << endl;
        cout << "Introduce una letra: ";
        char guess;
        cin >> guess;

        bool isCorrectGuess = false;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = true;
                isCorrectGuess = true;
            }
        }

        if (!isCorrectGuess) {
            incorrectGuesses.push_back(guess);
            attemptsLeft--;
        }
    }

    if (isWordGuessed(guessed)) {
        cout << "¡Felicidades! Adivinaste la palabra: " << word << endl;
    } else {
        drawHangman(0);
        cout << "Lo siento, has perdido. La palabra era: " << word << endl;
    }

    return 0;
}
