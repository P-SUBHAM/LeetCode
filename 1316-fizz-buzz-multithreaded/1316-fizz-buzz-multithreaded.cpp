class FizzBuzz {
private:
    int n;

public:
    mutex mtx;
    condition_variable cv;
    int turn;
    FizzBuzz(int n) {
        this->n = n;
        turn = 1;
        cv.notify_all();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(mtx);
        while(turn <= n) {
            while(turn <= n && !(turn%3==0 && turn%5!=0)) {
                cv.wait(lock);
            }
            if(turn <= n) printFizz();
            turn++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(mtx);
        while(turn <= n) {
            while(turn <= n && !(turn%3!=0 && turn%5==0)) {
                cv.wait(lock);
            }
            if(turn <= n) printBuzz();
            turn++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(mtx);
        while(turn <= n) {
            while(turn <= n && !(turn%3==0 && turn%5==0)) {
                cv.wait(lock);
            }
            if(turn <= n) printFizzBuzz();
            turn++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while(turn <= n) {
            while(turn <= n && (turn%3==0 or turn%5==0)) {
                cv.wait(lock);
            }
            if(turn <= n) printNumber(turn);
            turn++;
            cv.notify_all();
        }
    }
};