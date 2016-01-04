#include "Grafica.h"
void ProfilUtilizator::initProfil(char nume[100],char rang[100],int jocuriActive)
{
    char strAfis[250];
    strcpy(strAfis,nume);
    strcat(strAfis,"\n");
    strcat(strAfis,rang);
    strcat(strAfis,"\n");
    strcat(strAfis,jocuriActive + "0");
    texture.loadFromFile("grafica/bg_profil.jpg");
    sprite.setTexture(texture);
    sf::FloatRect spriteRect = sprite.getLocalBounds();
    sprite.setOrigin(spriteRect.width/2,spriteRect.height/2);
    text.setString(strAfis);
    font.loadFromFile("grafica/font1.ttf");
    text.setFont(font);
    text.setOrigin(0,0);
    text.setCharacterSize(50);
}
void ProfilUtilizator::afiseazaProfil(sf::RenderWindow &fereastra)
{
    fereastra.draw(sprite);
    fereastra.draw(text);
}

