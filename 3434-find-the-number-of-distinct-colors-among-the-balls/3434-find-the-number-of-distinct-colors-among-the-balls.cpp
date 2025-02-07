// Approach 1: Freq count, colormap
// maintain colormap i.e ball:color 
// maintain freq of col, if col freq:1->0 D-- freq:0->1 D++
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> distinct;
        unordered_map<int,int> colorfreq;
        unordered_map<int,int> colormap;
        int distinctcol = 0;
        for(auto query: queries) {
            int ball = query[0], color = query[1];
            if(colormap[ball]==0) {// color not replaced for ball
                if(colorfreq[color]++==0) {
                    distinctcol++;
                }
                colormap[ball] = color;
            }
            else { // color replaced
                if(color!=colormap[ball]) {
                    if(--colorfreq[colormap[ball]]==0) {
                        distinctcol--;
                    }
                    if(colorfreq[color]++==0) {
                        distinctcol++;
                    }
                    colormap[ball] = color;
                }
            }
            distinct.push_back(distinctcol);
        }
        return distinct;
    }
};