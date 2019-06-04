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
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
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
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
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
			this->label1->Font = (gcnew System::Drawing::Font(L"한컴 백제 B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP 주소";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"한컴 백제 M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->Location = System::Drawing::Point(77, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 28);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"한컴 백제 B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(301, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 31);
			this->button1->TabIndex = 2;
			this->button1->Text = L"접속";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"한컴 윤고딕 230", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
		// 메인 텍스트 박스 클릭 시 수정 불가능하게 고정
	private: System::Void mainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = true;
	}

			 // 통신에 필요한 각종 변수 선언
	public: static Socket^ server;
	public: static List<Socket^>^ listClient = gcnew List<Socket^>();
	public: static IPEndPoint^ IP;
	public: static Thread^ threadClient;

			// 시작 버튼 클릭 이벤트
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		// 2016 포트를 열고 해당 아이피에서 서버 시작
		IP = gcnew IPEndPoint(IPAddress::Parse(textBox1->Text), 2016);

		// backgroundWorker1 작동
		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}

			 // 하나의 클라이언트를 다루는 쓰레드 함수
	private: static void client(Object^ obj)
	{
		Socket^ socket = (Socket^)obj;
		while (true)
		{
			try
			{

				// 클라이언트에게서 버퍼를 통해 메시지를 입력 받음
				array<unsigned char>^ buff = gcnew array<unsigned char>(1024);
				int temp = socket->Receive(buff);

				// 모든 클라이언트에게 해당 메시지를 전송
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

			// 오류가 발생한 경우 해당 클라이언트 삭제
			catch (Exception^ ex)
			{
				listClient->Remove(socket);
				return;
			}
		}
	}

			 // 메인 텍스트 박스에 텍스트를 쓰는 함수
	private: void addTextToMainTextBox(String ^text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(text + "\n");
	}

			 // 프로그램이 로드(Load) 되면 자동 실행되는 함수
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			 // backgroundWorker1 실행 함수
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// 서버 동작을 알림
		server->Bind(IP);
		server->Listen(10);
		String^ text = " ~~~~~ 서버가 동작하고 있습니다. ~~~~~";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("한컴 윤고딕 230", 12, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Blue;
		addTextToMainTextBox(text, font, color);

		// 무한 반복으로 사용자들을 컨트롤함
		while (true)
		{
			Socket^ clientAccept = server->Accept();
			listClient->Add(clientAccept);

			// 클라이언트 접속 시 해당 클라이언트만의 쓰레드를 할당해 client 함수 시작
			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(GUIServer::MyForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			// 클라이언트 접속을 알림
			String^ textTemp = "!!! 클라이언트가 접속했습니다. !!!" + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^ fontTemp = gcnew System::Drawing::Font("한컴 윤고딕 230", 12, FontStyle::Bold);
			System::Drawing::Color^ colorTemp = Color::Blue;
			addTextToMainTextBox(textTemp, fontTemp, colorTemp);
		}
	}

			 // 프로그램을 닫으면 자동으로 backgroundWorker1을 종료시켜 완전히 종료
	private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (backgroundWorker1->IsBusy)
		{
			backgroundWorker1->CancelAsync();
		}
	}

	};
}
