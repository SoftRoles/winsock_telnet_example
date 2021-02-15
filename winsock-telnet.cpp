/*
	Step 1: Initialise Winsock
*/

//#include<stdio.h>
//#include<winsock2.h>
//
//#pragma comment(lib,"ws2_32.lib") //Winsock Library
//
//int main(int argc, char* argv[])
//{
//	WSADATA wsa;
//
//	printf("\nInitialising Winsock...");
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//	{
//		printf("Failed. Error Code : %d", WSAGetLastError());
//		return 1;
//	}
//
//	printf("Initialised.");
//
//	return 0;
//}

/*
	Step 2: Create a TCP socket
*/

//#include<stdio.h>
//#include<winsock2.h>
//
//#pragma comment(lib,"ws2_32.lib") //Winsock Library
//
//int main(int argc, char* argv[])
//{
//	WSADATA wsa;
//	SOCKET s;
//
//	printf("\nInitialising Winsock...");
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//	{
//		printf("Failed. Error Code : %d", WSAGetLastError());
//		return 1;
//	}
//
//	printf("Initialised.\n");
//
//
//	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//	{
//		printf("Could not create socket : %d", WSAGetLastError());
//	}
//
//	printf("Socket created.\n");
//
//	return 0;
//}

/*
	Step 3: Create a TCP socket
*/

//#include<stdio.h>
//#include<winsock2.h>
//
//#pragma comment(lib,"ws2_32.lib") //Winsock Library
//#pragma warning(disable : 4996)
//
//int main(int argc, char* argv[])
//{
//	WSADATA wsa;
//	SOCKET s;
//	struct sockaddr_in server;
//
//	printf("\nInitialising Winsock...");
//	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
//	{
//		printf("Failed. Error Code : %d", WSAGetLastError());
//		return 1;
//	}
//
//	printf("Initialised.\n");
//
//	//Create a socket
//	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
//	{
//		printf("Could not create socket : %d", WSAGetLastError());
//	}
//
//	printf("Socket created.\n");
//
//	// time info: india.colorado.edu -> 128.138.140.44:13
//	server.sin_addr.s_addr = inet_addr("128.138.140.44");
//	server.sin_family = AF_INET;
//	server.sin_port = htons(13);
//
//	//Connect to remote server
//	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
//	{
//		puts("connect error");
//		return 1;
//	}
//
//	puts("Connected");
//
//	return 0;
//}

/*
	Step 4: Receive message
*/

#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma warning(disable : 4996)

int main(int argc, char* argv[])
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	char server_reply[20000];
	int recv_size;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");


	// time info: india.colorado.edu -> 128.138.140.44:13
	// if connection by hostname required see complete tutorial:
	// https://www.binarytides.com/winsock-socket-programming-tutorial/
	server.sin_addr.s_addr = inet_addr("213.136.8.188");
	//server.sin_addr.s_addr = inet_addr("128.138.140.44");
	server.sin_family = AF_INET;
	//server.sin_port = htons(13);
	server.sin_port = htons(23);

	//Connect to remote server
	if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	////Receive a reply from the server
	//if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
	//{
	//	puts("recv failed");
	//}

	//puts("Reply received\n");

	////Add a NULL terminating character to make it a proper string before printing
	//server_reply[recv_size] = '\0';
	//puts(server_reply);

	while (true) {
		if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
		{
			puts("recv failed");
		}

		puts("Reply received\n");

		//Add a NULL terminating character to make it a proper string before printing
		server_reply[recv_size] = '\0';
		puts(server_reply);
		//Sleep(10);
		server_reply[0] = '\0';

	}
	

	closesocket(s);
	WSACleanup();

	return 0;
}