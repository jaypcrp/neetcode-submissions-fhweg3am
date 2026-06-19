class LRUCache {
private:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // A node can be removed from any part within the list because this operation will be called even if the 2nd element will be accessed in 100 element linked list.
    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Fix in mind that insertion is going to happen at beginning only i.e right after the head.

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            remove(node);
            insert(node);

            return;
        }

        Node* newNode = new Node(key, value);

        mp[key] = newNode;
        insert(newNode);

        if (mp.size() > cap) {

            Node* lru = tail->prev;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }
    }
};