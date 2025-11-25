#include <mutex>
#include <list>
#include <optional>

template<typename T>
class TinywlInputServiceQueue {
public:
    struct Event {
        T event;
        long nativePtr;

        Event(const T& event, long nativePtr) 
        : event(event), nativePtr(nativePtr) {}
    };

    TinywlInputServiceQueue() = default;
    
    ~TinywlInputServiceQueue() = default;
    
    // Non-copyable, non-movable
    TinywlInputServiceQueue(const TinywlInputServiceQueue&) = delete;
    TinywlInputServiceQueue& operator=(const TinywlInputServiceQueue&) = delete;
    TinywlInputServiceQueue(TinywlInputServiceQueue&&) = delete;
    TinywlInputServiceQueue& operator=(TinywlInputServiceQueue&&) = delete;
    
    // Pull an element from the queue
    // Returns std::nullopt if queue is empty
    std::optional<Event> pull() {
        std::lock_guard<std::mutex> lock(mutex_);
        
        if (queue_.empty()) {
            return std::nullopt;
        }
        
        Event item = std::move(queue_.back());
        queue_.pop_back();
        return item;
    }
        
    // Emplace element in-place
    void push(const T& event, long nativePtr) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.emplace_front(event, nativePtr);
    }
    
    // Get current queue length
    size_t length() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }
    
    // Check if queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

private:
    mutable std::mutex mutex_;
    std::list<Event> queue_;
};