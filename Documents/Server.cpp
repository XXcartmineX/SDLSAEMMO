/*
 * Server.cpp
 *
 *  Created on: May 24, 2017
 *      Author: komo97
 */

#include "Header files/Server.h"

Server* Server::instance = nullptr;
FLAG Server::serverIsClosing = false;
std::queue<int> Server::recieveQueue;
std::queue<int> Server::sendQueue1;
std::queue<int> Server::sendQueue2;
std::queue<int> Server::parseQueue;
std::queue<int> Server::loginQueue;
std::stack<std::thread> Server::waitingLogicThreads,
	Server::activeLogicThreads;
int Server::loginsfd;
int Server::serversfd;
int Server::querysfd;
int Server::sendsfd1;
int Server::sendsfd2;
sockaddr_in Server::loginsocket,
Server::serversocket,
Server::sendsocket1,
Server::sendsocket2,
Server::querysocket;
std::vector<sockaddr_in> Server::connectedEntities;
std::vector<size_t> Server::connectedEntitiesSizes;
std::vector<int> Server::clientSockets;
std::ofstream Server::loginLog;
std::ofstream Server::listenLog;
std::ofstream Server::logicLog1;
std::ofstream Server::logicLog2;
std::ofstream Server::sendLog1;
std::ofstream Server::sendLog2;

Server::Server() {
	// TODO Auto-generated constructor stub

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

Server* Server::getInstance(){

	return instance == nullptr ? instance = new Server() : instance;
}

void Server::DestroyServer(){
	delete instance;
}

void Server::App(){
	try{
		ServerInit();
		std::string command;
		const std::string close = "-Close";
		while(!serverIsClosing){
			std::cin >> command;
			if(command == close){
				serverIsClosing = true;
				std::cout << "Server closed" << std::endl;
			}
		}
		std::this_thread::__sleep_for((std::chrono::seconds)5,(std::chrono::nanoseconds)0);
		if(listenThread->joinable())
			listenThread->join();
		delete listenThread;
		std::cout << "thread closed" << std::endl;
		/*if(logicThread1->joinable())
			logicThread1->join();
		delete logicThread1;
		std::cout << "thread closed" << std::endl;
		if(logicThread2->joinable())
			logicThread2->join();
		delete logicThread2;*/
		std::cout << "thread closed" << std::endl;
		if(sendThread1->joinable())
			sendThread1->join();
		delete sendThread1;
		std::cout << "thread closed" << std::endl;
		if(sendThread2->joinable())
			sendThread2->join();
		delete sendThread2;
		std::cout << "thread closed" << std::endl;
		if(parseThread->joinable())
			parseThread->join();
		delete parseThread;
		std::cout << "thread closed" << std::endl;
		if(loginThread->joinable())
			loginThread->join();
		delete loginThread;
		std::cout << "thread closed" << std::endl;
	}
	catch(...){

	}

}

void Server::ServerInit() {
	SocketStructsInit();
	ThreadInit();
}

void Server::ThreadInit() {
	listenThread = new std::thread(UpdateListenThreads);
	listenThread->detach();
	/*logicThread1 = new std::thread(UpdateLogicThreads,std::ref(logicQueue1),std::ref(logicLog1));
	logicThread1->detach();
	logicThread2 = new std::thread(UpdateLogicThreads,std::ref(logicQueue2),std::ref(logicLog2));
	logicThread2->detach();*/
	sendThread1 = new std::thread(UpdateSendingThreads,std::ref(sendQueue1),ServerPortSend1,std::ref(sendLog1));
	sendThread1->detach();
	sendThread2 = new std::thread(UpdateSendingThreads,std::ref(sendQueue2),ServerPortSend1,std::ref(sendLog2));
	sendThread2->detach();
	parseThread = new std::thread(ParseThread);
	parseThread->detach();
	loginThread = new std::thread(LoginThread);
	loginThread->detach();
	queryThread = new std::thread(QueryThread);
	queryThread->detach();
	for(int i = ammountOfLogicThreads; i--;)
		waitingLogicThreads.push(std::thread(UpdateLogicThreads,data,listenLog));
	std::cout << "Threads initialized." << std::endl;
}

void Server::SocketStructsInit() {
	bzero((char*) &loginsocket,	sizeof(loginsocket));
	bzero((char*) &serversocket,sizeof(serversocket));
	bzero((char*) &sendsocket1,	sizeof(sendsocket1));
	bzero((char*) &sendsocket2,	sizeof(sendsocket2));
	bzero((char*) &querysocket, sizeof(querysocket));
	loginsocket.sin_family = AF_INET;
	loginsocket.sin_port = htons(ServerPortLogIn);
	loginsocket.sin_addr.s_addr = INADDR_ANY;
	serversocket.sin_family = AF_INET;
	serversocket.sin_port = htons(ServerPortListen);
	serversocket.sin_addr.s_addr = INADDR_ANY;
	sendsocket1.sin_family = AF_INET;
	sendsocket1.sin_port = htons(ServerPortSend1);
	sendsocket1.sin_addr.s_addr = INADDR_ANY;
	sendsocket2.sin_family = AF_INET;
	sendsocket2.sin_port = htons(ServerPortSend2);
	sendsocket1.sin_addr.s_addr = INADDR_ANY;
	querysocket.sin_family = AF_INET;
	querysocket.sin_port = htons(ServerPortQuery);
	querysocket.sin_addr.s_addr = INADDR_ANY;
	std::cout <<"Sockets initialized" << std::endl;

}

void Server::UpdateListenThreads() {
	listenLog = CreateLogWindow("ListenLog");
	listenLog << "Started listen thread." << std::endl;
	InitUDPSocket(serverIsClosing,serversfd,listenLog);
	listenLog << "Listen socket created" << std::endl;
	BindSocket(serverIsClosing,serversfd,(struct sockaddr *) &serversocket,sizeof(serversocket),listenLog);
	char* data = new char[7];
	unsigned int size;
	bzero(&data,7);
	while(!serverIsClosing){
		for(auto client : connectedEntities)
		{
			size = sizeof(client);
			if(RecieveFromSafe(serverIsClosing,loginsfd,(void*)data,7,NULL,(struct sockaddr *) &client,&size,listenLog) == 6)
			{
				while(waitingLogicThreads.empty());
				//std::thread(UpdateLogicThreads,data,listenLog)
				activeLogicThreads.push(waitingLogicThreads.top());
				waitingLogicThreads.pop();
			}
		}

	}
	listenLog << "Closing the listen server" << std::endl;
	CloseSafe(serverIsClosing,serversfd, listenLog);
	listenLog << "Closed the listen server" << std::endl;
	listenLog.close();
}

void Server::UpdateLogicThreads(char* data, std::ofstream& outlog) {
	if(!serverIsClosing)
	{
		int id = 0, xpos = 0, ypos = 0, inputs = 0, actions = 0;
		id += ReadBytes(data[0],0);
		id += ReadBytes(data[1],8);
		xpos += ReadBytes(data[2],0);
		ypos += ReadBytes(data[3],0);
		inputs += ReadBytes(data[4],0);
		actions += ReadBytes(data[5],0);
		actions += ReadBytes(data[6],8);

	}
}

void Server::UpdateSendingThreads(std::queue<int>& queue, uint16_t port, std::ofstream& outlog) {
	while(!serverIsClosing){

	}
}

void Server::ParseThread() {
	while(!serverIsClosing){

	}
}

void Server::LoginThread() {
	loginLog = CreateLogWindow("LoginLog");
	loginLog << "Started login thread." << std::endl;
	InitTCPSocket(serverIsClosing, loginsfd, loginLog);
	loginLog << "Login socket created." << std::endl;
	BindSocket(serverIsClosing,loginsfd,(struct sockaddr *) &loginsocket,sizeof(loginsocket), loginLog);
	loginLog << "Login socket is bound" << std::endl;
	ListenSafe(serverIsClosing,loginsfd,100, loginLog);
	loginLog << "Login socket is listening." << std::endl;
	int client;
	struct sockaddr_in clientCon;
	char* buff = new char[7000];
	std::string chatlog = "";
	while(!serverIsClosing){
		unsigned int size = sizeof(clientCon);
		bzero((char*) &clientCon, size);
		AcceptSafe(serverIsClosing,client,loginsfd,(struct sockaddr *) &clientCon, &size, loginLog);
		if(client > 0)
		{
			loginLog << "Nueva conexion: " << inet_ntoa(clientCon.sin_addr);
			connectedEntities.push_back(clientCon);
			connectedEntitiesSizes.push_back(size);
			clientSockets.push_back(client);
		}
		for(unsigned int i = 0; i < clientSockets.size(); ++i){
			SendSafe(serverIsClosing,clientSockets.at(i),(void*)chatlog.c_str(),7000,0, loginLog);
		}
		chatlog.clear();
		bzero(buff, sizeof(char)*7000);
		for(unsigned int i = 0; i < clientSockets.size(); ++i){
			RecieveSafe(serverIsClosing, clientSockets.at(i),(void*)buff,7000,0, loginLog);
			if(strcmp(buff,"/close\r\n"))
			{
				chatlog += inet_ntoa(connectedEntities.at(i).sin_addr);
				chatlog += ": ";
				chatlog += buff;
			}
			else{
				loginLog << "Closed conection: "<< inet_ntoa(connectedEntities.at(i).sin_addr);
				CloseSafe(serverIsClosing,clientSockets.at(i),loginLog);
				clientSockets.erase(clientSockets.begin() + i);
				connectedEntities.erase(connectedEntities.begin() + i);
				connectedEntitiesSizes.erase(connectedEntitiesSizes.begin() + i);
			}

		}
		loginLog << chatlog;
		loginLog.flush();
	}
	for(auto cl : clientSockets)
		CloseSafe(serverIsClosing,cl,loginLog);
	loginLog << "Closing the login server" << std::endl;
	CloseSafe(serverIsClosing,loginsfd, loginLog);
	loginLog << "Closed the login server" << std::endl;
	loginLog.close();
}

void Server::QueryThread(){
	while(!serverIsClosing){

	}
}

void Server::InitTCPSocket(bool& shouldTerminateFlag, int& socketfd, std::ofstream& outlog) {
	while(((socketfd = socket(AF_INET,SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0)) == -1) &&
			!shouldTerminateFlag){
		outlog << "Failed to create socket, error: " << errno << std::endl;
		switch(errno)
		{
		case EACCES:
			outlog << "Check your system permissions for creating the socket." << std::endl;
			goto kill;
		case EAFNOSUPPORT:
			outlog << "This implementation does not support your address family." << std::endl;
			goto kill;
		case EINVAL:
			outlog << "Unknown protocol, protocol unavailable or invalid flags. Check again later." <<std::endl;
			goto kill;
		case EMFILE:
			outlog << "Process limit has been reached." << std::endl <<
			"Please clean your memory, this error will loop until the memory is safe again" << std::endl;
			break;
		case ENFILE:
			outlog << "System limit on open files has been reached." << std::endl <<
			"This program will retry until memory has been freed." << std::endl;
			break;
		case ENOBUFS:
		case ENOMEM:
			outlog << "System memory is insufficient." << std::endl <<
			"This program will retry until memory has been freed." << std::endl;
			break;
		case EPROTONOSUPPORT:
			outlog << "This system does not support the protocol." << std::endl;
			goto kill;
		default:
			outlog << "Unknown Error." << std::endl;
			goto kill;
		kill:
			outlog << "Socket can't open. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}

	}
}

void Server::BindSocket(bool& shouldTerminateFlag, int socketfd,
		const struct sockaddr* addr, socklen_t addlen, std::ofstream& outlog) {
	while(bind(socketfd,addr,addlen) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EACCES:
			outlog << "The address is protected, and the user is not the superuser." << std::endl;
			goto kill;
		case EADDRINUSE:
			outlog << "The address is already in use or the port number was specified as zero" << std::endl <<
			"and there are no empty sockets in that area for use." << std::endl;
			goto kill;
		case EBADF:
			outlog << "The socket structure is invalid" << std::endl;
			goto kill;
		case EINVAL:
			outlog << "The socket is already bound to an address or the address structure is invalid." << std::endl;
			goto kill;
		case ENOTSOCK:
			outlog << "The file descriptor does not refer to a socket." << std::endl;
			goto kill;
		case EADDRNOTAVAIL:
			outlog << "A non existent interface was requested." << std::endl;
			goto kill;
		case EFAULT:
			outlog << "The address points outside the user's accessible address space." << std::endl;
			goto kill;
		case ELOOP:
			outlog << "To many symbolic links were encountered in resolving the address." << std::endl;
			goto kill;
		case ENAMETOOLONG:
			outlog << "The address name is too long." << std::endl;
			goto kill;
		case ENOENT:
			outlog << "A component in the directory of the socket pathname does not exist." << std::endl;
			goto kill;
		case ENOMEM:
			outlog << "Kernel memory was insufficient." << std::endl;
			break;
		case ENOTDIR:
			outlog << "A component in the directory of the socket path is not a directory." << std::endl;
			goto kill;
		case EROFS:
			outlog << "The socket would reside on a read only file system." << std::endl;
			goto kill;
		default:
			outlog << "Unknown Error." << std::endl;
			goto kill;
		kill:
			outlog << "Socket couldn't bind. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	}
}

void Server::ListenSafe(bool& shouldTerminateFlag, int socketfd,
		int waitingListCap, std::ofstream& outlog) {
	while(listen(socketfd,waitingListCap) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EADDRINUSE:
			outlog << "The address is already being used or you failed to bind it." << std::endl;
			goto kill;
		case EBADF:
			outlog << "socketfd is not a valid file descriptor." << std::endl;
			goto kill;
		case ENOTSOCK:
			outlog << "socketfd is not a socket." << std::endl;
			goto kill;
		case EOPNOTSUPP:
			outlog << "The socket doesn't support listening." << std::endl;
			goto kill;
		default:
			outlog << "Unknown error." <<std::endl;
		kill:
			outlog << "Socket can't listen. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	}
}

void Server::AcceptSafe(bool& shouldTerminateFlag, int& client, int socketfd,
		struct sockaddr* addr, socklen_t* addlen, std::ofstream& outlog) {
	while((client = accept(socketfd,addr,addlen)) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EAGAIN:
			//outlog << "No connections are available." << std::endl;
			goto safebreak;
		case EBADF:
			outlog << "socketfd is not an open file descriptor." << std::endl;
			goto kill;
		case ECONNABORTED:
			outlog << "The connection with the client has been aborted." << std::endl;
			goto safebreak;
		case EFAULT:
			outlog << "The address argument is not i0n a writable part of the user address space." << std::endl;
			goto safebreak;
		case EINTR:
			outlog << "The system call was interrupted by a signal that was caught before a valid connection arrived." << std::endl;
			goto safebreak;
		case EINVAL:
			outlog << "Invalid value in flags." << std::endl;
			goto kill;
		case EMFILE:
			outlog << "The per-process limit on the number of open fd has been reached." << std::endl;
			goto safebreak;
		case ENFILE:
			outlog << "The system-widw limit on the total number of open files has been reached." << std::endl;
			goto safebreak;
		case ENOBUFS:
		case ENOMEM:
			outlog << "Not enough free memory."<<std::endl;
			goto safebreak;
		case ENOTSOCK:
			outlog << "The file descriptor does not refer to a socket." << std::endl;
			goto kill;
		case ESOCKTNOSUPPORT:
		case EOPNOTSUPP:
			outlog << "The referenced socket is not of type SOCK_STREAM" << std::endl;
			goto safebreak;
		case EPROTONOSUPPORT:
		case EPROTO:
			outlog << "Protocol error" << std::endl;
			goto safebreak;
		case EPERM:
			outlog << "Firewall rules forbid connection." << std::endl;
			goto kill;
		case ETIMEDOUT:
			outlog << "Timeout on connection." << std::endl;
			goto safebreak;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		//outlog << "It is safe to continue..." << std::endl;
		break;
	}
}

void Server::ReadSafe(bool& shouldTerminateFlag, int socketfd, void* buffer, size_t count,
		std::ofstream& outlog) {
	while(read(socketfd,buffer,count) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EAGAIN:
			outlog << "The file descriptor fd refers to a file other than a socket and has been marked non blocking." << std::endl;
			goto safebreak;
		case EBADF:
			outlog << "fd is not a valid file descriptor or is not open for reading." << std::endl;
			goto safebreak;
		case EFAULT:
			outlog << "Buffer is outside your accessible address space." << std::endl;
			goto safebreak;
		case EINTR:
			outlog << "The call was interrupted by a signal before any data was read." << std::endl;
			goto safebreak;
		case EINVAL:
			outlog << "fd is unreadable or the size is not suitably aligned." << std::endl;
			goto safebreak;
		case EIO:
			outlog << "Input output error." << std::endl;
			goto safebreak;
		case EISDIR:
			outlog << "fd refers to a directory." << std::endl;
			goto safebreak;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;
	}
}

void Server::WriteSafe(bool& shouldTerminateFlag, int socketfd, const void* buffer, size_t count,
		std::ofstream& outlog) {
	while(write(socketfd,buffer,count) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EAGAIN:
			outlog << "The file descriptor refers to a file other than a socket and has been marked nonblocking" << std::endl;
			goto safebreak;
		case EBADF:
			outlog << "fd is not a valid file descriptor or is not open for writing."<<std::endl;
			goto safebreak;
		case EDESTADDRREQ:
			outlog << "fd refers to a datagram socket for which a peer address has not been set using connect" << std::endl;
			goto safebreak;
		case EDQUOT:
			outlog << "The user quota of disk blocks on the file system has been exhausted." << std::endl;
			goto safebreak;
		case EFAULT:
			outlog << "The buffer is outside your accessible address space." << std::endl;
			goto safebreak;
		case EFBIG:
			outlog << "An attempt was made to write a file that exceeds the implementation-defined maximum file size." << std::endl;
			goto safebreak;
		case EINTR:
			outlog << "The call was interrupted by a signal before any data was written." << std::endl;
			goto safebreak;
		case EINVAL:
			outlog << "fd is attached to an object which is unsuitable for writing." << std::endl;
			goto safebreak;
		case EIO:
			outlog << "Input output error" << std::endl;
			goto safebreak;
		case ENOSPC:
			outlog << "There is no room for the data" << std::endl;
			goto safebreak;
		case EPERM:
			outlog << "The operator was prevented by a file seal." << std::endl;
			goto safebreak;
		case EPIPE:
			outlog << "fd is connected to a pipe or socket whose reading end is closed." << std::endl;
			goto safebreak;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;
	}
}

void Server::RecieveSafe(bool& shouldTerminateFlag, int socketfd, void* buffer,
		size_t size, int flags, std::ofstream& outlog) {
	while(recv(socketfd,buffer,size,flags) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
		case EAGAIN:
			outlog << "The file descriptor fd refers to a file other than a socket and has been marked non blocking." << std::endl;
			goto safebreak;
		case EBADF:
			outlog << "fd is not a valid file descriptor or is not open for reading." << std::endl;
			goto safebreak;
		case EFAULT:
			outlog << "Buffer is outside your accessible address space." << std::endl;
			goto safebreak;
		case EINTR:
			outlog << "The call was interrupted by a signal before any data was read." << std::endl;
			goto safebreak;
		case ECONNREFUSED:
			outlog << "The connection refused." << std::endl;
			goto safebreak;
		case EINVAL:
			outlog << "fd is unreadable or the size is not suitably aligned." << std::endl;
			goto safebreak;
		case ENOMEM:
			outlog << "There's no memory left for reading." << std::endl;
			goto safebreak;
		case ENOTCONN:
			outlog << "The socket is associated with a connection oriented protocol and has not been connected."<< std::endl;
			goto safebreak;
		case ENOTSOCK:
			outlog << "The file descriptor is not a socket." << std::endl;
			goto safebreak;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;
	}
}

void Server::SendSafe(bool& shouldTerminateFlag, int socketfd, void* buffer,
		size_t size, int flags, std::ofstream& outlog) {
	while(send(socketfd,buffer,size,flags) == -1 &&
			!shouldTerminateFlag){
		switch(errno){
				case EAGAIN:
					outlog << "The file descriptor refers to a file other than a socket and has been marked nonblocking" << std::endl;
					goto safebreak;
				case EBADF:
					outlog << "fd is not a valid file descriptor or is not open for writing."<<std::endl;
					goto safebreak;
				case EDESTADDRREQ:
					outlog << "fd refers to a datagram socket for which a peer address has not been set using connect" << std::endl;
					goto safebreak;
				case EDQUOT:
					outlog << "The user quota of disk blocks on the file system has been exhausted." << std::endl;
					goto safebreak;
				case EFAULT:
					outlog << "The buffer is outside your accessible address space." << std::endl;
					goto safebreak;
				case EFBIG:
					outlog << "An attempt was made to write a file that exceeds the implementation-defined maximum file size." << std::endl;
					goto safebreak;
				case EINTR:
					outlog << "The call was interrupted by a signal before any data was written." << std::endl;
					goto safebreak;
				case EINVAL:
					outlog << "fd is attached to an object which is unsuitable for writing." << std::endl;
					goto safebreak;
				case EIO:
					outlog << "Input output error" << std::endl;
					goto safebreak;
				case ENOSPC:
					outlog << "There is no room for the data" << std::endl;
					goto safebreak;
				case EPERM:
					outlog << "The operator was prevented by a file seal." << std::endl;
					goto safebreak;
				case EPIPE:
					outlog << "fd is connected to a pipe or socket whose reading end is closed." << std::endl;
					goto safebreak;
				default:
					outlog << "Unknown error." << std::endl;
					goto kill;
				kill:
					outlog << "Could not accept connection. Closing down..." << std::endl;
					shouldTerminateFlag = true;
					break;
				}
			safebreak:
				outlog << "It is safe to continue..." << std::endl;
				break;
		}

}

std::ofstream Server::CreateLogWindow(const char* name) {
	std::ofstream out;
	std::string path = "/tmp/";
	path += name;
	out.open(path,std::_Ios_Openmode::_S_trunc | std::_Ios_Openmode::_S_out);
	std::string cmd = "gnome-terminal -e 'tail -f ";
	cmd += path;
	cmd += "'";
	system(cmd.c_str());
	return out;
}

void Server::InitUDPSocket(bool& shouldTerminateFlag, int& socketfd,
		std::ofstream& outlog) {
	while(((socketfd = socket(AF_INET,SOCK_DGRAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0)) == -1) &&
				!shouldTerminateFlag){
			outlog << "Failed to create socket, error: " << errno << std::endl;
			switch(errno)
			{
			case EACCES:
				outlog << "Check your system permissions for creating the socket." << std::endl;
				goto kill;
			case EAFNOSUPPORT:
				outlog << "This implementation does not support your address family." << std::endl;
				goto kill;
			case EINVAL:
				outlog << "Unknown protocol, protocol unavailable or invalid flags. Check again later." <<std::endl;
				goto kill;
			case EMFILE:
				outlog << "Process limit has been reached." << std::endl <<
				"Please clean your memory, this error will loop until the memory is safe again" << std::endl;
				break;
			case ENFILE:
				outlog << "System limit on open files has been reached." << std::endl <<
				"This program will retry until memory has been freed." << std::endl;
				break;
			case ENOBUFS:
			case ENOMEM:
				outlog << "System memory is insufficient." << std::endl <<
				"This program will retry until memory has been freed." << std::endl;
				break;
			case EPROTONOSUPPORT:
				outlog << "This system does not support the protocol." << std::endl;
				goto kill;
			default:
				outlog << "Unknown Error." << std::endl;
				goto kill;
			kill:
				outlog << "Socket can't open. Closing down..." << std::endl;
				shouldTerminateFlag = true;
				break;
			}

		}
}

void Server::CloseSafe(bool& shouldTerminateFlag, int socketfd, std::ofstream& outlog) {
	while(close(socketfd) == -1 &&
			 !shouldTerminateFlag){
		switch(errno){
		case EBADF:
			outlog << "fd is not a valid open file descriptor." << std::endl;
			goto safebreak;
		case EINTR:
			outlog << "The call was interrupted by a signal." << std::endl;
			break;
		case EIO:
			outlog << "An input output error has ocurred." << std::endl;
			break;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;
	}
}

size_t Server::RecieveFromSafe(bool& shouldTerminateFlag, int socketfd,
		void* buffer, size_t lenght, const int flags, struct sockaddr* address,
		socklen_t* address_len, std::ofstream& outlog) {
	size_t retsize;
	while((retsize = recvfrom(socketfd,buffer, lenght, flags, address, address_len))<= 0 &&
			!shouldTerminateFlag){
		switch(errno){ //tengo que ayudar a mi waifu... me necesita...
		case EAGAIN:
			outlog << "There is already a functional operation over this socket" << std::endl;
			break;
		case EBADF:
			outlog << "The socket argument is not a valid file descriptor" << std::endl;
			goto kill;
		case ECONNRESET:
			outlog << "A connection was forcibly closed by a peer" <<std::endl;
			goto safebreak;
		case EINTR:
			outlog << "A signal interrupted recvfrom() before any data was available" << std::endl;
			break;
		case EINVAL:
			outlog << "The MSG_OOB flag is set and no out-of-band data is available" << std::endl;
			goto kill;
		case ENOTCONN:
			outlog << "A receive is attempted on a connection-mode socket that is not connected" << std::endl;
			goto safebreak;
		case ENOTSOCK:
			outlog << "The socket argument does not refer to a socket." << std::endl;
			goto kill;
		case EOPNOTSUPP:
			outlog << "The specified flags are not supported for this socket type" << std::endl;
			goto safebreak;
		case ETIMEDOUT:
			outlog << "The connection timed out during connection establishment, or due to a transmission timeout on active connection" << std::endl;
			goto safebreak;
		case EIO:
			outlog << "An I/O error occurred while reading from or writing to the file system." << std::endl;
			break;
		case ENOBUFS:
			outlog << "Insufficient resources were available in the system to perform the operation." << std::endl;
			break;
		case ENOMEM:
			outlog << "Insufficient memory was available to fulfill the request" << std::endl;
			break;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;

	}
	return retsize;
}

size_t Server::SendToSafe(bool& shouldTerminateFlag, int socketfd, const void* message,
		size_t lenght, const int flags, const struct sockaddr* address,
		socklen_t dest_len, std::ofstream& outlog) {
	size_t retsize;
	while((retsize = sendto(socketfd,message,lenght,flags,address,dest_len)) == 1 &&
			! shouldTerminateFlag){
		switch (errno){
		case EAFNOSUPPORT:
			outlog << "Addresses in the specified address family cannot be used with this socket." << std::endl;
			goto kill;
		case EWOULDBLOCK:
			outlog << "The socket's file descriptor is marked O_NONBLOCK and the requested operation would block." << std::endl;
			goto safebreak;
		case EBADF:
			outlog << "The socket argument is not a valid file descriptor." << std::endl;
			goto kill;
		case ECONNRESET:
			outlog << "A connection was forcibly closed by a peer."<< std::endl;
			goto safebreak;
		case EINTR:
			outlog << "A signal interrupted sendto() before any data was transmitted." << std::endl;
			break;
		case EMSGSIZE:
			outlog << "The message is too large to be sent all at once, as the socket requires." << std::endl;
			goto safebreak;
		case ENOTCONN:
			outlog << "The socket is connection-mode but is not connected." << std::endl;
			break;
		case ENOTSOCK:
			outlog << "The socket argument does not refer to a socket." << std::endl;
			goto safebreak;
		case EOPNOTSUPP:
			outlog << " The socket argument is associated with a socket that does not support one or more of the values set in flags." << std::endl;
			goto safebreak;
		case EPIPE:
			outlog << "The socket is shut down for writing, or the socket is connection-mode and is no longer connected. In the latter case, and if the socket is of type SOCK_STREAM, the SIGPIPE signal is generated to the calling thread." << std::endl;
			goto safebreak;
		case EIO:
			outlog << "An I/O error occurred while reading from or writing to the file system." << std::endl;
			break;
		case ELOOP:
			outlog << "A loop exists in symbolic links encountered during resolution of the pathname in the socket address." << std::endl;
			goto safebreak;
		case ENAMETOOLONG:
			outlog << "A component of a pathname exceeded {NAME_MAX} characters, or an entire pathname exceeded {PATH_MAX} characters." << std::endl;
			goto safebreak;
		case ENOENT:
			outlog << "A component of the pathname does not name an existing file or the pathname is an empty string." << std::endl;
			goto safebreak;
		case ENOTDIR:
			outlog << "A component of the path prefix of the pathname in the socket address is not a directory." << std::endl;
			goto safebreak;
		case EACCES:
			outlog << "Search permission is denied for a component of the path prefix; or write access to the named socket is denied." << std::endl;
			goto safebreak;
		case EDESTADDRREQ:
			outlog << "The socket is not connection-mode and does not have its peer address set, and no destination address was specified." << std::endl;
			goto safebreak;
		case EHOSTUNREACH:
			outlog << "The destination host cannot be reached (probably because the host is down or a remote router cannot reach it)." << std::endl;
			goto safebreak;
		case EINVAL:
			outlog << "The dest_len argument is not a valid length for the address family." << std::endl;
			goto safebreak;
		case EISCONN:
			outlog << "A destination address was specified and the socket is already connected. This error may or may not be returned for connection mode sockets." << std::endl;
			goto safebreak;
		case ENETDOWN:
			outlog << "The local network interface used to reach the destination is down." << std::endl;
			break;
		case ENETUNREACH:
			outlog << "No route to the network is present." << std::endl;
			goto kill;
		case ENOBUFS:
			outlog << "Insufficient resources were available in the system to perform the operation." << std::endl;
			break;
		case ENOMEM:
			outlog << "Insufficient memory was available to fulfill the request." << std::endl;
			break;
		default:
			outlog << "Unknown error." << std::endl;
			goto kill;
		kill:
			outlog << "Could not accept connection. Closing down..." << std::endl;
			shouldTerminateFlag = true;
			break;
		}
	safebreak:
		outlog << "It is safe to continue..." << std::endl;
		break;

		}
		return retsize;
}

int Server::GenerateID() {
	return 0;
}

int Server::ReadBytes(char data, int shift) {
	int ret = 0;
	for(int i = 8; i--;){
		ret += data % 2;
		data = data >> 1;
	}
	ret = ret << shift;
	return ret;
}
