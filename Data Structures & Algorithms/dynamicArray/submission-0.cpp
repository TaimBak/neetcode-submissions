class DynamicArray {
public:

    DynamicArray(int capacity)
    : m_arr(std::make_unique<int[]>(capacity))
    , m_length(0)
    , m_capacity(capacity) {
  
    }

    int get(int i) {
        return m_arr[i];
    }

    void set(int i, int n) {
        m_arr[i] = n;
    }

    void pushback(int n) {
        if (m_length == m_capacity)
            resize();

        m_arr[m_length] = n;
        m_length++;
    }

    int popback() {
        m_length--;
        int value = m_arr[m_length];

        return value;
    }
    void resize() {
        std::unique_ptr<int[]> newArr = std::make_unique<int[]>(m_capacity * 2);

        for (int i = 0; i < (int)m_length; i++)
        {
            newArr[i] = m_arr[i];
        }

        m_arr = std::move(newArr);
        m_capacity *= 2;
    }

    int getSize() {
        return m_length;
    }

    int getCapacity() {
        return m_capacity;
    }
private:
    std::unique_ptr<int[]> m_arr;
    size_t m_length, m_capacity;
};
