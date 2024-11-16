#include <iostream>
using namespace std;
// Bagian Inisialisasi Dan Fungsi Fungsi  

// inisialisasi Jumlah Ticket 
const int MAX_TICKETS = 5;
// struktur data untuk ticket 
struct Ticket {
    int id;
    string nama;
    string BookingOleh;
    bool diBooking;
};

// INI UNTUK INISIALISASI CONSOLE DAN SAMBUTAN
void inisialisasi_Console(){
	    system("color 57"); // ini untuk ganti backgroud color dan text color ya dek~!!
	cout << "===================================================\n";
	cout << "===================================================\n";
	cout << "  ____  ____  ____ ___  _    _____  _ ___  _\n";
    cout << " /  __\\/  _ \\/  _ \\\\  \\//   /__ __\\/ \\\\  \\//\n";
    cout << " | | //| / \\|| / \\| \\  /_____ / \\  | | \\  / \n";
    cout << " | |_\\\\| \\_/|| \\_/| /  \\\\____\\| |  | | /  \\ \n";
    cout << " \\____/\\____/\\____//__/\\\\     \\_/  \\_//__/\\\\\n";
    cout << "                                             \n";
    cout << "================ Created By =======================\n";
    cout << "================ Kelompok 3 =======================\n";
	
};
// FUNGSI UNTUK MENAMPILKAN TICKET YANG MASIH ADA
void cekTicketYangMasihAda(Ticket tickets[], int jumlahTicket) {
    cout << "\nTiket yang tersedia:\n";
    cout << "ID\tNama Tiket\t\t\tStatus\n";
    for (int i = 0; i < jumlahTicket; i++) {
        if (!tickets[i].diBooking) {
            cout << tickets[i].id << "\t" << tickets[i].nama << "\tSIAP DI BOOKING\n";
        }
    }
};

// Fungsi untuk booking tiket
void bookTicket(Ticket tickets[], int jumlahTicket) {
	
    int ticketId;
    string namaPembeli;

    cout << "\nMasukkan ID tiket yang ingin dipesan: ";
    cin >> ticketId;

    // Validasi tiket
    if (ticketId < 1 || ticketId > jumlahTicket || tickets[ticketId - 1].diBooking) {
        cout << "Tiket tidak tersedia atau sudah dipesan!\n";
        return;
    }

    cout << "Masukkan Nama : ";
    cin.ignore();
    getline(cin, namaPembeli);

    // Proses pemesanan
    tickets[ticketId - 1].diBooking = true;
    tickets[ticketId - 1].BookingOleh = namaPembeli;

    cout << "Tiket berhasil dipesan oleh " << namaPembeli << "!\n";
};
// cek daftar pesanan
void tampilkan(Ticket tickets[], int jumlahTicket) {
    cout << "\nDaftar Pemesanan:\n";
    cout << "ID\tNama Pelanggan\tTicket Yang Dibeli\n";
    for (int i = 0; i < jumlahTicket; i++) {
        if (tickets[i].diBooking) {
            cout << tickets[i].id << "\t" << tickets[i].BookingOleh << "\t\t"<< tickets[i].nama <<"\n";
        }
    }
};



int main(){
	// List Ticket 
	Ticket tickets[MAX_TICKETS] = {
        {1, "NOTFUSSED FEST 2024\t","null", false},
        {2, "ATMA ASTA 2024\t\t","null", false},
        {3, "KICKFEST 2024\t\t","null" ,false},
        {4, "SAIL AND CONNECT THE PANTURAS","null", false},
        {5, "ELEVENTWELFTH JAPAN TOUR 2024","null", false},
    };
    // init console begin
	inisialisasi_Console();
	int pilihan;
    do {
		cout << "\n********  Silahkan Pilih Menunya!  ********\n\n";
        cout << "1. Lihat tiket yang tersedia\n";
        cout << "2. Pesan tiket\n";
        cout << "3. Lihat daftar pemesanan\n";
        cout << "4. Keluar\n";
      	cout << "\n*******************************************\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
            	system("cls");
                cekTicketYangMasihAda(tickets, MAX_TICKETS);
                break;
            case 2:
            	system("cls");
            	cekTicketYangMasihAda(tickets, MAX_TICKETS);
            	cout << '\n';
                bookTicket(tickets, MAX_TICKETS);
                break;
            case 3:
            	system("cls");
                tampilkan(tickets, MAX_TICKETS);
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";

        };
    } while (pilihan != 4);
    	system("cls");
      cout << "===================================================\n";
				cout << "===================================================\n";
				cout << "  ____  ____  ____ ___  _    _____  _ ___  _\n";
    			cout << " /  __\\/  _ \\/  _ \\\\  \\//   /__ __\\/ \\\\  \\//\n";
			    cout << " | | //| / \\|| / \\| \\  /_____ / \\  | | \\  / \n";
			    cout << " | |_\\\\| \\_/|| \\_/| /  \\\\____\\| |  | | /  \\ \n";
			    cout << " \\____/\\____/\\____//__/\\\\     \\_/  \\_//__/\\\\\n";
			    cout << "                                             \n";
			    cout << "================ Created By =======================\n";
			    cout << "================ Kelompok 3 =======================\n\n";
			    cout << "TERIMAKASIH SUDAH MENGGUNAKAN APLIKASI INI! <3";
    

}

