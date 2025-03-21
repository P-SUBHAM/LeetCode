struct minHeap {
    int n = 0;
    vector<int> arr;
    int parent(int x) {return (x-1)/2;}
    int left(int x) {return 2*x+1;}
    int right(int x) {return 2*x+2;}
    int pop() {
        if(n == 0) return INT_MAX;
        int root = arr[0];
        arr[0] = arr[n - 1];
        n--;
        MinHeapify(0);
        return root;
    }
    void push(int x) {
        if(arr.size() == n)
            arr.push_back(x); // only if arr is completely filled
        arr[n] = x; 
        n++;
        int i = n - 1;
        while(i > 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }
    }
    int top() {
        if(n == 0)
            return INT_MAX;
        return arr[0];
    }
    bool empty() {
        return n == 0;
    }
    void MinHeapify(int i) {
        if(i >= n) return;
        int smallest = i, l = left(i), r = right(i);
        if(l < n && arr[l] < arr[i])
            smallest = l;
        if(r < n && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i) {
            swap(arr[smallest],arr[i]);
            MinHeapify(smallest);
        }
    }
    void print() {
        cout<<"arr:";
        for(int i = 0; i < n; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};