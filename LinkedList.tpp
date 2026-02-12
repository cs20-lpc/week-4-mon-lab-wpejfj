template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO

  head = nullptr;
  this->length = 0;

  if (copyObj.head == nullptr) {
    return;
  }

  head = new Node(copyObj.head->value);
  this->length = 1;

  Node *i = copyObj.head->next;
  Node *f = head;

  while (i != nullptr) {
    f->next = new Node(i->value);
    f = f->next;
    i = i->next;
    this->length++;
  }

}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO

  if (position < 0 || position > this->length) {
    throw std::string("position out of bounds");
  }

  Node *n = new Node(elem);

  if (position == 0) {
    n->next = head;
    head = n;
  }
  else {
    Node *temp = head;

    for (int i = 0; i < position-1; ++i) {
      temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
  }

  this->length++;

}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
  if (position < 0 || position >= this->length) {
    throw std::string("position out of bounds");
  }

  Node *temp = nullptr;

  if (position == 0) {
    temp = head;
    head = head->next;
  }
  else {
    Node *n = head;

    for (int i = 0; i < position-1; ++i) {
      n = n->next;
    }

    temp = n->next;
    n->next = temp->next;
  }

  delete temp;
  this->length--;

}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
