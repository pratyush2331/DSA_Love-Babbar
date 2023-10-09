// CodeStudio : https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

// BRUTE FORCE
// TC : O(n), SC : O(1)
/*
Node* sortList(Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        else if(temp->data == 2) count2++;
        
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL) {
        if(count0) {
            temp->data = 0;
            count0--;
        }
        else if(count1) {
            temp->data = 1;
            count1--;
        }
        else if(count2) {
            temp->data = 2;
            count2--;
        }
        
        temp = temp->next;
    }
    
    return head;
}
*/

// without updating the value in the Nodes
// TC : O(n), SC : O(1)
Node* insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head) {
    // creating DUMMY NODES
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate lists for 0s, 1s and 2s
    while(curr != NULL) {
        int val = curr->data;
        
        if(val == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(val == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(val == 2) {
            insertAtTail(twoTail, curr);
        }
        
        curr = curr->next;
    }
    
    // merge 3 sublists
    if(oneHead->next != NULL) { // 1st list -> not empty
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    else { // 1s list -> empty
        zeroTail->next = twoHead->next;
    }
    
    twoTail->next = NULL;
    
    // setup head
    head = zeroHead->next;
    
    // delete DUMMY NODES
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
