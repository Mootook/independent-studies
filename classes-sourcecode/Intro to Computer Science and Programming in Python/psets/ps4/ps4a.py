# Problem Set 4A
# Name: <your name here>
# Collaborators:
# Time Spent: x:xx

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string

    sequence (string): an arbitrary string to permute. Assume that it is a
    non-empty string.  

    You MUST use recursion for this part. Non-recursive solutions will not be
    accepted.

    Returns: a list of all permutations of sequence

    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in
    a different order than what is listed here.
    '''
    if len(sequence) == 1:
      return [sequence]
    # Sequence is longer than one character
    res = []
    for i in range(len(sequence)):
      # Get letter
      l = sequence[i]
      #  Get all letters before and after targeted letter in loop
      perm = sequence[:i]  + sequence[i+1:]
      for other_perm in get_permutations(perm):
        res.append(l + other_perm)
    return res

if __name__ == '__main__':
  one_perms = get_permutations('a')
  print("Result: ", one_perms)
  print("===")
  two_perms = get_permutations('ab')
  print("Result: ", two_perms)
  print("===")
  three_perms = get_permutations('abc')
  print("Result: ", three_perms)
  print("===")
#    #EXAMPLE
#    example_input = 'abc'
#    print('Input:', example_input)
#    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
#    print('Actual Output:', get_permutations(example_input))
    
#    # Put three example test cases here (for your sanity, limit your inputs
#    to be three characters or fewer as you will have n! permutations for a 
#    sequence of length n)

