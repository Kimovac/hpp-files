#ifndef _PY_PRINT_HPP_
#define _PY_PRINT_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

//Print function prints wihth a new line,
//where as print_alt doesn't. print_alt is
//exclusively used in print implementations.

//Data strucures that print supports: 
//pair<T1, T2>, map<T1, T2>, set<T>, 
//stack<T>, vector<T>, vector<vector<T>>;


template<typename T>
void print(const T &p) {
	cout << p << "\n";
}

template<typename T>
void print_alt(const T &p) {
	cout << p;
}

template<typename T1, typename T2>
void print(const pair<T1, T2> &p) {
	cout << "(";
	print_alt(p.first);
	cout << ", ";
	print_alt(p.second);
	cout << ")";
	cout << "\n";
}

template<typename T1, typename T2>
void print_alt(const pair<T1, T2> &p) {
	cout << "(";
	print_alt(p.first);
	cout << ", ";
	print_alt(p.second);
	cout << ")";
}

template<typename T1, typename T2>
void print(const map<T1, T2> &p) {
	int size = p.size();
	cout << "[";
	for(auto it = p.begin(); it!= p.end(); it++) {
		if(--size) {
			cout << "(";
			print_alt(it->first);
			cout << " : ";
			print_alt(it->second);
			cout << "), ";
		}
		else {
			cout << "(";
			print_alt(it->first);
			cout << " : ";
			print_alt(it->second);
			cout << ")";
		}
	}
	cout << "]";
	cout << "\n";
}

template<typename T1, typename T2>
void print_alt(const map<T1, T2> &p) {
	cout << "[";
	for(auto it = p.begin(); it!= p.end(); it++) {
		int size = p.size();
		if(--size) {
			cout << "(";
			print_alt(it->first);
			cout << " : ";
			print_alt(it->second);
			cout << "), ";
		}
		else {
			cout << "(";
			print_alt(it->first);
			cout << " : ";
			print_alt(it->second);
			cout << ")";
		}
	}
	cout << "]";
}

template<typename T>
void print(const set<T> &p) {
	int size = p.size();
	cout << "{";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(--size) {
			print_alt(*it);
			cout << ", ";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "}";
	cout << "\n";
}

template<typename T>
void print_alt(const set<T> &p) {
	int size = p.size();
	cout << "{";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(--size) {
			print_alt(*it);
			cout << ", ";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "}";
}

template<typename T>
void print(stack<T> p) {
	while(!p.empty()) {
		cout << "|";
		auto it = p.top();
		p.pop();
		print_alt(it);
		cout << "|\n";
	}
	cout << "\n";
}

template<typename T>
void print_alt(stack<T> p) {
	while(!p.empty()) {
		cout << "|";
		auto it = p.top();
		p.pop();
		print_alt(it);
		cout << "|\n";
	}
}

template<typename T>
void print(const vector<T> &p) {
	cout << "[";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(it != p.end()-1) {
			print_alt(*it);
			cout << ", ";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "]";
	cout << "\n";
}

template<typename T>
void print_alt(const vector<T> &p) {
	cout << "[";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(it != p.end()-1) {
			print_alt(*it);
			cout << ", ";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "]";
}

template<typename T>
void print(const vector<vector<T>> &p) {
	cout << "[\n";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(it != p.end()-1) {
			print_alt(*it);
			cout << ", \n";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "\n]";
	cout << "\n";
}

template<typename T>
void print_alt(const vector<vector<T>> &p) {
	cout << "[\n";
	for(auto it = p.begin(); it != p.end(); it++) {
		if(it != p.end()-1) {
			print_alt(*it);
			cout << ", \n";
		}
		else {
			print_alt(*it);
		}
	}
	cout << "\n]";
}


#endif