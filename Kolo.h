#ifndef KOLO_H_INCLUDED
#define KOLO_H_INCLUDED

#include <iostream>
#include "Obiekt.h"
#include "Figura.h"

class Kolo
    : public Obiekt<Figura>
    {
        private:
            int r;
            int licz=0;
            std::string naz="K";

        public:
            Kolo(int r);
            ~Kolo();
            virtual std::string rysuj();
            virtual void modyfikuj(std::vector<int> wektor);
            virtual void modyfikuj(int kat);
            virtual void modyfikuj(double skala);
            virtual std::string wymiary();


    };

#endif // KOLO_H_INCLUDED
