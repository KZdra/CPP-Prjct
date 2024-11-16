#include<iostream>
#include<string> 
#include <sstream>
#include <vector>
using namespace std;
// Bagian Inisialisasi Dan Fungsi Fungsi  

const int MAX_MOTOR = 5;
struct Motor {
    int id;
    string namaMotor;
    int harga;
    int stok;
};

void inisialisasi_Console(){
	    system("color 57"); // ini untuk ganti backgroud color dan text color ya dek~!!
	cout << "=======================================================================================================================\n";
	cout << "=======================================================================================================================\n";
  	cout << " \t_/\\\\\\________/\\\\\\_______/\\\\\\\\_______/\\\\\\_____/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\____\n";
    cout << " \t_\\/\\\\\\_______\\/\\\\\\_____/\\\\\\///\\\\\\____\\/\\\\\\\\\\___\\/\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\__\n";
    cout << "\t  _\\/\\\\\\_______\\/\\\\\\___/\\\\\\/__\\///\\\\\\__\\/\\\\\\/\\\\\\__\\/\\\\\\_\\/\\\\\\______\\//\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\/\n";
    cout << "\t   _\\/\\\\\\\\\\\\\\\\\\\\\\\\\\__/\\\\\\______\\//\\\\\\_\\/\\\\\\//\\\\\\_\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\n";
    cout << "\t    _\\/\\\\\\/////////\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\//\\\\\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\n";
    cout << "\t     _\\/\\\\\\_______\\/\\\\\\_\\//\\\\\\______/\\\\\\__\\/\\\\\\_\\//\\\\\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    cout << "\t      _\\/\\\\\\_______\\/\\\\\\__\\///\\\\\\__/\\\\\\____\\/\\\\\\__\\//\\\\\\\\\\_\\/\\\\\\_______/\\\\\\__\\/\\\\\\_______\\/\\\\\\_\n";
    cout << "\t       _\\/\\\\\\_______\\/\\\\\\____\\///\\\\\\/_____\\/\\\\\\___\\//\\\\\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/___\\/\\\\\\_______\\/\\\\\\_\n";
    cout << "\t        _\\///________\\///_______\\/////_______\\///_____\\/////__\\////////////____\\///________\\///__\n\n";
    cout << "================================================ Created By ==========================================================\n";
    cout << "================================================ Kelompok 3 ==========================================================\n";
	
};
// FORMAT KE RUPIAH

string formatKeRupiah(int angka, string perantara = ".") {
 stringstream ss; ss << angka; 
 string output = ss.str();
 int inspost = output.length() - 3;
 while (inspost > 0) {
  output.insert(inspost, perantara);
  inspost -= 3;
 }
 
 output = "Rp " + output;
 
 return output;
} 
// FUNGSI UNTUK MENAMPILKAN Motor YANG MASIH ADA
void cekMotorYangAda(Motor listMotor[], int jumlahMotor) {
    cout << "\nMotor  yang tersedia:\n";
    cout << "ID\tNama Motor\tHarga Motor\tStok\n";
    for (int i = 0; i < jumlahMotor; i++) {
        if (listMotor[i].stok != 0) {
            cout << listMotor[i].id << "\t" << listMotor[i].namaMotor << "\t"<< formatKeRupiah(listMotor[i].harga) << "\t"<< listMotor[i].stok <<"\n";
        } else {
        	cout << "MAAF MOTOR ABIS KAK!....\n";
		}
    }
};

// Fungsi untuk Beli Motor
void beliMotor(Motor listMotor[], int jumlahMotor) {
	
	// Cek apakah masih ada Motor yang tersedia
    bool motorTersedia = false;
    for (int i = 0; i < jumlahMotor; i++) {
        if (listMotor[i].stok > 0) {
            motorTersedia = true;
            break;
        }
    }
    
    if (!motorTersedia) {
        cout << "MAAF MOTOR ABIS KAK!....\n";
        return;
    }
    int motorId;
    int jumlah;
    string namaPembeli;

		
    cout << "\nMasukkan ID Motor yang ingin dipesan: ";
    cin >> motorId;


    if (motorId < 1 || motorId > jumlahMotor) {
        cout << "Motor tidak tersedia\n";
        return;
    } else if (listMotor[motorId - 1].stok == 0 ){
    	cout << "MOTOR HABIS!!!\n";
        return;
	}

    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin, namaPembeli);
    cout << "Beli Berapa? : ";
    cin >> jumlah;

    // Proses pemesanan
    listMotor[motorId - 1].stok =  listMotor[motorId - 1].stok - jumlah;
	int totalHarga = listMotor[motorId - 1].harga * jumlah; 
	
    cout << "MOTOR BERHASIL DIBELI OLEH " << namaPembeli << "\n";
    cout << "===============Invoice==================\n";
    cout << "Nama Motor\tHarga Motor\tJumlah\n";
    cout << listMotor[motorId - 1].namaMotor <<"\t"<< listMotor[motorId - 1].harga <<"\t"<< jumlah <<"\n";
	cout << "Total Harga: " << formatKeRupiah(totalHarga);
	cout << "\n========================================";

	
};





int main(){
//
	inisialisasi_Console();

   Motor motorList[] = {
        {1, "Honda CBR 150R", 35000000, 10},
        {2, "Honda CB150R", 33000000, 15},
        {3, "Honda Vario 150", 24000000, 20},
        {4, "Honda CRF 250L", 70000000, 8},
        {5, "Honda Beat", 17000000, 25},
    };
    
	//
	int pilihan;
	
    do {
		cout << "\n********  Silahkan Pilih Menunya!  ********\n\n";
        cout << "1. Lihat Motor yang tersedia\n";
        cout << "2. Pesan Motor\n";
        cout << "3. Keluar\n";
      	cout << "\n*******************************************\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            	system("cls");
                cekMotorYangAda(motorList, MAX_MOTOR);
                break;
            case 2:
            	system("cls");
            	cekMotorYangAda(motorList, MAX_MOTOR);
            	cout << '\n';
                beliMotor(motorList, MAX_MOTOR);
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";

        };
    } while (pilihan != 3);
    system("cls");
   	inisialisasi_Console();
	cout << "\nTERIMAKASIH SUDAH MENGGUNAKAN APLIKASI INI! <3";
    

}

