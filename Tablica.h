#ifndef TABLICA_H_INCLUDED
#define TABLICA_H_INCLUDED

#include <iostream>
#include <list>
#include "Obiekt.h"
#include "Figura.h"

#include <fstream>

class Tablica
{
private:
    std::list<Obiekt<Figura>*> obiekty;
    int id=0;
    static unsigned n;
    static const unsigned limit = 2;
    static const int maxP=1, maxK=2;

public:
    std::string rysuj();
    Tablica();
    void dodaj(Obiekt<Figura> *obiekt);
    void usun(int id);
    void modyfikuj(int id, double skala, int rot, std::vector<int> wsp);
    void setId(int id);
    int getId() const;
    void sprawdz_figury(int id);
    int sprawdz_ilosc(std::string co_liczyc);

};


#endif // TABLICA_H_INCLUDED
