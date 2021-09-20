# used to time the sorting
import time

# decorate creation of lists because creating the lists is where memory gets used and it's fun
#@profile
def CreateLists():
    # make all lists global
    global unsortedList,rSortedList,nearlySortedList

    # read the file with unsorted numbers and put all of them in an integerlist
    unsortedList = []
    unsortedNumbers = open("C:\\Programming\\algoritmes\\randomSorted.txt", "r")
    unsortedLines = unsortedNumbers.readlines()
    for line in unsortedLines:
        unsortedList.append(int(line.replace("\n","")))

    # same thing with the reversed list
    rSortedList = []
    rSorted = open("C:\\Programming\\algoritmes\\reverseSorted.txt", "r")
    rSortedLines = rSorted.readlines()
    for line in rSortedLines:
        rSortedList.append(int(line.replace("\n","")))

    # same thing with the nearly sorted list
    nearlySortedList = []
    nearlySorted = open("C:\\Programming\\algoritmes\\nearlySorted.txt", "r")
    nearlySortedLines = nearlySorted.readlines()
    for line in nearlySortedLines:
        nearlySortedList.append(int(line.replace("\n","")))

# decorate the function to measure memory usage
#@profile
def Sort(arr):
    # get the length to calculate the changing gap
    length = len(arr)
    # int division because for loops don't work with floats
    gap = length // 2
    # swap all numbers "gap" apart
    while gap > 0:
        # iterate trough the list starting at the gap, ending at the end
        for i in range(gap, length):
            rightElement = arr[i]
            j = i
            # swap if the right element is smaller than the left
            while j >= gap and arr[j - gap] > rightElement:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = rightElement
        # shrink the gap
        gap = gap // 2
    return arr

def TimeAndCallSortingOfLists():
    # calls Sort with the unsorted list and measures the time taken to sort
    start = time.time()
    print(Sort(unsortedList))
    end = time.time()
    print("Time to sort random numbers: ", end - start)

    # same thing with the reversed list
    start = time.time()
    print(Sort(rSortedList))
    end = time.time()
    print("Time to sort reversed numbers: ", end - start)

    # and the nearly sorted list
    start = time.time()
    print(Sort(nearlySortedList))
    end = time.time()
    print("Time to sort nearly sorted numbers: ", end - start)

# creating lists is a separate function for fun, that is where memory gets used
CreateLists()
# calls the sorting algorithm with all three functions, times the sorting and prints the returned result
TimeAndCallSortingOfLists()