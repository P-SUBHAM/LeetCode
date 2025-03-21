// Approach 1: change:O(1)+logn(set insertion) find:logn(set find)
// use unordered map to behave like container, 
// use unordered_map<int,set<int>> indexmp; to insert indexes and find
class NumberContainers {
public:
    unordered_map<int,int> v;
    unordered_map<int,set<int>> indexmp; // number:(indexes of occur)
    NumberContainers() {
        v.clear();
        indexmp.clear();
    }
    
    void change(int index, int number) {
        if(v[index]==-1) {
            v[index] = number;
            indexmp[number].insert(index);
        }
        else {
            indexmp[v[index]].erase(index);
            indexmp[number].insert(index);
            v[index] = number;
        }
    }
    
    int find(int number) {
        if(indexmp[number].size()==0) { // no doesnt exist
            return -1;
        }
        else {
            return *indexmp[number].begin();
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */