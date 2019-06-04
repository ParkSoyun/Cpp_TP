using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Runtime::Serialization::Formatters;

#pragma once

using namespace System;

namespace ClassLibrary1 {
	[Serializable]

	// 텍스트의 형태를 나타내는 StructChat 클래스 정의
	public ref class StructChat
	{

		// 기본 변수 선언
	public:
		String^ textChat;
		System::Drawing::Color^ myColor;
		System::Drawing::Font^ myFont;

		// 기본 생성자 선언
	public: StructChat()
	{
		textChat = "";
		myColor = Color::Green;
		myFont = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Regular);
	}

	public: StructChat(String^ text, System::Drawing::Font^ font, Color^ color)
	{
		textChat = text;
		myColor = color;
		myFont = font;
	}

			// 현재의 객체 데이터를 얻어오는 함수
	public: void GetObjectData(SerializationInfo^ info, StreamingContext^ context)
	{
		info->AddValue("text", textChat);
		info->AddValue("font", myFont);
		info->AddValue("color", myColor);
	}

			// Serialization 정보를 이용해 초기화하는 생성자
	public: StructChat(SerializationInfo^ info, StreamingContext^ context)
	{
		textChat = (String^)info->GetValue("text", String::typeid);
		myFont = (System::Drawing::Font^)info->GetValue("font", System::Drawing::Font::typeid);
		myColor = (System::Drawing::Color^)info->GetValue("color", System::Drawing::Color::typeid);
	}
	};
}
