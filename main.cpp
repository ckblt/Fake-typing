#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

string read = "";
string buffer = "";

void openFile(char path[])
{
    // Read file
    ifstream f(path);
    
    if (!f.is_open())
    {
        cout << "ERROR" << endl; // Output error
        system("pause");
        exit(0);
    }
    
    char b[1024];
    while (!f.eof())
    {
        f.getline(b, 1024);
        read += b;
        read += '\n';
    }

    // 4 space -> tab
    while (read.find("    ") != read.npos)
    {
        read.replace(read.find("    "), 4, "\t");
    }
}

void typewriter()
{
    for (int i = 0; i < read.length(); i++)
    {
        _getch(); // Wait until the key is pressed
        system("cls"); // Clear screen
        buffer += read[i];
        cout << buffer;
    }
}

int main(int argc, char const *argv[])
{
    openFile("text.txt"); // Import file
    typewriter();
    system("pause"); // Pause, can be changed to ( while (true); )
    return 0;
}
