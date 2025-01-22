// Approach 1: 2 ptr
// add t to hashmap, keep increasing end++ and removing from map_t
// if and when valid, keep increasing begin++ and updating len_ans and head and adding to map_t
// valid is from beg to before end [begin,end)
class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> map_t;
        for(auto c: t) map_t[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map_t[s[end++]]-- > 0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map_t[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};

// Approach : 2 Pointer template
int findSubstring(string s){
    map<char,int> mp;
    int counter; // check whether the substring is valid
    int begin=0, end=0; //two pointers, one point to tail and one  head
    int d; //the length of substring

    for(;;) { /* initialize the hash map here */ }

    while(end<s.size()){

        if(mp[s[end++]]-- ? 1:0){  /* modify counter here */ }

        while(false/* counter condition */){ 
                
                /* update d here if finding minimum*/

            //increase begin to make it invalid/valid again
            
            if(mp[s[begin++]]++ ?1:0){ /*modify counter here*/ }
        }  

        /* update d here if finding maximum*/
    }
    return d;
}