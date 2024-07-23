#include <iostream>
#include <cmath>
using namespace std;

struct kletka                   //здесь я создал структуру для клеток
{
    char letter;
    int number;
};


void in (kletka &a)           //функция для ввода клеток
{
    cin >> a.letter >> a.number;
}


void input (kletka &one, kletka &two)           //функция для ввода клеток
{
    cout << "Введите координаты первой ячйки" << endl;
    in(one);
    cout << "Введите координаты второй ячйки" << endl;
    in(two);
}



void chek (kletka one, kletka two)                      //проверка на клетку. есть такая на доске или нет.
{
    char a = one.letter;
    char b = two.letter;

    if ((('h'>=a)&&(a>='a'))||(('H'>=a)&&(a>='A')))
        {
            if (((104>=b)&&(b>=97))||((72>=b)&&(b>=65)))
            {
                if ((8>=one.number)&&(one.number>=1))
                {
                    if ((8>=two.number)&&(two.number>=1))
                    {
                        return ;
                    }
                }
            }
        }
    cout << "Вы ввели неверные значения";
    exit (0);                                               //завершает всю прогу
}

int diagonal (kletka one, kletka two)
{
    int a = one.letter;
    int b = two.letter;
    if (('h'>=a)&&(a>='a'))
    {
        a = a - 32;
    }
    if (('h'>=b)&&(b>='a'))
    {
        b = b - 32;
    }
    a = a - 64;
    b = b - 64;

    int c, d;
    c = abs( a - b);
    d = abs(one.number - two.number);

    if (c == d)
    {
        return 1;
    }
    else
    {
        return 0;
    }

   // return (c==d)                     // тоже самое что и if (c==d) и т.д.

};

void compare (kletka one, kletka two)
{
    int z;
    z = diagonal (one, two);
    if (one.letter == two.letter)
    {
        cout << "Yes";
    }
    else if (one.number==two.number)
    {
        cout << "Yes";
    }
    else if (z==1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }


   // if (one.letter == two.letter || one.number==two.number || diagonal (one, two))

}

int main()
{
    kletka one{}, two{};
    input (one, two);
    chek (one, two);
    compare (one, two);
    return 0;
}
