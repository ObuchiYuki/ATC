//
//  trie.hpp
//  ATC
//
//  Created by yuki on 2022/06/14.
//

// 文字の種類(char_size)、int型で0に対応する文字(base)
template<int char_size, int base>
struct trie {
    struct node {
        vector<int> next;
        vector<int> accept;
        int c, common;
        node(int _c): c(_c), common(0) { next.assign(char_size, -1); }
    };
    
    vector<node> nodes;
    int root;
    
    trie(): root(0) { nodes.push_back(node(root)); }
    
    void insert(const string &word, int word_id) {
        int id = 0;
        rep(i, word.size()) {
            int c = int(word[i] - base);
            int &nid = nodes[id].next[c];
            if (nid == -1) { nid = (int)nodes.size(); nodes.push_back(node(c)); }
            nodes[id].common++;
            id = nid;
        }
        nodes[id].common++;
        nodes[id].accept.push_back(word_id);
    }
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }
    
    node* leaf(const string &word) {
        int id = 0;
        rep(i, word.size()) {
            int c = int(word[i]-base);
            int &nid = nodes[id].next[c];
            if (nid == -1) return nullptr;
            id = nid;
        }
        return &nodes[id];
    }
    
    int search(const string &word, bool prefix = false) {
        if (auto node = leaf(word)) { return (prefix) ? true : node->accept.size() > 0; }
        return false;
    }
    
    bool start_with(const string &prefix) { return search(prefix, true); }
    int count() const { return (nodes[0].common); }
    int size() const { return ((int)nodes.size()); }
};
