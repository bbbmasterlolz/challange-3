#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char str[128];

typedef struct kursi{
		int isi;
		str nama;
		str hp;
		str email;
	}kursi;

int main() {
	int k;
	char kode, Kode;
	kursi arr[12][8];
	char tl = 201, bl = 200, tr = 187, br = 188, v = 186, h = 205;
	printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,tl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,tr);
	printf("\n\t\t\t%c      oooooo   oooooo     oooo ooooo ooooo      ooo       %c", v, v);
	printf("\n\t\t\t%c      `888.    `888.     .8'  `888' `888b.     `8'        %c", v, v);
	printf("\n\t\t\t%c       `888.   .8888.   .8'    888   8 `88b.    8         %c", v, v);
	printf("\n\t\t\t%c        `888  .8'`888. .8'     888   8   `88b.  8         %c", v, v);
	printf("\n\t\t\t%c         `888.8'  `888.8'      888   8     `88b.8         %c", v, v);
	printf("\n\t\t\t%c          `888'    `888'       888   8       `888         %c", v, v);
	printf("\n\t\t\t%c           `8'      `8'       o888o o8o        `8         %c", v, v);
	printf("\n\t\t\t%c                                                          %c", v, v);
	printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,bl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,br);
	printf("\n");
	printf("\n\t\t[P1] [P2] [P3] [P4] [P5]                          [P1] [P2] [P3] [P4] [P5]");
	printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,tl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,tr,tl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,tr);
	printf("\n\t\t%c      WE OWN THIS      %c                         %c      WE OWN THIS      %c",v,v,v,v);
	printf("\n\t\t%c      EVOS ESPORT      %c                         %c      ONIC ESPORT      %c",v,v,v,v);
	printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c                         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
	,bl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,br,bl,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,h,br);
	printf("\n");
	printf("\n");
	
	kode = 'A';
	for(k=0;k<12;k++){
		Kode = kode + k;
		printf("\n\t\t[%c1]   [%c2]   [%c3]   [%c4]                         [%c5]   [%c6]   [%c7]   [%c8]",Kode,Kode,Kode,Kode,Kode,Kode,Kode,Kode);
	}
	
	printf("\n");
	printf("\n\t\t\t    --- [ Form Pembelian Ticket MPL Arena Season 99  ] ---");

	
	
	return 0;
}
