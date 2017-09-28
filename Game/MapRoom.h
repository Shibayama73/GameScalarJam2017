//============================================================//
//*���@�O	MapRoom.h
//*���@�e	�}�b�v1��������
//*���@�t	2017.9.26
//*�X�@�V	2017.9.26
//*�����	N.Shibayama
//============================================================//
#pragma once
#include <SpriteBatch.h>
#include <simplemath.h>

class MapRoom
{
public:
	MapRoom(int heightNum, int widthNum);
	int Initialize();
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

private:
	int m_roomHeight;	//1�����̍���
	int m_roomWidth;	//1�����̕�
	static int m_room[5][5];	//1�����̐�

	//	1�����̒��̏��������ꂽ�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	�`��ʒu
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	�����̈ʒu
	int m_widthNum;
	int m_heightNum;

	//	�E�B���h�E�̑傫��
	//int m_outputWidth;
	//int m_outputHeight;

	//	���݂���(�����ł͂Ȃ�)
	//bool IsPellucidity;

};
