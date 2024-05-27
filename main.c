#include "header.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	Tim T[16];
	int indexT, indexP;
	string pass, user, cap, konf;
	string tempnamaTim,tempuserTim, temppassTim, tempnamaPemain;
	int tempNo;
	float temphargaPemain;
	float saldo;
	char acak[6];
	int menu, submenu, cek, i, j;
	int timbeli, timbeliP;
	initData(T);
	kursi arr[12][8];
	
	for(i=0;i<12;i++){
		for(j=0;j<8;j++){
			arr[i][j].isi=0;
		}
	}
	
	do{
		system("cls");
		showmenu();
		menu = getche();
		
		switch(menu){
			case '1':
				while(1){
					printf("\n        [Login Panitia]");
					printf("\n        Username : ");fflush(stdin);gets(user);
					printf("        Password : ");fflush(stdin);gets(pass);
					if(ceklogin(user,pass) != true){
						printf("\n        [!] Username atau Password salah!\n");
					}else{
						break;
					}
				}
				while(1){
					captha(acak);
					printf("\n        Captcha : %s", acak);
					printf("\n        > ");fflush(stdin);gets(cap);
					if(cekcaptha(acak, cap) !=true){
						printf("\n        [!] Captcha salah\n");
					}else{
						break;
					}	
				}
				do{
					system("cls");
					showsubmenu1();
					submenu = getche();
					
					switch(submenu){
						case '1':
							if(getEmptyTim(T)==-1){
								printf("\n        [!] Tim sudah penuh");
								break;
							}
							printf("\n        --- [Pendataran Tim] ---\n\n");
							indexT = getEmptyTim(T);
							while(1){
								printf("        Masukkan nama tim : ");fflush(stdin);gets(tempnamaTim);
								if(!strcmpi(tempnamaTim,"-")){
									printf("\n        [!] Nama tim tidak boleh menggunakan '-'\n");
								}else if(strlen(tempnamaTim)==0){
									printf("\n        [!] Nama tim tidak boleh kosong\n");
								}else if(samanamaTim(T,tempnamaTim)==true){
									printf("\n        [!] Nama tim sudah ada\n");
								}else{
									break;
								}							
							}
							strcpy(T[indexT].namaTim, tempnamaTim);
							while(1){
								printf("        Masukkan Username : ");fflush(stdin);gets(tempuserTim);
								if(!strcmpi(tempuserTim,"-")){
									printf("\n        [!] Username tidak boleh menggunakan '-'\n");
								}else if(strlen(tempuserTim)==0){
									printf("\n        [!] Username tidak boleh kosong\n");
								}else if(samauserTim(T, tempuserTim) == true){
									printf("\n        [!] Username sudah digunakan\n");
								}else{
									break;
								}	
							}
							strcpy(T[indexT].userTim, tempuserTim);
							while(1){
								printf("        Masukkan Password : ");fflush(stdin);gets(T[indexT].passTim);
								if(!strcmpi(T[indexT].passTim,"-")){
									printf("\n        [!] Password tidak boleh menggunakan '-'\n");
								}else if(strlen(T[indexT].passTim)==0){
									printf("\n        [!] Password tidak boleh kosong\n");
								}else{
									break;
								}
							}
							printf("\n        [+] Tim %s berhasil terdaftar", T[indexT].namaTim);
							printf("\n        --> Saldo Tim : Rp. %.2f", T[indexT].saldoTim);
						break;
						
						case '2':
							if(isEmptyTim(T) == true){
								printf("\n        [!] Tidak ada tim yang terdaftar");
								break;
							}
							printf("\n\n        --- [Hapus Tim] ---\n");
							printf("\n        Masukkan nama tim : ");fflush(stdin);gets(tempnamaTim);
							if(findTim(T, tempnamaTim) != -1){
								indexT = findTim(T, tempnamaTim);
								printf("\n        Nama Tim : %s", T[indexT].namaTim);
								printf("\n        Username : %s", T[indexT].userTim);
								printf("\n        Password : %s", T[indexT].passTim);
								printf("\n        Saldo    : Rp. %.2f\n", T[indexT].saldoTim);
								while(1){
									printf("        Yakin akan menghapus tim ? (y/n) : ");fflush(stdin);gets(konf);
									if(!strcmpi(konf,"Y")){
										hapusTim(T, indexT);
										printf("\n        [!] Tim yang terdaftar berhasil dihapus\n");
										break;
									}else if(!strcmpi(konf,"N")){
										printf("\n        [!] Penghapusan Tim dibatalkan\n");
										break;
									}else{
										printf("\n        [!] Inputan hanya menerima [Y/N]\n");
									}
								}
							}else{
								printf("\n        [!] Tim yang dicari tidak ditemukan");
							}
						break;
						
						case '3':
							if(isEmptyTim(T) == true){
								printf("\n        [!] Tidak ada tim yang terdaftar");
								break;
							}
							printf("\n\n        --- [Edit Data Tim] ---\n");
							printf("\n        Masukkan nama tim : ");fflush(stdin);gets(tempnamaTim);
							if(findTim(T, tempnamaTim) != -1){
								indexT = findTim(T, tempnamaTim);
								printf("\n        Nama Tim : %s", T[indexT].namaTim);
								printf("\n        Username : %s", T[indexT].userTim);
								printf("\n        Password : %s", T[indexT].passTim);
								printf("\n        Saldo    : Rp. %.2f\n", T[indexT].saldoTim);
								while(1){
									printf("        Yakin ingin mengedit tim ? (y/n) : ");fflush(stdin);gets(konf);
									if(!strcmpi(konf,"Y")){
										printf("\n");
										while(1){
											printf("        Masukkan nama tim : ");fflush(stdin);gets(tempnamaTim);
											if(!strcmpi(tempnamaTim,"-")){
												printf("\n        [!] Nama tim tidak boleh menggunakan '-'\n");
											}else if(strlen(tempnamaTim)==0){
												printf("\n        [!] Nama tim tidak boleh kosong\n");
											}else if(samanamaTim(T,tempnamaTim)==true){
												printf("\n        [!] Nama tim sudah ada\n");
											}else{
												break;
											}							
										}
										strcpy(T[indexT].namaTim, tempnamaTim);
										while(1){
											printf("        Masukkan saldo baru : ");scanf("%f", &saldo);
											if(saldo < 0){
												printf("\n        [!] Saldo Tidak Boleh Kurang Dari 0\n");
											}else{
												break;
											}
										}
										T[indexT].saldoTim = saldo;
										printf("\n        [!] Tim berhasil diedit\n");
										break;
									}else if(!strcmpi(konf,"N")){
										printf("\n        [!] Edit Tim dibatalkan\n");
										break;
									}else{
										printf("\n        [!] Inputan hanya menerima [Y/N]\n");
									}
								}
							}else{
								printf("\n        [!] Tim yang dicari tidak ditemukan");
							}
						break;
						
						case '4':
							if(isEmptyTim(T) == true){
								printf("\n        [!] Tidak ada tim yang terdaftar");
								break;
							}
							printf("\n        [Tampil Data Tim dan Pemain]\n\n");
							tampilTim(T);
						break;
						
						case '5':
							if(isEmptyTim(T) == true){
								printf("\n        [!] Tidak ada tim yang terdaftar");
								break;
							}
							printf("\n\n        --- [Cari Tim] ---\n");
							printf("\n        Masukkan nama tim : ");fflush(stdin);gets(tempnamaTim);
							if(findTim(T, tempnamaTim) != -1){
								indexT = findTim(T, tempnamaTim);
								printf("\n        Nama Tim : %s", T[indexT].namaTim);
								printf("\n        Username : %s", T[indexT].userTim);
								printf("\n        Password : %s", T[indexT].passTim);
								printf("\n        Saldo    : Rp. %.2f\n", T[indexT].saldoTim);
							}else{
								printf("\n        [!] Tim yang dicari tidak ditemukan");
							}
						break;
						
						case 27:
							printf("\n~        [!] Kembali ke menu utama...");
						break;
						
						default :
							printf("\n        [!] Menu tidak tersedia");
						break;
					}getch();
				}while(submenu != 27);
			break;
			
			case '2':
				printf("\n        [Login Manager]");
				printf("\n        Username : ");fflush(stdin);gets(tempuserTim);
				printf("        Password : ");fflush(stdin);gets(temppassTim);
				if(loginManager(T,tempuserTim,temppassTim)==-1){
					printf("\n        [!] Username atau password salah");
					break;
				}
				indexT = loginManager(T,tempuserTim,temppassTim);
				do{
					system("cls");
					showsubmenu2(T, indexT);
					submenu = getche();
					
					switch(submenu){
						case '1':
							if(getEmptyPemain(T, indexT) == -1){
								printf("\n        [!] Pemain sudah penuh");
								break;
							}
							printf("\n        --- [Pendaftaran Player] ---\n\n");
							indexP = getEmptyPemain(T,indexT);
							while(1){
								printf("        Nama Pemain           : ");fflush(stdin);gets(T[indexT].P[indexP].namaPemain);
								if(!strcmpi(T[indexT].P[indexP].namaPemain,"-")){
									printf("\n        [!] Nama player tidak boleh menggunakan '-'\n");
								}else if(strlen(T[indexT].P[indexP].namaPemain)==0){
									printf("\n        [!] Nama player tidak boleh kosong\n");
								}else{
									break;
								}							
							}
							while(1){
								printf("        Masukkan harga pemain : ");scanf("%f", &T[indexT].P[indexP].hargaPemain);
								if(T[indexT].P[indexP].hargaPemain < 0){
									printf("\n        [!] Harga Pemain Tidak Boleh Kurang Dari 0\n");
								}else{
									break;
								}							
							}
							while(1){
								printf("        Masukkan role player  : ");fflush(stdin);gets(T[indexT].P[indexP].rolePemain);
								if(!strcmpi(T[indexT].P[indexP].rolePemain,"-")){
									printf("\n        [!] Role player tidak boleh menggunakan '-'\n");
								}else if(strlen(T[indexT].P[indexP].rolePemain)==0){
									printf("\n        [!] Role player tidak boleh kosong\n");
								}else{
									break;
								}							
							}
							T[indexT].P[indexP].isi = 1;
							printf("\n\n        [!] Player berhasil ditambahkan");
						break;
						
						case '2':
							if(getEmptyPemain(T, indexT) == -1){
								printf("\n        [!] Pemain sudah penuh");
								break;
							}
							printf("\n        --- [Beli Player] ---");
							printf("\n\n        Cari Tim : ");fflush(stdin);gets(tempnamaTim);
							if(findTim(T, tempnamaTim) != -1){
								if(!strcmpi(tempnamaTim,T[indexT].namaTim)){
									printf("\n        [!] Tim Invalid");
									break;
								}
								timbeli = findTim(T, tempnamaTim);
								cek = 0;
								for(j=0; j<20; j++){
									cek +=T[timbeli].P[j].isi;
								}
								if(cek == 0){
									printf("\n        [!] Tim tidak punya pemain");
									break;	
								}
								printf("\n        --- [ Data Pemain Tim %s ] ---",T[timbeli].namaTim);
								tampilPemain(T,timbeli);
								printf("\n        Pemain yang ingin dibeli [Nomor Punggung] : ");scanf("%d", &tempNo);
								if(findPemain(T, timbeli, tempNo) != -1){
									timbeliP =  findPemain(T, timbeli, tempNo);
									//pembayaran
									if(T[indexT].saldoTim<T[timbeli].P[timbeliP].hargaPemain){
										printf("\n        Saldo tim tidak cukup [!]");
										break;
									}
									T[indexT].saldoTim-=T[timbeli].P[timbeliP].hargaPemain;
									T[timbeli].saldoTim+=T[timbeli].P[timbeliP].hargaPemain;
									
									//transfer pemain
									indexP = getEmptyPemain(T,indexT);
									strcpy(T[indexT].P[indexP].namaPemain,T[timbeli].P[timbeliP].namaPemain);
									strcpy(T[indexT].P[indexP].rolePemain,T[timbeli].P[timbeliP].rolePemain);
									T[indexT].P[indexP].hargaPemain = T[timbeli].P[timbeliP].hargaPemain;
									T[indexT].P[indexP].isi = 1;
									
									//hapus pemain
									hapusPemain(T,timbeli,timbeliP);
									T[timbeli].P[timbeliP].isi = 0;
								}else{
									printf("\n        [!] Pemain tidak ditemukan");
								}
							}else{
								printf("\n        [!] Tim Invalid");
							}
						break;
						
						case '3':
							if(isEmptyPemain(T, indexT) == true){
								printf("\n        [!] Tim belum mempunyai player");
								break;
							}
							printf("\n        Nomor punggung pemain : ");scanf("%d", &tempNo);
							if(findPemain(T, indexT, tempNo) != -1){
								indexP = findPemain(T, indexT, tempNo);
								printf("\n        [Hapus Pemain]\n");
								printf("\n        Nomor Punggung : %d", T[indexT].P[indexP].noPemain);
								printf("\n        Nama Pemain    : %s", T[indexT].P[indexP].namaPemain);
								printf("\n        Role Player    : %s", T[indexT].P[indexP].rolePemain);
								printf("\n        Harga Pemain   : Rp. %.2f", T[indexT].P[indexP].hargaPemain);
								while(1){
									printf("\n        Yakin ingin dihapus ? (y/n) : ");fflush(stdin);gets(konf);
									if(!strcmpi(konf,"Y")){
										hapusPemain(T,indexT,indexP);
										T[indexT].P[indexP].isi = 0;
										printf("\n        [!] Data pemain berhasil dihapus");
										break;
									}else if(!strcmpi(konf,"N")){
										printf("\n        [!] Data pemain tidak jadi dihapus\n");
										break;
									}else{
										printf("\n        [!] Inputan hanya menerima [Y/N]\n");
									}
								}
							}else{
								printf("\n        [!] Player tidak ditemukan");
							}
						break;
						
						case '4':
							if(isEmptyPemain(T, indexT)== true){
								printf("\n        [!] Tim belum mempunyai player");
								break;
							}
							printf("\n        Nomor punggung pemain : ");scanf("%d", &tempNo);
							if(findPemain(T, indexT, tempNo) != -1){
								indexP = findPemain(T, indexT, tempNo);
								printf("\n        [Edit Data Pemain]\n");
								printf("\n        Nomor Punggung : %d", T[indexT].P[indexP].noPemain);
								printf("\n        Nama Pemain    : %s", T[indexT].P[indexP].namaPemain);
								printf("\n        Role Player    : %s", T[indexT].P[indexP].rolePemain);
								printf("\n        Harga Pemain   : Rp. %.2f", T[indexT].P[indexP].hargaPemain);
								while(1){
									printf("\n        Yakin ingin di-edit ? (y/n) : ");fflush(stdin);gets(konf);
									if(!strcmpi(konf,"Y")){
										printf("\n");
										while(1){
											printf("        Nama Pemain           : ");fflush(stdin);gets(tempnamaPemain);
											if(!strcmpi(tempnamaPemain,"-")){
												printf("\n        [!] Nama player tidak boleh menggunakan '-'\n");
											}else if(strlen(tempnamaPemain)==0){
												printf("\n        [!] Nama player tidak boleh kosong\n");
											}else{
												break;
											}							
										}
										strcpy(T[indexT].P[indexP].namaPemain, tempnamaPemain);
										while(1){
											printf("        Masukkan harga pemain : ");scanf("%f", &temphargaPemain);
											if(temphargaPemain < 0){
												printf("\n        [!] Harga Pemain Tidak Boleh Kurang Dari 0\n");
											}else{
												break;
											}							
										}
										T[indexT].P[indexP].hargaPemain = temphargaPemain;
										printf("\n        [!] Data player berhasil di-edit");
										break;
									}else if(!strcmpi(konf,"N")){
										printf("\n        [!] Edit data dibatalkan\n");
										break;
									}else{
										printf("\n        [!] Inputan hanya menerima [Y/N]\n");
									}
								}
							}else{
								printf("\n        [!] Player tidak ditemukan");
							}
						break;
						
						case '5':
							if(isEmptyPemain(T, indexT)== true){
								printf("\n        [!] Tim belum mempunyai player");
								break;
							}
							printf("\n                --- [ Tampil Player ] ---\n");
							tampilPemain(T,indexT);
						break;
						
						case 27:
							printf("\n~        [!] Kembali ke menu utama...");
						break;
						
						default:
							printf("\n        [!] Menu tidak tersedia");
						break;
					}getch();
				}while(submenu != 27);
				
			break;
			
			case '3':
				c3(arr);	
			break;
			
			case '4':
				c4(arr);
			break;
			
			case 27:
				printf("\n~        [~] [DuoLeveling] - [230712519] - [230712483] [~]");
			break;
			default:
				printf("\n        [!] Menu Tidak Tersedia [!]");
			break;
		}getch();
	}while(menu !=27);
	return 0;
}
