#pragma once
#include <math.h> 

namespace Converter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	double Rate0 = 63.861;
	double Rate1 = 63.461;
	double Rate2 = 69.251;
	double Rate3 = 68.781;
	
	int SelectPos;

	int OperType = 0;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  SumLabel;
	protected: 

	private: System::Windows::Forms::TextBox^  SumConvert;
	private: System::Windows::Forms::Label^  RateLabel;
	protected: 


	private: System::Windows::Forms::TextBox^  ExchRate;
	private: System::Windows::Forms::TextBox^  To;

	private: System::Windows::Forms::TextBox^  From;
	private: System::Windows::Forms::Label^  FromLabel;
	private: System::Windows::Forms::Label^  ToLabel;




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RadioButton^  RubToDol;
	private: System::Windows::Forms::RadioButton^  DolToRub;
	private: System::Windows::Forms::RadioButton^  RubToEur;
	private: System::Windows::Forms::RadioButton^  EurToRub;
	private: System::Windows::Forms::Label^  WarnText;











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
			this->SumLabel = (gcnew System::Windows::Forms::Label());
			this->SumConvert = (gcnew System::Windows::Forms::TextBox());
			this->RateLabel = (gcnew System::Windows::Forms::Label());
			this->ExchRate = (gcnew System::Windows::Forms::TextBox());
			this->To = (gcnew System::Windows::Forms::TextBox());
			this->From = (gcnew System::Windows::Forms::TextBox());
			this->FromLabel = (gcnew System::Windows::Forms::Label());
			this->ToLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->RubToDol = (gcnew System::Windows::Forms::RadioButton());
			this->DolToRub = (gcnew System::Windows::Forms::RadioButton());
			this->RubToEur = (gcnew System::Windows::Forms::RadioButton());
			this->EurToRub = (gcnew System::Windows::Forms::RadioButton());
			this->WarnText = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// SumLabel
			// 
			this->SumLabel->AutoSize = true;
			this->SumLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->SumLabel->ForeColor = System::Drawing::Color::Black;
			this->SumLabel->Location = System::Drawing::Point(12, 9);
			this->SumLabel->Name = L"SumLabel";
			this->SumLabel->Size = System::Drawing::Size(185, 20);
			this->SumLabel->TabIndex = 0;
			this->SumLabel->Text = L"Сумма для конвертации:";
			// 
			// SumConvert
			// 
			this->SumConvert->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SumConvert->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
			this->SumConvert->Location = System::Drawing::Point(227, 7);
			this->SumConvert->Name = L"SumConvert";
			this->SumConvert->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->SumConvert->Size = System::Drawing::Size(117, 22);
			this->SumConvert->TabIndex = 1;
			this->SumConvert->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->SumConvert->TextChanged += gcnew System::EventHandler(this, &Form1::SumConvert_TextChanged);
			// 
			// RateLabel
			// 
			this->RateLabel->AutoSize = true;
			this->RateLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->RateLabel->ForeColor = System::Drawing::Color::Black;
			this->RateLabel->Location = System::Drawing::Point(15, 69);
			this->RateLabel->Name = L"RateLabel";
			this->RateLabel->Size = System::Drawing::Size(182, 20);
			this->RateLabel->TabIndex = 2;
			this->RateLabel->Text = L"Курс покупки за 1 USD =";
			// 
			// ExchRate
			// 
			this->ExchRate->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ExchRate->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
			this->ExchRate->Location = System::Drawing::Point(227, 67);
			this->ExchRate->Name = L"ExchRate";
			this->ExchRate->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ExchRate->Size = System::Drawing::Size(117, 22);
			this->ExchRate->TabIndex = 3;
			this->ExchRate->Text = L"63,86";
			this->ExchRate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->ExchRate->TextChanged += gcnew System::EventHandler(this, &Form1::ExchRate_TextChanged);
			// 
			// To
			// 
			this->To->BackColor = System::Drawing::Color::White;
			this->To->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->To->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
			this->To->Location = System::Drawing::Point(227, 130);
			this->To->Name = L"To";
			this->To->ReadOnly = true;
			this->To->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->To->Size = System::Drawing::Size(117, 22);
			this->To->TabIndex = 4;
			this->To->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// From
			// 
			this->From->BackColor = System::Drawing::Color::White;
			this->From->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->From->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.5F, System::Drawing::FontStyle::Bold));
			this->From->Location = System::Drawing::Point(22, 127);
			this->From->Name = L"From";
			this->From->ReadOnly = true;
			this->From->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->From->Size = System::Drawing::Size(117, 22);
			this->From->TabIndex = 5;
			this->From->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// FromLabel
			// 
			this->FromLabel->AutoSize = true;
			this->FromLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->FromLabel->ForeColor = System::Drawing::Color::Black;
			this->FromLabel->Location = System::Drawing::Point(145, 129);
			this->FromLabel->Name = L"FromLabel";
			this->FromLabel->Size = System::Drawing::Size(52, 20);
			this->FromLabel->TabIndex = 6;
			this->FromLabel->Text = L"RUB =";
			// 
			// ToLabel
			// 
			this->ToLabel->AutoSize = true;
			this->ToLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->ToLabel->ForeColor = System::Drawing::Color::Black;
			this->ToLabel->Location = System::Drawing::Point(350, 133);
			this->ToLabel->Name = L"ToLabel";
			this->ToLabel->Size = System::Drawing::Size(39, 20);
			this->ToLabel->TabIndex = 7;
			this->ToLabel->Text = L"USD";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(19, 184);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 50);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Конвертировать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(227, 184);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 50);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// RubToDol
			// 
			this->RubToDol->AutoSize = true;
			this->RubToDol->BackColor = System::Drawing::Color::Brown;
			this->RubToDol->Checked = true;
			this->RubToDol->Cursor = System::Windows::Forms::Cursors::Hand;
			this->RubToDol->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->RubToDol->FlatAppearance->BorderSize = 12;
			this->RubToDol->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->RubToDol->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->RubToDol->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->RubToDol->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->RubToDol->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->RubToDol->ForeColor = System::Drawing::Color::White;
			this->RubToDol->Location = System::Drawing::Point(426, 74);
			this->RubToDol->Name = L"RubToDol";
			this->RubToDol->Size = System::Drawing::Size(156, 25);
			this->RubToDol->TabIndex = 10;
			this->RubToDol->TabStop = true;
			this->RubToDol->Text = L"Рубли в Доллары";
			this->RubToDol->UseVisualStyleBackColor = false;
			this->RubToDol->CheckedChanged += gcnew System::EventHandler(this, &Form1::RubToDol_CheckedChanged);
			// 
			// DolToRub
			// 
			this->DolToRub->AutoSize = true;
			this->DolToRub->BackColor = System::Drawing::Color::Brown;
			this->DolToRub->Cursor = System::Windows::Forms::Cursors::Hand;
			this->DolToRub->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveBorder;
			this->DolToRub->FlatAppearance->BorderSize = 12;
			this->DolToRub->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->DolToRub->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->DolToRub->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->DolToRub->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->DolToRub->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->DolToRub->ForeColor = System::Drawing::Color::White;
			this->DolToRub->Location = System::Drawing::Point(426, 12);
			this->DolToRub->Name = L"DolToRub";
			this->DolToRub->Size = System::Drawing::Size(156, 25);
			this->DolToRub->TabIndex = 11;
			this->DolToRub->Text = L"Доллары в Рубли";
			this->DolToRub->UseVisualStyleBackColor = false;
			this->DolToRub->CheckedChanged += gcnew System::EventHandler(this, &Form1::DolToRub_CheckedChanged);
			// 
			// RubToEur
			// 
			this->RubToEur->AutoSize = true;
			this->RubToEur->BackColor = System::Drawing::Color::Brown;
			this->RubToEur->Cursor = System::Windows::Forms::Cursors::Hand;
			this->RubToEur->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveBorder;
			this->RubToEur->FlatAppearance->BorderSize = 12;
			this->RubToEur->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->RubToEur->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->RubToEur->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->RubToEur->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->RubToEur->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->RubToEur->ForeColor = System::Drawing::Color::White;
			this->RubToEur->Location = System::Drawing::Point(456, 198);
			this->RubToEur->Name = L"RubToEur";
			this->RubToEur->Size = System::Drawing::Size(126, 25);
			this->RubToEur->TabIndex = 12;
			this->RubToEur->Text = L"Рубли в Евро";
			this->RubToEur->UseVisualStyleBackColor = false;
			this->RubToEur->CheckedChanged += gcnew System::EventHandler(this, &Form1::RubToEur_CheckedChanged);
			// 
			// EurToRub
			// 
			this->EurToRub->AutoSize = true;
			this->EurToRub->BackColor = System::Drawing::Color::Brown;
			this->EurToRub->Cursor = System::Windows::Forms::Cursors::Hand;
			this->EurToRub->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveBorder;
			this->EurToRub->FlatAppearance->BorderSize = 12;
			this->EurToRub->FlatAppearance->CheckedBackColor = System::Drawing::Color::Red;
			this->EurToRub->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Blue;
			this->EurToRub->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->EurToRub->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->EurToRub->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->EurToRub->ForeColor = System::Drawing::Color::White;
			this->EurToRub->Location = System::Drawing::Point(456, 136);
			this->EurToRub->Name = L"EurToRub";
			this->EurToRub->Size = System::Drawing::Size(126, 25);
			this->EurToRub->TabIndex = 13;
			this->EurToRub->Text = L"Евро в Рубли";
			this->EurToRub->UseVisualStyleBackColor = false;
			this->EurToRub->CheckedChanged += gcnew System::EventHandler(this, &Form1::EurToRub_CheckedChanged);
			// 
			// WarnText
			// 
			this->WarnText->AutoSize = true;
			this->WarnText->Cursor = System::Windows::Forms::Cursors::No;
			this->WarnText->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->WarnText->Location = System::Drawing::Point(18, 249);
			this->WarnText->Name = L"WarnText";
			this->WarnText->Size = System::Drawing::Size(0, 20);
			this->WarnText->TabIndex = 14;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Silver;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(594, 315);
			this->Controls->Add(this->WarnText);
			this->Controls->Add(this->EurToRub);
			this->Controls->Add(this->RubToEur);
			this->Controls->Add(this->DolToRub);
			this->Controls->Add(this->RubToDol);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ToLabel);
			this->Controls->Add(this->From);
			this->Controls->Add(this->To);
			this->Controls->Add(this->ExchRate);
			this->Controls->Add(this->RateLabel);
			this->Controls->Add(this->SumConvert);
			this->Controls->Add(this->SumLabel);
			this->Controls->Add(this->FromLabel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"АРМ оператора обменного пункта";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
private: System::Void RubToDol_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 OperType = 0;
			 RateLabel->Text = Convert::ToString("Курс покупки за 1 USD =");
			 FromLabel->Text = Convert::ToString("RUB =");
			 ToLabel->Text = Convert::ToString("USD");
			 ExchRate->Text = Convert::ToString(Rate0)->Substring(0,Convert::ToString(Rate0)->Length-1);
			 if (SumConvert->Text->Length > 0){
				SumConvert->Text = Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Substring(0,Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Length-1);
			 }
			 From->Text = "";
			 To->Text = "";
			 WarnText->Text = "";
			 SumConvert->Text = "";
		 }
private: System::Void DolToRub_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 OperType = 1;
			 RateLabel->Text = Convert::ToString("Курс продажи за 1 USD =");
			 FromLabel->Text = Convert::ToString("USD =");
			 ToLabel->Text = Convert::ToString("RUB");
			 ExchRate->Text = Convert::ToString(Rate1)->Substring(0,Convert::ToString(Rate1)->Length-1);
			 if (SumConvert->Text->Length > 0){
				SumConvert->Text = Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Substring(0,Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Length-1);
			 }
			 From->Text = "";
			 To->Text = "";
			 WarnText->Text = "";
			 SumConvert->Text = "";
		 }
private: System::Void RubToEur_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 OperType = 2;
			 RateLabel->Text = Convert::ToString("Курс покупки за 1 EUR =");
			 FromLabel->Text = Convert::ToString("RUB =");
			 ToLabel->Text = Convert::ToString("EUR");
			 ExchRate->Text = Convert::ToString(Rate2)->Substring(0,Convert::ToString(Rate2)->Length-1);
			 if (SumConvert->Text->Length > 0){
				SumConvert->Text = Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Substring(0,Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Length-1);
			 }
			 From->Text = "";
			 To->Text = "";
			 WarnText->Text = "";
			 SumConvert->Text = "";

		 }
private: System::Void EurToRub_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 OperType = 3;
			 RateLabel->Text = Convert::ToString("Курс продажи за 1 EUR =");
			 FromLabel->Text = Convert::ToString("EUR =");
			 ToLabel->Text = Convert::ToString("RUB");
			 ExchRate->Text = Convert::ToString(Rate3)->Substring(0,Convert::ToString(Rate3)->Length-1);
			 if (SumConvert->Text->Length > 0){
				SumConvert->Text = Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Substring(0,Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Length-1);
			 }
			 From->Text = "";
			 To->Text = "";
			 WarnText->Text = "";
			 SumConvert->Text = "";
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 From->Text = "";
			 To->Text = "";
			 WarnText->Text = "";
			 if (SumConvert->Text->Length > 0){
				SumConvert->Text = Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Substring(0,Convert::ToString(Convert::ToDouble(SumConvert->Text)+0.001)->Length-1);
			 }
			 switch(OperType){
					case 0: 
						ExchRate->Text = Convert::ToString(Rate0)->Substring(0,Convert::ToString(Rate0)->Length-1);
						try {From->Text = SumConvert->Text;
						To->Text = Convert::ToString(floor(Convert::ToSingle(SumConvert->Text)/Convert::ToDouble(ExchRate->Text)*100)/100); }
						 catch(...){WarnText->Text = L"Ошибка: Проверьте корректность\nвводимых значений."; return;}
						 return;
					case 1:
						ExchRate->Text = Convert::ToString(Rate1)->Substring(0,Convert::ToString(Rate1)->Length-1);
						 try { From->Text = SumConvert->Text;
						 To->Text = Convert::ToString(floor(Convert::ToSingle(SumConvert->Text)*Convert::ToDouble(ExchRate->Text)*100)/100); }
						 catch(...){WarnText->Text = L"Ошибка: Проверьте корректность\nвводимых значений."; return;}
						 return;
					case 2:
						ExchRate->Text = Convert::ToString(Rate2)->Substring(0,Convert::ToString(Rate2)->Length-1);
						 try {From->Text = SumConvert->Text;
						 To->Text = Convert::ToString(floor(Convert::ToSingle(SumConvert->Text)/Convert::ToDouble(ExchRate->Text)*100)/100); }
						 catch(...){WarnText->Text = L"Ошибка: Проверьте корректность\nвводимых значений."; return;}
						 return;
					case 3: 
						ExchRate->Text = Convert::ToString(Rate3)->Substring(0,Convert::ToString(Rate3)->Length-1);
						try { From->Text = SumConvert->Text;
						To->Text = Convert::ToString(floor(Convert::ToSingle(SumConvert->Text)*Convert::ToDouble(ExchRate->Text)*100)/100); }
						catch(...){WarnText->Text = L"Ошибка: Проверьте корректность\nвводимых значений."; return;}
						return;
				 }
		 }
private: System::Void SumConvert_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 WarnText->Text = "";
			 if (SumConvert->Text->Length > 0){
				 if (SumConvert->SelectionStart != 0) {
				 SelectPos = SumConvert->SelectionStart; //Обновляем позицию курсора
				 }
				 if ((SumConvert->Text->IndexOf(",") >= 0)&&(SumConvert->Text->Substring(SumConvert->Text->IndexOf(","))->Length > 3)){
					 SumConvert->Text = SumConvert->Text->Remove(SumConvert->SelectionStart-1,1);
					 SumConvert->SelectionStart = SelectPos-1;
				 }
				 try {
					 Convert::ToDouble(SumConvert->Text);
				 } catch(...){
					 SumConvert->Text = SumConvert->Text->Remove(SumConvert->SelectionStart-1,1);
					 SumConvert->SelectionStart = SelectPos-1;
				 }
			 }
		 }
private: System::Void ExchRate_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 WarnText->Text = "";
			 if (ExchRate->Text->Length > 0){
				 if (ExchRate->SelectionStart != 0) {
				 SelectPos = ExchRate->SelectionStart; //Обновляем позицию курсора
				 }
				 if ((ExchRate->Text->IndexOf(",") >= 0)&&(ExchRate->Text->Substring(ExchRate->Text->IndexOf(","))->Length > 3)){
					 ExchRate->Text = ExchRate->Text->Remove(ExchRate->SelectionStart-1,1);
					 ExchRate->SelectionStart = SelectPos-1;
				 }
				 try {
					 Convert::ToDouble(ExchRate->Text);
				 } catch(...){
					 ExchRate->Text = ExchRate->Text->Remove(ExchRate->SelectionStart-1,1);
					 ExchRate->SelectionStart = SelectPos-1;
				 }
			 }
			  switch(OperType){
					case 0: 
						if (ExchRate->Text->Length > 0){
						 try {Rate0 = Convert::ToDouble(ExchRate->Text) + 0.001;}
						 catch(...){}
						 return;
						}
					case 1:
						if (ExchRate->Text->Length > 0){
						 try {Rate1 = Convert::ToDouble(ExchRate->Text) + 0.001;}
						 catch(...){}
						 return;
						}
					case 2:
						if (ExchRate->Text->Length > 0){
						 try {Rate2 = Convert::ToDouble(ExchRate->Text) + 0.001;}
						 catch(...){}
						 return;
						}
					case 3: 
						if (ExchRate->Text->Length > 0){
						 try {Rate3 = Convert::ToDouble(ExchRate->Text) + 0.001;}
						 catch(...){}
						 return;
						}
				 }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
};
}

