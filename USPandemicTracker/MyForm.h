#pragma once
#include <Windows.h>
#include "state.h"
#include <msclr/marshal_cppstd.h>
#include "MyForm1.h"

namespace USPandemicTracker {

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
			statPanel->Hide();
			stateComboBox->SelectedIndex = 0;
			dataComboBox->SelectedIndex = 0;
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
	private: System::Windows::Forms::Label^ titleLabel;
	private: System::Windows::Forms::ComboBox^ stateComboBox;
	protected:

	protected:

	private: System::Windows::Forms::Label^ stateLabel;

	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::ComboBox^ dataComboBox;
	private: System::Windows::Forms::Button^ statButton;
	private: System::Windows::Forms::Panel^ statPanel;
	private: System::Windows::Forms::TextBox^ statTextBox;
	private: System::Windows::Forms::Button^ graphButton;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->titleLabel = (gcnew System::Windows::Forms::Label());
			this->stateComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->stateLabel = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->dataComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->statButton = (gcnew System::Windows::Forms::Button());
			this->statPanel = (gcnew System::Windows::Forms::Panel());
			this->statTextBox = (gcnew System::Windows::Forms::TextBox());
			this->graphButton = (gcnew System::Windows::Forms::Button());
			this->statPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// titleLabel
			// 
			this->titleLabel->AutoSize = true;
			this->titleLabel->BackColor = System::Drawing::Color::Transparent;
			this->titleLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->titleLabel->Location = System::Drawing::Point(240, 74);
			this->titleLabel->Name = L"titleLabel";
			this->titleLabel->Size = System::Drawing::Size(330, 37);
			this->titleLabel->TabIndex = 0;
			this->titleLabel->Text = L"US Pandemic Tracker";
			// 
			// stateComboBox
			// 
			this->stateComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::Simple;
			this->stateComboBox->FormattingEnabled = true;
			this->stateComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(50) {
				L"ALABAMA", L"ALASKA", L"ARIZONA", L"ARKANSAS",
					L"CALIFORNIA", L"COLORADO", L"CONNECTICUT", L"DELAWARE", L"FLORIDA", L"GEORGIA", L"HAWAII", L"IDAHO", L"ILLINOIS", L"INDIANA",
					L"IOWA", L"KANSAS", L"KENTUCKY", L"LOUISIANA", L"MAINE", L"MARYLAND", L"MASSACHUSETTS", L"MICHIGAN", L"MINNESOTA", L"MISSISSIPPI",
					L"MISSOURI", L"MONTANA", L"NEBRASKA", L"NEVADA", L"NEW HAMPSHIRE", L"NEW JERSEY", L"NEW MEXICO", L"NEW YORK", L"NORTH CAROLINA",
					L"NORTH DAKOTA", L"OHIO", L"OKLAHOMA", L"OREGON", L"PENNSYLVANIA", L"RHODE ISLAND", L"SOUTH CAROLINA", L"SOUTH DAKOTA", L"TENNESSEE",
					L"TEXAS", L"UTAH", L"VERMONT", L"VIRGINIA", L"WASHINGTON", L"WEST VIRGINIA", L"WISCONSIN", L"WYOMING"
			});
			this->stateComboBox->Location = System::Drawing::Point(257, 159);
			this->stateComboBox->Name = L"stateComboBox";
			this->stateComboBox->Size = System::Drawing::Size(121, 150);
			this->stateComboBox->TabIndex = 1;
			// 
			// stateLabel
			// 
			this->stateLabel->AutoSize = true;
			this->stateLabel->BackColor = System::Drawing::Color::Transparent;
			this->stateLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateLabel->Location = System::Drawing::Point(280, 131);
			this->stateLabel->Name = L"stateLabel";
			this->stateLabel->Size = System::Drawing::Size(62, 25);
			this->stateLabel->TabIndex = 2;
			this->stateLabel->Text = L"State";
			// 
			// dataLabel
			// 
			this->dataLabel->AutoSize = true;
			this->dataLabel->BackColor = System::Drawing::Color::Transparent;
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dataLabel->Location = System::Drawing::Point(435, 131);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(95, 25);
			this->dataLabel->TabIndex = 3;
			this->dataLabel->Text = L"Data Set";
			// 
			// dataComboBox
			// 
			this->dataComboBox->BackColor = System::Drawing::Color::White;
			this->dataComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::Simple;
			this->dataComboBox->ForeColor = System::Drawing::Color::Black;
			this->dataComboBox->FormattingEnabled = true;
			this->dataComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"DAILY NEW CASES", L"DAILY NEW DEATHS", L"TOTAL CASES",
					L"TOTAL DEATHS", L"ACTIVE CASES"
			});
			this->dataComboBox->Location = System::Drawing::Point(423, 159);
			this->dataComboBox->Name = L"dataComboBox";
			this->dataComboBox->Size = System::Drawing::Size(121, 150);
			this->dataComboBox->TabIndex = 4;
			// 
			// statButton
			// 
			this->statButton->BackColor = System::Drawing::Color::Transparent;
			this->statButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->statButton->Location = System::Drawing::Point(223, 331);
			this->statButton->Name = L"statButton";
			this->statButton->Size = System::Drawing::Size(155, 39);
			this->statButton->TabIndex = 5;
			this->statButton->Text = L"Get Statistics";
			this->statButton->UseVisualStyleBackColor = false;
			this->statButton->Click += gcnew System::EventHandler(this, &MyForm::statButton_Click);
			// 
			// statPanel
			// 
			this->statPanel->BackColor = System::Drawing::Color::Transparent;
			this->statPanel->Controls->Add(this->statTextBox);
			this->statPanel->Location = System::Drawing::Point(200, 388);
			this->statPanel->Name = L"statPanel";
			this->statPanel->Size = System::Drawing::Size(390, 195);
			this->statPanel->TabIndex = 6;
			// 
			// statTextBox
			// 
			this->statTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->statTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->statTextBox->Location = System::Drawing::Point(6, 0);
			this->statTextBox->Multiline = true;
			this->statTextBox->Name = L"statTextBox";
			this->statTextBox->ReadOnly = true;
			this->statTextBox->Size = System::Drawing::Size(384, 174);
			this->statTextBox->TabIndex = 0;
			// 
			// graphButton
			// 
			this->graphButton->BackColor = System::Drawing::Color::Transparent;
			this->graphButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->graphButton->Location = System::Drawing::Point(415, 331);
			this->graphButton->Name = L"graphButton";
			this->graphButton->Size = System::Drawing::Size(155, 39);
			this->graphButton->TabIndex = 7;
			this->graphButton->Text = L"Get Graph";
			this->graphButton->UseVisualStyleBackColor = false;
			this->graphButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(844, 605);
			this->Controls->Add(this->graphButton);
			this->Controls->Add(this->statPanel);
			this->Controls->Add(this->statButton);
			this->Controls->Add(this->dataComboBox);
			this->Controls->Add(this->dataLabel);
			this->Controls->Add(this->stateLabel);
			this->Controls->Add(this->stateComboBox);
			this->Controls->Add(this->titleLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->statPanel->ResumeLayout(false);
			this->statPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void statButton_Click(System::Object^ sender, System::EventArgs^ e) {
		statPanel->Show();
		statTextBox->Clear();

		std::string state = msclr::interop::marshal_as<std::string>(stateComboBox->Text);
		std::string data = msclr::interop::marshal_as<std::string>(dataComboBox->Text);

		State stateObject(state, data);
		std::string line1;
		std::string line2;
		std::string line3;
		std::string* ptr1 = &line1;
		std::string* ptr2 = &line2;
		std::string* ptr3 = &line3;
		stateObject.getStateData(ptr1, ptr2, ptr3);

		String^ s1 = gcnew System::String(line1.c_str());
		String^ s2 = gcnew System::String(line2.c_str());
		String^ s3 = gcnew System::String(line3.c_str());

		statTextBox->Text = s1;
		statTextBox->Text += "\r\n" + s2;
		statTextBox->Text += "\r\n" + s3;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string state = msclr::interop::marshal_as<std::string>(stateComboBox->Text);
		std::string data = msclr::interop::marshal_as<std::string>(dataComboBox->Text);
		State stateObject(state, data);
		if (stateObject.getDataName() == "DAILY NEW CASES" || 
			stateObject.getDataName() == "DAILY NEW DEATHS") {
			MyForm1^ form1 = gcnew MyForm1(stateObject);
			form1->Show();
		}
		else {
			MessageBox::Show(" A Graph is not available for this data set.");
		}
	}
};
}
