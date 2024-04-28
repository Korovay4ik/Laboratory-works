#pragma once

namespace Ferz 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для First
	/// </summary>
	public ref class First : public System::Windows::Forms::Form
	{
	private: static array <PictureBox^, 1>^ Pictures;
	public: static int delay;

	public: First(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~First()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ but_exit;
	private: System::Windows::Forms::Button^ but_start;
	private: System::Windows::Forms::TextBox^ textBox_delay;


	private: System::Windows::Forms::Label^ label;

	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(First::typeid));
			this->but_exit = (gcnew System::Windows::Forms::Button());
			this->but_start = (gcnew System::Windows::Forms::Button());
			this->textBox_delay = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// but_exit
			// 
			this->but_exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(209)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->but_exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->but_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->but_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->but_exit->ForeColor = System::Drawing::Color::White;
			this->but_exit->Location = System::Drawing::Point(600, -1);
			this->but_exit->Name = L"but_exit";
			this->but_exit->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->but_exit->Size = System::Drawing::Size(26, 23);
			this->but_exit->TabIndex = 0;
			this->but_exit->Text = L"X";
			this->but_exit->UseVisualStyleBackColor = false;
			this->but_exit->Click += gcnew System::EventHandler(this, &First::exit_Click);
			// 
			// but_start
			// 
			this->but_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->but_start->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->but_start->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"but_start.Image")));
			this->but_start->Location = System::Drawing::Point(569, 567);
			this->but_start->Name = L"but_start";
			this->but_start->Size = System::Drawing::Size(57, 57);
			this->but_start->TabIndex = 3;
			this->but_start->UseVisualStyleBackColor = true;
			this->but_start->Click += gcnew System::EventHandler(this, &First::but_start_Click);
			// 
			// textBox_delay
			// 
			this->textBox_delay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_delay->Location = System::Drawing::Point(482, 600);
			this->textBox_delay->Name = L"textBox_delay";
			this->textBox_delay->Size = System::Drawing::Size(60, 26);
			this->textBox_delay->TabIndex = 4;
			this->textBox_delay->Text = L"300";
			this->textBox_delay->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->BackColor = System::Drawing::Color::Transparent;
			this->label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label->Location = System::Drawing::Point(353, 600);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(123, 20);
			this->label->TabIndex = 5;
			this->label->Text = L"Задержка (мс):";
			// 
			// First
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(626, 626);
			this->Controls->Add(this->label);
			this->Controls->Add(this->textBox_delay);
			this->Controls->Add(this->but_exit);
			this->Controls->Add(this->but_start);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"First";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"8 Ферзей";
			this->Load += gcnew System::EventHandler(this, &First::First_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void First_Load(System::Object^ sender, System::EventArgs^ e) {
		Pictures = gcnew array <PictureBox^, 1>(64);
		for (int i = 0; i < 64; i++)
		{
			Pictures[i] = gcnew PictureBox;
			Pictures[i]->BackColor = System::Drawing::Color::Transparent;
			Pictures[i]->Location = System::Drawing::Point(62 * ((i % 8) + 1), 63 * ((i / 8) + 1));
			Pictures[i]->Size = System::Drawing::Size(66, 66);
			Controls->Add(this->Pictures[i]);
		}
	}
	public: System::Void Delay()
	{
		if (textBox_delay->Text == "") textBox_delay->Text = "0";
		this->delay = Convert::ToInt32(textBox_delay->Text);
	}
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void but_start_Click(System::Object^ sender, System::EventArgs^ e);
	public: static System::Void print();
};
}