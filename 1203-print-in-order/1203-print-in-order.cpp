class Foo {
public:
    mutex mtx;
    condition_variable cv;
    int turn;

    Foo() {
        turn = 1;
    }

    void first(function<void()> printFirst) {
        printFirst();
        turn = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        while(turn != 2) {
            cv.wait(lock);
        }
        printSecond();
        turn = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        while(turn != 3) {
            cv.wait(lock);
        }
        printThird();
    }
};