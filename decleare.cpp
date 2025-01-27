#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "HEADING_H"

friend void printhomepage() {
	char temp;
	cout << "A:	������ѧ��";
	cout << "B:	ɾ��ѧ��";
	cout << "C:	����ѧ��";
	cout << "D:	�޸�ѧ��";
	cout << "E:	���й���";
	cin >> temp;
	if (temp == 'A') {
		Addstudent();
	} else if (temp = 'B') {
		Deletestudent();
	} else if (temp = 'C') {
		Searchstudent();
	} else if (temp = 'D') {
		Changestudent();
	} else if (temp = 'E') {
		Ranking();
	}
}

void student::Addstudent() {
	system("cls");
	cout << "�����ڼ����µ�ѧ����Ϣ��";
	cout << "�밴��ѧ�ţ��������ɼ��ָ���";
	student temp;
	cin << temp.code;
	getline(temp.name);
	cin << temp.score;
	ofstream New_student("student.tex", ios::out | ios::app)
	New_student << temp.code << '\n';
	New_student << temp.name << '\n';
	New_student << temp.score << '\n';
	cout << "����ɹ���";
	printhomepage();

}

void student::Deletestudent() {

	system("cls");
	cout << "����ɾ��ѧ����Ϣ\n";
	cout << "������Ҫɾ����ѧ�š�\n";
	string templine;
	cin >> templine;



	ifstream test("student.txt", ios::in);
	int line_code;
	string line_name;
	float line_score;
	bool found = false;

	ofstream New_test("temp.txt");
	while (test >> line_code >> line_name >> line_score) {
		if (line_code == templine) {
			found = true;
			continue;
		} else {
			New_test << line_code << "\n" << line_name << "\n" << line_score << "\n";
		}
	}
	if (found == true) {
		test.close();
		New_test.close();

		remove("student.txt");
		rename("temp.txt", "student.txt");

		system("cls");
		cout << "�Ѿ�ɾ����ָ�����ݡ�";
		system("pause");
		printhomepage();
	} else {
		cout << "û��ָ�����ݡ�";
		system("pause");
		printhomepage();
	}

}

void student::Searchstudent() {
	system("cls");
	cout << "������Ҫ���ҵ�ѧ�š�\n";
	string temp_code;
	cin >> temp_code;
	ifstream Reader("student.txt", ios::in);
	if (Reader) {
		bool found = false;
		int line_code;
		string line_name;
		float line_score;
		while (Reader >> line_code >> line_name >> line_score && !found) {
			if (line_code == temp_code ) {
				found = true;
				cout << "�������ѧ����\n";

			}
		}
		if (!found) {
			cout << "���������ѧ����\n";
			system("pause");
			printhomepage();
		}
		system("pause");
		printhomepage();
		Reader.close();
	} else {
		cout << "�޷����ļ����ж�ȡ���㽫������һ����";
		system("pause");
		printhomepage();
	}
}

void student::Changestudent() {
	system("cls");
	cout << "�����ڸĳɼ���\n";
	cout << "������ѧ�š�\n";
	cout << "������һ��������Ķ���ĳɼ�\n";

	string change_to;
	string temp_code;
	cin >> temp_code >> change_to;


	bool found = false;
	int line_code;
	string line_name;
	float line_score;
	ifstream test("student.txt", ios::in);
	ofstream New_test("temp.txt");
	while (test >> line_code >> line_name >> line_score) {
		if (line_code == temp_code) {
			found = true;
			New_test <<  line_code << "\n" << line_name  << "\n" << change_to << "\n";
		} else {
			New_test << line_code << "\n" << line_name  << "\n" << line_score << "\n";
		}
	}
	if (found == true) {
		test.close();
		New_test.close();

		remove("student.txt");
		rename("temp.txt", "student.txt");

		system("cls");
		cout << "�Ѿ��޸���ָ�����ݡ�";
		system("pause");
		printhomepage();
	} else {
		cout << "û��ָ�����ݡ�";
		printhomepage();
	}
}






friend void Ranking() {
	char temp;
	cout << "A:	ȫ����";
	cout << "B:	ƽ����";
	cout << "C:	��߷�";
	cout << "D:	��ͷ�";
	cin >> temp;
	if (temp == 'A') {
		totalRank();
	} else if (temp == 'B') {
		Average();
	} else if (temp == 'C') {
		Highest();
	} else if (temp == 'D') {
		Lowest();
	}
}

friend void totalRank() {
	ifstream test("student.txt", ios::in);
	vector<float>total ;
	while (test >> line_code >> line_name >> line_score) {
		total.push_back(line_score)
	}
	for (int i = 0; i < total.size(); i++) {
		cout << i + 1 << "�� " << total[i];
	}
	test.close();
	printhomepage();
}

friend void Average() {
	ifstream test("student.txt", ios::in);
	vector<float>total ;
	while (test >> line_code >> line_name >> line_score) {
		total.push_back(line_score)
	}
	float sum = 0;
	for (int i = 0; i < total.size(); i++) {
		sum += total[i];
	}
	float average = sum / total.size();
	cout << "ƽ�����ǣ� " << average;
	test.close();
	printhomepage();
}

friend void Highest() {
	ifstream test("student.txt", ios::in);
	vector<float>total ;
	while (test >> line_code >> line_name >> line_score) {
		total.push_back(line_score)
	}
	float highest = 0;
	for (int i = 0; i < total.size(); i++) {
		if (total[i] > highest) {
			highest = total[i];
		}
	}
	cout << "��߷��ǣ� " << highest;
	test.close();
	printhomepage();
}

friend void Lowest() {
	ifstream test("student.txt", ios::in);
	vector<float>total ;
	while (test >> line_code >> line_name >> line_score) {
		total.push_back(line_score)
	}
	float lowest = 1000;
	for (int i = 0; i < total.size(); i++) {
		if (total[i] < highest) {
			lowest = total[i];
		}
	}
	cout << "��ߵͷ��ǣ� " << lowest;
	test.close();
	printhomepage();
}







