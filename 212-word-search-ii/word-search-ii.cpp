class Solution {
    struct TrieNode {
        TrieNode* child[26] = {};
        string word = "";
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string &w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->child[idx])
                    node->child[idx] = new TrieNode();
                node = node->child[idx];
            }
            node->word = w;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {

        char c = board[i][j];
        if (c == '#' || !node->child[c - 'a'])
            return;

        node = node->child[c - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";      // avoid duplicates
        }

        board[i][j] = '#';

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &d : dirs) {
            int x = i - d[0];
            int y = j + d[1];

            if (x >= 0 && x < board.size() &&
                y >= 0 && y < board[0].size())
                dfs(board, x, y, node, ans);
        }

        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
     TrieNode* root = buildTrie(words);
        vector<string> ans;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;   
    }
};