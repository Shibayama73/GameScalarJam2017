//	ASCIIコードからキーボードのキーに変換する
#pragma once

class KeyConvertList
{
public:
	KeyConvertList();
	~KeyConvertList();

	//	ASCIIコードからキーボードのキーに変換する
	int Convert(char asciiCode);

};
