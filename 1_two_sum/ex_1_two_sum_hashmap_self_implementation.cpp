#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class KeyValue {
private:
    int *value = nullptr;
    int *key = nullptr;
public:
    void setValue(int val) {
        if (this->value != nullptr) {
            delete this->value;
        }
        this->value = new int(val);
    }
    void setKey(int key) {
        if (this->key != nullptr) {
            delete this->key;
        }
        this->key = new int(key);
    }
    int *getKeyPtr() {
        return this->key;
    }
    int *getValuePtr() {
        return this->value;
    }
};
class HashMap {
private:
    KeyValue *key_value_array;
    int array_size;
public:
    HashMap(int size) {
        this->array_size = size;
        this->key_value_array = new KeyValue[size];
    }
    ~HashMap() {
        delete[] this->key_value_array;
    }
    int hash(int key, int count_collisons = 0) {
        return (abs(key) % 1000 + count_collisons * count_collisons) % 1000;
    }
    int compressor(int hash_code) {
        return hash_code % this->array_size;
    }
    void assign(int key, int val) {
        int idx = this->compressor(this->hash(key));
        KeyValue &bucket = this->key_value_array[idx];
        if (bucket.getValuePtr() == nullptr || *bucket.getKeyPtr() == key) {
            bucket.setKey(key);
            bucket.setValue(val);
            return;
        }
        int count_collision = 1;
        while (count_collision < this->array_size) {
            int new_idx = this->compressor(this->hash(key, count_collision));
            KeyValue &new_bucket = this->key_value_array[new_idx];
            if (new_bucket.getValuePtr() == nullptr || *new_bucket.getKeyPtr() == key) {
                new_bucket.setKey(key);
                new_bucket.setValue(val);
                return;
            }
            count_collision++;
        }
        //cout << "No more space to add more value!\n";
    }
    int *retrieve(int key) {
        int idx = this->compressor(this->hash(key));
        KeyValue &bucket = this->key_value_array[idx];
        if (bucket.getValuePtr() != nullptr && *bucket.getKeyPtr() == key) {
            return bucket.getValuePtr();
        } 
        int count_collisions = 1;
        while (count_collisions < this->array_size) {
            int new_idx = this->compressor(this->hash(key, count_collisions));
            KeyValue &new_bucket = this->key_value_array[new_idx];
            if (new_bucket.getValuePtr() != nullptr && *new_bucket.getKeyPtr() == key) {
                return new_bucket.getValuePtr();
            } 
            if (new_bucket.getValuePtr() == nullptr) {
                //cout << "No such keys in the map!\n";
                return nullptr;
            }
            count_collisions++;
        }
        //cout << "No such keys in the map!\n";
        return nullptr;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (target % 2 == 0) {
            vector<int>::iterator it_first = find(nums.begin(), nums.end(), target / 2);
            vector<int>::iterator it_second = find(it_first + 1, nums.end(), target / 2);
            if (it_first != nums.end() && it_second != nums.end()) {
                result.push_back(distance(nums.begin(), it_first));
                result.push_back(distance(nums.begin(), it_second));
                return result;
            }
        }
        HashMap hash_map(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            hash_map.assign(nums[i], i);
        }
        for (const auto& first_number : nums) {
            if (target % 2 == 0 && first_number == target / 2) {
                continue;
            }
            int second_number = target - first_number;
            int *idx_first = hash_map.retrieve(first_number);
            int *idx_second = hash_map.retrieve(second_number);
            //cout << first_number << ' ' << second_number << '\n';
            //cout << idx_first << ' ' << idx_second << '\n';
            if (idx_first != nullptr && idx_second != nullptr) {
                result.push_back(*idx_first);
                result.push_back(*idx_second);
                break;
            }
        }
        return result;
    }
};
int main() {
    vector<int> p = {3,2,4};
    int target = 6;
    Solution calculate;
    vector<int> result = calculate.twoSum(p, target);
    for (int& ele : result) cout << ele << ' ';
}