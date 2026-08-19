class DynamicArray {
public:

    DynamicArray(int capacity)
    {
        arr = std::make_unique<int[]>(capacity);
        m_capacity = capacity;
        m_size = 0;
    }

    int get(int i)
    {
        return arr[i];
    }

    void set(int i, int n) 
    {
        arr[i] = n;
    }

    void pushback(int n) 
    {
        if (m_size == m_capacity)
            resize();
        

        arr[m_size] = n;
        m_size++;
    }

    int popback() 
    {
        m_size--;
        return arr[m_size];
    }

    void resize() 
    {
        std::unique_ptr<int[]> newArr = std::make_unique<int[]>(2 * m_capacity);
        
        for (int i = 0; i < m_size; i++)
            newArr[i] = arr[i];

        arr = std::move(newArr);
        m_capacity *= 2;
    }

    int getSize() 
    {
        return m_size;
    }

    int getCapacity() {
        return m_capacity;
    }

private:
std::unique_ptr<int[]> arr;
int m_size, m_capacity;
};
