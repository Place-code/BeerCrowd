while True:
    try:
        nums = []
        a = 0
        nums.append(float(input()))
        nums.append(float(input()))
        if (nums[0] - int(nums[0])) >= nums[1]:
            print (nums[0].__ceil__())
        elif (nums[0] - int(nums[0])) == 0:
            print (int(nums[0]))
        else:
            print (round(nums[0] - 0.5))
    except EOFError:
        break