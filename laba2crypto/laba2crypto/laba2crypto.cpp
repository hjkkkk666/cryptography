// laba2crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <string>
#include <random>

using namespace std;

void gen(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        random_device rand;
        mt19937 randMT(rand());
        uniform_int_distribution <int> range(0, 1);

        for (int i = 0; i <= 10; i++) {
            int randoms = range(randMT);
            file << randoms;
        }

        file.close();
    }
}

int main()
{
    ifstream file("source.txt");
    if (!file) {
        cout << "error";
    }

    map<char, double> freq;
    char sym;
    int k = 0;
    double exp, entropy = 0;
    while (file >> sym) {
        freq[sym]++;
        k++;
    }
    
    cout << "freq: " << endl;
    for (const auto& c : freq) {
        exp = static_cast<double>(c.second) / k;
        entropy -= exp * log2(exp);
        cout << c.first << ": " << c.second / k << endl;
    }

    cout << "entropy: " << entropy << endl;

    gen("gen.txt");

    ifstream filegen("gen.txt");
    if (!filegen) {
        cout << "error";
    }

    map<char, double> freqR;
    char symR;
    int kR = 0;
    double expR, entropyR = 0;
    while (filegen >> symR) {
        freqR[symR]++;
        kR++;
    }

    cout << endl << "freq generate text: " << endl;
    for (const auto& cg : freqR) {
        expR = static_cast<double>(cg.second) / kR;
        entropyR -= expR * log2(expR);
        cout << cg.first << ": " << cg.second / kR << endl;
    }

    cout << "entropy generate text: " << entropyR << endl;





    file.close();
    filegen.close();

}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
