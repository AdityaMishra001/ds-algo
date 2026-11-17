class Node {
public:
    int val;
    Node* next;
    Node(int v=0,Node* n=nullptr):val(v),next(n){}
};
class Solution {
public:
    int winner(Node* h,int k,int size){
        if(size==1)return h->val;
        // cout<<"Currently at "<<h->val<<endl;
        for(int i=1;i<k;i++){
            h=h->next;
        }

        Node* toBeDel=h->next;
        h->val=toBeDel->val;
        h->next=toBeDel->next;
        // cout<<" Node to Be del "<<toBeDel->val<<endl<<endl;
        delete toBeDel;

        return winner(h,k,size-1);
    }
    int findTheWinner(int n, int k) {
        if(n==1)return 1;
        Node d;
        Node* h=&d;
        for(int i=1;i<=n;i++){
            h->next=new Node(i);
            h=h->next;
        }
        h->next=d.next;
        h=h->next;
        return winner(h,k,n);
    }
};