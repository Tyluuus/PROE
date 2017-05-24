//
// Created by tyluus on 14.05.17.
//

#include "Kolo.h"

std::string Kolo::rysuj()
{
    std::vector<int> wsp = Obiekt::figura.getWsp();

    std::string circ;
    circ += "<circle";

    circ += " cx=\"" + std::to_string(wsp[0]);
    circ += "\" cy=\"" + std::to_string(wsp[1]);
    circ += "\" r=\"" + std::to_string(r*Obiekt::figura.getSkala());
    circ += "\" fill=\"" + Obiekt::figura.getKolWyp();
    circ += "\" stroke=\"" + Obiekt::figura.getKolLin();
    circ += "\" stroke-width=\"" + std::to_string(Obiekt::figura.getGruLin());
    circ += "\" z-index= \"" + std::to_string(wsp[2]);
    circ += "\" transform=\"rotate(" + std::to_string(Obiekt::figura.getRot());
    circ += " , " + std::to_string(wsp[0]/2) + " , " + std::to_string(wsp[1]/2);
    circ += ")\" />";
    return circ;

}

void Kolo::modyfikuj(std::vector<int> wektor) {
    std::vector<int> wsp = Obiekt::figura.getWsp();
    for (int i = 0; i < 3; ++i) {
        wsp[i] += wektor[i];
    }
    Obiekt::figura.setWsp(wsp);
}

void Kolo::modyfikuj(int kat) {
    Obiekt::figura.setRot(kat);
}

void Kolo::modyfikuj(double skala) {
    Obiekt::figura.setSkala(skala);
}

Kolo::Kolo(int r) : r(r)
{
    licz++;
    Obiekt::setFig("Kolo");
}
Kolo::~Kolo(){licz--;}

std::string Kolo::wymiary() {

    std::string wymiary;
    wymiary += " r = " + std::to_string(r);
    return wymiary;
}


