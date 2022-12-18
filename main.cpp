#include <iostream>
#include <string>
#include <cstring>
#include "Locatie.h"
#include "Eveniment.h"
#include "Bilet.h"

using namespace std;

Locatie ::Locatie() {
    nume = new char[20];
    strcpy_s(nume, 10, "Necunoscut");
    nr_sectoare = 0;
    sectoare = nullptr;//(zone)
    nr_randuri = 0;
    randuri = nullptr;
    locuri_rand = 0;
    locuri = nullptr;
}

Locatie::Locatie(char* nume, int nr_sectoare, int* sectoare, int nr_randuri, int* randuri, int locuri_rand, int* locuri) {
    this->nume = new char[strlen(nume) + 1];
    strcpy_s(this->nume, strlen(nume) + 1, nume);
    this->nr_sectoare = nr_sectoare;
    this->sectoare = new int[nr_sectoare];
    for (int i = 0; i < nr_sectoare; i++) {
        this->sectoare[i] = sectoare[i];
    }
    this->nr_randuri = nr_randuri;
    this->randuri = new int[nr_randuri];
    for (int i = 0; i < nr_randuri; i++) {
        this->randuri[i] = randuri[i];
    }
    this->locuri_rand = locuri_rand;
    this->locuri = new int[locuri_rand];
    for (int i = 0; i < locuri_rand; i++) {
        this->locuri[i] = locuri[i];
    }
}

Locatie::Locatie(const Locatie& l)
{
    this->nume = l.nume;
    this->nr_sectoare = l.nr_sectoare;
    this->sectoare = new int[l.nr_sectoare + 1];
    for (int i = 0; i < l.nr_sectoare; i++) {
        this->sectoare[i] = l.sectoare[i];
    }
    this->nr_randuri = l.nr_randuri;
    this->randuri = new int[nr_randuri + 1];
    for (int i = 0; i < nr_randuri; i++)
    {
        this->randuri[i] = l.randuri[i];
    }
    this->locuri_rand = l.locuri_rand;
    this->locuri = new int[locuri_rand + 1];
    for (int j = 0; j < locuri_rand; j++)
    {
        this->locuri[j] = l.locuri[j];
    }
}
string Locatie::getNume()
{
    return nume;
}
void Locatie:: setNume(char* nume)
{
    this->nume = nume;
}
//getter pentru vectorul de sectoare
int* Locatie::getSectoare()
{
    return sectoare;
}
void Locatie::setSectoare(int* sectoare)
{
    this->sectoare = sectoare;
}
int Locatie:: getNr_randuri()
{
    return nr_randuri;

}
void Locatie::setNr_randuri(int nr_randuri)
{
    this->nr_randuri = nr_randuri;
}
int* Locatie:: getRanduri()
{
    if (randuri == NULL or nr_randuri <= 0) return NULL;
    int* copie = new int[nr_randuri];
    for (int i = 0; i < nr_randuri; i++)
    {
        copie[i] = randuri[i];
    }
    return copie;
}
void Locatie::setRanduri(int* rand, int nr)
{
    if (rand != NULL && nr > 0) delete[] randuri;
    nr_randuri = nr;
    randuri = new int[nr];
    for (int i = 0; i < nr; i++)
    {
        randuri[i] = rand[i];
    }
}

int Locatie::getLocuri_rand()
{
    return locuri_rand;

}
void Locatie::setLocuri_rand(int locuri_rand)
{
    this->locuri_rand = locuri_rand;
}
int* Locatie::getLocuri()
{
    if (locuri == NULL or locuri_rand <= 0) return NULL;
    int* copie = new int[locuri_rand];
    for (int i = 0; i < locuri_rand; i++)
    {
        copie[i] = locuri[i];
    }
    return copie;
}
void Locatie:: setLocuri(int* loc, int nr)
{
    if (loc != NULL && nr > 0) delete[] locuri;
    locuri_rand = nr;
    locuri = new int[nr];
    for (int i = 0; i < nr; i++)
    {
        locuri[i] = loc[i];

    }
}
Locatie& Locatie:: operator= (const Locatie& l)
{
    this->nume = l.nume;
    this->nr_sectoare = l.nr_sectoare;
    if (this->sectoare != nullptr)
        delete[] this->sectoare;
    this->sectoare = new int[l.nr_sectoare + 1];
    for (int i = 0; i < l.nr_sectoare; i++) {
        this->sectoare[i] = l.sectoare[i];
    }
    this->nr_randuri = l.nr_randuri;
    randuri = new int[nr_randuri + 1];
    for (int i = 0; i < nr_randuri; i++)
    {
        this->randuri[i] = l.randuri[i];

    }

    this->locuri_rand = l.locuri_rand;


    locuri = new int[locuri_rand + 1];
    for (int j = 0; j < locuri_rand; j++)
    {
        this->locuri[j] = l.locuri[j];

    }
    return *this;
}
int& Locatie::operator[](int index)
{
    if (index >= 0 && index < nr_randuri)
    {
        return randuri[index];
    }

}
void Locatie::adauga_randuri(int randuri_noi)
{
    nr_randuri = nr_randuri + randuri_noi;

}
void Locatie::elimina_randuri(int randuri_deteriorate)
{
    nr_randuri = nr_randuri - randuri_deteriorate;
}

Locatie::~Locatie()
{
    delete[] sectoare;
    sectoare = nullptr;
    delete[] randuri;
    randuri = NULL;
    delete[] locuri;
    locuri = NULL;
}
istream& operator>>(istream& in, Locatie& l)
{
    in >> l.nume;
    in >> l.nr_sectoare;
    if (l.sectoare != nullptr)
        delete[] l.sectoare;
    l.sectoare = new int[l.nr_sectoare + 1];
    for (int i = 0; i < l.nr_sectoare; i++) {
        in >> l.sectoare[i];
    }
    in >> l.nr_randuri;
    l.randuri = new int[l.nr_randuri + 1];
    for (int i = 0; i < l.nr_randuri; i++)
    {
        in >> l.randuri[i];
    }
    in >> l.locuri_rand;
    l.locuri = new int[l.locuri_rand + 1];
    for (int j = 0; j < l.locuri_rand; j++)
    {
        in >> l.locuri[j];
    }
    return in;
}

ostream& operator<<(ostream& os, const Locatie& locatie) {
    os << "\nnume: " << locatie.nume << "\nnr_sectoare: " << locatie.nr_sectoare << "\nsectoare: ";
    for (int i = 0; i < locatie.nr_sectoare; i++) {
        os << locatie.sectoare[i] << " ";
    }
    os << "\nnr_randuri: " << locatie.nr_randuri << "\nranduri: ";
    for (int i = 0; i < locatie.nr_randuri; i++) {
        os << locatie.randuri[i] << " ";
    }
    os << "\nlocuri_rand: "
       << locatie.locuri_rand << "\nlocuri: ";
    for (int i = 0; i < locatie.locuri_rand; i++)
        os << locatie.locuri[i] << " ";
    return os;
}


Eveniment::Eveniment() :durataMaxima(4)
{
    nume = "";
    durata = 0;
    capacitate_maxima = 0;
}
Eveniment:: Eveniment(string nume, float durata, int capacitate_maxima) :durataMaxima(4)
{
    this->nume = nume;
    this->durata = durata;
    this->capacitate_maxima = capacitate_maxima;
}
string Eveniment:: getNume()
{
    return nume;
}

void Eveniment::setNume(string nume)
{
    this->nume = nume;
}
float Eveniment:: getDurata()
{
    return durata;
}
void Eveniment::setDurata(float durata)
{
    this->durata = durata;
}
int Eveniment:: getCapacitate_maxima()
{
    return capacitate_maxima;
}
void Eveniment:: setCapacitate_maxima(int capacitate_maxima)
{
    this->capacitate_maxima = capacitate_maxima;
}

bool Eveniment::operator!()
{
    return durata != 0;
}
Eveniment Eveniment:: operator+(Eveniment e)
{
    Eveniment copie = *this;
    copie.durata = durata + e.durata;
    return copie;
}
void Eveniment::durata_finala(int intarziere)
{
    durata = durata + intarziere;
}
void Eveniment::locuri_suplimentare(int locuri_suplimentare)
{
    capacitate_maxima = capacitate_maxima + locuri_suplimentare;
}
ostream& operator<<(ostream& os, const Eveniment& eveniment) {
    os << "nume: " << eveniment.nume << " durata: " << eveniment.durata << " capacitate_maxima: "
       << eveniment.capacitate_maxima << " durataMaxima: " << eveniment.durataMaxima;
    return os;
}

istream& operator>>(istream& in, Eveniment& eveniment) {
    in >> eveniment.nume;
    in >> eveniment.durata;
    in >> eveniment.capacitate_maxima;
    return in;
}


Bilet::Bilet()
{
    sector = "";
    rand = 0;
    loc = 0;
    pret = 0;
}
Bilet::Bilet(string sector, int rand, char loc, int pret)
{
    this->sector = sector;
    this->rand = rand;
    this->loc = loc;
    this->pret = pret;
}
string Bilet::getSector()
{
    return sector;

}
void Bilet::setSector(string sector)
{
    this->sector = sector;

}
int Bilet::getRand()
{
    return rand;

}
void Bilet::setRand(int rand)
{
    this->rand = rand;
}
int Bilet:: getLoc()
{
    return loc;
}
void Bilet::setLoc(int loc)
{
    this->loc = loc;
}
string Bilet::getTipBilet()
{
    return tipBilet;
}
void Bilet:: setTipBilet(string tipBilet)
{
    Bilet::tipBilet = tipBilet;
}
int Bilet::getPret()
{
    return pret;
}
void Bilet::setPret(int pret)
{
    this->pret=pret;
}
Bilet Bilet::operator++()
{
    loc++;
    return *this;
}
Bilet Bilet::operator--()
{
    rand--;
    return *this;
}
void Bilet:: schimbare_rand(int x)
{
    rand = rand + x;
}
void Bilet::schimbare_loc(int x)
{
    loc = loc + x;
}
float Bilet::pret_mediu(Bilet* bilete, int nr_bilete)
{
    float suma = 0;
    for (int i = 0; i < nr_bilete; i++)
    {
        suma = suma + bilete[i].getPret();
    }
    return suma / nr_bilete;
}
string Bilet::tipBilet = "online";
ostream& operator<<(ostream& os, const Bilet& bilet) {
    os << "sector: " << bilet.sector << " rand: " << bilet.rand << " loc: " << bilet.loc << " tipBilet: "
       << bilet.tipBilet;
    return os;
}

istream& operator>>(istream& in, Bilet& bilet) {
    in >> bilet.sector;
    in >> bilet.rand;
    in >> bilet.loc;
    return in;
}

int main() {

    char* nume_arena = new char[20];
    strcpy_s(nume_arena, 11, "Arena Nati");
    Locatie l2 = Locatie(nume_arena, 3, new int[3] { 1, 2, 3 }, 10, new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, 10, new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
    cout << l2;
    //Exemplu metoda statica a clasei Bilet
    Bilet b1 = Bilet("A", 1, 1, 100);
    Bilet b2 = Bilet("A", 1, 2, 100);
    Bilet b3 = Bilet("A", 1, 3, 100);
    Bilet b4 = Bilet("A", 1, 4, 100);
    Bilet b5 = Bilet("A", 5, 6, 75);
    Bilet b6 = Bilet("A", 5, 7, 75);
    Bilet b7 = Bilet("A", 5, 8, 75);
    Bilet b8 = Bilet("A", 5, 9, 75);
    //vector de bilete
    Bilet bilete[8] = { b1,b2,b3,b4,b5,b6,b7,b8 };
    cout << Bilet::pret_mediu(bilete, 8);

    Eveniment e1 = Eveniment("Meci de zile mari", 2, 95000);
    cout<<e1;

    return 0;
}