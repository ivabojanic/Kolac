#include <iostream>

using namespace std;

enum TipPreliva {COKOLADNI,COKOLADNI_SA_SLAGOM};

class Preliv
{
private:
    TipPreliva preliiv;
public:
    Preliv(){preliiv = COKOLADNI;}
    Preliv(TipPreliva p){preliiv = p;}

    bool dodajSlag()
    {
        if(preliiv == COKOLADNI)
        {
            preliiv = COKOLADNI_SA_SLAGOM;
            return true;
        }else
            return false;
    }

    bool ukloniSlag()
    {
        if(preliiv == COKOLADNI_SA_SLAGOM)
        {
            preliiv = COKOLADNI;
            return true;
        }else
            return false;
    }
    TipPreliva getPreliv()const
    {
       return preliiv;
    }
    void ispisiPreliv(const Preliv &pr)
    {
        if(pr.getPreliv() == 0)
        {
            cout<<"Preliv je cokoladni.";
        }else
            cout<<"Preliv je cokoladni sa slagom";
    }
};

enum KolacStanje {UPRIPREMI,PECESE,IZGOREO,PRIPREMLJEN};

class Kolac
{
private:
    KolacStanje stanje;
    int temperatura;
    Preliv preliv;
public:
    Kolac(): preliv(){stanje = UPRIPREMI; temperatura = 20; preliv = COKOLADNI;}
    Kolac(const Kolac &k){stanje = k.stanje; temperatura = k.temperatura; preliv = k.preliv;}

    KolacStanje getStanje()const
    {
        return stanje;
    }
    int getTemperatura()const
    {
        return temperatura;
    }
    Preliv getPreliv()const
    {
        return preliv;
    }

    bool staviDaSePece()
    {
        if(stanje == UPRIPREMI && preliv.getPreliv()== COKOLADNI)
        {
            temperatura+=20;
            stanje = PECESE;
            return true;
        }else
            return false;
    }
    bool ispeciKolac()
    {
        if(stanje == PECESE)
        {
            stanje = UPRIPREMI;
            temperatura = 20;
            return true;
        }else
            return false;
    }
    bool zavrsiKolac()
    {
        if(stanje == UPRIPREMI)
        {
            stanje = PRIPREMLJEN;
            return true;
        }else
            return false;
    }
    bool povecajTemperaturu()
    {
        if(stanje == PECESE)
        {
            temperatura+=20;
            if(temperatura < 100)
            {
                return true;
            }else
                stanje = IZGOREO;
                temperatura = 20;
        }else
             return false;
    }
    bool smanjiTemperaturu()
    {
        if(stanje == PECESE && temperatura>=40)
        {
            temperatura-=20;
            return true;
        }else
            return false;
    }
    bool dodajSlag()
    {
        if(stanje == UPRIPREMI)
        {
            return preliv.dodajSlag();
        }else
            return false;
    }
    bool ukloniSlag()
    {
        if(stanje == UPRIPREMI)
        {
            return preliv.ukloniSlag();
        }else
            return false;
    }
};
    void ispisiKolac(Kolac &k)
    {
        cout<<"----------------";
        if(k.getStanje()== UPRIPREMI)
        {
            cout<<"Kolac je u pripremi"<<endl;
        }else if(k.getStanje()== PECESE)
        {
            cout<<"Kolac se pece"<<endl;
        }else if(k.getStanje()== IZGOREO)
        {
            cout<<"Kolac je igoreo :("<<endl;
        }else if(k.getStanje()== PRIPREMLJEN)
        {
            cout<<"Kolac je gotov"<<endl;
        }
        cout<<"Temperatura:"<<k.getTemperatura()<<endl;
        cout<<"Preliv:"<<endl;
        ispisiPreliv(k.getPreliv());
    }


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

