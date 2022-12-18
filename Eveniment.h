//
// Created by stoic on 18.12.2022.
//

#ifndef POPI_OOP_EVENIMENT_H
#define POPI_OOP_EVENIMENT_H

using namespace std;

class Eveniment
{
    string nume;
    float durata;
    int capacitate_maxima;
    const int durataMaxima;
public:
    friend ostream& operator<<(ostream& os, const Eveniment& eveniment);
    friend istream& operator>>(istream& in, Eveniment& eveniment);
    Eveniment();

    Eveniment(string nume, float durata, int capacitate_maxima);

    string getNume();

    void setNume(string nume);

    float getDurata();

    void setDurata(float durata);

    int getCapacitate_maxima();

    void setCapacitate_maxima(int capacitate_maxima);


    bool operator!();

    Eveniment operator+(Eveniment e);

    void durata_finala(int intarziere);

    void locuri_suplimentare(int locuri_suplimentare);

};


#endif //POPI_OOP_EVENIMENT_H
