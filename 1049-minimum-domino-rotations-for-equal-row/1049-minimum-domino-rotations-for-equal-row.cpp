// Approach 2: Greedy
// fix the final pos domino to be a = tops[0], or b = bottoms[0]
// for each index assume 4 condn atop abot btop bbot count swaps required
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = bottoms[0], b = tops[0], n = tops.size();
        int atcnt = 0, abcnt = 0, btcnt = 0, bbcnt = 0;
        int atswap = 0, abswap = 0, btswap = 0, bbswap = 0;
        for(int i = 0; i < n; i++) {
            // at
            if(tops[i] == a) {
                atcnt++;
            }
            else if(bottoms[i] == a) {
                atcnt++;
                atswap++;
            }
            // ab
            if(bottoms[i] == a) {
                abcnt++;
            }
            else if(tops[i] == a) {
                abcnt++;
                abswap++;
            }
            // bt
            if(tops[i] == b) {
                btcnt++;
            }
            else if(bottoms[i] == b) {
                btcnt++;
                btswap++;
            }
            // bb
            if(bottoms[i] == b) {
                bbcnt++;
            }
            else if(tops[i] == b) {
                bbcnt++;
                bbswap++;
            }
        }
        int ans = 2*n;
        cout<<n<<endl;
        cout<<atcnt<<" "<<abcnt<<" "<<btcnt<<" "<<bbcnt<<endl;
        cout<<atswap<<" "<<abswap<<" "<<btswap<<" "<<bbswap<<endl;
        if(atcnt == n) {ans = min(ans,atswap);}
        if(abcnt == n) {ans = min(ans,abswap);}
        if(btcnt == n) {ans = min(ans,btswap);}
        if(bbcnt == n) {ans = min(ans,bbswap);}
        if(ans == 2*n) ans = -1;
        return ans;
    }
};

class Solution1 {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int t= tops.size();
        int m1=tops[0];
        int m2= bottoms[0];
        int swp1=0;
        int swp2=0;
        int swp3=0;
        int swp4=0;
        //all top are m1
        for(int i=0;i<t;i++){
            if(m1==tops[i]){
continue;}
                
           else  if(m1!=tops[i] && m1==bottoms[i]){
               swp1++;
}
              
               else if(m1!=tops[i]&& m1!=bottoms[i]){
           swp1=INT_MAX;
            break;}
        
}
        //all top are m2
        for(int i=0;i<t;i++){
            if(m2==tops[i]){
continue;}
                
           else  if(m2!=tops[i] && m2==bottoms[i]){
               swp2++;
}
              
               else if(m2!=tops[i]&& m2!=bottoms[i]){
           swp2=INT_MAX;
            break;}
        
}
        
        //all bottom are m1
        for(int i=0;i<t;i++){
            if(m1==bottoms[i]){ continue;}
               
           else  if(m1!=bottoms[i] && m1==tops[i]){
               swp3++;
}
               
               else if(m1!=bottoms[i]&& m1!=tops[i])
               {
    swp3=INT_MAX; 
             break;}
            
}
        //all bottoms are m2
         for(int i=0;i<t;i++){
            if(m2==bottoms[i]){ continue;}
               
           else  if(m2!=bottoms[i] && m2==tops[i]){
               swp4++;
}
               
               else if(m2!=bottoms[i]&& m2!=tops[i])
               {
    swp4=INT_MAX; 
             break;}
            
}
        int ans = min({swp1,swp2,swp3,swp4});
        if(ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};