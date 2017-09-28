//============================================================//
//*���@�O	MapRoom.cpp
//*���@�e	�}�b�v��������
//*���@�t	2017.9.26
//*�X�@�V	2017.9.26
//*�����	N.Shibayama
//============================================================//
#include "pch.h"
#include "MapRoom.h"
#include <WICTextureLoader.h>
#include "Devices.h"
#include <random>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

//	1�����̈ʒu�ԍ��ݒ�
//int MapRoom::m_room[5][5] = { { 0,1,2,3,4 },{ 5,6,7,8,9 },{ 10,11,12,13,14 },{ 15,16,17,18,19 },{ 20,21,22,23,24 } };
//	1�����̒n�`���������ݒ�
int MapRoom::m_room[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } };

MapRoom::MapRoom(int heightNum, int widthNum) :m_roomHeight(30), m_roomWidth(32),m_heightNum(heightNum),m_widthNum(widthNum)
{
}

//	����(3,4)�܂�
int MapRoom::Initialize()
{
	//	�����̈ʒu���
	//m_heightNum = heightNum;
	//m_widthNum = widthNum;

	auto& devices = Devices::GetInstance();

	//	���\�[�X�ǂݍ���
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/test3.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	�n�`�����̐ݒ�
	srand((unsigned int)time_t(NULL));
	std::random_device rnd;

	//	�������ɒn�`�����݂��邩���߂�
	int existence = rnd() % 5;
	//	���݂��Ă�����
	if (existence < 2)
	{
		//	�������߂�
		int randWidth = rnd() % 5;
		int randHeight = rnd() % 5;
		m_room[randHeight][randWidth] = 1;
		//	�^�C���̐��̐ݒ�
		int tileNum = randWidth*randHeight;

		for (int i = 0; i < randHeight; i++)
		{
			for (int j = 0; j < randWidth; j++)
			{
				if (i - 1 >= 0)
					m_room[randHeight - 1][randWidth] = 1;	//��
				if (i + 1 <= 4)
					m_room[randHeight + 1][randWidth] = 1;	//��
				if (j - 1 >= 0)
					m_room[randHeight][randWidth - 1] = 1;	//��
				if (j + 1 <= 4)
					m_room[randHeight][randWidth + 1] = 1;	//�E
				if (i - 1 >= 0 && j - 1 >= 0)
					m_room[randHeight - 1][randWidth - 1] = 1;
				if (i + 1 <= 4 && j - 1 >= 0)
					m_room[randHeight + 1][randWidth - 1] = 1;
				if (i - 1 >= 0 && j + 1 <= 4)
					m_room[randHeight - 1][randWidth + 1] = 1;
				if (i + 1 <= 4 && j + 1 <= 4)
					m_room[randHeight + 1][randWidth + 1] = 1;
			}
		}

		//{
		//	//	���ɍ��킹�Ď����ݒ�(3�~3)
		//	if (randHeight - 1 >= 0)
		//		m_room[randHeight - 1][randWidth] = 1;	//��
		//	if (randHeight + 1 <= 4)
		//		m_room[randHeight + 1][randWidth] = 1;	//��
		//	if (randWidth - 1 >= 0)
		//		m_room[randHeight][randWidth - 1] = 1;	//��
		//	if (randWidth + 1 <= 4)
		//		m_room[randHeight][randWidth + 1] = 1;	//�E
		//	if (randHeight - 1 >= 0 && randWidth - 1 >= 0)
		//		m_room[randHeight - 1][randWidth - 1] = 1;
		//	if (randHeight + 1 <= 4 && randWidth - 1 >= 0)
		//		m_room[randHeight + 1][randWidth - 1] = 1;
		//	if (randHeight - 1 >= 0 && randWidth + 1 <= 4)
		//		m_room[randHeight - 1][randWidth + 1] = 1;
		//	if (randHeight + 1 <= 4 && randWidth + 1 <= 4)
		//		m_room[randHeight + 1][randWidth + 1] = 1;
		//}
	}

	return 0;
}

int MapRoom::Update()
{
	return 0;
}

int MapRoom::Draw(SpriteBatch* spriteBatch)
{
	int width = 160 * m_widthNum;
	int height = 150 * m_heightNum;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (m_room[i][j] == 1)
				spriteBatch->Draw(m_texture.Get(), Vector2(j*m_roomWidth + width, i*m_roomHeight + height), nullptr, Colors::White, 0.0f);
		}
	}

	return 0;
}
