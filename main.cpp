// Program: Student Database using 2d arrays
// Programmer: M Maaz Ahmad
// Compiler Used: Microsoft Visual Studio Community Edition 2022

#include <iostream>
#include <string>
#define SIZE 60
using namespace std;


// Read Data Function
void readData(int rr[], int ss1[], int ss2[], int ss3[], int ss4[], int ss5[], string nname[], int& nn) {
	cout << "Enter number of students: ";
	cin >> nn;
	cout << endl;
	for (int i = 0; i < nn; i++) {
		cout << endl << "Enter student " << i + 1 << " regirstion number: ";
		cin >> rr[i];
		cout << endl << "Enter student " << i + 1 << " name: ";
		cin.ignore(); // to ignore whitespace character left in the buffer by cin
		getline(cin, nname[i]);
		cout << endl << "Enter student " << i + 1 << " Subject 1 marks: ";
		cin >> ss1[i];
		cout << endl << "Enter student " << i + 1 << " Subject 2 marks: ";
		cin >> ss2[i];
		cout << endl << "Enter student " << i + 1 << " Subject 3 marks: ";
		cin >> ss3[i];
		cout << endl << "Enter student " << i + 1 << " Subject 4 marks: ";
		cin >> ss4[i];
		cout << endl << "Enter student " << i + 1 << " Subject 5 marks: ";
		cin >> ss5[i];
		cout << endl << "===================================================";
	}
	cout << endl;
}

void appendData(int rr[], int ss1[], int ss2[], int ss3[], int ss4[], int ss5[], string nname[], int& n) {
	if (n > 0)
	{
		cout << endl << "Enter student " << n + 1 << " regirstion number: ";
		cin >> rr[n];
		cout << endl << "Enter student " << n + 1 << " name: ";
		cin.ignore(); // to ignore whitespace character left in the buffer by cin
		getline(cin, nname[n]);
		cout << endl << "Enter student " << n + 1 << " Subject 1 marks: ";
		cin >> ss1[n];
		cout << endl << "Enter student " << n + 1 << " Subject 2 marks: ";
		cin >> ss2[n];
		cout << endl << "Enter student " << n + 1 << " Subject 3 marks: ";
		cin >> ss3[n];
		cout << endl << "Enter student " << n + 1 << " Subject 4 marks: ";
		cin >> ss4[n];
		cout << endl << "Enter student " << n + 1 << " Subject 5 marks: ";
		cin >> ss5[n];
		cout << endl << "===================================================";
		n++;
	}
	else {
		cout << endl << "No Data available. Please, insert some data.";
	}
}

void resultGen(int rr[], int ss1[], int ss2[], int ss3[], int ss4[], int ss5[], string nname[], int n) {
	if (n == 0)
		cout << "No Data available. Please, insert some data.";
	else
	{
		cout << "Reg # \t" << "Name\t\t\t\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t" << endl
			<< "-------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < n; i++) {
			cout << rr[i] << "\t" << nname[i] << "\t\t\t" << ss1[i] << "\t" << ss2[i] << "\t" << ss3[i] << "\t"
				<< ss4[i] << "\t" << ss5[i] << "\t" << endl;
		}
	}
}

int searchRec(int rr[], int ss1[], int ss2[], int ss3[], int ss4[], int ss5[], string nname[], int n) {
	int sInfo;
	int sPos = -1;
	if (n == 0)
		cout << "No Data available. Please, insert some data." << endl;
	else {
		cout << endl << "Enter reg no. of student: ";
		cin >> sInfo;
		for (int i = 0; i < n; i++) {
			if (sInfo == rr[i]) {
				sPos = i;
				break;
			}
		}
		return sPos;
	}
}

void delRecord(int rr[], int ss1[], int ss2[], int ss3[], int ss4[], int ss5[], string nname[], int& n) {
	if (n == 0)
		cout << endl << "No Data available. Please, insert some data." << endl;
	else {
		int delPos = searchRec(rr, ss1, ss2, ss3, ss4, ss5, nname, n);
		if (delPos == -1)
			cout << endl << "Not found for Deletion" << endl;
		else {
			for (int i = delPos; i < n - 1; i++) {
				rr[i] = rr[i + 1];
				ss1[i] = ss1[i + 1];
				ss2[i] = ss2[i + 1];
				ss3[i] = ss3[i + 1];
				ss4[i] = ss4[i + 1];
				ss5[i] = ss5[i + 1];
				nname[i] = nname[i + 1];
			}
			n--;
			cout << endl << "Operation Successful!" << endl;
		}
	}
		
}

int main() {
	int rno[SIZE], s1[SIZE], s2[SIZE], s3[SIZE], s4[SIZE], s5[SIZE];
	string name[SIZE];
	int n=0; 
	char ch;
	do {
		cout << endl << "----------------****----------------" << endl
			<< "1. Add or Append Data" << endl
			<< "2. Display Result Card" << endl
			<< "3. Search a particular Record" << endl
			<< "4. Delete a Record" << endl
			<< "5. Exit" << endl
			<< "----------------****----------------" << endl;

		cout << "Enter your choice: ";
		cin >> ch;
		cout << endl;
		switch (ch) {
		case '1':
			if(n==0)
				readData(rno, s1, s2, s3, s4, s5, name, n);
			else
				appendData(rno, s1, s2, s3, s4, s5, name, n);
			break;
		case '2':
			resultGen(rno, s1, s2, s3, s4, s5, name, n);
			break;
		case '3':
				int sPos;
				sPos = searchRec(rno, s1, s2, s3, s4, s5, name, n);
			if (n != 0)
			{
				cout << "Reg # \t" << "Name\t\t\t\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t" << endl
					<< "-------------------------------------------------------------------------------" << endl;
				cout << rno[sPos] << "\t" << name[sPos] << "\t\t\t" << s1[sPos] << "\t" << s2[sPos] << "\t" << s3[sPos] << "\t"
					<< s4[sPos] << "\t" << s4[sPos] << "\t" << endl;
			}
			break;
		case '4':
			delRecord(rno, s1, s2, s3, s4, s5, name, n);
			break;
		case '5':
			exit(-1);
			break;
		default:
			cout << "Invalid Input" << endl;
		}
	} while (true);
}
