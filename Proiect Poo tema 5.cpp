#include <iostream>

using namespace std;


// CLASA PERECHE

class Pereche
{

    int x, y;

public:
    Pereche(int a = 0, int b = 0);
    Pereche(const Pereche& a);
    ~Pereche();
    friend istream& operator >> (istream&, Pereche&);
    friend ostream& operator << (ostream&, Pereche&);
    Pereche& operator = (const Pereche&);
    void set_X(int a);
    void set_Y(int b);
    int get_X();
    int get_Y();

};


Pereche::Pereche(int a, int b)   //constructor de initializare
{
    this->x = a;
    this->y = b;
}
Pereche::Pereche(const Pereche& a)  //constructor de copiere
{
    this->x = a.x;
    this->y = a.y;
}
Pereche::~Pereche()  //destructor 
{ }
istream& operator>>(istream& in, Pereche& p)  //supraincarcarea operatorului >>
{
    cout << "Introduceti x: ";
    in >> p.x;
    cout << endl;
    cout << "Introduceti y: ";
    in >> p.y;
    return in;
}
ostream& operator<<(ostream& out, Pereche& p) //supraincarcarea operatorului <<
{
    out << p.x << " " << p.y << endl;
    return out;

}
Pereche& Pereche :: operator = (const Pereche& p)  //supraincarcarea operatorului =
{

    if (this == &p)
        return *this;
    this->x = p.x;
    this->y = p.y;

    return *this;

}
void Pereche::set_X(int a)
{
    this->x = a;
}
void Pereche::set_Y(int b)
{
    this->y = b;
}
int Pereche::get_X()
{
    return this->x;
}
int Pereche::get_Y()
{
    return this->y;
}


// CLASA MULTIME

class Multime_pereche
{
protected:
    int n;
    Pereche* multime;
public:
    Multime_pereche(int m = 0);
    Multime_pereche(const Multime_pereche& m);
    virtual ~Multime_pereche();
    friend istream& operator >> (istream&, Multime_pereche&);
    friend ostream& operator << (ostream&, Multime_pereche&);
    Multime_pereche& operator = (const Multime_pereche&);
    void addPerecheInMultime(Pereche p);
    void deletePerecheDinMultime(int index);
    int get_N();
    Pereche* get_multime();
    void set_N(int x);
    void set_multime(int x, Pereche p);
};


Multime_pereche::Multime_pereche(int m)   //constructorul de initializare 
{
    try {
        if (m < 0)
            throw m;
    }
    catch (int m)
    {
        cout << "Intruduceti un numar pozitiv!";
    }
    this->n = m;
    this->multime = new Pereche[n];
}
Multime_pereche::Multime_pereche(const Multime_pereche& m)   //constructor de copiere
{
    this->n = m.n;
    this->multime = new Pereche[m.n];
    for (int i = 0; i < n; ++i)
        multime[i] = m.multime[i];

}
istream& operator >> (istream& in, Multime_pereche& ob)  //supraincarcarea operatorului >>
{
    cout << "Introduceti numarul de perechi: ";
    in >> ob.n;
    cout << "Introduceti perechile: ";
    for (int i = 0; i < ob.n; ++i)
        in >> ob.multime[i];
    return in;
}
ostream& operator<<(ostream& out, Multime_pereche& ob) //supraincarcarea operatorului <<
{
    out << "Multimea este formata din " << ob.n << " perechi";
    out << endl;
    out << "Perechile sunt: ";
    for (int i = 0; i < ob.n; ++i)
        out << ob.multime[i] << " ";
    return out;

}
Multime_pereche& Multime_pereche::operator = (const Multime_pereche& m)   //supraincarcarea operatorului =
{
    if (this == &m)
        return *this;
    this->n = m.n;
    this->multime = m.multime;
    return *this;

}
Multime_pereche::~Multime_pereche() {  //destructor
    delete[] multime;
}
void Multime_pereche::addPerecheInMultime(Pereche p) {  //functie de adaugare a unei perechi in multime 
    multime[n] = p;
    this->n = this->n + 1;
}
void Multime_pereche::deletePerecheDinMultime(int x) { //functie pentru stergerea unei perechi din multime

    for (int i = x; i < n - 1; ++i)
        multime[i] = multime[i + 1];
    n--;
}
int Multime_pereche::get_N() {
    return n;
}
Pereche* Multime_pereche::get_multime() {
    return multime;
}
void Multime_pereche::set_N(int x) {
    n = x;
}
void Multime_pereche::set_multime(int x, Pereche p) {
    multime[x] = p;
}


// CLASA STIVA
class Stiva_pereche : public Multime_pereche
{
public:
    Stiva_pereche(int n);
    virtual ~Stiva_pereche();
    void adaugare(Pereche p);
    void stergere();
    friend ostream& operator<<(ostream& out, Stiva_pereche& ob); //supraincarcarea operatorului <<

};


Stiva_pereche::Stiva_pereche(int n)
    : Multime_pereche(n)
{}
Stiva_pereche::~Stiva_pereche() {  //destructor
    delete[] multime;
}
void Stiva_pereche::adaugare(Pereche p) {
    addPerecheInMultime(p);
}
void Stiva_pereche::stergere() {

    deletePerecheDinMultime(get_N());

}
ostream& operator<<(ostream& out, Stiva_pereche& ob) //supraincarcarea operatorului <<
{
    out << "Stiva este formata din " << ob.get_N() << " elemente";
    out << endl;
    out << "Elementele sunt: ";
    out << endl;
    for (int i = 0; i < ob.get_N(); i++)
        out << ob.get_multime()[i] << " ";
    return out;

}


//CLASA COADA
class Coada_pereche : public Multime_pereche
{
public:
    Coada_pereche(int n=0);
    Coada_pereche(const Coada_pereche& m);
    virtual ~Coada_pereche();
    void adaugare(Pereche p);
    void stergere();
    friend ostream& operator<<(ostream& out, Coada_pereche& ob); //supraincarcarea operatorului <<
    Coada_pereche & operator = (const Coada_pereche&);
};


Coada_pereche& Coada_pereche::operator = (const Coada_pereche& coada)   //supraincarcarea operatorului =
{
    if (this == &coada)
        return *this;
    this->n = coada.n;
    this->multime = coada.multime;
    return *this;

}
Coada_pereche::~Coada_pereche() {  //destructor
    delete[] multime;
}
ostream& operator<<(ostream& out, Coada_pereche& ob) //supraincarcarea operatorului <<
{
    out << "Coada este formata din " << ob.get_N() << " elemente ";
    out << endl;
    out << "Elementele sunt: ";
    out << endl;
    for (int i = 0; i < ob.get_N(); i++)
        out << ob.get_multime()[i] << " ";
    return out;

}
Coada_pereche::Coada_pereche(int n)
    :Multime_pereche(n)
{}
Coada_pereche::Coada_pereche(const Coada_pereche& m)   //constructor de copiere
{
    this->n = m.n;
    this->multime = new Pereche[m.n];
    for (int i = 0; i < n; ++i)
        multime[i] = m.multime[i];

}
void Coada_pereche::adaugare(Pereche p) {
    for (int i = get_N(); i > 0; i--)
       set_multime(i,get_multime()[i+1]);
    set_N(n + 1);
    set_multime(0, p);
}
void Coada_pereche::stergere() {

    deletePerecheDinMultime(get_N());

}



void PushStivaFolosindDouaCozi(Coada_pereche q1, Coada_pereche q2, int n, int x)
{
    n++;
    q2.adaugare(x);
    while(q1.get_N())
    {
        q2.adaugare(q1.get_multime()[q1.get_N()]);
        q1.stergere();
    }
    Coada_pereche q;
    q = q1;
    q1 = q2;
    q2 = q;
} //functie care simuleaza operatia push de pe stiva folosind doua cozi

Pereche PopStivaFolosindDouaCozi(Coada_pereche q1, int size) 
{
    Pereche p = q1.get_multime()[size];
    q1.stergere();
    return p;
   
}


int main()
{
    Multime_pereche m;
    cin >> m;
    return 0;
}
