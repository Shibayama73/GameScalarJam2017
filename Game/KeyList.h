//	�e�X�g�p�i���g�p�j
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
		//	�L�[�̖��O����T��
		if (keyName == (std::string&)key.GetState())
		{
			//	��v�����炻�̏ꏊ��Ԃ�
			
		}
		else
		{
			//�������nullptr��Ԃ�
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
		//	�L�[���X�g�𒲂ׂ�

		//	������Ă�����true�A�������false

		return true;
	}

};

class KeyboardFacade
{
public:
	std::string SearchKey(std::string keyName)
	{
		//	�L�[��T��
		KeyList* keyList = new KeyList();
		std::string location = keyList->SearchList(keyName);

		//	�L�[�̏ꏊ��null�łȂ��Ƃ�
		if (location != (std::string)nullptr)
		{
			//	�L�[��������Ă��邩���ׂ�
			KeyPush* keyPush = new KeyPush();
			if (keyPush->Check(keyName))
			{
				//	������Ă���Ƃ�
				return location;
			}
			else
			{
				//	������Ă��Ȃ��Ƃ�
				return "������Ă��܂���";
			}
		}
		//	�L�[���X�g�ƈ�v���Ȃ��Ƃ�
		else
		{
			return "��v���܂���ł���";
		}
	}

};
