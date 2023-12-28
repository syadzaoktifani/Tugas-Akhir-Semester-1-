#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct OrangTuaLanjutUsia {
    string nama;
    int usia;
    float tekananDarah;
    float kadarGulaDarah;
    char merokok;
    float beratBadan;
    float tinggiBadan;
};

void tampilkanPesanSelamatDatang() {
    cout << "==================================================================="  <<endl;
    cout << "|         Selamat Datang di Program Bantuan Orang Tua Lanjut Usia  |"<<endl;
    cout << "|                                                                  |  "<<endl;
    cout << "===================================================================" << endl;
}

void tampilkanMenu() {
    cout << "=== Program Bantuan Orang Tua Lanjut Usia ===" << endl;
    cout << "1. Tambahkan Informasi Orang Tua" << endl;
    cout << "2. Tampilkan Informasi Orang Tua" << endl;
    cout << "3. Hitung BMI dan Rekomendasi Kesehatan" << endl;
    cout << "4. Statistik BMI Keseluruhan" << endl;
    cout << "5. Keluar" << endl;
    cout << "=============================================" << endl;
}

void tambahkanInformasi(OrangTuaLanjutUsia orangTua[], int& jumlahOrangTua) {
    if (jumlahOrangTua < 5) {
        cout << "Masukkan Nama: ";
        cin >> orangTua[jumlahOrangTua].nama;

        cout << "Masukkan Usia: ";
        cin >> orangTua[jumlahOrangTua].usia;

        cout << "Masukkan Tekanan Darah: ";
        cin >> orangTua[jumlahOrangTua].tekananDarah;

        cout << "Masukkan Kadar Gula Darah: ";
        cin >> orangTua[jumlahOrangTua].kadarGulaDarah;

        cout << "Merokok? (Y/T): ";
        cin >> orangTua[jumlahOrangTua].merokok;

        cout << "Masukkan Berat Badan (kg): ";
        cin >> orangTua[jumlahOrangTua].beratBadan;

        cout << "Masukkan Tinggi Badan (cm): ";
        cin >> orangTua[jumlahOrangTua].tinggiBadan;

        jumlahOrangTua++;
        cout << "Informasi Orang Tua berhasil ditambahkan." << endl;
    } else {
        cout << "Maaf, sudah mencapai batas maksimal orang tua yang dapat dimasukkan." << endl;
    }
}

void tampilkanInformasi(const OrangTuaLanjutUsia orangTua[], int jumlahOrangTua) {
    if (jumlahOrangTua > 0) {
        cout << "=== Informasi Orang Tua ===" << endl;
        for (int i = 0; i < jumlahOrangTua; ++i) {
            cout << "Nama: " << orangTua[i].nama << endl;
            cout << "Usia: " << orangTua[i].usia << " tahun" << endl;
            cout << "Tekanan Darah: " << orangTua[i].tekananDarah << " mmHg" << endl;
            cout << "Kadar Gula Darah: " << orangTua[i].kadarGulaDarah << " mg/dL" << endl;
            cout << "Merokok: " << ((orangTua[i].merokok == 'Y' || orangTua[i].merokok == 'y') ? "Ya" : "Tidak") << endl;
            cout << "Berat Badan: " << orangTua[i].beratBadan << " kg" << endl;
            cout << "Tinggi Badan: " << orangTua[i].tinggiBadan << " cm" << endl;
            cout << "==========================" << endl;
        }
    } else {
        cout << "Belum ada informasi Orang Tua yang dimasukkan." << endl;
    }
}

void hitungBMIRekomendasi(const OrangTuaLanjutUsia& orangTua) {
    float tinggiMeter = orangTua.tinggiBadan / 100.0;
    float BMI = orangTua.beratBadan / (tinggiMeter * tinggiMeter);

    cout << "BMI: " << fixed << setprecision(2) << BMI << endl;

    // Menampilkan rekomendasi kesehatan berdasarkan BMI
    if (BMI < 18.5) {
        cout << "Kategori BMI: Kurus" << endl;
        cout << "Rekomendasi: Konsultasikan dengan dokter atau ahli gizi untuk penanganan lebih lanjut." << endl;
    } else if (BMI >= 18.5 && BMI < 25) {
        cout << "Kategori BMI: Normal" << endl;
        cout << "Rekomendasi: Pertahankan pola makan sehat dan aktifitas fisik yang teratur." << endl;
    } else if (BMI >= 25 && BMI < 30) {
        cout << "Kategori BMI: Gemuk (Overweight)" << endl;
        cout << "Rekomendasi: Pertahankan pola makan sehat, tingkatkan aktifitas fisik, konsultasikan dengan dokter jika perlu." << endl;
    } else {
        cout << "Kategori BMI: Obesitas" << endl;
        cout << "Rekomendasi: Konsultasikan dengan dokter atau ahli gizi untuk penanganan lebih lanjut." << endl;
    }
}

void tampilkanStatistikBMI(const OrangTuaLanjutUsia orangTua[], int jumlahOrangTua) {
    if (jumlahOrangTua > 0) {
        float totalBMI = 0;
        for (int i = 0; i < jumlahOrangTua; ++i) {
            float tinggiMeter = orangTua[i].tinggiBadan / 100.0;
            totalBMI += orangTua[i].beratBadan / (tinggiMeter * tinggiMeter);
        }

        float rataRataBMI = totalBMI / jumlahOrangTua;

        cout << "=== Statistik BMI Keseluruhan ===" << endl;
        cout << "Jumlah Orang Tua: " << jumlahOrangTua << endl;
        cout << "Rata-rata BMI: " << fixed << setprecision(2) << rataRataBMI << endl;
        cout << "================================" << endl;
    } else {
        cout << "Belum ada informasi Orang Tua yang dimasukkan untuk menampilkan statistik BMI." << endl;
    }
}

int main() {
    tampilkanPesanSelamatDatang();

    OrangTuaLanjutUsia orangTua[5];
    int jumlahOrangTua = 0;
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Pilih opsi (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahkanInformasi(orangTua, jumlahOrangTua);
                break;
            case 2:
                tampilkanInformasi(orangTua, jumlahOrangTua);
                break;
            case 3:
                int nomorOrangTua;
                cout << "Masukkan nomor Orang Tua untuk perhitungan BMI: ";
                cin >> nomorOrangTua;
                if (nomorOrangTua >= 1 && nomorOrangTua <= jumlahOrangTua) {
                    hitungBMIRekomendasi(orangTua[nomorOrangTua - 1]);
                } else {
                    cout << "Nomor Orang Tua tidak valid." << endl;
                }
                break;
            case 4:
                tampilkanStatistikBMI(orangTua, jumlahOrangTua);
                break;
            case 5:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih opsi yang benar." << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}
