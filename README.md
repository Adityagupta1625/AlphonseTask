# AlphonseTask

- **Input: input.txt**
- **Output: output.txt**

## Input Format:
- Each line of consists of description of Tree in level order fashion with N meaning NULL.
- For eg: 1 2 N 3 4
  
         1
        / \
       2   N
      / \
      3  4
  
  
## Output Format:
- Each line consiss of final colored trees wih 'R','G' and 'B' for (Red,Green and Blue colors) in a preoder fashion 
- For eg: B R B R
  
         B
        / \
        R   N
      / \
      B  R

## Alogrithm:

- Did bounary traversal of each node starting from left boundary followd by leaves of left and right child respectively and finally right boundary one by one.
- Took a color Variable and pass it as refrence after every coloring updated its value altrantively to Red and Blue based on previous value.
- Finally performed preorder of resulting tree and store it as string.
- By Default every node is marked as 'G' (GREEN)

## Time and Space Complexity:

- Time Complexity
    - O(length of input) for the conversion of level order traversal of Tree
    - O(N) N=no of nodes in binary tree, boundary traversal of Tree
    - O(N) N=no of nodes in binary tree, preorder traversal of Tree
    - Total: O(2*N)+O(length of input)
      
- Space Complexity
    - O(length of input) queue for storing level order traversal of Tree
    - O(height of tree) stack space for boundry traversal of Tree
    - O(height of tree) stack space for preorder traversal of Tree
    - Total: O(2*height of tree)+O(length of input)
