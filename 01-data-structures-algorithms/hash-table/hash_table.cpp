#include <cassert>
#include <cstddef>
#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <utility>
#include <vector>

class HashTable {
private:
    using Entry = std::pair<std::string, int>;
    std::vector<std::list<Entry>> buckets_;
    std::size_t size_ = 0;

    std::size_t index(const std::string& key) const {
        return std::hash<std::string>{}(key) % buckets_.size();
    }

public:
    explicit HashTable(std::size_t bucket_count = 17)
        : buckets_(bucket_count) {}

    void put(const std::string& key, int value) {
        auto& bucket = buckets_[index(key)];
        for (auto& entry : bucket) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        bucket.emplace_back(key, value);
        ++size_;
    }

    std::optional<int> get(const std::string& key) const {
        const auto& bucket = buckets_[index(key)];
        for (const auto& entry : bucket)
            if (entry.first == key) return entry.second;
        return std::nullopt;
    }

    bool remove(const std::string& key) {
        auto& bucket = buckets_[index(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                --size_;
                return true;
            }
        }
        return false;
    }

    std::size_t size() const { return size_; }
};

int main() {
    HashTable table;
    table.put("Alice", 90);
    table.put("Bob", 85);
    table.put("Alice", 95);

    assert(table.get("Alice").value() == 95);
    assert(table.get("Unknown") == std::nullopt);
    assert(table.size() == 2);

    assert(table.remove("Bob"));
    assert(table.get("Bob") == std::nullopt);

    std::cout << "Hash table demo passed.\n";
    return 0;
}
