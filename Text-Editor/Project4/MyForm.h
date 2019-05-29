#pragma once
#include "MyForm1.h"
#include <ostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include <deque>
#include <istream>

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		List<String^>^ ls = gcnew List<String^>();
		MyForm(void)
		{
			InitializeComponent();
			String^ fileName = "Words.txt";
			try
			{
				StreamReader^ din = File::OpenText(fileName);
				String^ str;
				int count = 0;
				while ((str = din->ReadLine()) != nullptr)
				{
					count++;
					ls->Add(str);
				}
				int indx = ls->Count - 1;
			}
			catch (Exception^ e)
			{
				if (dynamic_cast<FileNotFoundException^>(e))
					MessageBox::Show("file '{0}' not found", fileName);
				else
					MessageBox::Show("problem reading file '{0}'", fileName);
			}
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
	private: System::Windows::Forms::Label^  label2;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button13;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Maroon;
			this->label2->Location = System::Drawing::Point(412, 279);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Create new note";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(475, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(74, 26);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Log";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(416, 180);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 24);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(412, 146);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Note Name";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(499, 0);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(36, 34);
			this->button10->TabIndex = 36;
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(457, 0);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(36, 34);
			this->button9->TabIndex = 35;
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = false;
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(415, 0);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(36, 34);
			this->button15->TabIndex = 34;
			this->button15->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button15->UseVisualStyleBackColor = false;
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->Location = System::Drawing::Point(589, 0);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(17, 30);
			this->button11->TabIndex = 33;
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::White;
			this->button13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.Image")));
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(612, 0);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(32, 35);
			this->button13->TabIndex = 32;
			this->button13->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(644, 369);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		List<String^>^ list = gcnew List<String^>();
		String^ fileName = "user.txt";
		try
		{
			StreamReader^ din = File::OpenText(fileName);
			String^ str;
			int count = 0;
			while ((str = din->ReadLine()) != nullptr)
			{
				count++;
				list->Add(str);
			}
			int indx = list->Count - 1;
			while (indx >= 0) {
				if (list[indx] == textBox1->Text) {
					MyForm1^ pop = gcnew MyForm1(list[indx], 1);
					this->Hide();
					pop->Show();
				}
				indx--;
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				MessageBox::Show("file " + textBox1->Text +" not found");
			else
				MessageBox::Show("problem reading file " + textBox1->Text);
		}
		list->Clear();
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm1^ pop = gcnew MyForm1("", 0);
	this->Hide();
	pop->Show();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
	Environment::Exit(0);
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	WindowState = FormWindowState::Minimized;
}
};
}
