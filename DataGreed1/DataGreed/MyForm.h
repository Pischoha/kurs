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
#include <msclr\marshal_cppstd.h>

struct WorkerInfo
{
	std::string LastName;
	double Salary;
};

std::vector<std::string> csv_read_row(std::istream &in, char delimiter);
std::string Trimmer(std::string s);
std::string dtos(double dbl);
std::vector<WorkerInfo> ReadFile(std::string fileName);




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
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;


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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(600, 368);
			this->dataGridView1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(640, 28);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 42);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(638, 172);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Save workers info";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(640, 76);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 42);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Delete select row";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 411);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(227, 411);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(165, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 395);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"LastName";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(224, 395);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Salary";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(639, 124);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(98, 42);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Fill from textbox";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(638, 220);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(97, 42);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Save all table";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 443);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:


		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			std::vector<WorkerInfo> workers;
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				std::string fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
				workers = ReadFile(fileName);
				if (workers.size() == 0)
					return;
			}
			else
			{
				return;
			}


			DataTable^ MyTable = gcnew DataTable();
			MyTable->Columns->Add(gcnew DataColumn("Last name", Type::GetType("System.String")));
			MyTable->Columns->Add(gcnew DataColumn("Salary", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Income tax", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Pension tax", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Employment fund", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Total retained", Type::GetType("System.Double")));
			MyTable->Columns->Add(gcnew DataColumn("Total to issue", Type::GetType("System.Double")));

			/*Связать таблицу с dataGridView*/
			dataGridView1->DataSource = MyTable;
			dataGridView1->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[4]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[5]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			
			dataGridView1->Columns[2]->ReadOnly = true;
			dataGridView1->Columns[3]->ReadOnly = true;
			dataGridView1->Columns[4]->ReadOnly = true;
			dataGridView1->Columns[5]->ReadOnly = true;

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
				 std::vector<WorkerInfo> workers;
				 std::string fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
				 workers = ReadFile(fileName);
				 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 std::string saveName = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
					 workers = ReadFile(fileName);
					 if (workers.size() == 0)
						 return;
				 }
				 else
				 {
					 return;
				 }
				 std::string saveName = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
				 std::ofstream on(saveName);
				 std::string str;
				 for (int i = 0; i < workers.size(); i++)
				 {
					 str += workers[i].LastName + "; " + dtos(workers[i].Salary) + "\\ ";
					 
				 }
				 on << str << std::endl;
				 on.close();				 
	}


	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

				 std::vector<int> selectedRows;

				 for (int i = 0; i < dataGridView1->SelectedRows->Count; i++)
				 {
					 selectedRows.push_back(dataGridView1->SelectedRows[i]->Index);
				 }
				 for (int i = 0; i < selectedRows.size(); i++)
				 {
					 dataGridView1->Rows->RemoveAt(selectedRows[i]);
				 }
				 
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 std::string fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
				 std::vector<WorkerInfo> workers;
				 workers = ReadFile(fileName);
				 DataTable^ MyTable = gcnew DataTable();
				 MyTable->Columns->Add(gcnew DataColumn("Last name", Type::GetType("System.String")));
				 MyTable->Columns->Add(gcnew DataColumn("Salary", Type::GetType("System.Double")));
				 MyTable->Columns->Add(gcnew DataColumn("Income tax", Type::GetType("System.Double")));
				 MyTable->Columns->Add(gcnew DataColumn("Pension tax", Type::GetType("System.Double")));
				 MyTable->Columns->Add(gcnew DataColumn("Employment fund", Type::GetType("System.Double")));
				 MyTable->Columns->Add(gcnew DataColumn("Total retained", Type::GetType("System.Double")));
				 MyTable->Columns->Add(gcnew DataColumn("Total to issue", Type::GetType("System.Double")));

				 /*Связать таблицу с dataGridView*/
				 dataGridView1->DataSource = MyTable;
				 dataGridView1->Columns[0]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				 dataGridView1->Columns[1]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				 dataGridView1->Columns[2]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				 dataGridView1->Columns[3]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				 dataGridView1->Columns[4]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				 dataGridView1->Columns[5]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

				 if (textBox1->Text != ""&&textBox2->Text != "")
				 {
					 
					 String^ SyslastName = textBox1->Text;
					 std::string lastName = msclr::interop::marshal_as<std::string>(SyslastName);
					 String^ Syssalary = textBox2->Text;
					 std::string Strsalary = msclr::interop::marshal_as<std::string>(Syssalary);
					 salary = stod(Strsalary);
					 worker = { lastName, salary };
					 workers.push_back(worker);
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

					 std::ofstream in(fileName);
					 std::string str;
					 for (int i = 0; i < workers.size(); i++)
					 {
						 str += workers[i].LastName + "; " + dtos(workers[i].Salary) + "\\ ";
					 }
					 in << str << std::endl;
					 in.close();
					 textBox1->Text = "";
					 textBox2->Text = "";	 
				 }
				 else
				 {	
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
					 System::Windows::Forms::MessageBox::Show("Field is not filled");
				 }

	}
	
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 std::vector<WorkerInfo> workers;
			 std::string fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
			 workers = ReadFile(fileName);
			 if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 std::string saveAllName = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
				 workers = ReadFile(fileName);
				 if (workers.size() == 0)
					 return;
			 }
			 else
			 {
				 return;
			 }
			 std::string saveAllName = msclr::interop::marshal_as<std::string>(saveFileDialog1->FileName);
			 std::ofstream on(saveAllName);
			 std::string str;
			 for (int i = 0; i < workers.size(); i++)
			 {
				 double salary = workers[i].Salary;
				 double PP = salary * 0.2;
				 double PF = salary * 0.01;
				 double FZ = salary *0.005;
				 double U = PP + PF + FZ;
				 double ZP = salary - U;
				 str += workers[i].LastName + " | " + dtos(workers[i].Salary) + " | " + dtos(PP) + " | " + dtos(PF) + " | " + dtos(FZ) + " | " + dtos(U) + " | " + dtos(ZP);

			 }
			 on << str << std::endl;
			 on.close();

}
};
}