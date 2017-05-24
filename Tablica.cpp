//
// Created by tyluus on 14.05.17.
//

#include "Tablica.h"
#include "Wyjatek.h"

unsigned Tablica::n = 0;

std::string Tablica::rysuj() {
    std::string ret;
    std::fstream plik;

    ret += "<svg>\n";

    for (auto i = obiekty.begin(); i != obiekty.end(); i++) {
        ret += (*i)->rysuj() + "\n";
    }

    ret += "</svg>";
    plik.open("test.svg",std::ios::out);
    plik<<ret<<std::endl;
    plik.close();
    return "test.svg";
}

void Tablica::dodaj(Obiekt<Figura> *obiekt)
{
        if(obiekt->getFig()=="Prostokat")
        {
            if(sprawdz_ilosc("Prostokat")==maxP){
                throw Wyjatek("Osiagnieto limit prostokatow dla tej tablicy.");
            }
            obiekty.push_back(obiekt);
        }

       /* if(obiekty.size() >= limit) {
            throw Wyjatek("Osiągnięty został limit obiektów w tablicy.");
        }
        obiekty.push_back(obiekt); */

        if(obiekt->getFig()=="Kolo")
         {
             if(sprawdz_ilosc("Kolo")==maxK)
             {
                 throw Wyjatek("Osiagnieto limit kol dla tej tablicy.");
             }
            obiekty.push_back(obiekt);
        }
}

void Tablica::usun(int id)
{
       sprawdz_figury(id);
        for (auto i = obiekty.begin(); i != obiekty.end(); i++)
        {
            if ((*i)->getFigura().getId() == id) {
                obiekty.erase(i);
                delete(*i);
                break;
            }
        }
}

void Tablica::modyfikuj(int id, double skala, int rot, std::vector<int> wsp, double gruLin, std::string kolLin, std::string kolWyp)
{

        for(auto i = obiekty.begin(); i!= obiekty.end(); i++)
        {
            if((*i)->getFigura().getId() == id)
            {
                (*i)->modyfikuj(skala);
                (*i)->modyfikuj(rot);
                (*i)->modyfikuj(wsp);
                (*i)->getFigura().setGruLin(gruLin);
                (*i)->getFigura().setKolLin(kolLin);
                (*i)->getFigura().setKolWyp(kolWyp);
            }
        }
}

int Tablica::getId() const {
    return id;
}

void Tablica::setId(int id) {
    Tablica::id = id;
}

Tablica::Tablica()
{
    id=n;
    n++;
}

void Tablica::sprawdz_figury(int id)
{
    int t=0;
    for (auto i = obiekty.begin(); i != obiekty.end(); i++)
    {
        if((*i)->getFigura().getId() == id)
        {
            t=1;
            break;
        }
    }
    if(t==0)
        throw Wyjatek("Nie istnieje figura o takim id! ");

}
int Tablica::sprawdz_ilosc(std::string co_liczyc)
{
    int licznik=0;
    if(co_liczyc=="Kolo") {
        for (auto i = obiekty.begin(); i != obiekty.end(); i++) {
            if ((*i)->getFig() == "Kolo")licznik++;
        }
    return licznik;
    }
    if(co_liczyc=="Prostokat")
    {
        for (auto i = obiekty.begin(); i != obiekty.end(); i++) {
            if ((*i)->getFig() == "Prostokat")licznik++;
        }
        return licznik;
    }
}

const std::list<Obiekt<Figura> *> &Tablica::getObiekty() const {
    return obiekty;
}




//obiekt->getFigura().getId() (31. linia)

