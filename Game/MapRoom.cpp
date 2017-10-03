//============================================================//
//*���@�O	MapRoom.cpp
//*���@�e	�}�b�v��������
//*���@�t	2017.9.26
//*�X�@�V	2017.10.3
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

MapRoom::MapRoom(int heightNum, int widthNum) :m_roomHeight(30), m_roomWidth(32),m_heightNum(heightNum),m_widthNum(widthNum),m_existence(false)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			m_room[i][j] = 0;
		}
	}
	//m_room[5][5] = { { 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } };
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
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/tile.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	�n�`�����̐ݒ�
	std::random_device rnd;

	//	�������ɒn�`�����݂��邩���߂�
	//int existence = rand() % 5;
	//	���݂��Ă�����
	if (true)//existence < 2)
	{
		m_existence = true;

		//	�������߂�
		int randWidth = 1 + (rand() % 5);
		int randHeight = 1 + (rand() % 5);

		//	�n�`�������̎�
		m_tile.axisHeight = randHeight;
		m_tile.axisWidth = randWidth;

		//m_room[randHeight][randWidth] = 1;
		//	�^�C���̐��̐ݒ�
		//int tileNum = randWidth*randHeight;

		for (int i = 0; i <= randHeight; i++)
		{
			for (int j = 0; j <= randWidth; j++)
			{
				//	�͈͓��ɂ���Ƃ��^�C��������
				if (((0 <= i - 1) && (i - 1 <= 4) && (0 <= j - 1) && (j - 1 <= 4) &&
					(0 <= i + 1) && (i + 1 <= 4) && (0 <= j + 1) && (j + 1 <= 4)) ||
					(i == 0 || j == 0 || i == 4 || j == 4))
					m_room[i][j] = 1;
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

//	�ꕔ���̒n�`��Ԏ擾
//	�ꕔ��5�~5��1�}�X�̏�Ԏ擾
int MapRoom::Get1RoomTile(int height, int width)
{
	return m_room[height][width];

	//int room = 0;
	//for (int i = 0; i <= height; i++)
	//{
	//	for (int j = 0; j <= width; j++)
	//	{
	//		room = m_room[i][j];
	//	}
	//}
	//return room;

}

//	�n�`�������̎��̍����擾
int MapRoom::GetTileAxisHeight()
{
	return m_tile.axisHeight;
}

//	�n�`�������̎��̕��擾
int MapRoom::GetTileAxisWidth()
{
	return m_tile.axisWidth;
}

//	�n�`�����݂��Ă��邩
//	�L(true)�A��(false)
bool MapRoom::IsTileExistence()
{
	return m_existence;
}

//	�w�肳�ꂽ�n�`�����
void MapRoom::ChangeOnTile(int height, int width)
{
	m_room[height][width] = 1;
}
