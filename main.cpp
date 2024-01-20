#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Chunk{
	DWORD	len;
	BYTE	type[4];
} ;

DWORD Reverse(DWORD in) {
	return ((in >> 24) & 0x000000FF) | ((in >> 8) & 0x0000FF00) | ((in << 8) & 0x00FF0000) | ((in << 24) & 0xFF000000);
}

int main() {

	string file = "C://neu140_wgo_schema01.png";
    HANDLE handle = CreateFile(file.data(), GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0); //открыть
    DWORD size = GetFileSize(handle, 0);
    BYTE* Buffer{ new BYTE[size] };
    DWORD byte;
    ReadFile(handle, Buffer, size, &byte, 0);

   
	return 0;
}
