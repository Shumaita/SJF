//Shortest-Job-First
//implemented by myself
// j rady queue te age aashbe take execute korbe (shobar age)
#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter How many processes: ";//count the process
    cin >> n;

    int burst_time[n], process[n];
    for (int i = 0; i < n; i++) {//for couting burst time
        cout << "Enter burst time of process - " << i + 1 << " : ";
        cin >> burst_time[i];
        process[i] = i + 1;
    }

    // SJF BUBBLE SORT LOGIC
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                int temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    int waiting_time = 0;
    int total_waiting_time = 0;
    int turnaround_time[n];
    int total_turnaround_time = 0;

    // Print Gantt chart
    cout << "Gantt Chart:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "| P" << process[i] << " ";
    }
    cout << "|" << endl;

    // Print the timeline
    int timeline = 0;
    for (int i = 0; i < n; i++) {
        cout << timeline << "\t";
        timeline += burst_time[i];
    }
    cout << timeline << endl;

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        cout << "Waiting time of process - " << process[i] << " : " << waiting_time << endl;
        total_waiting_time += waiting_time;
        waiting_time += burst_time[i];

        // Calculate turnaround time
        turnaround_time[i] = waiting_time;
        total_turnaround_time += turnaround_time[i];
    }

    // Print turnaround time for each process
    for (int i = 0; i < n; i++) {
        cout << "Turnaround time of process - " << process[i] << " : " << turnaround_time[i] << endl;
    }

    // Print average waiting time
    cout << "Average waiting time: " << (total_waiting_time) / float(n) << endl;
     cout << "Average total turnaround time: " << (total_turnaround_time) / float(n) << endl;

    return 0;
}
