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

	cout << "�� ���� ȸ��? ";
	cin >> num;
	cout << num << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;

	vector <memberInfo> info(num);

	for (int i = 0; i < num; i++)
	{
		cout << i+1 << "��° ȸ��: ";
		cin >> info[i].name >> info[i].pw;
	}

	ofstream write_file("member_output.txt");
	if (write_file.fail()) cout << "���� ����" << endl;

	for (int i = 0; i < num; i++)
	{
		write_file << info[i].name << " " << info[i].pw << endl;
	}

	write_file.close();

	cout << "------------- ȸ�� ��� ���� �б� -------------" << endl;

	ifstream read_file("member_output.txt");
	string line;

	while (getline(read_file, line))
	{
		cout << line << endl;
	}

	read_file.close();

	return 0;
}