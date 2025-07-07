#include <iostream>
#include <string>

using namespace std;

struct buku
{
    string kode, judul, penulis, penerbit;
    int stok; // jumlah stok buku
};

// Fungsi untuk menambahkan buku
void tambahBuku(buku *&daftarBuku, int &jumlahBuku)
{
    // Alokasikan memori untuk satu elemen baru
    buku *temp = new buku[jumlahBuku + 1];

    // Salin elemen dari array lama ke array baru
    for (int i = 0; i < jumlahBuku; i++)
    {
        temp[i] = daftarBuku[i];
    }

    // Input buku baru
    buku bukuBaru;
    cout << "Masukkan detail buku " << jumlahBuku + 1 << ":\n";
    cout << "Kode unik: ";
    cin >> bukuBaru.kode;

    // Cek apakah kode buku sudah ada
    for (int i = 0; i < jumlahBuku; i++)
    {
        if (temp[i].kode == bukuBaru.kode)
        {
            cout << "Error: Kode buku sudah ada." << endl;
            delete[] temp; // Hapus alokasi baru untuk mencegah memory leak
            return;        // Kembali tanpa menambah buku baru
        }
    }

    // Input detail buku lainnya
    cout << "Judul: ";
    cin.ignore();
    getline(cin, bukuBaru.judul);
    bukuBaru.judul = bukuBaru.judul; // Normalisasi judul

    cout << "Penulis: ";
    getline(cin, bukuBaru.penulis);
    // bukuBaru.penulis = toTitleCase(bukuBaru.penulis); // Normalisasi nama penulis

    cout << "Penerbit: ";
    getline(cin, bukuBaru.penerbit);
    cout << "Jumlah stok: ";
    cin >> bukuBaru.stok;

    // Tambahkan buku baru ke array baru
    temp[jumlahBuku] = bukuBaru;
    jumlahBuku++; // Tambah jumlah buku

    // Hapus array lama untuk menghindari memory leak
    delete[] daftarBuku;

    // Array baru menjadi array yang digunakan
    daftarBuku = temp;
}

// Fungsi untuk mengubah data buku
void ubahBuku(buku *daftarBuku, int jumlahBuku, int i)
{
    cout << "Perbarui detail buku " << i + 1 << ":\n";
    cout << "Kode sebelumnya: " << daftarBuku[i].kode << endl;

    string kodeBaru;
    cout << "Kode baru: ";
    cin >> kodeBaru;

    // Cek apakah kode baru unik (tidak sama dengan kode sebelumnya)
    for (int j = 0; j < jumlahBuku; j++)
    {
        if (daftarBuku[j].kode == kodeBaru && j != i)
        {
            cout << "Error: Kode buku sudah ada." << endl;
            return; // Kembali tanpa mengubah buku
        }
    }

    // Jika kode baru valid, update
    daftarBuku[i].kode = kodeBaru; // update kode

    cout << "Judul sebelumnya: " << daftarBuku[i].judul << endl;
    cout << "Judul baru: ";
    cin.ignore();
    getline(cin, daftarBuku[i].judul);
    cout << "Penulis sebelumnya: " << daftarBuku[i].penulis << endl;
    cout << "Penulis baru: ";
    getline(cin, daftarBuku[i].penulis);
    cout << "Penerbit sebelumnya: " << daftarBuku[i].penerbit << endl;
    cout << "Penerbit baru: ";
    getline(cin, daftarBuku[i].penerbit);
    cout << "Jumlah stok sebelumnya: " << daftarBuku[i].stok << endl;
    cout << "Jumlah stok baru: ";
    cin >> daftarBuku[i].stok;
}

// Hapus data buku
void hapusBuku(buku *&daftarBuku, int &jumlahBuku, int i)
{
    for (int j = i; j < jumlahBuku - 1; j++)
    {
        daftarBuku[j] = daftarBuku[j + 1]; // geser buku ke kiri
    }
    jumlahBuku--; // decrement jumlah buku
}

// Tampilkan data buku dari akhir dulu
void tampilkanBukuTerbalik(buku *daftarBuku, int jumlahBuku, int i)
{
    if (i < 0)
    { // jika sudah mencapai buku pertama, kembali
        return;
    }
    cout << "Buku " << i + 1 << ":\n";
    cout << "   Kode: " << daftarBuku[i].kode << endl;
    cout << "   Judul: " << daftarBuku[i].judul << endl;
    cout << "   Penulis: " << daftarBuku[i].penulis << endl;
    cout << "   Penerbit: " << daftarBuku[i].penerbit << endl;
    cout << "   Jumlah stok: " << daftarBuku[i].stok << endl;

    // Panggil fungsi rekursif untuk buku sebelumnya
    tampilkanBukuTerbalik(daftarBuku, jumlahBuku, i - 1);
}

/*// Tampilkan data buku
void tampilkanBuku(buku* daftarBuku, int jumlahBuku, int i = 0) {
    if (i >= jumlahBuku) {  // sampai buku terakhir maka dikembalikan return
        return;
    }
    cout << "Buku " << i + 1 << ":\n";
    cout << "   Kode: " << daftarBuku[i].kode << endl;
    cout << "   Judul: " << daftarBuku[i].judul << endl;
    cout << "   Penulis: " << daftarBuku[i].penulis << endl;
    cout << "   Penerbit: " << daftarBuku[i].penerbit << endl;
    cout << "   Jumlah stok: " << daftarBuku[i].stok << endl;

    // Panggil fungsi rekursif untuk buku selanjutnya
    tampilkanBuku(daftarBuku, jumlahBuku, i + 1);
}*/

// fungsi cariBuku
void cariBuku(buku *daftarBuku, int jumlahBuku, string cari)
{
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++)
    {
        if (daftarBuku[i].judul.find(cari) != string::npos)
        {
            cout << "Buku " << i + 1 << ":\n";
            cout << "   Kode: " << daftarBuku[i].kode << endl;
            cout << "   Judul: " << daftarBuku[i].judul << endl;
            cout << "   Penulis: " << daftarBuku[i].penulis << endl;
            cout << "   Penerbit: " << daftarBuku[i].penerbit << endl;
            cout << "   Jumlah stok: " << daftarBuku[i].stok << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan)
    {
        cout << "Buku tidak ditemukan.\n";
    }
}

int main()
{
    int jumlahBuku = 0;         // Jumlah buku yang tersimpan
    buku *daftarBuku = nullptr; // Mulai dengan array kosong

    int pilihan, i;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Buku\n";
        cout << "2. Ubah Data Buku\n";
        cout << "3. Hapus Data Buku\n";
        cout << "4. Tampilkan Daftar Buku\n";
        cout << "5. Cari Buku\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1: // Tambah data buku
            tambahBuku(daftarBuku, jumlahBuku);
            break;

        case 2: // Ubah data buku
            if (jumlahBuku == 0)
            {
                cout << "Tidak ada buku yang tersedia untuk diubah.\n";
            }
            else
            {
                cout << "Masukkan nomor buku yang ingin diubah (1 sampai " << jumlahBuku << "): ";
                cin >> i;
                if (i > 0 && i <= jumlahBuku)
                {
                    ubahBuku(daftarBuku, jumlahBuku, i - 1);
                }
                else
                {
                    cout << "Nomor buku tidak valid.\n";
                }
            }
            break;

        case 3: // Hapus data buku
            if (jumlahBuku == 0)
            {
                cout << "Tidak ada buku yang tersedia untuk dihapus.\n";
            }
            else
            {
                cout << "Masukkan nomor buku yang ingin dihapus (1 sampai " << jumlahBuku << "): ";
                cin >> i;
                if (i > 0 && i <= jumlahBuku)
                {
                    hapusBuku(daftarBuku, jumlahBuku, i - 1);
                    cout << "Buku berhasil dihapus.\n";
                }
                else
                {
                    cout << "Nomor buku tidak valid.\n";
                }
            }
            break;

        case 4: // Tampilkan Daftar Buku Terbalik
            if (jumlahBuku == 0)
            {
                cout << "Tidak ada buku yang tersedia dalam daftar.\n";
            }
            else
            {
                tampilkanBukuTerbalik(daftarBuku, jumlahBuku, jumlahBuku - 1);
            }
            break;

        case 5: // Cari buku
            if (jumlahBuku == 0)
            {
                cout << "Tidak ada buku yang tersedia dalam daftar.\n";
            }
            else
            {
                string cari;
                cout << "Masukkan judul buku yang ingin dicari: ";
                cin.ignore();
                getline(cin, cari);
                cariBuku(daftarBuku, jumlahBuku, cari);
            }
            break;

        case 6: // Keluar
            cout << "Keluar...\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);

    // Hapus alokasi memori saat keluar
    delete[] daftarBuku;
    return 0;
}