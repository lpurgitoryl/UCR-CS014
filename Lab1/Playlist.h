#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include <iostream>
using namespace std;


class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;

        PlaylistNode* nextNodePtr;
        
    public:
         PlaylistNode(): 
            uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr){}

    PlaylistNode(string ID, string songName, string artistName, int songLength): 
        uniqueID(ID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr){}

    //node functions/ helper functions
        void InsertAfter(PlaylistNode* node); //changes position
        void SetNext(PlaylistNode * node); // adds node
        string GetID();
        string GetSongName(); 
        string GetArtistName(); 
        int GetSongLength();
        PlaylistNode * GetNext();
        void PrintPlaylistNode() const;

        void setNull();
        void setPtr(PlaylistNode* node){
            this->nextNodePtr = node;
        }
};

class Playlist{
    private:
        PlaylistNode* head;
        PlaylistNode* tail;

        string PlaylistName;
    public:
        Playlist(string Name): head(nullptr), tail(nullptr){
            PlaylistName = Name;
        }
        void menu();
       
        void addSong(); // done
        void removeSong(); //finished but check for errors
        void postion();
        void songsByArtist();
        void totalTime(); // looks like it works 
        void displayPlaylist();//done

};

#endif 