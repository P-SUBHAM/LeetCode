class Solution {
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