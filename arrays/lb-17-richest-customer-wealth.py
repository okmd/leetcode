def maximumWealth(self, accounts: List[List[int]]) -> int:
    max_sum=0
    for row in range(len(accounts)):
        row_sum=0
        for col in range(len(accounts[0])):
            row_sum += accounts[row][col]
        max_sum = max(max_sum, row_sum)
    return max_sum