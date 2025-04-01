#pragma once
#include <msclr/marshal_cppstd.h>
#include "Polinom.h"
namespace VisualPolinom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		int size = 10;
		int i = 0;
		Polinom* polinoms;
	public:
		MyForm(void)
		{
			InitializeComponent();
			polinoms = new Polinom[size];
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ execButton;
	private: System::Windows::Forms::ComboBox^ operationBox;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::ListBox^ listPolinoms;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ num1;
	private: System::Windows::Forms::TextBox^ num2;


	private: System::Windows::Forms::TextBox^ inputPolinom;
	private: System::Windows::Forms::Button^ addPolinom;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->execButton = (gcnew System::Windows::Forms::Button());
			this->operationBox = (gcnew System::Windows::Forms::ComboBox());
			this->listPolinoms = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->num1 = (gcnew System::Windows::Forms::TextBox());
			this->num2 = (gcnew System::Windows::Forms::TextBox());
			this->inputPolinom = (gcnew System::Windows::Forms::TextBox());
			this->addPolinom = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// execButton
			// 
			this->execButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->execButton->Location = System::Drawing::Point(1106, 30);
			this->execButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->execButton->Name = L"execButton";
			this->execButton->Size = System::Drawing::Size(106, 33);
			this->execButton->TabIndex = 0;
			this->execButton->Text = L"Calculate";
			this->execButton->UseVisualStyleBackColor = true;
			this->execButton->Click += gcnew System::EventHandler(this, &MyForm::execButton_Click);
			// 
			// operationBox
			// 
			this->operationBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->operationBox->FormattingEnabled = true;
			this->operationBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"+", L"-", L"*" });
			this->operationBox->Location = System::Drawing::Point(972, 33);
			this->operationBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->operationBox->Name = L"operationBox";
			this->operationBox->Size = System::Drawing::Size(54, 33);
			this->operationBox->TabIndex = 1;
			// 
			// listPolinoms
			// 
			this->listPolinoms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->listPolinoms->FormattingEnabled = true;
			this->listPolinoms->ItemHeight = 20;
			this->listPolinoms->Location = System::Drawing::Point(11, 90);
			this->listPolinoms->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->listPolinoms->Name = L"listPolinoms";
			this->listPolinoms->Size = System::Drawing::Size(1201, 664);
			this->listPolinoms->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(901, 11);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"1 Term";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(1040, 11);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"2 Term";
			// 
			// num1
			// 
			this->num1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->num1->Location = System::Drawing::Point(905, 33);
			this->num1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->num1->Name = L"num1";
			this->num1->Size = System::Drawing::Size(54, 30);
			this->num1->TabIndex = 5;
			// 
			// num2
			// 
			this->num2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->num2->Location = System::Drawing::Point(1044, 33);
			this->num2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->num2->Name = L"num2";
			this->num2->Size = System::Drawing::Size(54, 30);
			this->num2->TabIndex = 6;
			// 
			// inputPolinom
			// 
			this->inputPolinom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->inputPolinom->Location = System::Drawing::Point(11, 33);
			this->inputPolinom->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->inputPolinom->Name = L"inputPolinom";
			this->inputPolinom->Size = System::Drawing::Size(745, 27);
			this->inputPolinom->TabIndex = 7;
			// 
			// addPolinom
			// 
			this->addPolinom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->addPolinom->Location = System::Drawing::Point(774, 35);
			this->addPolinom->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->addPolinom->Name = L"addPolinom";
			this->addPolinom->Size = System::Drawing::Size(106, 30);
			this->addPolinom->TabIndex = 8;
			this->addPolinom->Text = L"Add";
			this->addPolinom->UseVisualStyleBackColor = true;
			this->addPolinom->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1223, 775);
			this->Controls->Add(this->addPolinom);
			this->Controls->Add(this->inputPolinom);
			this->Controls->Add(this->num2);
			this->Controls->Add(this->num1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listPolinoms);
			this->Controls->Add(this->operationBox);
			this->Controls->Add(this->execButton);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (inputPolinom->Text->ToString() != "") {
			if (i >= size) {
				MessageBox::Show("Достигнут максимум полиномов!", "Ошибка");
				return;
			}

			System::String^ inputStr = inputPolinom->Text;
			Polinom polinom;
			std::string nativeStr = msclr::interop::marshal_as<std::string>(inputStr);
			polinom.FromString(nativeStr);

			polinoms[i] = polinom;
			i++;

			std::string output = polinom.ToString();
			System::String^ managedString = msclr::interop::marshal_as<System::String^>(output);

			listPolinoms->Items->Add(String::Format("{0}. {1}", i, managedString));
			inputPolinom->Text = "";
		}
	}

	private: System::Void execButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string operation = msclr::interop::marshal_as<std::string>(operationBox->Text);

		int p1, p2;
		p1 = System::Int32::Parse(num1->Text);
		p2 = System::Int32::Parse(num2->Text);

		Polinom pol1, pol2, res;
		pol1 = polinoms[p1 - 1];
		pol2 = polinoms[p2 - 1];

		if (operation == "+") {
			res = pol1 + pol2;
		}
		else if (operation == "-") {
			res = pol1 - pol2;
		}
		else if (operation == "*") {
			res = pol1 * pol2;
		}
		Polinom nul;
		if (res != nul)
			polinoms[i] = res;
			i++;
			std::string output = res.ToString();
			System::String^ managedString = msclr::interop::marshal_as<System::String^>(output);

			listPolinoms->Items->Add(managedString);
		}
		
		

		
	};
	
}

