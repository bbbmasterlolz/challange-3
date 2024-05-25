#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef char str[128];

typedef struct kursi{
		int isi;
		str nama;
		str hp;
		str email;
		str bayar;
	}kursi;

int main() {
	int k, i, j, menu;
	str t_nama, t_hp, t_email, cek_at, t_bayar;
	char kode, Kode;
	str kordinat;
	kursi arr[12][8];
	char tl = 201, bl = 200, tr = 187, br = 188, v = 186, h = 205;
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			arr[i][j].isi=0;
		}
	}
	
	do{
		system("cls");
		printf(
			"\t--== Registrasi Tim MPL ==--\n"
			"\n [1]. Panitia"
			"\n [2]. Manager"
			"\n [3]. Beli tiket MPL Season 99"
			"\n [4]. Cari Data Tiket"
			"\n [ESC]. Exit"
			"\n >>>"
		);menu=getche();

		switch(menu){
			case 51:
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
				printf("\n\t\t\t     --- [ Form Pembelian Ticket MPL Arena Season 99  ] ---");
				
				do{
					printf("\n\n\t\tMasukkan Nama            : ");
					fflush(stdin); gets(t_nama);
					if(strcmp(t_nama, "-")==0||strcmp(t_nama, "")==0){
						printf("\n\t\t[!] Nama Penonton Tidak Boleh Kosong atau '-' [!]");
					}
				}while(strcmp(t_nama, "-")==0||strcmp(t_nama, "")==0);
				
				do{
					printf("\n\t\tMasukkan Nomor Handphone : ");
					fflush(stdin); gets(t_hp);
					if(strcmp(t_hp, "-")==0||strcmp(t_hp, "")==0){
						printf("\n\t\t[!] Nomor Handphone Tidak Boleh Kosong atau '-' [!]\n");
					}
				}while(strcmp(t_hp, "-")==0||strcmp(t_hp, "")==0);
				
				do{
					printf("\n\t\tMasukkan Email           : ");
					fflush(stdin); gets(t_email);
					k = strlen(t_email);
					for(i=0;i<k;i++){
						sprintf(cek_at+i,"%c", t_email[k-10+i]);
					}
					if(strcmp(t_email, "-")==0||strcmp(t_email, "")==0){
						printf("\n\t\t[!] Email Tidak Boleh Kosong atau '-' [!]\n");
					}else if(strcmp(cek_at, "@gmail.com")!=0){
						printf("\n\t\t[!] Email harus memiliki format '@gmail.com' [!]\n");
					}
				}while(strcmp(t_email, "-")==0||strcmp(t_email, "")==0||strcmp(cek_at, "@gmail.com")!=0);
				
				do{
					printf("\n\t\tMasukkan Nomor Kursi     : ");
					fflush(stdin); gets(kordinat);
					if(kordinat[0]-'A'<0||kordinat[0]-'A'>11||kordinat[1]-'1'<0||kordinat[1]-'1'>7){
						printf("\n\t\t[!] Nomor Kursi Tidak Tersedia [!]\n");
					}else if(arr[kordinat[0]-'A'][kordinat[1]-'1'].isi==1){
						printf("\n\t\t[!] Nomor Kursi Ini Sudah Ada Yang Punya [!]\n");
					}else{
						break;
					}
				}while(1);
				
				do{
					printf("\n\t\tPilih Metode Pembayaran [QRIS / Cash] : ");
					fflush(stdin); gets(t_bayar);
					if(strcmpi(t_bayar, "QRIS")!=0&&strcmpi(t_bayar, "CASH")!=0){
						printf("\n\t\t[!] Metode Yang Tersedia Hanya [QRIS / CASH] [!]\n");
					}
				}while(strcmpi(t_bayar, "QRIS")!=0&&strcmpi(t_bayar, "CASH")!=0);
				
				arr[kordinat[0]-'A'][kordinat[1]-'1'].isi=1;
				strcpy(arr[kordinat[0]-'A'][kordinat[1]-'1'].nama, t_nama);
				strcpy(arr[kordinat[0]-'A'][kordinat[1]-'1'].hp, t_hp);
				strcpy(arr[kordinat[0]-'A'][kordinat[1]-'1'].email, t_email);
				strcpy(arr[kordinat[0]-'A'][kordinat[1]-'1'].bayar, t_bayar);
				printf("\n\t\t[+] Berhasil Membeli Nomor Kursi %s Atas Nama %s [+]", kordinat, t_nama);
				break;
				
			case 52:
				printf("\n\t--- [ Cari Data Tiket ] ---\n");
				printf("\n\tMasukkan Nomor Kursi Yang Ingin Dicari : ");
				fflush(stdin); gets(kordinat);
				if(kordinat[0]-'A'<0||kordinat[0]-'A'>11||kordinat[1]-'1'<0||kordinat[1]-'1'>7){
					printf("\n\t\t[!] Data Kursi Tidak Ditemukan [!]\n");
				}else if(arr[kordinat[0]-'A'][kordinat[1]-'1'].isi==0){
					printf("\n\t\t[!] Data Kursi Tidak Ditemukan [!]\n");
				}else{
					printf("\n\t\t----- [ Kursi Nomor A1 ] -----");
					printf("\n\t\t--> Nama              : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].nama);
					printf("\n\t\t--> Nomor Handphone   : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].hp);
					printf("\n\t\t--> Email             : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].email);
					printf("\n\t\t--> Metode Pembayaran : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].bayar);	
					break;
				}
				break;	
		}getch();
	}while(1);
	return 0;
}
