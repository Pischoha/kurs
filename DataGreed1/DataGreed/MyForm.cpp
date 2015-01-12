#include "MyForm.h"                   //            The header file of the form
using namespace DataGreed;             //            The name of the namespace in MyForm.h
[STAThreadAttribute]                     //            Run this program in STA mode
int main(){
	MyForm fm;                      //            The form to be created and shown
	fm.ShowDialog();              //            Show the form
	return 0;
}

std::vector<WorkerInfo> ReadFile(std::string fileName)
{
	std::vector<WorkerInfo> workers;
	std::ifstream in(fileName);
	while (in.good())
	{
		//read the file into vector of strings
		std::vector<std::string> row = csv_read_row(in, ';');
		for (int i = 0, leng = row.size(); i < leng; i++)
		{
			if (i % 2 == 0)
			{
				lastName = Trimmer(row[i]);

			}
			else
			{
				strSalary = Trimmer(row[i]);
				salary = 0;
				if (!Parse(strSalary, &salary)) continue;
				worker = { lastName, salary };
				workers.push_back(worker);

			}
		}
	}
	in.close();
	return workers;
}

std::vector<std::string> csv_read_row(std::istream &in, char delimiter)
{
	std::stringstream ss;
	bool inquotes = false;
	std::vector<std::string> row;//relying on RVO
	while (in.good())
	{
		char c = in.get();
		if (!inquotes && c == delimiter) //end of field
		{
			row.push_back(ss.str());
			ss.str("");
		}
		else if (!inquotes && c == '\\')
		{
			row.push_back(ss.str());
			return row;
		}
		else
		{
			ss << c;
		}
	}
	return row;
}

std::string Trimmer(std::string s)
{
	while (s[0] == ' ')
	{
		s = s.substr(1);
	}
	while (s[s.length() - 1] == ' ')
	{
		s = s.substr(0, s.length() - 1);
	}
	return s;
}

std::string dtos(double dbl){
	char buf[BUFSIZ];
	sprintf_s(buf, "%lf", dbl);
	return buf;
}

bool Parse(std::string str, double *value)
{
	char* endptr;
	*value = strtod(str.c_str(), &endptr);
	return !*endptr;
}