class ZeroEvenOdd {
private:
    int n;

public:
    mutex mtx;
    condition_variable cv;
    int turn = 0;
    ZeroEvenOdd(int n) {
        this->n = n;
        turn = 1;
        cv.notify_all();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i = 0; i < n; i++) {
            while(turn%2!=1) {
                cv.wait(lock);
            }
            printNumber(0);
            turn++;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i = 2; i <= n; i+=2) {
            while(turn%2==1 or (turn/2)%2==1) {
                cv.wait(lock);
            }
            printNumber(i);
            turn++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        for(int i = 1; i <= n; i+=2) {
            while(turn%2==1 or (turn/2)%2==0) {
                cv.wait(lock);
            }
            printNumber(i);
            turn++;
            cv.notify_all();
        }
    }
};