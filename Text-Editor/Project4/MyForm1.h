#pragma once
#include <ostream>
#include <string>
#include <string.h>
#include <stack>
#include <vector>
#include "MyForm.h"
#include <deque>
#include <istream>
#include "stac.h"

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
	/// Summary for MyForm1
	/// </summary>
	value struct KMP
	{

		List<int>^ ls;
		void memset(int arr[], int sz) {//initializing the array with zeros
			for (int i = 0; i < sz; ++i)
				arr[i] = 0;
		}
		void Replace(String^text, String^ pattern, RichTextBox^ RTB, String^Replace)
		{
			try
			{
				int N = text->Length;
				int M = pattern->Length;
				int *LPS = new int[M];
				memset(LPS, M);
				ComputeLPS(pattern, LPS);
				int i, j;
				i = j = 0;
				while (i < N && j < M)
				{
					if (pattern[j] == text[i])
					{
						j++;
						i++;
					}

					if (j == M)
					{

						if (i == N || (text[i] == ' ' && ((i - j == 0) || text[i - j - 1] == ' ')))
						{


							RTB->Select(i - j, M);
							RTB->SelectionBackColor = Color::Red;
							RTB->SelectedText = Replace;
							text = RTB->Text;
							N = text->Length;



						}
						j = LPS[j - 1];
					}
					else if (i < N && pattern[j] != text[i])
					{
						if (j != 0)
							j = LPS[j - 1];
						else
							i++;
					}

				}
			}
			catch (Exception^ E)
			{
				MessageBox::Show(E->Message);
			}
		}
		void HighLight(String ^text, String^pattern, RichTextBox^ RTB)
		{

			try {
				int N = text->Length;
				int M = pattern->Length;
				int *LPS = new int[M];
				memset(LPS, M);

				ComputeLPS(pattern, LPS);


				int i, j;
				i = j = 0;
				while (i < N && j < M)
				{
					if (pattern[j] == text[i])
					{
						j++;
						i++;
					}
					if (j == M)
					{
						if (i == N || (text[i] == ' ' && ((i - j == 0) || text[i - j - 1] == ' ')))
						{
							RTB->Select(i - j, M);
							RTB->SelectionBackColor = Color::Yellow;
						}
						j = LPS[j - 1];
					}
					else if (i < N && pattern[j] != text[i])
					{
						if (j != 0)
							j = LPS[j - 1];
						else
							i++;
					}
				}
			}
			catch (Exception^E)
			{
				MessageBox::Show(E->Message);
			}
		}
		void ComputeLPS(String^ pattern, int LPS[])//pre process the Longest Prefix suffix
		{


			int i = 1, j = 0;
			while (i < pattern->Length)
			{
				if (pattern[i] == pattern[j])
				{
					LPS[i] = j + 1;
					j++; i++;
				}
				else
				{
					if (j != 0)
						j = LPS[j - 1];
					else
					{
						LPS[i] = 0;
						i++;
					}
				}
			}


		}
		void Find(String ^text, String^pattern, RichTextBox^ RTB)
		{

			try {
				ls = gcnew List<int>();
				int N = text->Length;
				int M = pattern->Length;
				int *LPS = new int[M];
				memset(LPS, M);

				ComputeLPS(pattern, LPS);


				int i, j;
				i = j = 0;
				while (i < N && j < M)
				{
					if (pattern[j] == text[i])
					{
						j++;
						i++;
					}
					if (j == M)
					{

						ls->Add(i - j);
						j = LPS[j - 1];
					}
					else if (i < N && pattern[j] != text[i])
					{
						if (j != 0)
							j = LPS[j - 1];
						else
							i++;
					}
				}
			}
			catch (Exception^E)
			{
				MessageBox::Show(E->Message);
			}
		}
	};
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		List<int>^ indx;
		int idx, FindWordLen;
	public:
		bool Pop;
		String^ name = "";
		MyForm1(String^ num, bool check)
		{
			InitializeComponent();
			if (check == 1) {
				button1->PerformClick();
			}
			Pop = false;
			name = num;
			String^ pop = "";
			if (num != "") {
				String^ fileName = num  + ".txt";
				textBox2->Text = num;
				try
				{
					StreamReader^ din = File::OpenText(fileName);
					String^ str;
					int count = 0;
					while ((str = din->ReadLine()) != nullptr)
					{
						count++;
						pop += str;
						pop += " ";
					}
					richTextBox1->Text = pop;
				}
				catch (Exception^ e)
				{
					if (dynamic_cast<FileNotFoundException^>(e))
						MessageBox::Show("file " + richTextBox1->Text + " not found");
					else
						MessageBox::Show("problem reading file " + richTextBox1->Text);
				}
			}
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  DownRDP;
	private: System::Windows::Forms::RadioButton^  UpRDP;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Panel^  FindPnl;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Panel^  ReplacePnl;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->DownRDP = (gcnew System::Windows::Forms::RadioButton());
			this->UpRDP = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->FindPnl = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->ReplacePnl = (gcnew System::Windows::Forms::Panel());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->FindPnl->SuspendLayout();
			this->ReplacePnl->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F));
			this->textBox2->Location = System::Drawing::Point(179, 398);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(394, 30);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(597, 398);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(6, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 28);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Undo";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(100, 41);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 28);
			this->button3->TabIndex = 4;
			this->button3->Text = L"RE-DO";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 16.2F));
			this->richTextBox1->Location = System::Drawing::Point(4, 75);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(707, 308);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::richTextBox1_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(4, 388);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(158, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 35;
			this->pictureBox1->TabStop = false;
			// 
			// button10
			// 
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::White;
			this->button10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.Image")));
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(576, 0);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(36, 34);
			this->button10->TabIndex = 37;
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::White;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(534, 0);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(36, 34);
			this->button9->TabIndex = 36;
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::White;
			this->button15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.Image")));
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(492, 0);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(36, 34);
			this->button15->TabIndex = 34;
			this->button15->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::White;
			this->button11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.Image")));
			this->button11->Location = System::Drawing::Point(666, 0);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(17, 30);
			this->button11->TabIndex = 33;
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm1::button11_Click);
			// 
			// button13
			// 
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::White;
			this->button13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.Image")));
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(689, 0);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(32, 35);
			this->button13->TabIndex = 32;
			this->button13->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm1::button13_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F));
			this->label1->ForeColor = System::Drawing::Color::Maroon;
			this->label1->Location = System::Drawing::Point(46, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 20);
			this->label1->TabIndex = 39;
			this->label1->Text = L"All license reserved";
			// 
			// button14
			// 
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Century Gothic", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Maroon;
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(4, 1);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(36, 34);
			this->button14->TabIndex = 38;
			this->button14->Text = L"\?";
			this->button14->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(573, 41);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(138, 28);
			this->button4->TabIndex = 40;
			this->button4->Text = L"Clear HighLigh";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button5->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->Location = System::Drawing::Point(448, 41);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 28);
			this->button5->TabIndex = 41;
			this->button5->Text = L"High Light";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button6->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button6->Location = System::Drawing::Point(321, 41);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(109, 28);
			this->button6->TabIndex = 42;
			this->button6->Text = L"Replace All";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(106)),
				static_cast<System::Int32>(static_cast<System::Byte>(208)));
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button7->Location = System::Drawing::Point(205, 41);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(97, 28);
			this->button7->TabIndex = 43;
			this->button7->Text = L"Find";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->DownRDP);
			this->groupBox1->Controls->Add(this->UpRDP);
			this->groupBox1->Location = System::Drawing::Point(96, 51);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(225, 44);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// DownRDP
			// 
			this->DownRDP->AutoSize = true;
			this->DownRDP->Checked = true;
			this->DownRDP->Location = System::Drawing::Point(5, 28);
			this->DownRDP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DownRDP->Name = L"DownRDP";
			this->DownRDP->Size = System::Drawing::Size(53, 17);
			this->DownRDP->TabIndex = 1;
			this->DownRDP->TabStop = true;
			this->DownRDP->Text = L"Down";
			this->DownRDP->UseVisualStyleBackColor = true;
			// 
			// UpRDP
			// 
			this->UpRDP->AutoSize = true;
			this->UpRDP->Location = System::Drawing::Point(126, 28);
			this->UpRDP->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UpRDP->Name = L"UpRDP";
			this->UpRDP->Size = System::Drawing::Size(39, 17);
			this->UpRDP->TabIndex = 0;
			this->UpRDP->Text = L"Up";
			this->UpRDP->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 24);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged_2);
			// 
			// FindPnl
			// 
			this->FindPnl->Controls->Add(this->button8);
			this->FindPnl->Controls->Add(this->groupBox1);
			this->FindPnl->Controls->Add(this->button12);
			this->FindPnl->Controls->Add(this->button16);
			this->FindPnl->Controls->Add(this->textBox1);
			this->FindPnl->Location = System::Drawing::Point(12, 232);
			this->FindPnl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FindPnl->Name = L"FindPnl";
			this->FindPnl->Size = System::Drawing::Size(330, 108);
			this->FindPnl->TabIndex = 44;
			this->FindPnl->Visible = false;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(13, 49);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(64, 19);
			this->button8->TabIndex = 4;
			this->button8->Text = L"Find";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button8_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(263, 2);
			this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(64, 19);
			this->button12->TabIndex = 2;
			this->button12->Text = L"Close";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm1::button12_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(13, 74);
			this->button16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(64, 19);
			this->button16->TabIndex = 1;
			this->button16->Text = L"Find Next";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm1::button16_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(13, 24);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(199, 20);
			this->textBox3->TabIndex = 0;
			// 
			// ReplacePnl
			// 
			this->ReplacePnl->Controls->Add(this->button17);
			this->ReplacePnl->Controls->Add(this->button18);
			this->ReplacePnl->Controls->Add(this->textBox3);
			this->ReplacePnl->Location = System::Drawing::Point(353, 234);
			this->ReplacePnl->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ReplacePnl->Name = L"ReplacePnl";
			this->ReplacePnl->Size = System::Drawing::Size(330, 81);
			this->ReplacePnl->TabIndex = 21;
			this->ReplacePnl->Visible = false;
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(263, 2);
			this->button17->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(64, 19);
			this->button17->TabIndex = 2;
			this->button17->Text = L"Close";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm1::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(13, 51);
			this->button18->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(64, 19);
			this->button18->TabIndex = 1;
			this->button18->Text = L"Replace";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm1::button18_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(723, 440);
			this->Controls->Add(this->ReplacePnl);
			this->Controls->Add(this->FindPnl);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->FindPnl->ResumeLayout(false);
			this->FindPnl->PerformLayout();
			this->ReplacePnl->ResumeLayout(false);
			this->ReplacePnl->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		stac^ run = gcnew stac();
		stac^ rerun = gcnew stac();
		List<String^>^ lss = gcnew List<String^>();
		String^ s1 = "";
		bool popo = 1, popo2 = 1;
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!run->empty()) {
		if (popo2) {
			rerun->push(run->top());
			run->popp();
			popo2 = 0;
			popo = 0;
			richTextBox1->Text = run->top();
			rerun->push(run->top());
			run->popp();
			return;
		}
		popo = 0;
		richTextBox1->Text = run->top();
		rerun->push(run->top());
		run->popp();
	}
	else {
		richTextBox1->Text = "";
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!rerun->empty()) {
		while ((rerun->len1()) && richTextBox1->Text == rerun->top()) {
			run->push(rerun->top());
			rerun->popp();
		}
		popo = 0;
		popo2 = 1;
		richTextBox1->Text = rerun->top();
		run->push(rerun->top());
		rerun->popp();
	}
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void textbox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	if (popo && richTextBox1->Text != s1) {
		run->push(richTextBox1->Text);
		s1 = richTextBox1->Text;
		popo2 = 1;
	}
	popo = 1;
}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox2->Text == "") {
			MessageBox::Show("Please Enter Name to file");
			return;
		}
		lss->Clear();
		try {
			String^ fn = "user.txt";
			StreamReader^ ff = File::OpenText(fn);
			String^ str1;
			while ((str1 = ff->ReadLine()) != nullptr)
			{
				lss->Add(str1);
			}
			ff->Close();
			String^ fileName = textBox2->Text + ".txt";
			FileStream^ fs = gcnew FileStream(fileName, FileMode::Create);
			StreamWriter^ sw = gcnew StreamWriter(fs);
			sw->WriteLine(richTextBox1->Text);
			sw->Close();
			MessageBox::Show("a new file (" + fileName + " ) has been written");
			int in = lss->Count - 1;
			while (in >= 0) {
				if (textBox2->Text == lss[in]) {
					return;
				}
				in--;
			}
			String^ file = "user.txt";
			StreamWriter^ sw1 = gcnew StreamWriter(file, true);
			sw1->WriteLine(textBox2->Text);
			sw1->Close();
		}
		catch (Exception^ ex) {
			return;
		}
	}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
	Environment::Exit(0);
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	WindowState = FormWindowState::Minimized;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Clear();
	FindPnl->Visible = true;
}
private: System::Void textBox1_TextChanged_2(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox3->Clear();
	ReplacePnl->Visible = true;
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	KMP^ kmp = gcnew KMP();
	kmp->HighLight(richTextBox1->Text, richTextBox1->SelectedText, richTextBox1);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	richTextBox1->Select(0, richTextBox1->Text->Length);
	richTextBox1->SelectionBackColor = Color::White;
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	button4->PerformClick();
	KMP^ kmp = gcnew KMP();
	kmp->Find(richTextBox1->Text, textBox1->Text, richTextBox1);
	indx = kmp->ls;
	idx = 0;
	FindWordLen = textBox1->Text->Length;
	if (indx->Count == 0)
	{
		MessageBox::Show("Word Not Found!!");
	}
	else
	{
		richTextBox1->Select(indx[idx], FindWordLen);
		richTextBox1->SelectionBackColor = Color::Yellow;
	}
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	if (indx->Count == 0 || (idx + 1 >= indx->Count && DownRDP->Checked) || (idx - 1 < 0 && UpRDP->Checked)) {
		MessageBox::Show("Word Not Found!!");
	}
	else
	{
		button4->PerformClick();
		if (DownRDP->Checked)
			idx++;
		else if (UpRDP->Checked)
			idx--;
		richTextBox1->Select(indx[idx], FindWordLen);
		richTextBox1->SelectionBackColor = Color::Yellow;
	}
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	FindPnl->Visible = false;
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	KMP^ kmp = gcnew KMP();
	kmp->Replace(richTextBox1->Text, richTextBox1->SelectedText, richTextBox1, textBox3->Text);
	ReplacePnl->Visible = false;
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	ReplacePnl->Visible = false;
}
};
}
