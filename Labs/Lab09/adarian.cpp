#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
  char letter;
  int freq;
  Node *left;
  Node *right;

  Node(char letter, int freq) {
    left = NULL;
    right = NULL;
    this->letter = letter;
    this->freq = freq;
  }
};

class path {
public:
  bool operator()(Node *left, Node *right) {
    return (left->freq > right->freq);
  }
};

void print(Node *C, string s, char array[], int num) {
  int i = num;

  if (!C) {
    return;
  }

  if (C->letter == array[i]) {
    cout << C->letter << ":" << s << endl;
  }

  print(C->left, s + "0", array, i);
  print(C->right, s + "1", array, i);
}

void HuffmanCode(char let[], int freq[], int size) {
  Node *x, *y, *C;
  priority_queue<Node *, vector<Node *>, path> A;

  for (int i = 0; i < size; ++i) {
    A.push(new Node(let[i], freq[i]));
  }

  while (A.size() != 1) {
    x = A.top();
    A.pop();
    y = A.top();
    A.pop();
    C = new Node('Z', (x->freq + y->freq));
    C->left = x;
    C->right = y;
    A.push(C);
  }

  for (int i = 0; i < 6; i++) {
    print(A.top(), "", let, i);
  }
}

int main() {
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  int freq[6];

  for (int i = 0; i < 6; i++) {
    cin >> freq[i];
  }

  HuffmanCode(letters, freq, 6);

  return 0;
}
