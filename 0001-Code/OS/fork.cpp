#include <unistd.h>   // for fork()
#include <sys/types.h> // for pid_t
#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "I am main parent process. PID: " << getpid() << endl;
    
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        cerr << "Fork failed!" << endl;
        return 1;
    }
    else if (pid == 0) {
        // Child process
        cout << "I am the child process. PID: " << getpid() << endl;
    }
    else {
        // Parent process
        cout << "I am the parent process. My child's PID: " << pid << " my pid:" << getpid() << endl;
    }

    return 0;
}

// I am main parent process. PID: 3721
// I am the parent process. My child's PID: 3725 my pid:3721
// I am the child process. PID: 3725