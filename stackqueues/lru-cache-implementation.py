import collections


class LRUCache:
    # window size
    capacity = 0

    def __init__(self):
        self.cache = list()  # (key, value)
        self.mapping = dict()  # {key:cache item)}

    def refresh_position(self, key, value):
        # make the element as most recently used
        del self.cache[self.mapping[key]]
        # insert new element at front.
        self.cache.insert(0, (key, value))
        # update or create the mapping for this element in dict.
        self.mapping[key] = self.cache[0]

    def LRU_cache(self, capaciy):
        self.capacity = capaciy

    def get(self, key):
        if self.mapping.get(key):
            self.refresh_position(key, self.mapping[key])
            # return the node of list where it is present
            return self.mapping[key][1]
        return -1

    def put(self, key, value):
        # if present in the cache or hashmap
        if self.mapping.get(key):
            # make it lru
            return self.refresh_position(key, value)
        else:
            self.cache.insert(0, (key, value))
            self.mapping[key] = self.cache[0]
            if len(self.mapping) > self.capacity:
                del self.mapping[self.cache[-1][0]]
                self.cache.pop()

    def print_cache(self):
        print("Least recently used: ", end=" ")
        for (i, v) in self.cache:
            print(i, end=" ")
        print()


# Run #
operations = [1, 2, 3, 4, 5]
window_size = 3
lru = LRUCache()
lru.LRU_cache(window_size)
for i, v in enumerate(operations):
    lru.put(v,i)

lru.print_cache()



class LRUCacheDequeue:
    size = 0
    def __init__(self, n):
        self.dq = collections.deque()
        self.hashmap = dict()
        self.size = n
        
        
    def refer(self, key):
        # present in hashmap or in caches
        if self.hashmap.get(key):
            del self.dq[self.map[key]]
        else:
            if len(self.dq)>=self.size:
                del self.hashmap[self.dq.popleft()]
            
        self.dq.append(key)
        self.hashmap[key] = self.dq[0]
        
    def print_cache(self):
        print("Least recently used: ", end=" ")
        for i in self.dq:
            print(i, end=" ")
        print()
            
lrudq = LRUCacheDequeue(window_size)
for v in operations:
    lrudq.refer(v)

lrudq.print_cache()
        
        
