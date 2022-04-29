#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    Node *l, *r;
    T val;
    Node(T value) { l = r = nullptr, val = value; }
};

template<typename T>
struct Stack {
    Node<T> *first;
    unsigned int sz;
    Stack() { first = nullptr, sz = 0; }

    void push(T value) {
        Node<T> *new_node = new Node(value);
        if (first != nullptr) {
            new_node->l = first->l;
            new_node->r = first;
            new_node->l->r = new_node;
            first->l = new_node;
        } else {
            first = new_node;
            first->l = first->r = first;
        }
        sz++;
    }
    void pop() {
        if (first == nullptr) return;
        if (first->r == first) {
            delete first;
            first = nullptr;
            sz--;
            return;
        }
        Node<T> *del = first->l;
        first->l = del->l;
        first->l->r = first;
        delete del;
        sz--;
    }
    T top() { return first->l->val; }
    unsigned int size() { return sz; }
    bool empty() { return sz == 0; }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Stack<int> st;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "push") {
            int n; cin >> n;
            st.push(n);
        }
        if (s == "pop") {
            if (st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        if (s == "size") cout << st.size() << "\n";
        if (s == "empty") cout << st.empty() << "\n";
        if (s == "top") {
            if (st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }
}