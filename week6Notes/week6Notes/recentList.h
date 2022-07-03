template <class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node<T>(const T& data_, Node<T>* next_ = nullptr, Node<T>* prev_ = nullptr) {
		data = data_;
		next = next_;
		prev = prev_;
	}
};

template <class T>
class RecentLists {
	Node<T>* front;
	Node<T>* end;
	int listSize;
public:
	RecentLists();
	void insert(const T&);
	bool copyToArray(T array[], int capacity);
	~RecentLists();
};