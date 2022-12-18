#pragma once
#include<iostream>
#include<vector>
using namespace std;

template <typename T >
class priority_queue {
private:
	int p_size;
	vector<T> v;
public:
	priority_queue() {
		p_size = 0;
		v.push_back(0);
	}
	void push(const T& elem) {
		v.push_back(elem);

		if (empty()) {
			p_size++;
			return;
		}

		int idx = v.size() - 1, parent = 0, child = 0;
		while (idx > 1) {
			child = idx;
			parent = idx / 2;
			if (v[parent] < v[child]) {
				swap(v[parent], v[child]);
				idx = parent;
			}
			else
				break;
		}
		p_size++;

	}
	void heapify(const int& idx) {
		int curIdx = idx;
		int left = 2 * idx;
		int right = 2 * idx + 1;

		if (left <= v.size() - 1 && v[curIdx] <= v[left]) {
			curIdx = left;
		}
		if (right <= v.size() - 1 && v[curIdx] <= v[right]) {
			curIdx = right;
		}
		if (curIdx != idx) {
			swap(v[curIdx], v[idx]);
			heapify(curIdx);
		}

	}
	void pop() {
		if (empty()) {
			cout << "우선순위 큐 비어있음";
			return;
		}
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);
		p_size--;
	}
	T top()
	{
		return v[1];
	}
	int size()
	{
		return p_size;
	}
	bool empty()
	{
		if (p_size) return false;
		else return true;
	}
	void print() {
		cout << "우선순위 큐의 원소들: ";
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
};