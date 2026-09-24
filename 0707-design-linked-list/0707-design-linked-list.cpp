class node{
public:
    int val;
    node* next;
    node(int x=0,node* n=nullptr):val(x),next(n){}
    };
class MyLinkedList {
public:
    node dummy;
    node*tail;
    int cap;
    MyLinkedList() {
        cap=0;
        tail=&dummy;
    }
    
    int get(int index) {
        if(index>=cap)return -1;
        node* temp=dummy.next;
        while(index--){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        node* temp=new node(val,dummy.next);
        dummy.next=temp;
        if(!temp->next)
            tail=temp;
        cap++;    
    }
    
    void addAtTail(int val) {
        tail->next=new node(val);
        tail=tail->next;
        cap++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>cap)return;
        node* temp=&(dummy);
        while(index--){
            temp=temp->next;
        }
        
        node* newNode=new node(val,temp->next);
        temp->next=newNode;
        if(!newNode->next)tail=newNode;
        
        cap++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=cap)return;
        node*temp=&(dummy);
        while(index--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        if(temp->next==nullptr)
            tail=temp;
        cap--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */