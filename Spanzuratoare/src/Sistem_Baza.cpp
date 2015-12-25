#include <Sistem_Baza.h>
using namespace std;
unsigned Sistem_Baza :: liniiScrise(ifstream &fisier)
{
    unsigned numarLinii = 0;
    char stocare_date_temp[20];
    while(fisier.getline(stocare_date_temp,20))++numarLinii;
    return numarLinii;
}
void Sistem_Baza :: scrieParagraf(ifstream &fisier, char delimitare[20], Sectiune_Text_Lista &lista)
{
    char text[100];
    fisier.getline(text,20);
    while(!strstr(text,delimitare))
         fisier.getline(text,20);
    fisier.getline(text,20);
    while(!strstr(text,delimitare))
    {
        lista.adaugaLinie(text);
        fisier.getline(text,20);
    }
}
Sectiune_Text :: Sectiune_Text()
{
    urmatorul = 0;
}
Sectiune_Text_Lista :: Sectiune_Text_Lista()
{
    travers = 0;
}
Sectiune_Text_Lista :: ~Sectiune_Text_Lista()
{
    stergeLista();
}
unsigned Sectiune_Text_Lista::nrElemente()
{
    Sectiune_Text *parcurgere = inceput;
    if(!parcurgere)return 0;
    else
    {
        unsigned nr_Elemente = 1;
        while(parcurgere->urmatorul)
        {
           ++nr_Elemente;
           parcurgere = parcurgere->urmatorul;
        }
        return nr_Elemente;
    }
}
void Sectiune_Text_Lista::adaugaLinie(char text[100])
{
    if(travers == 0)
    {
        travers = new Sectiune_Text();
        travers->indice = 1;
        strcpy(travers->text,text);
        inceput = travers;
    }
    else
    {
        int indice = travers->indice;
        while(travers->urmatorul)
        {
            travers = travers->urmatorul;
            ++indice;
        }
        travers->urmatorul = new Sectiune_Text();
        travers->urmatorul->indice = indice+1;
        strcpy(travers->urmatorul->text,text);
    }
}
void Sectiune_Text_Lista::gasesteText(unsigned indice_cautare, char text[100])
{
    Sectiune_Text *parcurgere = inceput;
    while(parcurgere->indice != indice_cautare && parcurgere->urmatorul!=0)
        parcurgere = parcurgere->urmatorul;
    strcpy(text,parcurgere->text);
}
void Sectiune_Text_Lista::stergeLista()
{
    Sectiune_Text *parcurgere = inceput;
    while(parcurgere->urmatorul)
    {
        Sectiune_Text *ptr_copie = parcurgere->urmatorul;
        delete parcurgere;
        parcurgere = ptr_copie;
    }
}
Lista_Utilizatori :: Lista_Utilizatori()
{
    travers = 0;
}
void Lista_Utilizatori :: adauga(Date_Utilizator utilizator_nou)
{
    if(travers == 0)
    {
        travers = &utilizator_nou;
        inceput = travers;
    }
    else
    {
        while(travers->urmatorul)
            travers = travers->urmatorul;
        travers->urmatorul = &utilizator_nou;
    }
}
Date_Utilizator *Lista_Utilizatori :: gaseste_utilizator(char nume[100])
{
    Date_Utilizator *verificare = inceput;
    while(verificare->urmatorul && verificare->urmatorul->nume != nume)
        verificare = verificare->urmatorul;
    return verificare->urmatorul;
}
unsigned Lista_Utilizatori ::nrUtilizatori()
{
    unsigned nr_Util = 1;
    while(travers->urmatorul)
    {
        ++nr_Util;
        travers = travers->urmatorul;
    }
    return nr_Util;
}
Date_Utilizator :: Date_Utilizator()
{
    urmatorul = 0;
}
