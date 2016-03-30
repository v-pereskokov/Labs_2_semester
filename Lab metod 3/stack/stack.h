struct stack {
	stack()
	:size_(100), head_(0), value_(new int[100]) {
        memset(value_, 0, size_);
    }

	stack(const int size)
	:size_(size), head_(0), value_(new int[size]) {
        memset(value_, 0, size_);
    }

	stack(const stack &copy)
	:size_(copy.size_), head_(copy.head_), value_(new int[copy.size_]) {
		for (size_t i = 0; i < head_; ++i)
			value_[i] = copy.value_[i];
	}

	~stack() {
		delete [] value_;
	}

	bool add(const int value) {
		if (head_ >= size_)
			return false;
		value_[head_++] = value;
		return true;
	}

	bool del() {
		if (head_ <= 0)
			return false;
		--head_;
		return true;
	}

	int get() const {
		if (head_ < 0)
			return -1;
		return value_[head_ - 1];
	}
private:
	int *value_;
	int head_;
	int size_;
};

//struct stack
//{
//    stack(tdata data, stack *next)
//    : data_(data), next_(next) {}
//    
//    ~Stack() = default;
//    
//    int	data_;
//    stack	*next_;
//};
//
//
//class StackController
//{
//public:
//    StackController()
//    : head(nullptr) {}
//    ~StackController() = default;
//    
//    
//    void	add(tdata data) {
//        stack *newElement = new Stack(data, head);
//        head = newElement;
//    }
//    
//    void	del(void) {
//        stack *deleted = head;
//        head = head->next;
//        
//        delete deleted;
//    }
//    
//    int	get(void) {
//        return head->data;
//    }
//private:
//    stack	*head;
//};
