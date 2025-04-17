#include <iostream>
using namespace std;

// create main array & temporary array
int arr[20], b[20];
// set array input size
int n;

void input()
{
    while (true)
    {
        cout << "Masukkan Panjang elemen array : ";
        cin >> n;

        if (n <= 20)
        {
            break;
        }
        else
        {
            cout << "\nMaksimal panjang array adalah 20\n";
        }
    }

    // inputkan isi element array
    cout << "\n-----------------------\n";
    cout << "Masukkan isi element array\n";
    cout << "-------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Array indeks ke- " << i << " : ";
        cin >> arr[i];
    }
}

// create function mergeSort
void mergeSort(int low, int high)
{
    if (low > high) // step 1.a
        return;     // step 1.b

    int mid = (low + high) / 2; // step 2

    // step 3 - bagian rekursif, mengunjungi setiap semakitan
    mergeSort(low, mid);       // step 3.a
    mergeSort(mid + 1, high);  // step 3.b

    // step 4
    int k = low, i = low, j = mid + 1; // step 4.a

    while (i <= mid && j <= high) // step 4.a.a
    {
        if (arr[i] <= arr[j]) // step 4.a.a.i
        {
            b[k] = arr[i]; // step 4.a.a.ii
            i++;           // step 4.a.a.iii
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++; // step 4.a.a.iii
    }

    while (i <= mid) // step 4.e
    {
        b[k] = arr[i]; // step 4.e.i
        i++;           // step 4.e.ii
        k++;           // step 4.e.iii
    }

    while (j <= high) // step 4.f
    {
        b[k] = arr[j]; // step 4.f.i
        j++;           // step 4.f.ii
        k++;           // step 4.f.iii
    }

    // step 5
    for (int x = low; x <= high; x++)
    {
        arr[x] = b[x];
    }
}

void output()
{
    cout << "\nData setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    input();
    mergeSort(0, n - 1);
    output();
}
