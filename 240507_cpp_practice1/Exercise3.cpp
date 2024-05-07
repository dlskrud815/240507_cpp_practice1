#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct memberInfo {
	string name;
	int pw;

	memberInfo() : pw(0) {}
};

int main()
{
	int num;

	cout << "몇 명의 회원? ";
	cin >> num;
	cout << num << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;

	vector <memberInfo> info(num);

	for (int i = 0; i < num; i++)
	{
		cout << i+1 << "번째 회원: ";
		cin >> info[i].name >> info[i].pw;
	}

	ofstream write_file("member_output.txt");
	if (write_file.fail()) cout << "파일 없음" << endl;

	for (int i = 0; i < num; i++)
	{
		write_file << info[i].name << " " << info[i].pw << endl;
	}

	write_file.close();

	cout << "------------- 회원 명부 파일 읽기 -------------" << endl;

	ifstream read_file("member_output.txt");
	string line;

	while (getline(read_file, line))
	{
		cout << line << endl;
	}

	read_file.close();

	return 0;
}