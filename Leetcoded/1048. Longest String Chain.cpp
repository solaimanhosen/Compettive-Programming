class Solution {

public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> word_position;

        for (int i = 0; i < words.size(); i++) {
            word_position[words[i]] = i;
        }

        edges.clear();
        edges.resize(words.size());

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            for (int index = 0; index < word.size(); index++) {
                string predecessor = word.substr(0, index) + word.substr(index + 1);
                auto it = word_position.find(predecessor);
                if (it == word_position.end()) {
                    continue;
                }

                edges[it->second].push_back(i);
            }
        }

        cache.clear();
        cache.resize(words.size());

        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            count = max(count, longest(i));
        }

        return count;
    }
    
private:
    
    int longest(int v) {
        if (cache[v]) return cache[v];
        
        cache[v] = 1;
        for (auto u : edges[v]) {
            cache[v]  = max(cache[v], longest(u) + 1);
        }
        
        return cache[v];
    }
    
    vector<vector<int>> edges;
    vector<int> cache;
};
