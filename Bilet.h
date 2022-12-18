//
// Created by stoic on 18.12.2022.
//

#ifndef POPI_OOP_BILET_H
#define POPI_OOP_BILET_H

#include <string>

using namespace std;

class Bilet
{

    string sector;
    int rand;
    int loc;
    int pret;


    static string tipBilet;
public:

    friend ostream& operator<<(ostream& os, const Bilet& bilet);
    friend istream& operator>>(istream& in, Bilet& bilet);
    Bilet();

    Bilet(string sector, int rand, char loc, int pret);

    string getSector();
    int getPret();
    void setPret(int pret);

    void setSector(string sector);

    int getRand();

    void setRand(int rand);

    int getLoc();

    void setLoc(int loc);

    static string getTipBilet();


    static void setTipBilet(string tipBilet);

    Bilet operator++();

    Bilet operator--();

    void schimbare_rand(int x);

    void schimbare_loc(int x);

    static float pret_mediu(Bilet* bilete, int nr_bilete);

};





#endif //POPI_OOP_BILET_H
