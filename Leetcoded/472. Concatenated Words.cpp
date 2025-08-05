
class Solution {
private:
    int isConcatenated(string word, unordered_set<string>& dict, unordered_map<string, int>& cache) {

        if (cache[word]) return cache[word];
        
        for (int i = 1; i < word.length(); i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i, word.length());

            if (dict.find(prefix) != dict.end() && (dict.find(suffix) != dict.end() || isConcatenated(suffix, dict, cache) == 1)) {
                return cache[word] = 1;
            }
        }
        
        return cache[word] = -1;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dict;
        
        for (auto word : words) {
            dict.insert(word);
        }
        
        vector<string> result;
        unordered_map<string, int> cache;
        for (auto word : words) {
            if (isConcatenated(word, dict, cache) == 1) {
                result.push_back(word);
            }
        }

        return result;
    }
};
