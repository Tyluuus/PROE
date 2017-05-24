#ifndef PROSTOKAT_H_INCLUDED
#define PROSTOKAT_H_INCLUDED

#include <iostream>
#include "Obiekt.h"
#include "Figura.h"
#include "Wyjatek.h"


class Prostokat
    : public Obiekt<Figura>
    {
        private:
            int licz=0;
            int a, b;


            public:
            Prostokat(int a, int b);
            ~Prostokat();
            virtual std::string rysuj();
            virtual void modyfikuj(std::vector<int> wektor);
            virtual void modyfikuj(int kat);
            virtual void modyfikuj(double skala);
            virtual std::string wymiary();
};



#endif // PROSTOKAT_H_INCLUDED

