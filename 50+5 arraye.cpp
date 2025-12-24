#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    int a[50], b[5];
    srand(time(0));

    // تولید آرایه ۵۰تایی تصادفی بین 1 تا 100
    for (int i = 0; i < 50; i++) {
        a[i] = rand() % 100 + 1;
    }

    // انتخاب یک موقعیت تصادفی برای زیرآرایه
    int pos = rand() % 46; // چون 50 - 5 = 45

    // آرایه ۵تایی را از آرایه ۵۰تایی می‌سازیم (زیرآرایه)
    for (int i = 0; i < 5; i++) {
        b[i] = a[pos + i];
    }

    // شماره فایل خروجی بر اساس زمان
    time_t t = time(0);
    string filename = "output_" + to_string(t) + ".txt";

    ofstream file(filename);
    if (!file) {
        cout << "خطا در ساخت فایل";
        return 1;
    }

    // نوشتن آرایه ۵۰تایی در فایل
    file << "Array 50:\n";
    for (int i = 0; i < 50; i++) {
        file << a[i] << " ";
    }
    file << "\n\n";

    // نوشتن آرایه ۵تایی در فایل
    file << "Array 5:\n";
    for (int i = 0; i < 5; i++) {
        file << b[i] << " ";
    }
    file << "\n\n";

    // چون حتماً زیرآرایه است، خروجی همیشه YES
    file << "Result: YES";

    file.close();
    cout << "Output saved in file: " << filename << endl;

    return 0;
}

//g++ pack.cpp -o program
//./program