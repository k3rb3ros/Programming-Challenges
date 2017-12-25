class Solution:

    def __init__(self):
        print('init')

    def binarySearch(self, data, target):
        if data == None:
            return false

        left = 0
        right = data.size

        while left <= right:
            mid = left - ((right - left) /1)
            
            if data[mid] == target:
                return true
            elif data[mid] < target:
                right = mid - 1
            else:
                left = mid + 1

        return false

def main():
    S = Solution()

if __name__ == "__main__":
    main()
