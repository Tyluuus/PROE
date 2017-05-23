//
// Created by tyluus on 15.05.17.
//
#include "Edytor.h"
using namespace std;

void Edytor::konsola()
{
    int kontrola=1;
    while(kontrola!=0)
    {
        cout<<"Wybierz co chcesz zrobic. (wcisnij podany w nawiasie przycisk i zatwierdz)"<<endl;
        cout<<"Dodaj figure (1)"<<endl;
        cout<<"Modyfikuj figure (2)"<<endl;
        cout<<"Usun figure (3)"<<endl;
        cout<<"Zapisz figury do pliku (4)"<<endl;
        cout<<"Dodaj tablice (5)"<<endl;
        cout<<"Usun tablice (6)"<<endl;
        cout<<"Zamknij program (0)"<<endl;
        cout<<"Wcisnij odpowiedni przycisk: ";
        cin>>kontrola;
        if(kontrola==1)
        {
            try {
                dodawanie();
            }
            catch(Wyjatek wyjatek)
            {
                cout<<wyjatek.getMsg()<<endl;
            }
        }
        if(kontrola==2)
        {
            try{
            modyfikuj();
            }
            catch(Wyjatek wyjatek)
            {
                cout<<wyjatek.getMsg()<<endl;
            }
        }
        if(kontrola==3)
        {
            try{
            usun();
            }
            catch(Wyjatek wyjatek)
            {
                cout<<wyjatek.getMsg()<<endl;
            }
        }
        if(kontrola==4)
        {
            try{
            zapisywanie();
            }
            catch(Wyjatek wyjatek)
            {
                cout<<wyjatek.getMsg()<<endl;
            }
        }
        if(kontrola==5)
        {
            dodaj_tablice();
        }
        if(kontrola==6)
        {
            try {
                usun_tablice();
            }
            catch(Wyjatek wyjatek)
            {
                cout<<wyjatek.getMsg()<<endl;
            }
        }
        if(kontrola==0)
        {
            exit;
        }

    }
}

void Edytor::dodawanie()
{
    if(tablice.empty())
    {
        throw Wyjatek("Aby zrobic cokolwiek musisz najpierw dodac pierwsza tablice!");
    }
    int wybor=0, id=0;
    cout<<"Dodajesz figure."<<endl;
    if(tablice.size()>1) {
        cout << "Podaj id tablicy do ktorej chcesz zapisywac figury: ";
        cin >> id;
    }
    try
    {
        sprawdz_tablice(id);
    }
    catch(Wyjatek wyjatek)
    {
        cout<<wyjatek.getMsg()<<endl;
    }
    cout<<"Jaka figure chcesz dodac?"<<endl;
    cout<<"1. Prostokat"<<endl;
    cout<<"2. Kolo"<<endl;
    cout<<"Podaj odpowiedni identyfikator: ";
    cin>>wybor;
    if(wybor==1)
    {
        int a,b;
        cout<<"Podaj dlugosci bokow a i b: ";
        cin>>a>>b;
        Prostokat *prostokat = new Prostokat(a, b);
        try
        {
            tablice[id].dodaj(prostokat);
            cout << "Dodano prostokat o id= " << prostokat->getFigura().getId() << endl;
        }
        catch(Wyjatek wyjatek)
        {
            cout<<wyjatek.getMsg()<<endl;
        }

    }
    if(wybor==2)
    {
        int r;
        cout<<"Podaj promien kola: ";
        cin>>r;
        Kolo *kolo = new Kolo(r);
        try
        {
            tablice[id].dodaj(kolo);
            cout<<"Dodano kolo o id= "<<kolo->getFigura().getId()<<endl;
        }
        catch(Wyjatek wyjatek)
        {
            cout<<wyjatek.getMsg()<<endl;
        }
    }
}
void Edytor::modyfikuj()
{
    if(tablice.empty())
    {
        throw Wyjatek("Aby zrobic cokolwiek musisz najpierw dodac pierwsza tablice!");
    }
    int id=0,idT=0, rot=0;
    char znak='k';
    double skala=1;
    vector<int> wsp;
    wsp.push_back(0);
    wsp.push_back(0);
    wsp.push_back(0);
    cout<<endl<<"Podaj id figury ktora chcesz zmodyfikowac: ";
    cin>>id;
    idT=find_tablica(id);
    while(znak!='d')
    {
    cout<<endl<<"Co chcesz zrobic?"<<endl<<"a. Rotacja o wybrany kat "<<endl<<"b. Przeskalowanie "<<endl<<"c. Przesuniecie o wektor"<<endl;
    cout<<"d. Zapisanie zmian"<<endl;


        cin>>znak;
        if (znak == 'a')
        {
            cout << endl << "Podaj kat (liczba calkowita): ";
            cin >> rot;
        }
        if (znak == 'b')
        {
            cout << endl << "Podaj skale: ";
            cin>>skala;
        }
        if (znak == 'c')
        {
            int x;
            wsp.clear();
            cout << endl << "Podaj wspolrzedne wektora: x=";
            cin>>x;
            wsp.push_back(x);
            cout<<" y= ";
            cin>>x;
            wsp.push_back(x);
            cout<<" z= ";
            cin>>x;
            wsp.push_back(x);

        }
    }
    tablice[idT].modyfikuj(id,skala,rot,wsp);

}
void Edytor::usun()
{
    if(tablice.empty())
    {
        throw Wyjatek("Aby zrobic cokolwiek musisz najpierw dodac pierwsza tablice!");
    }
    int id,idT;
    cout<<"Podaj id figury ktora chcesz usunac: ";
    cin>>id;
    idT=find_tablica(id);
    try
    {
        tablice[idT].usun(id);
    }
    catch(Wyjatek wyjatek)
    {
        cout<<wyjatek.getMsg()<<endl;
    }
}
void Edytor::zapisywanie()
{
    if(tablice.empty())
    {
        throw Wyjatek("Aby zrobic cokolwiek musisz najpierw dodac pierwsza tablice!");
    }
    int id;
    cout<<"Podaj id tablicy ktora chcesz zapisac do pliku: ";
    cin>>id;
    tablice[id].rysuj();
    string plik=tablice[id].rysuj();
    cout<<endl<<"Zapisano figury do pliku o nazwie"<<plik<<endl;
}
void Edytor::dodaj_tablice()
{
    Tablica *tablica = new Tablica();
    tablice.push_back(*tablica);
    cout<<"Dodales tablice o id= "<<tablica->getId()<<endl;

}

void Edytor::usun_tablice()
{
    if(tablice.empty())
    {
        throw Wyjatek("Aby zrobic cokolwiek musisz najpierw dodac pierwsza tablice!");
    }
    int id,t=0;
    cout<<"Podaj id tablicy do usuniecia: ";
    cin>>id;
    for(int i=0; i<=tablice.size();i++)
    {
        if(tablice[i].getId()==id)
        {
            t=1;
            break;
        }
    }
    if(t==0) {
        throw Wyjatek("Nie istnieje tablica o takim id! ");
    }

    for (auto i = tablice.begin(); i != tablice.end(); i++)
    {
        if ((*i).getId() == id) {
            tablice.erase(i);
            cout<<"Usunieto tablice o id= "<<id<<endl;
            break;
        }
    }

}

void Edytor::sprawdz_tablice(int id)
{
    int t=0;
    for(int i=0; i<tablice.size();i++)
    {
        if(tablice[i].getId()==id)
        {
            t=1;
            break;
        }
    }
    if(t==0)
        throw Wyjatek("Nie istnieje tablica o takim id! ");

}

int Edytor::find_tablica(int id)
{
    for(int i=0;i<tablice.size();i++)
    {
        try
        {
            tablice[i].sprawdz_figury(id);
        }
        catch(Wyjatek wyjatek){}
        return i;
    }
}



