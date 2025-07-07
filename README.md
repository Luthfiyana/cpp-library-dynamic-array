# Sistem Manajemen Perpustakaan Sederhana dengan Array Dinamis (C++)

---

## Deskripsi Proyek

Proyek ini adalah implementasi sistem manajemen buku sederhana menggunakan bahasa pemrograman C++. Aplikasi ini mengelola data buku menggunakan **array dinamis** yang dikelola secara manual. Ini berfungsi sebagai contoh dasar untuk memahami konsep alokasi memori dinamis, manipulasi pointer, dan penanganan array dinamis di C++. Aplikasi ini memungkinkan pengguna untuk melakukan operasi dasar seperti menambah, mengubah, menghapus, menampilkan, dan mencari data buku melalui antarmuka konsol.

## Fitur

- **Tambah Buku**: Menambahkan detail buku baru (kode, judul, penulis, penerbit, stok). Implementasi ini secara dinamis memperluas array saat buku baru ditambahkan, memastikan memori dialokasikan sesuai kebutuhan. Dilengkapi dengan validasi kode unik.
- **Ubah Buku**: Memperbarui informasi buku yang sudah ada dalam array dinamis.
- **Hapus Buku**: Menghapus buku dari array, diikuti dengan penyesuaian elemen array yang tersisa.
- **Tampilkan Daftar Buku**: Menampilkan semua buku yang tersimpan secara terbalik (dari yang terakhir ditambahkan) menggunakan fungsi rekursif.
- **Cari Buku**: Mencari buku berdasarkan judul dalam array.

## Konsep Utama yang Digunakan

- **Array Dinamis**: Implementasi inti dari penyimpanan data buku adalah melalui array yang ukurannya dapat berubah saat runtime menggunakan `new[]` dan `delete[]`.
- **Manajemen Memori Manual**: Proyek ini secara eksplisit mengelola alokasi dan dealokasi memori untuk array buku, menyoroti pentingnya `new` dan `delete` untuk mencegah _memory leak_.
- **Pointer**: Penggunaan pointer (`buku*`) sangat krusial dalam mengelola array dinamis dan mengarahkan ke lokasi memori yang benar.
- **Fungsi Rekursif**: Fungsi untuk menampilkan buku dari belakang ke depan diimplementasikan secara rekursif.

## Cara Menggunakan

### Prasyarat

Pastikan Anda memiliki compiler C++ (misalnya GCC, Clang, MinGW) terinstal di sistem Anda.

### Interaksi Aplikasi

Setelah menjalankan aplikasi, Anda akan melihat menu utama. Pilih angka yang sesuai dengan operasi yang ingin Anda lakukan dan ikuti petunjuk yang diberikan.

## Struktur Kode

- `struct buku`: Mendefinisikan struktur data untuk menyimpan informasi setiap buku.
- `tambahBuku(buku*& daftarBuku, int& jumlahBuku)`: Fungsi untuk menambahkan buku baru, mengelola realokasi array dinamis.
- `ubahBuku(buku* daftarBuku, int jumlahBuku, int i)`: Fungsi untuk mengubah detail buku yang sudah ada dalam array.
- `hapusBuku(buku*& daftarBuku, int& jumlahBuku, int i)`: Fungsi untuk menghapus buku dan menggeser elemen dalam array dinamis.
- `tampilkanBukuTerbalik(buku* daftarBuku, int jumlahBuku, int i)`: Fungsi rekursif untuk menampilkan daftar buku dari yang terakhir ditambahkan.
- `cariBuku(buku* daftarBuku, int jumlahBuku, string cari)`: Fungsi untuk mencari buku berdasarkan judul.
- `main()`: Fungsi utama yang mengelola menu interaktif, memanggil fungsi-fungsi lain, dan bertanggung jawab atas pelepasan memori array dinamis saat program berakhir.

## Extra

Made with love n (much) tears ❤️
