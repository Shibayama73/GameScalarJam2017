//============================================================//
//*名　前	MapRoom.cpp
//*内　容	マップ部屋生成
//*日　付	2017.9.26
//*更　新	2017.10.3
//*制作者	N.Shibayama
//============================================================//
#include "pch.h"
#include "MapRoom.h"
#include <WICTextureLoader.h>
#include "Devices.h"
#include <random>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

//	1部屋の位置番号設定
//int MapRoom::m_room[5][5] = { { 0,1,2,3,4 },{ 5,6,7,8,9 },{ 10,11,12,13,14 },{ 15,16,17,18,19 },{ 20,21,22,23,24 } };
//	1部屋の地形初期無し設定

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

//	引数(3,4)まで
int MapRoom::Initialize()
{
	//	部屋の位置代入
	//m_heightNum = heightNum;
	//m_widthNum = widthNum;

	auto& devices = Devices::GetInstance();

	//	リソース読み込み
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/tile.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	地形部分の設定
	std::random_device rnd;

	//	部屋内に地形が存在するか決める
	//int existence = rand() % 5;
	//	存在していたら
	if (true)//existence < 2)
	{
		m_existence = true;

		//	軸を決める
		int randWidth = 1 + (rand() % 5);
		int randHeight = 1 + (rand() % 5);

		//	地形生成時の軸
		m_tile.axisHeight = randHeight;
		m_tile.axisWidth = randWidth;

		//m_room[randHeight][randWidth] = 1;
		//	タイルの数の設定
		//int tileNum = randWidth*randHeight;

		for (int i = 0; i <= randHeight; i++)
		{
			for (int j = 0; j <= randWidth; j++)
			{
				//	範囲内にあるときタイルをつける
				if (((0 <= i - 1) && (i - 1 <= 4) && (0 <= j - 1) && (j - 1 <= 4) &&
					(0 <= i + 1) && (i + 1 <= 4) && (0 <= j + 1) && (j + 1 <= 4)) ||
					(i == 0 || j == 0 || i == 4 || j == 4))
					m_room[i][j] = 1;
			}
		}

		//{
		//	//	軸に合わせて周りを設定(3×3)
		//	if (randHeight - 1 >= 0)
		//		m_room[randHeight - 1][randWidth] = 1;	//上
		//	if (randHeight + 1 <= 4)
		//		m_room[randHeight + 1][randWidth] = 1;	//下
		//	if (randWidth - 1 >= 0)
		//		m_room[randHeight][randWidth - 1] = 1;	//左
		//	if (randWidth + 1 <= 4)
		//		m_room[randHeight][randWidth + 1] = 1;	//右
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

//	一部屋の地形状態取得
//	一部屋5×5の1マスの状態取得
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

//	地形生成時の軸の高さ取得
int MapRoom::GetTileAxisHeight()
{
	return m_tile.axisHeight;
}

//	地形生成時の軸の幅取得
int MapRoom::GetTileAxisWidth()
{
	return m_tile.axisWidth;
}

//	地形が存在しているか
//	有(true)、無(false)
bool MapRoom::IsTileExistence()
{
	return m_existence;
}

//	指定された地形を作る
void MapRoom::ChangeOnTile(int height, int width)
{
	m_room[height][width] = 1;
}
