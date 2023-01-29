// Problem Link: https://leetcode.com/problems/lfu-cache/
// Leetcode I'd: https://leetcode.com/dilsekhpatnaik7/

using Key_t = int;
using Count_t = int;
struct Node {
    int value;
    list<Key_t>::iterator itr;
};

class LFUCache {
    unordered_map<Key_t, Node> m_values;
    unordered_map<Key_t, Count_t> m_counts;
    unordered_map<Count_t, list<Key_t>> m_countKeyMap;
    int m_lowestFrequency;
    int m_maxCapacity;

public:
    LFUCache(int capacity) {
        m_maxCapacity = capacity;
        m_lowestFrequency = 0;
    }

    int get(int key) {
        if (m_values.find(key) == m_values.end() || m_maxCapacity <= 0)
        {
            return -1;
        }
        put(key, m_values[key].value);
        return m_values[key].value;
    }

    void put(int key, int value) {
        if (m_maxCapacity <= 0) {
            return;
        }
        if (m_values.find(key) == m_values.end()) {
            if (m_values.size() == m_maxCapacity)
            {
                int keyToDelete = m_countKeyMap[m_lowestFrequency].back(); 
                m_countKeyMap[m_lowestFrequency].pop_back();
                if (m_countKeyMap[m_lowestFrequency].empty())
                {
                    m_countKeyMap.erase(m_lowestFrequency);
                }
                m_values.erase(keyToDelete);
                m_counts.erase(keyToDelete);
            }
            m_values[key].value = value;
            m_counts[key] = 0;
            m_lowestFrequency = 0;
            m_countKeyMap[m_counts[key]].push_front(key);
            m_values[key].itr = m_countKeyMap[0].begin();
        }
        else {
            m_countKeyMap[m_counts[key]].erase(m_values[key].itr);
            if (m_countKeyMap[m_counts[key]].empty())
            {
                if (m_lowestFrequency == m_counts[key])
                    m_lowestFrequency++;
                m_countKeyMap.erase(m_counts[key]);
            }
            m_values[key].value = value;
            m_counts[key]++;
            m_countKeyMap[m_counts[key]].push_front(key);
            m_values[key].itr = m_countKeyMap[m_counts[key]].begin();
        }
    }
};