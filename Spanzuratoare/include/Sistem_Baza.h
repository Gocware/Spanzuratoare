#ifndef SISTEM_BAZA_H
#define SISTEM_BAZA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

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
};
class Joc
{
    public :
        int formeazaJoc(char categ_param[100], ifstream&fisier); // Implementat
        void actualizareInteractiuneJucator(char mesaj);
        void reset();
    private :
        char categorie[100];
        char string_curent[100];
};
class Date_Utilizator
{
     public :
         Date_Utilizator *urmatorul;
         int nrVictorii, nrPierderi, jocuriActive;
         int indice;
         char nume[100], rang[100];
         Joc joc_curent;
         Date_Utilizator();
         void formareUtilizator(char nume_param[100], Joc &joc);
};
class Lista_Utilizatori
{
     public :
         Lista_Utilizatori(); // Implementat
         ~Lista_Utilizatori(); // Implementat
         Date_Utilizator *inceput, *travers;
         void adauga(Date_Utilizator utilizator_nou); // Implementat
         void scrieListaInFisier(ofstream &fisier);
         void initializeazaListaDinFisier(ifstream &fisier);
         Date_Utilizator *gaseste_utilizator(int poz); // Implementat
         unsigned nrUtilizatori(); // Implementat
};
#endif // SISTEM_BAZA_H
