#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "klasa.h"
using namespace std;
using std::string;

plansza::plansza(){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			tab[j][i]=false;
			strzal[j][i]=0;
		}
};
statek::statek(): plansza(){ };

plansza::plansza(int k){			// konstruktor planszy tworzacy wg flagi
	for(int i=0;i<10;i++)			// 1 - tworzy dwa rzedy prawdziwe
		for(int j=0;j<10;j++){		// 2 - losowo ustawia statki
			tab[i][j]=false;		// inne - wszystkie pola to prawda
			strzal[j][i]=0;
		}
	if(k==1)
		for(int i=0;i<10;i++)
			for(int j=0;j<2;j++)
				tab[i][j]=true;
	else if(k==2){				// losowe utworzenie statkow
		srand(time(NULL));
		int p=0,l=0,wybor=0;
		//CZTEROMASZTOWIEC
		p=rand()%6+3;
		l=rand()%6+3;
		for(int i=0;i<4;i++){
			tab[p][l]=true;
			l++;		
		}
		//TROJMASZTOWIEC
		for(int i=0;i<2;i++){
			while(1){
			p=rand()%7+2;
			l=rand()%7+2;
			if(tab[p][l]==false && tab[p+1][l]==false && tab[p+2][l]==false){
				tab[p][l]=true;	tab[p+1][l]=true; tab[p+2][l]=true; break;
			}
			else if(tab[l][p]==false && tab[l+1][p]==false && tab[l+2][p]==false){
				tab[l][p]=true; tab[l+1][p]=true; tab[l+2][p]=true; break;
			}	}
		}
		//DWUMASZTOWCE
		for(int i=0;i<3;i++){
			while(1){
			p=rand()%8+1;
			l=rand()%8+1;
			if(tab[p][l]==false && tab[p+1][l]==false){ tab[p][l]=true; tab[p+1][l]=true; break; }
			else if(tab[p][l]==false && tab[p-1][l]==false){ tab[p][l]=true; tab[p-1][l]=true; break; }
			else if(tab[l][p]==false && tab[l+1][p]==false){ tab[l][p]=true; tab[l+1][p]=true; break; }
			else if(tab[l][p]==false && tab[l-1][p]==false){ tab[l][p]=true; tab[l-1][p]=true; break; }
			}
		}
		//JEDNOMASZTOWCE
		for(int i=0;i<4;i++){
			while(1){
			p=rand()%9;
			l=rand()%9;
			if(tab[p][l]==false){ tab[p][l]=true; break; }
			else if(tab[l][p]==false){ tab[l][p]=true; break; }
			}
		}
	}
	else
		for(int i=0;i<4;i++)
			for(int j=0;j<5;j++)
				tab[i][j]=true;		
};


plansza::plansza(plansza &k){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			tab[i][j]=k.tab[i][j];
			strzal[i][j]=k.strzal[i][j];
		}
};
	
int plansza::okresl_litere(string x){
	int zwrot=66;
	if(x=="A" || x=="a") {zwrot=0; }
	else if(x=="B" || x=="b") {zwrot=1; }
	else if(x=="C" || x=="c") {zwrot=2; }
	else if(x=="D" || x=="d") {zwrot=3; }
	else if(x=="E" || x=="e") {zwrot=4; }
	else if(x=="F" || x=="f") {zwrot=5; }
	else if(x=="G" || x=="g") {zwrot=6; }
	else if(x=="H" || x=="h") {zwrot=7; }
	else if(x=="I" || x=="i") {zwrot=8; }
	else if(x=="J" || x=="j") {zwrot=9; }
	else {
		printf("\nPodales niepoprawna litere...\n");
	}
	return zwrot;
};
void plansza::reset(){
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			tab[i][j]=false;
};
void plansza::wyswietl(){
	int sym=65; //sym->znaki A-J
	//wypisanie cyfr 1-10
	printf("  ");
	for(int i=0; i<10; i++)
		printf("%3d",i);
	printf("\n\n");
	//wypisanie poszczegolnych pol + znakow A-J
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j==0) { printf("%c  ",sym); sym++; }
			if(tab[j][i]==true) printf("[*]");
			else printf("[ ]");
		}printf("\n");
	}printf("\n\n");
};
void plansza::wyswietl2(){
	int sym=65; //sym->znaki A-J
	//wypisanie cyfr 0-9
	printf("  ");
	for(int i=0; i<10; i++)
		printf("%3d",i);
	printf("\n\n");
	//wypisanie poszczegolnych pol + znakow A-J
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j==0) { printf("%c  ",sym); sym++; } // TRZY RODZAJE POL TABLICY "STRZAL"
			if(strzal[j][i]==0) printf("[ ]");		// 0 - nienaruszone pole	
			else if(strzal[j][i]==1) printf("[O]"); // 1 - oddany strzal - chybione
			else if(strzal[j][i]==2) printf("[X]"); // 2 - oddany strzal - trafione
			else printf("[ ]");
		}printf("\n");
	}printf("\n\n");
};
void plansza::wyswietl3(plansza &h){
	int sym=65; //sym->znaki A-J
	//wypisanie cyfr 1-10
	printf("  ");
	for(int i=0; i<10; i++)
		printf("%3d",i);
	printf("\n\n");
	//wypisanie poszczegolnych pol + znakow A-J
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j==0) { printf("%c  ",sym); sym++; }
			if(tab[j][i]==true && h.getSTR(j,i)==0) printf("[*]");
			else if(tab[j][i]==true && h.getSTR(j,i)==2) printf("[X]");
			else if(tab[j][i]==false && h.getSTR(j,i)==1) printf("[O]");
			else printf("[ ]");
		}printf("\n");
	}printf("\n\n");
};


void plansza::setTAB(int x, int y){ tab[x][y]=true; };
bool plansza::getTAB(int x, int y){ if(tab[x][y]==true) return true; else return false; };
void plansza::setSTR(int x, int y){ 
	if(tab[x][y]==true) strzal[x][y]=2;
	else if(tab[x][y]==false) strzal[x][y]=1;};
int plansza::getSTR(int x, int y){ return strzal[x][y]; };
void plansza::setTRF(int x,int y, int k){ strzal[x][y]=k; };


plansza& plansza::operator+=(const plansza& k){
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(tab[j][i]==false && k.tab[j][i]==true) setTAB(j,i);
	return *this;
};

bool tt1::wstaw(int a, string b, string c,plansza k){ return false;
	/*
	x=okresl_litere(b);
	y=okresl_litere(c);
	if(getTAB(a,x)==true) return false;
	if(x==y){ 
		setTAB(a,x);
		return true;
	}
	else{
		printf("\nJednomasztowiec jest tylko w jednym punkcie!\n");
		return false;
	}*/
};

bool tt1::wstaw(string a, int b, int c,plansza k){ 
	x=okresl_litere(a);
	if(x>9||x<0||b>9||b<0||c>9||c<0) return false;
	else if(k.getTAB(b,x)==true) return false;
	else if(b==c){ 
		setTAB(b,x);
		return true;
	}
	else {
		printf("\nJednomasztowiec jest tylko w jednym punkcie!\n");	
		return false;
	}
};

bool tt2::wstaw(int a, string b, string c,plansza k){
	x=okresl_litere(b);
	y=okresl_litere(c);
	if(a>9||a<0||x>9||x<0||y>9||y<0) return false;
	else if(k.getTAB(a,x)==true || k.getTAB(a,y)==true) return false;
	else if(x-y==1 || y-x==1){
		setTAB(a,x);
		setTAB(a,y);
		return true;
	}
	else {
		printf("\nDwumasztowiec moze byc tylko w dwoch punktach obok siebie!\n");
		return false;
	}
	
};

bool tt2::wstaw(string a, int b, int c,plansza k){ 
	x=okresl_litere(a);
	if(x>9||x<0||b>9||b<0||c>9||c<0) return false;
	if(k.getTAB(b,x)==true || k.getTAB(b,x)==true) return false;
	if(b-c==1 || c-b==1){
		setTAB(b,x);
		setTAB(c,x);
		return true;
	}
	else{
		printf("\nDwumasztowiec moze byc tylko w dwoch punktach obok siebie!\n");
		return false;
	}	
};

bool tt3::wstaw(int a, string b, string c, plansza k){ 
	x=okresl_litere(b);
	y=okresl_litere(c);
	if(a>9||a<0||x>9||x<0||y>9||y<0) return false;
	else if(k.getTAB(a,x)==true || k.getTAB(a,y)==true) return false;
	else if(x-y==2 || y-x==2){
		if(x>y && (x-1<=9 && x-1>=0)){ 
			if(k.getTAB(a,x-1)==false)
				setTAB(a,x-1);	
			else return false;
		}
		else if(x<y &&(x+1<=9 && x+1>=0)){
			if(k.getTAB(a,x+1)==false)
				setTAB(a,x+1); 
			else return false;
		}
		else{
			printf("\nZle dane podane do utworzenia okretu!\n");
			return false;
		}
	setTAB(a,x);
	setTAB(a,y);
	return true;
	}
	else{
		printf("\nTrojmasztowiec musi zajmowac 3 obok siebie pola w linii!\n");
		return false;
	}
};

bool tt3::wstaw(string a, int b, int c, plansza k){ 
	x=okresl_litere(a);
	if(x>9||x<0||b>9||b<0||c>9||c<0) return false;
	else if(k.getTAB(b,x)==true || k.getTAB(c,x)==true) return false;
	else if(b-c==2 || c-b==2){
		if(b<c && (b+1<=9 && b+1>=0)){
			if(k.getTAB(b+1,x)==false)
				setTAB(b+1,x);
			else return false;
		}
		else if(b>c && (b-1<=9 && b-1>=0)){
			if(k.getTAB(b-1,x)==false)
				setTAB(b-1,x);
			else return false;
		}
		else{
			printf("\nBlad podanych danych!\n"); 
			return false;
		}			
		setTAB(b,x);
		setTAB(c,x);
		return true;
	}

	else{ 
		printf("\nTrojmasztowiec musi zajmowac 3 obok siebie pola w linii!\n"); 
		return false; 
	}
};

bool tt4::wstaw(int a, string b, string c, plansza k){
	x=okresl_litere(b);
	y=okresl_litere(c);
	if(a>9||a<0||x>9||x<0||y>9||y<0) return false;
	else if(getTAB(a,x)==true || getTAB(a,y)==true) return false;
	else if(x-y==3 || y-x==3){		
			if(x>y && (x-2<=9 && x-2>=0)){
				if(getTAB(a,x-1)==false && getTAB(a,x-2)==false){
					setTAB(a,x-1);
					setTAB(a,x-2);
				}
				else return false;				
			}
			else if(x<y && (x+2<=9 && x+2>=0)){
				if(getTAB(a,x+1)==false && getTAB(a,x+2)==false){
					setTAB(a,x+1);
					setTAB(a,x+2);
				}
				else return false;
			}
			else{ 
				cout<<"\nBledne wartosci podane zostaly - ponownie podaj je!\n";
				return false;
			}
			setTAB(a,x);
			setTAB(a,y);
			return true;
		}
		else{
			printf("\nCzteromasztowiec musi zajmowac 4 obok siebie pola w linii!\n");
			return false;
		}
};

bool tt4::wstaw(string a, int b, int c,plansza k){
	x=okresl_litere(a);
	if(x>9||x<0||b>9||b<0||c>9||c<0) return false;
	else if(k.getTAB(b,x)==true || k.getTAB(c,x)==true) return false;
	else if(b-c==3 || c-b==3){
		if(b>c && (b-2<=9 && b-2>=0)){
			if(getTAB(b-1,x)==false && getTAB(b-2,x)==false){
				setTAB(b-1,x);
				setTAB(b-2,x);
			}
			else return false;
		}
		else if(b<c && (b+2<=9 && b+2>=0)){
			if(getTAB(b+1,x)==false && getTAB(b+2,x)==false){
				setTAB(b+1,x);
				setTAB(b+2,x);
			}
			else return false;
		}
		else{ 
			cout<<"\nBledne wartosci podane zostaly - ponownie podaj je!\n";
			return false;
		}
		setTAB(b,x);
		setTAB(c,x);
		return true;
}
	else{
		printf("\nCzteromasztowiec musi zajmowac 4 obok siebie pola w linii!\n");
		return false;
	}
};