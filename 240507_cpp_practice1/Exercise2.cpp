#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool CheckInput() 
{
	//길이가 같은지?
	//하나하나 
	return true;
}

int main()
{
	ifstream file("bonus_input.txt");
	string line, input;
	vector <string> v1, v2;
	int num, lineCount = 0;

	cout << "1. 데이터 출력" << endl;
	while (getline(file, line))
	{
		v1.push_back(line);
		cout << line << endl;
		lineCount++;
	}

	file.close();

	cout << "2. 사용자 입력" << endl
		<< ": 줄 순서를 입력해주세요 ex) 231" << endl;
	//공백 확인 9줄까지 문자 확인
	cin >> input;
	
	/*
	
	while (!CheckInput)
	{
		cout << "[재입력]" << endl;
		cin >> input;
	}

	*/


	ofstream write_file("bonus_output.txt");
	if (write_file.fail()) cout << "파일 없음" << endl;


	for (int i = 0; i < input.size(); i++)
	{
		num = input[i] - '0';
		cout << v1.at(num - 1) << endl;
		v2.push_back(v1.at(num-1));
	}

	for (string line : v2)
	{
		write_file << line << endl;
	}

	write_file.close();
}