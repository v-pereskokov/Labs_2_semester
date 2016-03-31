struct stack {
public:
    stack()
    :head_(nullptr) {}
    
    ~stack() {
        node *temp = head_;
        while(temp != nullptr) {
            head_ = head_->pnext_;
            delete temp;
            temp = head_;
        }
    }
    
    void add(int &data) {
        node *temp = new node(data);
        temp->pnext_ = head_;
        head_ = temp;
        delete temp;
    }
    
    int get() {
        return head_->data_;
    }
    
    bool del() {
        if (isEmpty())
            return false;
        node *tmp = head_;
        head_ = head_->pnext_;
        delete tmp;
        return true;
    }
    
    bool isEmpty() {
        return head_ ? false : true;
    }
private:
    struct node {
        node()
        :pnext_(nullptr), data_(0) {}
        
        node *pnext_;
        int data_;
    };
    node *head_;
};
