//============================================================//
//*���@�O	Player.h
//*���@�e	�v���C���[
//*���@�t	2017.9.29
//*�X�@�V	2017.9.29
//*�����	N.Shibayama
//============================================================//
#pragma once
#include <SpriteBatch.h>
#include <simplemath.h>
#include "Devices.h"
#include "MapRoom.h"
#include "Keyboards.h"

class Player
{
public:
	Player(MapRoom* mapRoom);
	int Initialize();
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

private:
	//	�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	�e�N�X�`��1�}�X���̕�
	int m_width;
	//	�e�N�X�`��1�}�X���̍���
	int m_height;

	//	�ʒu
	int m_position[20][25];

	//	�}�b�v����
	MapRoom* m_mapRoom;
};
