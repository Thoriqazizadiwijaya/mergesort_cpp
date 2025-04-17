#include <iostream>
using namespace std;

const int MAX = 20;
int arr[MAX];  // Array utama
int B[MAX];    // Array bantu
int n;         // Jumlah elemen array

// Prosedur input data
void input() {
    while (true) {
        cout << "Masukkan jumlah elemen array (maksimal 20): ";
        cin >> n;

        if (n <= 20) {
            break;
        } else {
            cout << "\nArray dapat mempunyai maksimal 20 elemen.\n";
        }
    }

    cout << endl;
    cout << "=======================" << endl;
    cout << "Masukkan Elemen Array" << endl;
    cout << "=======================" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }
}

// Prosedur Merge Sort
void MergeSort(int low, int high) {
    // Step 1: Basis rekursi
    if (low >= high) {
        return; // Step 1a
    }

    // Step 2: Hitung nilai tengah
    int mid = (low + high) / 2;

    // Step 3: Pecah menjadi dua bagian (rekursif)
    MergeSort(low, mid);      // Step 3a
    MergeSort(mid + 1, high); // Step 3b

    // Step 4: Inisialisasi
    int i = low;      // Step 4a
    int j = mid + 1;  // Step 4b
    int k = low;      // Step 4c

    // Step 4d: Proses penggabungan
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            B[k] = arr[i];
            i++;
        } else {
            B[k] = arr[j];
            j++;
        }
        k++;
    }

    // Step 4e: Jika masih ada sisa dari bagian kanan
    while (j <= high) {
        B[k] = arr[j];
        j++;
        k++;
    }

    // Step 4f: Jika masih ada sisa dari bagian kiri
    while (i <= mid) {
        B[k] = arr[i];
        i++;
        k++;
    }

    // Step 5: Salin kembali hasil dari B ke arr
    for (int y = low; y <= high; y++) {
        arr[y] = B[y];
    }
}

// Prosedur untuk menampilkan hasil array
void display() {
    cout << endl;
    cout << "===============================" << endl;
    cout << "Element Array yang telah tersusun" << endl;
    cout << "===============================" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fungsi utama
int main() {
    input();               // Input data
    MergeSort(0, n - 1);   // Proses Merge Sort
    display();             // Tampilkan hasil akhir
    return 0;
}
