#include <iostream>
#include <vector>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

template<class K, class T>
struct LRUCacheEntry
{
	K key;
	T data;
	LRUCacheEntry* prev;
	LRUCacheEntry* next;
};

template<class K, class T>
class LRUCache
{
private:
	hash_map< K, LRUCacheEntry<K,T>* >	_mapping;
	vector< LRUCacheEntry<K,T>* >		_freeEntries;
	LRUCacheEntry<K,T> *			head;
	LRUCacheEntry<K,T> *			tail;
	LRUCacheEntry<K,T> *			entries;
public:
	LRUCache(size_t size){
		entries = new LRUCacheEntry<K,T>[size];
		for (unsigned int i=0; i<size; i++)
			_freeEntries.push_back(entries+i);
		head = new LRUCacheEntry<K,T>;
		tail = new LRUCacheEntry<K,T>;
		head->prev = NULL;
		head->next = tail;
		tail->next = NULL;
		tail->prev = head;
	}
	~LRUCache()
	{
		delete head;
		delete tail;
		delete [] entries;
	}
	void put(K key, T data)
	{
		LRUCacheEntry<K,T>* node = _mapping[key];
		if(node)
		{
			// refresh the link list
			printf("Adding (%d, %d), map already knows key, size of map: %d\n", key, data, _mapping.size());
			detach(node);
			node->data = data;
			attach(node);
		}
		else{
			printf("Adding (%d, %d), map doesn't  know key, size of map: %d\n", key, data, _mapping.size());
			if ( _freeEntries.empty() )
			{
				node = tail->prev;
				detach(node);
				_mapping.erase(node->key);
				node->data = data;
				node->key = key;
				attach(node);
				_mapping[node->key] = node;
			}
			else{
				node = _freeEntries.back();
				_freeEntries.pop_back();
				node->key = key;
				node->data = data;
				_mapping[key] = node;
				attach(node);
			}
		}
	}

	T get(K key)
	{
		LRUCacheEntry<K,T>* node = _mapping[key];
		if(node)
		{
			detach(node);
			attach(node);
			return node->data;
		}
		else return INT_MIN;
	}

private:
	void detach(LRUCacheEntry<K,T>* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void attach(LRUCacheEntry<K,T>* node)
	{
		node->next = head->next;
		node->prev = head;
		head->next = node;
		node->next->prev = node;
	}
};

#define N 1

int main() {
	LRUCache<int, int> cache(N);
	cache.put(2, 1);
	printf("get data at index %d: %d\n", 2, cache.get(2));
	cache.put(3, 2);
	printf("get data at index %d: %d\n", 2, cache.get(2));
	printf("get data at index %d: %d\n", 3, cache.get(3));
    // for (int i = 0; i < N; i++) {
	// 	cache.put(i, i);
	// 	cache.put(i, i+1);
	// }
	// printf("Start querying...\n");
    // for (int i = 0; i < N+1; i++) {
	// 	printf("get data at index %d: %d\n", i, cache.get(i));
	// }
	return 0;
}
