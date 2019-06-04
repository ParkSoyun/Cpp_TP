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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  mainTextBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;


	protected:

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
			this->label1->Font = (gcnew System::Drawing::Font(L"한컴 백제 B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"IP 주소";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"한컴 백제 M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox1->Location = System::Drawing::Point(77, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(216, 28);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// mainTextBox
			// 
			this->mainTextBox->Font = (gcnew System::Drawing::Font(L"한컴 윤고딕 230", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->mainTextBox->Location = System::Drawing::Point(12, 58);
			this->mainTextBox->Name = L"mainTextBox";
			this->mainTextBox->Size = System::Drawing::Size(364, 441);
			this->mainTextBox->TabIndex = 5;
			this->mainTextBox->Text = L"";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"한컴 백제 B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(301, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 31);
			this->button1->TabIndex = 4;
			this->button1->Text = L"접속";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"한컴 백제 M", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->textBox2->Location = System::Drawing::Point(12, 524);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(281, 28);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"한컴 백제 B", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->Location = System::Drawing::Point(301, 524);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 31);
			this->button2->TabIndex = 4;
			this->button2->Text = L"전송";
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
		// 메인 텍스트 박스 클릭 시 수정 불가능하게 고정
	private: System::Void mainTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		e->Handled = true;
	}
			 // 통신을 위한 변수 선언
	public: Socket^ client;
	public: IPEndPoint^ IP;
	public: Thread^ clientThread;

			// 프로그램이 로드(Load) 되면 실행되는 이벤트
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		// 소켓을 초기화
		client = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}

			 // 서버와의 연결 버튼 이벤트
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// 해당 서버에 2016 포트로 연결
		try {
			IP = gcnew IPEndPoint(IPAddress::Parse(textBox1->Text), 2016);
			client->Connect(IP);

			// backgroundWorker1 이벤트 실행
			backgroundWorker1->RunWorkerAsync();
		}

		// 오류가 발생한 경우
		catch (Exception^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}

			 // backgroundWorker1 이벤트 시작
	private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

		// 서버에서부터 오는 메시지를 반복적으로 받음
		while (true)
		{

			// 메시지를 버퍼에 담음
			array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
			int temp = client->Receive(buf);
			ClassLibrary1::StructChat^ str = gcnew ClassLibrary1::StructChat();

			// 버퍼로 넘어온 데이터를 ClassLibrary1::StructChat 객체인 str로 변환해 텍스트로 보여줌
			str = Deserialize(buf);
			addTextToMainTextBox(str->textChat, str->myFont, str->myColor);
		}
	}

			 // 텍스트를 추가하는 함수 addText()
	private: void addTextToMainTextBox(String^ text, System::Drawing::Font^ font, System::Drawing::Color^ color)
	{

		// 메인 텍스트 박스에 해당 문자열을 보여줌
		mainTextBox->SelectionFont = font;
		mainTextBox->SelectionColor = (Color)color;
		mainTextBox->AppendText(text + "\n");
		mainTextBox->ScrollToCaret();
	}

			 // MemoryStream과 BinaryFormatter를 이용해 ClassLibrary1::StructChat의 문자열 형태를 버퍼 형태로 변환하고 다시 원상 복귀 할 수 있음
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

			// 전송 버튼을 눌렀을 때
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		ClassLibrary1::StructChat^ str = gcnew ClassLibrary1::StructChat();

		// 현재의 보낼 문자열을 StructChat 객체 형태로 변환
		str->textChat = textBox2->Text;
		str->myColor = textBox2->ForeColor;
		str->myFont = textBox2->Font;

		// 해당 StructChat 객체 형태를 버퍼로 보낼 수 있게 Serialize() 해서 서버로 보내줌
		array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		buf = ms->ToArray();
		client->Send(buf, buf->Length, SocketFlags::None);
	}



};
}
