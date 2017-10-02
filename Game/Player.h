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
#include "Keyboards.h"
#include "Map.h"

class Player
{
public:
	Player(Map* map);
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
	//	��
	int m_PosWidth;
	//	����
	int m_PosHeight;

	//	�}�b�v����
	Map* m_map;

};
