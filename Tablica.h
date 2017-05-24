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
    static const int maxP=1, maxK=2;

public:
    std::string rysuj();
    Tablica();
    void dodaj(Obiekt<Figura> *obiekt);
    void usun(int id);
    void modyfikuj(int id, double skala, int rot, std::vector<int> wsp, double gruLin, std::string kolLin, std::string kolWyp);
    void setId(int id);
    int getId() const;
    void sprawdz_figury(int id);
    int sprawdz_ilosc(std::string co_liczyc);
    const std::list<Obiekt<Figura> *> &getObiekty() const;

};


#endif // TABLICA_H_INCLUDED
