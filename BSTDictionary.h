#pragma once

#include "Dictionary.h"
#include "BSTree.h"
#include "Pair.h"
#include "List.h"
#include "DLinkedList.h"

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
	V remove(K key) {
		Pair<K, V> p(key);
		p = tree->remove(p);
		return p.value;
	}
	V getValue(K key) {
		Pair<K, V> p(key);
		p = tree->find(p);
		return p.value;
	}
	void setValue(K key, V value) {
		Pair<K, V> p(key);
		tree->remove(p);
		p.value = value;
		tree->insert(p);
	}
	bool contains(K key) {
		Pair<K, V> p(key);
		return tree->contains(p);
	}
	bool isEmpty() {
		return tree->isEmpty();
	}
	void clear() {
		tree->clear();
	}
	List<K>* getKeys() {
		List<Pair<K, V>>* elements = tree->getElements();
		List<K>* keys = new DLinkedList<K>();
		for (elements->goToStart(); !elements->atEnd(); elements->next())
			keys->append(elements->getElement().key);
		delete elements;
		return keys;
	}
	List<V>* getValues() {
		List<Pair<K, V>>* elements = tree->getElements();
		List<V>* values = new DLinkedList<V>();
		for (elements->goToStart(); !elements->atEnd(); elements->next())
			values->append(elements->getElement().value);
		delete elements;
		return values;
	}
	int getSize() {
		return tree->getSize();
	}
	void update(Dictionary<K, V>* D) {
		List<K>* keys = D->getKeys();
		for (keys->goToStart(); !keys->atEnd(); keys->next()) {
			K key = keys->getElement();
			V value = D->getValue(key);
			if (contains(key))
				setValue(key, value);
			else
				insert(key, value);
		}
		delete keys;
	}
	void print() {
		tree->print();
	}
};