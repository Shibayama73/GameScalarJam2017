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

	//	�ꕔ���̒n�`��Ԏ擾
	int Get1RoomTile(int height,int width);
	//	�n�`�������̎��̍����擾
	int GetTileAxisHeight();
	//	�n�`�������̎��̕��擾
	int GetTileAxisWidth();
	//	�n�`�̑��ݗL��
	bool IsTileExistence();

private:
	int m_roomHeight;	//1�����̍���
	int m_roomWidth;	//1�����̕�
	int m_room[5][5];	//1�����̐�

	struct Tile{
		//	�n�`�������̎��̍���
		int axisHeight;
		//	�n�`�������̎��̕�
		int axisWidth;
	};

	Tile m_tile;

	//	1�����̒��̏��������ꂽ�e�N�X�`��
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
	//	�`��ʒu
	DirectX::SimpleMath::Vector2 m_screenPos;
	
	//	�����̈ʒu
	int m_widthNum;
	int m_heightNum;

	//	�n�`�̑��ݗL��
	bool m_existence;

};
