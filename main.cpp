#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n;
    cout << "Masukan Jumlah Murid Di Kelas Ini: ";
    cin >> n;
    cin.ignore();
    string nama[n];
    int length = sizeof(nama) / sizeof(*nama);
    for(int i = 0; i < length; i++){
        cout << "Masukan Nama Murid Ke " << i + 1 << " = ";
        getline(cin, nama[i]);
    }
    
    for(int i = 0; i < length; i++){
        cout << "Nama Murid ke " << i + 1 << " = " << nama[i] << endl;
    }
    
    return 0;
}
