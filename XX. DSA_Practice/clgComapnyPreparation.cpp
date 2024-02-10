// --------------------------------------------------- TCS DIGITAL --------------------------------------------------------

// rotate array from k
/*
#include<iostream>
using namespace std;

void reverseArr(int* &arr, int s, int e) {
	while(s < e) {
		swap(arr[s++], arr[e--]);
	}
}

int main() {
	int n;
	cin >> n;
	
	int *arr = new int[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int k;
	cin >> k;
	k %= n;

	// reverse till k
	reverseArr(arr, 0, n-1);
	reverseArr(arr, 0, k-1);
	reverseArr(arr, k, n-1);

	// display
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}
*/

// --------------------------------------------------- ACCENTURE --------------------------------------------------------

/*
I/P:
9
10 12 5 40 30 7 50 9 10

O/P:
9 12 5 7 30 40 50 10 10 
*/

/*
#include<iostream>
using namespace std;

// 2 pointer approach
void solve(int* &arr, int n) {

}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	// input
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	solve(arr, n);

	// display
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}
*/

// [a, b] --> count of numbers with non-repeating digit
/*
#include<iostream>
#include<unordered_map>
using namespace std;

bool checkRepeat (int n) {
	unordered_map<int, int> map;
	int temp = n;
	while(temp) {
		int digit = temp%10;
		if(map[digit]) {
			return 1; // repeated
		}
		map[digit]++;
		temp /= 10;
	}
	return 0;
}

int getNumber(int a, int b) {
	int count = 0;
	for(int i = a; i <= b; i++) {
		if(checkRepeat(i) == 0) { // not repeated
			count++;
		}
	}
	return count;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << getNumber(a, b) << endl;
	
	return 0;
}
*/

/*
// check for first row, first col, last row, last col

#include<iostream>
using namespace std;

int main() {
	int a, b, n;
	cin >> a >> b >> n;

	// check for first row
	if(n <= b) cout << "Yes" << endl;
	// first col
	else if(n%b == 1) cout << "Yes" << endl;
	// last col
	else if(n%b == 0) cout << "Yes" << endl;
	// last row
	if((a-1)*b < n && n <= a*b) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
*/





// Singly Linked List (SLL) implementation
/*
#include<iostream>
using namespace std;

// Node - class
class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d) {
    Node* n = new Node(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// WRONG OUTPUT
// void pairWiseSwap(Node* &head) {
// 	Node* temp = head;

// 	while(temp && temp->next) {
// 		Node* next = temp->next;
		
// 		temp->next = next->next;
// 		next->next = temp;

// 		temp = temp->next;
// 	}
// }

void pairWiseSwap(Node* &head) {
    Node* temp = head;

    while (temp && temp->next) {
		Node* next = temp->next;

        temp->next = next->next;
        next->next = temp;

        temp = temp->next;
        if (temp && temp->next) {
            next->next->next = temp->next;
        }
    }
}


int main() {
    Node* head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    print(head);

	pairWiseSwap(head);

    print(head);
    
    return 0;
}
*/

/*
// Nikita and her

#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int N;
		cin >> N;

		int* arr = new int[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		int Q;
		cin >> Q;

		int L, R;
		cin >> L >> R;
	}

	delete[] arr;
	
	return 0;
}
*/

// Longest Palindrome Subsequence
/*
#include<iostream>
#include<map>
using namespace std;

int longestPalindromeSubseq(string str) {
	int count = 0;

	

	return count;
}

int main() {
	string str;
	cin >> str;

	cout << longestPalindromeSubseq(str) << endl;
	
	return 0;
}
*/

// 
/*
#include<iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	cout << ((15&x>>4) | (240&x<<4)) << endl;
	
	return 0;
}
*/

// Level Order Traversal - BFS

/*
#include<iostream>
#include<queue>
using namespace std;

class node {
  public:
	int data;
	node* left;
	node* right;

	node(int d) {
		this->data = d;
		this->left = NULL;
		this->right = NULL;
	}
};

node* buildTree(node* root) {
	int data;
	cout << "Enter value : ";
	cin >> data;

	// base case
	if(data == -1) {
		return NULL;
	}

	root = new node(data);

	cout << "Enter value for left of " << data << endl;
	root->left = buildTree(root->left);

	cout << "Enter value for right of " << data << endl;
	root->right = buildTree(root->right);

	return root;
}

void levelOrderTraversal(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;

			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";

			if(temp->left)
				q.push(temp->left);

			if(temp->right)
				q.push(temp->right);
		}
	}
}

int main() {
	node* root = NULL;

	root = buildTree(root);

	levelOrderTraversal(root);
	
	return 0;
}
*/

// Bit Masking && Bit Manipulation
/*
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;

	int count = 0;
	int temp = n;
	while(temp) {
		count++;
		temp = temp>>1;
	}

	int ans = 0;

	// cout << count << endl;
	int maxi = max(count, max(a, b));

	temp = n;
	int cnt = 0;
	while(maxi) {
		bool bit = (n>>(maxi-1))&1;
		cout << bit << " ";

		if(cnt == a) {
			bit = (n>>b) & 1;
		}
		if(cnt == b) {
			bit = (n>>a) & 1;
		}

		count--;
		cnt++;
		if(maxi != 0) {
			ans = ans | bit;
			ans = ans << 1;
		}
	}

	cout << "ans : " << ans << endl;

	// ans = ans | b1;

	return 0;
}
*/



// ------------------------------------------------ TCS NINJA ------------------------------------------------



// Increment Operator in printf in C/C++
/*
#include<iostream>
using namespace std;

int main() {
	int a = 10;

	// cout << a++ << " " << ++a << " " << a << " " << a++ << " " << ++a << endl;

	printf("%d %d %d %d %d\n", a++, ++a, a, a++, ++a);

	// printf("%d %d %d\n", a, a++, ++a);
	
	return 0;
}
*/




// ------------------------------------------------ SDOT (Super Dream) --------------------------------------------------

// Linked List -> SLL, DLL, CLL, DSLL, DCLL, insertAtPos, deleteAtPos...
/*
Input : L0 -> L1 -> L2 ...... -> Ln-1 -> Ln
Output : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 .......
*/
/*
#include<iostream>
using namespace std;

// Node - class
class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d) {
    Node* n = new Node(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* findMid(Node* head) {
	Node* slow = head;
	Node* fast = head->next;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node* reverse(Node* head) {
	if(!head || !(head->next)) {
		return head;
	}
	Node* chotaHead = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return chotaHead;
}

Node* reverseList(Node* head) {
	return reverse(head);
}

void changeOrder(Node* head) {
	Node* temp = head;

	Node* mid = findMid(head);

	Node* p1 = head;
	while(temp->next != mid->next) {
		temp = temp->next;
	}
	Node* p2 = temp->next;
	temp->next = NULL;

	print(p1);

	reverseList(p2);

	print(p2);

}

int main() {

	Node* head = NULL;
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    // insertAtTail(head, 9);

    print(head);

	changeOrder(head);

    // print(head);
	
	return 0;
}
*/

// SLL
// 1 -> insert, 0 -> display
/*
#include<iostream>
using namespace std;

// Node - class
class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d) {
    Node* n = new Node(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
	Node* head = NULL;

	int choice = 1;
	while(choice != -1) {
		cout << "Enter choice (1, 0, -1) : ";
		cin >> choice;

		switch(choice) {
			case 1:
			int data;
			cout << "Enter data : ";
			cin >> data;
			insertAtTail(head, data);
			break;

			case 0:
			print(head);
			break;

			case -1:
			cout << "Exiting...\n";
			return 0;

			default:
			cout << "ENter valid choice\n";
		}
	}
	
	return 0;
}
*/

// Diagonal
/*
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	while(i <= n) {

		// space
		int k = n-i;
		while(k >= 1) {
			cout << " ";
			k--;
		}

		// upper triangle
		int j = 1;
		while(j <= i) {
			cout << "* ";
			j++;
		}

		i++;
		cout << endl;
	}

	i = 1;
	while(i <= n) {

		// space
		int k = n-i;
		while(k < n) {
			cout << " ";
			k++;
		}
		
		// Lower triangle
		int p = n-i;
		while(p >= 1) {
			cout << "* ";
			p--;
		}

		i++;
		cout << endl;
	}
	
	return 0;
}
*/


/*
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	while(i <= n) {
		int j = 1;
		if(!(i & 1)) { // i --> even
			cout << i+1 << " ";
		}
		while(j <= n-1) {
			cout << i << " ";
			j++;
		}
		if(i & 1) { // i --> odd
			cout << i+1 << " ";
		}

		cout << endl;
		i++;
	}
	
	return 0;
}
*/

// Singly Linked List (SLL) implementation
/*
#include<iostream>
using namespace std;

// Node - class
class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    // new node create
    Node* temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, int d) {
    Node* n = new Node(d);

    // list is empty
    if(head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}


int main() {
	Node* head = NULL;

	int choice = 1;
	while(choice != -1) {
		cout << "Enter choice (1, 0, -1) : ";
		cin >> choice;

		switch(choice) {
			case 1:
			int data;
			cout << "Enter data : ";
			cin >> data;
			if(!search(head, data))
				insertAtTail(head, data);
			else {
				cout << "Duplicate value = " << data << endl;
			}
			break;

			case 0:
			print(head);
			break;

			case -1:
			cout << "Exiting...\n";
			return 0;

			default:
			cout << "ENter valid choice\n";
		}
	}
	
	return 0;
}
*/

// Identify Seq and write the program for it...
/*
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i = 1;
	int prev = 2;
	while(i <= n) {
		cout << prev << " ";
		prev += i*13;
		i++;
	}
	
	return 0;
}
*/

// 
/*
#include<iostream>
using namespace std;

bool isPossible(int dist, int a, int b, int c, int d) {
	if(d == 0) {
		if(dist == c) {
			return 1;
		}
		else {
			return 0;
		}
	}

	dist = (dist<c) ? dist+b : dist-b;

	return isPossible(dist, a, b, c, d-1);
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		cout << isPossible(a, a, b, c, d) << endl;
	}
	
	return 0;
}
*/

