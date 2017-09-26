//============================================================//
//*���@�O	MapRoom.h
//*���@�e	�}�b�v��������
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
	MapRoom();
	int Initialize(int width, int height);
	int Update();
	int Draw(DirectX::SpriteBatch* spriteBatch);

private:
	int m_height;	//1�����̍���
	int m_width;	//1�����̕�
	int m_room[20];	//�����̐�

	//	��g�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	�`��ʒu
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	�E�B���h�E�̑傫��
	int m_outputWidth;
	int m_outputHeight;

};
