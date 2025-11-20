#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Patient {
    string name;
    int priorityLevel;
};

struct Node {
    Patient data;
    Node* next;
};

class TriageQueue {
private:
    Node* front;

public:
    TriageQueue() : front(nullptr) {}

    ~TriageQueue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(const string& name, int priority) {
        Patient newPatient = {name, priority};
        Node* newNode = new Node{newPatient, nullptr};

        if (front == nullptr || priority < front->data.priorityLevel) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            while (current->next != nullptr && current->next->data.priorityLevel <= priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    Patient dequeue() {
        if (isEmpty()) {
            return {"", 99};
        }
        Patient treatedPatient = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return treatedPatient;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    string peek() const {
        if (isEmpty()) {
            return "No patients waiting.";
        }
        return front->data.name + " (Priority " + to_string(front->data.priorityLevel) + ")";
    }
};

int main() {
    TriageQueue triage;

    triage.enqueue("Bob (Stable)", 3);
    cout << "Added Bob (P3)" << endl;
    triage.enqueue("Alice (Broken Arm)", 2);
    cout << "Added Alice (P2)" << endl;
    triage.enqueue("Charlie (Cardiac)", 1);
    cout << "Added Charlie (P1)" << endl;

    cout << "\nNext patient to be treated: " << triage.peek() << endl;

    triage.enqueue("Dave (Headache)", 4);
    cout << "Added Dave (P4)" << endl;
    triage.enqueue("Eve (Bleeding)", 1);
    cout << "Added Eve (P1)" << endl;

    cout << "\n--- Treating Patients ---" << endl;

    Patient p1 = triage.dequeue();
    cout << "Treated: " << p1.name << " (P" << p1.priorityLevel << ")" << endl;
    cout << "Next to be treated: " << triage.peek() << endl;

    Patient p2 = triage.dequeue();
    cout << "Treated: " << p2.name << " (P" << p2.priorityLevel << ")" << endl;

    Patient p3 = triage.dequeue();
    cout << "Treated: " << p3.name << " (P" << p3.priorityLevel << ")" << endl;

    cout << "\nNext to be treated: " << triage.peek() << endl;

    triage.dequeue(); 
    triage.dequeue(); 
    triage.dequeue(); 

    cout << "Is the queue empty? " << (triage.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
