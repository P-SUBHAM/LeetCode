// Approach 1: Topo Sort
class Solution {
public:
    // convert items in vector to hashset and returns
    unordered_set<string> getItemSet(vector<string> &recipes) {
        unordered_set<string> Item_set;
        for(auto it: recipes) {
            Item_set.insert(it);
        }
        return Item_set;
    }
    // returns adjacency list given recipe and its ingredients, along with indeg
    unordered_map<string,vector<string>> getAdjListIndeg(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_map<string,int> &indeg) {
        unordered_map<string,vector<string>> adj;
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            string recipe = recipes[i];
            for(auto ing: ingredients[i]) {
                // ing -> recipe
                adj[ing].push_back(recipe);
                indeg[recipe]++;
                if(indeg.find(ing) == indeg.end()) 
                    indeg[ing] = 0;
            }
        }
        return adj;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> recipe_set = getItemSet(recipes);
        unordered_set<string> supply_set = getItemSet(supplies);
        unordered_map<string,int> indeg;
        unordered_map<string,vector<string>> adj = getAdjListIndeg(recipes,ingredients,indeg);
        queue<string> qu;
        vector<string> pos_recipes_list;
        // indeg 0 items not present in supply should not be included as start
        for(auto it: indeg) {
            string item = it.first;
            int ind = it.second;
            if(ind == 0 && (supply_set.find(item) != supply_set.end())) {
                qu.push(item);
            }
        }
        while(!qu.empty()) {
            auto item = qu.front(); qu.pop();
            if(recipe_set.find(item) != recipe_set.end()) {
                pos_recipes_list.push_back(item);
            }
            for(auto recipe_items: adj[item]) {
                if(--indeg[recipe_items] == 0) {
                    qu.push(recipe_items);
                }

            }
        }
        return pos_recipes_list;
    }
};