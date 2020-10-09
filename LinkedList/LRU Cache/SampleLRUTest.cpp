#include "pch.h"
#include "LRUCache.cpp"
#include <unordered_map>

unordered_map<string, int> letterMaps{ {"a", 0}, {"b", 1}, {"c", 2}, {"d", 3},
                                      {"e", 4}, {"f", 5}, {"g", 6}, {"h", 7},
                                      {"i", 8}, {"j", 9} };
vector<string> letters{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };

#define testLruOfSize(lruSize)                                                 \
  {                                                                            \
    /* Instantiate cache and insert first key. */                              \
    LRUCache lru(lruSize);                                                     \
    assert(lru.getValueFromKey("a") == 0);                                     \
    lru.insertKeyValuePair("a", 99);                                           \
    assert(lru.getMostRecentKey() == "a");                                     \
    assert(*lru.getValueFromKey("a") == 99);                                   \
    /* Add existing key - cache not full. */                                   \
    lru.insertKeyValuePair("a", 0);                                            \
    assert(lru.getMostRecentKey() == "a");                                     \
    assert(*lru.getValueFromKey("a") == 0);                                    \
    /* Add keys - maximum cache capacity. */                                   \
    for (int i = 1; i < lruSize; i++) {                                        \
      string mostRecentLetter = letters[i - 1];                                \
      assert(lru.getMostRecentKey() == mostRecentLetter);                      \
      /* Test key retrieval - cache not full. */                               \
      for (int j = 0; j < i; j++) {                                            \
        string letter = letters[j];                                            \
        assert(*lru.getValueFromKey(letter) == letterMaps[letter]);            \
        assert(lru.getMostRecentKey() == letter);                              \
      }                                                                        \
      string currentLetter = letters[i];                                       \
      assert(lru.getValueFromKey(currentLetter) == 0);                         \
      lru.insertKeyValuePair(currentLetter, letterMaps[currentLetter]);        \
      assert(lru.getMostRecentKey() == currentLetter);                         \
      assert(*lru.getValueFromKey(currentLetter) ==                            \
             letterMaps[currentLetter]);                                       \
    }                                                                          \
    /* Add keys - maximum capacity. */                                         \
    for (int i = lruSize; i < letters.size(); i++) {                           \
      string mostRecentLetter = letters[i - 1];                                \
      assert(lru.getMostRecentKey() == mostRecentLetter);                      \
      /* Test key retrieval - cache is full. */                                \
      for (int j = i - lruSize; j < i; j++) {                                  \
        string letter = letters[j];                                            \
        assert(*lru.getValueFromKey(letter) == letterMaps[letter]);            \
        assert(lru.getMostRecentKey() == letter);                              \
      }                                                                        \
      string leastRecentLetter = letters[i - lruSize];                         \
      string currentLetter = letters[i];                                       \
      assert(lru.getValueFromKey(currentLetter) == 0);                         \
      lru.insertKeyValuePair(currentLetter, letterMaps[currentLetter]);        \
      assert(lru.getMostRecentKey() == currentLetter);                         \
      assert(*lru.getValueFromKey(currentLetter) ==                            \
             letterMaps[currentLetter]);                                       \
      assert(lru.getValueFromKey(leastRecentLetter) == 0);                     \
    }                                                                          \
    /* Add existing keys. */                                                   \
    for (int i = letters.size() - lruSize; i < letters.size(); i++) {          \
      string currentLetter = letters[i];                                       \
      assert(*lru.getValueFromKey(currentLetter) ==                            \
             letterMaps[currentLetter]);                                       \
      lru.insertKeyValuePair(currentLetter,                                    \
                             (letterMaps[currentLetter] + 1) * 100);           \
      assert(*lru.getValueFromKey(currentLetter) ==                            \
             (letterMaps[currentLetter] + 1) * 100);                           \
    }                                                                          \
  }



TEST(SampleTestCase, SampleTest) {
    LRUCache lruCache(3);
    lruCache.insertKeyValuePair("b", 2);
    lruCache.insertKeyValuePair("a", 1);
    lruCache.insertKeyValuePair("c", 3);
    EXPECT_EQ(lruCache.getMostRecentKey(), "c");
    EXPECT_EQ(*lruCache.getValueFromKey("a"), 1);
    EXPECT_EQ(lruCache.getMostRecentKey(), "a");
    lruCache.insertKeyValuePair("d", 4);
    EXPECT_EQ(lruCache.getValueFromKey("b"), nullptr);
    lruCache.insertKeyValuePair("a", 5);
    EXPECT_EQ(*lruCache.getValueFromKey("a"), 5);
}


