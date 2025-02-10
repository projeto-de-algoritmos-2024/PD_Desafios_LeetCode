class Solution(object):
    def wordBreak(s, wordDict):

        wordSet = set(wordDict)
        memo = {}

        def backtrack(start):
            if start in memo:
                return memo[start]
            if start == len(s):
                return [""]

            sentences = []

            for end in range(start + 1, len(s) + 1):
                word = s[start:end]
                if word in wordSet:

                    for sub in backtrack(end):
                        if sub:
                            sentences.append(word + " " + sub)
                        else:
                            sentences.append(word)
            memo[start] = sentences
            return sentences

        return backtrack(0)
    
solucao = Solution
s = "catsanddog"
wordDict = ["cat","cats","and","sand","dog"]

res = solucao.wordBreak(s, wordDict)
print(res)