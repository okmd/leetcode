# https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
# Fractional knapsack
class Item:
    def __init__(self, wt, pr):
        self.weight = wt
        self.profit = pr
        self.pw_ratio = pr//wt

    def __lt__(self, item):
        return self.pw_ratio < item.pw_ratio


class FractionalKnapsack:
    def __init__(self, profits, weights, W):
        self.profits = profits
        self.weights = weights
        self.W = W

    def getMaxProfit(self):
        values = []
        for i in range(len(self.profits)):
            values.append(Item(self.weights[i], self.profits[i]))
        # NOTE: When pw_ratio is not present in the Item class
        # sort using lamda function as
        # sorted(values, reverse=True, key=lambda item:item.profit/item.weight)
        pw_sorted = sorted(values, reverse=True)
        profit = 0
        for pw in pw_sorted:
            if self.W >= pw.weight:
                self.W -= pw.weight
                profit += pw.profit
            else:
                profit += self.W* pw.pw_ratio
                break
        return profit


pr = [60, 40, 100, 120]
wt = [10, 40, 20, 30]
c = 50
fr = FractionalKnapsack(pr, wt, c)
print(fr.getMaxProfit())
