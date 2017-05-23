#ifndef OBIEKT_H_INCLUDED
#define OBIEKT_H_INCLUDED

#include <iostream>
#include <vector>

template<class argSzabl>
class Obiekt
{
    protected:
        argSzabl figura;
        std::string fig;

    public:
        virtual void modyfikuj(std::vector<int> wektor) = 0;
        virtual void modyfikuj(int kat) = 0;
        virtual void modyfikuj(double skala) = 0;
        virtual std::string rysuj() = 0;

        const std::string &getFig() const {
            return fig;
         }

         void setFig(const std::string &fig) {
            Obiekt::fig = fig;
         }

    argSzabl getFigura() const {
            return figura;
        }


};


#endif // OBIEKT_H_INCLUDED
