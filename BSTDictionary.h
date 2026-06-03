#pragma once

#include "Dictionary.h"
#include "BSTree.h"
#include "Pair.h"

template <typename K, typename V>
class BSTDictionary : public Dictionary<K, V> {
private:
	BSTree<Pair<K, V>>* tree;

public:
	BSTDictionary() {
		tree = new BSTree<Pair<K, V>>();
	}
	~BSTDictionary() {
		delete tree;
	}
	void insert(K key, V value) {
		Pair<K, V> p(key, value);
		tree->insert(p);
	}
};