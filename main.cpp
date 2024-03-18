#include "includes/includes.hpp"
#include <iostream>
#include <stdio.h>

#include <Windows.h>
#include <string>
#include "includes/utils.hpp"
#include <urlmon.h>
#include <tchar.h>

#include "general.h"
#include <random>
#include "protect/auth.hpp"

#include <thread>
#include <cstring>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <shellapi.h>

#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

LPCSTR hus = "";  


static class MainFunction {
private:
	 SOCKET sock;
	uint32_t header[2] = { 0x12345678, 0 };

	 void findHardware() {
		wchar_t currentDir[MAX_PATH];
		GetCurrentDirectoryW(MAX_PATH, currentDir);
		std::wstring mapper = std::wstring(currentDir) + L"data\\Mapper.exe";
		std::wstring driver = std::wstring(currentDir) + L"data\\mouseMoveDriver.sys";
		std::this_thread::sleep_for(std::chrono::seconds(1));

		sockaddr_in serverAddress;
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(6666);
		if (inet_pton(AF_INET, "127.0.0.1", &(serverAddress.sin_addr)) != 1) {
			MessageBoxA(0, "error 405", 0, MB_ICONWARNING);
			exit(1);
		}
		if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
			MessageBoxA(0, "error 402", 0, MB_ICONWARNING);
			exit(1);
		}
	}

	 void send_packet(uint32_t packet_data[5]) {
		int dataSize = sizeof(uint32_t) * 5;
		std::vector<char> buffer(dataSize);
		memcpy(buffer.data(), packet_data, dataSize);
		send(sock, buffer.data(), dataSize, 0);
	}

public:
	MainFunction() {
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			MessageBoxA(0, "error 401", 0, MB_ICONWARNING);
			exit(1);
		}

		sock = socket(AF_INET, SOCK_STREAM, 0);
		findHardware();
	}

	~MainFunction() {
		closesocket(sock);
		WSACleanup();
	}

	void deactivate() {
		closesocket(sock);
		sock = INVALID_SOCKET;
	}

	 void niggggeeererrr(float x, float y) {
		uint32_t memory_data[5] = { header[0], header[1], static_cast<uint32_t>(x), static_cast<uint32_t>(y), 0 };
		send_packet(memory_data);


	}
};

void Print(const std::string& text) {
		std::cout << text;
}

std::thread titleThread;

HWND windowid = NULL;

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

void mapdriver() {
	const char* url = "https://cdn.discordapp.com/attachments/1214348467837735033/1217998083733061683/driver.sys?ex=6606101c&is=65f39b1c&hm=728291ddc58e5c64b974828a68181e3e4e13db8ee1d598bfac38efbdd309eb63&";
	const char* destination = "C:\\Users\\driver.sys";
	HRESULT hr = URLDownloadToFile(NULL, url, destination, 0, NULL);
	const char* url1 = "https://cdn.discordapp.com/attachments/1214348467837735033/1217998102888321115/kdmapper_Release.exe?ex=66061021&is=65f39b21&hm=1e5d97189acd12830ea0f43d47ee92ad5a6b27b02d64f02cb690921a99f62b00&";
	const char* destination1 = "C:\\Users\\kdmapper_Release.exe";
	HRESULT hr1 = URLDownloadToFile(NULL, url1, destination1, 0, NULL);
	Sleep(2000);
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	system("cd C:\\Users && kdmapper_Release.exe driver.sys");
	system("cls");
	ShowWindow(GetConsoleWindow(), SW_RESTORE);
	Sleep(1000);
	remove("C:\\Users\\kdmapper_Release.exe");
	remove("C:\\Users\\driver.sys");
}

using namespace KeyAuth;

auto name = skCrypt("titan"); // change to yours
auto ownerid = skCrypt("cwsKdZzXyz"); // change to yours
auto secret = skCrypt("d4989926741afd2da692298fa220d739e26ce472fabd66bba00e468ddd51b44c"); // change to yours
auto version = skCrypt("1.0"); // dont touch if your dumb
auto url = skCrypt("https://keyauth.win/api/1.2/"); // dont touch

api KeyAuthApp(name.decrypt(), ownerid.decrypt(), secret.decrypt(), version.decrypt(), url.decrypt());

void auth() {
	std::string key;
	std::cout << skCrypt("\n Enter license: ");
	std::cin >> key;
	KeyAuthApp.license(key);
}

auto main() -> int
{
	SetConsoleTitle("");
	KeyAuthApp.init();
	auth(); // delete or comment out this if you dont want to use auth
	mapdriver();
	mem::find_driver();
	mouse_interface();

	system("cls");
	std::cout << "\n Waiting for fortnite...";

	while (windowid == NULL)
	{
		XorS(wind, "Fortnite  ");
		windowid = FindWindowA_Spoofed(0, wind.decrypt());
	}

	globals->hwnd = FindWindowA_Spoofed(NULL, "Fortnite  ");
	LI_FN(Sleep)(1000);
	mem::find_process("FortniteClient-Win64-Shipping.exe");

	system("cls");

	virtualaddy = mem::find_image();

	system("cls");

	globals->width = GetSystemMetrics_Spoofed(SM_CXSCREEN); globals->height = GetSystemMetrics_Spoofed(SM_CYSCREEN);

	if (Render->Setup() != RENDER_INFORMATION::RENDER_SETUP_SUCCESSFUL) ExitProcess(0);
	if (Hook->Setup() != HOOK_INFORMATION::HOOKS_SUCCESSFUL) ExitProcess(0);
	if (Game->Setup() != GAME_INFORMATION::GAME_SETUP_SUCCESSFUL) ExitProcess(0);
	Render->Render();
}

