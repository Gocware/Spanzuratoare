#ifndef COMUNICARE_H
#define COMUNICARE_H

#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

#define ACCES_TASTATURA 1

class Comunicare
{
    public:
        void verifInchidere(sf::RenderWindow &fereastra,sf::Event &ev);
        std::string interactTastatura(sf::RenderWindow &fereastra,sf::Event &ev);
        std::string text_dl_tastatura;
    private:

};

#endif // COMUNICARE_H
