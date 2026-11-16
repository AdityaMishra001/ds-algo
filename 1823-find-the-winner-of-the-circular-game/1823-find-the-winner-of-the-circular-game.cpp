class Solution {
public:
    class Node{
    public:
        int val;
        Node*next;
        Node(int val=0,Node* next=nullptr):val(val),next(next){}
    };
   
       
    Node* winner(int k,Node* head){
        if(head->next==head)
            return head;
        for(int i=1;i<k;i++){
            head=head->next;
        }
        head->val=head->next->val;

        Node* del=head->next;
        head->next=del->next;
        delete del;
        return winner(k,head);
    }
    int findTheWinner(int n, int k) {
        
        if(n==1)
            return 1;
        Node dummy;
        Node* p=&dummy;
        for(int i=1;i<=n;i++){
            p->next=new Node(i);
            p=p->next;
        }
        p->next=dummy.next;
        return winner(k,dummy.next)->val;
    }
};