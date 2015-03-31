/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: multicast.h
--
-- PROGRAM: CommAudio_Client
--
-- DATE: March 12, 2015
--
-- REVISIONS: Created March 10, 2015
--
-- DESIGNER: Michael Chimick
--
-- PROGRAMMER: Michael Chimick
--
-- NOTES:
--
--
----------------------------------------------------------------------------------------------------------------------*/
#ifndef CLIENT_H
#define CLIENT_H
#define NOMINMAX

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib, "winmm.lib")

#define BUFFER 65536
#define DATAGRAM 4096

#define BITS_PER_SAMPLE 16
#define SAMPLES_PER_SECOND 44100
#define CHANNELS 2

#define MULTICAST_PORT 8910

#include <mmsystem.h>
#include <Ws2tcpip.h>

struct TRIPLE_BUFFER
{
	HWAVEIN wavein;
	HWAVEOUT waveout;
	LPWAVEHDR primary;
	LPWAVEHDR secondary;
	LPWAVEHDR tertiary;
	char * buf;
	int pos;
};

struct SOCKET_INFORMATION
{
	SOCKET socket;
	WSABUF datagram;
	DWORD bytesRECV;
	DWORD bytesSEND;
	struct ip_mreq addr;
	SOCKADDR_IN sockAddr;
	OVERLAPPED overlapped;
};

#endif
