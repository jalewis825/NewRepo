# Bug Fixes for practice03.cpp

### Bug 1: Off by 1 in sumRange
    - Issue: In the loop for sumRange it included the start but excluded the end
    - Fix: change the loop from i < end to i <= end to include the end number.

### Bug 2: Out of bounds in containsNegative
    - Issue: The loop for containsNegative runs until i <= numbers.size(). This causes an out of bounds because the size of the vector = 4 but it indexing is zero
      based. This means 0= 3, 1=-1, 2=5, and 3=7. The loops runs to 4 (number.size()) but there is nothing at 4 in the index.
    - Fix: The loop should be i < numbers.size() or i = numbers.size() -1 to prevent from going out of bounds. 
    
### Bug 3: Logical Error in containsNegative
    - Issue: The function is supposed to return true if any element is negative but the if statement "numbers[i] > 0" returns true if any element is positive.
      This means it will always be true even with a negative value listed if there are positive values also listed.
    - Fix: Change to if (numbers[i] < 0); this will return true when a negative is found. 

### Bug 4: Out of bounds in findMax
    - Issue: The for loop checks for i <= numbers.size() created the same out of bounds error as before.
    - Fix: change to i < numbers.size() so it doesn't go out of the index bounds

### Bug 5: Logical error in findMax
    - Issue: The if statement if(numbers[i] >= maxVal) could cause a bug as it is looking for both the values larger than maxValue
      and the value set as maxValue.
    - Fix: Change if statement to if(numbers[i] > maxVal). This will check only for numbers larger than the current maxVal. 