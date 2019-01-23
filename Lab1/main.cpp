#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std;

void PrintMenu(string);

int main() {
    string listTitle = " ";
    
    cout << "Enter playlist's title:" << endl;
    getline(cin, listTitle);
    cout << endl;
    
    PrintMenu(listTitle);
    
    return 0;
}

void PrintMenu(string title) {
    char option = ' ';
    string newUniqueID = " ";
    string newSongName = " ";
    string newArtistName = " ";
    int newSongLength = 0;
    int songPos = 0;
    int tempMax = 0;
    int i = 0;
    PlaylistNode playList;
    PlaylistNode* head = 0;
    PlaylistNode* tail = 0;
    PlaylistNode* dataAt = 0;
    PlaylistNode* tempPointer = 0;
    
    while (option != 'q') {
        option = ' ';
        
        while (!(option == 'a' || option == 'd' || option == 'c' || option == 's' || option == 't' || option == 'o' || option == 'q')) {
            cout << title << " PLAYLIST MENU" << endl;
            cout << "a - Add song" << endl;
            cout << "d - Remove song" << endl;
            cout << "c - Change position of song" << endl;
            cout << "s - Output songs by specific artist" << endl;
            cout << "t - Output total time of playlist (in seconds)" << endl;
            cout << "o - Output full playlist" << endl;
            cout << "q - Quit" << endl << endl;
            cout << "Choose an option:";
            cin >> option;
            cout << endl;
            cin.ignore(1);
        }
        
        if (option == 'a') {
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:";
            getline(cin, newUniqueID);
            cout << endl;
            cout << "Enter song's name:";
            getline(cin, newSongName);
            cout << endl;
            cout << "Enter artist's name:";
            getline(cin, newArtistName);
            cout << endl;
            cout << "Enter song's length (in seconds):";
            cin >> newSongLength;
            cout << endl << endl;
            
            dataAt = new PlaylistNode(newUniqueID, newSongName, newArtistName, newSongLength);
            
            if (head == 0) {
                head = dataAt;
                tail = dataAt;
            }

            else {
                tempPointer = tail;
                tail = dataAt;
                tempPointer->SetNext(dataAt);
            }
        }

        else if (option == 'd') {
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:";
            getline(cin, newUniqueID);
            cout << endl;
            
            dataAt = head;
            tempPointer = dataAt;
            while (dataAt != 0) {
                if (dataAt->GetID() == newUniqueID) {
                    newSongName = dataAt->GetSongName();
                    if (head == dataAt) {
                        if (head == tail) {
                            tail = 0;
                        }
                        tempPointer = head;
                        head = dataAt->GetNext();
                        delete tempPointer;
                        dataAt = head;
                        tempPointer = dataAt;
                    }

                    else {
                        if (tail == dataAt) {
                            tail = tempPointer;
                        }
                        tempPointer->SetNext(dataAt->GetNext());
                        delete dataAt;
                        dataAt = tempPointer;
                        dataAt = dataAt->GetNext();
                    }
                    cout << "\"" << newSongName << "\" removed." << endl << endl;
                }
                else {
                    tempPointer = dataAt;
                    dataAt = dataAt->GetNext();
                }
            }
        }

        else if (option == 'c') {
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:";
            cin >> songPos;
            cout << endl;
            tempMax = songPos;
            dataAt = head;
            tempPointer = head;
            i = 1;
            while (i < songPos) {
                tempPointer = dataAt;
                dataAt = dataAt->GetNext();
                ++i;
            }
            newSongName = dataAt->GetSongName();
            if (head == dataAt) {
                head = dataAt->GetNext();
            }

            else if (tail == dataAt) {
                tempPointer->SetNext(tail->GetNext() );
                tail = tempPointer;
            }

            else {
                tempPointer->SetNext(dataAt->GetNext() );
            }
            cout << "Enter new position for song:";
            cin >> songPos;
            cout << endl;
            tempPointer = head;
            i = 2;

            while (i < songPos) {
                tempPointer = tempPointer->GetNext();
                ++i;
            }

            if (songPos <= 1) {
                dataAt->SetNext(head);
                head = dataAt;
            }

            else if (songPos > (tempMax - 1)) {
                tail = dataAt;
                tempPointer->InsertAfter(dataAt);
            }

            else {
                tempPointer->InsertAfter(dataAt);
            }
            cout << "\"" << newSongName << "\" moved to position " << songPos << endl << endl;
        }

        else if (option == 's') {
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:";
            getline(cin, newArtistName);
            cout << endl << endl;
            dataAt = head;
            i = 1;

            while (dataAt != 0) {
                if (dataAt->GetArtistName() == newArtistName) {
                    cout << i << '.' << endl;
                    playList.PrintPlaylistNode(dataAt);
                }
                
                dataAt = dataAt->GetNext();
                ++i;
            }
        }

        else if (option == 't') {
            dataAt = head;
            newSongLength = 0;
            while (dataAt != 0) {
                newSongLength = newSongLength + dataAt->GetSongLength();
                
                dataAt = dataAt->GetNext();
            }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << newSongLength << " seconds" << endl << endl;
        }

        else if (option == 'o') {
            cout << title << " - OUTPUT FULL PLAYLIST" << endl;
            
            if (head == 0) {
                cout << "Playlist is empty" << endl << endl;
            }

            else {
                dataAt = head;
                i = 1;
                while (dataAt != 0) {
                    cout << i << '.' << endl;
                    playList.PrintPlaylistNode(dataAt);
                    dataAt = dataAt->GetNext();
                    ++i;
                }
            }
        }
    }
    
    return;
}