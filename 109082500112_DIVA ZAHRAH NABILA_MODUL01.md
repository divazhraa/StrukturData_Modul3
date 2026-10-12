# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)- ... </h1>
<p align="center">[Diva Zahrah Nabila] - [109082500112]</p>

## Unguided 

# Dasar Teori
## A.	Array
###     Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama. Untuk mengakses setiap komponen / elemen array berdasarkan indeks dari setiap elemen. 

## B.	Pointer dan Alamat Memori
###     Pointer adalah variabel khusus yang berisi nilai integer dalam format heksadesimal untuk menyimpan alamat memori dari variabel lain. Karena semua data program komputer disimpan dalam sel memori yang memiliki alamat unik, pointer memungkinkan program untuk langsung menunjuk dan mengakses nilai dari variabel di alamat tersebut. Pointer juga dapat digunakan untuk mengakses elemen pada array maupun karakter pada string.

## C.	Fungsi
###     Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan membuat program lebih terstruktur, mudah dipahami, dan menghindari pengulangan kode. Fungsi umumnya memerlukan masukan yang disebut parameter, memproses masukan tersebut, dan memberikan hasil akhir berupa nilai balik (return value).

## D.	Prosedure
###     Prosedur adalah sebutan untuk fungsi yang tidak mengembalikan nilai akhir, yang dalam bahasa C++ dideklarasikan dengan tipe void. Prosedur hanya mengeksekusi instruksi atau tugas tertentu yang ada di dalam blok kodenya tanpa memberikan return value kepada pemanggilnya.

## E.   Parameter Fungsi
###     Parameter adalah nilai masukan untuk fungsi atau prosedur, yang terbagi menjadi parameter formal (variabel saat fungsi didefinisikan) dan parameter aktual (nilai saat fungsi dipanggil). Terdapat tiga metode pengiriman parameter: Call by Value (menyalin nilai, tidak mengubah variabel asli), Call by Pointer (mengirim alamat memori untuk mengubah nilai variabel asli menggunakan pointer), dan Call by Reference (mengirim alamat melalui referensi rujukan untuk mengubah nilai asli tanpa simbol pointer tambahan saat pemanggilan). 


# GUIDED 1
### Source code: 

```cpp
#include <iostream>
using namespace std;
struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata - rata = " << rata2(mhs);
    return 0;
}
void inputMhs(mahasiswa &m)
{
    cout << "input nama = ";
    cin >> m.nim;
    cout << "input nilai = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}
float rata2(mahasiswa m)
{
    return float(m.nilai1 + m.nilai2) / 2;
}
``` 

### Penjelasan: Program ini menggunakan tipe data bentukan (struct) bernama mahasiswa untuk mengelompokkan data secara rapi, yaitu NIM, nilai 1, dan nilai 2. Seluruh kode pada program ini ditulis di dalam satu file tunggal. Di dalamnya terdapat dua fungsi pendukung: prosedur inputMhs() yang bertugas meminta pengguna memasukkan data, dan fungsi rata2() untuk menghitung nilai rata-rata dari kedua nilai tersebut. Fungsi main() kemudian akan memanggil kedua fungsi itu secara berurutan agar hasilnya bisa tampil di layar.



### GUIDED 2	
### Source code: 

### mahasiswa.h
```cpp
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif
```
### mahasiswa.cpp
```cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;
void inputMhs(mahasiswa &m){
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai =";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}
float rata2(mahasiswa m)
{
    return float(m.nilai1 + m.nilai2) / 2;
}
```
### guided2.main.cpp
```cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;
int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata - rata = " << rata2(mhs);
    return 0;
}
```

### Penjelasan: Program ini adalah contoh penerapan Abstract Data Type (ADT) di mana satu program sengaja dipecah menjadi tiga file. File mahasiswa.h berfungsi sebagai kerangka dasar untuk mengenalkan nama tipe data dan fungsi. File mahasiswa.cpp berisi isi atau logika cara kerja dari fungsi-fungsi tersebut. Terakhir, file guided2.cpp adalah program utamanya yang bertugas memanggil file-file tadi agar hasilnya bisa tampil di layar.




# Unguided
### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.
```cpp
#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama, nim;
    float uts, uas, tugas, nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas){
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main(){
    Mahasiswa mhs[10]; 
    int jumlah;
    cout << "Masukkan jumlah mahasiswa (Maks 10): ";
    cin >> jumlah;
    if (jumlah > 10)
        jumlah = 10;
    for (int i = 0; i < jumlah; i++){
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> mhs[i].nama;
        cout << "NIM   : ";
        cin >> mhs[i].nim;
        cout << "UTS   : ";
        cin >> mhs[i].uts;
        cout << "UAS   : ";
        cin >> mhs[i].uas;
        cout << "Tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== HASIL REKAP NILAI MAHASISWA ===" << endl;
    for (int i = 0; i < jumlah; i++){
        cout << "Nama: " << mhs[i].nama << " | NIM: " << mhs[i].nim
             << " | Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }
    return 0;
}
```
### Output 1
![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/StrukturData_Modul3/blob/main/StrukturData_Modul3/output/SOAL1.png)

![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/StrukturData_Modul3/blob/main/StrukturData_Modul3/output/SOAL1(JAM).png)


### penjelasan unguided 1
[Program ini menggunakan tipe data array of struct untuk menyimpan data maksimal 10 mahasiswa. Rumus nilai dipisah ke dalam fungsi bernama hitungNilaiAkhir(). Fungsi ini mengambil nilai UTS, UAS, dan tugas, menghitung hasilnya, lalu menyimpan hasil hitungan tersebut langsung ke dalam data milik masing-masing mahasiswa.]


### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:

### pelajaran.h
```cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED
#include <string>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};
pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);
#endif
```

### pelajaran.cpp
```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;
pelajaran create_pelajaran(string namapel, string kodepel){
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel){
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

### soal2.main.cpp
```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :
![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/StrukturData_Modul3/blob/main/StrukturData_Modul3/output/pelajaran.h.png)

![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/StrukturData_Modul3/blob/main/StrukturData_Modul3/output/pelajaran.cpp.png)

![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/StrukturData_Modul3/blob/main/StrukturData_Modul3/output/SOAL2.png)



### penjelasan unguided 2
[Program ini adalah contoh penerapan Abstract Data Type (ADT) di mana satu program dipecah menjadi tiga file. File pelajaran.h berfungsi sebagai kerangka dasar untuk mengenalkan nama tipe data dan fungsi. File pelajaran.cpp berisi isi atau logika cara kerja dari fungsi-fungsi tersebut. Terakhir, file soal2.main.cpp adalah program utamanya yang bertugas memanggil file-file tadi agar hasilnya bisa tampil di layar.]

### 3. Buatlah program dengan ketentuan :
#### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
#### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
#### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
#### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
### source code unguided 3
```cpp

#
```
### Output Unguided 3 :
![Screenshot Output Unguided 1_!] (https://github.com/divazhraa/STRUKTUR_DATA/blob/main/MODUL02/OUTPUT/soal3.png)


### penjelasan unguided 3
[Program ini menunjukkan cara menukar data menggunakan array dua dimensi dan pointer. Fungsi tukarIsiArray() dibuat untuk menukar isi dari dua buah array (berukuran 3x3) pada posisi baris dan kolom tertentu. Sedangkan fungsi tukarPointer() berguna untuk menukar nilai dari dua variabel secara langsung dengan cara mengakses alamat memorinya menggunakan bantuan tanda bintang (*).]


# Kesimpulan
[]


### Referensi
#### Modul pembelajaran


