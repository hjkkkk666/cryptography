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


/*bool findDictionary(const string& encrypt) {
	for (int i = 0; i < 26; ++i) {
		string decrypt = decryption(encrypt, i);
		istringstream iss(decrypt);
		string word;
		bool found = true;
		while (iss >> word && !dictionary.count(word)) {
			found = false;
			break;
		}
		if (found) {
			cout << "found key: " << i << "text: " << decrypt << endl;
			return true;
		}
	}
	return false;
}*/

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



	/*
	string decrypt_aa = "";
	int key_aa = 0;
	char lib[2] = { 'as', 'is'};
	for (int j = 0; j < 26; j++) {
		
		for (int i = 0; i < encrypt.length(); i++) {
			if (isupper(encrypt[i])) {
				if ((encrypt[i] - j - 65) < 0) decrypt_aa += 91 + (encrypt[i] - j - 65);
				else decrypt_aa += (encrypt[i] - j - 65) % 26 + 65;
			}
			else if (islower(encrypt[i])) {
				if ((encrypt[i] - j - 97) < 0) decrypt_aa += 123 + (encrypt[i] - j - 97);
				else decrypt_aa += (encrypt[i] - j - 97) % 26 + 97;
			}
			else decrypt_aa += encrypt[i];
		}
		for (int l = 1; l < decrypt_aa.length(); l++) {
			if (decrypt_aa[l - 1] == lib[0] && decrypt_aa[l] == lib[1]) cout << "key: " << j << "result: " << decrypt_aa << endl;
		}}*/
	
	

	/*for (int i = 1; i < 5; i++) {
		switch (i)
		{

		case 1:
		{
			string en = encryption(source, key);
			cout << en;
			
		}
		case 2:
		{
			string de = decryption(en, key);
			cout << de;
		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 0: {

		}
		}
	}
	*/
	

}

/*#include <iostream>

using namespace std;

string CaesarEncode(string text, int shift) {
	string encode = "";
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') encode += text[i];
		if (text[i] >= 'a' && text[i] <= 'z') {
			encode += int(text[i] + shift - int('a')) % 26 + int('a');
		}
		else if (text[i] >= 'A' && text[i] <= 'Z') {
			encode += int(text[i] + shift - int('A')) % 26 + int('A');
		}
	}
	return encode;
}

string CaesarDecode(string text, int shift) {
	string decode = "";
	int a;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') decode += text[i];
		if (text[i] >= 'a' && text[i] <= 'z') {
			a = int(text[i] - shift - int('a')) % 26;
			decode += int(26 + text[i] - shift - int('a')) % 26 + int('a');
		}
		else if (text[i] >= 'A' && text[i] <= 'Z') {
			decode += int(26 + text[i] - shift - int('A')) % 26 + int('A');
		}
	}
	return decode;
}

void CaesarEncodeText(string encoded, string original) {
	string decode = "";
	int key;
	for (int i = 1; i <= 26; i++) {
		decode = CaesarDecode(encoded, i);
		if (original == decode) {
			cout << "key is " << i << endl;
			return;
		}
	}
	cout << "Key not found!" << endl;
}

void CaesarRandomEncode(string encoded) {
	string decoded = "";
	for (int i = 1; i <= 25; i++) {
		decoded = CaesarDecode(encoded, i);
		cout << "Text with shift = " << i << " is: " << decoded << endl;
	}
}

int main() {
	string text = "My new text";
	unsigned short shift;
	cout << "Enter shift: ";
	cin >> shift;
	string encode = CaesarEncode(text, shift);
	cout << "Text: " << text << " Shift = " << shift << " Encoded text: " << encode << endl;
	CaesarRandomEncode(encode);
	CaesarEncodeText(encode, text);
	return 0;

}
*/
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
