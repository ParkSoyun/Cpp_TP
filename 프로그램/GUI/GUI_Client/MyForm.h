#pragma once

namespace GUIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ClassLibrary1;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Runtime::Serialization::Formatters;
	using namespace System::Threading;

	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  mainTextBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	protected:

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->mainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"���� ���� B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"IP �ּ�";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"���� ���� M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->Location = System::Drawing::Point(77, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 28);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"���� ����� 230", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->mainTextBox->Location = System::Drawing::Point(12, 58);
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(364, 441);
			this->mainTextBox->TabIndex = 5;
			this->mainTextBox->Text = L"";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"���� ���� B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(301, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 31);
			this->button1->TabIndex = 4;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"���� ���� M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox2->Location = System::Drawing::Point(12, 524);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(281, 28);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"���� ���� B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->Location = System::Drawing::Point(301, 524);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 31);
			this->button2->TabIndex = 4;
			this->button2->Text = L"����";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 564);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ���� �ؽ�Ʈ �ڽ� Ŭ�� �� ���� �Ұ����ϰ� ����
	private: System::Void mainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = true;
	}
			 // ����� ���� ���� ����
	public: Socket^ client;
	public: IPEndPoint^ IP;
	public: Thread^ clientThread;

			// ���α׷��� �ε�(Load) �Ǹ� ����Ǵ� �̺�Ʈ
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		// ������ �ʱ�ȭ
		client = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			 // �������� ���� ��ư �̺�Ʈ
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// �ش� ������ 2016 ��Ʈ�� ����
		try {
			IP = gcnew IPEndPoint(IPAddress::Parse(textBox1->Text), 2016);
			client->Connect(IP);

			// backgroundWorker1 �̺�Ʈ ����
			backgroundWorker1->RunWorkerAsync();
		}

		// ������ �߻��� ���
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

			 // backgroundWorker1 �̺�Ʈ ����
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// ������������ ���� �޽����� �ݺ������� ����
		while (true)
		{

			// �޽����� ���ۿ� ����
			array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
			int temp = client->Receive(buf);
			ClassLibrary1::StructChat^ str = gcnew ClassLibrary1::StructChat();

			// ���۷� �Ѿ�� �����͸� ClassLibrary1::StructChat ��ü�� str�� ��ȯ�� �ؽ�Ʈ�� ������
			str = Deserialize(buf);
			addTextToMainTextBox(str->textChat, str->myFont, str->myColor);
		}
	}

			 // �ؽ�Ʈ�� �߰��ϴ� �Լ� addText()
	private: void addTextToMainTextBox(String^ text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{

		// ���� �ؽ�Ʈ �ڽ��� �ش� ���ڿ��� ������
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(text + "\n");
		mainTextBox->ScrollToCaret();
	}

			 // MemoryStream�� BinaryFormatter�� �̿��� ClassLibrary1::StructChat�� ���ڿ� ���¸� ���� ���·� ��ȯ�ϰ� �ٽ� ���� ���� �� �� ����
	public: array<unsigned char, 1>^ Serialize(ClassLibrary1::StructChat^ str)
	{
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		return ms->ToArray();
	}

	public: ClassLibrary1::StructChat^ Deserialize(array<unsigned char>^ buff)
	{
		MemoryStream^ ms = gcnew MemoryStream(buff);
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		return (ClassLibrary1::StructChat^)bf->Deserialize(ms);
	}

			// ���� ��ư�� ������ ��
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		ClassLibrary1::StructChat^ str = gcnew ClassLibrary1::StructChat();

		// ������ ���� ���ڿ��� StructChat ��ü ���·� ��ȯ
		str->textChat = textBox2->Text;
		str->myColor = textBox2->ForeColor;
		str->myFont = textBox2->Font;

		// �ش� StructChat ��ü ���¸� ���۷� ���� �� �ְ� Serialize() �ؼ� ������ ������
		array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		buf = ms->ToArray();
		client->Send(buf, buf->Length, SocketFlags::None);
	}



};
}
