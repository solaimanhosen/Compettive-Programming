#include <string>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        trie = new Trie();
        length = 0;
    }

    ~MedianFinder() {
        delete trie;
    }
    
    void addNum(int num) {
        num += SHIFT;
        string suffix = to_string(num);
        int prefix_len = to_string(SHIFT).length() - suffix.length();
        string prefix = "";
        for (int i = 0; i < prefix_len; ++i) {
            prefix += "0";
        }
        trie->insert(prefix + suffix);
        length++;
    }
    
    double findMedian() {
        double median = trie->findNthNumber(length / 2 + 1);
        median -= SHIFT;
        if (length % 2 == 0) {
            median += trie->findNthNumber(length / 2);
            median -= SHIFT;
            return median / 2;
        }
        return median;
    }
private:
    class TrieNode {
    public:
        static const int DEGREE = 10;
        int count;
        TrieNode* next[DEGREE];

        TrieNode() {
            count = 0;
            for (int i = 0; i < DEGREE; i++) {
                next[i] = 0;
            }
        }

        ~TrieNode() {
            for (int i = 0; i < DEGREE; ++i) {
                delete next[i];
            }
        }
    };

    class Trie {
    private:
        TrieNode* root;

        int findNthNumber(TrieNode* node, int n, int number) {
            if (n <= 0) return 0;

            int sum = 0;
            for (int i = 0; i < TrieNode::DEGREE; ++i) {
                if (node->next[i] != 0) {
                    if (sum + node->next[i]->count >= n)
                        return findNthNumber(node->next[i], n - sum, number * 10 + i);
                    sum += node->next[i]->count;
                }
            }

            return number;
        }
    public:
        Trie() {
            root = new TrieNode();
        }

        ~Trie() {
            delete root;
        }

        void insert(string number) {
            TrieNode* node = root;
            node->count++;

            for (int i = 0; i < number.length(); ++i) {
                int index = (int) (number[i] - '0');
                if (node->next[index] == 0) node->next[index] = new TrieNode();
                node = node->next[index];
                node->count++;
            }
        }

        int findNthNumber(int n) {
            return findNthNumber(root, n, 0);
        }
    };

    Trie* trie;
    int length;
    static const int SHIFT = 100000;
};