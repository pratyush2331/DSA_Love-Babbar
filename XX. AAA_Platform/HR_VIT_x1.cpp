/*
A binary tree is a special type of tree in which each node of the tree can have at most two child nodes. These child nodes are known as right child and left child.

Binary Tree using Array: Lets derive the positions of nodes and their parent and child nodes in the array :

When we use 1 index based sequencing.
Suppose parent node is at index p.
Right_node is at index (2*p)+1.
Left_node is at index (2*p).
Example: Let us consider the following Binary tree

     A
   /   \
  B     C
   \   / \
    D E   F
The array representation of the Binary tree is

Index   - | 1 | 2 | 3 |  4 | 5 | 6 | 7 |

Element - | A | B | C | -1 | D | E | F |
Write an algorithm and subsequent code for each following operations on binary tree. Assume nodes of the binary tree has poisitve integers only. -1 in the array indicates that node is not presented in the tree

Number of nodes at level-1(Assume root node is at level-0)
Degree of each node at level-1
Input Format

Number of nodes n

Binary tree in Array and elements in the array are integers

Constraints

n<=10000

Output Format

Number nodes at level-1 and degree of each node at level-1

Sample Input 0

7
A B C -1 D E F
Sample Output 0

2
1 2
Sample Input 1

4
34 7 -1 6
Sample Output 1

1
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   cin>>n;
   
   int t=0;
   
   if(n<=1) {
          cout<<"0";
          return 0;
   }
   
   vector<string> v;
   string x;
   while(t<n && t<=6) {
          cin>>x;
          v.push_back(x);
          t++;
   }
   if(n==2) {
       if(v[1]!="-1") cout<<"1\n0";
       else cout<<"0";
       return 0;
   }
   vector<int> nodes;
   for(int i=1; i<=2; i++) {
       if(v[i]!="-1") {
           nodes.push_back(i);
       }
   }
   cout<<nodes.size()<<endl;
   for(auto x: nodes) {
          int deg=0;
          unsigned i1 = 2*x+1;
          unsigned i2 = 2*x+2;
          if(i1<v.size() && v[i1]!="-1") deg++;
          if(i2<v.size() && v[i2]!="-1") deg++;
          cout<<deg<<" ";
   }
   return 0;
}