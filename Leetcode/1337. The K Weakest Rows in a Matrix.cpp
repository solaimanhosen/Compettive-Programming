#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<RowStrength> strengths;

        for (int i = 0; i < mat.size(); ++i) {
            int strength = 0;
            for (int j = 0; j < mat[0].size(); ++j) {
                if (mat[i][j] == 1) strength++;
                else break;
            }
            
            strengths.push_back({i, strength});
        }

        // sort(strengths.begin(), strengths.end(), [] (auto x, auto y) {
        //     if (x.strength < y.strength) return true;
        //     if (x.strength == y.strength && x.index < y.index) return true;
        //     return false;
        // });
        
        sort(strengths.begin(), strengths.end(), comp);
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(strengths[i].index);
        }

        return result;
    }
    
    struct RowStrength {
        int index;
        int strength;
    };
    
    static bool comp(const RowStrength x, const RowStrength y) {
        if (x.strength == y.strength) return x.index < y.index;
        return x.strength < y.strength;
    }
};

