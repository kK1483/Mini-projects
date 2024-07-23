#include <iostream>
#include <cmath>
using namespace std;

struct kletka                   //§¤¥áì ï á®§¤ « áâàãªâãàã ¤«ï ª«¥â®ª
{
    char letter;
    int number;
};


void in (kletka &a)           //äã­ªæ¨ï ¤«ï ¢¢®¤  ª«¥â®ª
{
    cin >> a.letter >> a.number;
}


void input (kletka &one, kletka &two)           //äã­ªæ¨ï ¤«ï ¢¢®¤  ª«¥â®ª
{
    cout << "‚¢¥¤¨â¥ ª®®à¤¨­ âë ¯¥à¢®© ïç©ª¨" << endl;
    in(one);
    cout << "‚¢¥¤¨â¥ ª®®à¤¨­ âë ¢â®à®© ïç©ª¨" << endl;
    in(two);
}



void chek (kletka one, kletka two)                      //¯à®¢¥àª  ­  ª«¥âªã. ¥áâì â ª ï ­  ¤®áª¥ ¨«¨ ­¥â.
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
    cout << "‚ë ¢¢¥«¨ ­¥¢¥à­ë¥ §­ ç¥­¨ï";
    exit (0);                                               //§ ¢¥àè ¥â ¢áî ¯à®£ã
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

   // return (c==d)                     // â®¦¥ á ¬®¥ çâ® ¨ if (c==d) ¨ â.¤.

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
