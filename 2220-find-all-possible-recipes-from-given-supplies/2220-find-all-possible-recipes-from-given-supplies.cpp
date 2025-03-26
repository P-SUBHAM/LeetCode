class Solution {
public:
    void can_cook_supplies(unordered_map<string,bool> &can_cook, vector<string>& supplies) {
        for(auto it: supplies) {
            can_cook[it] = true;
        }
    }
    void enumerateRecipe(vector<string>& recipes, unordered_map<string,int> &recipe_idx) {
        int n = recipes.size();
        for(int i = 0; i < n; i++) {
            recipe_idx[recipes[i]] = i;  
        }
    }

    bool dfs(vector<string>& recipes, vector<vector<string>>& ingredients, unordered_map<string,int> &recipe_idx, string item, unordered_map<string,bool> &can_cook) {
        if(recipe_idx.find(item) == recipe_idx.end()) { // supply and not recipe
            return can_cook[item]; // return if supply exists or not
        }
        if(can_cook.find(item) != can_cook.end()) { // recipe status already known
            return can_cook[item];
        }
        // Do dfs and determine if its nei ingredients recipe/supply are cookable
        // check for directed cycle 
        can_cook[item] = false; // to detect/make cycle cases false, else inf loop
        for(auto nei: ingredients[recipe_idx[item]]) {
            if(!dfs(recipes,ingredients,recipe_idx,nei,can_cook)) {
                return can_cook[item] = false;
            }
        }
        return can_cook[item] = true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        unordered_map<string,bool> can_cook; // cookable supply and recipes
        can_cook_supplies(can_cook,supplies); // mark base supply items

        unordered_map<string,int> recipe_idx; // recipe: recipe_index
        enumerateRecipe(recipes,recipe_idx);

        vector<string> can_cook_recipes_list; // final ans

        for(int i = 0; i < n; i++) {
            if(dfs(recipes,ingredients,recipe_idx,recipes[i],can_cook)) {
                can_cook_recipes_list.push_back(recipes[i]);
            }
        }

        return can_cook_recipes_list;
    }
};

// Approach 1: Topo Sort
// 00:55:13
class Solution1 {
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