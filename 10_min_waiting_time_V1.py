# O(nlogn) Time
# O(1) Space

def minimumWaitingTime(queries):
    totalWaitingTime = 0
    remainQueries = len(queries)
    
    queries.sort()
    
    for i in range(len(queries)):

        #  后面每个queries都要等这么长时间, 还剩几个query就等几倍
        remainQueries = len(queries) - i - 1
        totalWaitingTime += remainQueries * queries[i]

    return totalWaitingTime

queries = [3, 1, 2, 2, 6]
print(minimumWaitingTime(queries))

