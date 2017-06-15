#pragma comment(lib,"ws2_32.lib")
#include <thread>
#include <iostream>
#include <string>
#include <queue>
#include <WinSock2.h>
#include <Ws2tcpip.h>
#include <ws2def.h>
#include <mutex>

#define BUFLEN 20
#define _OUT &
#define _IN
#define _INOUT &
typedef bool FLAG;
class Client 
{
public: 
	static Client* getInstanse();
	bool LogIn(std::string x, std::string y);
	void Update();
	int iD = 0;

private:
	static Client* Instance;
	static WSADATA wsa;
	struct sockaddr_in si_other;
	int slen = sizeof(si_other);
	SOCKET s;
	const std::string iP = "1.1.1.1\0";
	const int UDPport = 11100, TCPport = 11111;
	char buf[BUFLEN];
	char message[BUFLEN];
	static void SocketSafe( const int _IN connectionType,
		const int _IN socketType, const int _IN slayerTipe, SOCKET _OUT outSocket);
	void ConnectSafe(SOCKET _IN sock, const struct sockaddr* _IN serv, size_t _IN sizeOfserver);
	void AdressFill(struct sockaddr_in _OUT sock, const char* _IN ip, int _IN port);
	void recieveFromSafe(SOCKET _IN sock, char* _OUT  buf, int _IN len,
		int _IN flags,struct sockaddr* _OUT from,int* _INOUT fromlen);
	void sendToSafe(SOCKET _IN sock, const char* _IN buf, int _IN len, int _IN flags,
		const struct sockaddr* _IN to, int _IN tolen);
	void sendSafe(SOCKET _IN sock, const char* _IN buf, int _IN len, int _IN flags);
	void recvSafe(SOCKET _IN sock,  char* _IN buf, int _IN len, int _IN flags);
	int ReadBytes(char _IN data, int _IN shift);
};