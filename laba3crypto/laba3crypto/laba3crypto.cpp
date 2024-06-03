// laba3crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

string rc4(const string& key, const string& source) {
    int S[256];
    int key_len = key.length();
    for (int i = 0; i < 256; i++) S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key_len]) % 256;
        swap(S[i], S[j]);
    }

    int i = 0; j = 0;
    string encryptRC4 = source;
    int source_len = source.length();
    for (int k = 0; k < source_len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        encryptRC4[k] = source[k] ^ S[t];
    }
    return encryptRC4;
}


void keyGen(const string& filename, int size) {
    ofstream file(filename);
    if (file.is_open()) {
        random_device rand;
        mt19937 randMT(rand());
        uniform_int_distribution <int> range(0, 9);

        for (int i = 0; i <= size; i++) {
            int randoms = range(randMT);
            file << randoms;
        }

        file.close();
    }
}

string encryption(string source, string key) {
    string encrypt;
    for (int i = 0; i < source.length(); i++) {
        encrypt += source[i] ^ key[i];
    }
    return encrypt;
}

string decryption(string encrypt, string key) {
    string decrypt;
    for (int i = 0; i < encrypt.length(); i++) {
        decrypt += encrypt[i] ^ key[i];
    }
    return decrypt;
}


int main()
{
    fstream file("source.txt");
    if (!file) {
        cout << "error";
    }

    fstream fileEncrypt("encrypt.txt");
    if (!fileEncrypt) {
        cout << "error";
    }

    fstream fileDencrypt("dencrypt.txt");
    if (!fileDencrypt) {
        cout << "error";
    }

    string source, key, encrypt, dencrypt;
    getline(file, source);
    int size = source.length();
    keyGen("key.txt", size);

    ifstream fileGen("key.txt");
    if (!fileGen) {
        cout << "error";
    }

    getline(fileGen, key);
    cout << "source: " << source << endl << "key: " << key << endl;

    encrypt = encryption(source, key);
    fileEncrypt << encrypt;
    cout << "encrypt: " << encrypt << endl;
    dencrypt = decryption(encrypt, key);
    fileDencrypt << dencrypt;
    cout << "dencrypt: " << dencrypt << endl;

    //rc4:
    string keyRC4;
    fstream fileRC4("resultRC4.txt");
    if (!fileRC4) {
        cout << "error";
    }

    cout << "enter key: ";
    cin >> keyRC4;
    string encryptRC4 = rc4(keyRC4, source);
    fileRC4 << encryptRC4;
    cout << "encrypt rc4: " << encryptRC4 << endl;

    cout << "enter key for decryption rc4: ";
    cin >> keyRC4;
    string dencryptRC4 = rc4(keyRC4, encryptRC4);
    fileRC4 << dencryptRC4;
    cout << "dencrypt rc4: " << dencryptRC4 << endl;

    fileGen.close();
    fileEncrypt.close();
    fileDencrypt.close();
    file.close();
    fileRC4.close();
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
