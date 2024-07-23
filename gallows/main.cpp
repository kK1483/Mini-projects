#include <iostream>
#include <vector>
#include "wordsList.h"

using namespace std;

// КОДИРОВКА IBM 866

void start (int &number)
{
    cout << endl << "выберите режим игры" << endl << "1. Играть с компьютером " << endl << "2. Играть с другом " << endl << "3. Правила" << endl << "0. Выход" << endl;
    cin >> number;
}

char decrease (char a)                              //Приводит буквы к одному регистру
{
    int b;
    b =a;
    if (-112>b && b>-129)
       {
        a = a+32;
       }
    else if (-96 > b && b > -113)
       {
    a = a+80;
       }
    return a;
}

//void print_alphabet (vector <char> alphabet, vector <char> letters, string word, char letter)
//{
//    vector <char> word_letter;
//    cout << "выберете букву:    ";
//
//}


void gallows_paint (int error, string word)
{
    switch (error)
    {
        case 0:
            cout << endl << " " << endl << " " <<endl<< " " << endl << " " << endl<< " " << endl<< " " << endl << " " << endl;
            break;
        case 1:
            cout << endl << " " << endl << " " <<endl<< " " << endl << " " << endl<< " " << endl<< " " << endl << "=========" << endl;
            break;
        case 2:
            cout << endl << "  +---+" << endl << "      |" <<endl<< "      |" << endl << "      |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 3:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "      |" << endl << "      |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 4:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << "      |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 5:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << "  |   |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 6:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << " /|   |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 7:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << " /|\\  |" << endl<< "      |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 8:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << " /|\\  |" << endl<< " /    |" << endl<< "      |" << endl << "=========" << endl;
            break;
        case 9:
            cout << endl << "  +---+" << endl << "  |   |" <<endl<< "  O   |" << endl << " /|\\  |" << endl<< " / \\  |" << endl<< "      |" << endl << "=========" << endl;
            cout << "ВЫ ПРОИГРАЛИ" << endl << endl << "Это было слово: " <<  word << endl;
            break;
        default:
            return ;
    }
}

void write_word (vector<bool> right,string word)
{
    for (int i = 0; i<word.size() ; i++)
        {
            if (right[i] == 1)
                {
                    cout << word[i] << " ";
                }
            else
                {
                    cout << "_ ";
                }
        }
    cout << endl << endl;
}


bool contains_char(string word, int letter, vector<bool> &right)
{
    bool ret = 0;
    for (int i = 0; i<word.size(); i++)
        {
            if (letter == word[i])
                {
                    right[i]=true;
                    ret = 1;
                }
        }
    return ret;
}

bool is_win (vector<bool> right, int letter_size)
{
    for (int i = 0; i<letter_size; i++)
    {
        if (right[i]==0)
        {
            return 0;
        }
    }
    return 1;
}


void Game (string word)
{
    cout << "Игра началась." << endl << endl;
    int letter_size = word.size(), error = 0;
    char letter;



    vector <bool> right(letter_size, false);
    vector <char> letters;
    vector <char> alphabet;
    char a = 'А';
    for (int i = 0; i<32; i++)
    {
        alphabet.push_back(a);
        a = a+1;
    }

    write_word (right, word);

    while (error < 9)
        {
//        print_alphabet (alphabet, letters, word, letter);
        cout << endl << "Введите  букву:";
        cin >> letter;
        letter = decrease (letter);
        letters.push_back(letter);
            if (contains_char(word, letter, right) == 0)
                {
                    error++;
                }
        write_word (right, word);
        gallows_paint (error, word);
        if (is_win(right, letter_size)==1)
        {
            cout << "ВЫ ВЫИГРАЛИ!" << endl;
            return;
        }
        }
}



void GamePC ()
{
    string word;
    cout << "Компьютер выбрал слово." << endl;
    wordsList book;
    word = book.get_word();
    Game (word);
}

void GameFrend ()
{
    string word;
    cout << "Введите слово. Слово должно быть существительным в именительном падеже, в единственном числе, на русском языке и написанно только маленькими буквами." << endl;
    cin >> word;
    cout << endl << endl << endl << endl << endl << endl << endl<<endl<<endl<<endl;
    Game (word);

}

void Rules ()
{
    int a = 0;
    cout << endl << "Игрок должен отгадать русское слово по букве за 9 попыток." << endl << "Каждая неудачная попытка пририсовывает деталь к висилице." << endl;
    cout << "Слово является именем существительным, напсианным маленькими буквами. Слово загадано в именительном падеже, в единственном числе." << endl << "ВАЖНО - ИСПОЛЬЗУЙТЕ МАЛЕНЬКИЕ БУКВЫ" << endl;
    while (a != 1)
        {
            cout << endl << "Для возвращения в меню введите 1" << endl;
            cin >> a;
        }

}


void choice (int input)
{
    if (input == 1)
        {
            GamePC ();
        }
    else if (input == 2)
        {
            GameFrend ();
        }
    else if (input == 3)
        {
            Rules();
        }
    else if (input == 0)
        {
            cout << endl << "Спасибо за игру!" << endl;
            exit (0);
        }
    else
        {
            cout << "Вы ввели неверное значение, попробуйте снова.";
        }
}

int main()
{

    // std::cout << "\033[1;31m";   // переключает цвет на красный
  // std::cout << "\033[1;32m"; // переключает цвет на зеленый
    //    std::cout << "\033[0m"; // Сбрасываем цвет текста


    while (1)
        {
            int number;
            start(number);
            choice(number);
        }
}
