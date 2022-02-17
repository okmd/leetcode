# you are given n meetings to be scheduled in a room.
# each meeting start and end at some time start<end time
# starti!=endj i.e there is always gap betwwen start time and end time of two meeting but they can exit at same time.
# you job is to maximize the number of meeting in the room.

# Greedy about the finish time.
def greedy_meeting(arr):
    n = len(arr)
    # sort the meeting according to the finish time. as more meetings can be accomodated in future.
    arr.sort(key=lambda x:x[1])
    count = 1
    previous = arr[0]
    for i in range(1, n):
        # start is more tha end of previous no conflict i.e can be assigned easily
        if arr[i][0] > previous[1]:
            count += 1
            previous = arr[i]
    return count

start = [1,3,0,5,8,5]
end = [2,4,6,7,9,9]
arr = [(i,j) for i, j in zip(start, end)]
print(greedy_meeting(arr))
        
