#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "HEADING_H"

friend void printhomepage() {
	char temp;
	cout << "A:	增加新学生";
	cout << "B:	删除学生";
	cout << "C:	查找学生";
	cout << "D:	修改学生";
	cout << "E:	排行功能";
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
	cout << "你正在加入新的学生信息。";
	cout << "请按照学号，姓名，成绩分隔开";
	student temp;
	cin << temp.code;
	getline(temp.name);
	cin << temp.score;
	ofstream New_student("student.tex", ios::out | ios::app)
	New_student << temp.code << '\n';
	New_student << temp.name << '\n';
	New_student << temp.score << '\n';
	cout << "输入成功。";
	printhomepage();

}

void student::Deletestudent() {

	system("cls");
	cout << "正在删除学生信息\n";
	cout << "请输入要删除的学号。\n";
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
		cout << "已经删除了指定内容。";
		system("pause");
		printhomepage();
	} else {
		cout << "没有指定内容。";
		system("pause");
		printhomepage();
	}

}

void student::Searchstudent() {
	system("cls");
	cout << "输入你要查找的学号。\n";
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
				cout << "存在这个学生！\n";

			}
		}
		if (!found) {
			cout << "不存在这个学生。\n";
			system("pause");
			printhomepage();
		}
		system("pause");
		printhomepage();
		Reader.close();
	} else {
		cout << "无法对文件进行读取，你将返回上一级。";
		system("pause");
		printhomepage();
	}
}

void student::Changestudent() {
	system("cls");
	cout << "你正在改成绩。\n";
	cout << "请输入学号。\n";
	cout << "请在下一行输入你改动后的成绩\n";

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
		cout << "已经修改了指定内容。";
		system("pause");
		printhomepage();
	} else {
		cout << "没有指定内容。";
		printhomepage();
	}
}






friend void Ranking() {
	char temp;
	cout << "A:	全排列";
	cout << "B:	平均分";
	cout << "C:	最高分";
	cout << "D:	最低分";
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
		cout << i + 1 << "： " << total[i];
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
	cout << "平均分是： " << average;
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
	cout << "最高分是： " << highest;
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
	cout << "最高低分是： " << lowest;
	test.close();
	printhomepage();
}







