#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct memberInfo {
	string name;
	string pw;
};

void CheckInput(vector<memberInfo>& info, int i)
{
	int type = 0; // 정상

	while (true) {
		// cin으로 받으면 1번 오류에 당착할 경우가 없능디??
		if (info[i].name.empty() || info[i].pw.empty())
		{
			type = 1; // 입력 양식
		}
		else if (info[i].pw.size() < 6 || info[i].pw.size() > 18)
		{
			type = 2; // 비밀번호 양식
		}
		else {
			break;
		}

		switch (type)
		{
		case 1:
			cout << "* {사용자이름} {비밀번호}과 같은 양식으로 입력해주세요." << endl;
			break;
		case 2:
			cout << "* 비밀번호는 6자리 이상 ~ 18자리 미만으로 입력해주세요." << endl;
			break;
		}

		cout << i + 1 << "번째 회원: ";
		cin >> info[i].name >> info[i].pw;
	}
}


int main()
{
	int num;

	cout << "몇 명의 회원? ";
	cin >> num;
	cout << endl << num << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;

	vector <memberInfo> info(num);

	for (int i = 0; i < num; i++)
	{
		cout << i+1 << "번째 회원: ";
		cin >> info[i].name >> info[i].pw;

		CheckInput(info, i);
	}

	ofstream write_file("member_output.txt");
	if (write_file.fail()) cout << "파일 없음" << endl;

	for (int i = 0; i < num; i++)
	{
		write_file << info[i].name << " " << info[i].pw << endl;
	}

	write_file.close();

	cout << endl << "------------- 회원 명부 파일 읽기 -------------" << endl;

	ifstream read_file("member_output.txt");
	string line;

	while (getline(read_file, line))
	{
		cout << line << endl;
	}

	read_file.close();

	return 0;
}