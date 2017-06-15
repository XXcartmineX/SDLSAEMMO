#include "Client.h"
#include "RPGSAEMMOApp.h"


Client* Client::Instance = nullptr;
WSADATA Client::wsa;
Client* Client::getInstanse()
{
	return Instance == nullptr ? Instance = new Client() : Instance;
}

bool Client::LogIn(std::string x, std::string y)
{
	


	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
		return false;
	}
	printf("Initialised.\n");
	SocketSafe(AF_INET,SOCK_STREAM,0,s);
	AdressFill(si_other, iP.c_str(),TCPport);
	ConnectSafe(s,(sockaddr*)&si_other,slen);
	sendSafe(s, x.c_str(), BUFLEN ,0);
	sendSafe(s, y.c_str(), BUFLEN, 0);

	recvSafe(s, buf, BUFLEN, 0);
	char *_iD = new char[2];
	if (!strcmp(buf, "Close"))
	{
		closesocket(s);
		return false;
	}
	else
	{
		std::cout << "Conectado \n";
		recvSafe(s, _iD, 2, 0);
		iD += ReadBytes(_iD[0], 0);
		iD += ReadBytes(_iD[1], 8);
		closesocket(s);
	}

	return SDL_TRUE;

} 


void Client::Update()
{
	SocketSafe(AF_INET, SOCK_DGRAM, 0, s);
	AdressFill(si_other, iP.c_str(), UDPport);
	while (RPGSAEMMOApp::ApplicationIsClosing())
	{
		

	

		
	}
}


void Client::SocketSafe(const int _IN connectionType, 
	const int _IN socketType, const int _IN slayerTipe, SOCKET _OUT outSocket)
{
	//AF significa que nos vamos a conectar a internet con un puerto tipo ipv6
	//Sock_Stream, nos vamos a conectar con un rio de informacion, el 0 es un parametro para definir si quieres usar un tipo de conexion especial, vamos a trabajar con TCP
	while (!RPGSAEMMOApp::ApplicationIsClosing() &&
		(outSocket = socket(connectionType, socketType, slayerTipe)) == INVALID_SOCKET)
	{
		//Funciones seguras
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "Pendejo inicializa la libreria primero cawn!! \n";
			goto kill;
		case WSAENETDOWN:
			std::cout << "Pendejo conectate a internet!! \n";
			goto kill;
		case WSAEAFNOSUPPORT:
			std::cout << "Pendejo actualiza tu computadora  \n";
			goto kill;
		case WSAEINPROGRESS:
			std::cout << "Pendejo ya entraste, deja de mamar, ya inicializaste \n";
			break;
		case WSAEMFILE:
			std::cout << "Pendejo ya no puedes crear mas archivos \n";
			goto kill;
		case WSAEINVAL:
			std::cout << "Pendejo inicializa bien, escribiste mal algo \n";
			goto kill;
		case WSAEINVALIDPROVIDER:
			std::cout << "Pendejo checa tu version del Windows sockets application \n";
			goto kill;
		case WSAEINVALIDPROCTABLE:
			std::cout << "Pendejo el programa se programa se apendejo, tu tranqui \n";
			break;
		case WSAENOBUFS:
			std::cout << "Pendejo no tienes espacio espacio en el Buffer, cierra tu porno \n";
			break;
		case WSAEPROTONOSUPPORT:
			std::cout << "Pendejo tu protocolo no es soportado \n";
			goto kill;
		case WSAEPROTOTYPE:
			std::cout << "Pendejo este socket no funciona con el protocolo que quieres usar \n";
			goto kill;
		case WSAEPROVIDERFAILEDINIT:
			std::cout << "Pendejo el servidor no pudo inicializar  \n";
			break;
		case WSAESOCKTNOSUPPORT:
			std::cout << "Pendejo este tipo de socket no funciona con este tipo de libreria \n";
			goto kill;

		default:
			std::cout << "Pendejo tu error esta hiperPendejo como tu, que ni yo se que peoo, suicidate  \n";
			goto kill;

		kill: std::cout << "Ah C mamo, cerrando... \n";
			RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
			break;
		}
	}

}

void Client::ConnectSafe(SOCKET _IN sock, const sockaddr * _IN serv, size_t _IN sizeOfserver)
{
	
		
	while (!RPGSAEMMOApp::ApplicationIsClosing() && 
		connect(sock, serv, sizeOfserver) < 0)
	{
		
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "NO INICIALIZASTE" << std::endl;
			goto kill;
		case WSAENETDOWN:
			std::cout << "NO HAY INTERNET" << std::endl;
			goto kill;
		case WSAEADDRINUSE:
			std::cout << "ADDRESS IN USE" << std::endl;
			goto kill;
		case WSAEINTR:
			std::cout << "THE CALL WAS CANCELED" << std::endl;
			goto kill;
		case WSAEALREADY:
			std::cout << "ALREADY CONNECTED" << std::endl;
			goto kill;
		case WSAEADDRNOTAVAIL:
			std::cout << "INVALID ADDRESS" << std::endl;
			goto kill;
		case WSAEAFNOSUPPORT:
			std::cout << "NO SUPPORT FOR THE FAMILY" << std::endl;
			goto kill;
		case WSAEFAULT:
			std::cout << "INCORRECT ADDRESS FORMAT" << std::endl;
			goto kill;
		case WSAEINVAL:
			std::cout << "THE SOCKET IS LISTENING" << std::endl;
			goto kill;
		case WSAEISCONN:
			std::cout << "ALREADY CONNECTED" << std::endl;
			goto kill;
		case WSAENETUNREACH:
			std::cout << "NET UNREACHABLE" << std::endl;
			goto kill;
		case WSAENOBUFS:
			std::cout << "NO BUFFER AVAILABLE" << std::endl;
			goto kill;
		case WSAENOTSOCK:
			std::cout << "NOT A SOCKET" << std::endl;
			goto kill;
		case WSAETIMEDOUT:
			std::cout << "TIMED OUT" << std::endl;
			goto kill;
		case WSAEWOULDBLOCK:
			std::cout << "CALL IS BLOCKED" << std::endl;
			goto kill;
		case WSAEACCES:
			std::cout << "DATAGRAM FAILED" << std::endl;
		default:
			std::cout << "Pendejo tu error esta hiperPendejo como tu, que ni yo se que peoo, suicidate  \n";
			goto kill;

		kill: std::cout << "Ah C mamo, cerrando... \n";
			RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
			
			break;
		}
		std::cout << "FUCK";

	}
}

void Client::AdressFill(sockaddr_in _OUT sock, const char* _IN ip,int _IN port)
{
	sock.sin_family = AF_INET;
	sock.sin_port = htons(port);
	InetPton(AF_INET, ip, &sock.sin_addr);
}

void Client::recieveFromSafe(SOCKET _IN sock, char* _OUT  buf, int _IN len,
	int _IN flags, struct sockaddr* _OUT from, int* _INOUT fromlen)
{
	while (!RPGSAEMMOApp::ApplicationIsClosing() && recvfrom(sock,buf, len, flags,from,fromlen))
	{
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "NO INICIALIZASTE" << std::endl;
			goto kill;
		case WSAENETDOWN:
			std::cout << "NO HAY INTERNET" << std::endl;
			goto kill;
		case WSAEFAULT:
			std::cout << "INCORRECT ADDRESS FORMAT" << std::endl;
			goto kill;
		case WSAEINTR:
			std::cout << "THE CALL WAS CANCELED" << std::endl;
			goto kill;
		case WSAEINPROGRESS:
			std::cout << "Un Socket de Windows esta en progreso o el proveedor esta en proceso " << std::endl;
			goto safeBreak;
		case WSAEINVAL:
			std::cout << "THE SOCKET IS LISTENING" << std::endl;
			goto kill;
		case WSAEISCONN:
			std::cout << "ALREADY CONNECTED" << std::endl;
			goto kill;
		case WSAENETRESET:
			std::cout << "El tiempo ha acabado" << std::endl;
			goto kill;
		case WSAENOTSOCK:
			std::cout << "Este parametro no es un socket" << std::endl;
			goto kill;
		case WSAEOPNOTSUPP:
			std::cout << "No hay soporte en la comunicacion del Dominio" << std::endl;
			goto safeBreak;
		case WSAESHUTDOWN:
			std::cout << "Tu Socket se apago" << std::endl;
			goto kill;
		case WSAEWOULDBLOCK:
			std::cout << "CALL IS BLOCKED" << std::endl;
			goto kill;
		case WSAEMSGSIZE:
			std::cout << "Tu mensaje es muy largo" << std::endl;
			goto safeBreak;
		case WSAETIMEDOUT:
			std::cout << "TIMED OUT" << std::endl;
			goto kill;
		case WSAECONNRESET:
			std::cout << "El puerto no puede ser alcanzado" << std::endl;
			goto kill;
		default:
			std::cout << "Pendejo tu error me da sida... y ese sida mato mi cancer de testiculos... \n";
			goto kill;
		kill: std::cout << "Cerrando papuh \n";
			RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
		}
		safeBreak:
			std::cout << "Todo tranqui, sigue adelante..." << std::endl;
			break;
	}
}

void Client::sendToSafe(SOCKET _IN sock, const char* _IN buf, int _IN len, int _IN flags,
	const struct sockaddr* _IN to, int _IN tolen)
{
	while (!RPGSAEMMOApp::ApplicationIsClosing() && sendto(sock, buf, len, flags, to, tolen))
	{
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "NO INICIALIZASTE" << std::endl;
			goto kill;
		case WSAENETDOWN:
			std::cout << "NO HAY INTERNET" << std::endl;
			goto kill;
		case WSAEACCES:
			std::cout << "DATAGRAM FAILED" << std::endl;
			break;
		case WSAEINVAL:
			std::cout << "THE SOCKET IS LISTENING" << std::endl;
			goto kill;
		case WSAEINTR:
			std::cout << "THE CALL WAS CANCELED" << std::endl;
			goto kill;
		case WSAEINPROGRESS:
			std::cout << "Un Socket de Windows esta en progreso o el proveedor esta en proceso " << std::endl;
			goto safeBreak;
		case WSAEFAULT:
			std::cout << "INCORRECT ADDRESS FORMAT" << std::endl;
			goto kill;
		case WSAENETRESET:
			std::cout << "La conexion esta rota GG" << std::endl;
			goto safeBreak;
		case WSAENOBUFS:
			std::cout << "No hay espacio en el buffer" << std::endl;
			goto kill;
		case WSAENOTCONN:
			std::cout << "El socket no esta conectado" << std::endl;
			goto kill;
		case WSAENOTSOCK:
			std::cout << "NOT A SOCKET" << std::endl;
			goto kill;
		case WSAEOPNOTSUPP:
			std::cout << "El socket no tiene support y se la avento solo ADC GG" << std::endl;
			goto safeBreak;
		case WSAESHUTDOWN:
			std::cout << "Tu Socket se apago" << std::endl;
			goto kill;
		case WSAEWOULDBLOCK:
			std::cout << "El socket no esta bloqueado y debe ser bloqueado" << std::endl;
			break;
		case WSAEMSGSIZE:
			std::cout << "Tu mensaje es muy largo" << std::endl;
			goto safeBreak;
		case WSAEHOSTUNREACH:
			std::cout << "El Host no se encuentra" << std::endl;
			goto safeBreak;
		case WSAECONNABORTED:
			std::cout << "Ya termino el ciclo o tuve un fallo y se jodio la app" << std::endl;
			goto kill;
		case WSAECONNRESET:
			std::cout << "El puerto no puede ser alcanzado" << std::endl;
			goto kill;
		case WSAEADDRNOTAVAIL:
			std::cout << "el adress no es valido" << std::endl;
			goto kill;
		case WSAEAFNOSUPPORT:
			std::cout << "la familia no es compatible con el socket" << std::endl;
			goto kill;
		case WSAEDESTADDRREQ:
			std::cout << "El adress requiere un destino" << std::endl;
			break;
		case WSAENETUNREACH:
			std::cout << "La Network no se encuentra" << std::endl;
			goto safeBreak;
		case WSAETIMEDOUT:
			std::cout << "TIMED OUT" << std::endl;
			goto kill;
		default: std::cout << "No se que paso pero seguro la cagaste \n";
			goto kill;
		kill: std::cout << "se cerro alv \n";
		RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
			break;
		}
	safeBreak:
		std::cout << "Todo tranqui, sigue adelante..." << std::endl;
		break;
	}
}

void Client::sendSafe(SOCKET _IN sock, const char* _IN buf, int _IN len, int _IN flags)
{
	while (!RPGSAEMMOApp::ApplicationIsClosing() && send(sock, buf, len, flags))
	{
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "NO INICIALIZASTE" << std::endl;
			goto kill;
		case WSAENETDOWN:
			std::cout << "NO HAY INTERNET" << std::endl;
			goto kill;
		case WSAEACCES:
			std::cout << "DATAGRAM FAILED" << std::endl;
			break;
		case WSAEINVAL:
			std::cout << "THE SOCKET IS LISTENING" << std::endl;
			goto kill;
		case WSAEINTR:
			std::cout << "THE CALL WAS CANCELED" << std::endl;
			goto kill;
		case WSAEINPROGRESS:
			std::cout << "Un Socket de Windows esta en progreso o el proveedor esta en proceso " << std::endl;
			goto safeBreak;
		case WSAEFAULT:
			std::cout << "INCORRECT ADDRESS FORMAT" << std::endl;
			goto kill;
		case WSAENETRESET:
			std::cout << "La conexion esta rota GG" << std::endl;
			goto safeBreak;
		case WSAENOBUFS:
			std::cout << "No hay espacio en el buffer" << std::endl;
			goto kill;
		case WSAENOTCONN:
			std::cout << "El socket no esta conectado" << std::endl;
			goto kill;
		case WSAENOTSOCK:
			std::cout << "NOT A SOCKET" << std::endl;
			goto kill;
		case WSAEOPNOTSUPP:
			std::cout << "El socket no tiene support y se la avento solo ADC GG" << std::endl;
			goto safeBreak;
		case WSAESHUTDOWN:
			std::cout << "Tu Socket se apago" << std::endl;
			goto kill;
		case WSAEWOULDBLOCK:
			std::cout << "El socket no esta bloqueado y debe ser bloqueado" << std::endl;
			break;
		case WSAEMSGSIZE:
			std::cout << "Tu mensaje es muy largo" << std::endl;
			goto safeBreak;
		case WSAEHOSTUNREACH:
			std::cout << "El Host no se encuentra" << std::endl;
			goto safeBreak;
		case WSAECONNABORTED:
			std::cout << "Ya termino el ciclo o tuve un fallo y se jodio la app" << std::endl;
			goto kill;
		case WSAECONNRESET:
			std::cout << "El puerto no puede ser alcanzado" << std::endl;
			goto kill;
		case WSAEADDRNOTAVAIL:
			std::cout << "el adress no es valido" << std::endl;
			goto kill;
		case WSAEAFNOSUPPORT:
			std::cout << "la familia no es compatible con el socket" << std::endl;
			goto kill;
		case WSAEDESTADDRREQ:
			std::cout << "El adress requiere un destino" << std::endl;
			break;
		case WSAENETUNREACH:
			std::cout << "La Network no se encuentra" << std::endl;
			goto safeBreak;
		case WSAETIMEDOUT:
			std::cout << "TIMED OUT" << std::endl;
			goto kill;
		default: std::cout << "No se que paso pero seguro la cagaste \n";
			goto kill;
		kill: std::cout << "se cerro alv \n";
		RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
			break;
		}
	safeBreak:
		std::cout << "Todo tranqui, sigue adelante..." << std::endl;
		break;
	}
}

void Client::recvSafe(SOCKET _IN sock,  char* _IN buf, int _IN len, int _IN flags)
{
	while (!RPGSAEMMOApp::ApplicationIsClosing() && recv(sock, buf, len, flags))
	{
		switch (WSAGetLastError())
		{
		case WSANOTINITIALISED:
			std::cout << "NO INICIALIZASTE" << std::endl;
			goto kill;
		case WSAENETDOWN:
			std::cout << "NO HAY INTERNET" << std::endl;
			goto kill;
		case WSAEACCES:
			std::cout << "DATAGRAM FAILED" << std::endl;
			break;
		case WSAEINVAL:
			std::cout << "THE SOCKET IS LISTENING" << std::endl;
			goto kill;
		case WSAEINTR:
			std::cout << "THE CALL WAS CANCELED" << std::endl;
			goto kill;
		case WSAEINPROGRESS:
			std::cout << "Un Socket de Windows esta en progreso o el proveedor esta en proceso " << std::endl;
			goto safeBreak;
		case WSAEFAULT:
			std::cout << "INCORRECT ADDRESS FORMAT" << std::endl;
			goto kill;
		case WSAENETRESET:
			std::cout << "La conexion esta rota GG" << std::endl;
			goto safeBreak;
		case WSAENOBUFS:
			std::cout << "No hay espacio en el buffer" << std::endl;
			goto kill;
		case WSAENOTCONN:
			std::cout << "El socket no esta conectado" << std::endl;
			goto kill;
		case WSAENOTSOCK:
			std::cout << "NOT A SOCKET" << std::endl;
			goto kill;
		case WSAEOPNOTSUPP:
			std::cout << "El socket no tiene support y se la avento solo ADC GG" << std::endl;
			goto safeBreak;
		case WSAESHUTDOWN:
			std::cout << "Tu Socket se apago" << std::endl;
			goto kill;
		case WSAEWOULDBLOCK:
			std::cout << "El socket no esta bloqueado y debe ser bloqueado" << std::endl;
			break;
		case WSAEMSGSIZE:
			std::cout << "Tu mensaje es muy largo" << std::endl;
			goto safeBreak;
		case WSAEHOSTUNREACH:
			std::cout << "El Host no se encuentra" << std::endl;
			goto safeBreak;
		case WSAECONNABORTED:
			std::cout << "Ya termino el ciclo o tuve un fallo y se jodio la app" << std::endl;
			goto kill;
		case WSAECONNRESET:
			std::cout << "El puerto no puede ser alcanzado" << std::endl;
			goto kill;
		case WSAEADDRNOTAVAIL:
			std::cout << "el adress no es valido" << std::endl;
			goto kill;
		case WSAEAFNOSUPPORT:
			std::cout << "la familia no es compatible con el socket" << std::endl;
			goto kill;
		case WSAEDESTADDRREQ:
			std::cout << "El adress requiere un destino" << std::endl;
			break;
		case WSAENETUNREACH:
			std::cout << "La Network no se encuentra" << std::endl;
			goto safeBreak;
		case WSAETIMEDOUT:
			std::cout << "TIMED OUT" << std::endl;
			goto kill;
		default: std::cout << "No se que paso pero seguro la cagaste \n";
			goto kill;
		kill: std::cout << "se cerro alv \n";
			RPGSAEMMOApp::ApplicationShouldClose(SDL_TRUE);
			break;
		}
	safeBreak:
		std::cout << "Todo tranqui, sigue adelante..." << std::endl;
		
		break;
	}
}

int Client::ReadBytes(char _IN data, int _IN shift)
{
	int ret = 0;
	for (int i = 8; i--;)
	{
		ret += data % 2;
		data = data >> 1;
	}
	ret = ret << shift;
	return ret;
}
