#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i = vector<int>;
class Node {
    public:
      int data;
      Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
Node* add_node(int data,Node* head,Node** tail) {
    if(head == NULL) {
        head = new Node(data);
       *tail = head;
    }else {
         (*tail) ->next = new Node(data);
         (*tail) =(*tail)->next;
    }
    return head;
}
Node* rotate (Node* head, Node* tail ,int d) {
   Node* temp = head->next;
   int size = 1;
   while(temp->next != tail) {
       temp = temp->next;
       size++;
   }
   temp->next = head->next;
   int t = abs(d) % size;
   d = d > 0 ? t : size - t;
   Node* pre = temp;
   temp = head->next;
   while(d >= 1) {
       temp = temp->next;
       pre = pre->next;
       d--;
   }
   pre->next = tail;
   head->next = temp;
   return head->next;
 }
Node* rotateBlockWise(Node* head,Node* tail,int k,int d) {
    if(head==NULL || head->next==NULL) return head;

    Node* head_temp = new Node(-1);
    Node* tail_temp = new Node(-1);

    head_temp->next = head;
    tail->next = tail_temp;
    int p = k;
    tail = head;
    head = head_temp;
    while( true ) {
        tail = tail -> next;
        if(p==1 || tail == tail_temp) {
            p=k+1;
            head->next = rotate(head,tail,d);
            while (head->next != tail)
            {
                head = head->next;
            }
            if(tail==tail_temp) break;
        }
        p--;
    }
  tail = head;
  tail->next = NULL;
  head = head_temp->next;
  return head;
}
void solve() {
  int n,k,d;
  cin>>n>>k>>d;
  Node* head = NULL;
  Node* tail = NULL;
  for(int i=0;i<n;i++)  {
      int data;
      cin>>data;
      head = add_node(data,head,&tail);
    }
    head = rotateBlockWise(head,tail,k,d);
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<' ';
        temp = temp->next;
    }
}
int main() {
#ifndef ONLINE_JUDGE
freopen("e:/competitive/input.txt", "r", stdin);
freopen("e:/competitive/output.txt", "w", stdout);
#endif
// int t;
// cin>>t;
// while(t--){
solve();
 // }
return 0;
 }