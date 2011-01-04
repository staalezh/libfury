#include <iostream>
#include <cstring>

using namespace std;

void vulnerable(char* buffer)
{
    char buf_copy[32];
    strcpy(buf_copy, buffer);
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Usage: ./vuln [buffer]" << endl;
        return 1;
    }

    char* buffer = argv[1];
    cout << "Using buffer: " << buffer << endl;

    vulnerable(buffer);

    return 0;
}
