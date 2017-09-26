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

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

MapRoom::MapRoom() :m_height(150), m_width(160)
{

}

int MapRoom::Initialize(int width, int height)
{
	m_outputWidth = width;
	m_outputHeight = height;

	auto& devices = Devices::GetInstance();

	//	���\�[�X�ǂݍ���
	ComPtr<ID3D11Resource> resource;
	DX::ThrowIfFailed(
		CreateWICTextureFromFile(devices.GetDevice().Get(), L"Resources/test.png", resource.GetAddressOf(),
			m_texture.ReleaseAndGetAddressOf()));
	//	�\�����W����ʒ����Ɏw��
	m_screenPos.x = m_outputWidth / 2.0f;
	m_screenPos.y = m_outputHeight / 2.0f;

	return 0;
}

int MapRoom::Update()
{
	return 0;
}

int MapRoom::Draw(SpriteBatch* spriteBatch)
{
	spriteBatch->Draw(m_texture.Get(), Vector2(0,0), nullptr, Colors::White, 0.0f);
	return 0;
}
