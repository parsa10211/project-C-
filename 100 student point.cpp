#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    int freq[21] = {0};  // نمرات 0 تا 20
    int score;

    // باز کردن فایل ورودی input.txt
    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "فایل input.txt پیدا نشد!" << endl;
        return 1;
    }

    while (inFile >> score) {
        if (score >= 0 && score <= 20)
            freq[score]++;
    }
    inFile.close();

    // پیدا کردن نمره با بیشترین تکرار
    int maxFreq = freq[0];
    int mostRepeated = 0;

    for (int i = 1; i <= 20; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostRepeated = i;
        }
    }

    // نوشتن خروجی در فایل result.txt
    ofstream outFile("result.txt");
    outFile << "بیشترین نمره تکراری: " << mostRepeated << endl;
    outFile << "تعداد تکرار: " << maxFreq << endl;
    outFile.close();

    cout << "نتیجه در فایل result.txt ذخیره شد." << endl;
    return 0;
}

//g++ university.cpp -o university university
