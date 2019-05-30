#include <iostream>
using namespace std;

#include "Playlist.h"

void PrintMenu();

int main(){
    
    cout << "Enter playlist's title:" << endl;
    string PlaylName;
    getline(cin, PlaylName);
    cout << endl;

    Playlist newPlaylist = Playlist(PlaylName);
    
    newPlaylist.menu();

    


    return 0;
}