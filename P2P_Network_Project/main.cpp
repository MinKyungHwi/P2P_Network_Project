#include <iostream>
#include "main.h"

using namespace std;

int main()
{
	WSADATA wsdata;
	int v_check = WSAStartup(MAKEWORD(2, 2), &wsdata);
	if (v_check != 0) {									// 0일 때 True , 나머지 false
		cout << "버전을 확인 해주세요" << "\n";
	}

	SOCKET ser_sock;
	ser_sock = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN ser_addr;
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(30000);
	ser_addr.sin_addr.S_un.S_addr = ADDR_ANY;

	if (bind(ser_sock, (SOCKADDR*)&ser_addr, sizeof(ser_addr)) == SOCKET_ERROR) 
	{
		cout << "bind fail" << WSAGetLastError() << "\n";
	}

	
	if (listen(ser_sock, SOMAXCONN) == SOCKET_ERROR)
	{
		cout << "listen fail" << WSAGetLastError() << "\n";
	}

	// accept();  클라이언트가 접근을 안 하면 무한정 대기상태로 빠짐
	// WSAAsyncSelect(); 윈도우 폼 이용할때 비동기 식으로 처리함

	// 스레드 개념 배우기
	// 


	WSACleanup();

}