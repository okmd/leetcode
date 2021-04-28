def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
    output=[]
    max_candies = max(candies)
    for i in candies:
        if i+extraCandies >= max_candies:
            output.append(True)
        else:
            output.append(False)
    return output