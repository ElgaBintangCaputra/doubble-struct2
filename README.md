# doubble-struct2
#include <iostream>
#include <string>
using namespace std;

struct Tanggal {
    int hari, bulan, tahun;
};

struct Nilai {
    float uts, uas, tugas;
};

struct Mahasiswa {
    string nama, jurusan;
    int umur;
    Tanggal lahir;
    Nilai nilaiMhs;
};

float hitungNilaiAkhir(Nilai n) {
    return (n.uas * 0.4) + (n.uts * 0.35) + (n.tugas * 0.25);
}

void tampilkanBobot(Nilai n) {
    cout << "BOBOT NILAI:" << endl;
    cout << "UAS 40%  : " << n.uas * 0.4 << endl;
    cout << "UTS 35%  : " << n.uts * 0.35 << endl;
    cout << "Tugas 25%: " << n.tugas * 0.25 << endl;
}

void inputData(Mahasiswa &m, int nomor) {
    cout << "\n=== DATA MAHASISWA KE-" << nomor << " ===" << endl;

    cin.ignore();
    cout << "Nama    : ";
    getline(cin, m.nama);

    cout << "Umur    : ";
    cin >> m.umur;

    cin.ignore();
    cout << "Jurusan : ";
    getline(cin, m.jurusan);

    cout << "TANGGAL LAHIR" << endl;
    cout << "Hari  : ";
    cin >> m.lahir.hari;
    cout << "Bulan : ";
    cin >> m.lahir.bulan;
    cout << "Tahun : ";
    cin >> m.lahir.tahun;

    cout << "\nNILAI" << endl;
    cout << "UTS   : ";
    cin >> m.nilaiMhs.uts;
    cout << "UAS   : ";
    cin >> m.nilaiMhs.uas;
    cout << "Tugas : ";
    cin >> m.nilaiMhs.tugas;
}

void tampilkanData(Mahasiswa m[], int jumlah) {
    cout << "\n\n=== HASIL DATA MAHASISWA ===" << endl;

    for(int i = 0; i < jumlah; i++) {
        cout << "\n----------------------------------------------------" << endl;
        cout << "MAHASISWA KE-" << (i + 1) << endl;
        cout << "Nama    : " << m[i].nama << endl;
        cout << "Umur    : " << m[i].umur << endl;
        cout << "Jurusan : " << m[i].jurusan << endl;
        cout << "Lahir   : " << m[i].lahir.hari << "-"
             << m[i].lahir.bulan << "-" << m[i].lahir.tahun << endl;

        cout << "\nNILAI AKADEMIK" << endl;
        cout << "UTS   : " << m[i].nilaiMhs.uts << endl;
        cout << "UAS   : " << m[i].nilaiMhs.uas << endl;
        cout << "Tugas : " << m[i].nilaiMhs.tugas << endl;

        tampilkanBobot(m[i].nilaiMhs);
        cout << "NILAI AKHIR: " << hitungNilaiAkhir(m[i].nilaiMhs) << endl;
    }
    cout << "----------------------------------------------------" << endl;
}

int main() {
    int jumlah;

    cout << "PROGRAM DATA MAHASISWA" << endl;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;

    if(jumlah <= 0) {
        cout << "Jumlah tidak valid!" << endl;
        return 1;
    }

    if(jumlah > 36) {
        cout << "Jumlah maksimal 36. Diatur ke 36." << endl;
        jumlah = 36;
    }

    Mahasiswa mhs[jumlah];

    for(int i = 0; i < jumlah; i++) {
        inputData(mhs[i], i + 1);
    }

    tampilkanData(mhs, jumlah);

    cout << "\nTerima kasih telah menggunakan program kami!" << endl;
    return 0;
}
