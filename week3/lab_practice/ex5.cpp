#include <iostream>
using namespace std;

class Node {
    public: 
    string song ;
    Node* next ;
    Node (string s) {
        song = s;
        next = nullptr;
    }
};
class MusicPlayList {
    private:
        Node * tail;
        Node * head ;
        Node* current;
    public:
    MusicPlayList () {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    void addSong (string s){
        Node* NewSong = new Node(s);
        if ( head == nullptr){
            head = NewSong;
            tail= NewSong;
            current = head;
            tail->next = head;
        } else {
            tail->next = NewSong ;
            NewSong->next = head ;
            tail = NewSong;
        }
    }
    void PlayNext () {
        if (head == nullptr){
            cout << "PlayList is empty" <<endl;
        }
        cout << "Music :" << current->song << " is playing."<< endl;
        current = current->next;
    }
    void display() {
        if (head == nullptr) {
            cout << "Playlist is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Playlist: ";
        do {
            cout << temp->song << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to start)" << endl;
    }
};
int main () {
    MusicPlayList Mix1;
    Mix1.addSong("Joji - PIXELATED KISSES");
    Mix1.addSong("Ricky Montgomery - Mr Loverman");
    Mix1.addSong("innocence — daniel caesar");
    Mix1.addSong("The We4kend - រូបកាយ ");
    Mix1.addSong("Joji - SLOW DANCING IN THE DARK");
    Mix1.display();
    Mix1.PlayNext();
    Mix1.PlayNext();
    Mix1.PlayNext();
    Mix1.PlayNext();
    Mix1.PlayNext();
}