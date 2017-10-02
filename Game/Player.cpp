//============================================================//
//*名　前	Player.cpp
//*内　容	プレイヤー
//*日　付	2017.9.29
//*更　新	2017.9.29
//*制作者	N.Shibayama
//============================================================//
#include "pch.h"
#include "Player.h"
#include <WICTextureLoader.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

const int HEIGHT = 20;
const int WIDTH = 25;

Player::Player(Map* map):m_width(32),m_height(30),m_map(map)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			m_position[i][j] = 0;
		}
	}
}

int Player::Initialize()
{
	auto& devices = Devices::GetInstance();

	//	リソース読み込み
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/test4.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	開始位置の設定
	m_PosHeight = 1;
	m_PosWidth = 1;

	return 0;
}

int Player::Update()
{
	auto& key = Keyboards::GetInstance();
	key.GetState();
	key.TrackerUpdate();

	//	移動範囲
	//m_map->Get1RoomTile(1, 1);

	//	移動(上下左右)
	if (key.CheckKey('W'))
	{
		//＊テスト＊指定された部屋内の地形の配列に地形があるかどうか
		//if (m_map->Get1Room(0, 0)->Get1RoomTile(2,2)==1)
		//m_height -= 1;

		//	1マス先に地形が存在していたら進む
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile((m_PosHeight % 5) - 1, m_PosWidth % 5) == 1)
		m_PosHeight -= 1;
		
	}
	if (key.CheckKey('S'))
	{
		//m_height += 1;
		//	1マス先に地形が存在していたら進む
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile((m_PosHeight % 5) + 1, m_PosWidth % 5) == 1)
		m_PosHeight += 1;
	}
	if (key.CheckKey('A'))
	{
		//m_width -= 1;
		//	1マス先に地形が存在していたら進む
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile(m_PosHeight % 5, (m_PosWidth % 5) - 1) == 1)
		m_PosWidth -= 1;
	}
	if (key.CheckKey('D'))
	{
		//m_width += 1;
		//	1マス先に地形が存在していたら進む
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile(m_PosHeight % 5, (m_PosWidth % 5) + 1) == 1)
		m_PosWidth += 1;
	}

	return 0;
}

int Player::Draw(DirectX::SpriteBatch * spriteBatch)
{
	spriteBatch->Draw(m_texture.Get(), Vector2(m_PosWidth*m_width, m_PosHeight*m_height), nullptr, Colors::White, 0.0f);
	return 0;
}
