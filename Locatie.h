
using namespace std;

class Locatie
{
private:
    char* nume;
    int nr_sectoare;
    int* sectoare;
    int nr_randuri;
    int* randuri;
    int locuri_rand;
    int* locuri;

public:
    friend ostream& operator<<(ostream&, const Locatie&);
    friend istream& operator>>(istream&, Locatie&);

    Locatie();

    Locatie(char* nume, int nr_sectoare, int* sectoare, int nr_randuri, int* randuri, int locuri_rand, int* locuri);
    Locatie(const Locatie& l);

    string getNume();

    void setNume(char* nume);

    //getter pentru vectorul de sectoare
    int* getSectoare();

    void setSectoare(int* sectoare);

    int getNr_randuri();

    void setNr_randuri(int nr_randuri);

    int* getRanduri();


    void setRanduri(int* rand, int nr);


    int getLocuri_rand();

    void setLocuri_rand(int locuri_rand);

    int* getLocuri();

    void setLocuri(int* loc, int nr);

    Locatie& operator= (const Locatie& l);

    int& operator[](int index);

    void adauga_randuri(int randuri_noi);

    void elimina_randuri(int randuri_deteriorate);


    ~Locatie();

};


