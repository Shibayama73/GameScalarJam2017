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

Player::Player(MapRoom* mapRoom):m_width(32),m_height(30),m_mapRoom(mapRoom)
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

	//������
	//	�J�n�ʒu�̐ݒ�

	return 0;
}

int Player::Update()
{
	auto& key = Keyboards::GetInstance();
	key.GetState();
	key.TrackerUpdate();

	//	�ړ��͈�

	//	�ړ�(�㉺���E)
	if (key.CheckKey('W'))
	{
		m_height -= 1;
	}
	if (key.CheckKey('S'))
	{
		m_height += 1;
	}
	if (key.CheckKey('A'))
	{
		m_width -= 1;
	}
	if (key.CheckKey('D'))
	{
		m_width += 1;
	}

	return 0;
}

int Player::Draw(DirectX::SpriteBatch * spriteBatch)
{
	spriteBatch->Draw(m_texture.Get(), Vector2(m_width, m_height), nullptr, Colors::White, 0.0f);
	return 0;
}
