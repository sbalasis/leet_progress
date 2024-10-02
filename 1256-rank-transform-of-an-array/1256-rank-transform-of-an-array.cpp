
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        // Create a vector of pairs to store value and its original index
        std::vector<std::pair<int, int>> indexedVec;
        std::vector<int> ranks(arr.size(),0);
        for (int i = 0; i < arr.size(); ++i) 
        {
            indexedVec.push_back({i, arr[i]});  // {original_index, value}
        }

        // Sort the vector of pairs by the value (second element of the pair)
        std::sort(indexedVec.begin(), indexedVec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) 
        {
            return a.second < b.second;  // Sort by value (second element)
        });

        // Output the sorted values along with their original indices
        std::cout << "Sorted values with original indices:" << std::endl;
        int tmp = -1;
        int rank = 0;
        for (const auto& kv : indexedVec) 
        {
            if(kv.second != tmp)
            {
                tmp = kv.second;
                rank++;
            }
            ranks[kv.first] = rank;
            std::cout << "Original Index: " << kv.first << ", Value: " << kv.second << std::endl;
        }
        return ranks;
    }
};