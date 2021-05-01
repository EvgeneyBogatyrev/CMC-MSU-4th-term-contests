#include <vector>
#include <algorithm>

void process(const std::vector<int> &indices, std::vector<int> &vector)
{
    std::vector<int> indices_copy(indices);

    auto begin = indices_copy.begin();
    auto end = indices_copy.end();

    std::sort(begin, end, [] (int a, int b) {return a < b;});
    end = std::unique(begin, end);
   
    auto cur = begin;

    while (cur < end && *cur < 0) {
        ++cur;
    }

    int index = 0;
    int removed = 0;
    
    for (auto it = vector.begin(); it < vector.end(); ++it) {
        if (cur < end && index + removed == *cur && it + removed < vector.end()) {
            ++cur;
            ++removed;
        }

        if (it + removed < vector.end() && removed > 0) {
            std::swap(*it, *(it + removed));
        }

        ++index;
    }

    vector.resize(vector.size() - removed);
}
