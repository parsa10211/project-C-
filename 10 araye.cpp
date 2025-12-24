#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int arr1[10];
    int arr2[10];

    srand(time(0));

    // تولید اعداد تصادفی
    for (int i = 0; i < 10; i++) {
        arr1[i] = rand() % 100 + 1;
        arr2[i] = rand() % 100 + 1;
    }

    // مرتب‌سازی چون الگوریتم merge نیاز دارد
    sort(arr1, arr1 + 10);
    sort(arr2, arr2 + 10);

    int merged[20];
    int i = 0, j = 0, k = 0;

    while (i < 10 && j < 10) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    while (i < 10)
        merged[k++] = arr1[i++];

    while (j < 10)
        merged[k++] = arr2[j++];

    // ساخت فایل با نام یکتا
    time_t t = time(0);
    string filename =
        "C:\\Users\\parsa\\Desktop\\ali1\\output_" + to_string(t) + ".txt";

    ofstream file(filename);
    if (!file) {
        return 1;
    }

    file << "Array 1:\n";
    for (int x = 0; x < 10; x++)
        file << arr1[x] << " ";

    file << "\n\nArray 2:\n";
    for (int x = 0; x < 10; x++)
        file << arr2[x] << " ";

    file << "\n\nMerged Array:\n";
    for (int x = 0; x < 20; x++)
        file << merged[x] << " ";

    file.close();

    return 0;
}
