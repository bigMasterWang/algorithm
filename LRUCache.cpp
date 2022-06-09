#include<map>
using namespace std;


struct LinkNode
{
	int key, value;
	LinkNode* pre, * next;
	LinkNode() :key(0), value(0), pre(nullptr), next(nullptr) {};
	LinkNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {};
};

class LRUCache {
private:
	LinkNode* _head, * _tail = _head;
	map<int, LinkNode*> _nodeMap;
	int _totalSize = 0, _usedSize = 0;

	void freshNode(LinkNode* node)
	{
		//原来末尾的前一位， 变为末尾
		node->pre->next = node->next;
		node->next->pre = node->pre;

		//提到首位
		_head->next->pre = node;
		node->next = _head->next;
		_head->next = node;
		node->pre = _head;
	}
public:
	LRUCache(int capacity) {
		_totalSize = capacity;
	}

	int get(int key) {
		if (_nodeMap.find(key) == _nodeMap.end())
			return 0;
		freshNode(_nodeMap[key]);
		return _nodeMap[key]->value;
	}

	void put(int key, int value) {
		if (_usedSize < _totalSize)
		{
			LinkNode* node = new LinkNode(key, value);
			node->pre = _tail;
			_tail = node;
			_nodeMap[key] = node;
			_usedSize++;
		}
		else
		{
			// 最后一个删除
			_nodeMap.erase(_tail->key);
			_tail->key = key;
			_tail->value = value;
			_nodeMap[key] = _tail;

		}
		freshNode(_tail);
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */