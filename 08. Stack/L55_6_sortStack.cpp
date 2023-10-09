// Sort a Stack
// CodeStudio : https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stack, int num) {
	if(stack.empty() || stack.top() < num) {
		stack.push(num);
		return;
	}

	int n = stack.top();
	stack.pop();

	sortedInsert(stack, num);

	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	sortedInsert(stack, num);
}

int main() {

    return 0;
}