#include "Playlist.h"
#include <iostream>
#include <string>

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string newUniqueID, string newSongName, string newArtistName, int newSongLength) {
    uniqueID = newUniqueID;
    songName = newSongName;
    artistName = newArtistName;
    songLength = newSongLength;
    nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* data) {
    PlaylistNode* temp = 0;
    temp = nextNodePtr;
    nextNodePtr = data;
    data->SetNext(temp);
    
    return;
}

void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
    
    return;
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(PlaylistNode *nextData) const {
    cout << "Unique ID: " << nextData->GetID() << endl;
    cout << "Song Name: " << nextData->GetSongName() << endl;
    cout << "Artist Name: " << nextData->GetArtistName() << endl;
    cout << "Song Length (in seconds): " << nextData->GetSongLength() << endl << endl;
    
    return;
}




