#include <iostream>
#include <map>
#include <cstdlib>  // rand() و srand()
#include <ctime>    // time()
#include <fstream>  // برای فایل

using namespace std;

int main() {
    map<int, int> countMap;
    srand(time(0));

    ofstream outFile("output.txt");  // فایل خروجی
    if (!outFile) {
        cerr << "خطا در باز کردن فایل!" << endl;
        return 1;
    }

    outFile << "اعداد تصادفی تولید شده:" << endl;
    for (int i = 0; i < 100; i++) {
        int num = rand() % 50 + 1;  // عدد تصادفی بین 1 تا 50
        outFile << num << " ";
        countMap[num]++;
    }

    outFile << "\n\nتعداد تکرار هر عدد:" << endl;
    for (auto it : countMap) {
        outFile << "عدد " << it.first << " : " << it.second << " بار تکرار شده است." << endl;
    }

    outFile.close();
    cout << "خروجی در فایل output.txt ذخیره شد." << endl;

    return 0;
}

//g++ number.cpp -o program
//./program
