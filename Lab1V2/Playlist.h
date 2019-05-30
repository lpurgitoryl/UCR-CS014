#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

#include <iostream>
using namespace std;



class PlaylistNode{

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
        void InsertAfter(PlaylistNode* node); //the calling node points to the param and the param points to the node that the calling node pointed to 
        void SetNext(PlaylistNode * node); // points the pointer of the calling node to the param and points the param to the node the caling node points to
        string GetID();
        string GetSongName(); 
        string GetArtistName(); 
        int GetSongLength();
        PlaylistNode * GetNext();//returns pointer to next node
        void PrintPlaylistNode () ;// helper func, prints the contents of a node



};

#endif 