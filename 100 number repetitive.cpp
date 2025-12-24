#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int N = 100;
    int arr[N];
    int count[101] = {0};

    srand(time(0));

    // تولید ۱۰۰ عدد تصادفی بین ۱ تا ۱۰۰
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
        count[arr[i]]++;
    }

    ofstream file("output.txt");

    if (!file) {
        cout << "خطا در ساخت فایل!";
        return 1;
    }

    file << "اعداد تکراری:\n";

    for (int i = 1; i <= 100; i++) {
        if (count[i] > 1) {
            file << i << endl; // فقط خود عدد
        }
    }

    file.close();
    return 0;
}



//g++ main.cpp -o program
//./program