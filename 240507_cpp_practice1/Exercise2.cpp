#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool CheckInput() 
{
	//���̰� ������?
	//�ϳ��ϳ� 
	return true;
}

int main()
{
	ifstream file("bonus_input.txt");
	string line, input;
	vector <string> v1, v2;
	int num, lineCount = 0;

	cout << "1. ������ ���" << endl;
	while (getline(file, line))
	{
		v1.push_back(line);
		cout << line << endl;
		lineCount++;
	}

	file.close();

	cout << "2. ����� �Է�" << endl
		<< ": �� ������ �Է����ּ��� ex) 231" << endl;
	//���� Ȯ�� 9�ٱ��� ���� Ȯ��
	cin >> input;
	
	while (!CheckInput)
	{
		cout << "[���Է�]" << endl;
		cin >> input;
	}

	ofstream write_file("bonus_output.txt");
	if (write_file.fail()) cout << "���� ����" << endl;


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