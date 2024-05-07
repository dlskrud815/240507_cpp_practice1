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
	int type = 0; // ����

	while (true) {
		// cin���� ������ 1�� ������ ������ ��찡 ���ɵ�??
		if (info[i].name.empty() || info[i].pw.empty())
		{
			type = 1; // �Է� ���
		}
		else if (info[i].pw.size() < 6 || info[i].pw.size() > 18)
		{
			type = 2; // ��й�ȣ ���
		}
		else {
			break;
		}

		switch (type)
		{
		case 1:
			cout << "* {������̸�} {��й�ȣ}�� ���� ������� �Է����ּ���." << endl;
			break;
		case 2:
			cout << "* ��й�ȣ�� 6�ڸ� �̻� ~ 18�ڸ� �̸����� �Է����ּ���." << endl;
			break;
		}

		cout << i + 1 << "��° ȸ��: ";
		cin >> info[i].name >> info[i].pw;
	}
}


int main()
{
	int num;

	cout << "�� ���� ȸ��? ";
	cin >> num;
	cout << endl << num << "���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;

	vector <memberInfo> info(num);

	for (int i = 0; i < num; i++)
	{
		cout << i+1 << "��° ȸ��: ";
		cin >> info[i].name >> info[i].pw;

		CheckInput(info, i);
	}

	ofstream write_file("member_output.txt");
	if (write_file.fail()) cout << "���� ����" << endl;

	for (int i = 0; i < num; i++)
	{
		write_file << info[i].name << " " << info[i].pw << endl;
	}

	write_file.close();

	cout << endl << "------------- ȸ�� ��� ���� �б� -------------" << endl;

	ifstream read_file("member_output.txt");
	string line;

	while (getline(read_file, line))
	{
		cout << line << endl;
	}

	read_file.close();

	return 0;
}