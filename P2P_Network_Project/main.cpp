#include <iostream>
#include "main.h"

using namespace std;

int main()
{
	WSADATA wsdata;
	int v_check = WSAStartup(MAKEWORD(2, 2), &wsdata);
	if (v_check != 0) {									// 0�� �� True , ������ false
		cout << "������ Ȯ�� ���ּ���" << "\n";
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

	// accept();  Ŭ���̾�Ʈ�� ������ �� �ϸ� ������ �����·� ����
	// WSAAsyncSelect(); ������ �� �̿��Ҷ� �񵿱� ������ ó����

	// ������ ���� ����
	// 


	WSACleanup();

}