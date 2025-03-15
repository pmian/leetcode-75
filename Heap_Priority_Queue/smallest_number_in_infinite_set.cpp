// https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75

class SmallestInfiniteSet
{
public:
    set<int> s;

    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1005; i++)
            s.insert(i);
    }

    int popSmallest()
    {
        auto it = s.begin();
        int ans = *it;
        s.erase(it);
        return ans;
        ;
    }

    void addBack(int num)
    {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */