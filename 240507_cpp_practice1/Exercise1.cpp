#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//ifstream file("C://Users/lng/OneDrive - UOU/���� ȭ��/SF5 �ǽ�/20240507/hello.txt");
	ifstream file("hello.txt");
	string line;
	vector <string> v;

	while (getline(file, line))
	{
		v.push_back(line);
	}

	file.close();

	//ofstream write_file("C://Users/lng/OneDrive - UOU/���� ȭ��/SF5 �ǽ�/20240507/output.txt");
	ofstream write_file("output.txt");

	if (write_file.fail()) cout << "���� ����" << endl;

	while (!v.empty())
	{
		write_file << v.back() << endl;
		v.pop_back();
	}

	write_file.close();

	return 0;
}