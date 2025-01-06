class Foo:
    def __init__(self):
        self.turn = 1
        self.cv = threading.Condition()

    def first(self, printFirst: Callable[[], None]) -> None:
        with self.cv:  # Acquire the lock before notifying
            printFirst()
            self.turn = 2
            self.cv.notify_all()  # Notify waiting threads

    def second(self, printSecond: Callable[[], None]) -> None:
        with self.cv:  # Acquire the lock before waiting
            while self.turn != 2:  # Use `while` to recheck condition after wakeup
                self.cv.wait()  # Wait for notification
            printSecond()
            self.turn = 3
            self.cv.notify_all()  # Notify waiting threads

    def third(self, printThird: Callable[[], None]) -> None:
        with self.cv:  # Acquire the lock before waiting
            while self.turn != 3:  # Use `while` to recheck condition after wakeup
                self.cv.wait()  # Wait for notification
            printThird()