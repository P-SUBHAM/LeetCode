class FooBar {
private:
    int n;

public:
    mutex mtx;
    condition_variable cv;
    int turn = 1;
    FooBar(int n) {
        this->n = n;
        turn = 1;
        cv.notify_all();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while(turn != 1) {
                cv.wait(lock);
            }
        	printFoo();
            turn *= -1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while(turn != -1) {
                cv.wait(lock);
            }
        	printBar();
            turn *= -1;
            cv.notify_all();
        }
    }
};