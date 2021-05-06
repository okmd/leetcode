def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
    cnt=0
    for t,c,n in items:
        if ruleKey =="type" and ruleValue==t:
            cnt+=1
        elif ruleKey =="color" and ruleValue==c:
            cnt+=1
        elif ruleKey =="name" and ruleValue==n:
            cnt+=1
    return cnt
        