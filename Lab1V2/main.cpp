#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;


void PrintMenu( string name);
void displayPlaylist(PlaylistNode* &head, PlaylistNode* &tail);
void addSong(PlaylistNode* &head, PlaylistNode* &tail);
void totalTime(PlaylistNode* head, PlaylistNode* tail);
void songsByArtist(PlaylistNode* head, PlaylistNode* tail, string &artName);
void removeSong(PlaylistNode* &head, PlaylistNode* &tail, string &unqID );

       
void postion(PlaylistNode* &head, PlaylistNode* &tail );
       

int main() {
    string pName;
    char letter;
    
    cout << "Enter playlist's title:" << endl;
    getline(cin,pName);

    cout << endl;

    PrintMenu(pName);

    cout << endl;
    cout << "Choose an option:" ;
    cin >> letter;
   cout << endl;
   
   PlaylistNode* head = new PlaylistNode();
   PlaylistNode* tail = new PlaylistNode();
//   PlaylistNode* head = nullptr;
//    PlaylistNode* tail = nullptr;

while( letter != 'q'){

    if(letter == 'a'){
        
        addSong(head, tail);
        cout << endl;
        PrintMenu(pName);
    }
    else if(letter == 'd'){
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        string unqID;
        cin >> unqID;

        removeSong(head, tail,unqID);
        cout << endl;
        PrintMenu(pName);
    }
    else if(letter == 'c'){
        // postion(head, tail);
        PrintMenu(pName);
    }
    else if(letter == 's'){
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        string artName;
        cin >> artName;

        songsByArtist(head, tail, artName);
        PrintMenu(pName);
    }
    else if(letter == 't'){
        totalTime(head, tail);
        cout << endl;
        PrintMenu(pName);
    }
    else if(letter == 'o'){
        cout << pName << " - OUTPUT FULL PLAYLIST" << endl;
        displayPlaylist(head, tail);
        cout << endl;
        PrintMenu(pName);
    }
     
    cout << endl;
    cout << "Choose an option:" ;
    cin >> letter;
    cout << endl;
}

    




    return 0;
}

void PrintMenu( string name){
    
    cout << name << " PLAYLIST MENU" << endl;

       cout <<"a - Add song" << endl 
       << "d - Remove song" << endl 
       << "c - Change position of song" << endl 
       << "s - Output songs by specific artist" << endl 
       << "t - Output total time of playlist (in seconds)"<< endl
       << "o - Output full playlist" << endl << "q - Quit" << endl ;
}

       
void addSong(PlaylistNode* &head, PlaylistNode* &tail){
    cout << "ADD SONG" << endl;

    cout << "Enter song's unique ID:" << endl;
    string id;
    cin >> id;

    cout << "Enter song's name:" << endl;
    string songN;
    cin.ignore(1);
    getline(cin, songN);

    cout << "Enter artist's name:" << endl;
    string artist;
    getline(cin, artist);

    cout << "Enter song's length (in seconds):" ;
     cout << endl;
    int time;
    // cin.ignore(1);
    cin >> time;
   

   PlaylistNode* tmp =  new PlaylistNode( id,  songN, artist, time);

    if( ( head->GetSongLength() == 0 ) && ( tail->GetSongLength() == 0) ){// takes care of no list case
        delete head;
        delete tail;

        // head = new PlaylistNode(id,  songN, artist, time);
        head = tmp;

        tail = head;
       // cout << " head and tail set" << endl;

        return;
    }
   
    else{
        tail->SetNext(tmp);
        tail = tmp;
      //  cout << "node added to tail and tail now points to new node" << endl;

    }
 
    return;
}
        
void displayPlaylist(PlaylistNode* &head, PlaylistNode* &tail){
    if( ( head->GetSongLength() == 0 ) && ( tail->GetSongLength() == 0) ){// takes care of empty list
        cout << "Playlist is empty" << endl;
        return;
    }
    int counter = 1;
    //now know there is at least head

    // cout << counter << "." << endl;
    // head->PrintPlaylistNode();

    
    for(PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext() ){
        if(curr == head){
            cout << counter << "." << endl;
            head->PrintPlaylistNode();
             //counter++;
        }
        else{
         counter++;
         cout << endl;
         cout << counter << "." << endl;
         curr->PrintPlaylistNode();
         //counter++;
        }
    }
    // PlaylistNode* curr = head->GetNext();
    //  while(!curr){
       
    //      cout << endl;
    //      cout << counter << "." << endl;
    //      curr->PrintPlaylistNode();
    //      counter++;
        
    // }

    return;
}

void totalTime(PlaylistNode* head, PlaylistNode* tail){
    if( ( head->GetSongLength() == 0 ) && ( tail->GetSongLength() == 0) ){
        cout << "Playlist is empty" << endl;
        return;
    }
    
    int addedTime = 0;
    for(PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext() ){
       addedTime += curr->GetSongLength();
    }

    cout << "Total Time: " << addedTime << " seconds";
}

void songsByArtist(PlaylistNode* head, PlaylistNode* tail, string &artName){
    cout << endl;

    int counter = 1;
     for(PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext() ){
        if(curr->GetArtistName() == artName){
        cout << counter << "." << endl;
        curr->PrintPlaylistNode();
        counter++;
        }
        else{
            counter++;
        }
    }
}
void pop_back(PlaylistNode* &head, PlaylistNode* &tail ){
    PlaylistNode* tailPrev;

    for(PlaylistNode* curr = head; curr != tail ; curr = curr->GetNext()){
        tailPrev = curr;
    }

    delete tail;

    tail = tailPrev;
}
void removeSong(PlaylistNode* &head, PlaylistNode* &tail, string &unqID ){
    if( ( head->GetSongLength() == 0 ) && ( tail->GetSongLength() == 0) ){ //emptry list
        cout << "No songs to remove" << endl;
        return;
    }
    else if(  (head ==  tail ) && (head->GetID() == unqID ) ){//if same node AKA list of one
        cout << "list of one to empty list" << endl;

        cout << "\"" << head->GetSongName() << "\"" << " removed." << endl;

       //  cout << "test output playlist should be 0" << endl;
        delete head;
        head = new PlaylistNode();
        tail = new PlaylistNode();

        return;

    }
   else if( (head->GetID() == unqID ) && tail != head ){ // head case and not a list of one
        PlaylistNode* curr = head->GetNext();
        // cout << "this is head case" << endl;
        cout << "\"" << head->GetSongName() << "\"" << " removed."<< endl ;
        delete head;
        head = curr;
        
        return;
        }

    for(PlaylistNode* curr = head; curr != tail; curr = curr->GetNext() ){//all other acses

        if( (curr->GetNext()->GetID() ) ==  unqID ){//evrything else
            PlaylistNode* deletingNode = curr->GetNext();

           // cout << "testing case of anything other than head and tail" << endl;
            cout << "\"" << deletingNode->GetSongName() << "\"" << " removed." << endl;

            curr->SetNext( deletingNode->GetNext() );

            delete deletingNode;
            
            return;
        }
    }

    if( tail->GetID() == unqID){
        cout << "\"" << tail->GetSongName() << "\"" << " removed." << endl; 
        pop_back(head, tail);
    }

    

    cout << "There is no song with the ID of " << unqID<<  endl;
    return;
}

