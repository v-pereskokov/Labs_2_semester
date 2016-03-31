struct stack {
public:
    stack()
    :head_(nullptr) {}
    
    ~stack() {
        node *temp = head_;
        while(temp != nullptr) {
            head_ = head_->pnext;
            delete temp;
            temp = head_;
        }
    }
    
    void add(int &data) {
        node *temp = new node(data);
        temp->pnext = head_;
        head_ = temp;
        delete temp;
    }
    
    int get() {
        return head_->data;
    }
    
    bool del() {
        if (isEmpty())
            return false;
        node *tmp = head_;
        head_ = head_->pnext;
        delete tmp;
        return true;
    }
    
    bool isEmpty() {
        return head_ ? false : true;
    }
private:
    struct node {
        node()
        :pnext(nullptr), data(0) {}
        
        ~node() = default;
        
        node *pnext;
        int data;
    };
    node *head_;
};
