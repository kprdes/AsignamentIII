#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void scan(vector<int> &requests, int head, int disk_size) {
    vector<int> left, right;
    int count = 0;
    vector<int> sequence;

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        if (requests[i] > head)
            right.push_back(requests[i]);
    }
    
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++) {
        int actual = right[i];
        sequence.push_back(actual);
        count += abs(actual - head);
        head = actual;
    }

    count += abs(disk_size - head - 1);
    head = disk_size - 1;

    for (int i = left.size() - 1; i >= 0; i--) {
        int actual = left[i];
        sequence.push_back(actual);
        count += abs(actual - head);
        head = actual;
    }

    cout << "SCAN route: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << "\nTotal length of the route: " << count << endl;
}

void cscan(vector<int> &requests, int head, int disk_size) {
    vector<int> left, right;
    int count = 0;
    vector<int> sequence;

    for (int i = 0; i < requests.size(); i++) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        if (requests[i] > head)
            right.push_back(requests[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++) {
        int actual = right[i];
        sequence.push_back(actual);
        count += abs(actual - head);
        head = actual;
    }

    count += abs(disk_size - head - 1);
    head = 0; 


    for (int i = 0; i < left.size(); i++) {
        int actual = left[i];
        sequence.push_back(actual);
        count += abs(actual - head);
        head = actual;
    }

    cout << "CSCAN route: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << "\nTotal length of the route: " << count << endl;
}

int main() {
    int head, disk_size;
    vector<int> requests;
    
    
    ifstream file("request.txt");
    if (!file) {
        cerr << "Error" << endl;
        return 1;
    }

    int request;
    while (file >> request) {
        requests.push_back(request);
    }
    file.close();

    cout << "Initial position of the head: ";
    cin >> head;
    cout << "Disk size: ";
    cin >> disk_size;

    scan(requests, head, disk_size);
    cscan(requests, head, disk_size);

    return 0;
}
