class H2O {
public:
    mutex mtx;
    condition_variable cv;
    int turn;
    H2O() {
        turn = 0;
        cv.notify_all();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);
        while(turn%3==0) {
            cv.wait(lock);
        }
        releaseHydrogen();
        turn++;
        turn=turn%3;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);
        while(turn%3!=0) {
            cv.wait(lock);
        }
        releaseOxygen();
        turn++;
        turn=turn%3;
        cv.notify_all();
    }
};