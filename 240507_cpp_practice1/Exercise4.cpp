#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> //공백 split용

using namespace std;

int main()
{
	string line, name, pw, name_input, pw_input;
	bool nameCheck = false, pwCheck = false;

	cout << "이름을 입력하세요: ";
	cin >> name_input;
	cout << "비번을 입력하세요: ";
	cin >> pw_input;

	ifstream member_file("member.txt");
	
	while (getline(member_file, line))
	{
		stringstream ss(line);
		ss >> name >> pw;

		//cout << "확인용: " << name << " " << pw << endl;

		if (name_input == name)
		{
			nameCheck = true;

			if (pw_input == pw)
			{
				pwCheck = true;
				break;
			}
		}
	}

	member_file.close();

	if (nameCheck == true && pwCheck == true)
	{
		cout << endl << "로그인 성공" << endl;
	}
	else
	{
		cout << endl << "로그인 실패" << endl;
	}

	return 0;
}