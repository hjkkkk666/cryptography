// laba1crypto.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string>
#include<vector>

using namespace std;


string encryption(string source, int key) {
	string encrypt = "";
	for (int i = 0; i < source.length(); i++) {
		if (isupper(source[i])) {
			encrypt += (source[i] + key - 65) % 26 + 65;
		}
		else if (islower(source[i])) {
			encrypt += (source[i] + key - 97) % 26 + 97;
		}
		else encrypt += source[i];
	}
	return encrypt;

}

string decryption(string encrypt, int key) {
	string decrypt = "";
	for (int i = 0; i < encrypt.length(); i++) {
		if (isupper(encrypt[i])) {
			if ((encrypt[i] - key - 65) < 0) decrypt += 91 + (encrypt[i] - key - 65);
			else decrypt += (encrypt[i] - key - 65) % 26 + 65;
		}
		else if (islower(encrypt[i])) {
			if ((encrypt[i] - key - 97) < 0) decrypt += 123 + (encrypt[i] - key - 97);
			else decrypt += (encrypt[i] - key - 97) % 26 + 97;
		}
		else decrypt += encrypt[i];
	}
	return decrypt;

}




bool is_word(string word, vector<string> dictionary) {
	for (int i = 0; i < dictionary.size(); i++) {
		if (word == dictionary[i]) {
			return true;
		}
	}
	return false;
}

int main()
{
	int key;
	string source;
	cout << "enter open text: ";
	getline(cin, source);
	cout << "enter key: ";
	cin >> key;

	string encrypt = encryption(source, key);
	cout << endl << "encryption: " << encrypt << endl;

	string decrypt = decryption(encrypt, key);
	cout << "decryption: " << decrypt << endl;

	string decrypt_a = "";
	int key_a = 0;
	for (int i = 0; i < 26; i++) {
		decrypt_a = decryption(encrypt, i);
		if (source == decrypt_a) key_a = i;
		cout << "key: " << i << "    result: " << decrypt_a << endl;
	}
	cout << "true key: " << key_a << endl;


	vector<string> dictionary = { "note", "story", "what", "group"};
	string decrypt_aa = "";
	int key_aa = 0;
	for (int j = 0; j < 26; j++) {

		string result = "";
		string word = "";
		for (int i = 0; i < encrypt.length(); i++) {
			if (isalpha(encrypt[i])) {
				if (isupper(encrypt[i])) {
					word += char(int(encrypt[i] - j - 65 + 26) % 26 + 65);
				}
				else {
					word += char(int(encrypt[i] - j - 97 + 26) % 26 + 97);
				}
			}
			else {
				if (word != "" && is_word(word, dictionary)) {
					result += word + " ";
				}
				word = "";
			}
		}
		if (word != "" && is_word(word, dictionary)) {
			result += word + " ";
		}
		cout << "key: " << j << "    result: " << result << endl;

	}
	

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
