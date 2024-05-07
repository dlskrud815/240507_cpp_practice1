#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream file("C://Users/lng/OneDrive - UOU/바탕 화면/SF5 실습/20240507/hello.txt");
	string line;
	vector <string> v;

	while (getline(file, line))
	{
		v.push_back(line);
	}

	file.close();

	ofstream write_file("C://Users/lng/OneDrive - UOU/바탕 화면/SF5 실습/20240507/output.txt");

	if (write_file.fail()) cout << "파일 없음" << endl;

	for (int i = v.size() - 1 ; i >= 0; i--)
	{
		write_file << v[i] << endl;
	}

	write_file.close();

	return 0;
}