#include <unordered_map>
#include <utility>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// class Solution {
// private:
//     int max_width;

//     void calculateWidth(TreeNode* node, unordered_map<int, BigInt>& widthByDepth, int depth, BigInt nodeNumber) {
//         // cout << "depth: " << depth << " " << "parent: " << parent << endl;
//         if (node == NULL) return;
//         if (widthByDepth.find(depth) == widthByDepth.end()) {
//             widthByDepth[depth] = nodeNumber;
//         } else {
//             max_width = max(max_width, (int) (widthByDepth[depth] - nodeNumber));
//         }

//         calculateWidth(node->right, widthByDepth, depth + 1, (nodeNumber * 2) + 1);
//         calculateWidth(node->left, widthByDepth, depth + 1, nodeNumber * 2);
//     }
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         max_width = numeric_limits<int>::min();
//         unordered_map<int, BigInt> widthByDepth;

//         calculateWidth(root, widthByDepth, 0, 0);

//         return max_width;
//     }
// };

class BigInt {
    string digits;
public:
    BigInt() {
        digits = string();
    }
    BigInt(string integer) {
        digits = string(integer.rbegin(), integer.rend());
        for (int i = 0; i < digits.size(); ++i) {
            digits[i] -= '0';
        }
    }

    BigInt(char* integer) {
        string str = integer;
        BigInt bigInt (str);
        digits = bigInt.digits;
    }

    BigInt(long long integer) {
        while (integer) {
            digits.push_back(integer % 10);
            integer /= 10;
        }
    }

    BigInt operator += (long long integer) {
        BigInt bigInt = *this;
        // cout << bigInt << endl;
        for (int i = 0; i < bigInt.digits.size() && integer; ++i) {
            long long digit = bigInt.digits[i] + integer;
            bigInt.digits[i] = digit % 10;
            integer = digit / 10;
        }
        
        BigInt bigInt2;
        
        if (integer) bigInt2 = BigInt(integer);
        bigInt.digits.append(bigInt2.digits);
        return bigInt;
    }

    BigInt operator + (long long integer) {
        return *this += integer;
    }

    BigInt operator *= (long long integer) {
        // cout << integer << endl;
        BigInt bigInt = *this;
        long long carry = 0;
        for (int i = 0; i < bigInt.digits.size(); ++i) {
            long long digit = bigInt.digits[i] * integer + carry;
            bigInt.digits[i] = digit % 10;
            carry = digit / 10;
        }
        BigInt bigInt2 = BigInt(carry);
        bigInt.digits.append(bigInt2.digits);
        return bigInt;
    }

    BigInt operator * (long long integer) {
        return *(this) *= integer;
    }

//     bool operator < (BigInt& bigInt) const {
//         if (digits.size() != bigInt.digits.size())
//             return digits.size() < bigInt.digits.size();

//         for (int i = digits.size() - 1; i >= 0; --i) {
//             if (digits[i] != bigInt.digits[i]) {
//                 return digits[i] < bigInt.digits[i];
//             }
//         }
//         return false;
//     }

    long long operator - (BigInt thatInt) {
        long long integer = 0;
        long long carry = 0;
        int i = 0;
        BigInt thisInt = *this;
        BigInt newInt;
        while (i < thisInt.digits.size() && i < thatInt.digits.size()) {
            thatInt.digits[i] += carry;
            carry = 0;
            if (thisInt.digits[i] < thatInt.digits[i]) {
                thisInt.digits[i] += 10;
                carry = 1;
            }

            newInt.digits.push_back(thisInt.digits[i] - thatInt.digits[i]);
            ++i;
        }

        while (i < thisInt.digits.size()) {
            if (carry) {
                thisInt.digits[i] -= carry;
                carry = 0;
            }
            // if (thisInt.digits[i] == 0) break;
            newInt.digits.push_back(thisInt.digits[i]);
            ++i;
        }
        while (newInt.digits.size() && newInt.digits.back() == 0) {
            newInt.digits.pop_back();
        }
        // cout << "new int sizs: " << newInt.digits.size() << endl;
        return newInt.toInt();
    }

    long long toInt() {
        long long integer = 0;
        long long SHIFT = 1;

        for (int i = 0; i < digits.size(); ++i) {
            integer = SHIFT * digits[i] + integer;
            SHIFT *= 10;
        }

        return integer;
    }

    string toString() {
        if (!digits.size()) return "0";
        // return string(digits.rbegin(), digits.rend());
        string integer = string();
        for (int i = digits.size() - 1; i >= 0; --i) {
            integer.push_back(digits[i] + '0');
        }
        return integer;
    }
};

ostream& operator << (ostream&out, BigInt bigInt) {
    out << bigInt.toString();
    return out;
}


int main() {

    // TreeNode* root = new TreeNode();
    // Solution* s = new Solution();
    // s->widthOfBinaryTree(root);

    BigInt bigInt = 10;
    BigInt bigInt2 = 6;
    int maxWidth = -5;

    BigInt newInt = bigInt - bigInt2;
    cout << newInt << endl;
    cout << newInt.toString().size() << endl;
    cout << bigInt << endl;
    cout << bigInt2 << endl;


    maxWidth = max(maxWidth, (int) (bigInt - bigInt2));
    cout << maxWidth << endl;

    cout << bigInt << endl;

    return 0;
}