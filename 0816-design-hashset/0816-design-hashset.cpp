static void linked_list_delete(ListNode *head) {
    if (head == nullptr) {
        return;
    }
    auto next = head->next; 
    while (next != nullptr) {
        delete head;
        head = next; 
        next = head->next; 
    }
    delete head; 
}

class MyHashSet {
private:
    static constexpr int bucket_size = 1024; 
    array<ListNode*, bucket_size> buckets; 
    static int hash_func(int key) {
        return key % bucket_size;
    }

public:
    MyHashSet() : buckets({}) {}
    ~MyHashSet() {
        for (auto node: buckets) {
            linked_list_delete(node); 
        }
    }
    void add(int key) {
        if (contains(key)) {
            return;
        }
        auto bucket_index = hash_func(key);
        auto node = buckets[bucket_index];
        buckets[bucket_index] = new ListNode(key);
        buckets[bucket_index]->next = node; 
    }
    
    void remove(int key) {
        auto bucket_index = hash_func(key); 
        if (buckets[bucket_index] == nullptr){
            return; 
        } 

        if (buckets[bucket_index]->val == key) {
            auto tmp = buckets[bucket_index]->next; 
            delete buckets[bucket_index];
            buckets[bucket_index] = tmp; 
            return; 
        }

        for (auto node = buckets[bucket_index]; node->next != nullptr; node = node->next) {
            auto next_node = node->next; 
            if (next_node->val != key) {
                continue; 
            } 
            auto next_next_node = next_node->next; 
            delete next_node; 
            node->next = next_next_node;
            return; 
        }

    }
    
    bool contains(int key) {
        auto bucket_index = hash_func(key);
        auto node = buckets[bucket_index];
        while (node != nullptr) {
            if (node->val == key) {
                return true; 
            }
            node = node->next; 
        }
        return false; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */