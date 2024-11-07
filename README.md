**Total Tree:**
    There are total 3 trees:
      1)Player Tree (created using Players.txt)
      2)Game Played tree(each player has this)
      3) Game (created using the games.txt)

**Insertion in the PLayer Tree:**
  Starting with the flow of the game, first it ask's the user from which file you want to create the player tree i.e from the csv files or from the txt.
  _Time Complexity:_
      n log(n)
        As the loop runs n times for the n times and the insertion in player has complexity log (n).

**Insertioin using input:**
    This insertion in 2 trees i.e Players tree and each player has a gameplayed tree. To insert in the games played tree user has to input the details for the players. And if insertion is possible i.e user has not entered an existing id, the node is then inserted into the tree other wise it will not.
    _Time Complexity:_
      log(n)
      
    **Insertion in the game played Tree:**
         User inputs the player id in which he has to insert. If the id is present in the tree, insertion is possible and the user has to input the details of the game played node.
         Other wise it will not be added.
         _Time Comlexity:_
             log(n)^2

**Searching in the Trees:**
  Player tree has time complexity for seacrching is log(n). To search in the Gameplayed Tree it is log(n)^2 i.e first check which player's gameplayed has to be search.


**Deletion In Trees:**
  The deletion for a node in Player tree has time complexity log(n). To delete in the Gameplayed Tree it is log(n)^2 i.e first check which player's gameplayed has to be delete.

**Save Data:**
  The data is saved in the csv file in pre order traversal and it has time complexity O(n^2). i.e for both of the player and the gamePlayed Tree.


**Show N Layers:**
  The data structure queue is used for this purpose. Time complexity is O(N).


**Layer Number for a Player's Id:**
    Time complexity for this function is O(log(n)). This function has the attributes reference to the root , id of the player and a variable which keeps the track of the layer number.


**Show Path:**
    The preorder traversal is used to show path from the root to the that. It's time complexity is also O(log(n)).

**Editing in the tree:**
    First of all it takes the backup of the node which has to be edited. If the player edit's other than the id it is O(log(n)). Otherwise first we have to delete the node as we have the backup of that node. The again insert in the player tree.
    _Time Complexity:_
      O(log(n)

**Top N Players:**
    For this function I thinked alot and find this solution. I created a class named as players for this in which there is info of Player Id and total games played by the player. If two players have played the same amount of total games, it will simply append the id in the node. After the inorder traversal (Right ,Node , Left) is done to display the top n players.
    _Time Complexity:_
        O(n) for the worst case scenario.

**Show Details:**
    Time complexity for this is O(log n) ^3 as we have to display the details of the player, gameplayed , and game details.


**Has PLayed:**
    First finds the node of the player for which we have to check that it has played the game or not i.e O(log(n)). After that, it finds in the gameplayed tree i.e O(log(n)).
    So the time complexity is 2log(n) i.e O(log(n))
  
  
