#include <SFML/Graphics.hpp>
#include "Sistem_Baza.h"
int main()
{
    ifstream bazaDate("baza.txt");
    Sectiune_Text_Lista s1;
    Sistem_Baza :: scrieParagraf(bazaDate,"ParagrafDelim",s1);
    cout<<s1.nrElemente()<<' ';
    return 0;
}
