#pragma once

namespace GUIServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ClassLibrary1;
	using namespace System::Collections::Generic;
	using namespace System::Net;
	using namespace System::Net::Sockets;
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
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  mainTextBox;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->mainTextBox = (gcnew System::Windows::Forms::RichTextBox());
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
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP �ּ�";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"���� ���� M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->Location = System::Drawing::Point(77, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 28);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"���� ���� B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(301, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"���� ����� 230", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->mainTextBox->Location = System::Drawing::Point(12, 58);
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(364, 494);
			this->mainTextBox->TabIndex = 3;
			this->mainTextBox->Text = L"";
			this->mainTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::mainTextBox_KeyPress);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 564);
			this->Controls->Add(this->mainTextBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ���� �ؽ�Ʈ �ڽ� Ŭ�� �� ���� �Ұ����ϰ� ����
	private: System::Void mainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = true;
	}

			 // ��ſ� �ʿ��� ���� ���� ����
	public: static Socket^ server;
	public: static List<Socket^>^ listClient = gcnew List<Socket^>();
	public: static IPEndPoint^ IP;
	public: static Thread^ threadClient;

			// ���� ��ư Ŭ�� �̺�Ʈ
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		// 2016 ��Ʈ�� ���� �ش� �����ǿ��� ���� ����
		IP = gcnew IPEndPoint(IPAddress::Parse(textBox1->Text), 2016);

		// backgroundWorker1 �۵�
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}

			 // �ϳ��� Ŭ���̾�Ʈ�� �ٷ�� ������ �Լ�
	private: static void client(Object^ obj)
	{
		Socket^ socket = (Socket^)obj;
		while (true)
		{
			try
			{

				// Ŭ���̾�Ʈ���Լ� ���۸� ���� �޽����� �Է� ����
				array<unsigned char>^ buff = gcnew array<unsigned char>(1024);
				int temp = socket->Receive(buff);

				// ��� Ŭ���̾�Ʈ���� �ش� �޽����� ����
				for each(Socket^ sock in listClient)
				{
					try {
						sock->Send(buff, buff->Length, SocketFlags::None);
					}
					catch (Exception^ ex)
					{
					}
				}
			}

			// ������ �߻��� ��� �ش� Ŭ���̾�Ʈ ����
			catch (Exception^ ex)
			{
				listClient->Remove(socket);
				return;
			}
		}
	}

			 // ���� �ؽ�Ʈ �ڽ��� �ؽ�Ʈ�� ���� �Լ�
	private: void addTextToMainTextBox(String ^text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(text + "\n");
	}

			 // ���α׷��� �ε�(Load) �Ǹ� �ڵ� ����Ǵ� �Լ�
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			 // backgroundWorker1 ���� �Լ�
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// ���� ������ �˸�
		server->Bind(IP);
		server->Listen(10);
		String^ text = " ~~~~~ ������ �����ϰ� �ֽ��ϴ�. ~~~~~";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("���� ����� 230", 12, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Blue;
		addTextToMainTextBox(text, font, color);

		// ���� �ݺ����� ����ڵ��� ��Ʈ����
		while (true)
		{
			Socket^ clientAccept = server->Accept();
			listClient->Add(clientAccept);

			// Ŭ���̾�Ʈ ���� �� �ش� Ŭ���̾�Ʈ���� �����带 �Ҵ��� client �Լ� ����
			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(GUIServer::MyForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			// Ŭ���̾�Ʈ ������ �˸�
			String^ textTemp = "!!! Ŭ���̾�Ʈ�� �����߽��ϴ�. !!!" + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^ fontTemp = gcnew System::Drawing::Font("���� ����� 230", 12, FontStyle::Bold);
			System::Drawing::Color^ colorTemp = Color::Blue;
			addTextToMainTextBox(textTemp, fontTemp, colorTemp);
		}
	}

			 // ���α׷��� ������ �ڵ����� backgroundWorker1�� ������� ������ ����
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (backgroundWorker1->IsBusy)
		{
			backgroundWorker1->CancelAsync();
		}
	}

	};
}
