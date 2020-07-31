#pragma once
#include "state.h"

namespace USPandemicTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(State stateObject)
		{
			InitializeComponent();
			InitializeGraph(stateObject);
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(11, 11);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Data";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(422, 360);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 382);
			this->Controls->Add(this->chart1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
		void InitializeGraph(State stateObject) {
			int* arr;

			chart1->ChartAreas["ChartArea1"]->AxisX->Title = "DAYS SINCE JAN 21, 2020";

			if (stateObject.getDataName() == "DAILY NEW CASES") {
				chart1->ChartAreas["ChartArea1"]->AxisY->Title = "REPORTED CASES PER DAY";
				this->Text = "DAILY NEW CASES";
				arr = stateObject.getDailyCases();
				for (int i; i < stateObject.getDays(); i++) {
					chart1->Series["Data"]->Points->AddXY("", arr[i]);
				}
			}
			else if (stateObject.getDataName() == "DAILY NEW DEATHS") {
				chart1->ChartAreas["ChartArea1"]->AxisY->Title = "REPORTED DEATHS PER DAY";
				this->Text = "DAILY NEW DEATHS";
				arr = stateObject.getDailyDeaths();
				for (int i; i < stateObject.getDays(); i++) {
					chart1->Series["Data"]->Points->AddXY("", arr[i]);
				}
			}

			else if (stateObject.getDataName() == "ACTIVE CASES") {
				chart1->ChartAreas["ChartArea1"]->AxisY->Title = "ACTIVE CASES BY DAY (30 DAYS ONSET)";
				this->Text = "ACTIVE CASES";
				arr = stateObject.getActiveCases();
				for (int i; i < stateObject.getDays(); i++) {
					chart1->Series["Data"]->Points->AddXY("", arr[i]);
				}
			} 


		}
#pragma endregion
	};
}
