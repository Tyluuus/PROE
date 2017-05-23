#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

#include <iostream>
#include <vector>

class Figura
{
    protected:
        static unsigned n;
        int id;
        std::vector<int> wsp;
        double gruLin;
        std::string kolLin;
        std::string kolWyp;
        int rot=0;
        double skala=1;


    public:
        Figura(const std::vector<int> &wsp = std::vector<int>(3, 0), double gruLin = 1, const std::string &kolLin = "black", const std::string &kolWyp = "none");
        const std::vector<int> &getWsp() const;
        void setWsp(const std::vector<int> &wsp);
        double getGruLin() const;
        void setGruLin(double gruLin);
        const std::string &getKolLin() const;
        void setKolLin(const std::string &kolLin);
        const std::string &getKolWyp() const;
        void setKolWyp(const std::string &kolWyp);
        int getRot() const;
        void setRot(int rot);
        double getSkala() const;
        void setSkala(double skala);
        int getId() const;

};


#endif // FIGURA_H_INCLUDED
