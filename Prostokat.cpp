//
// Created by tyluus on 14.05.17.
//

#include <vector>
#include "Prostokat.h"

void Prostokat::modyfikuj(std::vector<int> wektor) {
    std::vector<int> wsp = Obiekt::figura.getWsp();
    for (int i = 0; i < 3; ++i) {
        wsp[i] += wektor[i];
    }
    Obiekt::figura.setWsp(wsp);
}

void Prostokat::modyfikuj(int kat) {
    Obiekt::figura.setRot(kat);
}

void Prostokat::modyfikuj(double skala) {
    Obiekt::figura.setSkala(skala);
}

std::string Prostokat::rysuj() {
    std::vector<int> wsp = Obiekt::figura.getWsp();

    std::string ret;
    ret += "<rect";

    ret += " x=\"" + std::to_string(wsp[0]);
    ret += "\" y=\"" + std::to_string(wsp[1]);
    ret += "\" width=\"" + std::to_string(a*Obiekt::figura.getSkala());
    ret += "\" height=\"" + std::to_string(b*Obiekt::figura.getSkala());

    ret += "\" style=\"";
    ret += "fill:" + Obiekt::figura.getKolWyp();
    ret += ";stroke:" + Obiekt::figura.getKolLin();
    ret += ";stroke-width:" + std::to_string(Obiekt::figura.getGruLin());
    ret += "\"z-index: \"" + std::to_string(wsp[2]);
    ret += "\" transform=\"rotate(" + std::to_string(Obiekt::figura.getRot());
    ret += " , " + std::to_string(a/2) + " , " + std::to_string(b/2);
    ret += ")\" />";
    return ret;
}



Prostokat::Prostokat(int a, int b) : a(a), b(b)
{
    Prostokat::licz++;
    Obiekt::setFig("Prostokat");
}
Prostokat::~Prostokat(){Prostokat::licz--; }



