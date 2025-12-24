#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int arr[101];
    srand(time(0));

    // مرحله 1: تولید 100 عدد تصادفی
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    // مرتب‌سازی 100 عدد اول
    sort(arr, arr + 100);

    // مرحله 2: تولید عدد 101ام
    int newNumber = rand() % 1000 + 1;

    // مرحله 3: پیدا کردن جای مناسب
    int position = 100;
    for (int i = 0; i < 100; i++) {
        if (arr[i] >= newNumber) {
            position = i;
            break;
        }
    }

    // مرحله 4: جا باز کردن
    for (int i = 99; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // مرحله 5: قرار دادن عدد جدید
    arr[position] = newNumber;

    // ===== ساخت فایل txt با نام یکتا =====
    time_t t = time(0);
    string filename =
        "C:\\Users\\parsa\\Desktop\\ali2" + to_string(t) + ".txt";

    ofstream file(filename);
    if (!file) {
        return 1;
    }

    // ===== نوشتن خروجی در فایل =====
    file << "First 100 numbers (sorted):\n";
    for (int i = 0; i < 100; i++)
        file << arr[i] << " ";

    file << "\n\nInserted number:\n" << newNumber << "\n";

    file << "\nFinal array (101 numbers):\n";
    for (int i = 0; i < 101; i++)
        file << arr[i] << " ";

    file.close();

    return 0;
}
