#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;

template<typename NodeType>
class LinkedList {
private:
	class Node {
	private:
		NodeType value;
		Node* next;

	public:
		Node(NodeType _value, Node* _next = nullptr) : value(_value), next(_next) {}

		NodeType getValue() const { return value; }
		Node* getNext() const { return next; }

		void setNext(Node* _next) { next = _next; }

		friend class LinkedList;
	};

	int size;
	Node* head;

public:

	LinkedList() : size(0), head(nullptr){	}

	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->getNext();
			delete current;
			current = next;
		}
		
	}

	LinkedList(const LinkedList& other) :size(0), head(nullptr) {
		Node* current = other.head;

		while (current != nullptr) {
			add(current->getValue());
			current = current->getNext();
		}
	}
	LinkedList& operator=(const LinkedList& other) {
		if (this != &other) {
			LinkedList temp(other);

			swap(head, temp.head);
			swap(size, temp.size);
		}
		return *this;
	}

	void add(NodeType value) { //добавляет узел в конец
		Node* newNode = new Node(value);

		if (head == nullptr) head = newNode;
		else {
			Node* current = head;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(newNode);
		}
		size++;
	}
	void printAllNodes() const { //перечисляет все узлы в формате {значение - адрес - адрес следующего}
		Node* current = head; // Та же проблема шаблонов, у NodeType может не быть оператора <<. Нужно по хорошему писать concept
		if (head == nullptr) {
			cout << "empty list";
			return;
		}
		while (current->getNext() != nullptr) {
			cout << "Value: " << current->getValue() << "\t Self: " << current << "\t Next: " << current->getNext() << endl;
			current = current->getNext();
		}
		cout << "Value: " << current->getValue() << "\t Self: " << current << "\t Next: " << current->getNext() << endl;
	}

	void delFirstFind(NodeType target) { //Хуево то что раньше тут был int, а теперь вопрос, будет ли это работать например если NodeType = std::vector<T>?
		Node* current = head;
		Node* pred = nullptr;
		if (head == nullptr) {
			cout << "Empty list";
			return;
		}
		while (current != nullptr) {
			if (current->getValue() == target) {
				if (current == head) {
					head = current->getNext();
				}
				else {
					pred->setNext(current->getNext());
				}
				delete current;
				size--;
				return;
			}
			pred = current;
			current = current->getNext();
		}
		cout << "Target didn't exist";
	}
};
