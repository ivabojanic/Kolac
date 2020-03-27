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
            if(temperatura > 100)
            {
                stanje = IZGOREO;
                temperatura = 20;
            }
            return true;
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
        cout<<"------------------";
    }

int meni()
{
    int opcija;

        cout<<"Odaberite operaciju:"<<endl;
        cout<<"1. Stavite kolac da se pece"<<endl;
        cout<<"2. Ispecite kolac"<<endl;
        cout<<"3. Zavrsite sa pecenjem kolacem"<<endl;
        cout<<"4. Povecajte temperaturu pecenja"<<endl;
        cout<<"5. Smanjite temperaturu pecenja"<<endl;
        cout<<"6. Dodajte slag na kolac"<<endl;
        cout<<"7. Uklonite slag sa kolaca"<<endl;
        cout<<"8. Zavrsetak rada programa"<<endl;
        cin>>opcija;

        return opcija;
}


int main()
{
    int opcijaIzMenija;
    Kolac kolacic;
    bool prom;

    do
    {
        opcijaIzMenija = meni();
        switch(opcijaIzMenija)
        {
        case 1:
            prom = kolacic.staviDaSePece();
            break;
        case 2:
            prom = kolacic.ispeciKolac();
            break;
        case 3:
            prom = kolacic.zavrsiKolac();
            break;
        case 4:
            prom = kolacic.povecajTemperaturu();
            break;
        case 5:
            prom = kolacic.smanjiTemperaturu();
            break;
        case 6:
            prom = kolacic.dodajSlag();
            break;
        case 7:
            prom = kolacic.ukloniSlag();
            break;
        }

        if(prom == true)
        {
            ispisiKolac(kolacic);
        }
    }while(opcijaIzMenija>1 && opcijaIzMenija<8 );
    return 0;
}
