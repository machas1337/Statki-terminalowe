#include <iostream>
#include <string>
using namespace std;
using std::string;

#ifndef klasa_h
#define klasa_h

class plansza{ // klasa bazowa
private:
	bool tab[10][10]; //rozmiar planszy
	int strzal[10][10]; //rozmiar planszy do strzelania
public:
	plansza();
	plansza(int);
	plansza(plansza&);
	plansza& operator+=(const plansza& i);
	int okresl_litere(string); // konwertuje litere na liczbe zgodna z ukladem planszy 10x10
	void reset(); // resetuje cala plansze do wszystkich pol false
	void wyswietl(); // pokazuje plansze ze statkami - rozstawianie
	void wyswietl2(); // pokazuje strzaly
	void wyswietl3(plansza &);//pokazuje Twoja plansze ze strzalami przeciwnika
	void setTAB(int, int); // ustala wartosci TRUE/FALSE dla konkretnego pola x i y
	bool getTAB(int, int); // pobiera wartosc TRUE/FALSE dla konkretnego pola x i y
	void setSTR(int, int); // ustala wartosci strzalu - [0,1,2] [nienaruszone pole, pudlo, traf] wzgledem tab[][]
	int getSTR(int, int); // pobiera wartosci strzalu - [0,1,2] -||-
	void setTRF(int, int, int); // usatala wartosc strzalu (x,y, nr_trafienia[0,1,2])
};
plansza rozstawianie(); //deklaracja funkcji rozstawianai

class statek: public plansza{ // klasa abstrakcyjna dziedziczaca po klasie plansza
protected:
	int x,y; // wspolrzedne statku
public:
	statek();
	virtual bool wstaw(int, string, string, plansza)=0; // wirtualna klasa odpowiadajaca za pionowy zakres statku np. w kolumnie 3, trojmasztowiec z zakresu A-C
	virtual bool wstaw(string, int, int, plansza)=0; // wirtualna klasa odpowiadaja za poziomy zakres statku np. w wierszu B, dwumasztowiec w zakresie 4-5
};
class tt1: public statek{ // jednomasztowiec
public:
	bool wstaw(int,string,string, plansza);
	bool wstaw(string, int, int, plansza);
};
class tt2: public statek{ // dwumasztowiec
public:
	bool wstaw(int,string,string, plansza);
	bool wstaw(string, int, int, plansza);
};
class tt3: public statek{ // trojmasztowiec
public:
	bool wstaw(int,string,string, plansza);
	bool wstaw(string, int, int, plansza);
};
class tt4: public statek{ // czteromasztowiec
public:
	bool wstaw(int,string,string, plansza);
	bool wstaw(string, int, int, plansza);
};

#endif