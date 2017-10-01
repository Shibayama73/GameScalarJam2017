//============================================================//
//*���@�O	Map.cpp
//*���@�e	�}�b�v
//*���@�t	2017.9.30
//*�X�@�V	2017.9.30
//*�����	N.Shibayama
//============================================================//
#include "pch.h"
#include "Map.h"
#include <WICTextureLoader.h>
#include <time.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

Map::Map() 
{
}

int Map::Initialize()
{
	//	20�̕����̐���
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			//mapRoom[j * 5 + k] = new MapRoom(j, k);
			m_mapRoom[j][k] = new MapRoom(j, k);
			m_mapRoom[j][k]->Initialize();
		}
	}

	return 0;
}

int Map::Draw(DirectX::SpriteBatch * spriteBatch)
{
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			//	�}�b�v����
			m_mapRoom[j][k]->Draw(&*spriteBatch);
		}
	}

	return 0;
}

void Map::Finalize()
{
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			delete m_mapRoom[j][k];
		}
	}

}

//	�ꕔ���̒n�`��Ԏ擾
MapRoom* Map::Get1Room(int height, int width)
{
	MapRoom* room = nullptr;

	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			room = &*m_mapRoom[i][j];
		}
	}
	return &*room;
}
