#include <iostream>
#include <Windows.h>
#include <string>

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

    int current_size = 8;

    string type;
    while (current_size < size) {
        Chunk* chunk = (Chunk*)&Buffer[current_size];
        type = string((char*)&Buffer[current_size + 4], 4);
        DWORD right_len = Reverse(chunk->len);
        cout << "lenght " << right_len << " type " << type << endl << endl;
        current_size = current_size + right_len + 12;
    }
    int len_of_file = current_size;
    cout<<"final size of file " << len_of_file << endl;

    CloseHandle(handle);
    delete[] Buffer;
    return 0;
}
