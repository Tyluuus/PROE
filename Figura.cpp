#include "Figura.h"

unsigned Figura::n = 0;

Figura::Figura(const std::vector<int> &wsp, double gruLin, const std::string &kolLin, const std::string &kolWyp)
    : wsp(wsp), gruLin(gruLin), kolLin(kolLin), kolWyp(kolWyp)
{
    id = n;
    n++;
}

const std::vector<int> &Figura::getWsp() const {
    return wsp;
}

void Figura::setWsp(const std::vector<int> &wsp) {
    Figura::wsp = wsp;
}

double Figura::getGruLin() const {
    return gruLin;
}

void Figura::setGruLin(double gruLin) {
    Figura::gruLin = gruLin;
}

const std::string &Figura::getKolLin() const {
    return kolLin;
}

void Figura::setKolLin(const std::string &kolLin) {
    Figura::kolLin = kolLin;
}

const std::string &Figura::getKolWyp() const {
    return kolWyp;
}

void Figura::setKolWyp(const std::string &kolWyp) {
    Figura::kolWyp = kolWyp;
}

int Figura::getRot() const {
    return rot;
}

void Figura::setRot(int rot) {
    Figura::rot = rot;
}

double Figura::getSkala() const {
    return skala;
}

void Figura::setSkala(double skala) {
    Figura::skala = skala;
}

int Figura::getId() const {
    return id;
}

