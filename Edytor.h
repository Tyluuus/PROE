//
// Created by tyluus on 14.05.17.
//

#ifndef PROE2_EDYTOR_H
#define PROE2_EDYTOR_H
#include "Tablica.h"
#include "Prostokat.h"
#include "Kolo.h"
#include <vector>

class Edytor
{
private:
    std::vector<Tablica> tablice;
public:
    void konsola();
    void dodawanie();
    void modyfikuj();
    void usun();
    void zapisywanie();
    void dodaj_tablice();
    void usun_tablice();
    void sprawdz_tablice(int id);
    int przeszukaj_tablice(int id);
    int znajdz_tablice(int id);

};



#endif //PROE2_EDYTOR_H
