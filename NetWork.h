#pragma once
#include "SendDate.h"
#include "RecvData.h"
#include <WinSock2.h>
#include <ws2tcpip.h>	// WinSock用
#pragma comment( lib, "ws2_32.lib" )
#include "Engine/Transform.h"
#define PLAYERMENBER 2
namespace NetWork
{
	void InitSocket();

	/// <summary>
	/// Serverに中身が空の送信をして、Clientのアドレスを知らせる
	/// </summary>
	void InitSend();

	/// <summary>
	/// serverからプレイヤーキャラの初期位置を受け取る
	/// </summary>
	/// <returns>プレイヤーキャラの初期位置を受け取れたかどうか</returns>
	bool InitRecv();

	void UpdateRecv();

	void UpdateSend();

	/// <summary>
	//　引数の変数の中身をホストバイトオーダーに変換する
	/// </summary>
	/// <param name="convertDate">変換する変数</param>
	RecvCorrespondence ConvertRecvDate(RecvCorrespondence convertDate);
};

