#include "Playlist.h"

   string PlaylistNode::GetID(){
        return this->uniqueID;

    }

    string PlaylistNode::GetSongName(){
        return this->songName;
    }

    string PlaylistNode::GetArtistName(){
        return this->artistName;
    }

    int PlaylistNode::GetSongLength(){
        return this->songLength;
    }

    PlaylistNode *  PlaylistNode::GetNext(){
      return this->nextNodePtr;

    }

    void PlaylistNode::PrintPlaylistNode() {
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Song Name: " << songName << endl;
        cout << "Artist Name: " << artistName << endl;
        cout << "Song Length (in seconds): " << songLength << endl;
    }

    void PlaylistNode::SetNext(PlaylistNode * node){
        this->nextNodePtr = node;
    }

    void PlaylistNode::InsertAfter(PlaylistNode* node){
        PlaylistNode* tmp = this->nextNodePtr;
        this->nextNodePtr = node;
        node->nextNodePtr = tmp;
    }
