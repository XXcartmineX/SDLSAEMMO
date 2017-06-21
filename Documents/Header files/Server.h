/*
 * Server.h
 *
 *  Created on: May 24, 2017
 *      Author: komo97
 */

#ifndef SOURCE_FILES_SERVER_H_
#define SOURCE_FILES_SERVER_H_

#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <queue>
#include <fstream>
#include <vector>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp6.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef bool FLAG;

//Server ports
const uint16_t ServerPortListen = 11100;
const uint16_t ServerPortQuery = 11101;
const uint16_t ServerPortLogIn = 11111;
const uint16_t ServerPortSend1 = 11103;
const uint16_t ServerPortSend2 = 11104;
const int ammountOfLogicThreads = 6;

class Server {
public:
	virtual ~Server();
	static Server* getInstance();
	void App();
	static void DestroyServer();
 private:
	Server();
	static Server* instance;
	void ServerInit();
	void ThreadInit();
	void SocketStructsInit();
	static std::ofstream CreateLogWindow(const char* name);
	static void UpdateListenThreads();
	static void UpdateLogicThreads(char* data, std::ofstream& outlog);
	static void UpdateSendingThreads(std::queue<int>& queue, uint16_t port, std::ofstream& outlog);
	static void ParseThread();
	static void LoginThread();
	static void QueryThread();
	static void InitTCPSocket(bool& shouldTerminateFlag, int& socketfd, std::ofstream& outlog);
	static void InitUDPSocket(bool& shouldTerminateFlag, int& socketfd, std::ofstream& outlog);
	static void BindSocket(bool& shouldTerminateFlag, int socketfd,
			const struct sockaddr* addr, socklen_t addlen, std::ofstream& outlog);
	static void ListenSafe(bool& shouldTerminateFlag, int socketfd,
			int waitingListCap, std::ofstream& outlog);
	static void AcceptSafe(bool& shouldTerminateFlag, int& client,int socketfd,
			struct sockaddr* addr, socklen_t* addlen, std::ofstream& outlog);
	static void ReadSafe(bool& shouldTerminateFlag, int socketfd,
			void *buffer, size_t count, std::ofstream& outlog);
	static void WriteSafe(bool& shouldTerminateFlag, int socketfd,
			const void *buffer, size_t count, std::ofstream& outlog);
	static void RecieveSafe(bool& shouldTerminateFlag, int socketfd,
			void *buffer, size_t size, int flags, std::ofstream& outlog);
	static void SendSafe(bool& shouldTerminateFlag, int socketfd,
			void *buffer, size_t size, int flags, std::ofstream& outlog);
	static void CloseSafe(bool& shouldTerminateFlag, int socketfd, std::ofstream& outlog);
	static size_t RecieveFromSafe(bool& shouldTerminateFlag, int socketfd,
			void * buffer, size_t lenght, const int flags,
			struct sockaddr * address, socklen_t* address_len, std::ofstream& outlog);
	static size_t SendToSafe(bool& shouldTerminateFlag, int socketfd,
			const void * message, size_t lenght, const int flags,
			const struct sockaddr * address, socklen_t dest_len, std::ofstream& outlog);
	std::thread* listenThread = nullptr;
	/*std::thread* logicThread1 = nullptr;
	std::thread* logicThread2 = nullptr;*/
	std::thread* sendThread1 = nullptr;
	std::thread* sendThread2 = nullptr;
	std::thread* parseThread = nullptr;
	std::thread* loginThread = nullptr;
	std::thread* queryThread = nullptr;
	static std::stack<std::thread> waitingLogicThreads;
	static std::stack<std::thread> activeLogicThreads;
	static std::queue<int> recieveQueue;
	static std::queue<int> sendQueue1;
	static std::queue<int> sendQueue2;
	static std::queue<int> parseQueue;
	static std::queue<int> loginQueue;
	static FLAG serverIsClosing;
	static int loginsfd, serversfd, querysfd, sendsfd1, sendsfd2;
	static struct sockaddr_in loginsocket, serversocket, sendsocket1, sendsocket2, querysocket;
	static std::vector<sockaddr_in> connectedEntities;
	static std::vector<size_t> connectedEntitiesSizes;
	static std::vector<int> clientSockets;
	static std::ofstream loginLog, listenLog, logicLog1, logicLog2, sendLog1, sendLog2;
	static int GenerateID();
	static int ReadBytes(char data, int shift);
};

#endif /* SOURCE_FILES_SERVER_H_ */
