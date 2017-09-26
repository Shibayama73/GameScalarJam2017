#include "Keyboards.h"

using namespace DirectX;
using Microsoft::WRL::ComPtr;

std::unique_ptr<Keyboards> Keyboards::keyboard(nullptr);

void Keyboards::CreateKeyboard()
{
	//	キーボードの生成
	this->m_keyboard = std::make_unique<Keyboard>();
	//	トラッカー生成
	this->m_tracker = std::make_unique<Keyboard::KeyboardStateTracker>();
	//	キー変換リストの生成
	this->m_keyList = std::make_unique<KeyConvertList>();

}

//	状態取得
DirectX::Keyboard::State Keyboards::GetState()
{
	return this->m_keyboard->GetState();
}

//	トラッカー更新
void Keyboards::TrackerUpdate()
{
	this->m_tracker->Update(Keyboards::GetState());
}

//	指定されたキーが押されたかどうか
bool Keyboards::CheckKey(char keyName)
{
	//	指定されたキー(ASCIIコード)からキーボードの値に変換する
	int keyCodeNum = m_keyList->Convert(keyName);
	//	キーの状態取得
	Keyboard::State key = m_keyboard->GetState();

	//	キーボードを変換された値に入れる
	switch (keyCodeNum)
	{
	case 0x41:
		if (key.A)	return true;
		return false;
	case 0x42:
		if (key.B)	return true;
		return false;
	case 0x43:
		if (key.C)	return true;
		return false;
	case 0x44:
		if (key.D)	return true;
		return false;
	case 0x45:
		if (key.E)	return true;
		return false;
	case 0x46:
		if (key.F)	return true;
		return false;
	case 0x47:
		if (key.G)	return true;
		return false;
	case 0x48:
		if (key.H)	return true;
		return false;
	case 0x49:
		if (key.I)	return true;
		return false;
	case 0x4a:
		if (key.J)	return true;
		return false;
	case 0x4b:
		if (key.K)	return true;
		return false;
	case 0x4c:
		if (key.L)	return true;
		return false;
	case 0x4d:
		if (key.M)	return true;
		return false;
	case 0x4e:
		if (key.N)	return true;
		return false;
	case 0x4f:
		if (key.O)	return true;
		return false;
	case 0x50:
		if (key.P)	return true;
		return false;
	case 0x51:
		if (key.Q)	return true;
		return false;
	case 0x52:
		if (key.R)	return true;
		return false;
	case 0x53:
		if (key.S)	return true;
		return false;
	case 0x54:
		if (key.T)	return true;
		return false;
	case 0x55:
		if (key.U)	return true;
		return false;
	case 0x56:
		if (key.V)	return true;
		return false;
	case 0x57:
		if (key.W)	return true;
		return false;
	case 0x58:
		if (key.X)	return true;
		return false;
	case 0x59:
		if (key.Y)	return true;
		return false;
	case 0x5a:
		if (key.Z)	return true;
		return false;
	default:
		return false;
	}
}

////	ASCIIコードからキーボードの値に変換する
//int Keyboards::Convert(char asciiCode)
//{
//	switch (asciiCode)
//	{
//	case 'A':
//		return 0x41;
//	case 'B':
//		return 0x42;
//	case 'C':
//		return 0x43;
//	case 'D':
//		return 0x44;
//	case 'E':
//		return 0x45;
//	case 'F':
//		return 0x46;
//	case 'G':
//		return 0x47;
//	case 'H':
//		return 0x48;
//	case 'I':
//		return 0x49;
//	case 'J':
//		return 0x4a;
//	case 'K':
//		return 0x4b;
//	case 'L':
//		return 0x4c;
//	case 'M':
//		return 0x4d;
//	case 'N':
//		return 0x4e;
//	case 'O':
//		return 0x4f;
//	case 'P':
//		return 0x50;
//	case 'Q':
//		return 0x51;
//	case 'R':
//		return 0x52;
//	case 'S':
//		return 0x53;
//	case 'T':
//		return 0x54;
//	case 'U':
//		return 0x55;
//	case 'V':
//		return 0x56;
//	case 'W':
//		return 0x57;
//	case 'X':
//		return 0x58;
//	case 'Y':
//		return 0x59;
//	case 'Z':
//		return 0x5a;
//	default:
//		break;
//	}
//
//	return 0;
//}
