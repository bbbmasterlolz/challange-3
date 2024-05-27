#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef char string[100];
typedef char str[128];

typedef struct{
	int isi;
	string namaPemain;
	string rolePemain;
	float hargaPemain;
	int noPemain;
}Pemain;

typedef struct{
	string namaTim;
	string userTim;
	string passTim;
	float saldoTim;
	Pemain P[20];
}Tim;

typedef struct kursi{
		int isi;
		str nama;
		str hp;
		str email;
		str bayar;
}kursi;

void initData(Tim T[]);
void showmenu();
bool ceklogin(string user, string pass);
void captha(char acak[]);
bool cekcaptha(char acak[], string cap);

//case 1
void showsubmenu1();
int getEmptyTim(Tim T[]);
bool isEmptyTim(Tim T[]);
void tampilTim(Tim T[]);
bool samanamaTim(Tim T[], string tempnamaTim);
bool samauserTim(Tim T[], string tempuserTim);
int findTim(Tim T[], string tempnamaTim);
void hapusTim(Tim T[], int indexT);

//case 2
void showsubmenu2(Tim T[], int indexT);
int loginManager(Tim T[], string tempuserTim, string temppassTim);
int getEmptyPemain(Tim T[], int indexT);
bool isEmptyPemain(Tim T[], int indexT);
void tampilPemain(Tim T[], int index);
int findPemain(Tim T[], int index, int tempNo);
void hapusPemain(Tim T[], int index, int indexs);

//case 3
void c3(kursi arr[12][8]);

//case 4
void c4(kursi arr[12][8]);
