#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct memberInfo {
	string name, pw;
};

void CheckInput(string idPw, vector<memberInfo>& info, int i)
{
	int type = 0, cnt, j;
	vector <string> idPwInfo(2);

	while (true) {

		cnt = 0,  j = 0;

		for (int i = 0; i < idPw.size(); i++)
		{
			idPwInfo[j] += idPw[i];

			if (idPw[i] == ' ')
			{
				cnt++;
				j++;
			}
		}

		if (cnt == 1)
		{
			info[i].name = idPwInfo[0];
			info[i].pw = idPwInfo[1];
		}

		// cin으로 받으면 1번 오류에 당착할 경우가 없능디??
		if (cnt > 1 || cnt < 1)
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
		cin >> idPw;
		//cin >> info[i].name >> info[i].pw;
	}
}


int main()
{
	int num;
	string idPw;

	cout << "몇 명의 회원? ";
	cin >> num;
	cout << endl << num << "명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;

	vector <memberInfo> info(num);

	for (int i = 0; i < num; i++)
	{
		cout << i+1 << "번째 회원: ";
		cin >> idPw;

		CheckInput(idPw, info, i);
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