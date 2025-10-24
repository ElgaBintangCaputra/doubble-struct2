#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Nilai {
    float Mtk;
    float IPA;
    float BIn;
    float Big;
};

struct Siswa {
    string nama;
    string NISN;
    string jurusan;
    Nilai nilai;
    float nilaiAkhir;
};

// === Fungsi menghitung nilai akhir ===
float hitungNilaiAkhir(Nilai n) {
    return (n.Mtk * 0.35) + (n.IPA * 0.25) + (n.BIn * 0.20) + (n.Big * 0.20);
}

// === Input data siswa ===
void inputData(vector<Siswa> &daftar) {
    int jumlah;
    cout << "Masukkan jumlah siswa yang ingin dimasukkan: ";
    cin >> jumlah;
    cin.ignore();

    for (int i = 0; i < jumlah; i++) {
        Siswa s;
        cout << "\n=== DATA SISWA KE-" << i + 1 << " ===" << endl;
        cout << "Nama     : ";
        getline(cin, s.nama);
        cout << "NISN     : ";
        getline(cin, s.NISN);
        cout << "Jurusan  : ";
        getline(cin, s.jurusan);

        cout << "\n-- Nilai --" << endl;
        cout << "Matematika : ";
        cin >> s.nilai.Mtk;
        cout << "IPA         : ";
        cin >> s.nilai.IPA;
        cout << "B. Indonesia: ";
        cin >> s.nilai.BIn;
        cout << "B. Inggris  : ";
        cin >> s.nilai.Big;
        cin.ignore();

        s.nilaiAkhir = hitungNilaiAkhir(s.nilai);
        daftar.push_back(s);
    }
}

// === Tampilkan semua data siswa ===
void tampilDataSiswa(const vector<Siswa> &daftar) {
    if (daftar.empty()) {
        cout << "\nBelum ada data siswa!" << endl;
        return;
    }

    cout << "\n\n=== DATA SISWA & NILAI ===" << endl;
    for (size_t i = 0; i < daftar.size(); i++) {
        const Siswa &s = daftar[i];
        cout << "\n------------------------------------------------" << endl;
        cout << "SISWA KE-" << i + 1 << endl;
        cout << "Nama     : " << s.nama << endl;
        cout << "NISN     : " << s.NISN << endl;
        cout << "Jurusan  : " << s.jurusan << endl;
        cout << "Matematika : " << s.nilai.Mtk << endl;
        cout << "IPA         : " << s.nilai.IPA << endl;
        cout << "B. Indonesia: " << s.nilai.BIn << endl;
        cout << "B. Inggris  : " << s.nilai.Big << endl;

        cout << fixed << setprecision(2);
        cout << "Nilai Akhir : " << s.nilaiAkhir << endl;
    }
    cout << "------------------------------------------------" << endl;
}

// === Cari siswa berdasarkan NISN ===
void cariSiswa(const vector<Siswa> &daftar) {
    if (daftar.empty()) {
        cout << "\nBelum ada data siswa!" << endl;
        return;
    }

    string cari;
    cout << "\nMasukkan NISN yang ingin dicari: ";
    getline(cin, cari);

    bool ditemukan = false;
    for (const auto &s : daftar) {
        if (s.NISN == cari) {
            cout << "\n=== DATA DITEMUKAN ===" << endl;
            cout << "Nama     : " << s.nama << endl;
            cout << "NISN     : " << s.NISN << endl;
            cout << "Jurusan  : " << s.jurusan << endl;
            cout << "Matematika : " << s.nilai.Mtk << endl;
            cout << "IPA         : " << s.nilai.IPA << endl;
            cout << "B. Indonesia: " << s.nilai.BIn << endl;
            cout << "B. Inggris  : " << s.nilai.Big << endl;
            cout << "Nilai Akhir : " << s.nilaiAkhir << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nSiswa dengan NISN " << cari << " tidak ditemukan." << endl;
    }
}

// === Tampilkan ranking berdasarkan nilai akhir ===
void tampilRanking(vector<Siswa> daftar) {
    if (daftar.empty()) {
        cout << "\nBelum ada data siswa!" << endl;
        return;
    }

    sort(daftar.begin(), daftar.end(), [](const Siswa &a, const Siswa &b) {
        return a.nilaiAkhir > b.nilaiAkhir;
    });

    cout << "\n=== RANKING SISWA BERDASARKAN NILAI AKHIR ===" << endl;
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "NISN"
         << setw(10) << "Akhir"
         << "Rincian (MTK/IPA/IND/ING)" << endl;
    cout << "-------------------------------------------------------------" << endl;

    int no = 1;
    for (const auto &s : daftar) {
        cout << left << setw(5) << no++
             << setw(20) << s.nama
             << setw(15) << s.NISN
             << setw(10) << fixed << setprecision(2) << s.nilaiAkhir
             << "(" << s.nilai.Mtk << "/" << s.nilai.IPA << "/"
             << s.nilai.BIn << "/" << s.nilai.Big << ")" << endl;
    }
}

// === MAIN PROGRAM ===
int main() {
    vector<Siswa> daftar;
    inputData(daftar);

    int pilih;
    do {
        cout << "\n===== MENU PROGRAM DATA SISWA =====" << endl;
        cout << "1. Tampilkan Semua Data" << endl;
        cout << "2. Cari Siswa (NISN)" << endl;
        cout << "3. Tampilkan Ranking" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                tampilDataSiswa(daftar);
                break;
            case 2:
                cariSiswa(daftar);
                break;
            case 3:
                tampilRanking(daftar);
                break;
            case 0:
                cout << "\nProgram selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}
