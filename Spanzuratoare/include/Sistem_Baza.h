#ifndef SISTEM_BAZA_H
#define SISTEM_BAZA_H
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Sectiune_Text
{
    public :
        Sectiune_Text();
        Sectiune_Text *urmatorul;
        unsigned indice;
        char text[100];
};
class Sectiune_Text_Lista
{
    public :
        Sectiune_Text_Lista(); // Implementat
        ~Sectiune_Text_Lista(); // Implementat
        unsigned nrElemente(); // Implementat
        void stergeLista(); // Implementat
        void adaugaLinie(char text[100]); // Implementat
        void gasesteText(unsigned indice_cautare, char text[100]); // Implementat
    private :
        Sectiune_Text *travers, *inceput;
};
class Sistem_Baza
{
    public:
        static unsigned liniiScrise(ifstream &fisier); // Implementat
        static void scrieParagraf(ifstream &fisier, char delimitare[20], Sectiune_Text_Lista &lista); // Implementat
    private:
        static char utilizator_curent[100];
        static Sectiune_Text_Lista lista_utilizatori;
};
class Joc
{
    public :
        Joc();
        void formeazaJoc(char categ_param[100]);
        void actualizare(char mesaj);
        void reset();
    private :
        char categorie[100];
        char string_curent[100];
};
class Date_Utilizator
{
     public :
         Date_Utilizator();
         char nume[100];
         Joc joc_curent;
         void formareUtilizator(char nume_param[100], Joc &joc);
         Date_Utilizator *urmatorul;
};
class Lista_Utilizatori
{
     public :
         Lista_Utilizatori();
         Date_Utilizator *inceput, *travers;
         void adauga(Date_Utilizator utilizator_nou); // Implementat
         Date_Utilizator *gaseste_utilizator(char nume[100]); // Implementat
         unsigned nrUtilizatori(); // Implementat
};
#endif // SISTEM_BAZA_H
