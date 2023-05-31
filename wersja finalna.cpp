#include <iostream>
#include <cstring>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y){
	COORD c;
	c.X=x-1;
	c.Y=y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

class film{
	
	protected:
		char tytul[40];
		char gatunek[40];
		float dlugosc;
		float cena;
		int rok_wydania;
		char jezyk[10];
		
		
	public:
		film();
		void wypisz();
		void wyczysc();
		void ustaw(char *tyt, char *gat, float dl, float cen, int rok, char *jez);
		void piszXY(int x,int y);
		
		char getTytul();
		char* getGatunek();
		float getDlugosc();
		float getCena();
		int getRok_wydania();
		char getJezyk();
		
		void setTytul(char *tyt);
		void setGatunek(char *gat);
		void setDlugosc(float dl);
		void setCena(float cen);
		void setRok_wydania(int rok);
		void setJezyk(char *jez);
		
		
};


class filmoteka{
	
	protected:
			film *tabF;
			film *wyszukane;
			film *smietnik;
			int licznosc;
			int rozmiar;
			int ilosc;
			int current;
			int currentS;
			int currentW;
			int licznoscW;
			int licznoscS;
			
		private:     
			int i;	     
		          
		public:
			filmoteka(int roz, int il);
			void dodajKolejny(char *tyt, char *gat, float dl, float cen, int rok, char *jez);
	    	void wyczyscCalosc();
	    	void wypiszCalosc();
	    	void zapiszPlik(char *nazwa);
	    	void wczytajPlik(char *nazwa);	
				
			bool setCurrent(int index);
			bool setCurrentW(int index);
			bool setCurrentS(int index);
			void prev();
			void next();
			void showCurrent(int x, int y);
			void deleteCurrent();
			void wyszukajPrzedzial(int x,int y); 
			void wyszukaj(char *gat);
			void modifyNumbers(int liczba, char numer);
			void modifyChars(char *tekst, char numer);
			void sortCena(char rodzaj);
			void sortDlugosc(char rodzaj);
			
			void prevS();
			void nextS();
			void showCurrentS(int x, int y);
			void deleteCurrentS();
			void recoverCurrent();
			
			void prevW();
			void nextW();
			void showCurrentW(int x, int y);
			
			int getLicznosc();
			int getLicznoscW();
			int getLicznoscS();
};

//funkcje flimu


film::film(){
	strcpy(tytul, "");
	strcpy(gatunek, "");
	dlugosc=0;
	cena=0;
	rok_wydania=0;	
	strcpy(jezyk, "");
}

void film::wyczysc(){
	
	strcpy(tytul, "");
	strcpy(gatunek, "");
	dlugosc=0;
	cena=0;
	rok_wydania=0;	
	strcpy(jezyk, "");
}


void film::ustaw(char *tyt, char *gat, float dl, float cen, int rok, char *jez){
	strcpy(tytul, tyt);
	strcpy(gatunek, gat);
	dlugosc=dl;
	cena=cen;
	rok_wydania=rok;	
	strcpy(jezyk, jez);
}

void film::wypisz(){
	cout<<"Tytul: "<<tytul<<endl<<"Gatunek: "<<gatunek<<endl;
	cout<<"Dlugosc: "<<dlugosc<<" minut"<<endl<<"cena: "<<cena<<"zl"<<endl;
	cout<<"Rok wydania:  "<<rok_wydania<<endl<<"Czy jest polski jezyk: "<<jezyk<<endl<<endl;
}

void film::piszXY(int x,int y){
		gotoxy(x+5,y);
		cout<< "Tytul:";
		gotoxy(x+5,y+1);
		cout<< "Gatunek:";
		gotoxy(x+5,y+2);
		cout<< "Dlugosc:";
		gotoxy(x+5,y+3);
		cout<< "Cena:";
		gotoxy(x+5,y+4);
		cout<< "Rok wydania:";
		gotoxy(x+5,y+5);
		cout<< "Jezyk polski:";
		gotoxy(x+25,y);
		cout<< tytul;
		gotoxy(x+25,y+1);
		cout<< gatunek;
		gotoxy(x+25,y+2);
		cout<< dlugosc;
		gotoxy(x+25,y+3);
		cout<< cena;
		gotoxy(x+25,y+4);
		cout<< rok_wydania;
		gotoxy(x+25,y+5);
		cout<< jezyk<<endl<<endl;
		
}

char film::getTytul() {
	return *tytul;
}
char* film::getGatunek() {
	return gatunek;
}
float film::getDlugosc() {
	return dlugosc;
}
float film::getCena() {
	return cena;
}
int film::getRok_wydania() {
	return rok_wydania;
}
char film::getJezyk() {
	return *jezyk;
}


void film::setTytul(char *tyt){
	strcpy(tytul,tyt);
}
void film::setGatunek(char *gat){
	strcpy(gatunek,gat);
}
void film::setDlugosc(float dl){
	dlugosc=dl;
}
void film::setCena(float cen){
	cena=cen;
}
void film::setRok_wydania(int rok){
	rok_wydania=rok;
}
void film::setJezyk(char *jez){
	strcpy(jezyk, jez);
}

//funkcje klienta









//funckje filmoteki

filmoteka::filmoteka(int roz, int il) {
	rozmiar=roz;
	tabF=new film[rozmiar];
	    for (i=0;i<rozmiar;i++)
	        tabF[i].wyczysc();
	wyszukane=new film[rozmiar];
	    for (i=0;i<rozmiar;i++)
	        wyszukane[i].wyczysc();
	smietnik=new film[100];
	    for (i=0;i<100;i++)
	        smietnik[i].wyczysc();
	currentW=0;
	licznoscW=0;
	licznosc=0;
	current=0; 
	licznoscS=0;
	currentS=0;          
} 

void filmoteka::dodajKolejny(char *tyt, char *gat, float dl, float cen, int rok, char *jez) {
    if(licznosc<rozmiar){
        tabF[licznosc].ustaw(tyt,gat,dl,cen,rok,jez);
        licznosc++;
    }
}

void filmoteka::wypiszCalosc(){
    for (i=0;i<licznosc;i++)
        tabF[i].wypisz();
}

void filmoteka::wyczyscCalosc() {
    for (i=0;i<rozmiar;i++)
        tabF[i].wyczysc();
    licznosc=0;
}
void filmoteka::zapiszPlik(char *nazwa){
	FILE *fp;
	strcat(nazwa, ".dat");
	fp = fopen(nazwa, "wb");
	fwrite(&rozmiar, sizeof(rozmiar), 1, fp);
	fwrite(&licznosc,sizeof(licznosc), 1, fp);
	fwrite(tabF, sizeof(*tabF)*rozmiar, 1, fp);
	fclose(fp);
}

void filmoteka::wczytajPlik(char *nazwa){
	FILE *fp;
	strcat(nazwa, ".dat");
	fp = fopen(nazwa, "rb");
	fread(&rozmiar, sizeof(rozmiar), 1, fp);
	fread(&licznosc,sizeof(licznosc), 1, fp);
	fread(tabF, sizeof(*tabF)*rozmiar, 1, fp);
	fclose(fp);
}

void filmoteka::next(){
	current++;
	if(current>=licznosc){
		current = 0;
	}
}

void filmoteka::prev(){
	current--;
	if(current<0){
		current=licznosc-1;
	}
	
}

bool filmoteka::setCurrent(int index){
	if(index>0 && index<=licznosc){
		current = index-1;
		return true;
	}else return false;
	
}
bool filmoteka::setCurrentW(int index){
	if(index>0 && index<=licznosc){
		current = index-1;
		return true;
	}else return false;
	
}
bool filmoteka::setCurrentS(int index){
	if(index>0 && index<=licznosc){
		current = index-1;
		return true;
	}else return false;
	
}

void filmoteka::showCurrent(int x ,int y){
	tabF[current].piszXY(x,y);
	
}
int filmoteka::getLicznosc(){
	return licznosc;
}
int filmoteka::getLicznoscW(){
	return licznoscW;
}
int filmoteka::getLicznoscS(){
	return licznoscS;
}

void filmoteka::deleteCurrent(){
	licznosc--;
	smietnik[licznoscS]=tabF[current];
	licznoscS++;
	tabF[current]=tabF[licznosc];
	tabF[licznosc].wyczysc();
}
void filmoteka::wyszukajPrzedzial(int x,int y){
	licznoscW=0;
	currentW=0;
	for (i=0;i<rozmiar;i++){
	    	wyszukane[i].wyczysc();
		}
	for(i=0;i<licznosc;i++){
		if(tabF[i].getCena() >= x && tabF[i].getCena()<=y){
			wyszukane[i]=tabF[i];
			licznoscW++;
		}
	}
}
void filmoteka::nextW(){
	currentW++;
	if(currentW>=licznoscW){
		currentW = 0;
	}
}

void filmoteka::prevW(){
	currentW--;
	if(currentW<0){
		currentW=licznoscW-1;
	}
	
}
void filmoteka::showCurrentW(int x ,int y){
	wyszukane[currentW].piszXY(x,y);
	
}

void filmoteka::nextS(){
	currentS++;
	if(currentS>=licznoscS){
		currentS = 0;
	}
}

void filmoteka::prevS(){
	currentS--;
	if(currentS<0){
		currentS=licznoscS-1;
	}
	
}
void filmoteka::showCurrentS(int x ,int y){
	smietnik[currentS].piszXY(x,y);
	
}
void filmoteka::deleteCurrentS(){

	licznoscS--;
	smietnik[currentS]=smietnik[licznoscS];
	smietnik[licznoscS].wyczysc();
	if(currentS>0)currentS--;
}
void filmoteka::recoverCurrent(){
	if(licznosc<rozmiar){
		tabF[licznosc]=smietnik[currentS];
		licznosc++;
	}
}
void filmoteka::wyszukaj(char *gat)
{
	licznoscW=0;
	for(i=0;i<licznosc;i++)
	{
		if(!strcmp(tabF[i].getGatunek(),gat))
		{
			wyszukane[licznoscW]=tabF[i];
			licznoscW++;
		}
	}
}

void filmoteka::modifyNumbers(int liczba, char numer)
{
		switch(numer){
			case '4':
				tabF[current].setCena(liczba);
			break;
			case '6':
				tabF[current].setDlugosc(liczba);
			break;
			case '5':
				tabF[current].setRok_wydania(liczba);
		}
}

void filmoteka::modifyChars(char *tekst, char numer)
{
	switch(numer){
			case '1':
				tabF[current].setJezyk(tekst);
			break;
			case '2':
				tabF[current].setGatunek(tekst);
			break;
			case '3':
				tabF[current].setTytul(tekst);
			break;
			
		}
}

void filmoteka::sortCena(char rodzaj){
	film pom;
	if(rodzaj=='1'){
		for(int i=0;i<licznosc;i++)
		{
			for(int j=1;j<licznosc-i;j++) 
			{
				if(tabF[j-1].getCena()>tabF[j].getCena()) 
				{
				pom=tabF[j-1];
				tabF[j-1]=tabF[j];
				tabF[j]=pom;
				}
			}
		
		}
	}else {
		for(int i=0;i<licznosc;i++)
		{
			for(int j=1;j<licznosc-i;j++) 
			{
				if(tabF[j-1].getCena()<tabF[j].getCena()) 
				{
				pom=tabF[j-1];
				tabF[j-1]=tabF[j];
				tabF[j]=pom;
				}
			}
		
		}
	}
	
}
void filmoteka::sortDlugosc(char rodzaj){
	film pom;
	if(rodzaj=='1'){
		for(int i=0;i<licznosc;i++)
		{
			for(int j=1;j<licznosc-i;j++) 
			{
				if(tabF[j-1].getDlugosc()>tabF[j].getDlugosc()) 
				{
				pom=tabF[j-1];
				tabF[j-1]=tabF[j];
				tabF[j]=pom;
				}
			}
		
		}
	}else {
		for(int i=0;i<licznosc;i++)
		{
			for(int j=1;j<licznosc-i;j++) 
			{
				if(tabF[j-1].getDlugosc()<tabF[j].getDlugosc()) 
				{
				pom=tabF[j-1];
				tabF[j-1]=tabF[j];
				tabF[j]=pom;
				}
			}
		
		}
	}
	
}


int main() {
	
    char znak, znak2,arrow , tyt[40], gat[40], jez[10], usuwanie,sort, plik[20];
    float dl, cen, x;
    int roz, klienci=1 ,rok,a,b;
    cout<<"Podaj wielkosc naszej filmoteki: ";
    cin>>roz;
    cin.ignore();
    
    filmoteka filmy(roz, klienci);

    do{
    	
		cout << endl << endl <<"=================================="<<endl<<endl;
		cout << "[ 1 ] Dodaj Film" << endl;
		cout << "[ 2 ] Wyswietl wszystkie" << endl;
		cout << "[ 3 ] Usun wszystkie" << endl;
		cout << "[ 4 ] Tryb edycji" << endl;
		cout << "[ 5 ] Wyszukaj po przedziale cenowym" << endl;
		cout << "[ 6 ] Smietnik" << endl;
		cout << "[ 7 ] Wyszukaj po gatunku" << endl;
		cout << "[ S ] Zapisz plik" << endl;
		cout << "[ W ] Zapisz plik jako" << endl;
		cout << "[ O ] Wczytaj plik" << endl;
		cout << "[ 0 ] Zamknij" << endl;
       	cout << endl << endl <<"==================================";

        znak = getch();
        system("cls");
        switch (znak) {
        	case '1':
        		if(filmy.getLicznosc()<roz){

        			cout<<"Tytul: ";
        			gets(tyt);
        			cout<<"Gatunek: ";
        			gets(gat);
        			cout<<"Dlugosc: ";
        			cin>>dl;
        			cout<<"Cena: ";
        			cin>>cen;
        			cout<<"Rok Wydania: ";
        			cin>>rok;
        			fflush(stdin);
        			cout<<"Czy jest jezyk polski? (tak/nie): ";
        			gets(jez);
        			
        			filmy.dodajKolejny(tyt,gat,dl,cen,rok,jez);
        			system("cls");
				}
				else{
					cout<<"NIE MAMY MIEJSCA NA WIECEJ FILMOW!"<<endl;
				}
			break;
			case '2':
				system("cls");
				filmy.wypiszCalosc();
				cout<<endl<<endl<<"Pokazano "<<filmy.getLicznosc()<<" Pozostale miejsce: "<<roz-filmy.getLicznosc();
				getchar();
				system("cls");
				break;
			case '3':
				system("cls");
				cout<<"Czy napewno chcesz usunac wszytskie filmy? (y/n): ";
				usuwanie = getch();
				if(usuwanie!='y'){
					break;
				}else filmy.wyczyscCalosc();
				break;
			case '4':
				
					do{
					if(filmy.getLicznosc()>0){
						system("cls");
						filmy.showCurrent(10,5);
						gotoxy(8,11);
						cout<<"[<]PREV";
						gotoxy(18,11);
						cout<<"[B]BACK";
						gotoxy(28,11);
						cout<<"[I]INDEX";
						gotoxy(38,11);
						cout<<"[>]NEXT";
						gotoxy(48,11);
						cout<<"[U]DELETE";
						gotoxy(58,11);
						cout<<"[S]SORT";
						gotoxy(68,11);
						cout<<"[M]MODIFY";
						arrow = getch();
						switch(arrow){
							case '<':
								filmy.prev();
								break;
							case '>':
								filmy.next();
								break;
							case 'I':
								cout<<endl<<"Ktory film chcesz wyswietlic? ";
								cin>>x;
								if(!filmy.setCurrent(x)){
									cout<<endl<<"Nie ma filmu o tym numerze";
									getchar();
									
								}
								system("cls");
								break;
							case 'U':
								cout<<endl<<"Czy napewno chcesz usunac film? (y/n): ";
								usuwanie = getch();
								if(usuwanie!='y'){
									cout<<endl<<"nie usunieto!"<<endl;
									Sleep(1000);
								}else filmy.deleteCurrent();
								break;
								
							case 'S':
								cout<<endl<<"Posortowac po ? (1 - cena / 2 - dlugosc): ";
								fflush(stdin);
								usuwanie = getch();
								if(usuwanie=='1' || usuwanie=='2'){
									cout<<endl<<"Rosnaco/malejaco (1/2) ";
									sort=getch();
									if(sort=='1' || sort=='2'){
									
										switch(usuwanie){
											case '1':
												filmy.sortCena(sort);
												break;
											case '2':
												filmy.sortDlugosc(sort);
											break;	
									}
									cout<<endl<<"posortowano"<<endl;
									Sleep(1000);
									}else{
										cout<<endl<<"zly wybor"<<endl;
										Sleep(1000);
									}
								}else {
									cout<<endl<<"zly wybor"<<endl;
									Sleep(1000);
								}
								filmy.setCurrent(1);
								break;
							case 'M':
								
								do{
									system("cls");
									filmy.showCurrent(10,5);
									gotoxy(80,8);
									cout<<"1.Jezyk 2.Gatunek  3.tytul";
									gotoxy(80,9);
									cout<<"4.cena  5.rok  6.dlugosc  0.wyjdz";
									fflush(stdin);
									znak2=getch();
									gotoxy(87,10);
									switch(znak2){
										case'1':
											fflush(stdin);
											cout<<"jezyk: ";
					        				gets(jez);
					        				filmy.modifyChars(jez,znak2);
					        			break;
					        			case'2':
											fflush(stdin);
											cout<<"Gatunek: ";
					        				gets(gat);
					        				filmy.modifyChars(gat,znak2);
					        			break;
					        			case'3':
											fflush(stdin);
											cout<<"tytul: ";
					        				gets(tyt);
					        				filmy.modifyChars(tyt,znak2);
					        			break;
					        			case'4':
											fflush(stdin);
											cout<<"cena: ";
					        				cin>>cen;
					        				filmy.modifyNumbers(cen,znak2);
					        			break;
					        			case'5':
											fflush(stdin);
											cout<<"rok: ";
					        				cin>>rok;
					        				filmy.modifyNumbers(rok,znak2);
					        			break;
					        			case'6':
											fflush(stdin);
											cout<<"dlugosc: ";
					        				cin>>dl;
					        				filmy.modifyNumbers(dl,znak2);
					        			break;
					        			default:
					        				cout<<endl<<"Zly numer"<<endl;
									}
									
								}	while(znak2!='0')	;
								break;
							case 'B':
								system("cls");
								break;
						}
					}else {
						system("cls");
						cout<<"NIE MASZ CZEGO EDYTOWAC!"<<endl;
						break;
					}
				}while( arrow !='B');
				
				break;
			case '5':
				fflush(stdin);
				cout<<endl<<"Podaj Przedzia³ cenowy: "<<endl<<"OD: ";
				cin>>a;
				fflush(stdin);
				cout<<endl<<"DO: ";
				cin>>b;
				filmy.wyszukajPrzedzial(a,b);
				filmy.setCurrentW(1);
				do{
					if(filmy.getLicznoscW()>0){
						
						system("cls");
						cout<<"   === WYSZUKANE ===";
						filmy.showCurrentW(10,5);
						gotoxy(13,11);
						cout<<"[<]PREV";
						gotoxy(23,11);
						cout<<"[B]BACK";
						gotoxy(33,11);
						cout<<"[>]NEXT";
						arrow = getch();
						switch(arrow){
							case '<':
								filmy.prevW();
								break;
							case '>':
								filmy.nextW();
								break;
							case 'B':
								system("cls");
								break;
						}
					}else {
						system("cls");
						cout<<"NIE ZNALEZIONO NIC!"<<endl;
						break;
					}
				}while( arrow !='B');
				
				break;
			case '6':
				filmy.setCurrentS(1);
				do{
					if(filmy.getLicznoscS()>0){
						
						system("cls");
						filmy.showCurrentS(10,5);
						gotoxy(8,11);
						cout<<"[<]PREV";
						gotoxy(18,11);
						cout<<"[B]BACK";
						gotoxy(28,11);
						cout<<"[R]RECOVER";
						gotoxy(38,11);
						cout<<"[>]NEXT";
						gotoxy(48,11);
						cout<<"[U]DELETE";
						arrow = getch();
						switch(arrow){
							case '<':
								filmy.prevS();
								break;
							case '>':
								filmy.nextS();
								break;
							case 'R':
								if(filmy.getLicznosc()<roz){
									filmy.recoverCurrent();
									cout<<endl<<"PRZYWROCONO NA MIEJSCE: "<<filmy.getLicznosc()-1<<endl;
									filmy.deleteCurrentS();
								}else {
									cout<<"Nie ma miejsca na przywrocenie!"<<endl;
									system("pause");
								}
								break;
									
							case 'U':
								cout<<"Czy napewno chcesz usunac ten film !!NA ZAWSZE!! ? (y/n): ";
								usuwanie = getch();
								if(usuwanie!='y'){
									break;
								}else filmy.deleteCurrentS();
								break;
								
							case 'B':
								system("cls");
								break;
						}
					}else {
						system("cls");
						cout<<"SMIETNIK JEST PUSTY!"<<endl;
						break;
					}
				}while( arrow !='B');
				
				break;
			case '7':
				cout<<endl<<"Podaj gatunek: "<<endl;
				fflush(stdin);
				gets(gat);
				fflush(stdin);
				filmy.wyszukaj(gat);
				filmy.setCurrentW(1);
				do{
					if(filmy.getLicznoscW()>0){
						system("cls");
						cout<<"   === WYSZUKANE ===";
						filmy.showCurrentW(10,5);
						gotoxy(13,11);
						cout<<"[<]PREV";
						gotoxy(23,11);
						cout<<"[B]BACK";
						gotoxy(33,11);
						cout<<"[>]NEXT";
						arrow = getch();
						switch(arrow){
							case '<':
								filmy.prevW();
								break;
							case '>':
								filmy.nextW();
								break;
							case 'B':
								system("cls");
								break;
						}
					}else {
						system("cls");
						cout<<"NIE ZNALEZIONO NIC!"<<endl;
					}
				}while( arrow !='B');
				break;	
						
			case 'S':
				cout<<"Napewno chcesz zapisaæ plik (moze byc on pusty) y/n";
				usuwanie = getch();
				switch(usuwanie){
					case 'y':
						strcpy(plik,"filmy");
						filmy.zapiszPlik(plik);
						cout<<endl<<"PLIK ZOSTAL ZAPISANY"<<endl;
						break;
					case 'n':
						cout<<endl<<"PLIK NIE ZOSTAL ZAPISANY"<<endl;
						break;
					default:
						cout<<endl<<"ZLA OPCJA"<<endl;
						break;	
				}
				strcpy(plik,"");
				break;
				case 'W':
				cout<<"Napewno chcesz zapisaæ plik (moze byc on pusty) y/n";
				usuwanie = getch();
				switch(usuwanie){
					case 'y':
						cout<<endl<<"podaj nazwe: ";
						fflush(stdin);
						gets(plik);
						fflush(stdin);
						filmy.zapiszPlik(plik);
						cout<<endl<<"PLIK ZOSTAL ZAPISANY"<<endl;
						break;
					case 'n':
						cout<<endl<<"PLIK NIE ZOSTAL ZAPISANY"<<endl;
						break;
					default:
						cout<<endl<<"ZLA OPCJA"<<endl;
						break;	
				}
				strcpy(plik,"");
				break;
			case 'O':
				cout<<"Napewno chcesz wczytac plik (mozesz utracic aktualne dane) y/n";
				usuwanie = getch();
				switch(usuwanie){
					case 'y':
						cout<<endl<<"podaj nazwe: ";
						fflush(stdin);
						gets(plik);
						fflush(stdin);
						filmy.wczytajPlik(plik);
						cout<<endl<<"PLIK ZOSTAL Wczytany"<<endl;
						break;
					case 'n':
						cout<<endl<<"PLIK NIE ZOSTAL WCZYTANY"<<endl;
						break;
					default:
						cout<<endl<<"ZLA OPCJA"<<endl;
						break;	
				}
				strcpy(plik,"");
				break;
			case '0':
				cout<<"Czy napewno chcesz wyjœæ? 0-tak cokolwiek-nie";
				usuwanie=getch();
				if(usuwanie!='0'){
					znak='1';
				}
				break;							
        }
    }while (znak != '0');
}





















