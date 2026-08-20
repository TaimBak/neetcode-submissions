class LinkedList {
public:
    struct Node {
        int val;
        Node* next;
    };

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) 
    {   
        if(index < 0 || index >= size)
            return -1;

        Node* itr = head;
        
        for (int i = 0; i < index; i++)
            itr = itr->next;

        return itr->val;
    }

    void insertHead(int val)
    {
        Node* newNode = new Node {val, head};
        head = newNode;
        size++;
    }
    
    void insertTail(int val)
    {
        Node* newNode = new Node {val, nullptr};
        if (head == nullptr)
            head = newNode;
        else
        {
            Node* itr = head;
            while (itr->next != nullptr)
                itr = itr->next;
            itr->next = newNode;
        }
        size++;
    }

    bool remove(int index)
    {
        if (index < 0 || index >= size)
            return false;
        
        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node* itr = head;
            for (int i = 0; i < index - 1; i++)
                itr = itr->next;
            Node* toDelete = itr->next;
            itr->next = toDelete->next;
            delete toDelete;
        }

        size--;
        return true;
    }

    vector<int> getValues()
    {
        vector<int> values;

        Node* itr = head;
        while (itr != nullptr)
        {
            values.push_back(itr->val);
            itr = itr->next;
        }
        return values;
    }

LinkedList::Node* head;
int size;
};
