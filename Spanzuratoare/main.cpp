#include "Buton.h"
#include "Comunicare.h"
int main()
{
    Comunicare instanta_comunic;
    sf::RenderWindow f(sf::VideoMode(1280,720),"Joc Magnific");
    sf::Text txt;
    txt.setCharacterSize(20);
    sf::Font font;
    font.loadFromFile("grafica/font1.ttf");
    txt.setFont(font);
    while(f.isOpen())
    {
        sf::Event ev;
        while(f.pollEvent(ev))
        {
            f.clear();
            instanta_comunic.verifInchidere(f,ev);
            instanta_comunic.interactTastatura(f,ev);
        }
        txt.setString(instanta_comunic.text_dl_tastatura);
        f.draw(txt);
        f.display();
    }
    return 0;

}
