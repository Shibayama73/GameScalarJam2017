//	テスト用（未使用）
#pragma once
#include <string>
#include "Keyboards.h"

class KeyList 
{
public:
	std::string SearchList(std::string keyName)
	{
		std::string location = nullptr;
		auto& key = Keyboards::GetInstance();
		//	キーの名前から探す
		if (keyName == (std::string&)key.GetState())
		{
			//	一致したらその場所を返す
			
		}
		else
		{
			//無ければnullptrを返す
			location = nullptr;
		}

		return location;
	}

};

class KeyPush
{
public:
	bool Check(std::string keyName)
	{
		//	キーリストを調べる

		//	押されていたらtrue、無ければfalse

		return true;
	}

};

class KeyboardFacade
{
public:
	std::string SearchKey(std::string keyName)
	{
		//	キーを探す
		KeyList* keyList = new KeyList();
		std::string location = keyList->SearchList(keyName);

		//	キーの場所がnullでないとき
		if (location != (std::string)nullptr)
		{
			//	キーが押されているか調べる
			KeyPush* keyPush = new KeyPush();
			if (keyPush->Check(keyName))
			{
				//	押されているとき
				return location;
			}
			else
			{
				//	押されていないとき
				return "押されていません";
			}
		}
		//	キーリストと一致しないとき
		else
		{
			return "一致しませんでした";
		}
	}

};
