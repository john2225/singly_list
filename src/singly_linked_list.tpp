/* parametrize ctor */
template <typename T>
singly_list<T>::singly_list(const T &element) : _head{new Node<T>(element)}
{
    ++_size;
}
/* parametrize ctor initializer_list*/
template<typename T>
singly_list<T>::singly_list(const std::initializer_list<T>& element)
{
    for(auto e : element)
    {
        push_front(e);
    }
    reverse();
}
/* copy ctor */
template <typename T>
singly_list<T>::singly_list(const singly_list<T> &obj)
{
    if (obj._head == nullptr)
    {
        _head = nullptr;
    }
    else
    {
        _head = new Node<T>(obj._head->data);
        Node<T> *current = _head;
        Node<T> *objHead = obj._head;
        Node<T>* currentObj = objHead;
        while (currentObj->next != nullptr)
        {
            current->next = new Node<T>(currentObj->next->data);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    _size = obj._size;
}
/* move ctor */
template<typename T>
singly_list<T>::singly_list(singly_list<T>&& obj)
{
    _head = obj._head;
    _size = obj._size;
    obj._head = nullptr;
    obj._size = 0;
}
/* copy assignment */
template<typename T>
singly_list<T>& singly_list<T>::operator=(const singly_list& obj)
{
    if(this == &obj) { return *this; }
    
    if (obj._head == nullptr)
    {
        _head = nullptr;
    }
    else
    {
        _head = new Node<T>(obj._head->data);
        Node<T> *current = _head;
        Node<T> *objHead = obj._head;
        Node<T>* currentObj = objHead;
        while (currentObj->next != nullptr)
        {
            current->next = new Node<T>(currentObj->next->data);
            currentObj = currentObj->next;
            current = current->next;
        }
    }
    _size = obj._size;
    return *this;
}
/* move assignment */
template<typename T>
singly_list<T>& singly_list<T>::operator=(singly_list<T>&& obj)
{
    _head = obj._head;
    _size = obj._size;
    obj._head = nullptr;
    obj._size = 0;
    return *this;
}
/* is_empty */
template<typename T>
bool singly_list<T>::is_empty()
{
    return _head == nullptr ? true : false;
}
/* push_front lvalue */
template<typename T>
void singly_list<T>::push_front(const T& element)
{
    Node<T>* node = new Node<T>(element,_head);
    _head = node;
    ++_size;
}
/* push_front rvalue */
template <typename T>
void singly_list<T>::push_front(T&& element)
{
    Node<T>* node = new Node<T>(element,_head);
    _head = node;
    ++_size;
}
/* pop_front */
template<typename T>
void singly_list<T>::pop_front()
{
    if(_head == nullptr) { return; }
    Node<T>* node = _head->next;
    delete _head;
    _head = node;
    --_size;
}
/* insert element at position */
template <typename T>
void singly_list<T>::insert(const T& element, std::size_t position)
{
    if((position < 0) || (position > _size))
    {
        std::cout << "out of range!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(0 == position)
    {
        push_front(element);
        return;
    }
    Node<T>* node = new Node<T>(element);
    Node<T>* current = _head;
    for(int i = 1; i < position; ++i)
    {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    ++_size;
}
/* remove_at position */
template<typename T>
void singly_list<T>::remove_at(std::size_t position)
{
    if((position < 0) || (position > _size))
    {
        std::cout << "out of range!" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(0 == position)
    {
        pop_front();
    }
    Node<T>* node = nullptr;
    Node<T>* current = _head;
    for(int i = 1; i < position; ++i)
    {
        current = current->next;
    }
    node = current->next;
    current->next = node->next;
    delete node;
    node = nullptr;
    --_size;
 }
/* traverse */
template<typename T>
void singly_list<T>::traverse(void (*print)(const T &element))
{
    Node<T>* current = _head;
    while(current != nullptr)
    {
        (*print)(current->data);
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
/* reverse */
template<typename T>
void singly_list<T>::reverse() noexcept
{
    Node<T>* current = _head;
 
    if((current == nullptr) || (current->next == nullptr))
    {
        return;
    }
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    while(current != nullptr)
    {   
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    _head = prev;
}
/* destructor */
template <typename T>
singly_list<T>::~singly_list()
{
    while(_head != nullptr){ pop_front(); }
}
