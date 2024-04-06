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
            newInt.digits.push_back(digits[i]);
            ++i;
        }
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

class Solution {
private:
    int max_width;

    void calculateWidth(TreeNode* node, unordered_map<int, BigInt>& widthByDepth, int depth, BigInt nodeNumber) {
        if (node == 0) return;
        // cout << "node val: " << node->val << " depth: " << depth << " " << "nodeNumber: " << nodeNumber << endl;
        if (widthByDepth.find(depth) == widthByDepth.end()) {
            // cout << "depth: " << depth << " maxNode: " << nodeNumber << endl;
            widthByDepth[depth] = nodeNumber;
        } else {
            // cout << "maxNodeByDepth: " << widthByDepth[depth] << " this node: " << nodeNumber << endl;
            // cout << "width: " << (int) (widthByDepth[depth] - nodeNumber) << endl;
            max_width = max(max_width, (int) (widthByDepth[depth] - nodeNumber));
        }

        calculateWidth(node->right, widthByDepth, depth + 1, nodeNumber * 2 + 1);
        calculateWidth(node->left, widthByDepth, depth + 1, nodeNumber * 2);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        max_width = 0;
        unordered_map<int, BigInt> widthByDepth;

        calculateWidth(root, widthByDepth, 0, 0);

        return max_width + 1;
    }
};


