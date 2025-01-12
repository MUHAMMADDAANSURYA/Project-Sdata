#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

struct KTP {
    string nama;
    string nik;
    string alamat;
};

struct Item {
    string kode;
    string tanggal;
};

struct Pembeli {
    string ktp;
    string waktu_kedatangan;
    string kode_item;
};

void entriDataKTP() {
    ofstream file("data_ktp.txt", ios::app);
    int jumlah;
    cout << "Berapa banyak data KTP yang ingin dimasukkan? ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        KTP ktp;
        cout << "Masukkan nama: ";
        getline(cin, ktp.nama);
        cout << "Masukkan NIK: ";
        getline(cin, ktp.nik);
        cout << "Masukkan alamat: ";
        getline(cin, ktp.alamat);

        file << ktp.nama << "|" << ktp.nik << "|" << ktp.alamat << endl;
    }
    file.close();
    cout << "Data KTP berhasil disimpan ke data_ktp.txt\n";
}

void entriBarang(stack<Item> &lifo, queue<Item> &fifo) {
    int jumlah;
    cout << "Masukkan jumlah item barang: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        Item item;
        cout << "Masukkan kode item: ";
        getline(cin, item.kode);
        cout << "Masukkan tanggal masuk (tgl-bulan-tahun): ";
        getline(cin, item.tanggal);

        lifo.push(item);
        fifo.push(item);
    }
    cout << "Item berhasil ditambahkan ke gudang.\n";
}

void jualLIFO(stack<Item> &lifo) {
    if (lifo.empty()) {
        cout << "Gudang kosong! Tidak ada barang untuk dijual.\n";
        return;
    }

    Item item = lifo.top();
    lifo.pop();

    cout << "Barang dengan kode " << item.kode << " dan tanggal " << item.tanggal << " telah dijual.\n";
}

void jualFIFO(queue<Item> &fifo) {
    if (fifo.empty()) {
        cout << "Gudang kosong! Tidak ada barang untuk dijual.\n";
        return;
    }

    Item item = fifo.front();
    fifo.pop();

    cout << "Barang dengan kode " << item.kode << " dan tanggal " << item.tanggal << " telah dijual.\n";
}

void cetakBarang(stack<Item> lifo, queue<Item> fifo) {
    cout << "\nDaftar Barang (LIFO - Last In First Out):\n";
    while (!lifo.empty()) {
        Item item = lifo.top();
        lifo.pop();
        cout << item.kode << " - " << item.tanggal << endl;
    }

    cout << "\nDaftar Barang (FIFO - First In First Out):\n";
    while (!fifo.empty()) {
        Item item = fifo.front();
        fifo.pop();
        cout << item.kode << " - " << item.tanggal << endl;
    }
}

int main() {
    stack<Item> lifo; 
    queue<Item> fifo; 

    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Entri data KTP\n";
        cout << "2. Entri item barang ke gudang\n";
        cout << "3. Jual item barang (LIFO - Last In First Out)\n";
        cout << "4. Jual item barang (FIFO - First In First Out)\n";
        cout << "5. Cetak daftar barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
        case 1:
            entriDataKTP();
            break;
        case 2:
            entriBarang(lifo, fifo);
            break;
        case 3:
            jualLIFO(lifo);
            break;
        case 4:
            jualFIFO(fifo);
            break;
        case 5:
            cetakBarang(lifo, fifo);
            break;
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
