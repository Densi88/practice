#include <string>
#include <fstream>
#include <iostream>

using  namespace std;
string fileData;
string filename;
string numbers;
string inputFilename;
string s;
string output;
string reading;
bool renamed = false;
bool renamedData = false;
bool findNumbers = false;
int registr[10];
void Read() {
	
	if (!renamedData) {
		ifstream fin("Input.txt");
		if (fin.is_open()) {
			while (getline(fin, reading)) {
				cout << reading << endl;
			}
		}
		else {
			cout << "File not open!" << endl;
		}
	}

	else {
		ifstream fin(inputFilename + ".txt");
		if (fin.is_open()) {
			while (getline(fin, s)) {
				cout << s << endl;
			}
		}
		else {
			cout << "File not open!" << endl;
		}
	}
}
void create() {
	ofstream fout;
	getline(cin, fileData);
	fout.open("Input.txt");
	if (fout.is_open()) {
		fout << fileData;
		fout.close();
	}
	else {
		cout << "File not found!" << endl;
	}
}
void GetNumbers() {

	string reading;

	ifstream fin("Input.txt");
	if (fin.is_open()) {
		getline(fin, reading);
	}
	else {
		cout << "File not open!" << endl;
	}


	int pos = 0;
	while (pos <= reading.size()) {
		if ((reading[pos] >= '0' && reading[pos] <= '9') && (reading[pos + 1] >= '0' && reading[pos + 1] <= '9')
			&& (reading[pos + 2] == '-') && (reading[pos + 3] >= '0' && reading[pos + 3] <= '9') && (reading[pos + 4] >= '0' && reading[pos + 4] <= '9') && (reading[pos + 5] == '-')
			&& (reading[pos + 6] >= '0' && reading[pos + 6] <= '9') && (reading[pos + 7] >= '0' && reading[pos + 7] <= '9')) {

			numbers += reading.substr(pos, 8) + "\n";
			cout << "Number find from " << pos<<" " << "to " << pos + 8 << endl;
			pos += 8;
			
			findNumbers = true;
		}
		else if ((reading[pos] >= '0' && reading[pos] <= '9') && (reading[pos + 1] >= '0' && reading[pos + 1] <= '9') &&
			(reading[pos + 2] >= '0' && reading[pos + 2] <= '9') && (reading[pos + 3] == '-') &&
			(reading[pos + 4] >= '0' && reading[pos + 4] <= '9') && (reading[pos + 5] >= '0' && reading[pos + 5] <= '9') &&
			(reading[pos + 6] >= '0' && reading[pos + 6] <= '9')) {

			numbers += reading.substr(pos, 7) + "\n";
			cout << "Numbers find from " << pos<<" " << "to " << pos + 7 << endl;
			pos += 7;
			findNumbers = true;
		}
		pos = pos + 1;

	}
	if (!findNumbers) {
		cout << "Numbers not found!" << endl;
	}
	else {
		cout << "Your numbers:" << endl;
	}



	ofstream fout;
	fout.open("Output.txt");
	if (fout.is_open()) {
		fout << numbers;
		fout.close();
	}
	else {
		cout << "File not created!" << endl;
	}





	ifstream in("Output.txt");
	if (in.is_open()) {
		while (getline(in, output)) {
			cout << output << endl;
		}
	}
	else {
		cout << "File not open!" << endl;
	}
}
void SaveNumbersAs() {

	cout << "Enter new name of file: ";
	cin >> filename;
	ofstream fout;
	fout.open(filename + ".txt");
	if (fout.is_open()) {
		fout << numbers;
		fout.close();
		cout << "File resaved" << endl;
	}
	else {
		cout << "File not open!" << endl;
	}
}
void saveInputAs() {
	cout << "Enter new name of file: ";
	cin >> inputFilename;
	ofstream fout;
	fout.open(inputFilename + ".txt");
	if (fout.is_open()) {
		fout << fileData;
		fout.close();
	}
	else {
		cout << "File not open!" << endl;
	}
	renamedData = true;
}
void TimeList() {
	string reading;

	ifstream fin("Time.txt");
	if (fin.is_open()) {
		getline(fin, reading);
	}
	else {
		cout << "File not open!" << endl;
	}
	int pos = 0;
}
int getValidatedChoose() {
	string input;
	while (true) {
		cout << "Input choose: ";
		getline(cin, input);
		bool isValid = true;
		for (char c : input) {
			if (!isdigit(c)) {
				isValid = false;
				break;
			}
		}
		if (isValid && !input.empty()) {
			return stoi(input);
		}
		else {
			cout << "Invalid input. Please enter a valid choose" << endl;
		}
	}
}
void registrChecking() {
	bool reg = false;
	ifstream fin("Input.txt");
	if (fin.is_open()) {
		getline(fin, reading);
	}
	else {
		cout << "File not open!" << endl;
	}
	int i = 0;
	int pos = 0;
	while (pos <= reading.size()||i<10) {
		if ((reading[pos]=='.')||reading[pos]=='!'||reading[pos]=='?') {
			toupper(reading[pos+2]);
			registr[i] = pos;
			reg = true;
		}
		pos = pos + 1;
		i = i + 1;
	}
	if (reg) {
		cout << "Registr changed at positions: ";
		for (i = 0; i < 10; i++) {
			cout << registr[i] << ", ";
		}
	}
	else {
		cout << "Text input correctly" << endl;
	}
}
int main()
{

	int y;
	do {
		cout << "Create a file(1)" << endl;
		cout << "Read  file(2)" << endl;
		cout << "Get numbers list(3)" << endl;
		cout << "Save numbers as(4)" << endl;
		cout << "Save input as(5)" << endl;
		cout << " Exit(6 ) " << endl;

		y = getValidatedChoose();
		switch (y) {
		case 1:
			cout << "Your text:  ";
			getchar();
			create();
			registrChecking();
			break;
		case 2:
			Read();
			break;
		case 3:
			GetNumbers();
			break;
		case 4:
			SaveNumbersAs();
			break;
		case 5:
			saveInputAs();
			break;
		}
	} while (y != 6);
	return 0;
}
