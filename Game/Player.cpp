//============================================================//
//*���@�O	Player.cpp
//*���@�e	�v���C���[
//*���@�t	2017.9.29
//*�X�@�V	2017.9.29
//*�����	N.Shibayama
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

	//	���\�[�X�ǂݍ���
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/test4.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));

	//	�J�n�ʒu�̐ݒ�
	m_PosHeight = 1;
	m_PosWidth = 1;

	return 0;
}

int Player::Update()
{
	auto& key = Keyboards::GetInstance();
	key.GetState();
	key.TrackerUpdate();

	//	�ړ��͈�
	//m_map->Get1RoomTile(1, 1);

	//	�ړ�(�㉺���E)
	if (key.CheckKey('W'))
	{
		//���e�X�g���w�肳�ꂽ�������̒n�`�̔z��ɒn�`�����邩�ǂ���
		//if (m_map->Get1Room(0, 0)->Get1RoomTile(2,2)==1)
		//m_height -= 1;

		//	1�}�X��ɒn�`�����݂��Ă�����i��
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile((m_PosHeight % 5) - 1, m_PosWidth % 5) == 1)
		m_PosHeight -= 1;
		
	}
	if (key.CheckKey('S'))
	{
		//m_height += 1;
		//	1�}�X��ɒn�`�����݂��Ă�����i��
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile((m_PosHeight % 5) + 1, m_PosWidth % 5) == 1)
		m_PosHeight += 1;
	}
	if (key.CheckKey('A'))
	{
		//m_width -= 1;
		//	1�}�X��ɒn�`�����݂��Ă�����i��
		if (m_map->Get1Room(m_PosHeight / 5, m_PosWidth / 5)
			->Get1RoomTile(m_PosHeight % 5, (m_PosWidth % 5) - 1) == 1)
		m_PosWidth -= 1;
	}
	if (key.CheckKey('D'))
	{
		//m_width += 1;
		//	1�}�X��ɒn�`�����݂��Ă�����i��
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
