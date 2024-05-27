#include "header.h"

void showmenu(){
	printf("        --== Registrasi Tim MPL ==--");
	printf("\n\n [1]. Panitia");
	printf("\n [2]. Manager");
	printf("\n [3]. Beli tiket MPL Season 99");
	printf("\n [4]. Cari Data Tiket");
	printf("\n [ESC]. Exit");
	printf("\n >>> ");
}

bool ceklogin(string user, string pass){
	if(!strcmp(user,"panitia") && !strcmp(pass,"admin")){
		return true;
	}else{
		return false;
	}
}

void captha(char acak[]){
	int temp;
	acak[0] = 'A' + rand()%26;
	acak[4] = 'A' + rand()%26;
	acak[1] = 'a' + rand()%26;
	acak[5] = 'a' + rand()%26;
	acak[2] = '0' + rand()%10;
	acak[6] = '0' + rand()%10;
	
	temp = rand()%(3-1+1)+1;

	if(temp == 1){
    		acak[3] = 'a' + rand() %26;
		}else if(temp == 2){
			acak[3] = 'A' + rand() %26;
		}else{
			acak[3] = '0' + rand() %10;
		}
}

bool cekcaptha(char acak[], string cap){
	if(!strcmp(cap,acak)){
		return true;
	}else{
		return false;
	}
}

void showsubmenu1(){
	printf("\n        --== Login sebagai 'Panitia' ==--");
	printf("\n        [1]. Daftarkan Tim");
	printf("\n        [2]. Hapus Tim");
	printf("\n        [3]. Edit Tim");
	printf("\n        [4]. Tampil Tim");
	printf("\n        [5]. Cari Tim");
	printf("\n        [ESC]. Log-out");
	printf("\n        >>> ");
}

int getEmptyTim(Tim T[]){
	int i;
	for(i=0;i<16;i++){
		if(!strcmpi(T[i].namaTim,"-")){
			return i;
		}
	}
	return -1;
}

void initData(Tim T[]){
	int i, j;
	
	for(i=0; i<16; i++){
		strcpy(T[i].namaTim,"-");
		strcpy(T[i].userTim,"-");
		strcpy(T[i].passTim,"-");
		T[i].saldoTim = 10000;
		for(j=0;j<16;j++){
			strcpy(T[i].P[j].namaPemain,"-");
			strcpy(T[i].P[j].rolePemain,"-");
			T[i].P[j].hargaPemain = 0;
			T[i].P[j].noPemain = j+1;
			T[i].P[j].isi = 0;
		}
	}
}
	
bool isEmptyTim(Tim T[]){
	int i;
	for(i=0;i<16;i++){
		if(strcmpi(T[i].namaTim,"-")){
			return false;
		}
	}
	return true;
}

void tampilTim(Tim T[]){
	int i, j, k;
	for(i=0;i<16;i++){
		if(strcmpi(T[i].namaTim,"-")){
			printf("\n        Nama Tim : %s", T[i].namaTim);
			printf("\n        Username : %s", T[i].userTim);
			printf("\n        Password : %s", T[i].passTim);
			printf("\n        Saldo    : Rp. %.2f", T[i].saldoTim);
			printf("\n");
			k = 0;
			for(j=0; j<20; j++){
				if(T[i].P[j].isi == 1){
					printf("\n                Nama Pemain  : %s", T[i].P[j].namaPemain);
					printf("\n                Role Player  : %s", T[i].P[j].rolePemain);
					printf("\n                Harga Pemain : Rp. %.2f", T[i].P[j].hargaPemain);
					printf("\n"); k++;
				}
			}
			if(k == 0){
				printf("\n                [!] Tim ini belum ada player [!]\n");	
			}
		}
	}
}

bool samanamaTim(Tim T[], string tempnamaTim){
	int i;
	for(i=0; i<16; i++){
		if(!strcmpi(T[i].namaTim,tempnamaTim)){
			return true;
		}
	}
	return false;
}

bool samauserTim(Tim T[], string tempuserTim){
	int i;
	for(i=0; i<16; i++){
		if(!strcmpi(T[i].userTim,tempuserTim)){
			return true;
		}
	}
	return false;
}

int findTim(Tim T[], string tempnamaTim){
	int i;
	for(i=0; i<16; i ++){
		if(!strcmpi(T[i].namaTim, tempnamaTim)){
			return i;
		}
	}
	return -1;
}


void hapusTim(Tim T[], int indexT){
	int i,  j;
	
	for(i = indexT ; i < 15 ; i ++){
		strcpy(T[i].namaTim, T[i+1].namaTim);
		strcpy(T[i].userTim, T[i+1].userTim);
		strcpy(T[i].passTim, T[i+1].passTim);
		T[i].saldoTim = T[i+1].saldoTim;
		for(j = 0; j<20 ; j ++){
			strcpy(T[i].P[j].namaPemain, T[i+1].P[j].namaPemain);
			strcpy(T[i].P[j].rolePemain, T[i+1].P[j].rolePemain);
			T[i].P[j].hargaPemain = T[i+1].P[j].hargaPemain;
			T[i].P[j].isi = T[i+1].P[j].isi;
		}
	}
	strcpy(T[15].namaTim,"-");
	strcpy(T[15].userTim,"-");
	strcpy(T[15].passTim,"-");
	T[15].saldoTim = 10000;
	for(j = 0; j<20 ; j ++){
		strcpy(T[15].P[j].namaPemain,"-");
		strcpy(T[15].P[j].rolePemain,"-");
		T[15].P[j].hargaPemain = 0;
		T[15].P[j].isi = 0;
	}
}

int loginManager(Tim T[], string tempuserTim, string temppassTim){
    int i;
	
	for(i=0; i<16; i++){
		if(!strcmp(tempuserTim,T[i].userTim) && !strcmp(temppassTim,T[i].passTim)){
			return i;
		}	
	}    
	return -1;	
}

void showsubmenu2(Tim T[], int indexT){
	printf("\n        --== Login sebagai Tim : %s ==--", T[indexT].namaTim);
	printf("\n        Saldo : Rp %.2f", T[indexT].saldoTim);
	printf("\n        [1]. Daftarkan Pemain");
	printf("\n        [2]. Beli Pemain");
	printf("\n        [3]. Hapus Pemain");
	printf("\n        [4]. Edit Pemain");
	printf("\n        [5]. Tampil Pemain");
	printf("\n        [ESC]. Logout");
	printf("\n        >>> ");
}

int getEmptyPemain(Tim T[], int indexT){
	int i;
	for(i=0; i<20; i ++){
		if(!strcmpi(T[indexT].P[i].namaPemain,"-")){
			return i;
		}
	}
	return -1;
}

bool isEmptyPemain(Tim T[], int indexT){
	int i;
	for(i=0;i<20;i++){
		if(T[indexT].P[i].isi==1){
			return false;
		}
	}
	return true;
}

void tampilPemain(Tim T[], int index){
	int i;
	for(i=0;i<20;i++){
		if(T[index].P[i].isi == 1){
			printf("\n        Nomor Punggung : %d", T[index].P[i].noPemain);
			printf("\n        Nama Pemain    : %s", T[index].P[i].namaPemain);
			printf("\n        Role Player    : %s", T[index].P[i].rolePemain);
			printf("\n        Harga Pemain   : Rp. %.2f", T[index].P[i].hargaPemain);
			printf("\n");
		}
	}
}

int findPemain(Tim T[], int index, int tempNo){
	int i;
	for(i=0; i<20; i ++){
		if(T[index].P[i].noPemain == tempNo && T[index].P[i].hargaPemain != 0){
			return i;
		}
	}
	return -1;
}

void hapusPemain(Tim T[], int index, int indexs){
	T[index].P[indexs].isi=0;
	strcpy(T[index].P[indexs].namaPemain,"-");
}

void c3(kursi arr[12][8]){
	int k, i, j, p;
    str t_nama, t_hp, t_email, cek_at, t_bayar;
    char kode, Kode, kode_a, kode_h;
    str kordinat, kode_s, temp;
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
    
    
    //normal
//    kode = 'A';
//    for(k=0;k<12;k++){
//        Kode = kode + k;
//        printf("\n\t\t[%c1]   [%c2]   [%c3]   [%c4]                         [%c5]   [%c6]   [%c7]   [%c8]",Kode,Kode,Kode,Kode,Kode,Kode,Kode,Kode);
//    }
    
    
//				inovasi
				kode_a = '1';
				kode_h = 'A';
				for(i=0;i<12;i++){
					p=0;
					strcpy(kode_s, "\n\t\t");
					p+=strlen("\n\t\t");
					for(j=0;j<8;j++){
						if(arr[i][j].isi==1){
							sprintf(kode_s+p, "\033[31m");
							p+=strlen("\033[31m");
						}
						sprintf(kode_s+p, "[%c%c]   ",kode_h+i, kode_a+j);
						p+=strlen("[A1]   ");
						if(j==3){
							sprintf(kode_s+p, "                      ");
							p+=strlen("                      ");
						}
						if(arr[i][j].isi==1){
							sprintf(kode_s+p, "\033[0m");
							p+=strlen("\033[0m");
						}
					}
					printf(kode_s);
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
}

void c4(kursi arr[12][8]){
	str kordinat;
	
	printf("\n\t--- [ Cari Data Tiket ] ---\n");
	printf("\n\tMasukkan Nomor Kursi Yang Ingin Dicari : ");
	fflush(stdin); gets(kordinat);
	if(kordinat[0]-'A'<0||kordinat[0]-'A'>11||kordinat[1]-'1'<0||kordinat[1]-'1'>7){
		printf("\n\t\t[!] Data Kursi Tidak Ditemukan [!]\n");
	}else if(arr[kordinat[0]-'A'][kordinat[1]-'1'].isi==0){
		printf("\n\t\t[!] Data Kursi Tidak Ditemukan [!]\n");
	}else{
		printf("\n\t\t----- [ Kursi Nomor %s ] -----", kordinat);
		printf("\n\t\t--> Nama              : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].nama);			
		printf("\n\t\t--> Nomor Handphone   : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].hp);
		printf("\n\t\t--> Email             : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].email);
		printf("\n\t\t--> Metode Pembayaran : %s", arr[kordinat[0]-'A'][kordinat[1]-'1'].bayar);		
	}	
}
