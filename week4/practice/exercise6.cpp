#include <iostream>
using namespace std;

struct Job {
    int id;
    int pages;
    Job* next;
};

class PrinterQueue {
private:
    Job* front;
    Job* rear;

public:
    PrinterQueue() : front(nullptr), rear(nullptr) {}

    ~PrinterQueue() {
        while (front != nullptr) {
            Job* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int id, int pages) {
        Job* newJob = new Job{id, pages, nullptr};
        if (!rear) {
            front = rear = newJob;
        } else {
            rear->next = newJob;
            rear = newJob;
        }
    }

    Job* dequeue() {
        if (!front) return nullptr;
        Job* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        return temp;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void printQueue() {
        Job* temp = front;
        cout << "Jobs in queue:\n";
        while (temp) {
            cout << "Job ID: " << temp->id << ", Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PrinterQueue pq;

    // Add jobs
    pq.enqueue(1, 5);
    pq.enqueue(2, 10);
    pq.enqueue(3, 2);

    cout << "Initial queue:\n";
    pq.printQueue();
    cout << "\n--- Printing Jobs ---\n";

    // Print and remove jobs
    while (!pq.isEmpty()) {
        Job* job = pq.dequeue();
        cout << "Printing Job ID: " << job->id << " (" << job->pages << " pages)" << endl;
        delete job;  // Remove the job once complete
    }

    cout << "\nAll jobs completed. Queue is empty.\n";

    return 0;
}
