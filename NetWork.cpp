#include "NetWork.h"


namespace NetWork
{
    SOCKET sock_;
    int fromlen_;
    int ret_;
    int tolen_;
    SOCKADDR_IN toAddr_;

    void InitSocket()
    {
        WSADATA wsaData;
        int wsetup = WSAStartup(MAKEWORD(2, 2), &wsaData);


        // ソケット作成
        sock_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock_ > 0)
        {

            //  message.append("socket ok\r\n");

        }
        u_long arg = 0x01;
        int stop = ioctlsocket(sock_, FIONBIO, &arg);
        if (stop == 0)
        {
        }


    }



    void InitSend()
    {
        memset(&toAddr_, 0, sizeof(toAddr_));
        toAddr_.sin_family = AF_INET;
        //toAddr_.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        inet_pton(AF_INET, "127.0.0.1", &toAddr_.sin_addr.s_addr);
        toAddr_.sin_port = htons(8080);
        char buff[1024] = "";
        int tolen = sizeof(toAddr_);
        int ret = sendto(sock_, buff, sizeof(buff), 0, (sockaddr*)&toAddr_, tolen);
        if (ret > 0)
        {

            int i = 0;
        }
        else
        {
            int error = WSAGetLastError();
        }
    }

    bool InitRecv()
    {
        RecvCorrespondence recv;
        SOCKADDR_IN  fromAddr_;
        fromlen_ = sizeof(fromAddr_);
        ret_ = recvfrom(sock_, (char*)&recv, sizeof(recv), 0, (SOCKADDR*)&fromAddr_, &fromlen_);
        int error = 0;
        if (ret_ < 0)
        {
            error = WSAGetLastError();
            if (error != WSAEWOULDBLOCK)
            {

                // エラー
                int a = 0;
            }
            int i = 0;
        }
        else
        {
                RecvCorrespondence c = ConvertRecvDate(recv);
                if (c.sendContent == 0)
                {
                    if (RecvData::playerList.size() == 0)
                    {
                        RecvData::playerList.push_back(c.pInit);
                        RecvData::playerNum = c.pInit.playerNumber;
                        return true;
                    }
                    if (c.pInit.playerNumber != RecvData::playerList[0].playerNumber)
                    {
                        RecvData::playerList.push_back(c.pInit);
                        return true;
                    }
                }
            }
        return false;
    }

    void UpdateRecv()
    {
        RecvCorrespondence recv;
        SOCKADDR_IN  fromAddr_;
        fromlen_ = sizeof(fromAddr_);
        ret_ = recvfrom(sock_, (char*)&recv, sizeof(recv), 0, (SOCKADDR*)&fromAddr_, &fromlen_);
        int error = 0;
        if (ret_ < 0)
        {
            error = WSAGetLastError();
            if (error != WSAEWOULDBLOCK)
            {

                // エラー
                int a = 0;
            }
            int i = 0;
        }
        else
        {
            ConvertRecvDate(recv);
            RecvData::updateList.push_back(recv);
        }
        return;
    }

    void UpdateSend()
    {
        memset(&toAddr_, 0, sizeof(toAddr_));
        toAddr_.sin_family = AF_INET;
        //toAddr_.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
        inet_pton(AF_INET, "127.0.0.1", &toAddr_.sin_addr.s_addr);
        toAddr_.sin_port = htons(8080);
        SendDateToServer s = SendDate::send;
        s.playerNumber = htonl(s.playerNumber);
        s.Position.x = htonl((int)s.Position.x);
        s.Position.y = htonl((int)s.Position.y);
        s.Position.z = htonl((int)s.Position.z);
        s.rotate_Cannon = htonf(s.rotate_Cannon);
        s.rotate_Tank = htonf(s.rotate_Tank);
        int tolen = sizeof(toAddr_);
        int ret = sendto(sock_, (char*)&s, sizeof(s), 0, (sockaddr*)&toAddr_, tolen);
        if (ret > 0)
        {

            int i = 0;
        }
        else
        {
            int error = WSAGetLastError();
        }
    }

   
    RecvCorrespondence ConvertRecvDate(RecvCorrespondence convertDate)
    {
        RecvCorrespondence conv;
        conv.sendContent = ntohl(convertDate.sendContent);

        conv.pInit.playerNumber = ntohl(convertDate.pInit.playerNumber);
        conv.pInit.position.x = ntohf(convertDate.pInit.position.x);
        conv.pInit.position.y = ntohf(convertDate.pInit.position.y);
        conv.pInit.position.z = ntohf(convertDate.pInit.position.z);

        conv.pUpdate.playerNumber = ntohl(convertDate.pUpdate.playerNumber);
        conv.pUpdate.position.x = ntohf(convertDate.pUpdate.position.x);
        conv.pUpdate.position.y = ntohf(convertDate.pUpdate.position.y);
        conv.pUpdate.position.z = ntohf(convertDate.pUpdate.position.z);
        conv.pUpdate.rotate_Cannon = ntohf(convertDate.pUpdate.rotate_Cannon);
        conv.pUpdate.rotate_Tank = ntohf(convertDate.pUpdate.rotate_Tank);
        conv.pUpdate.shoot = convertDate.pUpdate.shoot;

        conv.h.hitReaction = ntohl(convertDate.h.hitReaction);
        conv.h.targetPlayerNum = ntohl(convertDate.h.targetPlayerNum);
        conv.h.objNum = ntohl(convertDate.h.objNum);
        conv.h.position.x = ntohf(convertDate.h.position.x);
        conv.h.position.y = ntohf(convertDate.h.position.y);
        conv.h.position.z = ntohf(convertDate.h.position.z);
        return conv;
    }
}