class LNode {
public:
	LNode* prev = nullptr;
	LNode* next = nullptr;
	int value;
	int key;
};

class LRUCache {
public:
	LNode* head;
	LNode* tail;
	int capacity;
	int size;
	unordered_map<int, LNode*> keyToNode;

	LRUCache(int capacity) {
		this->capacity = capacity;
		size = 0;
		head = new LNode();
		tail = new LNode();
		head->next = tail;
		tail->prev = head;
	}

	LNode* insertFront(int key, int value) {
		LNode* newNode = new LNode();
		newNode->key = key;
		newNode->value = value;
		LNode* prev = head;
		LNode* next = head->next;
		newNode->next = next;
		newNode->prev = prev;
		prev->next = newNode;
		next->prev = newNode;
		++size;
		keyToNode[key] = newNode;
		return newNode;
	}

	void remove(LNode* node) {
		LNode* prev = node->prev;
		LNode* next = node->next;

		prev->next = next;
		next->prev = prev;
		--size;
		keyToNode.erase(node->key);
	}

	int get(int key) {
		auto it = keyToNode.find(key);
		if (it == keyToNode.end()) return -1;
		int ans = it->second->value;
		remove(it->second);
		insertFront(key, ans);
		return ans;
	}

    void moveToFront(LNode *node) {
        if(head->next == node) return;
        LNode *prev = node->prev;
        LNode *next = node->next;
        LNode *newPrev = head;
        LNode *newNext = head->next;
        prev->next = next;
        next->prev = prev;
        node->prev = newPrev;
        node->next = newNext;
        newPrev->next = node;
        newNext->prev = node;
    }

	void put(int key, int value) {
		auto it = keyToNode.find(key);
		if (it != keyToNode.end()) {
            it->second->value = value;
			moveToFront(it->second);
		}
		else {
			if (size == capacity) {
				remove(tail->prev);
			}

			insertFront(key, value);
		}
	}
};