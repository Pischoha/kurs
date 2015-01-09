﻿#pragma once

#include <stdio.h>
#include <tchar.h>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <stdio.h>
#include <tchar.h>
#include <cstring>
#include <cstdlib>

std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
std::string Trimmer(std::string s);
std::string dtos(double dbl);

struct WorkerInfo
{
	std::string LastName;
	double Salary;
};
std::string dtos(double dbl){
	char buf[BUFSIZ];
	sprintf_s(buf, "%lf", dbl);
	return buf;
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
}
std::vector<WorkerInfo> workers;

std::string lastName;
std::string strSalary;
double salary;
WorkerInfo worker;

namespace DataGreed {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(591, 422);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(652, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(652, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 32);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(783, 446);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		
		
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			std::ifstream in("input.csv");
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
						salary = stod(strSalary);
						salary = floor((salary * 10) + 0.5);
						salary /= 10;
						worker = { lastName, salary };
						workers.push_back(worker);
						
					}
				}			
			}
			in.close();

			/*Добавление Колонны*/
			DataTable^ MyTable = gcnew DataTable();
			MyTable->Columns->Add(gcnew DataColumn("Last name", Type::GetType("System.String")));
			MyTable->Columns->Add(gcnew DataColumn("Salary", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Income tax", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Pension tax", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Employment fund", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Total retained", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Total to issue", Type::GetType("System.Double")));

			/*Связать таблицу с dataGridView*/
			dataGridView1->DataSource = MyTable; //связь
			dataGridView1->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[4]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[5]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			for (int i = 0; i < workers.size(); i++)
			{
				String^ lastName = gcnew String(workers[i].LastName.c_str());
				double salary = workers[i].Salary;
				double PP = salary * 0.2;
				double PF = salary * 0.01;
				double FZ = salary *0.005;
				double U = PP + PF + FZ;
				double ZP = salary - U;
				MyTable->Rows->Add(lastName, salary, PP, PF, FZ, U, ZP);

			}
				 

				

				 /*Сохраняем в xml*/
				 /*DataSet^ DS = gcnew DataSet();
				 DS->Tables->Add(MyTable);
				 DS->WriteXml("C:\\patch_list.xml");
*/
				 /*Загружаем из файла*/
				 /*DataSet^ DS = gcnew DataSet();
				 try
				 {
					 DS->ReadXml(C:\\patch_list.xml);
					 dataGridView1->DataSource = DS->Tables[0];
					 dataGridView1->Refresh();
				 }
				 catch (System::Exception^ e)
				 {
					 MessageBox::Show("Ошибка чтение xml");
				 }*/
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}