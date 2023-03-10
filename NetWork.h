#pragma once
#include "SendDate.h"
#include "RecvData.h"
#include <WinSock2.h>
#include <ws2tcpip.h>	// WinSock�p
#pragma comment( lib, "ws2_32.lib" )
#include "Engine/Transform.h"
#define PLAYERMENBER 2
namespace NetWork
{
	void InitSocket();

	/// <summary>
	/// Server�ɒ��g����̑��M�����āAClient�̃A�h���X��m�点��
	/// </summary>
	void InitSend();

	/// <summary>
	/// server����v���C���[�L�����̏����ʒu���󂯎��
	/// </summary>
	/// <returns>�v���C���[�L�����̏����ʒu���󂯎�ꂽ���ǂ���</returns>
	bool InitRecv();

	void UpdateRecv();

	void UpdateSend();

	/// <summary>
	//�@�����̕ϐ��̒��g���z�X�g�o�C�g�I�[�_�[�ɕϊ�����
	/// </summary>
	/// <param name="convertDate">�ϊ�����ϐ�</param>
	RecvCorrespondence ConvertRecvDate(RecvCorrespondence convertDate);
};

